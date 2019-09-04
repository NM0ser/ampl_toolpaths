#-----------------------------------------------------------------------------
#
# VTKConfig.cmake - VTK CMake configuration file for external projects.
#
# This file is configured by VTK and used by the UseVTK.cmake module
# to load VTK's settings for an external project.

# Compute the installation prefix from this VTKConfig.cmake file location.
get_filename_component(VTK_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(VTK_INSTALL_PREFIX "${VTK_INSTALL_PREFIX}" PATH)
get_filename_component(VTK_INSTALL_PREFIX "${VTK_INSTALL_PREFIX}" PATH)
get_filename_component(VTK_INSTALL_PREFIX "${VTK_INSTALL_PREFIX}" PATH)
set(VTK_MODULES_DIR "${VTK_INSTALL_PREFIX}/lib/cmake/vtk-6.1/Modules")

# The C and C++ flags added by VTK to the cmake-configured flags.
SET(VTK_REQUIRED_C_FLAGS "")
SET(VTK_REQUIRED_CXX_FLAGS "")
SET(VTK_REQUIRED_EXE_LINKER_FLAGS "")
SET(VTK_REQUIRED_SHARED_LINKER_FLAGS "")
SET(VTK_REQUIRED_MODULE_LINKER_FLAGS "")

# The VTK version number
SET(VTK_MAJOR_VERSION "6")
SET(VTK_MINOR_VERSION "1")
SET(VTK_BUILD_VERSION "0")

# The location of the UseVTK.cmake file.
SET(VTK_CMAKE_DIR "${VTK_INSTALL_PREFIX}/lib/cmake/vtk-6.1")
SET(VTK_USE_FILE "${VTK_CMAKE_DIR}/UseVTK.cmake")

#-----------------------------------------------------------------------------
# Load requested modules.

# List of available VTK modules.
set(VTK_MODULES_ENABLED)

# Determine list of available VTK-modules by scanning the VTK_MODULES_DIR.
file(GLOB config_files RELATIVE "${VTK_MODULES_DIR}" "${VTK_MODULES_DIR}/*.cmake")
foreach (_file ${config_files})
  if (NOT "${_file}" MATCHES "[^\\-]+-[a-zA-Z]+\\.cmake")
    string(REGEX REPLACE "\\.cmake$" "" _module "${_file}")
    list(APPEND VTK_MODULES_ENABLED "${_module}")
  endif()
endforeach()

# Import VTK targets.
set(VTK_CONFIG_TARGETS_FILE "${VTK_INSTALL_PREFIX}/lib/cmake/vtk-6.1/VTKTargets.cmake")
if(NOT TARGET vtkCommonCore)
  include("${VTK_CONFIG_TARGETS_FILE}")
endif()

# Load module interface macros.
include("${VTK_INSTALL_PREFIX}/lib/cmake/vtk-6.1/vtkModuleAPI.cmake")

# Compute set of requested modules.
if(VTK_FIND_COMPONENTS)
  # Specific modules requested by find_package(VTK).
  set(VTK_MODULES_REQUESTED "${VTK_FIND_COMPONENTS}")
elseif(NOT "${CMAKE_VERSION}" VERSION_GREATER 2.8.4.20110407)
  # CMake 2.8.4 and lower do not forward the components list through
  # their FindVTK.cmake module, so unless the application called
  #
  #   find_package(VTK NO_MODULE ...)
  #
  # then only the per-component variables VTK_FIND_REQUIRED_<mod> will
  # have leaked through.
  set(VTK_MODULES_REQUESTED "")
  get_cmake_property(_vars VARIABLES)
  foreach(v IN LISTS _vars)
    if("x${v}" MATCHES "^xVTK_FIND_REQUIRED_" AND ${v})
      string(REGEX REPLACE "^VTK_FIND_REQUIRED_" "" _mod "${v}")
      list(APPEND VTK_MODULES_REQUESTED ${_mod})
    endif()
  endforeach()
endif()
if(NOT VTK_MODULES_REQUESTED)
  # No specific modules requested.  Use all of them.
  set(VTK_MODULES_REQUESTED "${VTK_MODULES_ENABLED}")
endif()

# Load requested modules and their dependencies into variables:
#  VTK_DEFINITIONS     = Preprocessor definitions
#  VTK_LIBRARIES       = Libraries to link
#  VTK_INCLUDE_DIRS    = Header file search path
#  VTK_LIBRARY_DIRS    = Library search path (for outside dependencies)
vtk_module_config(VTK ${VTK_MODULES_REQUESTED})

#-----------------------------------------------------------------------------

# VTK global configuration options.
SET(VTK_BUILD_SHARED_LIBS "ON")
SET(VTK_LEGACY_REMOVE "OFF")
SET(VTK_LEGACY_SILENT "OFF")
SET(VTK_WRAP_PYTHON "OFF")
SET(VTK_WRAP_TCL "OFF")
SET(VTK_WRAP_JAVA "OFF")
SET(VTK_QT_VERSION "")

# Do not add options or information here that is specific to a
# particular module.  Instead set <module>_EXPORT_OPTIONS and/or
# <module>_EXPORT_CODE_BUILD and <module>_EXPORT_CODE_INSTALL
# at the top of the module CMakeLists.txt file.
