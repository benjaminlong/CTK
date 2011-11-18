#
# QtTesting
#
SET(QtTesting_DEPENDS)
IF(CTK_USE_QTTESTING)

  # Sanity checks
  IF(DEFINED QtTesting_DIR AND NOT EXISTS ${QtTesting_DIR})
    MESSAGE(FATAL_ERROR "QtTesting_DIR variable is defined but corresponds to non-existing directory")
  ENDIF()

  SET(proj QtTesting)
  SET(proj_DEPENDENCIES)

  SET(QtTesting_DEPENDS ${proj})

  IF(NOT DEFINED QtTesting_DIR)

    # Set CMake OSX variable to pass down the external project
    set(CMAKE_OSX_EXTERNAL_PROJECT_ARGS)
    if(APPLE)
      list(APPEND CMAKE_OSX_EXTERNAL_PROJECT_ARGS
        -DCMAKE_OSX_ARCHITECTURES=${CMAKE_OSX_ARCHITECTURES}
        -DCMAKE_OSX_SYSROOT=${CMAKE_OSX_SYSROOT}
        -DCMAKE_OSX_DEPLOYMENT_TARGET=${CMAKE_OSX_DEPLOYMENT_TARGET})
    endif()

    MESSAGE(STATUS "Adding project:${proj}")
    ExternalProject_Add(${proj}
      SOURCE_DIR ${CMAKE_BINARY_DIR}/${proj}
      BINARY_DIR ${proj}-build
      PREFIX ${proj}${ep_suffix}
      GIT_REPOSITORY "${git_protocol}://paraview.org/QtTesting.git"
      GIT_TAG "origin/master"
      CMAKE_GENERATOR ${gen}
      INSTALL_COMMAND ""
      UPDATE_COMMAND ""
      CMAKE_ARGS
        ${ep_common_args}
        -DBUILD_SHARED_LIBS:BOOL=ON
        -DQT_QMAKE_EXECUTABLE:FILEPATH=${QT_QMAKE_EXECUTABLE}
      DEPENDS
        ${proj_DEPENDENCIES}
      )
    SET(QtTesting_DIR ${CMAKE_BINARY_DIR}/${proj}-build)

    # Since QtTesting is statically build, there is not need to add its corresponding
    # library output directory to CTK_EXTERNAL_LIBRARY_DIRS

  ELSE()
    ctkMacroEmptyExternalProject(${proj} "${proj_DEPENDENCIES}")
  ENDIF()

  LIST(APPEND CTK_SUPERBUILD_EP_ARGS -DQtTesting_DIR:PATH=${QtTesting_DIR})

ENDIF()
