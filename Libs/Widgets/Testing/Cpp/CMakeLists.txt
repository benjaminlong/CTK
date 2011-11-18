SET(KIT ${PROJECT_NAME})

SET(TEST_SOURCES
  ctkActionsWidgetTest1.cpp
  ctkAddRemoveComboBoxTest1.cpp
  ctkAxesWidgetTest1.cpp
  ctkButtonGroupTest1.cpp
  ctkCheckBoxPixmapsTest1.cpp
  ctkCheckableComboBoxTest1.cpp
  ctkCheckableHeaderViewTest1.cpp
  ctkCheckableHeaderViewTest2.cpp
  ctkCheckableModelHelperTest2.cpp
  ctkCheckablePushButtonTest1.cpp
  ctkCollapsibleButtonTest1.cpp
  ctkCollapsibleButtonTest2.cpp
  ctkCollapsibleGroupBoxTest1.cpp
  ctkColorDialogTest1.cpp
  ctkColorDialogTest2.cpp
  ctkColorPickerButtonTest1.cpp
  ctkComboBoxTest1.cpp
  ctkCompleterTest1.cpp
  ctkConfirmExitDialogTest1.cpp
  ctkConsoleTest1.cpp
  ctkCoordinatesWidgetTest1.cpp
  ctkCrosshairLabelTest1.cpp
  ctkDirectoryButtonTest1.cpp
  ctkDoubleRangeSliderTest1.cpp
  ctkDoubleRangeSliderTest2.cpp
  ctkDoubleSliderTest1.cpp
  ctkDoubleSliderTest2.cpp
  ctkDynamicSpacerTest1.cpp
  ctkDynamicSpacerTest2.cpp
  ctkErrorLogWidgetTest1.cpp
  ctkExpandButtonTest1.cpp
  ctkFileDialogTest1.cpp
  ctkFittedTextBrowserTest1.cpp
  ctkFlowLayoutTest1.cpp
  ctkFontButtonTest1.cpp
  ctkLayoutManagerTest1.cpp
  ctkMaterialPropertyPreviewLabelTest1.cpp
  ctkMaterialPropertyWidgetTest1.cpp
  ctkMaterialPropertyWidgetTest2.cpp
  ctkMatrixWidgetTest1.cpp
  ctkMatrixWidgetTest2.cpp
  ctkMenuButtonTest1.cpp
  ctkMenuComboBoxTest1.cpp
  ctkMenuComboBoxTest2.cpp
  ctkMenuComboBoxTest3.cpp
  ctkModalityWidgetTest1.cpp
  ctkPathLineEditTest1.cpp
  ctkPopupWidgetTest1.cpp
  ctkRangeSliderTest1.cpp
  ctkRangeWidgetTest1.cpp
  ctkRangeWidgetTest2.cpp
  ctkDateRangeWidgetTest1.cpp
  ctkScreenshotDialogTest1.cpp
  ctkSearchBoxTest1.cpp
  ctkSearchBoxTest2.cpp
  ctkSettingsPanelTest1.cpp
  ctkSettingsPanelTest2.cpp
  ctkSettingsTest1.cpp
  ctkSettingsDialogTest1.cpp
  ctkSignalMapperTest1.cpp
  ctkSliderWidgetTest1.cpp
  ctkSliderWidgetTest2.cpp
  ctkThumbnailListWidgetTest1.cpp
  ctkThumbnailWidgetTest1.cpp
  ctkToolTipTrapperTest1.cpp
  ctkTreeComboBoxTest1.cpp
  ctkWidgetsUtilsTest1.cpp
  ctkWidgetsUtilsTestGrabWidget.cpp
  ctkWorkflowWidgetTest1.cpp
  ctkWorkflowWidgetTest2.cpp
  ctkExampleUseOfWorkflowWidgetUsingDerivedSteps.cpp
  ctkExampleUseOfWorkflowWidgetUsingSignalsAndSlots.cpp
  )

#
# Tests expecting CTKData to be set
#
IF(EXISTS "${CTKData_DIR}")
  LIST(APPEND TEST_SOURCES
    ctkCrosshairLabelTest2.cpp
    )
ENDIF()

#
# Test expecting CTK_USE_QTTESTING to be ON
#
IF(CTK_USE_QTTESTING)
  LIST(APPEND TEST_SOURCES
    ctkActionsWidgetEventTranslatorPlayerTest1.cpp
    ctkAddRemoveComboBoxEventTranslatorPlayerTest1.cpp
    ctkAxesWidgetEventTranslatorPlayerTest1.cpp
#    ctkBasePopupWidgetEventTranslatorPlayerTest1.cpp
    ctkButtonGroupEventTranslatorPlayerTest1.cpp
    ctkCheckableComboBoxEventTranslatorPlayerTest1.cpp
    ctkCheckableHeaderViewEventTranslatorPlayerTest1.cpp
    ctkCheckablePushButtonEventTranslatorPlayerTest1.cpp
    ctkCollapsibleButtonEventTranslatorPlayerTest1.cpp
    ctkCollapsibleGroupBoxEventTranslatorPlayerTest1.cpp
    ctkColorDialogEventTranslatorPlayerTest1.cpp
    ctkColorPickerButtonEventTranslatorPlayerTest1.cpp
    ctkComboBoxEventTranslatorPlayerTest1.cpp
#    ctkCompleterEventTranslatorPlayerTest1.cpp
#    ctkConfirmExitDialogEventTranslatorPlayerTest1.cpp
    ctkConsoleEventTranslatorPlayerTest1.cpp
    ctkCoordinatesWidgetEventTranslatorPlayerTest1.cpp
#    ctkCrosshairLabelEventTranslatorPlayerTest1.cpp
    ctkDateRangeWidgetEventTranslatorPlayerTest1.cpp
    ctkDirectoryButtonEventTranslatorPlayerTest1.cpp
    ctkDoubleRangeSliderEventTranslatorPlayerTest1.cpp
    ctkDoubleSliderEventTranslatorPlayerTest1.cpp
#    ctkDynamicSpacerEventTranslatorPlayerTest1.cpp
#    ctkErrorLogStatusMessageHandlerEventTranslatorPlayerTest1.cpp
#    ctkErrorLogWidgetEventTranslatorPlayerTest1.cpp
    ctkExpandButtonEventTranslatorPlayerTest1.cpp
    ctkFileDialogEventTranslatorPlayerTest1.cpp
#    ctkFittedTextBrowserEventTranslatorPlayerTest1.cpp
#    ctkFlowLayoutEventTranslatorPlayerTest1.cpp
    ctkFontButtonEventTranslatorPlayerTest1.cpp
#    ctkIconEnginePluginEventTranslatorPlayerTest1.cpp
#    ctkLayoutManagerEventTranslatorPlayerTest1.cpp
#    ctkMaterialPropertyPreviewLabelEventTranslatorPlayerTest1.cpp
    ctkMaterialPropertyWidgetEventTranslatorPlayerTest1.cpp
    ctkMatrixWidgetEventTranslatorPlayerTest1.cpp
    ctkMenuButtonEventTranslatorPlayerTest1.cpp
    ctkMenuComboBoxEventTranslatorPlayerTest1.cpp
    ctkModalityWidgetEventTranslatorPlayerTest1.cpp
    ctkPathLineEditEventTranslatorPlayerTest1.cpp
#    ctkPixmapIconEngineEventTranslatorPlayerTest1.cpp
    ctkPopupWidgetEventTranslatorPlayerTest1.cpp
#    ctkQImageViewEventTranslatorPlayerTest1.cpp
    ctkRangeSliderEventTranslatorPlayerTest1.cpp
    ctkRangeWidgetEventTranslatorPlayerTest1.cpp
    ctkScreenshotDialogEventTranslatorPlayerTest1.cpp
    ctkSearchBoxEventTranslatorPlayerTest1.cpp
    ctkSettingsDialogEventTranslatorPlayerTest1.cpp
#    ctkSettingsEventTranslatorPlayerTest1.cpp
    ctkSettingsPanelEventTranslatorPlayerTest1.cpp
#    ctkSignalMapperEventTranslatorPlayerTest1.cpp
#    ctkSimpleLayoutManagerEventTranslatorPlayerTest1.cpp
    ctkSliderWidgetEventTranslatorPlayerTest1.cpp
#    ctkTemplateWidgetEventTranslatorPlayerTest1.cpp
#    ctkTestApplicationEventTranslatorPlayerTest1.cpp
#    ctkThumbnailListWidgetEventTranslatorPlayerTest1.cpp
#    ctkThumbnailWidgetEventTranslatorPlayerTest1.cpp
#    ctkToolTipTrapperEventTranslatorPlayerTest1.cpp
#    ctkTransferFunctionBarsItemEventTranslatorPlayerTest1.cpp
#    ctkTransferFunctionControlPointsItemEventTranslatorPlayerTest1.cpp
#    ctkTransferFunctionGradientItemEventTranslatorPlayerTest1.cpp
#    ctkTransferFunctionItemEventTranslatorPlayerTest1.cpp
#    ctkTransferFunctionNativeItemEventTranslatorPlayerTest1.cpp
#    ctkTransferFunctionSceneEventTranslatorPlayerTest1.cpp
#    ctkTransferFunctionViewEventTranslatorPlayerTest1.cpp
    ctkTreeComboBoxEventTranslatorPlayerTest1.cpp
#    ctkWorkflowAbstractPagedWidgetEventTranslatorPlayerTest1.cpp
#    ctkWorkflowButtonBoxWidgetEventTranslatorPlayerTest1.cpp
#    ctkWorkflowGroupBoxEventTranslatorPlayerTest1.cpp
#    ctkWorkflowStackedWidgetEventTranslatorPlayerTest1.cpp
#    ctkWorkflowTabWidgetEventTranslatorPlayerTest1.cpp
#    ctkWorkflowWidgetEventTranslatorPlayerTest1.cpp
#    ctkWorkflowWidgetStepEventTranslatorPlayerTest1.cpp
    )
