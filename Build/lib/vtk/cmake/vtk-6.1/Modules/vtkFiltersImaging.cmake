set(vtkFiltersImaging_LOADED 1)
set(vtkFiltersImaging_DEPENDS "vtkFiltersStatistics;vtkImagingGeneral;vtkImagingSources")
set(vtkFiltersImaging_LIBRARIES "vtkFiltersImaging")
set(vtkFiltersImaging_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-6.1")
set(vtkFiltersImaging_LIBRARY_DIRS "")
set(vtkFiltersImaging_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkFiltersImaging_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkFiltersImagingHierarchy.txt")

