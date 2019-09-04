set(vtkInteractionWidgets_LOADED 1)
set(vtkInteractionWidgets_DEPENDS "vtkFiltersHybrid;vtkFiltersModeling;vtkImagingGeneral;vtkImagingHybrid;vtkInteractionStyle;vtkRenderingAnnotation;vtkRenderingFreeType;vtkRenderingVolume")
set(vtkInteractionWidgets_LIBRARIES "vtkInteractionWidgets")
set(vtkInteractionWidgets_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-6.1")
set(vtkInteractionWidgets_LIBRARY_DIRS "")
set(vtkInteractionWidgets_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkInteractionWidgets_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkInteractionWidgetsHierarchy.txt")

