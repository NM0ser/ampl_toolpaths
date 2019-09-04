set(vtkIOMINC_LOADED 1)
set(vtkIOMINC_DEPENDS "vtkCommonExecutionModel;vtkFiltersHybrid;vtkIOGeometry;vtkIOImage;vtkRenderingCore;vtknetcdf;vtksys")
set(vtkIOMINC_LIBRARIES "vtkIOMINC")
set(vtkIOMINC_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-6.1")
set(vtkIOMINC_LIBRARY_DIRS "")
set(vtkIOMINC_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkIOMINC_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIOMINCHierarchy.txt")

