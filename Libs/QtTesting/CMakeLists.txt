PROJECT(CTKQtTesting)

#
# Add the libraries QtTesting
#
FIND_PACKAGE(QtTesting REQUIRED)
LINK_DIRECTORIES(
  ${QtTesting_LIBRARY_DIR}
  )

#
# See CTK/CMake/ctkMacroBuildLib.cmake for details
#

SET(KIT_export_directive "CTK_QTTESTING_EXPORT")

SET(CTK_LIBS_WIDGET_DIR)

# TODO The following code used to create CTK_ENABLED_LIBNAMES list could be
#      moved in the main CMakeLists.txt
SET(CTK_ENABLED_LIBNAMES)
FOREACH(lib_subdir ${CTK_LIBS_SUBDIRS})
  IF(CTK_LIB_${lib_subdir})
    STRING(REPLACE "/" "" lib_name_no_slash ${lib_subdir})
    LIST(APPEND CTK_ENABLED_LIBNAMES CTK${lib_name_no_slash})
    STRING(REGEX MATCHALL "Widgets" CTK_LIB_WIDGET ${lib_name_no_slash})
    IF(CTK_LIB_WIDGET)
      LIST(APPEND CTK_LIBS_WIDGET_DIR CTK${lib_name_no_slash})
    ENDIF()
  ENDIF()
ENDFOREACH()

# Recover All the event player/translator headers
SET(CTK_HEADERS_EVENT_PLAYERS)
SET(CTK_HEADERS_EVENT_TRANSLATORS)

FOREACH(CTK_LIB_WIDGET_DIR ${CTK_LIBS_WIDGET_DIR})
  FILE(GLOB HEADERS RELATIVE ${${CTK_LIB_WIDGET_DIR}_SOURCE_DIR} "${${CTK_LIB_WIDGET_DIR}_SOURCE_DIR}/*.h")
  FOREACH(HEADER ${HEADERS})
    STRING(REGEX MATCHALL "EventPlayer" HEADER_PLAYER ${HEADER})
    STRING(REGEX MATCHALL "EventTranslator" HEADER_TRANSLATOR ${HEADER})
    IF(HEADER_PLAYER)
      LIST(APPEND CTK_HEADERS_EVENT_PLAYERS ${HEADER})
    ENDIF()
    IF(HEADER_TRANSLATOR)
      LIST(APPEND CTK_HEADERS_EVENT_TRANSLATORS ${HEADER})
    ENDIF()
  ENDFOREACH()
ENDFOREACH()

LIST(SORT CTK_HEADERS_EVENT_PLAYERS)
LIST(SORT CTK_HEADERS_EVENT_TRANSLATORS)

# Define the C++ code for the file ctkQtTestingUtility
# Define the headers
# Define the methode addWidgetEventTranslator/Player()
SET(CTK_ADD_HEADER_EVENT_PLAYERS "// Event player includes\n")
#SET(CTK_ADD_WIDGET_EVENT_PLAYERS)
FOREACH(CTK_HEADER_EVENT_PLAYERS ${CTK_HEADERS_EVENT_PLAYERS})
  SET(CTK_ADD_HEADER_EVENT_PLAYERS "${CTK_ADD_HEADER_EVENT_PLAYERS}#include <${CTK_HEADER_EVENT_PLAYERS}>\n")
  get_filename_component(CTK_HEADER_EVENT_PLAYERS_NAME ${CTK_HEADER_EVENT_PLAYERS} NAME_WE)
  STRING(COMPARE EQUAL "ctkVTKRenderViewEventPlayer" ${CTK_HEADER_EVENT_PLAYERS_NAME} RESULT)
  IF(RESULT)
    SET(CTK_ADD_WIDGET_EVENT_PLAYERS "${CTK_ADD_WIDGET_EVENT_PLAYERS}  this->eventPlayer()->addWidgetEventPlayer(new ${CTK_HEADER_EVENT_PLAYERS_NAME}(\"QVTKObject\"));\n")
  ELSE()
    SET(CTK_ADD_WIDGET_EVENT_PLAYERS "${CTK_ADD_WIDGET_EVENT_PLAYERS}  this->eventPlayer()->addWidgetEventPlayer(new ${CTK_HEADER_EVENT_PLAYERS_NAME}());\n")
  ENDIF()
ENDFOREACH()

