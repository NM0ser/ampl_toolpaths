set(vtkChartsCore_LOADED 1)
set(vtkChartsCore_DEPENDS "vtkCommonColor;vtkInfovisCore;vtkRenderingContext2D")
set(vtkChartsCore_LIBRARIES "vtkChartsCore")
set(vtkChartsCore_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-6.1")
set(vtkChartsCore_LIBRARY_DIRS "")
set(vtkChartsCore_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkChartsCore_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkChartsCoreHierarchy.txt")

