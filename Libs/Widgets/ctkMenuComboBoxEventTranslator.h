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

#ifndef __ctkMenuComboBoxEventTranslator_h
#define __ctkMenuComboBoxEventTranslator_h

// QtTesting includes
#include <pqWidgetEventTranslator.h>

// CTK includes
#include <ctkPimpl.h>
#include "ctkWidgetsExport.h"

class QAction;
class QMenu;

/// Translate low-level Qt events into high-level events for QtTesting

class CTK_WIDGETS_EXPORT ctkMenuComboBoxEventTranslator :
  public pqWidgetEventTranslator
{
  Q_OBJECT

public:
  ctkMenuComboBoxEventTranslator(QObject* parent = 0);

  virtual bool translateEvent(QObject *Object, QEvent *Event, bool &Error);

private:
  ctkMenuComboBoxEventTranslator(const ctkMenuComboBoxEventTranslator&); // NOT implemented
  ctkMenuComboBoxEventTranslator& operator=(const ctkMenuComboBoxEventTranslator&); // NOT implemented

  QObject* CurrentObject;

  void connectAllMenu(QMenu* menu);

private slots:

  void onAboutToShow();
  void onAboutToHide();

  void onEditTextChanged(const QString&);
  void onToolButtonClicked(bool state);
  void onActionTriggered(QAction* action);
};

#endif
