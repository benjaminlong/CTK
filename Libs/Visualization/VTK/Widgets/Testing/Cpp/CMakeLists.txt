SET(KIT ${PROJECT_NAME})

#
# Tests
#
SET(TEST_SOURCES
  ctkVTKDataSetArrayComboBoxTest1.cpp
  ctkVTKDataSetModelTest1.cpp
  ctkVTKMatrixWidgetTest1.cpp
  ctkVTKMagnifyViewTest1.cpp
  ctkVTKScalarBarWidgetTest1.cpp
  ctkTransferFunctionBarsItemTest1.cpp
  ctkTransferFunctionViewTest1.cpp
  ctkTransferFunctionViewTest2.cpp
  ctkTransferFunctionViewTest3.cpp
  ctkTransferFunctionViewTest4.cpp
  ctkTransferFunctionViewTest5.cpp
  ctkVTKRenderViewTest1.cpp
  ctkVTKScalarsToColorsUtilsTest1.cpp
  ctkVTKSliceViewTest1.cpp
  ctkVTKSurfaceMaterialPropertyWidgetTest1.cpp
  ctkVTKTextPropertyWidgetTest1.cpp
  ctkVTKThumbnailViewTest1.cpp
  ctkVTKWidgetsUtilsTestGrabWidget.cpp
  )

SET(TEST_MOC_SOURCES)
SET(TEST_UI_FORMS)

IF(CTK_USE_CHARTS)
  SET(TEST_SOURCES
      ctkVTKChartViewTest1.cpp
      ctkVTKVolumePropertyWidgetTest1.cpp
      ctkVTKScalarsToColorsViewTest1.cpp
      ctkVTKScalarsToColorsViewTest2.cpp
      ctkVTKScalarsToColorsViewTest3.cpp
      ctkVTKScalarsToColorsViewTest4.cpp
      ctkVTKScalarsToColorsWidgetTest1.cpp
      ctkVTKScalarsToColorsWidgetTest2.cpp
      ctkVTKScalarsToColorsWidgetTest3.cpp
      ${TEST_SOURCES})
ENDIF(CTK_USE_CHARTS)

#
# Tests expecting CTKData to be set
#
IF(EXISTS "${CTKData_DIR}")
  LIST(APPEND TEST_SOURCES
    ctkVTKMagnifyViewTest2.cpp
    ctkVTKSliceViewTest2.cpp
    ctkVTKRenderViewTest2.cpp
    )
ENDIF()

#
# Test expecting CTK_USE_QTTESTING to be ON
#
IF(CTK_USE_QTTESTING)
  LIST(APPEND TEST_SOURCES
#    ctkVTKAbstractMatrixWidgetEventTranslatorPlayerTest1.cpp
    ctkVTKAbstractViewEventTranslatorPlayerTest1.cpp
#    ctkVTKChartViewEventTranslatorPlayerTest1.cpp
    ctkVTKDataSetArrayComboBoxEventTranslatorPlayerTest1.cpp
    ctkVTKDataSetModelEventTranslatorPlayerTest1.cpp
    ctkVTKMagnifyViewEventTranslatorPlayerTest1.cpp
    ctkVTKMatrixWidgetEventTranslatorPlayerTest1.cpp
    ctkVTKRenderViewEventTranslatorPlayerTest1.cpp
    ctkVTKScalarBarWidgetEventTranslatorPlayerTest1.cpp
#    ctkVTKScalarsToColorsUtilsEventTranslatorPlayerTest1.cpp
#    ctkVTKScalarsToColorsViewEventTranslatorPlayerTest1.cpp
#    ctkVTKScalarsToColorsWidgetEventTranslatorPlayerTest1.cpp
    ctkVTKSliceViewEventTranslatorPlayerTest1.cpp
#    ctkVTKSurfaceMaterialPropertyWidgetEventTranslatorPlayerTest1.cpp
    ctkVTKTextPropertyWidgetEventTranslatorPlayerTest1.cpp
#    ctkVTKThresholdWidgetEventTranslatorPlayerTest1.cpp
#    ctkVTKThumbnailViewEventTranslatorPlayerTest1.cpp
#    ctkVTKVolumePropertyWidgetEventTranslatorPlayerTest1.cpp
#    ctkVTKWidgetsUtilsEventTranslatorPlayerTest1.cpp
    )
ENDIF()

CREATE_TEST_SOURCELIST(Tests ${KIT}CppTests.cpp
  ${TEST_SOURCES}
  #EXTRA_INCLUDE TestingMacros.h
  )

SET (TestsToRun ${Tests})
REMOVE (TestsToRun ${KIT}CppTests.cpp)

