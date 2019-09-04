#include "stdafx.h"

#include "QtOcct.h"

void QtOcct::makeFunnelSlot()
{
	TopoDS_Compound tempTopoDsCompound;
	bool makeFunnelSuccess;
	QString makeFunnelMsg;

	QString baseRadStr = myFunnelDialog->getBaseDiamLineEdit().trimmed();
	QString initWallAngStr = myFunnelDialog->getInitWallAngleLineEdit().trimmed();
	QString funArcRadStr = myFunnelDialog->getRadOfArcLineEdit().trimmed();
	QString depthStr = myFunnelDialog->getDepthLineEdit().trimmed();
	QString filletRadStr = myFunnelDialog->getFilletRadLineEdit().trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;
	bool str2floatOK4 = false;
	bool str2floatOK5 = false;

	baseRadStr.toFloat(&str2floatOK1);
	initWallAngStr.toFloat(&str2floatOK2);
	funArcRadStr.toFloat(&str2floatOK3);
	depthStr.toFloat(&str2floatOK4);
	filletRadStr.toFloat(&str2floatOK5);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3 || !str2floatOK4 || !str2floatOK5)
	{
		textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	Standard_Real baseRad = (abs(baseRadStr.toFloat()))/2.0;
	Standard_Real initWallAng = abs(initWallAngStr.toFloat());
	Standard_Real funArcRad = abs(funArcRadStr.toFloat());
	Standard_Real depth = abs(depthStr.toFloat());
	Standard_Real filletRad = abs(filletRadStr.toFloat());
	Standard_Real TOL = 0.002;

	if (partIsActive)
		myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
	else
		partIsActive = true; // First time a part has been added to context

	textEdit->insertPlainText("Creating a funnel... ");
	textEdit->repaint();

	makeFunnelSuccess = part::makeFunnel(baseRad, initWallAng, funArcRad, depth, filletRad, TOL, tempTopoDsCompound, makeFunnelMsg);

	if (makeFunnelSuccess)
	{
		myCurrentPart = tempTopoDsCompound;
		//TopAbs_ShapeEnum myShapeType = myCurrentPart.ShapeType();

		if (myAisShape.IsNull())
			myAisShape = new AIS_Shape(myCurrentPart);
		else
		{
			myAisShape.Nullify();
			myAisShape = new AIS_Shape(myCurrentPart);
		}

		myContext->Display(myAisShape);
		textEdit->insertPlainText(makeFunnelMsg);
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
	else
	{
		textEdit->insertPlainText(makeFunnelMsg);
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}
}

void QtOcct::makePyramidSlot()
{
	TopoDS_Compound tempTopoDsCompound;
	bool makePyramidSuccess;
	QString makePyramidMsg;

	QString baseWidthStr = myPyramidDialog->getBaseDiamLineEdit().trimmed();
	QString wallAngleStr = myPyramidDialog->getWallAngleLineEdit().trimmed();
	QString depthStr = myPyramidDialog->getDepthLineEdit().trimmed();
	QString filletRadStr = myPyramidDialog->getFilletRadLineEdit().trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;
	bool str2floatOK4 = false;

	baseWidthStr.toFloat(&str2floatOK1);
	wallAngleStr.toFloat(&str2floatOK2);
	depthStr.toFloat(&str2floatOK3);
	filletRadStr.toFloat(&str2floatOK4);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3 || !str2floatOK4)
	{
		textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	Standard_Real baseWidth = abs(baseWidthStr.toFloat());
	Standard_Real wallAngle = abs(wallAngleStr.toFloat());
	Standard_Real depth = abs(depthStr.toFloat());
	Standard_Real filletRad = abs(filletRadStr.toFloat());
	Standard_Real TOL = 0.002;

	if (partIsActive)
		myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
	else
		partIsActive = true; // First time a part has been added to context

	textEdit->insertPlainText("Creating a truncated pyramid... ");
	textEdit->repaint();
	makePyramidSuccess = part::makePyramid(baseWidth, wallAngle, depth, filletRad, TOL, tempTopoDsCompound, makePyramidMsg);

	if (makePyramidSuccess)
	{
		myCurrentPart = tempTopoDsCompound;
		//TopAbs_ShapeEnum myShapeType = myCurrentPart.ShapeType();
		if (myAisShape.IsNull())
			myAisShape = new AIS_Shape(myCurrentPart);
		else
		{
			myAisShape.Nullify();
			myAisShape = new AIS_Shape(myCurrentPart);
		}

		myContext->Display(myAisShape);
		textEdit->insertPlainText(makePyramidMsg);
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
	else
	{
		textEdit->insertPlainText(makePyramidMsg);
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}
}

void QtOcct::makeTrunConeSlot()
{
	TopoDS_Compound tempTopoDsCompound;
	bool makeTrunConeSuccess;
	QString makeTrunConeMsg;

	QString baseRadStr = myTrunConeDialog->getBaseDiamLineEdit().trimmed();
	QString wallAngleStr = myTrunConeDialog->getWallAngleLineEdit().trimmed();
	QString depthStr = myTrunConeDialog->getDepthLineEdit().trimmed();
	QString filletRadStr = myTrunConeDialog->getFilletRadLineEdit().trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;
	bool str2floatOK4 = false;

	baseRadStr.toFloat(&str2floatOK1);
	wallAngleStr.toFloat(&str2floatOK2);
	depthStr.toFloat(&str2floatOK3);
	filletRadStr.toFloat(&str2floatOK4);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3 || !str2floatOK4)
	{
		textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	Standard_Real baseRad = (abs(baseRadStr.toFloat()))/2.0;
	Standard_Real wallAngle = abs(wallAngleStr.toFloat());
	Standard_Real depth = abs(depthStr.toFloat());
	Standard_Real filletRad = abs(filletRadStr.toFloat());
	Standard_Real TOL = 0.002;

	if (partIsActive)
		myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
	else
		partIsActive = true; // First time a part has been added to context

	textEdit->insertPlainText("Creating a truncated cone... ");
	textEdit->repaint();
	makeTrunConeSuccess = part::makeTrunCone(baseRad, wallAngle, depth, filletRad, TOL, tempTopoDsCompound, makeTrunConeMsg);

	if (makeTrunConeSuccess)
	{
		myCurrentPart = tempTopoDsCompound;
		//TopAbs_ShapeEnum myShapeType = myCurrentPart.ShapeType();
		if (myAisShape.IsNull())
			myAisShape = new AIS_Shape(myCurrentPart);
		else
		{
			myAisShape.Nullify();
			myAisShape = new AIS_Shape(myCurrentPart);
		}

		myContext->Display(myAisShape);
		textEdit->insertPlainText(makeTrunConeMsg);
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
	else
	{
		textEdit->insertPlainText(makeTrunConeMsg);
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}
}

bool part::makeFunnel(const Standard_Real &baseRad, const Standard_Real &initWallAng,
	const Standard_Real &funArcRad, const Standard_Real &depth, const Standard_Real &filletRad,
	const Standard_Real &TOL, TopoDS_Compound &myFunnelOut, QString &logOut)
{
	gp_Pnt originPnt(0.0, 0.0, 0.0);
	gp_Pnt botCenterPnt(0.0, 0.0, -depth);
	gp_Pnt topFunnelRimPnt(baseRad, 0.0, 0.0);
	gp_Pnt topFunnelPerimPnt(2.0*baseRad, 0.0, 0.0);
	gp_Pnt circCenterPnt(baseRad + funArcRad*sin(initWallAng*PI / 180.0), 0.0, -(funArcRad*cos(initWallAng*PI / 180.0)));
	Standard_Real finalCircAngleOriginal = 180.0 - (asin(cos(initWallAng*PI / 180.0) - (depth/funArcRad)))*180/PI; // In Degrees
	Standard_Real finalCircAngleFilletOut = 180.0 - (asin(cos(initWallAng*PI / 180.0) - ((depth - filletRad)/ funArcRad))) * 180 / PI; // In Degrees

	if (baseRad == 0.0 || funArcRad == 0.0 || depth == 0.0 || filletRad == 0.0)
	{
		logOut = logOut.append("\nERROR: Cannot have zero-valued inputs.\n");
		return false;
	}
	else if ((90 - (180.0 - finalCircAngleFilletOut)) >= 90.0)
	{
		logOut = logOut.append("\nERROR: Max wall angle on the funnel prior to adding fillets exceeds 90.0 deg. Reduce part depth or increase the funnel's radius of arc.\n");
		return false;
	}

	gp_Dir normalDirCirc(0.0, -1.0, 0.0);
	gp_Dir xDir2NormalCirc(1.0, 0.0, 0.0);
	gp_Ax2 funnelCircAx2(circCenterPnt, normalDirCirc, xDir2NormalCirc);
	gp_Circ funnelCircGp(funnelCircAx2, funArcRad);
	
	Handle(Geom_TrimmedCurve) funnelPerimTrimCurve = GC_MakeSegment(topFunnelPerimPnt, topFunnelRimPnt);
	Handle(Geom_TrimmedCurve) arcFunnelTrimCurv = GC_MakeArcOfCircle(funnelCircGp, 90.0*PI/180.0 + initWallAng*PI/180.0, finalCircAngleOriginal*PI/180.0, true);
	gp_Pnt tempCurvePnt1 = arcFunnelTrimCurv->StartPoint();
	gp_Pnt tempCurvePnt2 = arcFunnelTrimCurv->EndPoint();
	gp_Pnt topArcCurvePnt;
	gp_Pnt botArcCurvePnt;
	if (tempCurvePnt1.Z() > tempCurvePnt2.Z())
	{
		topArcCurvePnt = tempCurvePnt1;
		botArcCurvePnt = tempCurvePnt2;
	}
	else
	{
		topArcCurvePnt = tempCurvePnt2;
		botArcCurvePnt = tempCurvePnt1;
	}

	if (!(abs(topArcCurvePnt.X() - baseRad) < TOL) || !(abs(topArcCurvePnt.Z()) < TOL))
	{
		logOut = logOut.append("\nERROR: Failed to make arc cross-section with the start point on the X-axis.\n");
		return false;
	}

	Handle(Geom_TrimmedCurve) botHorizTrimCurve = GC_MakeSegment(botArcCurvePnt, botCenterPnt);

	TopoDS_Edge funnelPerimEdge = BRepBuilderAPI_MakeEdge(funnelPerimTrimCurve);
	TopoDS_Edge arcFunnelEdge = BRepBuilderAPI_MakeEdge(arcFunnelTrimCurv);
	TopoDS_Edge botHorizEdge = BRepBuilderAPI_MakeEdge(botHorizTrimCurve);
	
	TopoDS_Wire funnelCrossSectionWire;
	BRepBuilderAPI_MakeWire funnelCrossSectionBuilder = BRepBuilderAPI_MakeWire(funnelPerimEdge, arcFunnelEdge, botHorizEdge);
	if (!funnelCrossSectionBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not stitch together the 3 line curves that defines the funnel's cross section.\n");
		return false;
	}
	funnelCrossSectionWire = funnelCrossSectionBuilder.Wire();

	gp_Ax1 axisOfRev(originPnt, gp_Dir(0.0, 0.0, 1.0));
	BRepPrimAPI_MakeRevol revBuilder = BRepPrimAPI_MakeRevol(funnelCrossSectionWire, axisOfRev, false);
	if (!revBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not revolve cross-section profile.\n");
		return false;
	}

	TopoDS_Shape funnelNoFilletShape = revBuilder.Shape();
	TopAbs_ShapeEnum coneShapeType = funnelNoFilletShape.ShapeType();
	if (coneShapeType != TopAbs_ShapeEnum::TopAbs_SHELL)
	{
		logOut = logOut.append("\nERROR: Final revolved part was not found to be a shell surface.\n");
		return false;
	}
	TopoDS_Shell funnelNoFilletShell = TopoDS::Shell(funnelNoFilletShape);

	TopTools_IndexedMapOfShape edgeMap;
	TopExp::MapShapes(funnelNoFilletShell, TopAbs_ShapeEnum::TopAbs_EDGE, edgeMap);
	TColStd_Array1OfInteger faceCount(1, edgeMap.Extent());
	faceCount.Init(0);
	TopExp_Explorer explorerFace(funnelNoFilletShell, TopAbs_ShapeEnum::TopAbs_FACE);
	while (explorerFace.More())
	{
		TopExp_Explorer explorerEdge(TopoDS::Face(explorerFace.Current()), TopAbs_ShapeEnum::TopAbs_EDGE);
		while (explorerEdge.More())
		{
			faceCount(edgeMap.FindIndex(TopoDS::Edge(explorerEdge.Current())))++; // Increment face count by one for the current edge
			explorerEdge.Next();
		}
		explorerFace.Next();
	}

	BRepFilletAPI_MakeFillet funnelFilletBuilder(funnelNoFilletShell);
	Standard_Integer indxI;
	TColStd_Array1OfInteger indexOfFilletEdges(1, edgeMap.Extent());

	for (indxI = 1; indxI <= edgeMap.Extent(); indxI++)
	{
		if (faceCount(indxI) > 1) // A shared edge will have more than 1 face connected to it
		{
			funnelFilletBuilder.Add(filletRad, TopoDS::Edge(edgeMap(indxI)));
		}
	}
	funnelFilletBuilder.Build();

	if (!funnelFilletBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not fillet all shared edges. Try decreasing the part depth, decreasing the fillet radius, or increasing the opening diameter.\n");
		return false;
	}
	TopoDS_Shape funnelShapeFilleted;
	funnelShapeFilleted = funnelFilletBuilder.Shape();
	
	// Build a shell from the compound to ensure the correct topology exists for toolpaths
	TopoDS_Shell funnelShellFilleted;
	BRep_Builder TopoDsShellBuilder;
	TopoDsShellBuilder.MakeShell(funnelShellFilleted);
	explorerFace.Init(funnelShapeFilleted, TopAbs_ShapeEnum::TopAbs_FACE);
	while (explorerFace.More())
	{
		TopoDsShellBuilder.Add(funnelShellFilleted, TopoDS::Face(explorerFace.Current()));
		explorerFace.Next();
	}

	// Find max wall angle at the top of the bottom-most fillet; Explore all vertices to find the Z-coordinate of this location.
	TopExp_Explorer explorerVertex1(funnelShellFilleted, TopAbs_ShapeEnum::TopAbs_VERTEX);
	TopTools_IndexedMapOfShape vertexMap;
	TopExp::MapShapes(funnelShellFilleted, TopAbs_ShapeEnum::TopAbs_VERTEX, vertexMap);
	TColStd_Array1OfReal vertexZDepths(1, vertexMap.Extent());
	TColStd_Array1OfInteger vertexIndicesZSorted(1, vertexMap.Extent());
	while (explorerVertex1.More())
	{
		TopoDS_Vertex currentTopoVertex = TopoDS::Vertex(explorerVertex1.Current());
		gp_Pnt currentPnt = BRep_Tool::Pnt(currentTopoVertex);
		Standard_Real currentZCoord = currentPnt.Z();
		Standard_Integer tempCurrentIndex = vertexMap.FindIndex(explorerVertex1.Current());
		vertexZDepths(tempCurrentIndex) = currentZCoord;
		vertexIndicesZSorted(tempCurrentIndex) = tempCurrentIndex;
		explorerVertex1.Next();
	}

	for (Standard_Integer ii=1; ii <= vertexMap.Extent(); ii++) // Doing a simple bubble sort
	{
		for (Standard_Integer jj=1; jj < vertexMap.Extent(); jj++)
		{
			if (vertexZDepths(jj) > vertexZDepths(jj + 1))
			{
				Standard_Real tempZDepth = vertexZDepths(jj + 1); // Move smaller value towards the beginning of the array
				vertexZDepths(jj + 1) = vertexZDepths(jj);
				vertexZDepths(jj) = tempZDepth;

				Standard_Integer tempZIndex = vertexIndicesZSorted(jj + 1); // Perform same operation on the index array
				vertexIndicesZSorted(jj + 1) = vertexIndicesZSorted(jj);
				vertexIndicesZSorted(jj) = tempZIndex;
			}
		}
	}

	Standard_Boolean foundVertex = false;
	Standard_Integer ii = 0;
	Standard_Integer maxWallAngleVertexIndex;
	Standard_Real lastIterZDepth = vertexZDepths(1);
	Standard_Real maxWallAngleDepth;
	while (ii <= vertexMap.Extent())
	{
		ii = ii + 1;
		Standard_Real currZDepth = vertexZDepths(ii);

		if (abs(currZDepth - lastIterZDepth) > TOL) // Find the second deepest vertex
		{
			maxWallAngleDepth = currZDepth;
			maxWallAngleVertexIndex = vertexIndicesZSorted(ii);
			break;
		}
		
	}
	TopoDS_Vertex maxWallAngVertex = TopoDS::Vertex(vertexMap(maxWallAngleVertexIndex)); // Can visualize this vertex to ensure the algorithm worked
	gp_Pnt maxWallAngOnSurfPoint = BRep_Tool::Pnt(maxWallAngVertex);
	gp_Pnt maxWallAngProjectionPnt(maxWallAngOnSurfPoint.X() - 10.0*TOL, maxWallAngOnSurfPoint.Y() + 2.0*TOL, maxWallAngOnSurfPoint.Z() + 2.0*TOL);

	// Need to find the surface of revolution
	// Going to project a the recently found fillet vertex back on to the surface to get it's local U and V parameters
	TopExp_Explorer explorerFace1(funnelShellFilleted, TopAbs_ShapeEnum::TopAbs_FACE);
	TopExp_Explorer explorerVertex2;
	Standard_Boolean foundRevolutionFace = false;
	TopoDS_Face revolutionFace;
	while (explorerFace1.More())
	{
		TopoDS_Face currentFace = TopoDS::Face(explorerFace1.Current());
		explorerVertex1.Init(currentFace, TopAbs_ShapeEnum::TopAbs_VERTEX);
		explorerVertex2.Init(currentFace, TopAbs_ShapeEnum::TopAbs_VERTEX);
		while (explorerVertex1.More())
		{
			TopoDS_Vertex currentVertex1 = TopoDS::Vertex(explorerVertex1.Current());
			gp_Pnt currentPnt1 = BRep_Tool::Pnt(currentVertex1);
			if (currentVertex1 == maxWallAngVertex)
			{
				while (explorerVertex2.More())
				{
					TopoDS_Vertex currentVertex2 = TopoDS::Vertex(explorerVertex2.Current());
					gp_Pnt currentPnt2 = BRep_Tool::Pnt(currentVertex2);
					if ((currentVertex2 != currentVertex1) && (currentPnt2.Z() > currentPnt1.Z()))
					{
						revolutionFace = currentFace;
						foundRevolutionFace = true;
						break;
					}
					explorerVertex2.Next();
				}
			}

			if (foundRevolutionFace)
				break;
			explorerVertex1.Next();
		}

		if (foundRevolutionFace)
			break;
		explorerFace1.Next();
	}

	// Get the local U and V parameters now
	Handle(Geom_Surface) revolutionSurface = BRep_Tool::Surface(revolutionFace);
	GeomAPI_ProjectPointOnSurf maxWallAnglePntProjectionBuilder(maxWallAngProjectionPnt, revolutionSurface, TOL);
	Standard_Real revolutionSurfUParam, revolutionSurfVParam;
	gp_Pnt maxWallAngleClosestProjPnt = maxWallAnglePntProjectionBuilder.NearestPoint();
	maxWallAnglePntProjectionBuilder.LowerDistanceParameters(revolutionSurfUParam, revolutionSurfVParam);
	BRepBuilderAPI_MakeVertex vertexBuilder(maxWallAngleClosestProjPnt);
	TopoDS_Vertex maxWallAngleClosestProjVertex = vertexBuilder.Vertex();
	
	// Finally, can use local surface properties tool to grab the surface normal 
	GeomLProp_SLProps revolveSurfProps(revolutionSurface, revolutionSurfUParam, revolutionSurfVParam, 1, TOL);
	gp_Dir maxWallAngleDir;
	if (!revolveSurfProps.IsNormalDefined())
	{
		logOut = logOut.append("\nERROR: Could not get the surface normal.\n");
		return false;
	}
	maxWallAngleDir = revolveSurfProps.Normal();
	Standard_Real maxWallAngleAtFilletDeg = (PI/2.0 - maxWallAngleDir.Angle(gp_Dir(maxWallAngleDir.X(), maxWallAngleDir.Y(), 0.0)))*180.0/PI;

	TopoDS_Compound tempTopoDsCompound;
	BRep_Builder TopoDsCompoundBuilder;
	TopoDsCompoundBuilder.MakeCompound(tempTopoDsCompound);
	TopoDsCompoundBuilder.Add(tempTopoDsCompound, funnelShellFilleted);
	//TopoDsCompoundBuilder.Add(tempTopoDsCompound, revolutionFace);
	//TopoDsCompoundBuilder.Add(tempTopoDsCompound, maxWallAngleClosestProjVertex);

	myFunnelOut = tempTopoDsCompound;
	logOut = logOut.append("Success!\n");
	QString maxWallAngMsg1 = "Max Wall Angle: ";
	//QString maxWallAngMsg2 = QString::number(90 - (180.0 - finalCircAngleOriginal));
	//QString maxWallAngMsg3 = "  From Fillet Calculation: ";
	QString maxWallAngMsg4 = QString::number(maxWallAngleAtFilletDeg);
	QString maxWallAngMsg5= " deg\n";
	logOut = logOut.append(maxWallAngMsg1 + maxWallAngMsg4 + maxWallAngMsg5);
	return true;
}

bool part::makePyramid(const Standard_Real &baseWidth, const Standard_Real &wallAngle,
	const Standard_Real &depth, const Standard_Real &filletRad,
	const Standard_Real &TOL, TopoDS_Compound &myPyramidOut, QString &logOut)
{
	Standard_Real baseRad = baseWidth / 2.0;
	Standard_Real wPyramid = abs(tan(wallAngle*PI / 180.0));
	if (wPyramid == 0.0)
	{
		logOut = logOut.append("\nERROR: Wall angle is 0.0 deg.\n");
		return false;
	}
	else if (wallAngle >= 90.0)
	{
		logOut = logOut.append("\nERROR: Wall angle is equal to or greater than 90.0 deg.\n");
		return false;
	}
	else if (baseWidth == 0.0 || wallAngle == 0.0 || depth == 0.0 || filletRad == 0.0)
	{
		logOut = logOut.append("\nERROR: Cannot have zero-valued inputs.\n");
		return false;
	}
	wPyramid = depth / wPyramid;

	Standard_Real botPyramRad = baseRad - wPyramid;
	Standard_Real dFilletCalc = filletRad - filletRad*cos(wallAngle*PI / 180.0);
	gp_Pnt2d p0FilletCalc(filletRad*sin(wallAngle*PI / 180.0), -filletRad*cos(wallAngle*PI / 180.0));
	gp_Pnt2d p1FilletCalc(p0FilletCalc.X() + dFilletCalc*tan(wallAngle*PI / 180.0), p0FilletCalc.Y() - dFilletCalc);
	Standard_Real lenP0P1FilletCalc = sqrt(pow(p1FilletCalc.X() - p0FilletCalc.X(), 2.0) + pow(p1FilletCalc.Y() - p0FilletCalc.Y(), 2.0));
	Standard_Real widthBotFilletCalc = lenP0P1FilletCalc*tan((90 - wallAngle)*PI / 180.0);
	if ((botPyramRad - widthBotFilletCalc) <= TOL)
	{
		logOut = logOut.append("\nERROR: Depth is too deep and causes a self-intersecting surface. Please either increase the wall angle, increase part diameter, decrease fillet radius, or decrease part depth.\n");
		return false;
	}
	else if ((depth/2.0 - dFilletCalc) <= TOL)
	{
		logOut = logOut.append("\nERROR: Fillet radius is too large with respect to the depth of the part.\n");
		return false;
	}
	else if ((baseRad - filletRad) <= TOL)
	{
		logOut = logOut.append("\nERROR: Fillet radius is too large with respect to the part's width.\n");
		return false;
	}

	// Input seems OK, then start to make the bottom face wire profile
	gp_Pnt aPntOrigin(0.0, 0.0, 0.0);
	gp_Pnt aPntBot1(-botPyramRad, -botPyramRad, -depth);
	gp_Pnt aPntBot2(botPyramRad, -botPyramRad, -depth);
	gp_Pnt aPntBot3(botPyramRad, botPyramRad, -depth);
	gp_Pnt aPntBot4(-botPyramRad, botPyramRad, -depth);

	Handle(Geom_TrimmedCurve) botTrimCurve12 = GC_MakeSegment(aPntBot1, aPntBot2);
	Handle(Geom_TrimmedCurve) botTrimCurve23 = GC_MakeSegment(aPntBot2, aPntBot3);
	Handle(Geom_TrimmedCurve) botTrimCurve34 = GC_MakeSegment(aPntBot3, aPntBot4);
	Handle(Geom_TrimmedCurve) botTrimCurve41 = GC_MakeSegment(aPntBot4, aPntBot1);

	TopoDS_Edge botEdge12 = BRepBuilderAPI_MakeEdge(botTrimCurve12);
	TopoDS_Edge botEdge23 = BRepBuilderAPI_MakeEdge(botTrimCurve23);
	TopoDS_Edge botEdge34 = BRepBuilderAPI_MakeEdge(botTrimCurve34);
	TopoDS_Edge botEdge41 = BRepBuilderAPI_MakeEdge(botTrimCurve41);

	TopoDS_Wire botSqrWire;
	BRepBuilderAPI_MakeWire botWireBuilder = BRepBuilderAPI_MakeWire(botEdge12, botEdge23, botEdge34, botEdge41);
	if (!botWireBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not build the bottom square profile consisting of 4 line segments.\n");
		return false;
	}
	botSqrWire = botWireBuilder.Wire();

	// Extrude the profile linearly upward towards the origin
	gp_Dir pyramExtrudeDir(0.0, 0.0, 1.0);
	gp_Vec pyramExtrudeVec(pyramExtrudeDir);
	pyramExtrudeVec.Scale(depth);
	TopoDS_Shape botPyramSqrPrism;
	BRepPrimAPI_MakePrism botPyramSqrPrismBuilder(botSqrWire, pyramExtrudeVec, false, true);
	if (!botPyramSqrPrismBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not do a linear extrude of the bottom square profile.\n");
		return false;
	}
	botPyramSqrPrism = botPyramSqrPrismBuilder.Shape();

	if (!(TopAbs_ShapeEnum::TopAbs_SHELL == botPyramSqrPrism.ShapeType()))
	{
		logOut = logOut.append("\nERROR: Resultant linear extrude of the bottom square profile did not result in a shell-type surface.\n");
		return false;
	}
	TopoDS_Shell botPyramSqrPrismShell = TopoDS::Shell(botPyramSqrPrism);

	// Collect all four faces into a shape container, and use these faces in a draft angle operation
	TopTools_ListOfShape listOfFace;
	TopExp_Explorer explorer1;
	for (explorer1.Init(botPyramSqrPrismShell, TopAbs_FACE); explorer1.More(); explorer1.Next()) 
	{
		listOfFace.Append(explorer1.Current());
	}
	
	gp_Pln draftNeutralPlane(gp_Pnt(0.0, 0.0, -depth), pyramExtrudeDir);
	BRepOffsetAPI_DraftAngle pyramDraftAngleBuilder(botPyramSqrPrismShell);
	TopTools_ListIteratorOfListOfShape it1;
	for (it1.Initialize(listOfFace); it1.More(); it1.Next())
	{
		pyramDraftAngleBuilder.Add(TopoDS::Face(it1.Value()), pyramExtrudeDir, (90.0 - wallAngle)*PI/180.0, draftNeutralPlane);
		if (!pyramDraftAngleBuilder.AddDone())
		{
			break;
		}
	}

	if (!pyramDraftAngleBuilder.AddDone())
	{
		TopoDS_Shape guilty = pyramDraftAngleBuilder.ProblematicShape();
		logOut = logOut.append("\nERROR: Could not add specified face to the draft angle.\n");
		return false;
	}

	pyramDraftAngleBuilder.Build();
	if (!pyramDraftAngleBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Failed to build draft angle from the pyramid's square base.\n");
		return false;
	}
	TopoDS_Shape pyramDraftShape = pyramDraftAngleBuilder.Shape();

	if (!(TopAbs_ShapeEnum::TopAbs_SHELL == pyramDraftShape.ShapeType())) // Draft complete, cast back into a shell type
	{
		logOut = logOut.append("\nERROR: Resultant drafted shape did not result in a shell-type surface.\n");
		return false;
	}
	TopoDS_Shell pyramDraftShell = TopoDS::Shell(pyramDraftShape); 

	// Make bottom face
	BRepBuilderAPI_MakeFace botPyramFaceBuilder(draftNeutralPlane, botSqrWire);
	if (!botPyramFaceBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not make bottom face of the truncated pyramid.\n");
		return false;
	}
	TopoDS_Face botPyramFace = botPyramFaceBuilder.Face();

	// Make top face
	gp_Pnt aPntBot5(-2.0*baseRad, -2.0*baseRad, 0.0);
	gp_Pnt aPntBot6(2.0*baseRad, -2.0*baseRad, 0.0);
	gp_Pnt aPntBot7(2.0*baseRad, 2.0*baseRad, 0.0);
	gp_Pnt aPntBot8(-2.0*baseRad, 2.0*baseRad, 0.0);
	gp_Pln xyPlaneTOLneg(gp_Pnt(0.0, 0.0, -0.0002), gp_Dir(0.0, 0.0, 1.0));
	gp_Pln xyPlane(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(0.0, 0.0, 1.0));

	Handle(Geom_TrimmedCurve) topTrimCurve56 = GC_MakeSegment(aPntBot5, aPntBot6);
	Handle(Geom_TrimmedCurve) topTrimCurve67 = GC_MakeSegment(aPntBot6, aPntBot7);
	Handle(Geom_TrimmedCurve) topTrimCurve78 = GC_MakeSegment(aPntBot7, aPntBot8);
	Handle(Geom_TrimmedCurve) topTrimCurve85 = GC_MakeSegment(aPntBot8, aPntBot5);

	TopoDS_Edge topEdge56 = BRepBuilderAPI_MakeEdge(topTrimCurve56);
	TopoDS_Edge topEdge67 = BRepBuilderAPI_MakeEdge(topTrimCurve67);
	TopoDS_Edge topEdge78 = BRepBuilderAPI_MakeEdge(topTrimCurve78);
	TopoDS_Edge topEdge85 = BRepBuilderAPI_MakeEdge(topTrimCurve85);

	TopoDS_Wire topOutsideSqrWire;
	BRepBuilderAPI_MakeWire topOutsideSqrWireBuilder = BRepBuilderAPI_MakeWire(topEdge56, topEdge67, topEdge78, topEdge85);
	if (!topOutsideSqrWireBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not build the top perimeter square profile consisting of 4 line segments.\n");
		return false;
	}
	topOutsideSqrWire = topOutsideSqrWireBuilder.Wire();

	BRepBuilderAPI_MakeFace topOutsidePyramFaceBuilder(xyPlaneTOLneg, topOutsideSqrWire);
	if (!topOutsidePyramFaceBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not make top perimeter face connecting to the truncated pyramid.\n");
		return false;
	}
	TopoDS_Face topOutsidePyramFace = topOutsidePyramFaceBuilder.Face();

	// Intersect the walls with the XY-plane and make a wire
	BRepAlgoAPI_Section  pyramPlusTopFaceSectionBuilder(topOutsidePyramFace, pyramDraftShell);
	if (!pyramPlusTopFaceSectionBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not perform surface intersection operation between the pyramid's walls and the top face coincident with the XY-plane.\n");
		return false;
	}
	bool generatedShapes = pyramPlusTopFaceSectionBuilder.HasGenerated();
	TopoDS_Shape topPyramIntersectShape = pyramPlusTopFaceSectionBuilder.Shape();

	TopExp_Explorer explorer2;
	TopoDS_Wire topIntersectSqrWire;
	BRepBuilderAPI_MakeWire topIntersectSqrWireBuilder;
	for (explorer2.Init(topPyramIntersectShape, TopAbs_ShapeEnum::TopAbs_EDGE); explorer2.More(); explorer2.Next())
	{
		topIntersectSqrWireBuilder.Add(TopoDS::Edge(explorer2.Current()));
	}
	if (!topIntersectSqrWireBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not build the top wire-based intersection into a closed profile for cutting the top face coincident with the XY-plane.\n");
		return false;
	}
	topIntersectSqrWire = topIntersectSqrWireBuilder.Wire();
	TopoDS_Face topIntersectSqrFace1;
	BRepBuilderAPI_MakeFace topIntersectSqrFace1Builder(topIntersectSqrWire);
	if (!topIntersectSqrFace1Builder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not build the top wire-based intersection into a single face.\n");
		return false;
	}
	topIntersectSqrFace1 = topIntersectSqrFace1Builder.Face(); // Build a face from the closed wire and then extrude the face into a solid

	gp_Vec topCubeCutExtrudeVec(pyramExtrudeDir);
	topCubeCutExtrudeVec.Scale(2.0*TOL);
	BRepPrimAPI_MakePrism topCubeCutExtrudeBuilder(topIntersectSqrFace1, topCubeCutExtrudeVec);
	if (!topCubeCutExtrudeBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not build the top wire-based cube to be used for the intersection of the face coincident with the XY-plane.\n");
		return false;
	}
	TopoDS_Solid topCubeCutExtrudeShape = TopoDS::Solid(topCubeCutExtrudeBuilder.Shape());

	BRepBuilderAPI_MakeFace topOutsidePyramFaceBuilder2(xyPlane, topOutsideSqrWire); // Make the top face again, but don't shift it down by -TOL in the z-direction
	if (!topOutsidePyramFaceBuilder2.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not make top perimeter face #2 connecting to the truncated pyramid.\n");
		return false;
	}
	TopoDS_Face topOutsidePyramFace2 = topOutsidePyramFaceBuilder2.Face();

	TopoDS_Shape topPerimPyramShape;
	BRepAlgoAPI_Cut topPerimPyramShapeBuilder(topOutsidePyramFace2, topCubeCutExtrudeShape); // Use the solid cube to cut a hole into the top surface
	if (!topPerimPyramShapeBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not complete the intersection process with the top plane and the top edge of the pyramid.\n");
		return false;
	}
	topPerimPyramShape = topPerimPyramShapeBuilder.Shape();

	// Sew all faces together into one coherent shell object
	BRepBuilderAPI_Sewing sewBuilder;
	sewBuilder.SetTolerance(2.0*TOL);
	TopExp_Explorer explorer3;
	for (explorer3.Init(topPerimPyramShape, TopAbs_ShapeEnum::TopAbs_FACE); explorer3.More(); explorer3.Next())
	{
		sewBuilder.Add(TopoDS::Face(explorer3.Current()));
	}
	for (explorer2.Init(pyramDraftShell, TopAbs_ShapeEnum::TopAbs_FACE); explorer2.More(); explorer2.Next())
	{
		sewBuilder.Add(TopoDS::Face(explorer2.Current()));
	}
	for (explorer1.Init(botPyramFace, TopAbs_ShapeEnum::TopAbs_FACE); explorer1.More(); explorer1.Next())
	{
		sewBuilder.Add(TopoDS::Face(explorer1.Current()));
	}
	sewBuilder.Perform();
	TopoDS_Shape truncPyramidShape = sewBuilder.SewedShape();
	if (truncPyramidShape.ShapeType() != TopAbs_ShapeEnum::TopAbs_SHELL)
	{
		TopAbs_ShapeEnum  truncPyramidSewedShapeType = truncPyramidShape.ShapeType();
		logOut = logOut.append("\nERROR: Attempted to sew all faces together but result was not a shell.\n");
		return false;
	}
	TopoDS_Shell truncPyramidShell = TopoDS::Shell(truncPyramidShape);

	// Fillet all shared edges, so first explore and find all shared edges
	TopTools_IndexedMapOfShape edgeMap;
	TopExp::MapShapes(truncPyramidShell, TopAbs_ShapeEnum::TopAbs_EDGE, edgeMap);
	TColStd_Array1OfInteger faceCount(1, edgeMap.Extent());
	faceCount.Init(0);
	TopExp_Explorer explorerFace(truncPyramidShell, TopAbs_ShapeEnum::TopAbs_FACE);
	while (explorerFace.More())
	{
		TopExp_Explorer explorerEdge(TopoDS::Face(explorerFace.Current()), TopAbs_ShapeEnum::TopAbs_EDGE);
		while (explorerEdge.More())
		{
			faceCount(  edgeMap.FindIndex( TopoDS::Edge(explorerEdge.Current()) )  )++; // Increment face count by one for the current edge
			explorerEdge.Next();
		}
		explorerFace.Next();
	}

	BRepFilletAPI_MakeFillet trunPyramFilletBuilder(truncPyramidShell);
	Standard_Integer indxI;
	for (indxI = 1; indxI <= edgeMap.Extent(); indxI++)
	{
		if (faceCount(indxI) > 1) // A shared edge will have more than 1 face connected to it
		{
			trunPyramFilletBuilder.Add(filletRad, TopoDS::Edge(edgeMap(indxI)));
		}
	}
	trunPyramFilletBuilder.Build();
	if (!trunPyramFilletBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not fillet all shared edges.\n");
		return false;
	}
	TopoDS_Shape truncPyramidShapeFilleted = trunPyramFilletBuilder.Shape();

	// Build a shell from the compound to ensure the correct topology exists for toolpaths
	TopoDS_Shell truncPyramidShellFilleted;
	BRep_Builder TopoDsShellBuilder;
	TopoDsShellBuilder.MakeShell(truncPyramidShellFilleted);
	explorerFace.Init(truncPyramidShapeFilleted, TopAbs_ShapeEnum::TopAbs_FACE);
	while (explorerFace.More())
	{
		TopoDsShellBuilder.Add(truncPyramidShellFilleted, TopoDS::Face(explorerFace.Current()));
		explorerFace.Next();
	}

	TopoDS_Compound tempTopoDsCompound;
	BRep_Builder TopoDsCompoundBuilder;
	TopoDsCompoundBuilder.MakeCompound(tempTopoDsCompound);
	TopoDsCompoundBuilder.Add(tempTopoDsCompound, truncPyramidShellFilleted);

	myPyramidOut = tempTopoDsCompound;
	logOut = logOut.append("Success!\n");
	return true;
}

bool part::makeTrunCone(const Standard_Real &baseRad, const Standard_Real &wallAngle,
	const Standard_Real &depth, const Standard_Real &filletRad,
	const Standard_Real &TOL, TopoDS_Compound &myTrunConeOut, QString &logOut)
{
	Standard_Real wCone = abs(tan(wallAngle*PI / 180.0));
	if (wCone == 0.0)
	{
		logOut = logOut.append("\nERROR: Wall angle is 0.0 deg.\n");
		return false;
	}
	else if (wallAngle >= 90.0)
	{
		logOut = logOut.append("\nERROR: Wall angle is greater than or equal to 90.0 deg.\n");
		return false;
	}
	else if (baseRad == 0.0 || wallAngle == 0.0 || depth == 0.0 || filletRad == 0.0)
	{
		logOut = logOut.append("\nERROR: Cannot have zero-valued inputs.\n");
		return false;
	}

	wCone = depth / wCone;

	Standard_Real dFilletCalc = filletRad - filletRad*cos(wallAngle*PI / 180.0);
	if (dFilletCalc >= depth / 2.0)
	{
		logOut = logOut.append("\nERROR: Fillet radius is too large with respect to the depth of the part.\n");
		return false;
	}

	// 3D points used for the cross-section later
	gp_Pnt aPntOrigin(0.0, 0.0, 0.0);
	gp_Pnt aPnt1(0.0, 0.0, -depth);
	gp_Pnt aPnt2(baseRad - wCone, 0.0, -depth);
	gp_Pnt aPnt3(baseRad, 0.0, 0.0);
	gp_Pnt aPnt4(2.0 * baseRad, 0.0, 0.0);

	// 2D points for determining the fillets based on tangency constraints
	gp_Pnt2d aPnt2dOrigin(0.0, 0.0);
	gp_Pnt2d aPnt2d1(0.0, -depth);
	gp_Pnt2d aPnt2d2(baseRad - wCone, -depth);
	gp_Pnt2d aPnt2d3(baseRad, 0.0);
	gp_Pnt2d aPnt2d4(2.0*baseRad, 0.0);

	gp_Dir2d HorizDir2d((Standard_Real)1.0, (Standard_Real)0.0);  // Horizontal direction towards Positive X
	gp_Dir2d wallDir2d((Standard_Real)wCone, (Standard_Real)depth); // Direction parallel to the wall of the cone's cross-section, going positive X

	gp_Lin2d botLine2d(aPnt2d1, HorizDir2d); // Line definitions
	gp_Lin2d wallLine2d(aPnt2d2, wallDir2d);
	gp_Lin2d topLine2d(aPnt2d3, HorizDir2d);

	GccEnt_QualifiedLin botLine2dQualEnclosing(botLine2d, GccEnt_enclosed); // Bottom fillet-circle is on the left-side of these two lines
	GccEnt_QualifiedLin wallLine2dQualEnclosing(wallLine2d, GccEnt_enclosed);

	GccEnt_QualifiedLin wallLine2dQualOutside(wallLine2d, GccEnt_outside); // Top fillet-circle is on the right-side of these two lines
	GccEnt_QualifiedLin topLine2dQualOutside(topLine2d, GccEnt_outside);

	GccAna_Circ2d2TanRad botCircFilletSolver(botLine2dQualEnclosing, wallLine2dQualEnclosing, filletRad, TOL);
	if (!botCircFilletSolver.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not create a tangent fillet in the bottom corner.\n");
		return false;
	}

	GccAna_Circ2d2TanRad topCircFilletSolver(wallLine2dQualOutside, topLine2dQualOutside, filletRad, TOL);
	if (!topCircFilletSolver.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not create a tangent fillet in the top corner.\n");
		return false;
	}

	Standard_Real numSolBotCircFillet = botCircFilletSolver.NbSolutions();
	Standard_Real numSolTopCircFillet = topCircFilletSolver.NbSolutions();
	if ((numSolBotCircFillet > 1) || (numSolTopCircFillet > 1))
	{
		logOut = logOut.append("\nERROR: Multiple tangent curves found either the top or bottom corners of the cross-section profile.\n");
		return false;
	}

	gp_Circ2d topCirc2d = topCircFilletSolver.ThisSolution(1); // Have the circles, but need the tangent points
	gp_Circ2d botCirc2d = botCircFilletSolver.ThisSolution(1); // to make a 3-pt arc tangent to the lines
	Handle(Geom2d_Circle)  topCirc2dGeomRef = new Geom2d_Circle(topCirc2d);
	Handle(Geom2d_Circle)  botCirc2dGeomRef = new Geom2d_Circle(botCirc2d);

	Standard_Real parSolTemp;
	Standard_Real parArgTemp;
	gp_Pnt2d botLeftFilletPt2D;
	gp_Pnt2d botRightFilletPt2D;
	gp_Pnt2d topLeftFilletPt2D;
	gp_Pnt2d topRightFilletPt2D;

	topCircFilletSolver.Tangency1(1, parSolTemp, parArgTemp, topLeftFilletPt2D);
	topCircFilletSolver.Tangency2(1, parSolTemp, parArgTemp, topRightFilletPt2D);
	botCircFilletSolver.Tangency1(1, parSolTemp, parArgTemp, botLeftFilletPt2D);
	botCircFilletSolver.Tangency2(1, parSolTemp, parArgTemp, botRightFilletPt2D);

	// Now to actually make the 3D cross-section
	gp_Dir negYDir(0.0, -1.0, 0.0);
	gp_Dir posXDir(1.0, 0.0, 0.0);
	gp_Ax3 crossSectPlaneAx3(aPntOrigin, negYDir, posXDir);
	gp_Pln crossSectPlane(crossSectPlaneAx3);

	Handle(Geom_Curve) topCircCurve3dRef = GeomAPI::To3d(topCirc2dGeomRef, crossSectPlane); // Use API to convert 2D circles into 3D circles
	Handle(Geom_Curve) botCircCurve3dRef = GeomAPI::To3d(botCirc2dGeomRef, crossSectPlane);
	Handle(Geom_Circle) topCirc3dRef;
	Handle(Geom_Circle) botCirc3dRef;

	if (topCircCurve3dRef->DynamicType() == STANDARD_TYPE(Geom_Circle))
		topCirc3dRef = Handle(Geom_Circle)::DownCast(topCircCurve3dRef);
	else
	{
		logOut = logOut.append("\nERROR: Could not downcast a general curve into a circle object for the top fillet.\n");
		return false;
	}

	if (botCircCurve3dRef->DynamicType() == STANDARD_TYPE(Geom_Circle))
		botCirc3dRef = Handle(Geom_Circle)::DownCast(botCircCurve3dRef);
	else
	{
		logOut = logOut.append("\nERROR: Could not downcast a general curve into a circle object for the bottom fillet.\n");
		return false;
	}

	gp_Circ topCirc3d = topCirc3dRef->Circ();
	gp_Circ botCirc3d = botCirc3dRef->Circ();

	gp_Pnt botLeftFilletPt(botLeftFilletPt2D.X(), 0.0, botLeftFilletPt2D.Y());
	gp_Pnt botRightFilletPt(botRightFilletPt2D.X(), 0.0, botRightFilletPt2D.Y());
	gp_Pnt topLeftFilletPt(topLeftFilletPt2D.X(), 0.0, topLeftFilletPt2D.Y());
	gp_Pnt topRightFilletPt(topRightFilletPt2D.X(), 0.0, topRightFilletPt2D.Y());

	if (botLeftFilletPt.X() <= TOL)
	{
		logOut = logOut.append("\nERROR: Depth is too deep and causes a self-intersecting surface. Please either increase the wall angle, increase part diameter, or decrease part depth.\n");
		return false;
	}

	//Handle(Geom_TrimmedCurve) botHorizTrimCurve = GC_MakeSegment(aPnt1, botLeftFilletPt);
	//Handle(Geom_TrimmedCurve) botFilletTrimCurve = GC_MakeArcOfCircle(botCirc3d, botLeftFilletPt, botRightFilletPt, true);
	//Handle(Geom_TrimmedCurve) wallTrimCurve = GC_MakeSegment(botRightFilletPt, topLeftFilletPt);
	//Handle(Geom_TrimmedCurve) topFilletTrimCurve = GC_MakeArcOfCircle(topCirc3d, topRightFilletPt, topLeftFilletPt, true);
	//Handle(Geom_TrimmedCurve) topHorizTrimCurve = GC_MakeSegment(topRightFilletPt, aPnt4);

	Handle(Geom_TrimmedCurve) botHorizTrimCurve = GC_MakeSegment(aPnt1, aPnt2);
	Handle(Geom_TrimmedCurve) wallTrimCurve = GC_MakeSegment(aPnt2, aPnt3);
	Handle(Geom_TrimmedCurve) topHorizTrimCurve = GC_MakeSegment(aPnt3, aPnt4);

	//gp_Ax1 axisOfRev(aPntOrigin, gp_Dir(0.0, 0.0, 1.0));
	//Geom_SurfaceOfRevolution botHorizRevSurf(botHorizTrimCurve, axisOfRev);
	//TopoDS_Face aFace1 = BRepPrimAPI_MakeRevolution(botHorizTrimCurve);

	TopoDS_Edge aEdge1 = BRepBuilderAPI_MakeEdge(botHorizTrimCurve);
	//TopoDS_Edge aEdge2 = BRepBuilderAPI_MakeEdge(botFilletTrimCurve);
	TopoDS_Edge aEdge3 = BRepBuilderAPI_MakeEdge(wallTrimCurve);
	//TopoDS_Edge aEdge4 = BRepBuilderAPI_MakeEdge(topFilletTrimCurve);
	TopoDS_Edge aEdge5 = BRepBuilderAPI_MakeEdge(topHorizTrimCurve);

	TopoDS_Wire coneSectionWire;
	BRepBuilderAPI_MakeWire wireBuilder = BRepBuilderAPI_MakeWire(aEdge1, aEdge3, aEdge5);
	//wireBuilder.Add(aEdge5);
	wireBuilder.Build();
	if (!wireBuilder.IsDone())
	{
		BRepBuilderAPI_WireError myWireError = wireBuilder.Error();
		logOut = logOut.append("\nERROR: Edges could not be combined to define the cross-section's profile.\n");
		return false;
	}

	coneSectionWire = wireBuilder.Wire();
	gp_Ax1 axisOfRev(aPntOrigin, gp_Dir(0.0, 0.0, 1.0));

	BRepPrimAPI_MakeRevol revBuilder = BRepPrimAPI_MakeRevol(coneSectionWire, axisOfRev, false);
	if (!revBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not revolve cross-section profile.\n");
		return false;
	}

	TopoDS_Shape coneTopoShape = revBuilder.Shape();

	TopTools_IndexedMapOfShape edgeMap;
	TopExp::MapShapes(coneTopoShape, TopAbs_ShapeEnum::TopAbs_EDGE, edgeMap);
	TColStd_Array1OfInteger faceCount(1, edgeMap.Extent());
	faceCount.Init(0);
	TopExp_Explorer explorerFace(coneTopoShape, TopAbs_ShapeEnum::TopAbs_FACE);
	while (explorerFace.More())
	{
		TopExp_Explorer explorerEdge(TopoDS::Face(explorerFace.Current()), TopAbs_ShapeEnum::TopAbs_EDGE);
		while (explorerEdge.More())
		{
			faceCount(edgeMap.FindIndex(TopoDS::Edge(explorerEdge.Current())))++; // Increment face count by one for the current edge
			explorerEdge.Next();
		}
		explorerFace.Next();
	}

	BRepFilletAPI_MakeFillet coneFilletBuilder(coneTopoShape);
	Standard_Integer indxI;
	TColStd_Array1OfInteger indexOfFilletEdges(1, edgeMap.Extent());

	for (indxI = 1; indxI <= edgeMap.Extent(); indxI++)
	{
		if (faceCount(indxI) > 1) // A shared edge will have more than 1 face connected to it
		{
			coneFilletBuilder.Add(filletRad, TopoDS::Edge(edgeMap(indxI)));
		}
	}
	coneFilletBuilder.Build();

	if (!coneFilletBuilder.IsDone())
	{
		logOut = logOut.append("\nERROR: Could not fillet all shared edges. Try decreasing the part depth, decreasing the fillet radius, or increasing the opening diameter.\n");
		return false;
	}
	TopoDS_Shape coneShapeFilleted;
	coneShapeFilleted = coneFilletBuilder.Shape();

	TopoDS_Shell coneShellFilleted;
	BRep_Builder TopoDsShellBuilder;
	TopoDsShellBuilder.MakeShell(coneShellFilleted);
	explorerFace.Init(coneShapeFilleted, TopAbs_ShapeEnum::TopAbs_FACE);
	while (explorerFace.More())
	{
		TopoDsShellBuilder.Add(coneShellFilleted, TopoDS::Face(explorerFace.Current()));
		explorerFace.Next();
	}

	TopAbs_ShapeEnum coneShapeType = coneShellFilleted.ShapeType();
	if (coneShapeType != TopAbs_ShapeEnum::TopAbs_SHELL)
	{
		logOut = logOut.append("\nERROR: Final revolved part was not found to be a shell surface.\n");
		return false;
	}

	TopoDS_Compound tempTopoDsCompound;
	BRep_Builder aBuilder;
	aBuilder.MakeCompound(tempTopoDsCompound);
	aBuilder.Add(tempTopoDsCompound, coneShellFilleted);

	//QTextStream logTextStream(&logOut);
	//logTextStream << "Success! Created a truncated cone." << endl;
	myTrunConeOut = tempTopoDsCompound;
	logOut = logOut.append("Success!\n");
	return true;
}