ENDIF()

CREATE_TEST_SOURCELIST(Tests ${KIT}CppTests.cxx
  ${TEST_SOURCES}
  )

SET (TestsToRun ${Tests})
REMOVE (TestsToRun ${KIT}CppTests.cxx)

SET(LIBRARY_NAME ${PROJECT_NAME})

SET(Tests_SRCS
  ctkExampleDerivedWorkflowWidgetStep.cpp
  ctkExampleDerivedWorkflowWidgetStep.h
  ctkExampleWorkflowWidgetStepUsingSignalsAndSlots.cpp
  ctkExampleWorkflowWidgetStepUsingSignalsAndSlots.h
  ctkSettingsPanelTest2Helper.cpp
  ctkSettingsPanelTest2Helper.h
  )

SET(Tests_MOC_SRCS
  ctkExampleDerivedWorkflowWidgetStep.h
  ctkExampleWorkflowWidgetStepUsingSignalsAndSlots.h
  ctkSettingsPanelTest2Helper.h
  )

SET(Tests_MOC_CPP)
QT4_WRAP_CPP(Tests_MOC_CPP ${Tests_MOC_SRCS})

#
SET(KIT_target_libraries ${LIBRARY_NAME})

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

  LIST(APPEND KIT_Target_libraries CTKQtTesting)

  LIST(APPEND TEST_SOURCES
    ${CTK_SOURCE_DIR}/Libs/QtTesting/ctkEventTranslatorPlayerWidget.h
    ${CTK_SOURCE_DIR}/Libs/QtTesting/ctkEventTranslatorPlayerWidget.cpp
    )
ENDIF()

ADD_EXECUTABLE(${KIT}CppTests ${Tests} ${Tests_SRCS} ${Tests_MOC_CPP})
TARGET_LINK_LIBRARIES(${KIT}CppTests ${KIT_Target_libraries})


SET( KIT_TESTS ${CPP_TEST_PATH}/${KIT}CppTests)

MACRO( SIMPLE_TEST  TESTNAME )
  ADD_TEST( ${TESTNAME} ${KIT_TESTS} ${TESTNAME}
            -D "${CTKData_DIR}/Data"
            -V "${CTKData_DIR}/Baseline/Libs/Widgets"
            )
  SET_PROPERTY(TEST ${TESTNAME} PROPERTY LABELS ${PROJECT_NAME})
