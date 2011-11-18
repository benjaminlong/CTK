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
#include <QDebug>
#include <QStandardItemModel>
#include <QTimer>
#include <QTreeView>

// CTK includes
#include "ctkCallback.h"
#include "ctkConfig.h"
#include "ctkColorDialog.h"
#include "ctkEventTranslatorPlayerWidget.h"

// STD includes
#include <cstdlib>
#include <iostream>

namespace
{
//-----------------------------------------------------------------------------
void checkFinalWidgetState(void* data)
  {
  ctkColorDialog* widget = reinterpret_cast<ctkColorDialog*>(data);

  CTKCOMPARE(QColor::fromRgb(widget->customColor(0)), QColor::fromRgb(85,85,255));
  CTKCOMPARE(QColor::fromRgb(widget->customColor(2)), QColor::fromRgb(170,0,255));
  CTKCOMPARE(widget->selectedColor(), QColor(125, 255, 194));
  }
}

//-----------------------------------------------------------------------------
int ctkColorDialogEventTranslatorPlayerTest1(int argc, char * argv [] )
{
  QApplication app(argc, argv);

  QString xmlDirectory = CTK_SOURCE_DIR "/Libs/Widgets/Testing/Cpp/";

  // ------------------------
  ctkEventTranslatorPlayerWidget etpWidget;

  // Test case 1
  ctkColorDialog* widget = new ctkColorDialog();
  etpWidget.addTestCase(widget,
                        xmlDirectory + "ctkColorDialogEventTranslatorPlayerTest1.xml",
                        &checkFinalWidgetState);

  // ------------------------
  if (!app.arguments().contains("-I"))
    {
    QTimer::singleShot(0, &etpWidget, SLOT(play()));
    }

  etpWidget.show();
  return app.exec();
}
