#include "stdafx.h"

#include "QtOcct.h"

void QtOcct::showExtractCrossSectionToolDialogSlot(void)
{
	exportCrossSectionDialog myCrossSectionDialog(this);

	if (!partIsActive)
	{
		textEdit->insertPlainText("ERROR: No active part is present to calculate cross-section information.\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	textEdit->insertPlainText("WARNING: Any active toolpath points will be DESTROYED upon running this tool. Save your toolpath beforehand.\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	textEdit->repaint();

	if (myCrossSectionDialog.exec())
	{
		setToolpathVisibilitySlot(true);
		myCurrentToolpath.reset();

		QString currentDirectory = myCrossSectionDialog.getDirectory();
		QString currentFileName = myCrossSectionDialog.getFileName();
		QString fullFilePath = currentDirectory + QString("/") + currentFileName;

		gp_Pnt basePnt, startingPnt;
		gp_Dir planeNormalDir;
		bool basePntSuccess = myCrossSectionDialog.getBasePntOfPlane(basePnt);
		bool startingPntSuccess = myCrossSectionDialog.getStartingPnt(startingPnt);
		bool planeNormalDirSuccess = myCrossSectionDialog.getNormalDirOfPlane(planeNormalDir);
		float maxPnt2PntDist = myCrossSectionDialog.getMaxDistBetweenPnts();

		if (!basePntSuccess || !startingPntSuccess || !planeNormalDirSuccess)
		{
			textEdit->insertPlainText("ERROR: Could not parse user input. Please double-check that only numbers were entered.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		gp_Pln intersectPln(basePnt, planeNormalDir);
		ampl::planeIntersecter contourObj(myCurrentPart, intersectPln);
		if (!contourObj.performIntersect())
		{
			textEdit->insertPlainText(QString("ERROR: Failed to perform intersection. Double-check that the part does not contain self-intersecting geometry and that the plane actually intersects the part.\n"));
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		bool edgeToEdgeTolSuccess = false;
		Standard_Real edgeToEdgeTol = 0.005;
		std::vector<double> edgeToEdgeTolArr = { 0.01, 0.02, 0.035, 0.05, 0.075, 0.1 };
		contourObj.setEdgeToEdgeTol(0.005);
		contourObj.sortIntersection();

		Standard_Integer numClosedWires = 0;
		Standard_Integer numWires;
		std::vector<int> closedWireIndices;
		contourObj.getNumClosedWires(numClosedWires, closedWireIndices);
		contourObj.getNumWires(numWires);

		if (numWires > 1)
		{
			int edgeToEdgeCount = 1;
			for (double tol : edgeToEdgeTolArr) // Try sorting the edges with a larger tolerance
			{
				contourObj.resetWireArray();
				contourObj.setEdgeToEdgeTol(tol);
				contourObj.sortIntersection();
				contourObj.getNumClosedWires(numClosedWires, closedWireIndices);

				if (numWires > 1)
				{
					edgeToEdgeTolSuccess = true;
					edgeToEdgeTol = tol;
					break;
				}
				edgeToEdgeCount++;
			}
		}
		else
			edgeToEdgeTolSuccess = true;

		contourObj.getNumWires(numWires);
		contourObj.getNumClosedWires(numClosedWires, closedWireIndices);

		if (numWires > 1)
		{
			textEdit->insertPlainText("WARNING: Multiple wires were found upon intersecting the part with the user's plane. Generating intersect points for all wires...\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();
		}
		else if (numWires == 0)
		{
			textEdit->insertPlainText("ERROR: No wires were found after intersecting the part with the user's plane.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		std::vector<gp_Pnt> allPnts;
		float intersectLen = 0;
		std::vector<gp_Pnt> comArr;
		std::vector<float> wireLengthArr;
		for (int wireIndex = 0; wireIndex < numWires; wireIndex++) // Discretize all wires
		{
			std::vector<gp_Pnt> localIntersectPnts;
			Standard_Real maxDistFromFirstCoM, wireDistLocal;
			gp_Pnt localCOMPnt;
			contourObj.getCenterOfMass(wireIndex, localCOMPnt);
			contourObj.getWireLength(wireIndex, wireDistLocal);
			comArr.push_back(localCOMPnt);
			wireLengthArr.push_back(wireDistLocal);
			intersectLen = intersectLen + wireDistLocal;

			contourObj.discretizeIntersection(wireIndex, maxPnt2PntDist, localIntersectPnts);

			for (gp_Pnt &tempPnt : localIntersectPnts)
			{
				(allPnts).push_back(tempPnt);
			}
			localIntersectPnts.clear();
		}
		int numIntersectPnts = allPnts.size();

		float tempSumX = 0, tempSumY = 0, tempSumZ = 0; // Find the average center of gravity (weighted based on edge length) of the intersection
		for (int wireIndex = 0; wireIndex < numWires; wireIndex++)
		{
			gp_Pnt curComPnt = comArr.at(wireIndex);
			Standard_Real curEdgeLength = wireLengthArr.at(wireIndex);

			tempSumX = tempSumX + (curEdgeLength / intersectLen)*curComPnt.X();
			tempSumY = tempSumY + (curEdgeLength / intersectLen)*curComPnt.Y();
			tempSumZ = tempSumZ + (curEdgeLength / intersectLen)*curComPnt.Z();
		}
		gp_Pnt avgCOM(tempSumX / numWires, tempSumY / numWires, tempSumZ / numWires);

		ampl::amplWireIntersection::sequentialSortDiscretizedPnts(startingPnt, allPnts);
		if (allPnts.front().IsEqual(allPnts.back(), 0.002))
		{
			allPnts.erase(allPnts.end() - 1);
			//numIntersectPnts = numIntersectPnts - 1;
		}

		QString numIntersectPntsMsg = QString("Intersection has been SUCCESSFULLY discretized into ") + QString::number(numIntersectPnts) + QString(" points. Use the 'Top Contact Points' visualization setting to change line type.\n");
		textEdit->insertPlainText(numIntersectPntsMsg);
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		ofstream myfile;
		myfile.open(fullFilePath.toStdString(), std::ios::out | std::ios::trunc);

		toolpathZHeightProps tempHeightPropsSaved;
		//amplToolpath tempToolpathObj;
		tempHeightPropsSaved.allTopContactPnts = allPnts;
		tempHeightPropsSaved.zDepthAvgCoM = avgCOM;
		tempHeightPropsSaved.copyAllContactPntsToLocalAmpl();
		tempHeightPropsSaved.copyAmplContactPntsToOther(myCurrentToolpath);

		contourObj.getAllSurfProps(allPnts, avgCOM, true, tempHeightPropsSaved.allNormals, tempHeightPropsSaved.allKappaMax, tempHeightPropsSaved.allKappaMaxDirections,
			tempHeightPropsSaved.allKappaMin, tempHeightPropsSaved.allKappaMinDirections, tempHeightPropsSaved.allKappaMean, tempHeightPropsSaved.allKappaGaussian);

		tempHeightPropsSaved.copyAllSurfPropsToLocalAmpl();
		tempHeightPropsSaved.copyAmplSurfPropsToOther(myCurrentToolpath);

		if (myfile.is_open())
		{
			if (myCurrentToolpath.topContactPnts.size() == myCurrentToolpath.topContactPntsSurfProps.size())
			{
				textEdit->insertPlainText("Writing Intersect Points with Surface Properties to: " + fullFilePath + "\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

				myfile << "pntX,pntY,pntZ,normalX,normalY,normalZ,maxCurvature,maxCurvDirectionX,maxCurvDirectionY,maxCurvDirectionZ,minCurvature,minCurvDirectionX,minCurvDirectionY,minCurvDirectionZ,meanCurvature,GaussianCurvature" << std::endl;
				myfile << std::fixed << std::setprecision(4);

				int iCount = 0;
				for (const std::vector<float> &i : myCurrentToolpath.topContactPnts)
				{
					int kCount = 0;
					for (const float &j : i)
					{
						myfile << j << ",";
					}
					for (const float &k : myCurrentToolpath.topContactPntsSurfProps.at(iCount))
					{
						if (kCount < 12)
						{
							myfile << k << ",";
						}
						else
						{
							myfile << k << std::endl;
						}

						kCount = kCount + 1;
					}

					iCount = iCount + 1;
				}
				myfile.close();
			}
			else
			{
				textEdit->insertPlainText("ERROR: Could not write intersect points with surface properties due to differently sized arrays.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			}
		}

		setToolpathVisibilitySlot(false);
	}
}

void QtOcct::showCalcTwoSurfDeviationDialogSlot(void)
{
	textEdit->insertPlainText("WARNING: Any active part or toolpath points will be DESTROYED upon running this tool. Save your part and toolpath beforehand.\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	textEdit->repaint();

	calc2SurfDeviationErrorDialog mySurfDevErrorDialog(this);

	if (mySurfDevErrorDialog.exec())
	{
		calc2SurfDeviationErrorDialog::regionType myRegionType = mySurfDevErrorDialog.getRegionType();
		QString directoryPath = mySurfDevErrorDialog.getDirectory();
		QString prefixName = mySurfDevErrorDialog.getPrefixName();

		TopoDS_Compound surf1;
		TopoDS_Compound surf2;
		amplLineRegion lineReg;
		amplRectRegion rectReg;

		bool surf1Success, surf2Success, regionDefinitionSuccess;
		surf1Success = mySurfDevErrorDialog.getSurf1(surf1);
		surf2Success = mySurfDevErrorDialog.getSurf2(surf2);

		if (myRegionType == calc2SurfDeviationErrorDialog::regionType::RECT)
			regionDefinitionSuccess = mySurfDevErrorDialog.getRectRegion(rectReg);
		else if (myRegionType == calc2SurfDeviationErrorDialog::regionType::LINE)
			regionDefinitionSuccess = mySurfDevErrorDialog.getLineRegion(lineReg);

		if (!surf1Success)
		{
			textEdit->insertPlainText("ERROR: Failed to import Surface 1.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
		if (!surf2Success)
		{
			textEdit->insertPlainText("ERROR: Failed to import Surface 2.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
		if (!regionDefinitionSuccess)
		{
			textEdit->insertPlainText("ERROR: Failed to define Region of Interest.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		QEventLoop myEventLoop(this);
		setToolpathVisibilitySlot(true);
		myCurrentToolpath.reset();

		if (partIsActive)
		{
			myContext->Remove(myAisShape);
			myAisShape.Nullify();
			myCurrentPart.Nullify();
			partIsActive = false;
		}

		TopoDS_Compound localPartTopoDsCompound;
		BRep_Builder localTopoDsCompoundBuilder;
		localTopoDsCompoundBuilder.MakeCompound(localPartTopoDsCompound);
		localTopoDsCompoundBuilder.Add(localPartTopoDsCompound, surf1);
		localTopoDsCompoundBuilder.Add(localPartTopoDsCompound, surf2);
		myCurrentPart = localPartTopoDsCompound;
		partIsActive = true;

		if (myAisShape.IsNull())
			myAisShape = new AIS_Shape(myCurrentPart);
		else
		{
			myAisShape.Nullify();
			myAisShape = new AIS_Shape(myCurrentPart);
		}
		myContext->Display(myAisShape);

		toolpathZHeightProps tempHeightPropsSaved;
		gp_Pnt avgCoM;
		std::vector<gp_Pnt> allGridPntsFlat;
		std::vector< std::vector<gp_Pnt> > allGridPnts2D;
		int numXPnts, numYPnts, numPnts;

		if (myRegionType == calc2SurfDeviationErrorDialog::regionType::RECT)
		{
			rectReg.getDiscretizedRect(allGridPnts2D);
			numXPnts = allGridPnts2D.size();
			numYPnts = (allGridPnts2D.front()).size();
			numPnts = numXPnts*numYPnts;
			for (int m = 0; m < numXPnts; m++)
			{
				for (int n = 0; n < numYPnts; n++)
				{
					gp_Pnt curPnt = (allGridPnts2D.at(m)).at(n);
					allGridPntsFlat.push_back(curPnt);
				}
			}
			rectReg.getCenterPoint(avgCoM);
		}
		else if (myRegionType = calc2SurfDeviationErrorDialog::regionType::LINE)
		{
			lineReg.getDiscretizedLine(allGridPntsFlat);
			numPnts = allGridPntsFlat.size();
			numXPnts = numPnts;
			numYPnts = 0;

			gp_Pnt startPnt, endPnt;
			lineReg.getStartPoint(startPnt);
			lineReg.getEndPoint(endPnt);
			avgCoM = gp_Pnt((startPnt.X() + endPnt.X())/2.0, (startPnt.Y() + endPnt.Y()) / 2.0, (startPnt.Z() + endPnt.Z()) / 2.0);
		}
		tempHeightPropsSaved.zDepthAvgCoM = avgCoM;

		std::vector<gp_Vec> zAxisVecs;
		for (int m = 0; m < numPnts; m++)
		{
			gp_Dir zAxisDirLocal(0.0, 0.0, 1.0);
			gp_Vec zAxisVecLocal(zAxisDirLocal);
			zAxisVecs.push_back(zAxisVecLocal);
		}

		textEdit->insertPlainText("Calculating query points on Surface 1. This may take a while...\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();
		std::vector<gp_Pnt> allSurf1Pnts;
		std::vector<int> skipIndices, keptIndices;
		int surf1LoopCount = 0;
		int surf1LoopCountTemp = 0;
		for (int pntIndex = 0; pntIndex < allGridPntsFlat.size(); pntIndex++)
		{
			gp_Pnt currentPnt = allGridPntsFlat.at(pntIndex);
			gp_Pnt closestProjPnt;
			gp_Vec currentVec = zAxisVecs.at(pntIndex);
			Handle(Geom_Line) currentLine = GC_MakeLine(currentPnt, gp_Dir(currentVec));
			TopoDS_Edge currentIntersectEdge = BRepBuilderAPI_MakeEdge(currentLine, -10000, 10000);

			//BRepAlgoAPI_Section sectionBuilder(shellPartIn, currentIntersectEdge);
			BRepAlgoAPI_Section sectionBuilder;
			sectionBuilder.Init1(surf1);
			sectionBuilder.Init2(currentIntersectEdge);
			sectionBuilder.SetRunParallel(true);
			sectionBuilder.SetFuzzyValue(0.005);
			sectionBuilder.Approximation(true);
			sectionBuilder.SetOperation(BOPAlgo_Operation::BOPAlgo_SECTION);
			sectionBuilder.Build();

			if (!sectionBuilder.IsDone())
			{
				surf1LoopCountTemp++;
				allSurf1Pnts.push_back(currentPnt);
				skipIndices.push_back(pntIndex);
				continue;
			}

			TopoDS_Shape intersectShape = sectionBuilder.Shape();
			TopExp_Explorer explorer1Vertex(intersectShape, TopAbs_ShapeEnum::TopAbs_VERTEX);
			if (!explorer1Vertex.More())
			{
				surf1LoopCountTemp++;
				allSurf1Pnts.push_back(currentPnt);
				skipIndices.push_back(pntIndex);
				continue;
			}
			
			float minIntersectPntDist = 1000000;
			for (; explorer1Vertex.More(); explorer1Vertex.Next())
			{
				TopoDS_Vertex currentIntersectVertex = TopoDS::Vertex(explorer1Vertex.Current());
				gp_Pnt currentIntersectPnt = BRep_Tool::Pnt(currentIntersectVertex);
				float currentIntersectDist = currentIntersectPnt.Distance(currentPnt);

				if (currentIntersectDist < minIntersectPntDist)
				{
					minIntersectPntDist = currentIntersectDist;
					closestProjPnt = currentIntersectPnt;
				}
			}

			allSurf1Pnts.push_back(closestProjPnt);
			keptIndices.push_back(pntIndex);
			surf1LoopCountTemp++;

			if (surf1LoopCountTemp >= 2000)
			{
				surf1LoopCount = surf1LoopCount + surf1LoopCountTemp;
				surf1LoopCountTemp = 0;
				
				QString updateMsg = QString("Currently found ") + QString::number(surf1LoopCount) + QString(" points on Surface 1\n");
				textEdit->insertPlainText(updateMsg);
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();
				myEventLoop.processEvents();
			}
			else if (pntIndex == allGridPntsFlat.size() - 1)
			{
				surf1LoopCount = surf1LoopCount + surf1LoopCountTemp;
				surf1LoopCountTemp = 0;

				QString updateMsg = QString("Currently found ") + QString::number(surf1LoopCount) + QString(" points on Surface 1\n");
				textEdit->insertPlainText(updateMsg);
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();
				myEventLoop.processEvents();
			}
		}
		tempHeightPropsSaved.allTopContactPnts = allSurf1Pnts;
		tempHeightPropsSaved.copyAllContactPntsToLocalAmpl();
		tempHeightPropsSaved.copyAmplContactPntsToOther(myCurrentToolpath);
		setToolpathVisibilitySlot(false);

		std::vector<gp_Pnt> surf1PntsForProps;
		for (int m = 0; m < allSurf1Pnts.size(); m++)
		{
			bool skipCurIndex = false;
			for (int n = 0; n < skipIndices.size(); n++)
			{
				if (m == skipIndices.at(n))
				{
					skipCurIndex = true;
					break;
				}
			}
			if (skipCurIndex)
				continue;

			gp_Pnt curPntLocal = allSurf1Pnts.at(m);
			surf1PntsForProps.push_back(curPntLocal);
		}

		textEdit->insertPlainText("Calculating local geometric properties at each query point...\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		std::vector<gp_Vec> normalsSurf1;
		std::vector<float> kappaMaxSurf1;
		std::vector<gp_Vec> kappaMaxDirectionSurf1;
		std::vector<float> kappaMinSurf1;
		std::vector<gp_Vec> kappaMinDirectionSurf1;
		std::vector<float> kappaMeanSurf1;
		std::vector<float> kappaGaussianSurf1;

		ampl::planeIntersecter::getAllSurfProps(surf1, surf1PntsForProps, avgCoM, true, normalsSurf1, kappaMaxSurf1, kappaMaxDirectionSurf1, kappaMinSurf1, 
			kappaMinDirectionSurf1, kappaMeanSurf1, kappaGaussianSurf1);

		std::vector<gp_Vec> allNormals(numPnts, gp_Vec(0.0, 0.0, 0.0));
		std::vector<float> allKappaMax(numPnts, 0.0);
		std::vector<gp_Vec> allKappaMaxDirection(numPnts, gp_Vec(0.0, 0.0, 0.0));
		std::vector<float> allKappaMin(numPnts, 0.0);
		std::vector<gp_Vec> allKappaMinDirection(numPnts, gp_Vec(0.0, 0.0, 0.0));
		std::vector<float> allKappaMean(numPnts, 0.0);
		std::vector<float> allKappaGaussian(numPnts, 0.0);

		for (int m = 0; m < keptIndices.size(); m++)
		{
			int curIndex = keptIndices.at(m);
			allNormals.at(curIndex) = normalsSurf1.at(m);
			allKappaMax.at(curIndex) = kappaMaxSurf1.at(m);
			allKappaMaxDirection.at(curIndex) = kappaMaxDirectionSurf1.at(m);
			allKappaMin.at(curIndex) = kappaMinSurf1.at(m);
			allKappaMinDirection.at(curIndex) = kappaMinDirectionSurf1.at(m);
			allKappaMean.at(curIndex) = kappaMeanSurf1.at(m);
			allKappaGaussian.at(curIndex) = kappaGaussianSurf1.at(m);
		}
		tempHeightPropsSaved.allNormals = allNormals;
		tempHeightPropsSaved.allKappaMax = allKappaMax;
		tempHeightPropsSaved.allKappaMaxDirections = allKappaMaxDirection;
		tempHeightPropsSaved.allKappaMin = allKappaMin;
		tempHeightPropsSaved.allKappaMinDirections = allKappaMinDirection;
		tempHeightPropsSaved.allKappaMean = allKappaMean;
		tempHeightPropsSaved.allKappaGaussian = allKappaGaussian;
		tempHeightPropsSaved.copyAllSurfPropsToLocalAmpl();
		tempHeightPropsSaved.copyAmplSurfPropsToOther(myCurrentToolpath);

		textEdit->insertPlainText("Calculating deviation query points on Surface 2. This may take a while...\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();
		std::vector<gp_Pnt> allSurf2Pnts;
		int surf2LoopCount = 0;
		int surf2LoopCountTemp = 0;
		for (int pntIndex = 0; pntIndex < allSurf1Pnts.size(); pntIndex++)
		{
			gp_Pnt currentPnt = allSurf1Pnts.at(pntIndex);

			bool skipCurIndex = false;
			for (int n = 0; n < skipIndices.size(); n++)
			{
				if (pntIndex == skipIndices.at(n))
				{
					skipCurIndex = true;
					break;
				}
			}
			if (skipCurIndex)
			{
				allSurf2Pnts.push_back(currentPnt);
				surf2LoopCountTemp++;
				continue;
			}
			
			gp_Pnt closestProjPnt;
			gp_Vec currentVec = allNormals.at(pntIndex);
			Handle(Geom_Line) currentLine = GC_MakeLine(currentPnt, gp_Dir(currentVec));
			TopoDS_Edge currentIntersectEdge = BRepBuilderAPI_MakeEdge(currentLine, -10000, 10000);

			//BRepAlgoAPI_Section sectionBuilder(shellPartIn, currentIntersectEdge);
			BRepAlgoAPI_Section sectionBuilder;
			sectionBuilder.Init1(surf2);
			sectionBuilder.Init2(currentIntersectEdge);
			sectionBuilder.SetRunParallel(true);
			sectionBuilder.SetFuzzyValue(0.005);
			sectionBuilder.Approximation(true);
			sectionBuilder.SetOperation(BOPAlgo_Operation::BOPAlgo_SECTION);
			sectionBuilder.Build();

			if (!sectionBuilder.IsDone())
			{
				allSurf2Pnts.push_back(currentPnt);
				surf2LoopCountTemp++;
				continue;
			}

			TopoDS_Shape intersectShape = sectionBuilder.Shape();
			TopExp_Explorer explorer1Vertex(intersectShape, TopAbs_ShapeEnum::TopAbs_VERTEX);
			if (!explorer1Vertex.More())
			{
				allSurf2Pnts.push_back(currentPnt);
				surf2LoopCountTemp++;
				continue;
			}
			
			float minIntersectPntDist = 1000000;
			for (; explorer1Vertex.More(); explorer1Vertex.Next())
			{
				TopoDS_Vertex currentIntersectVertex = TopoDS::Vertex(explorer1Vertex.Current());
				gp_Pnt currentIntersectPnt = BRep_Tool::Pnt(currentIntersectVertex);
				float currentIntersectDist = currentIntersectPnt.Distance(currentPnt);

				if (currentIntersectDist < minIntersectPntDist)
				{
					minIntersectPntDist = currentIntersectDist;
					closestProjPnt = currentIntersectPnt;
				}
			}

			allSurf2Pnts.push_back(closestProjPnt);
			surf2LoopCountTemp++;

			if (surf2LoopCountTemp >= 2000)
			{
				surf2LoopCount = surf2LoopCount + surf2LoopCountTemp;
				surf2LoopCountTemp = 0;

				QString updateMsg = QString("Currently found ") + QString::number(surf2LoopCount) + QString(" points on Surface 2\n");
				textEdit->insertPlainText(updateMsg);
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();
				myEventLoop.processEvents();
			}
			else if (pntIndex == allGridPntsFlat.size() - 1)
			{
				surf2LoopCount = surf2LoopCount + surf2LoopCountTemp;
				surf2LoopCountTemp = 0;

				QString updateMsg = QString("Currently found ") + QString::number(surf2LoopCount) + QString(" points on Surface 2\n");
				textEdit->insertPlainText(updateMsg);
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();
				myEventLoop.processEvents();
			}
		}
		tempHeightPropsSaved.allBotContactPnts = allSurf2Pnts;
		tempHeightPropsSaved.copyAllContactPntsToLocalAmpl();
		tempHeightPropsSaved.copyAmplContactPntsToOther(myCurrentToolpath);
		setToolpathVisibilitySlot(false);

		std::vector<float> devDistArr;
		for (int m = 0; m < numPnts; m++)
		{
			gp_Pnt surf1PntLocal = allSurf1Pnts.at(m);
			gp_Pnt surf2PntLocal = allSurf2Pnts.at(m);
			float localDist = surf1PntLocal.Distance(surf2PntLocal);
			devDistArr.push_back(localDist);
		}

		QString fullFilePath1 = directoryPath + QString("/") + prefixName + QString("_Surf1.csv");
		ofstream myfile1;
		myfile1.open(fullFilePath1.toStdString(), std::ios::out | std::ios::trunc);
		if (myfile1.is_open())
		{
			if (myCurrentToolpath.topContactPnts.size() == myCurrentToolpath.topContactPntsSurfProps.size())
			{
				textEdit->insertPlainText("Writing Surface 1 points with Surface Properties to: " + fullFilePath1 + "\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

				myfile1 << "pntX,pntY,pntZ,normalX,normalY,normalZ,maxCurvature,maxCurvDirectionX,maxCurvDirectionY,maxCurvDirectionZ,minCurvature,minCurvDirectionX,minCurvDirectionY,minCurvDirectionZ,meanCurvature,GaussianCurvature" << std::endl;
				myfile1 << std::fixed << std::setprecision(4);

				int iCount = 0;
				for (const std::vector<float> &i : myCurrentToolpath.topContactPnts)
				{
					int kCount = 0;
					for (const float &j : i)
					{
						myfile1 << j << ",";
					}
					for (const float &k : myCurrentToolpath.topContactPntsSurfProps.at(iCount))
					{
						if (kCount < 12)
						{
							myfile1 << k << ",";
						}
						else
						{
							myfile1 << k << std::endl;
						}

						kCount = kCount + 1;
					}

					iCount = iCount + 1;
				}
				myfile1.close();
			}
			else
			{
				textEdit->insertPlainText("ERROR: Could not write intersect points with surface properties due to differently sized arrays.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			}
		}

		QString fullFilePath2 = directoryPath + QString("/") + prefixName + QString("_Surf2.csv");
		ofstream myfile2;
		myfile2.open(fullFilePath2.toStdString(), std::ios::out | std::ios::trunc);
		if (myfile2.is_open())
		{
				textEdit->insertPlainText("Writing Surface 2 points with Deviation Distances to: " + fullFilePath2 + "\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

			myfile2 << "pntX,pntY,pntZ,Deviation Distance" << std::endl;
			myfile2 << std::fixed << std::setprecision(4);

			int iCount = 0;
			for (const std::vector<float> &i : myCurrentToolpath.botContactPnts)
			{
				for (const float &j : i)
				{
					myfile2 << j << ",";
				}
				myfile2 << devDistArr.at(iCount) << std::endl;

				iCount = iCount + 1;
			}
			myfile2.close();
		}
	}
}