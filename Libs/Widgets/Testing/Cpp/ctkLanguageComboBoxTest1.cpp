// Qt includes
#include <QApplication>
#include <QDebug>
#include <QSettings>
#include <QTimer>
#include <QVBoxLayout>

// CTK includes
#include "ctkLanguageComboBox.h"
#include "ctkSettingsDialog.h"
#include "ctkSettingsPanel.h"

// STD includes
#include <cstdlib>
#include <iostream>

// ------------------------------------------------------------------------------
int ctkLanguageComboBoxTest1(int argc, char* argv[])
{
  QApplication app(argc, argv);
  QSettings settings(QSettings::IniFormat,QSettings::UserScope, "CTK");

  ctkLanguageComboBox languageBox;
  languageBox.setDirectory("/home/benjaminlong/work/slicer/Slicer4-Superbuild/Slicer-build/Applications/SlicerQT");
  languageBox.show();

  ctkSettingsDialog settingsDialog;
  settingsDialog.setSettings(&settings);
  ctkSettingsPanel* panel1 = new ctkSettingsPanel;
  settingsDialog.addPanel("Panel 1", panel1);
  if (panel1->settings() != &settings)
    {
    std::cerr << "ctkSettingsDialog::addPanel settings failed " << panel1->settings() << std::endl;
    return EXIT_FAILURE;
    }
  ctkLanguageComboBox* languageBox2 = new ctkLanguageComboBox(panel1);

  languageBox2->setDirectory("/home/benjaminlong/work/slicer/Slicer4-Superbuild/Slicer-build/Applications/SlicerQT");
  settingsDialog.setCurrentPanel("Panel 1");
  settingsDialog.show();

  if (argc < 2 || QString(argv[1]) != "-I" )
    {
    QTimer::singleShot(200, &app, SLOT(quit()));
    }

  return app.exec();
}

