#include "stdafx.h"

#include "QtOcct.h"

namespace part
{
	TopoDS_Compound makeBottleFunc(const Standard_Real, const Standard_Real, const Standard_Real);
}

void QtOcct::makeBottleSlot()
{
	textEdit->insertPlainText("Making a demo bottle part... ");
	textEdit->repaint();
	Standard_Real myWidth = 50;
	Standard_Real myHeight = 70;
	Standard_Real myThickness = 30;
	
	if (partIsActive)
		myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
	else
		partIsActive = true; // First time a part has been added to context

	myCurrentPart = part::makeBottleFunc(myWidth, myHeight, myThickness);

	if (myAisShape.IsNull())
		myAisShape = new AIS_Shape(myCurrentPart);
	else
	{
		myAisShape.Nullify();
		myAisShape = new AIS_Shape(myCurrentPart);
	}

	myContext->Display(myAisShape);
	textEdit->insertPlainText("Success!\nNote: This is a solid part, not a surface, and is not suitable for incremental sheet forming toolpath generation.\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::makeBoxSlot()
{
	TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox(40.0, 30.0, 50.0).Shape();
	TopoDS_Compound tempCompound;
	BRep_Builder aBuilder;
	aBuilder.MakeCompound(tempCompound);
	aBuilder.Add(tempCompound, aTopoBox);

	if (partIsActive)
		myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
	else
		partIsActive = true; // First time a part has been added to context

	myCurrentPart = tempCompound;

	if (myAisShape.IsNull())
		myAisShape = new AIS_Shape(myCurrentPart);
	else
	{
		myAisShape.Nullify();
		myAisShape = new AIS_Shape(myCurrentPart);
	}

	myAisShape = new AIS_Shape(myCurrentPart);
	myAisShape->SetColor(Quantity_NOC_RED);

	myContext->Display(myAisShape);
	textEdit->insertPlainText("Making a demo box... Success!\nNote: This is a solid part, not a surface, and is not suitable for incremental sheet forming toolpath generation.\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::makeSphereSlot()
{
	gp_Dir aDir(0.0, 0.0, 1.0);
	gp_Pnt aPnt(0.0, 0.0, 0.0);
	gp_Ax2 anAxis(aPnt, aDir);

	TopoDS_Shape aTopoSphere = BRepPrimAPI_MakeSphere(anAxis, 20.0).Shape();

	TopoDS_Compound tempCompound;
	BRep_Builder aBuilder;
	aBuilder.MakeCompound(tempCompound);
	aBuilder.Add(tempCompound, aTopoSphere);

	if (partIsActive)
		myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
	else
		partIsActive = true; // First time a part has been added to context

	myCurrentPart = tempCompound;

	if (myAisShape.IsNull())
		myAisShape = new AIS_Shape(myCurrentPart);
	else
	{
		myAisShape.Nullify();
		myAisShape = new AIS_Shape(myCurrentPart);
	}

	myAisShape = new AIS_Shape(myCurrentPart);
	myAisShape->SetColor(Quantity_NOC_BLUE1);

	myContext->Display(myAisShape);
	textEdit->insertPlainText("Making a deom sphere part... Success!\nNote: This is a solid part, not a surface, and is not suitable for incremental sheet forming toolpath generation.\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

TopoDS_Compound part::makeBottleFunc(Standard_Real myWidth, Standard_Real myHeight, Standard_Real myThickness)
{
	// Profile : Define Support Points
	gp_Pnt aPnt1(-myWidth / 2., 0, 0);
	gp_Pnt aPnt2(-myWidth / 2., -myThickness / 4., 0);
	gp_Pnt aPnt3(0, -myThickness / 2., 0);
	gp_Pnt aPnt4(myWidth / 2., -myThickness / 4., 0);
	gp_Pnt aPnt5(myWidth / 2., 0, 0);

	// Profile : Define the Geometry
	Handle(Geom_TrimmedCurve) anArcOfCircle = GC_MakeArcOfCircle(aPnt2, aPnt3, aPnt4);
	Handle(Geom_TrimmedCurve) aSegment1 = GC_MakeSegment(aPnt1, aPnt2);
	Handle(Geom_TrimmedCurve) aSegment2 = GC_MakeSegment(aPnt4, aPnt5);

	// Profile : Define the Topology
	TopoDS_Edge anEdge1 = BRepBuilderAPI_MakeEdge(aSegment1);
	TopoDS_Edge anEdge2 = BRepBuilderAPI_MakeEdge(anArcOfCircle);
	TopoDS_Edge anEdge3 = BRepBuilderAPI_MakeEdge(aSegment2);
	TopoDS_Wire aWire = BRepBuilderAPI_MakeWire(anEdge1, anEdge2, anEdge3);

	// Complete Profile
	gp_Ax1 xAxis = gp::OX();
	gp_Trsf aTrsf;

	aTrsf.SetMirror(xAxis);
	BRepBuilderAPI_Transform aBRepTrsf(aWire, aTrsf);
	TopoDS_Shape aMirroredShape = aBRepTrsf.Shape();
	TopoDS_Wire aMirroredWire = TopoDS::Wire(aMirroredShape);

	BRepBuilderAPI_MakeWire mkWire;
	mkWire.Add(aWire);
	mkWire.Add(aMirroredWire);
	TopoDS_Wire myWireProfile = mkWire.Wire();

	// Body : Prism the Profile
	TopoDS_Face myFaceProfile = BRepBuilderAPI_MakeFace(myWireProfile);
	gp_Vec aPrismVec(0, 0, myHeight);
	TopoDS_Shape myBody = BRepPrimAPI_MakePrism(myFaceProfile, aPrismVec);

	// Body : Apply Fillets
	BRepFilletAPI_MakeFillet mkFillet(myBody);
	TopExp_Explorer anEdgeExplorer(myBody, TopAbs_EDGE);
	while (anEdgeExplorer.More()) {
		TopoDS_Edge anEdge = TopoDS::Edge(anEdgeExplorer.Current());
		//Add edge to fillet algorithm
		mkFillet.Add(myThickness / 12., anEdge);
		anEdgeExplorer.Next();
	}

	myBody = mkFillet.Shape();

	// Body : Add the Neck
	gp_Pnt neckLocation(0, 0, myHeight);
	gp_Dir neckAxis = gp::DZ();
	gp_Ax2 neckAx2(neckLocation, neckAxis);

	Standard_Real myNeckRadius = myThickness / 4.;
	Standard_Real myNeckHeight = myHeight / 10.;

	BRepPrimAPI_MakeCylinder MKCylinder(neckAx2, myNeckRadius, myNeckHeight);
	TopoDS_Shape myNeck = MKCylinder.Shape();

	myBody = BRepAlgoAPI_Fuse(myBody, myNeck);

	// Body : Create a Hollowed Solid
	TopoDS_Face   faceToRemove;
	Standard_Real zMax = -1;

	for (TopExp_Explorer aFaceExplorer(myBody, TopAbs_FACE); aFaceExplorer.More(); aFaceExplorer.Next())
	{
		TopoDS_Face aFace = TopoDS::Face(aFaceExplorer.Current());
		// Check if <aFace> is the top face of the bottle's neck 
		Handle(Geom_Surface) aSurface = BRep_Tool::Surface(aFace);
		if (aSurface->DynamicType() == STANDARD_TYPE(Geom_Plane))
		{
			Handle(Geom_Plane) aPlane = Handle(Geom_Plane)::DownCast(aSurface);
			gp_Pnt aPnt = aPlane->Location();
			Standard_Real aZ = aPnt.Z();
			if (aZ > zMax)
			{
				zMax = aZ;
				faceToRemove = aFace;
			}
		}
	}

	TopTools_ListOfShape facesToRemove;
	facesToRemove.Append(faceToRemove);
	myBody = BRepOffsetAPI_MakeThickSolid(myBody, facesToRemove, -myThickness / 50, 1.e-3);
	// Threading : Create Surfaces
	Handle(Geom_CylindricalSurface) aCyl1 = new Geom_CylindricalSurface(neckAx2, myNeckRadius * 0.99);
	Handle(Geom_CylindricalSurface) aCyl2 = new Geom_CylindricalSurface(neckAx2, myNeckRadius * 1.05);

	// Threading : Define 2D Curves
	gp_Pnt2d aPnt(2. * M_PI, myNeckHeight / 2.);
	gp_Dir2d aDir(2. * M_PI, myNeckHeight / 4.);
	gp_Ax2d anAx2d(aPnt, aDir);

	Standard_Real aMajor = 2. * M_PI;
	Standard_Real aMinor = myNeckHeight / 10;

	Handle(Geom2d_Ellipse) anEllipse1 = new Geom2d_Ellipse(anAx2d, aMajor, aMinor);
	Handle(Geom2d_Ellipse) anEllipse2 = new Geom2d_Ellipse(anAx2d, aMajor, aMinor / 4);
	Handle(Geom2d_TrimmedCurve) anArc1 = new Geom2d_TrimmedCurve(anEllipse1, 0, M_PI);
	Handle(Geom2d_TrimmedCurve) anArc2 = new Geom2d_TrimmedCurve(anEllipse2, 0, M_PI);
	gp_Pnt2d anEllipsePnt1 = anEllipse1->Value(0);
	gp_Pnt2d anEllipsePnt2 = anEllipse1->Value(M_PI);

	Handle(Geom2d_TrimmedCurve) aSegment = GCE2d_MakeSegment(anEllipsePnt1, anEllipsePnt2);
	// Threading : Build Edges and Wires
	TopoDS_Edge anEdge1OnSurf1 = BRepBuilderAPI_MakeEdge(anArc1, aCyl1);
	TopoDS_Edge anEdge2OnSurf1 = BRepBuilderAPI_MakeEdge(aSegment, aCyl1);
	TopoDS_Edge anEdge1OnSurf2 = BRepBuilderAPI_MakeEdge(anArc2, aCyl2);
	TopoDS_Edge anEdge2OnSurf2 = BRepBuilderAPI_MakeEdge(aSegment, aCyl2);
	TopoDS_Wire threadingWire1 = BRepBuilderAPI_MakeWire(anEdge1OnSurf1, anEdge2OnSurf1);
	TopoDS_Wire threadingWire2 = BRepBuilderAPI_MakeWire(anEdge1OnSurf2, anEdge2OnSurf2);
	BRepLib::BuildCurves3d(threadingWire1);
	BRepLib::BuildCurves3d(threadingWire2);

	// Create Threading 
	BRepOffsetAPI_ThruSections aTool(Standard_True);
	aTool.AddWire(threadingWire1);
	aTool.AddWire(threadingWire2);
	aTool.CheckCompatibility(Standard_False);

	TopoDS_Shape myThreading = aTool.Shape();

	// Building the Resulting Compound 
	TopoDS_Compound aRes;
	BRep_Builder aBuilder;
	aBuilder.MakeCompound(aRes);
	aBuilder.Add(aRes, myBody);
	aBuilder.Add(aRes, myThreading);

	return aRes;
}
