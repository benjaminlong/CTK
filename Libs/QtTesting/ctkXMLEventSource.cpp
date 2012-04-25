/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

// QT includes
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QMap>
#include <QMessageBox>
#include <QVariant>

// CTKQtTesting includes
#include "ctkXMLEventSource.h"

//-----------------------------------------------------------------------------
// ctkXMLEventSource methods

//-----------------------------------------------------------------------------
ctkXMLEventSource::ctkXMLEventSource(QObject* p)
  : Superclass(p)
{
  this->Automatic = false;
  this->XMLStream = NULL;
  this->TestUtility = qobject_cast<pqTestUtility*>(p);
}

//-----------------------------------------------------------------------------
ctkXMLEventSource::~ctkXMLEventSource()
{
  delete this->XMLStream;
  this->TestUtility = 0;
}

//-----------------------------------------------------------------------------
void ctkXMLEventSource::setRestoreSettingsAuto(bool value)
{
  this->Automatic = value;
}

//-----------------------------------------------------------------------------
bool ctkXMLEventSource::restoreSettingsAuto() const
{
  return this->Automatic;
}

//-----------------------------------------------------------------------------
void ctkXMLEventSource::setContent(const QString& xmlfilename)
{
  delete this->XMLStream;
  this->XMLStream = NULL;

  QFile xml(xmlfilename);
  if (!xml.open(QIODevice::ReadOnly))
    {
    qDebug() << "Failed to load " << xmlfilename;
    return;
    }
  QByteArray data = xml.readAll();
  this->XMLStream = new QXmlStreamReader(data);
  /* This checked for valid event objects, but also caused the first event
   * to get dropped. Commenting this out in the example. If you wish to report
   * empty XML test files a flag indicating whether valid events were found is
   * probably the best way to go.
  while (!this->XMLStream->atEnd())
    {
    QXmlStreamReader::TokenType token = this->XMLStream->readNext();
    if (token == QXmlStreamReader::StartElement)
      {
      if (this->XMLStream->name() == "event")
        {
        break;
        }
      }
    } */
  if (this->XMLStream->atEnd())
    {
    qDebug() << "Invalid xml" << endl;
    return;
    }

  if(this->settingsRecorded())
    {
    qDebug() << "settings recorded";
    this->OldSettings = this->recoverSettingsFromXML();
    if(!this->settingsUpToData())
      {
      qDebug() << "restoring ...";
      this->restoreApplicationSettings();
      }
    }
  return;
}

//-----------------------------------------------------------------------------
int ctkXMLEventSource::getNextEvent(QString& widget, QString& command, QString&arguments)
{
  if (this->XMLStream->atEnd())
    {
    return DONE;
    }
  while (!this->XMLStream->atEnd())
    {
    QXmlStreamReader::TokenType token = this->XMLStream->readNext();
    if (token == QXmlStreamReader::StartElement)
      {
      if (this->XMLStream->name() == "event")
        {
        break;
        }
      }
    }
  if (this->XMLStream->atEnd())
    {
    return DONE;
    }
  widget = this->XMLStream->attributes().value("widget").toString();
  command = this->XMLStream->attributes().value("command").toString();
  arguments = this->XMLStream->attributes().value("arguments").toString();
  return SUCCESS;
}

//-----------------------------------------------------------------------------
bool ctkXMLEventSource::settingsRecorded()
{
  while(this->XMLStream->name() != "settings" && this->XMLStream->name() != "events")
    {
    this->XMLStream->readNext();
    }
  return (this->XMLStream->name() == "settings") ? true : false;
}

//-----------------------------------------------------------------------------
bool ctkXMLEventSource::settingsUpToData()
{
  QMainWindow* window = this->mainWindow();

  bool result = true;
  QMap<QObject*, QString> states = this->TestUtility->objectStateProperty();

  result &= (this->OldSettings.value("geometry") == QString(window->saveGeometry().toHex()));
  result &= (this->OldSettings.value("state") == QString(window->saveState().toHex()));

  QMap<QObject*, QString>::iterator iter;
  for(iter = states.begin() ; iter!=states.end() ; ++iter)
    {
    result &= (this->OldSettings.value(iter.value()) ==
              iter.key()->property(iter.value().toLatin1()).toString());
    }

  return result;
}

//-----------------------------------------------------------------------------
bool ctkXMLEventSource::restoreApplicationSettings()
{
  QMainWindow* window = this->mainWindow();

  bool result = false;
  QMap<QObject*, QString> states = this->TestUtility->objectStateProperty();

  if (!this->Automatic)
    {
    if (QMessageBox::No == QMessageBox::warning(0, tr("Playback ..."),
                                                tr("The settings are differents from the record Settings.\n"
                                                   "Do you want to restore the settings?"),
                                                QMessageBox::Yes | QMessageBox::No,
                                                QMessageBox::Yes))
      {
      return false;
      }

    result = window->restoreState(
                QByteArray::fromHex(QByteArray(this->OldSettings.value("state").toLocal8Bit().constData())));
    result = window->restoreGeometry(
                QByteArray::fromHex(QByteArray(this->OldSettings.value("geometry").toLocal8Bit().constData())));

    QMap<QObject*, QString>::iterator iter;
    for(iter = states.begin() ; iter!=states.end() ; ++iter)
      {
      iter.key()->setProperty(iter.value().toLatin1(),
                              QVariant(this->OldSettings.value(iter.value())));
      }
    }

  return result;
}

//-----------------------------------------------------------------------------
QMap<QString, QString> ctkXMLEventSource::recoverSettingsFromXML()
{
  // Recover the settings
  QMap<QString, QString> settings;
  while (this->XMLStream->tokenType() != QXmlStreamReader::EndElement ||
         this->XMLStream->name() != "settings")
    {
    this->XMLStream->readNext();
    if (!this->XMLStream->name().isEmpty() &&
        this->XMLStream->tokenType() == QXmlStreamReader::StartElement)
      {
      settings.insert(this->XMLStream->name().toString(),
                      this->XMLStream->attributes().value("arguments").toString());
      }
    }
  return settings;
}

//-----------------------------------------------------------------------------
QMainWindow* ctkXMLEventSource::mainWindow()
{
  QMainWindow* window = NULL;
  foreach(QWidget * widget, QApplication::topLevelWidgets())
    {
    window = qobject_cast<QMainWindow*>(widget);
    if (window)
      {
      return window;
      }
    }
  return 0;
}