ENDMACRO( SIMPLE_TEST  )

#
# Add Tests
#

SIMPLE_TEST( ctkActionsWidgetTest1 )
SIMPLE_TEST( ctkAddRemoveComboBoxTest1 )
SIMPLE_TEST( ctkAxesWidgetTest1 )
SIMPLE_TEST( ctkButtonGroupTest1 )
SIMPLE_TEST( ctkCheckBoxPixmapsTest1 )
SIMPLE_TEST( ctkCheckableComboBoxTest1 )
SIMPLE_TEST( ctkCheckableHeaderViewTest1 )
SIMPLE_TEST( ctkCheckableHeaderViewTest2 )
SIMPLE_TEST( ctkCheckableModelHelperTest2 )
SIMPLE_TEST( ctkCheckablePushButtonTest1 )
SIMPLE_TEST( ctkCollapsibleButtonTest1 )
SIMPLE_TEST( ctkCollapsibleButtonTest2 )
SIMPLE_TEST( ctkCollapsibleGroupBoxTest1 )
SIMPLE_TEST( ctkColorDialogTest1 )
SIMPLE_TEST( ctkColorDialogTest2 )
SIMPLE_TEST( ctkColorPickerButtonTest1 )
SIMPLE_TEST( ctkComboBoxTest1 )
SIMPLE_TEST( ctkCompleterTest1 )
SIMPLE_TEST( ctkConfirmExitDialogTest1 )
SIMPLE_TEST( ctkConsoleTest1 )
SIMPLE_TEST( ctkCoordinatesWidgetTest1 )
SIMPLE_TEST( ctkCrosshairLabelTest1 )
SIMPLE_TEST( ctkDateRangeWidgetTest1 )
SIMPLE_TEST( ctkDirectoryButtonTest1 )
SIMPLE_TEST( ctkDoubleRangeSliderTest1 )
SIMPLE_TEST( ctkDoubleRangeSliderTest2 )
SIMPLE_TEST( ctkDoubleSliderTest1 )
SIMPLE_TEST( ctkDoubleSliderTest2 )
SIMPLE_TEST( ctkDynamicSpacerTest1 )
SIMPLE_TEST( ctkDynamicSpacerTest2 )
SIMPLE_TEST( ctkErrorLogWidgetTest1 )
SIMPLE_TEST( ctkExampleUseOfWorkflowWidgetUsingDerivedSteps )
SIMPLE_TEST( ctkExampleUseOfWorkflowWidgetUsingSignalsAndSlots )
SIMPLE_TEST( ctkExpandButtonTest1 )
SIMPLE_TEST( ctkFileDialogTest1 )
SIMPLE_TEST( ctkFittedTextBrowserTest1 )
SIMPLE_TEST( ctkFlowLayoutTest1 )
SIMPLE_TEST( ctkFontButtonTest1 )
SIMPLE_TEST( ctkLayoutManagerTest1 )
SIMPLE_TEST( ctkMaterialPropertyPreviewLabelTest1 )
SIMPLE_TEST( ctkMaterialPropertyWidgetTest1 )
SIMPLE_TEST( ctkMaterialPropertyWidgetTest2 )
SIMPLE_TEST( ctkMatrixWidgetTest1 )
SIMPLE_TEST( ctkMatrixWidgetTest2 )
SIMPLE_TEST( ctkMenuButtonTest1 )
SIMPLE_TEST( ctkMenuComboBoxTest1 )
SIMPLE_TEST( ctkMenuComboBoxTest2 )
SIMPLE_TEST( ctkMenuComboBoxTest3 )
SIMPLE_TEST( ctkModalityWidgetTest1 )
SIMPLE_TEST( ctkPathLineEditTest1 )
SIMPLE_TEST( ctkPopupWidgetTest1 )
SIMPLE_TEST( ctkRangeSliderTest1 )
SIMPLE_TEST( ctkRangeWidgetTest1 )
SIMPLE_TEST( ctkRangeWidgetTest2 )
SIMPLE_TEST( ctkScreenshotDialogTest1 )
SIMPLE_TEST( ctkSearchBoxTest1 )
SIMPLE_TEST( ctkSearchBoxTest2 )
SIMPLE_TEST( ctkSettingsDialogTest1 )
SIMPLE_TEST( ctkSettingsPanelTest1 )
SIMPLE_TEST( ctkSettingsPanelTest2 )
SIMPLE_TEST( ctkSettingsTest1 )
SIMPLE_TEST( ctkSignalMapperTest1 )
SIMPLE_TEST( ctkSliderWidgetTest1 )
SIMPLE_TEST( ctkSliderWidgetTest2 )
SIMPLE_TEST( ctkThumbnailListWidgetTest1 )
SIMPLE_TEST( ctkThumbnailWidgetTest1 )
SIMPLE_TEST( ctkToolTipTrapperTest1 )
SIMPLE_TEST( ctkTreeComboBoxTest1 )
SIMPLE_TEST( ctkWidgetsUtilsTest1 )
SIMPLE_TEST( ctkWidgetsUtilsTestGrabWidget )
SIMPLE_TEST( ctkWorkflowWidgetTest1 )
SIMPLE_TEST( ctkWorkflowWidgetTest2 )

