set(vtkIOAMR_LOADED 1)
set(vtkIOAMR_DEPENDS "vtkFiltersAMR;vtkParallelCore;vtkhdf5;vtksys")
set(vtkIOAMR_LIBRARIES "vtkIOAMR")
set(vtkIOAMR_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-6.1")
set(vtkIOAMR_LIBRARY_DIRS "")
set(vtkIOAMR_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkIOAMR_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIOAMRHierarchy.txt")