SET(CTK_ADD_HEADER_EVENT_TRANSLATORS "// Event translator includes\n")
#SET(CTK_ADD_WIDGET_EVENT_TRANSLATORS)
FOREACH(CTK_HEADER_EVENT_TRANSLATORS ${CTK_HEADERS_EVENT_TRANSLATORS})
  SET(CTK_ADD_HEADER_EVENT_TRANSLATORS "${CTK_ADD_HEADER_EVENT_TRANSLATORS}#include <${CTK_HEADER_EVENT_TRANSLATORS}>\n")
  get_filename_component(CTK_HEADER_EVENT_TRANSLATOR_NAME ${CTK_HEADER_EVENT_TRANSLATORS} NAME_WE)
  STRING(COMPARE EQUAL "ctkVTKRenderViewEventTranslator" ${CTK_HEADER_EVENT_TRANSLATOR_NAME} RESULT)
  IF(RESULT)
    SET(CTK_ADD_WIDGET_EVENT_TRANSLATORS "${CTK_ADD_WIDGET_EVENT_TRANSLATORS}  this->eventTranslator()->addWidgetEventTranslator(new ${CTK_HEADER_EVENT_TRANSLATOR_NAME}(\"QVTKObject\"));\n")
  ELSE()
    SET(CTK_ADD_WIDGET_EVENT_TRANSLATORS "${CTK_ADD_WIDGET_EVENT_TRANSLATORS}  this->eventTranslator()->addWidgetEventTranslator(new ${CTK_HEADER_EVENT_TRANSLATOR_NAME}());\n")
  ENDIF()
ENDFOREACH()

SET(KIT_INCLUDE_DIRECTORIES
  ${QtTesting_INCLUDE_DIRS}
  ${CTK_SUPERBUILD_BINARY_DIR} # For ctkConfig.h
  )

FOREACH(libname ${CTK_ENABLED_LIBNAMES})
  LIST(APPEND KIT_INCLUDE_DIRECTORIES
    ${${libname}_SOURCE_DIR}
    ${${libname}_BINARY_DIR}
    )
ENDFOREACH()

configure_file(
  ctkQtTestingUtility.cpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/ctkQtTestingUtility.cpp
  )

# Source files
SET(KIT_SRCS
  ctkEventTranslatorPlayerWidget.cpp
  ctkEventTranslatorPlayerWidget.h
  ${CMAKE_CURRENT_BINARY_DIR}/ctkQtTestingUtility.cpp
  ctkQtTestingUtility.h
  ctkXMLEventObserver.cpp
  ctkXMLEventObserver.h
  ctkXMLEventSource.cpp
  ctkXMLEventSource.h
  )

# Header that should run through moc
SET(KIT_MOC_SRCS
  ctkEventTranslatorPlayerWidget.h
  ctkQtTestingUtility.h
  ctkXMLEventObserver.h
  ctkXMLEventSource.h
  )

# UI files
SET(KIT_UI_FORMS
  Resources/UI/ctkEventTranslatorPlayerWidget.ui
)

# Resources
SET(KIT_resources
)

# dependencie dynamic from all the libraries with Widgets + QtTesting
SET(KIT_target_libraries)

FOREACH(libname ${CTK_ENABLED_LIBNAMES})
  LIST(APPEND KIT_target_libraries ${libname})
ENDFOREACH()

if(CTK_USE_QTTESTING)
  list(APPEND KIT_target_libraries QtTesting)
endif()
#message("${KIT_target_libraries}")

ctkMacroBuildLib(
  NAME ${PROJECT_NAME}
  EXPORT_DIRECTIVE ${KIT_export_directive}
  SRCS ${KIT_SRCS}
  MOC_SRCS ${KIT_MOC_SRCS}
  UI_FORMS ${KIT_UI_FORMS}
  INCLUDE_DIRECTORIES ${KIT_INCLUDE_DIRECTORIES}
  TARGET_LIBRARIES ${KIT_target_libraries}
  RESOURCES ${KIT_resources}
  LIBRARY_TYPE ${CTK_LIBRARY_MODE}
  )

IF(CTK_WRAP_PYTHONQT_FULL OR CTK_WRAP_PYTHONQT_LIGHT)
  ctkMacroBuildLibWrapper(
    TARGET ${PROJECT_NAME}
    SRCS ${KIT_SRCS}
    WRAPPER_LIBRARY_TYPE ${CTK_LIBRARY_MODE}
    )
ENDIF()

# Testing
#IF(BUILD_TESTING)
#  ADD_SUBDIRECTORY(Testing)
#ENDIF(BUILD_TESTING)

