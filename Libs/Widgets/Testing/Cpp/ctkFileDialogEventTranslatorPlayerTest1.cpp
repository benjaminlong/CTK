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

// Qt includes
#include <QAction>
#include <QApplication>
#include <QCheckBox>
#include <QDebug>
#include <QStandardItemModel>
#include <QTimer>
#include <QTreeView>

// CTK includes
#include "ctkCallback.h"
#include "ctkConfig.h"
#include "ctkEventTranslatorPlayerWidget.h"
#include "ctkFileDialog.h"
#include "ctkMenuComboBoxEventTranslator.h"

// STD includes
#include <cstdlib>
#include <iostream>

namespace
{
//-----------------------------------------------------------------------------
void checkFinalWidgetState(void* data)
  {
  ctkFileDialog* widget = reinterpret_cast<ctkFileDialog*>(data);
  Q_UNUSED(widget);
  }
}

//-----------------------------------------------------------------------------
int ctkFileDialogEventTranslatorPlayerTest1(int argc, char * argv [] )
{
  QApplication app(argc, argv);

  QString xmlDirectory = CTK_SOURCE_DIR "/Libs/Widgets/Testing/Cpp/";

  // ------------------------
  ctkEventTranslatorPlayerWidget etpWidget;
  etpWidget.addWidgetEventTranslator(new ctkMenuComboBoxEventTranslator);

  // Test case 1
  ctkFileDialog* fileDialog = new ctkFileDialog();
  fileDialog->setFileMode(QFileDialog::AnyFile);
  fileDialog->setNameFilter("Images (*.png *.xpm *.jpg)");
  fileDialog->setViewMode(QFileDialog::Detail);
  QCheckBox* checkBox = new QCheckBox;
  fileDialog->setBottomWidget(checkBox, "Foo Bar:");
  QObject::connect(checkBox, SIGNAL(toggled(bool)),
                   fileDialog, SLOT(setAcceptButtonEnable(bool)));
  fileDialog->setAcceptButtonEnable(false);

  etpWidget.addTestCase(fileDialog,
                        xmlDirectory + "ctkFileDialogEventTranslatorPlayerTest1.xml",
                        &checkFinalWidgetState);

  // ------------------------
  if (!app.arguments().contains("-I"))
    {
    QTimer::singleShot(0, &etpWidget, SLOT(play()));
    }

  etpWidget.show();
  return app.exec();
}