SET(LIBRARY_NAME ${PROJECT_NAME})

#
# If CTK_USE_QTTESTING is ON
#
IF(CTK_USE_QTTESTING)
  # Do not export symbol in ctkEventTranslatorPlayerWidget class
  ADD_DEFINITIONS(-DNO_SYMBOL_EXPORT)

  INCLUDE_DIRECTORIES(
    ${CTK_SOURCE_DIR}/Libs/QtTesting
    ${CTK_BINARY_DIR}/Libs/QtTesting
    )

  LIST(APPEND LIBRARY_NAME CTKQtTesting)

  LIST(APPEND TEST_SOURCES
    ${CTK_SOURCE_DIR}/Libs/QtTesting/ctkEventTranslatorPlayerWidget.h
    ${CTK_SOURCE_DIR}/Libs/QtTesting/ctkEventTranslatorPlayerWidget.cpp
    )
  LIST(APPEND TEST_MOC_SOURCES
    ${CTK_SOURCE_DIR}/Libs/QtTesting/ctkEventTranslatorPlayerWidget.h
    )
  LIST(APPEND TEST_UI_FORMS
    ${CTK_SOURCE_DIR}/Libs/QtTesting/Resources/UI/ctkEventTranslatorPlayerWidget.ui
    )
ENDIF()

SET(TEST_MOC_CPP)
IF(TEST_MOC_SOURCES)
  QT4_WRAP_CPP(TEST_MOC_CPP ${TEST_MOC_SOURCES})
ENDIF()
SET(TEST_UI_CPP)
IF(TEST_UI_FORMS)
  QT4_WRAP_UI(TEST_UI_CPP ${TEST_UI_FORMS})
ENDIF()

ADD_EXECUTABLE(${KIT}CppTests ${Tests} ${TEST_SOURCES} ${TEST_MOC_CPP} ${TEST_UI_CPP})
TARGET_LINK_LIBRARIES(${KIT}CppTests ${LIBRARY_NAME} vtkCharts ${CTK_BASE_LIBRARIES})

SET( KIT_TESTS ${CPP_TEST_PATH}/${KIT}CppTests)

MACRO( SIMPLE_TEST  TESTNAME )
  ADD_TEST( ${TESTNAME} ${KIT_TESTS} ${TESTNAME}
            -D "${CTKData_DIR}/Data"
            -V "${CTKData_DIR}/Baseline/Libs/Visualization/VTK/Widgets"
            )
  SET_PROPERTY(TEST ${TESTNAME} PROPERTY LABELS ${PROJECT_NAME})
ENDMACRO( SIMPLE_TEST  )

MACRO( MAGNIFY_WIDGET_TEST  TESTNAME  TESTTYPE  SIZE  MAGNIFICATION)
  ADD_TEST( ${TESTNAME}${TESTTYPE} ${KIT_TESTS} ${TESTNAME}
            -D "${CTKData_DIR}/Data"
            -V "${CTKData_DIR}/Baseline/Libs/Visualization/VTK/Widgets"
            -T "${TESTTYPE}"
            -S "${SIZE}"
            -M "${MAGNIFICATION}"
            )
  SET_PROPERTY(TEST ${TESTNAME}${TESTTYPE} PROPERTY LABELS ${PROJECT_NAME})
ENDMACRO( MAGNIFY_WIDGET_TEST  )

#
# Add Tests
#

SIMPLE_TEST( ctkVTKDataSetArrayComboBoxTest1 )
SIMPLE_TEST( ctkVTKDataSetModelTest1 )
SIMPLE_TEST( ctkVTKMagnifyViewTest1 )
SIMPLE_TEST( ctkVTKMatrixWidgetTest1 )
SIMPLE_TEST( ctkVTKScalarBarWidgetTest1 )
SIMPLE_TEST( ctkVTKScalarsToColorsUtilsTest1 )
SIMPLE_TEST( ctkTransferFunctionBarsItemTest1 )
SIMPLE_TEST( ctkTransferFunctionViewTest1 )
SIMPLE_TEST( ctkTransferFunctionViewTest2 )
SIMPLE_TEST( ctkTransferFunctionViewTest3 )
SIMPLE_TEST( ctkTransferFunctionViewTest4 )
SIMPLE_TEST( ctkTransferFunctionViewTest5 )
IF (CTK_USE_CHARTS)
  SIMPLE_TEST( ctkVTKChartViewTest1 )
  SIMPLE_TEST( ctkVTKVolumePropertyWidgetTest1 )
  SIMPLE_TEST( ctkVTKScalarsToColorsViewTest1 )
  SIMPLE_TEST( ctkVTKScalarsToColorsViewTest2 )
  SIMPLE_TEST( ctkVTKScalarsToColorsViewTest3 )
  SIMPLE_TEST( ctkVTKScalarsToColorsViewTest4 )
  SIMPLE_TEST( ctkVTKScalarsToColorsWidgetTest1 )
  SIMPLE_TEST( ctkVTKScalarsToColorsWidgetTest2 )
  SIMPLE_TEST( ctkVTKScalarsToColorsWidgetTest3 )
