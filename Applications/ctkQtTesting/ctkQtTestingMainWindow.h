#ifndef CTKQTTESTINGMAINWINDOW_H
#define CTKQTTESTINGMAINWINDOW_H

#include <QWidget>
#include <ctkQtTestingUtility.h>
#include "ui_ctkQtTestingMainWindow.h"

//class pqTestUtility;

class ctkQtTestingMainWindow : public QWidget
{
  Q_OBJECT
public:
  ctkQtTestingMainWindow();
  ~ctkQtTestingMainWindow();
protected slots:
  void record();
  void play();

private:
  Q_DISABLE_COPY(ctkQtTestingMainWindow)

//  pqTestUtility *TestUtility;
  ctkQtTestingUtility *TestUtility;
  Ui::ctkQtTestingMainWindow Ui;
};

#endif