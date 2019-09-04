set(vtkViewsCore_LOADED 1)
set(vtkViewsCore_DEPENDS "vtkInteractionWidgets;vtkRenderingCore")
set(vtkViewsCore_LIBRARIES "vtkViewsCore")
set(vtkViewsCore_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-6.1")
set(vtkViewsCore_LIBRARY_DIRS "")
set(vtkViewsCore_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkViewsCore_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkViewsCoreHierarchy.txt")

