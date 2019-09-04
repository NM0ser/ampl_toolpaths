#ifndef STDAFX_HEADER_GUARD
#define STDAFX_HEADER_GUARD

// Fast C++ CSV Parser
#define CSV_IO_NO_THREAD
#include <csv.h>

// Cereal headers
#include <cereal/archives/xml.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>
//#include <cereal/archives/json.hpp>

// OCC Graphics Headers
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>

#include <Aspect_Handle.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <Aspect_DisplayConnection.hxx>

#include <OpenGl_GraphicDriver.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <WNT_Window.hxx>

// OCC Shapes/Tools Headers
#include <TColStd_ListOfReal.hxx>
#include <NCollection_Array1.hxx>

#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Pln.hxx>
#include <gp_Trsf.hxx>
#include <gp_Lin2d.hxx>

#include <Geom_ConicalSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_Plane.hxx>
#include <Geom2d_Ellipse.hxx>
#include <Geom2d_Circle.hxx>
#include <Geom2d_Line.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom_Circle.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Geom_SurfaceOfRevolution.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_Line.hxx>

#include <GeomAPI.hxx>
#include <Geom2dAPI_InterCurveCurve.hxx>
#include <Geom2dAPI_Interpolate.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <GeomAPI_IntCS.hxx>
#include <GeomLProp_SLProps.hxx>
#include <GProp_GProps.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <Adaptor3d_Curve.hxx>

#include <GC_MakeTrimmedCone.hxx>
#include <GC_MakeSegment.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <GC_MakeCircle.hxx>
#include <GC_MakeLine.hxx>
#include <GCE2d_MakeSegment.hxx>
#include <gce_MakeCirc.hxx>
#include <GccEnt.hxx>
#include <GccEnt_QualifiedLin.hxx>
#include <GccEnt_Position.hxx>
#include <GccAna_Circ2d2TanRad.hxx>
#include <GCPnts_UniformAbscissa.hxx>
#include <GCPnts_AbscissaPoint.hxx>
#include <GCPnts_QuasiUniformAbscissa.hxx>

#include <TopoDS.hxx>
#include <TopoDS_Shape.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TopLoc_Location.hxx>

#include <BRepLib.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <BRepBuilderAPI_MakeShell.hxx>
#include <BRepBuilderAPI_WireError.hxx>

#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <BRepPrimAPI_MakeRevolution.hxx>

#include <BRepFill.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>

#include <BRepOffsetAPI_MakePipe.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <BRepOffsetAPI_DraftAngle.hxx>

#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Section.hxx>
#include <BOPAlgo_Section.hxx>

#include <BRepTools_WireExplorer.hxx>
#include <BRepGProp.hxx>

#include <ShapeFix_Shape.hxx>
#include <ShapeFix_Wireframe.hxx>

#include <STEPControl_Writer.hxx>
#include <STEPControl_Reader.hxx>
#include <IGESControl_Controller.hxx> 
#include <IGESControl_Writer.hxx>
#include <IGESControl_Reader.hxx>
#include <Interface_Static.hxx>

// STL headers
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <math.h>
#include <utility>

// Qt headers
#include <QtWidgets/QMainWindow>
#include <QWidget> 
#include <QEventLoop>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QStyleFactory> 
#include <QTextStream> 
#include <QScrollBar>
#include <QSharedPointer>
#include <QDialog>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#endif