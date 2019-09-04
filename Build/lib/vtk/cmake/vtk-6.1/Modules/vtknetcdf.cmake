set(vtknetcdf_LOADED 1)
set(vtknetcdf_DEPENDS "vtkhdf5")
set(vtknetcdf_LIBRARIES "vtkNetCDF;vtkNetCDF_cxx")
set(vtknetcdf_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-6.1")
set(vtknetcdf_LIBRARY_DIRS "")
set(vtknetcdf_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtknetcdf_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtknetcdfHierarchy.txt")
set(vtknetcdf_EXCLUDE_FROM_WRAPPING 1)