#
# Add Tests expecting CTK_USE_QTTESTING to be set
#
IF(CTK_USE_QTTESTING)
  SIMPLE_TEST( ctkActionsWidgetEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkActionsWidgetEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkAddRemoveComboBoxEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkAxesWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkBasePopupWidgetEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkButtonGroupEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkCheckableComboBoxEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkCheckableHeaderViewEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkCheckablePushButtonEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkCollapsibleButtonEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkCollapsibleGroupBoxEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkColorDialogEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkColorPickerButtonEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkComboBoxEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkCompleterEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkConfirmExitDialogEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkConsoleEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkCoordinatesWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkCrosshairLabelEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkDateRangeWidgetEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkDirectoryButtonEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkDoubleRangeSliderEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkDoubleSliderEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkDynamicSpacerEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkErrorLogStatusMessageHandlerEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkErrorLogWidgetEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkExpandButtonEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkFileDialogEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkFittedTextBrowserEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkFlowLayoutEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkFontButtonEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkIconEnginePluginEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkLayoutManagerEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkMaterialPropertyPreviewLabelEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkMaterialPropertyWidgetEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkMatrixWidgetEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkMenuButtonEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkMenuComboBoxEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkModalityWidgetEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkPathLineEditEventTranslatorPlayerTest1 )
#  SIMPLE_TEST( ctkPixmapIconEngineEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkPopupWidgetEventTranslatorPlayerTest1 )
#  SIMPLE_TEST( ctkQImageViewEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkRangeSliderEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkRangeWidgetEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkScreenshotDialogEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkSearchBoxEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkSettingsDialogEventTranslatorPlayerTest1 )
#  SIMPLE_TEST( ctkSettingsEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkSettingsPanelEventTranslatorPlayerTest1 )
#  SIMPLE_TEST( ctkSignalMapperEventTranslatorPlayerTest1 )
#  SIMPLE_TEST( ctkSimpleLayoutManagerEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkSliderWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkTemplateWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkTestApplicationEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkThumbnailListWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkThumbnailWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkToolTipTrapperEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkTransferFunctionBarsItemEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkTransferFunctionControlPointsItemEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkTransferFunctionGradientItemEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkTransferFunctionItemEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkTransferFunctionNativeItemEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkTransferFunctionSceneEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkTransferFunctionViewEventTranslatorPlayerTest1 )
  SIMPLE_TEST( ctkTreeComboBoxEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkWorkflowAbstractPagedWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkWorkflowButtonBoxWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkWorkflowGroupBoxEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkWorkflowStackedWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkWorkflowTabWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkWorkflowWidgetEventTranslatorPlayerTest1 )
# SIMPLE_TEST( ctkWorkflowWidgetStepEventTranslatorPlayerTest1 )
ENDIF()

#
# Add Tests expecting CTKData to be set
#
IF(EXISTS "${CTKData_DIR}")
  SIMPLE_TEST( ctkCrosshairLabelTest2 )
ENDIF()
