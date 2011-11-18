PROJECT(ctkQtTesting)


FIND_PACKAGE(QtTesting REQUIRED)
LINK_DIRECTORIES(
  ${QtTesting_LIBRARY_DIR}
  ${ctkAtTesting_LIBRARY_DIR}
  )
INCLUDE_DIRECTORIES(
  ${QtTesting_INCLUDE_DIRS}
  ${CTKQtTesting_INCLUDE_DIRS}
  ${CTK_BASE_INCLUDE_DIRS}
  )

#
# See CTK/CMake/ctkMacroBuildApp.cmake for details
#

SET(KIT_SRCS
  ctkQtTestingMain.cpp
  ctkQtTestingMainWindow.cpp
  ctkQtTestingMainWindow.h
)

# Headers that should run through moc
SET(KIT_MOC_SRCS
  ctkQtTestingMainWindow.h
)

# UI files
SET(KIT_UI_FORMS
  ctkQtTestingMainWindow.ui
)

# Resources
SET(KIT_resources
)


set(KIT_target_libraries CTKWidgets QtTesting CTKQtTesting)

ctkMacroBuildApp(
  NAME ${PROJECT_NAME}
  SRCS ${KIT_SRCS}
  MOC_SRCS ${KIT_MOC_SRCS}
  UI_FORMS ${KIT_UI_FORMS}
  TARGET_LIBRARIES ${KIT_target_libraries}
  RESOURCES ${KIT_resources}
  )

# Testing
IF(BUILD_TESTING)
#   ADD_SUBDIRECTORY(Testing)
ENDIF(BUILD_TESTING)
