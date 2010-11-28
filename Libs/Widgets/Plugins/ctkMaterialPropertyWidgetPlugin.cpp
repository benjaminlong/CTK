/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

// CTK includes
#include "ctkMaterialPropertyWidgetPlugin.h"
#include "ctkMaterialPropertyWidget.h"

//-----------------------------------------------------------------------------
ctkMaterialPropertyWidgetPlugin::ctkMaterialPropertyWidgetPlugin(QObject *_parent) : QObject(_parent)
{
}

//-----------------------------------------------------------------------------
QWidget *ctkMaterialPropertyWidgetPlugin::createWidget(QWidget *_parent)
{
  ctkMaterialPropertyWidget* _widget = new ctkMaterialPropertyWidget(_parent);
  return _widget;
}

//-----------------------------------------------------------------------------
QString ctkMaterialPropertyWidgetPlugin::domXml() const
{
  return "<widget class=\"ctkMaterialPropertyWidget\" \
          name=\"MaterialPropertyWidget\">\n"
          "</widget>\n";
}

//-----------------------------------------------------------------------------
QIcon ctkMaterialPropertyWidgetPlugin::icon() const
{
  return QIcon(":/Icons/pushbutton.png");
}

//-----------------------------------------------------------------------------
QString ctkMaterialPropertyWidgetPlugin::includeFile() const
{
  return "ctkMaterialPropertyWidget.h";
}

//-----------------------------------------------------------------------------
bool ctkMaterialPropertyWidgetPlugin::isContainer() const
{
  return false;
}

//-----------------------------------------------------------------------------
QString ctkMaterialPropertyWidgetPlugin::name() const
{
  return "ctkMaterialPropertyWidget";
}