ENDIF(CTK_USE_CHARTS)
SIMPLE_TEST( ctkVTKRenderViewTest1 )
SIMPLE_TEST( ctkVTKSliceViewTest1 )
SIMPLE_TEST( ctkVTKSurfaceMaterialPropertyWidgetTest1 )
SIMPLE_TEST( ctkVTKTextPropertyWidgetTest1 )
SIMPLE_TEST( ctkVTKThumbnailViewTest1 )
SIMPLE_TEST( ctkVTKWidgetsUtilsTestGrabWidget )

#
# Add Tests expecting CTKData to be set
#
IF(EXISTS "${CTKData_DIR}")
  #
  # Dependencies required so that these tests won't run in parallel
  #
  MAGNIFY_WIDGET_TEST( ctkVTKMagnifyViewTest2 OddOdd 341 17 )
  MAGNIFY_WIDGET_TEST( ctkVTKMagnifyViewTest2 EvenEven 340 18 )
  SET_TESTS_PROPERTIES( ctkVTKMagnifyViewTest2EvenEven
                        PROPERTIES DEPENDS
                        ctkVTKMagnifyViewTest2OddOdd )
  MAGNIFY_WIDGET_TEST( ctkVTKMagnifyViewTest2 OddEven 341 18 )
  SET_TESTS_PROPERTIES( ctkVTKMagnifyViewTest2OddEven
                        PROPERTIES DEPENDS
                        ctkVTKMagnifyViewTest2EvenEven )
  MAGNIFY_WIDGET_TEST( ctkVTKMagnifyViewTest2 EvenOdd 340 17 )
  SET_TESTS_PROPERTIES( ctkVTKMagnifyViewTest2EvenOdd
                        PROPERTIES DEPENDS
                        ctkVTKMagnifyViewTest2OddEven )
  SIMPLE_TEST( ctkVTKSliceViewTest2 )
  SIMPLE_TEST( ctkVTKRenderViewTest2 )
ENDIF()

#
# Add Tests expecting CTK_USE_QTTESTING to be set
#
IF(CTK_USE_QTTESTING)
#    SIMPLE_TEST( ctkVTKAbstractMatrixWidgetEventTranslatorPlayerTest1 )
    SIMPLE_TEST( ctkVTKAbstractViewEventTranslatorPlayerTest1 )
#    SIMPLE_TEST( ctkVTKChartViewEventTranslatorPlayerTest1 )
    SIMPLE_TEST( ctkVTKDataSetArrayComboBoxEventTranslatorPlayerTest1 )
    SIMPLE_TEST( ctkVTKDataSetModelEventTranslatorPlayerTest1 )
    SIMPLE_TEST( ctkVTKMagnifyViewEventTranslatorPlayerTest1 )
    SIMPLE_TEST( ctkVTKMatrixWidgetEventTranslatorPlayerTest1 )
    SIMPLE_TEST( ctkVTKRenderViewEventTranslatorPlayerTest1 )
    SIMPLE_TEST( ctkVTKScalarBarWidgetEventTranslatorPlayerTest1 )
#    SIMPLE_TEST( ctkVTKScalarsToColorsUtilsEventTranslatorPlayerTest1 )
#    SIMPLE_TEST( ctkVTKScalarsToColorsViewEventTranslatorPlayerTest1 )
#    SIMPLE_TEST( ctkVTKScalarsToColorsWidgetEventTranslatorPlayerTest1 )
    SIMPLE_TEST( ctkVTKSliceViewEventTranslatorPlayerTest1 )
#    SIMPLE_TEST( ctkVTKSurfaceMaterialPropertyWidgetEventTranslatorPlayerTest1 )
    SIMPLE_TEST( ctkVTKTextPropertyWidgetEventTranslatorPlayerTest1 )
#    SIMPLE_TEST( ctkVTKThresholdWidgetEventTranslatorPlayerTest1 )
#    SIMPLE_TEST( ctkVTKThumbnailViewEventTranslatorPlayerTest1 )
#    SIMPLE_TEST( ctkVTKVolumePropertyWidgetEventTranslatorPlayerTest1 )
#    SIMPLE_TEST( ctkVTKWidgetsUtilsEventTranslatorPlayerTest1 )
ENDIF()
