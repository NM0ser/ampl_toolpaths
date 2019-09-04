#include "stdafx.h"

#include "SPIF.h"
#include "amplToolpath.h"
#include "amplWireIntersection.h"
#include "planeIntersecter.h"

SPIF::SPIF()
{
	myCurrentToolpath = nullptr;
	myViewer = NULL;
	myView = NULL;
	myContext = NULL;
	myAisShape = NULL;
	myAisTopContactPnts = NULL;
	myAisBotContactPnts = NULL;
	myCurrentPart = nullptr;
	myCurrentTopContactPnts = nullptr;
	myCurrentBotContactPnts = nullptr;
	myCurrentTopToolTips = nullptr;
	myCurrentBotToolTips = nullptr;
	myAisTopToolTips = NULL;
	myAisBotToolTips = NULL;
	textEdit = nullptr;
}

bool SPIF::initContactPnts(amplToolpath &myCurrentToolpathIn, TopoDS_Compound &myCurrentTopContactPntsIn, TopoDS_Compound &myCurrentBotContactPntsIn,
	Handle(AIS_Shape) &myAisTopContactPntsIn, Handle(AIS_Shape) &myAisBotContactPntsIn, TopoDS_Compound &myCurrentPartIn, Handle(V3d_Viewer) &myViewerIn, 
	Handle(V3d_View) &myViewIn, Handle(AIS_InteractiveContext) &myContextIn, Handle(AIS_Shape) &myAisShapeIn, QTextEdit *textEditIn, QEventLoop &myEventLoopIn)
{
	myCurrentToolpath = &myCurrentToolpathIn;
	myViewer = myViewerIn;
	myView = myViewIn;
	myContext = myContextIn;
	myAisShape = &myAisShapeIn;
	myCurrentPart = &myCurrentPartIn;

	bool directionDown;
	if (myCurrentToolpath->myFormingDirectionType == amplToolpath::formingDirectionType::negZDir)
		directionDown = true;
	else
		directionDown = false;

	myAisTopContactPnts = &myAisTopContactPntsIn;
	myCurrentTopContactPnts = &myCurrentTopContactPntsIn;
	myAisBotContactPnts = &myAisBotContactPntsIn;
	myCurrentBotContactPnts = &myCurrentBotContactPntsIn;

	textEdit = textEditIn;
	myEventLoop = &myEventLoopIn;

	if (!myAisTopContactPntsIn.IsNull())
	{
		myContext->Remove(myAisTopContactPntsIn);
		myCurrentTopContactPntsIn.Nullify();
	}

	if (!myAisBotContactPntsIn.IsNull())
	{
		myContext->Remove(myAisBotContactPntsIn);
		myCurrentBotContactPntsIn.Nullify();
	}

	return true;
}

bool SPIF::initToolTipPnts(amplToolpath &myCurrentToolpathIn, TopoDS_Compound &myCurrentTopToolTipsIn, TopoDS_Compound &myCurrentBotToolTipsIn, 
	Handle(AIS_Shape) &myAisTopToolTipsIn, Handle(AIS_Shape) &myAisBotToolTipsIn, TopoDS_Compound &myCurrentPartIn, Handle(V3d_Viewer) &myViewerIn, 
	Handle(V3d_View) &myViewIn, Handle(AIS_InteractiveContext) &myContextIn, Handle(AIS_Shape) &myAisShapeIn, QTextEdit *textEditIn, QEventLoop &myEventLoopIn)
{
	myCurrentToolpath = &myCurrentToolpathIn;
	myViewer = myViewerIn;
	myView = myViewIn;
	myContext = myContextIn;
	myAisShape = &myAisShapeIn;
	myCurrentPart = &myCurrentPartIn;

	bool directionDown;
	if (myCurrentToolpath->myFormingDirectionType == amplToolpath::formingDirectionType::negZDir)
		directionDown = true;
	else
		directionDown = false;

	myAisTopToolTips = &myAisTopToolTipsIn;
	myCurrentTopToolTips = &myCurrentTopToolTipsIn;
	myAisBotToolTips = &myAisBotToolTipsIn;
	myCurrentBotToolTips = &myCurrentBotToolTipsIn;

	textEdit = textEditIn;
	myEventLoop = &myEventLoopIn;

	if (!myAisTopToolTipsIn.IsNull())
	{
		myContext->Remove(myAisTopToolTipsIn);
		myCurrentTopToolTipsIn.Nullify();
	}

	if (!myAisBotToolTipsIn.IsNull())
	{
		myContext->Remove(myAisBotToolTipsIn);
		myCurrentBotToolTipsIn.Nullify();
	}

	return true;
}

bool SPIF::calcContactPnts()
{
	// All "temp" toolpathZHeightProps data objects get reset/changed for each contour slice. Contact points and surface information for ALL slices are stored
	// in masterHeightProps, which is what eventually gets copied into the myCurrentToolpath as output for the algorithm. 
	toolpathZHeightProps masterHeightProps, tempHeightPropsCurrent, tempHeightPropsLast, tempHeightPropsSaved;

	std::vector<float> allZDepthSlices;
	bool initializationSuccess = toolpathPreprocessing(masterHeightProps, allZDepthSlices);
	if (!initializationSuccess)
		return false;

	textEdit->insertPlainText(QString("Initiating SPIF toolpath algorithm. Toolpath rendering will be updated periodically.\n"));
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	textEdit->repaint();

	tempHeightPropsCurrent.copyAllFromOther(masterHeightProps);
	tempHeightPropsLast.copyAllFromOther(masterHeightProps);
	tempHeightPropsSaved.copyAllFromOther(masterHeightProps);

	ampl::amplWireIntersection::pointsXYDirection toolXYDirection = toolXYDirection = ampl::amplWireIntersection::pointsXYDirection::CW;
	if (masterHeightProps.localAmplToolpath.goingCCW)
		toolXYDirection = ampl::amplWireIntersection::pointsXYDirection::CCW;

	bool directionDown = false;
	if (masterHeightProps.localAmplToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::negZDir)
		directionDown = true;

	Standard_Integer zDepthCount = 1;
	Standard_Integer contactPointCounter1 = 0;
	Standard_Real toolpathLength = 0;
	Standard_Real toolpathLengthUpdate = 500;
	for (int depthIndex = 0; depthIndex < allZDepthSlices.size(); depthIndex++)
	{
		float currentDepth = allZDepthSlices.at(depthIndex);
		tempHeightPropsCurrent.currentZDepth = currentDepth;
		gp_Pnt origin(0.0, 0.0, 0.0);
		gp_Pnt zDepthOriginPnt(0.0, 0.0, currentDepth);
		gp_Dir zAxisDir(0.0, 0.0, 1.0);
		gp_Pln zDepthXYPlane(zDepthOriginPnt, zAxisDir);

		ampl::planeIntersecter contourObj(*myCurrentPart, zDepthXYPlane); // Initialize intersecter at the starting depth
		if (!contourObj.performIntersect())
		{
			textEdit->insertPlainText(QString("ERROR at Z-height = ") + QString::number(currentDepth) + QString(" mm\n"));
			textEdit->insertPlainText(QString("ERROR: Failed to perform intersection. Double-check that the part does not contain self-intersecting geometry and that the input heights are correct.\n"));
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			refreshGraphics(masterHeightProps, true, false);
			masterHeightProps.copyAmplContactPntsToOther(*myCurrentToolpath);
			masterHeightProps.copyAmplSurfPropsToOther(*myCurrentToolpath);
			return false;
		}

		bool intersectSuccess = getDiscretizedIntersection(contourObj, tempHeightPropsCurrent, masterHeightProps);
		if (!intersectSuccess)
		{
			masterHeightProps.copyAmplContactPntsToOther(*myCurrentToolpath);
			masterHeightProps.copyAmplSurfPropsToOther(*myCurrentToolpath);
			return false;
		}

		// In SPIF, intersection always results in top contact points
		contourObj.orderDiscretization(tempHeightPropsCurrent.zDepthStartAnglePnt, toolXYDirection, tempHeightPropsCurrent.zDepthTopContactPnts);
		if (!directionDown)
			std::reverse((tempHeightPropsCurrent.zDepthTopContactPnts).begin(), (tempHeightPropsCurrent.zDepthTopContactPnts).end());

		if ((masterHeightProps.localAmplToolpath.contourRampSkipPnts > 0) && (masterHeightProps.localAmplToolpath.mytoolpathMethodType == amplToolpath::toolpathMethodType::contour))
			removeInitialPnts(masterHeightProps.localAmplToolpath.contourRampSkipPnts, tempHeightPropsCurrent.zDepthTopContactPnts);

		if (masterHeightProps.localAmplToolpath.removedCollinearContactPoints)
		{
			std::vector<int> indicesKeptTemp;
			removeCollinearPnts(0.001, tempHeightPropsCurrent.zDepthTopContactPnts, indicesKeptTemp);
		}

		// Extra step to find the points between this contour and last contour for spiral toolpaths
		if ((masterHeightProps.localAmplToolpath.mytoolpathMethodType == amplToolpath::toolpathMethodType::spiral) && (zDepthCount == 1))
		{
			tempHeightPropsSaved.copyZDepthFromOther(tempHeightPropsCurrent); // Need two contours to do spiral algorithm, so skip contact points on first loop
			calcSurfInfo(contourObj, tempHeightPropsSaved, masterHeightProps);  // Surface intersection contact points are stored in "TopContactPnts"
		}
		else
		{
			tempHeightPropsSaved.copyZDepthFromOther(tempHeightPropsCurrent); // Current contact points are saved in tempHeightPropsSaved
			if (masterHeightProps.localAmplToolpath.mytoolpathMethodType == amplToolpath::toolpathMethodType::spiral)
			{
				getSpiralPoints(tempHeightPropsLast, tempHeightPropsCurrent, masterHeightProps, tempHeightPropsSaved);
				if (masterHeightProps.localAmplToolpath.useFastSpiralApprox)
				{
					// Use local contours to approximate the local properties since the contact point is not actually on the surface
					calcApproxSpiralSurfInfo(contourObj, tempHeightPropsLast, tempHeightPropsCurrent, tempHeightPropsSaved, masterHeightProps);
				}
				else
					calcSurfInfo(contourObj, tempHeightPropsSaved, masterHeightProps);
			}
			else
			{
				//tempHeightPropsSaved.copyZDepthFromOther(tempHeightPropsCurrent); // In contour, current slice will be saved
				calcSurfInfo(contourObj, tempHeightPropsSaved, masterHeightProps);  // Surface intersection contact points are stored in "TopContactPnts"
			}
		}
		// calcSurfInfo automatically stores current contact points and surface data from tempHeightPropsSaved into masterHeightProps
		// NOTE: Only information from masterHeightProps gets placed into the toolpath data structure at the end of the algorithm

		// Find out next delta_Z increment if using adaptive slicing
		if (masterHeightProps.localAmplToolpath.adaptiveSlicingOn) 
		{
			float nextZHeight;
			bool keepAdaptiveSlicing = findNextAdaptiveZSlice(tempHeightPropsSaved, masterHeightProps, nextZHeight);
			if (keepAdaptiveSlicing)
				allZDepthSlices.push_back(nextZHeight);
		}

		if ((depthIndex == allZDepthSlices.size() - 1) && (masterHeightProps.localAmplToolpath.mytoolpathMethodType == amplToolpath::toolpathMethodType::spiral))
		{
			tempHeightPropsSaved.resetMembers();
			tempHeightPropsSaved.copyZDepthFromOther(tempHeightPropsCurrent); // On last slice, add the last contour to the toolpath
			calcSurfInfo(contourObj, tempHeightPropsSaved, masterHeightProps);
		}

		contactPointCounter1 = contactPointCounter1 + tempHeightPropsSaved.zDepthTopContactPnts.size();
		toolpathLength = toolpathLength + tempHeightPropsSaved.zDepthTotalIntersectLength;

		// Process events and update graphics
		if (currentDepth == allZDepthSlices.back())
		{
			textEdit->insertPlainText(QString("Generated ") + QString::number(contactPointCounter1) + QString(" contact points for a total distance of ") +
				QString::number(toolpathLength) + QString( " mm, ") + QString("refreshing rendering.  Generation of contact points was SUCCESSFUL!\n"));
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();
			refreshGraphics(masterHeightProps, true, false);
		}
		else if (toolpathLength > toolpathLengthUpdate)
		{
			toolpathLengthUpdate = toolpathLengthUpdate + 2000; // Update every 2000 mm
			textEdit->insertPlainText(QString("Generated ") + QString::number(contactPointCounter1) + QString(" contact points.  ") +
				QString("Currently passing ") + QString::number(currentDepth) + QString(" mm in height.  Refreshing rendering...\n"));
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();
			refreshGraphics(masterHeightProps, true, false);
		}

		myEventLoop->processEvents();

		tempHeightPropsLast.resetMembers();
		tempHeightPropsLast.copyZDepthFromOther(tempHeightPropsCurrent);
		tempHeightPropsCurrent.resetMembers();
		tempHeightPropsSaved.resetMembers();
		zDepthCount++;
	}

	masterHeightProps.copyAmplContactPntsToOther(*myCurrentToolpath);
	masterHeightProps.copyAmplSurfPropsToOther(*myCurrentToolpath);
	return true;
}

bool SPIF::calcToolTipPnts(const bool checkToolpathInterference, const int performConstZHeightTips)
{
	toolpathZHeightProps masterHeightProps, tempHeightPropsSaved;
	
	std::vector<float> allZDepthSlices;
	bool initializationSuccess = toolTipPreprocessing(masterHeightProps);
	if (!initializationSuccess)
		return false;

	textEdit->insertPlainText(QString("Calculating tool-tip points, this may take a few minutes...\n"));
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	textEdit->repaint();

	tempHeightPropsSaved.copyAllFromOther(masterHeightProps);

	getToolTipPoints(masterHeightProps, tempHeightPropsSaved, checkToolpathInterference, performConstZHeightTips);

	tempHeightPropsSaved.pushBackAllToolTipPntsToOther(masterHeightProps, false);
	tempHeightPropsSaved.pushBackAllToolTipPntsModToOther(masterHeightProps, false);

	refreshGraphics(masterHeightProps, false, true);

	masterHeightProps.copyAmplToolTipPntsToOther(*myCurrentToolpath);
	masterHeightProps.copyAmplToolTipPntsModToOther(*myCurrentToolpath);

	textEdit->insertPlainText(QString("Tool-tip points were calculated SUCCESSFULLY!\n"));
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	textEdit->repaint();
	return true;
}

bool SPIF::toolTipPreprocessing(toolpathZHeightProps &masterHeightProps)
{
	float unAssignedVal = myCurrentToolpath->getUnassignedVal();
	if (myCurrentToolpath->topToolTipPntsActive())
		myCurrentToolpath->topToolTipPnts = { {unAssignedVal, unAssignedVal, unAssignedVal} };
	if (myCurrentToolpath->botToolTipPntsActive())
		myCurrentToolpath->botToolTipPnts = { { unAssignedVal, unAssignedVal, unAssignedVal } };
	if (myCurrentToolpath->topToolTipPntsModActive())
		myCurrentToolpath->topToolTipPntsMod = { { unAssignedVal, unAssignedVal, unAssignedVal } };
	if (myCurrentToolpath->botToolTipPntsModActive())
		myCurrentToolpath->botToolTipPntsMod = { { unAssignedVal, unAssignedVal, unAssignedVal } };

	masterHeightProps.init(*myCurrentToolpath);

	std::vector< std::vector<float> > topContactXYZPnts;
	std::vector< std::vector<float> > botContactXYZPnts;
	std::vector<gp_Pnt> topContactPnts;
	std::vector<gp_Pnt> botContactPnts;

	if (myCurrentToolpath->topContactPntsActive())
	{
		topContactXYZPnts = masterHeightProps.localAmplToolpath.topContactPnts;
	}
	if (myCurrentToolpath->botContactPntsActive())
	{
		botContactXYZPnts = masterHeightProps.localAmplToolpath.botContactPnts;
	}

	for (int m = 0; m < topContactXYZPnts.size(); m++)
	{
		gp_Pnt localTempPnt((topContactXYZPnts.at(m)).at(0), (topContactXYZPnts.at(m)).at(1), (topContactXYZPnts.at(m)).at(2));
		topContactPnts.push_back(localTempPnt);
	}
	for (int m = 0; m < botContactXYZPnts.size(); m++)
	{
		gp_Pnt localTempPnt((botContactXYZPnts.at(m)).at(0), (botContactXYZPnts.at(m)).at(1), (botContactXYZPnts.at(m)).at(2));
		botContactPnts.push_back(localTempPnt);
	}

	masterHeightProps.allTopContactPnts = topContactPnts;
	masterHeightProps.allBotContactPnts = botContactPnts;
	masterHeightProps.allContourIndices = masterHeightProps.localAmplToolpath.contourIndices;

	return true;
}

void SPIF::getToolTipPoints(const toolpathZHeightProps &masterHeightProps, toolpathZHeightProps &tempHeightPropsSaved, bool checkForInterference, int performConstZHeightTips)
{
	// Use local copies for easier coding
	std::vector<gp_Pnt> topToolTipPnts;
	std::vector<gp_Pnt> botToolTipPnts;
	std::vector<gp_Pnt> topToolCenterPnts;
	std::vector<gp_Pnt> botToolCenterPnts;
	std::vector<gp_Pnt> topToolCornerCenterPnts;
	std::vector<gp_Pnt> botToolCornerCenterPnts;
	float topToolDiam = masterHeightProps.localAmplToolpath.topToolDiam;
	float botToolDiam = masterHeightProps.localAmplToolpath.botToolDiam;
	float topToolCornerRad, botToolCornerRad;
	std::vector< std::vector<float> > topContactPntsSurfProps;
	std::vector< std::vector<float> > botContactPntsSurfProps;
	std::vector<gp_Pnt> topContactPnts = masterHeightProps.allTopContactPnts;
	std::vector<gp_Pnt> botContactPnts = masterHeightProps.allBotContactPnts;;
	std::vector<gp_Vec> topNormalVecs;
	std::vector<gp_Vec> botNormalVecs;
	
	if (masterHeightProps.localAmplToolpath.topToolProfile == amplToolpath::toolProfile::flatTop)
	{
		topToolCornerRad = masterHeightProps.localAmplToolpath.topToolCornerRad;
	}
	if (masterHeightProps.localAmplToolpath.botToolProfile == amplToolpath::toolProfile::flatTop)
	{
		botToolCornerRad = masterHeightProps.localAmplToolpath.botToolCornerRad;
	}

	if (myCurrentToolpath->topContactPntsActive())
	{
		topContactPntsSurfProps = masterHeightProps.localAmplToolpath.topContactPntsSurfProps;
	}
	if (myCurrentToolpath->botContactPntsActive())
	{
		botContactPntsSurfProps = masterHeightProps.localAmplToolpath.botContactPntsSurfProps;
	}

	for (int m = 0; m < topContactPntsSurfProps.size(); m++)
	{
		gp_Vec localTempVec(gp_Dir((topContactPntsSurfProps.at(m)).at(0), (topContactPntsSurfProps.at(m)).at(1), (topContactPntsSurfProps.at(m)).at(2)));
		topNormalVecs.push_back(localTempVec);
	}
	for (int m = 0; m < botContactPntsSurfProps.size(); m++)
	{
		gp_Vec localTempVec(gp_Dir((botContactPntsSurfProps.at(m)).at(0), (botContactPntsSurfProps.at(m)).at(1), (botContactPntsSurfProps.at(m)).at(2)));
		botNormalVecs.push_back(localTempVec);
	}

	bool directionDown = true;
	if (masterHeightProps.localAmplToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::posZDir)
		directionDown = false;

	bool goingCCWLocal = masterHeightProps.localAmplToolpath.goingCCW;

	if (directionDown)
	{
		// Start calculating tool tip points for top tool
		if (masterHeightProps.localAmplToolpath.topToolProfile == amplToolpath::toolProfile::hemispherical)
		{
			if (topContactPnts.size() == topNormalVecs.size())
			{
				for (int m = 0; m < topContactPnts.size(); m++)
				{
					gp_Pnt curPnt = topContactPnts.at(m);
					gp_Vec translationVec1 = topNormalVecs.at(m); // Set to be facing positive z-direction
					translationVec1.Scale(topToolDiam / 2.0);
					gp_Vec translateZVec(0.0, 0.0, -topToolDiam / 2.0);

					curPnt.Translate(translationVec1);
					topToolCenterPnts.push_back(curPnt);

					curPnt.Translate(translateZVec);
					topToolTipPnts.push_back(curPnt);
				}
			}
		}
		else if (masterHeightProps.localAmplToolpath.topToolProfile == amplToolpath::toolProfile::flatTop)
		{
			if (topContactPnts.size() == topNormalVecs.size())
			{
				for (int m = 0; m < topContactPnts.size(); m++)
				{
					gp_Pnt curPnt = topContactPnts.at(m);
					gp_Vec translationVec1 = topNormalVecs.at(m); 
					translationVec1.Scale(topToolCornerRad);
					curPnt.Translate(translationVec1);
					topToolCornerCenterPnts.push_back(curPnt);

					gp_Dir translationDir2;
					findLocalTangentDirection(curPnt, m, topContactPnts, topNormalVecs, false, goingCCWLocal, translationDir2);
					gp_Vec translationVec2(translationDir2);
					translationVec2.Scale((topToolDiam / 2.0) - topToolCornerRad);
					curPnt.Translate(translationVec2);
					topToolCenterPnts.push_back(curPnt);

					gp_Vec translateZVec(0.0, 0.0, -topToolCornerRad);
					curPnt.Translate(translateZVec);
					topToolTipPnts.push_back(curPnt);
				}
			}
		}
		tempHeightPropsSaved.allTopToolTipPnts = topToolTipPnts;
	}
	else
	{
		// Start calculating tool tip points for bottom tool
		if (masterHeightProps.localAmplToolpath.botToolProfile == amplToolpath::toolProfile::hemispherical)
		{
			if (botContactPnts.size() == botNormalVecs.size())
			{
				for (int m = 0; m < botContactPnts.size(); m++)
				{
					gp_Pnt curPnt = botContactPnts.at(m);
					gp_Vec translationVec1 = botNormalVecs.at(m); // Set to be facing negative z-direction
					translationVec1.Scale(botToolDiam / 2.0);
					gp_Vec translateZVec(0.0, 0.0, botToolDiam / 2.0);

					curPnt.Translate(translationVec1);
					botToolCenterPnts.push_back(curPnt);

					curPnt.Translate(translateZVec);
					botToolTipPnts.push_back(curPnt);
				}
			}
		}
		else if (masterHeightProps.localAmplToolpath.botToolProfile == amplToolpath::toolProfile::flatTop)
		{
			if (botContactPnts.size() == botNormalVecs.size())
			{
				for (int m = 0; m < botContactPnts.size(); m++)
				{
					gp_Pnt curPnt = botContactPnts.at(m);
					gp_Vec translationVec1 = botNormalVecs.at(m);
					translationVec1.Scale(botToolCornerRad);
					curPnt.Translate(translationVec1);
					botToolCornerCenterPnts.push_back(curPnt);

					gp_Dir translationDir2;
					findLocalTangentDirection(curPnt, m, botContactPnts, botNormalVecs, false, goingCCWLocal, translationDir2);
					gp_Vec translationVec2(translationDir2);
					translationVec2.Scale((botToolDiam / 2.0) - botToolCornerRad);
					curPnt.Translate(translationVec2);
					botToolCenterPnts.push_back(curPnt);

					gp_Vec translateZVec(0.0, 0.0, botToolCornerRad);
					curPnt.Translate(translateZVec);
					botToolTipPnts.push_back(curPnt);
				}
			}
		}
		tempHeightPropsSaved.allBotToolTipPnts = botToolTipPnts;
	}

	// Adjust tool tip positions for each contour/revolution to maintain constant Z-height fluctuations
	if (directionDown && (performConstZHeightTips == 2 || performConstZHeightTips == 1)) // Currently, the dialog forces this option to be hemispherical tools only
	{
		correctConstZHeightTips(true, masterHeightProps, topToolDiam / 2.0, topContactPnts, topToolCenterPnts, topNormalVecs, topToolTipPnts);
		tempHeightPropsSaved.allTopToolTipPnts = topToolTipPnts;
	}
	else if (!directionDown && (performConstZHeightTips == 2 || performConstZHeightTips == -1)) // Currently, the dialog forces this option to be hemispherical tools only
	{
		correctConstZHeightTips(false, masterHeightProps, botToolDiam / 2.0, botContactPnts, botToolCenterPnts, botNormalVecs, botToolTipPnts);
		tempHeightPropsSaved.allBotToolTipPnts = botToolTipPnts;
	}

	// Now check and potentially correct for toolpath self interference
	std::vector<gp_Pnt> topToolCenterPntsMod, topToolCornerCenterPntsMod;
	std::vector<gp_Pnt> botToolCenterPntsMod, botToolCornerCenterPntsMod;;
	if (checkForInterference)
	{
		bool topToolInterferenceTrue = false;
		bool botToolInterferenceTrue = false;
		float maxTopInterferenceVal, maxBotInterferenceVal;

		if (masterHeightProps.localAmplToolpath.topToolProfile == amplToolpath::toolProfile::hemispherical && directionDown)
			topToolInterferenceTrue = correctSphericalInterference(true, topToolCenterPnts, topToolTipPnts, topContactPnts, topNormalVecs, topToolDiam / 2.0, 0.002, tempHeightPropsSaved.allTopToolTipPntsMod, topToolCenterPntsMod, maxTopInterferenceVal);
		else if (masterHeightProps.localAmplToolpath.topToolProfile == amplToolpath::toolProfile::flatTop && directionDown)
			topToolInterferenceTrue = correctFlatTopInterference(true, topToolCenterPnts, topToolCornerCenterPnts, topToolTipPnts, topContactPnts, topNormalVecs, topToolDiam / 2.0, topToolCornerRad, 0.002, tempHeightPropsSaved.allTopToolTipPntsMod, topToolCenterPntsMod, topToolCornerCenterPntsMod, maxTopInterferenceVal);
		else if(masterHeightProps.localAmplToolpath.botToolProfile == amplToolpath::toolProfile::hemispherical && !directionDown)
			botToolInterferenceTrue = correctSphericalInterference(false, botToolCenterPnts, botToolTipPnts, botContactPnts, botNormalVecs, botToolDiam / 2.0, 0.002, tempHeightPropsSaved.allBotToolTipPntsMod, botToolCenterPntsMod, maxBotInterferenceVal);
		else if (masterHeightProps.localAmplToolpath.botToolProfile == amplToolpath::toolProfile::flatTop && !directionDown)
			botToolInterferenceTrue = correctFlatTopInterference(false, botToolCenterPnts, botToolCornerCenterPnts, botToolTipPnts, botContactPnts, botNormalVecs, botToolDiam / 2.0, botToolCornerRad, 0.002, tempHeightPropsSaved.allBotToolTipPntsMod, botToolCenterPntsMod, botToolCornerCenterPntsMod, maxBotInterferenceVal);

		if (topToolInterferenceTrue)
		{
			QString maxTopInterferenceStr = QString::number(maxTopInterferenceVal);
			QString interferenceMsg = QString("SELF-INTERFERENCE of ") + maxTopInterferenceStr + QString(" mm was found in the TOP tool's toolpath. Modified and original tool-tip points will be saved. Use the Toolpath Visibility options to access both.\n");
			textEdit->insertPlainText(interferenceMsg);
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();
		}
		else if (botToolInterferenceTrue)
		{
			QString maxBotInterferenceStr = QString::number(maxBotInterferenceVal);
			QString interferenceMsg = QString("SELF-INTERFERENCE of ") + maxBotInterferenceStr + QString(" mm was found in the BOTTOM tool's toolpath. Modified and original tool-tip points will be saved. Use the Toolpath Visibility options to access both.\n");
			textEdit->insertPlainText(interferenceMsg);
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();
		}
	}
}

/*void SPIF::correctToolTipSelfIntersections(const toolpathZHeightProps &masterHeightProps, toolpathZHeightProps &tempHeightPropsSaved)
{
	// Use local copies for easier coding
	std::vector<gp_Pnt> topToolTipPnts = tempHeightPropsSaved.allTopToolTipPnts;
	std::vector<gp_Pnt> botToolTipPnts = tempHeightPropsSaved.allBotToolTipPnts;
	float topToolDiam = masterHeightProps.localAmplToolpath.topToolDiam;
	float botToolDiam = masterHeightProps.localAmplToolpath.botToolDiam;
	std::vector< std::vector<float> > topContactPntsSurfProps;
	std::vector< std::vector<float> > botContactPntsSurfProps;
	std::vector<gp_Pnt> topContactPnts = tempHeightPropsSaved.allTopContactPnts;
	std::vector<gp_Pnt> botContactPnts = tempHeightPropsSaved.allBotContactPnts;;
	std::vector<gp_Vec> topNormalVecs;
	std::vector<gp_Vec> botNormalVecs;

	if (myCurrentToolpath->topContactPntsActive())
	{
		topContactPntsSurfProps = masterHeightProps.localAmplToolpath.topContactPntsSurfProps;
	}
	if (myCurrentToolpath->botContactPntsActive())
	{
		botContactPntsSurfProps = masterHeightProps.localAmplToolpath.botContactPntsSurfProps;
	}

	for (int m = 0; m < topContactPntsSurfProps.size(); m++)
	{
		gp_Vec localTempVec(gp_Dir((topContactPntsSurfProps.at(m)).at(0), (topContactPntsSurfProps.at(m)).at(1), (topContactPntsSurfProps.at(m)).at(2)));
		topNormalVecs.push_back(localTempVec);
	}
	for (int m = 0; m < botContactPntsSurfProps.size(); m++)
	{
		gp_Vec localTempVec(gp_Dir((botContactPntsSurfProps.at(m)).at(0), (botContactPntsSurfProps.at(m)).at(1), (botContactPntsSurfProps.at(m)).at(2)));
		botNormalVecs.push_back(localTempVec);
	}

	bool directionDown = true;
	if (masterHeightProps.localAmplToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::posZDir)
		directionDown = false;

	if (masterHeightProps.localAmplToolpath.topToolProfile == amplToolpath::toolProfile::hemispherical)
	{

	}

	if (masterHeightProps.localAmplToolpath.botToolProfile == amplToolpath::toolProfile::hemispherical)
	{

	}
}*/

void SPIF::refreshGraphics(const toolpathZHeightProps &allHeightProps, bool refreshContactPnts, bool refreshToolTipPnts)
{
	if (refreshContactPnts)
	{
		TopoDS_Vertex localVertex;
		BRep_Builder topVertexCompoundBuilder;
		BRep_Builder botVertexCompoundBuilder;

		Standard_Integer numBotPoints = allHeightProps.allBotContactPnts.size();
		if (!myAisBotContactPnts->IsNull())
		{
			myContext->Remove(*myAisBotContactPnts, false);
			myAisBotContactPnts->Nullify();
			myCurrentBotContactPnts->Nullify();
		}
		botVertexCompoundBuilder.MakeCompound(*myCurrentBotContactPnts);

		for (Standard_Integer arrIndex = 0; arrIndex < numBotPoints; arrIndex++)
		{
			localVertex = BRepBuilderAPI_MakeVertex(allHeightProps.allBotContactPnts.at(arrIndex));
			botVertexCompoundBuilder.Add(*myCurrentBotContactPnts, localVertex);
		}

		*myAisBotContactPnts = new AIS_Shape(*myCurrentBotContactPnts);
		(*myAisBotContactPnts)->SetColor(Quantity_NOC_RED1);
		myContext->Display(*myAisBotContactPnts);

		Standard_Integer numTopPoints = allHeightProps.allTopContactPnts.size();
		if (!myAisTopContactPnts->IsNull())
		{
			myContext->Remove(*myAisTopContactPnts, false);
			myAisTopContactPnts->Nullify();
			myCurrentTopContactPnts->Nullify();
		}
		topVertexCompoundBuilder.MakeCompound(*myCurrentTopContactPnts);

		for (Standard_Integer arrIndex = 0; arrIndex < numTopPoints; arrIndex++)
		{
			localVertex = BRepBuilderAPI_MakeVertex(allHeightProps.allTopContactPnts.at(arrIndex));
			topVertexCompoundBuilder.Add(*myCurrentTopContactPnts, localVertex);
		}

		*myAisTopContactPnts = new AIS_Shape(*myCurrentTopContactPnts);
		(*myAisTopContactPnts)->SetColor(Quantity_NOC_BLUE1);
		myContext->Display(*myAisTopContactPnts);
	}

	if (refreshToolTipPnts)
	{		
		bool useModifiedTopTipPnts = false;
		bool useModifiedBotTipPnts = false;
		if (allHeightProps.allTopToolTipPntsMod.size() > 0)
			useModifiedTopTipPnts = true;
		if (allHeightProps.allBotToolTipPntsMod.size() > 0)
			useModifiedBotTipPnts = true;

		Standard_Integer numBotPoints;
		if(useModifiedBotTipPnts)
			numBotPoints = allHeightProps.allBotToolTipPntsMod.size();
		else
			numBotPoints = allHeightProps.allBotToolTipPnts.size();

		if (!myAisBotToolTips->IsNull())
		{
			myContext->Remove(*myAisBotToolTips, false);
			myAisBotToolTips->Nullify();
			myCurrentBotToolTips->Nullify();
		}

		TopoDS_Vertex botLocalVertex;
		BRep_Builder botVertexCompoundBuilder;
		botVertexCompoundBuilder.MakeCompound(*myCurrentBotToolTips);
		for (Standard_Integer arrIndex = 0; arrIndex < numBotPoints; arrIndex++)
		{
			if (useModifiedBotTipPnts)
				botLocalVertex = BRepBuilderAPI_MakeVertex(allHeightProps.allBotToolTipPntsMod.at(arrIndex));
			else
				botLocalVertex = BRepBuilderAPI_MakeVertex(allHeightProps.allBotToolTipPnts.at(arrIndex));

			botVertexCompoundBuilder.Add(*myCurrentBotToolTips, botLocalVertex);
		}

		*myAisBotToolTips = new AIS_Shape(*myCurrentBotToolTips);
		(*myAisBotToolTips)->SetColor(Quantity_NOC_MAGENTA1);
		myContext->Display(*myAisBotToolTips);

		Standard_Integer numTopPoints;
		if (useModifiedTopTipPnts)
			numTopPoints = allHeightProps.allTopToolTipPntsMod.size();
		else
			numTopPoints = allHeightProps.allTopToolTipPnts.size();

		if (!myAisTopToolTips->IsNull())
		{
			myContext->Remove(*myAisTopToolTips, false);
			myAisTopToolTips->Nullify();
			myCurrentTopToolTips->Nullify();
		}

		TopoDS_Vertex topLocalVertex;
		BRep_Builder topVertexCompoundBuilder;
		topVertexCompoundBuilder.MakeCompound(*myCurrentTopToolTips);
		for (Standard_Integer arrIndex = 0; arrIndex < numTopPoints; arrIndex++)
		{
			if (useModifiedTopTipPnts)
				topLocalVertex = BRepBuilderAPI_MakeVertex(allHeightProps.allTopToolTipPntsMod.at(arrIndex));
			else
				topLocalVertex = BRepBuilderAPI_MakeVertex(allHeightProps.allTopToolTipPnts.at(arrIndex));

			topVertexCompoundBuilder.Add(*myCurrentTopToolTips, topLocalVertex);
		}

		*myAisTopToolTips = new AIS_Shape(*myCurrentTopToolTips);
		(*myAisTopToolTips)->SetColor(Quantity_NOC_CYAN1);
		myContext->Display(*myAisTopToolTips);
	}
}

void SPIF::removeCollinearPnts(Standard_Real relAngleTolDeg, std::vector<gp_Pnt> &orderdPntsArrInOut, std::vector<int> &indicesKept)
{
	std::vector<gp_Pnt> zDepthPnts = orderdPntsArrInOut;
	orderdPntsArrInOut.clear();
	indicesKept.clear();

	// Go through and take out groups of points that are collinear
	Standard_Real relAngleTol = 0.001; //deg
	for (int m = 0; m < zDepthPnts.size() - 2; m++)
	{
		gp_Pnt curPnt = zDepthPnts.at(m);
		gp_Pnt curPntMP1 = zDepthPnts.at(m + 1);
		gp_Pnt curPntMP2 = zDepthPnts.at(m + 2);

		if (m == 0)
		{
			orderdPntsArrInOut.push_back(curPnt);
			indicesKept.push_back(m);
		}

		if ((curPnt.Distance(curPntMP1) < 0.002) || (curPnt.Distance(curPntMP2) < 0.002))
		{
			continue;
		}

		gp_Vec vec12(curPnt, curPntMP1);
		gp_Vec vec13(curPnt, curPntMP2);
		Standard_Real relAngle = (vec12.Angle(vec13))*180.0 / 3.14159265358979323846;
		int nextPntIndex = m + 1;

		if (relAngle <= relAngleTol)
		{
			for (int n = m + 3; n < zDepthPnts.size(); n++)
			{
				nextPntIndex = n - 1;
				gp_Pnt nextPnt = zDepthPnts.at(n);
				if (curPnt.Distance(nextPnt) < 0.002)
				{
					continue;
				}

				gp_Vec vecNext(curPnt, nextPnt);
				relAngle = (vec12.Angle(vecNext))*180.0 / 3.14159265358979323846;
				if (relAngle > relAngleTol)
				{
					//nextPntIndex = nextPntIndex - 1;
					break;
				}
			}
			m = nextPntIndex; // Going to get added by 1 by the for loop
			orderdPntsArrInOut.push_back(zDepthPnts.at(nextPntIndex + 1));
			indicesKept.push_back(nextPntIndex + 1);
		}
		else if (m == zDepthPnts.size() - 3)
		{
			orderdPntsArrInOut.push_back(curPntMP1);
			indicesKept.push_back(m + 1);

			orderdPntsArrInOut.push_back(curPntMP2);
			indicesKept.push_back(m + 2);
		}
		else
		{
			orderdPntsArrInOut.push_back(curPntMP1);
			indicesKept.push_back(m + 1);
		}
	}
}

bool SPIF::toolpathPreprocessing(toolpathZHeightProps &masterHeightProps, std::vector<float> &allZDepthSlices)
{
	float unAssignedVal = myCurrentToolpath->getUnassignedVal();
	if (myCurrentToolpath->topContactPntsActive())
		myCurrentToolpath->topContactPnts = { { unAssignedVal, unAssignedVal, unAssignedVal } };
	if (myCurrentToolpath->botContactPntsActive())
		myCurrentToolpath->botContactPnts = { { unAssignedVal, unAssignedVal, unAssignedVal } };

	if (myCurrentToolpath->topContactPntsSurfPropsActive())
		myCurrentToolpath->topContactPntsSurfProps = { { unAssignedVal, unAssignedVal, unAssignedVal, unAssignedVal,
														 unAssignedVal, unAssignedVal, unAssignedVal, unAssignedVal,
														 unAssignedVal, unAssignedVal, unAssignedVal, unAssignedVal, unAssignedVal } };
	if (myCurrentToolpath->botContactPntsSurfPropsActive())
		myCurrentToolpath->botContactPntsSurfProps = { { unAssignedVal, unAssignedVal, unAssignedVal, unAssignedVal,
														 unAssignedVal, unAssignedVal, unAssignedVal, unAssignedVal,
													     unAssignedVal, unAssignedVal, unAssignedVal, unAssignedVal, unAssignedVal } };

	myCurrentToolpath->contourIndices = { 0 };

	masterHeightProps.init(*myCurrentToolpath);

	bool directionDown = false;
	if (masterHeightProps.localAmplToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::negZDir)
		directionDown = true;

	if (directionDown)
	{
		masterHeightProps.localAmplToolpath.startDepth = masterHeightProps.localAmplToolpath.startDepth - 0.005;
		masterHeightProps.localAmplToolpath.endDepth = masterHeightProps.localAmplToolpath.endDepth + 0.005;

		if (masterHeightProps.localAmplToolpath.endDepth >= masterHeightProps.localAmplToolpath.startDepth)
		{
			textEdit->insertPlainText("ERROR: Going in the negative Z-direction but the end depth is larger than the start depth.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}
	}
	else
	{
		masterHeightProps.localAmplToolpath.startDepth = masterHeightProps.localAmplToolpath.startDepth + 0.005;
		masterHeightProps.localAmplToolpath.endDepth = masterHeightProps.localAmplToolpath.endDepth - 0.005;

		if (masterHeightProps.localAmplToolpath.endDepth <= masterHeightProps.localAmplToolpath.startDepth)
		{
			textEdit->insertPlainText("ERROR: Going in the positive Z-direction but the end depth is smaller than the start depth.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}
	}

	if (masterHeightProps.localAmplToolpath.useFastSpiralApprox)
		masterHeightProps.localAmplToolpath.removedCollinearContactPoints = false;

	float startHeight = masterHeightProps.localAmplToolpath.startDepth;
	float endHeight = masterHeightProps.localAmplToolpath.endDepth;
	float incDepth = masterHeightProps.localAmplToolpath.incDepth;

	// Determine what z-heights that will be used in the algorithm
	allZDepthSlices.clear();
	allZDepthSlices = { startHeight };

	if (!masterHeightProps.localAmplToolpath.adaptiveSlicingOn)
	{
		bool moreDepthToCut = true;
		float nextDepth, lastDepth;
		int zDepthLen = 1;
		while (moreDepthToCut)
		{
			if (zDepthLen == 1)
				lastDepth = startHeight;
			else
				lastDepth = nextDepth;

			if (directionDown)
			{
				nextDepth = lastDepth - incDepth; // This algorithm goes in negative z-direction

				if (nextDepth >= endHeight)
				{
					zDepthLen++;
					allZDepthSlices.push_back(nextDepth);
				}
				else if (lastDepth >= endHeight)
				{
					zDepthLen++;
					allZDepthSlices.push_back(endHeight);
					moreDepthToCut = false;
				}
				else
					moreDepthToCut = false;
			}
			else
			{
				nextDepth = lastDepth + incDepth; // This algorithm goes in positive z-direction

				if (nextDepth <= endHeight)
				{
					zDepthLen++;
					allZDepthSlices.push_back(nextDepth);
				}
				else if (lastDepth <= endHeight)
				{
					zDepthLen++;
					allZDepthSlices.push_back(endHeight);
					moreDepthToCut = false;
				}
				else
					moreDepthToCut = false;
			}
		}
	}
	return true;
}

bool SPIF::findNextAdaptiveZSlice(const toolpathZHeightProps &tempHeightPropsCurrent, const toolpathZHeightProps &masterHeightProps, float &nextZHeightOut)
{
	const float PI_Local = 3.14159265358979323846;
	float minWallAngle = 100.0; //rad
	for (const gp_Vec &localNormalVec : tempHeightPropsCurrent.zDepthNormals)
	{
		float currentWallAngle;
	
		if (abs(localNormalVec.X()) <= 0.001 && abs(localNormalVec.Y()) <= 0.001)
		{
			currentWallAngle = 0.0;
		}
		else
		{
			gp_Dir localXYNormalDir(localNormalVec.X(), localNormalVec.Y(), 0.0);
			gp_Vec localXYNormalVec(localXYNormalDir);
			currentWallAngle = (PI_Local / 2.0) - localNormalVec.Angle(localXYNormalVec);
		}
	
		if (currentWallAngle < minWallAngle)
		{
			minWallAngle = currentWallAngle;
		}
	}
	
	minWallAngle = abs(minWallAngle); // Calculated increment will always be positive

	bool directionDown = false;
	if (masterHeightProps.localAmplToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::negZDir)
		directionDown = true;

	float incDepth = masterHeightProps.localAmplToolpath.incDepth;
	float nextIncHeight = incDepth*sinf(minWallAngle);
	float currentHeight = tempHeightPropsCurrent.currentZDepth;
	float endHeight = masterHeightProps.localAmplToolpath.endDepth;
	
	if (nextIncHeight < (incDepth / 7.5))
		nextIncHeight = (incDepth / 7.5);
	
	if (nextIncHeight < 0.010)
		nextIncHeight = 0.010;
	
	if (directionDown)
	{
		nextZHeightOut = currentHeight - nextIncHeight; // This algorithm goes in negative z-direction
	
		if (nextZHeightOut >= endHeight)
		{
			return true;
		}
		else if (currentHeight > endHeight)
		{
			nextZHeightOut = endHeight;
			return true;
		}
		else
			return false;
	}
	else
	{
		nextZHeightOut = currentHeight + nextIncHeight; // This algorithm goes in positive z-direction
	
		if (nextZHeightOut <= endHeight)
		{
			return true;
		}
		else if (currentHeight < endHeight)
		{
			nextZHeightOut = endHeight;
			return true;
		}
		else
			return false;
	}
	
}

bool SPIF::getDiscretizedIntersection(ampl::planeIntersecter &contourObj, toolpathZHeightProps &tempHeightPropsCurrent, const toolpathZHeightProps &masterHeightProps)
{
	float currentHeight = tempHeightPropsCurrent.currentZDepth;
	bool edgeToEdgeTolSuccess = false;
	Standard_Real edgeToEdgeTol = 0.005;
	std::vector<double> edgeToEdgeTolArr = { 0.01, 0.02, 0.035, 0.05, 0.075, 0.1 };
	contourObj.setEdgeToEdgeTol(0.005);
	contourObj.sortIntersection();
	
	Standard_Integer numClosedWires = 0;
	std::vector<int> closedWireIndices;
	contourObj.getNumClosedWires(numClosedWires, closedWireIndices);
	
	if (numClosedWires == 0)
	{
		int edgeToEdgeCount = 1;
		for (double tol : edgeToEdgeTolArr) // Try sorting the edges with a larger tolerance
		{
			contourObj.resetWireArray();
			contourObj.setEdgeToEdgeTol(tol);
			contourObj.sortIntersection();
			contourObj.getNumClosedWires(numClosedWires, closedWireIndices);
	
			if (numClosedWires > 0)
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
	
	Standard_Integer numWires;
	contourObj.getNumWires(numWires);
	contourObj.getNumClosedWires(numClosedWires, closedWireIndices);
	
	if (numWires > 1)
	{
		textEdit->insertPlainText(QString("WARNING at Z-height = ") + QString::number(currentHeight) + QString(" mm\n"));
		textEdit->insertPlainText("WARNING: Multiple wires were found upon intersecting the part with the translated XY-plane. Generating contact points for all wires...\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();
	}
	else if (numWires == 0)
	{
		textEdit->insertPlainText(QString("ERROR at Z-height = ") + QString::number(currentHeight) + QString(" mm\n"));
		textEdit->insertPlainText("ERROR: No wires were found after intersecting the part with the translated XY-plane.\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		refreshGraphics(masterHeightProps, true, false);
		return false;
	}
	else if (numClosedWires == 0)
	{
		textEdit->insertPlainText(QString("WARNING at Z-height = ") + QString::number(currentHeight) + QString(" mm\n"));
		textEdit->insertPlainText("WARNING: No closed wires were found after intersecting the part with the translated XY-plane. Attempting to automatically close the wire...\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();
	}
	
	tempHeightPropsCurrent.zDepthTopContactPnts.clear(); // SPIF - Always assumed to intersect the part and get the top contact points
	tempHeightPropsCurrent.zDepthBotContactPnts.clear();
	tempHeightPropsCurrent.zDepthTotalIntersectLength = 0.0;
	std::vector<gp_Pnt> localIntersectPnts;
	std::vector<gp_Pnt> comArr;
	std::vector<float> wireLengthArr;
	for (int wireIndex = 0; wireIndex < numWires; wireIndex++) // Discretize all wires (assuming they are one contour)
	{
		Standard_Real maxDistFromFirstCoM, wireDistLocal;
		gp_Pnt localCOMPnt;
		contourObj.getCenterOfMass(wireIndex, localCOMPnt);
		contourObj.getWireLength(wireIndex, wireDistLocal);
		comArr.push_back(localCOMPnt);
		wireLengthArr.push_back(wireDistLocal);
		tempHeightPropsCurrent.zDepthTotalIntersectLength = tempHeightPropsCurrent.zDepthTotalIntersectLength + wireDistLocal;
	
		if((masterHeightProps.localAmplToolpath.mytoolpathMethodType == amplToolpath::toolpathMethodType::spiral) && (masterHeightProps.localAmplToolpath.useFastSpiralApprox))
			contourObj.discretizeIntersection(wireIndex, masterHeightProps.localAmplToolpath.incToolpathCurve/2.0, localIntersectPnts);
		else
			contourObj.discretizeIntersection(wireIndex, masterHeightProps.localAmplToolpath.incToolpathCurve, localIntersectPnts);

		for (gp_Pnt &tempPnt : localIntersectPnts)
		{
			(tempHeightPropsCurrent.zDepthTopContactPnts).push_back(tempPnt);
		}
		localIntersectPnts.clear();
	}
	
	float tempSumX = 0, tempSumY = 0, tempSumZ = 0; // Find the average center of gravity (weighted based on edge length) of the intersection
	for (int wireIndex = 0; wireIndex < numWires; wireIndex++)
	{
		gp_Pnt curComPnt = comArr.at(wireIndex);
		Standard_Real curEdgeLength = wireLengthArr.at(wireIndex);
	
		tempSumX = tempSumX + (curEdgeLength / tempHeightPropsCurrent.zDepthTotalIntersectLength)*curComPnt.X();
		tempSumY = tempSumY + (curEdgeLength / tempHeightPropsCurrent.zDepthTotalIntersectLength)*curComPnt.Y();
		tempSumZ = tempSumZ + (curEdgeLength / tempHeightPropsCurrent.zDepthTotalIntersectLength)*curComPnt.Z();
	}
	
	float startAngleRad = masterHeightProps.localAmplToolpath.startAngleFromXAxisDeg * 3.14159265358979323846 / 180.0;
	float maxDistanceFromCOM = masterHeightProps.localAmplToolpath.startRadialDistance;
	tempHeightPropsCurrent.zDepthMaxDistanceFromCOM = maxDistanceFromCOM;
	tempHeightPropsCurrent.zDepthAvgCoM = gp_Pnt(tempSumX / numWires, tempSumY / numWires, tempSumZ / numWires);
	tempHeightPropsCurrent.zDepthStartAnglePnt = gp_Pnt(0.0, 0.0, 0.0);
	tempHeightPropsCurrent.zDepthStartAnglePnt.SetX(tempHeightPropsCurrent.zDepthStartAnglePnt.X() + maxDistanceFromCOM*cos(startAngleRad));
	tempHeightPropsCurrent.zDepthStartAnglePnt.SetY(tempHeightPropsCurrent.zDepthStartAnglePnt.Y() + maxDistanceFromCOM*sin(startAngleRad));
	
	return true;
}

void SPIF::calcSurfInfo(ampl::planeIntersecter &contourObj, toolpathZHeightProps &tempHeightPropsSaved, toolpathZHeightProps &masterHeightProps)
{
	bool directionDown = false;
	if (masterHeightProps.localAmplToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::negZDir)
		directionDown = true;

	if (masterHeightProps.allContourIndices.empty()) // Store the last index of each slice/revolution
		masterHeightProps.allContourIndices.push_back((tempHeightPropsSaved.zDepthTopContactPnts.size() - 1));
	else if (masterHeightProps.allContourIndices.size() == 1 && masterHeightProps.allContourIndices.at(0) == 0)
		masterHeightProps.allContourIndices.at(0) = tempHeightPropsSaved.zDepthTopContactPnts.size() - 1;
	else
		masterHeightProps.allContourIndices.push_back(masterHeightProps.allContourIndices.back() + tempHeightPropsSaved.zDepthTopContactPnts.size());

	masterHeightProps.localAmplToolpath.contourIndices = masterHeightProps.allContourIndices;

	if (directionDown)
	{
		contourObj.getAllSurfProps(tempHeightPropsSaved.zDepthTopContactPnts, tempHeightPropsSaved.zDepthAvgCoM, true, tempHeightPropsSaved.zDepthNormals,
			tempHeightPropsSaved.zDepthKappaMax, tempHeightPropsSaved.zDepthKappaMaxDirections, tempHeightPropsSaved.zDepthKappaMin, tempHeightPropsSaved.zDepthKappaMinDirections,
			tempHeightPropsSaved.zDepthKappaMean, tempHeightPropsSaved.zDepthKappaGaussian);

		tempHeightPropsSaved.pushBackZDepthTopContactPnts(false, false);
		tempHeightPropsSaved.pushBackZDepthContactPntsSurfProps(false, 1);
	}
	else
	{
		contourObj.getAllSurfProps(tempHeightPropsSaved.zDepthTopContactPnts, tempHeightPropsSaved.zDepthAvgCoM, false, tempHeightPropsSaved.zDepthNormals,
			tempHeightPropsSaved.zDepthKappaMax, tempHeightPropsSaved.zDepthKappaMaxDirections, tempHeightPropsSaved.zDepthKappaMin, tempHeightPropsSaved.zDepthKappaMinDirections,
			tempHeightPropsSaved.zDepthKappaMean, tempHeightPropsSaved.zDepthKappaGaussian);

		tempHeightPropsSaved.zDepthBotContactPnts = tempHeightPropsSaved.zDepthTopContactPnts;
		tempHeightPropsSaved.pushBackZDepthBotContactPnts(false, true, false);
		tempHeightPropsSaved.pushBackZDepthContactPntsSurfProps(false, -1);
	}

	// Add the current contact points and properties at this Z-depth to the master object 
	tempHeightPropsSaved.pushBackAllContactPntsToOther(masterHeightProps, false);
	if (directionDown)
		tempHeightPropsSaved.pushBackAllSurfPropsToOther(masterHeightProps, 1, false);
	else
		tempHeightPropsSaved.pushBackAllSurfPropsToOther(masterHeightProps, -1, false);
}

void SPIF::calcApproxSpiralSurfInfo(ampl::planeIntersecter &contourObj, toolpathZHeightProps &tempHeightPropsLast, toolpathZHeightProps &tempHeightPropsCurrent, toolpathZHeightProps &tempHeightPropsSaved, toolpathZHeightProps &masterHeightProps)
{
	// These are copied from regular SPIF::calcSurfInfo(...)
	bool directionDown = false;
	if (masterHeightProps.localAmplToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::negZDir)
		directionDown = true;

	if (masterHeightProps.allContourIndices.empty()) // Store the last index of each slice/revolution
		masterHeightProps.allContourIndices.push_back((tempHeightPropsSaved.zDepthTopContactPnts.size() - 1));
	else if (masterHeightProps.allContourIndices.size() == 1 && masterHeightProps.allContourIndices.at(0) == 0)
		masterHeightProps.allContourIndices.at(0) = tempHeightPropsSaved.zDepthTopContactPnts.size() - 1;
	else
		masterHeightProps.allContourIndices.push_back(masterHeightProps.allContourIndices.back() + tempHeightPropsSaved.zDepthTopContactPnts.size());

	masterHeightProps.localAmplToolpath.contourIndices = masterHeightProps.allContourIndices;

	if (directionDown)
	{
		// Get properties of last and current contours
		contourObj.getAllSurfProps(tempHeightPropsLast.zDepthTopContactPnts, tempHeightPropsLast.zDepthAvgCoM, true, tempHeightPropsLast.zDepthNormals,
			tempHeightPropsLast.zDepthKappaMax, tempHeightPropsLast.zDepthKappaMaxDirections, tempHeightPropsLast.zDepthKappaMin, tempHeightPropsLast.zDepthKappaMinDirections,
			tempHeightPropsLast.zDepthKappaMean, tempHeightPropsLast.zDepthKappaGaussian);

		contourObj.getAllSurfProps(tempHeightPropsCurrent.zDepthTopContactPnts, tempHeightPropsCurrent.zDepthAvgCoM, true, tempHeightPropsCurrent.zDepthNormals,
			tempHeightPropsCurrent.zDepthKappaMax, tempHeightPropsCurrent.zDepthKappaMaxDirections, tempHeightPropsCurrent.zDepthKappaMin, tempHeightPropsCurrent.zDepthKappaMinDirections,
			tempHeightPropsCurrent.zDepthKappaMean, tempHeightPropsCurrent.zDepthKappaGaussian);

		// Interpolate all of the geometric properties between the contours near the desired spiral point
		tempHeightPropsSaved.interpolateZDepthContactContours(tempHeightPropsSaved.zDepthTopContactPnts, tempHeightPropsLast, tempHeightPropsCurrent, tempHeightPropsSaved);

		// These are copied from regular SPIF::calcSurfInfo(...)
		tempHeightPropsSaved.pushBackZDepthTopContactPnts(false, false);
		tempHeightPropsSaved.pushBackZDepthContactPntsSurfProps(false, 1);
	}
	else
	{
		// Get properties of last and current contours
		contourObj.getAllSurfProps(tempHeightPropsLast.zDepthTopContactPnts, tempHeightPropsLast.zDepthAvgCoM, false, tempHeightPropsLast.zDepthNormals,
			tempHeightPropsLast.zDepthKappaMax, tempHeightPropsLast.zDepthKappaMaxDirections, tempHeightPropsLast.zDepthKappaMin, tempHeightPropsLast.zDepthKappaMinDirections,
			tempHeightPropsLast.zDepthKappaMean, tempHeightPropsLast.zDepthKappaGaussian);

		contourObj.getAllSurfProps(tempHeightPropsCurrent.zDepthTopContactPnts, tempHeightPropsCurrent.zDepthAvgCoM, false, tempHeightPropsCurrent.zDepthNormals,
			tempHeightPropsCurrent.zDepthKappaMax, tempHeightPropsCurrent.zDepthKappaMaxDirections, tempHeightPropsCurrent.zDepthKappaMin, tempHeightPropsCurrent.zDepthKappaMinDirections,
			tempHeightPropsCurrent.zDepthKappaMean, tempHeightPropsCurrent.zDepthKappaGaussian);

		// Interpolate all of the geometric properties between the contours near the desired spiral point
		tempHeightPropsSaved.interpolateZDepthContactContours(tempHeightPropsSaved.zDepthTopContactPnts, tempHeightPropsLast, tempHeightPropsCurrent, tempHeightPropsSaved);

		// These are copied from regular SPIF::calcSurfInfo(...)
		tempHeightPropsSaved.zDepthBotContactPnts = tempHeightPropsSaved.zDepthTopContactPnts;
		tempHeightPropsSaved.pushBackZDepthBotContactPnts(false, true, false);
		tempHeightPropsSaved.pushBackZDepthContactPntsSurfProps(false, -1);
	}

	// Add the current contact points and properties at this Z-depth to the master object 
	tempHeightPropsSaved.pushBackAllContactPntsToOther(masterHeightProps, false);
	if (directionDown)
		tempHeightPropsSaved.pushBackAllSurfPropsToOther(masterHeightProps, 1, false);
	else
		tempHeightPropsSaved.pushBackAllSurfPropsToOther(masterHeightProps, -1, false);
}

void SPIF::getSpiralPoints(const toolpathZHeightProps &tempHeightPropsLast, const toolpathZHeightProps &tempHeightPropsCurrent, const toolpathZHeightProps &masterHeightProps, toolpathZHeightProps &tempHeightPropsSaved)
{
	tempHeightPropsSaved.zDepthTopContactPnts.clear();

	Standard_Real lastIntersectLength = 0.0;
	Standard_Real currentIntersectLength = 0.0;
	std::vector<float> distOfAllLastPnts = { 0.0 };
	std::vector<float> distOfAllCurrentPnts = { 0.0 };
	for (int pntIndex = 1; pntIndex < tempHeightPropsLast.zDepthTopContactPnts.size(); pntIndex++)
	{
		gp_Pnt lastPnt = tempHeightPropsLast.zDepthTopContactPnts.at(pntIndex - 1);
		gp_Pnt currentPnt = tempHeightPropsLast.zDepthTopContactPnts.at(pntIndex);
		float incDist = lastPnt.Distance(currentPnt);
		lastIntersectLength = lastIntersectLength + incDist;
		distOfAllLastPnts.push_back(lastIntersectLength);
	}

	for (int pntIndex = 1; pntIndex < tempHeightPropsCurrent.zDepthTopContactPnts.size(); pntIndex++)
	{
		gp_Pnt lastPnt = tempHeightPropsCurrent.zDepthTopContactPnts.at(pntIndex - 1);
		gp_Pnt currentPnt = tempHeightPropsCurrent.zDepthTopContactPnts.at(pntIndex);
		float incDist = lastPnt.Distance(currentPnt);
		currentIntersectLength = currentIntersectLength + incDist;
		distOfAllCurrentPnts.push_back(currentIntersectLength);
	}

	std::vector<Standard_Real> percentDistArr = { 0.0 };
	Standard_Real spiralDistInc = masterHeightProps.localAmplToolpath.incToolpathCurve;
	Standard_Real spiralPercentInc = spiralDistInc / currentIntersectLength;
	bool keepFindingPercentPnts = true;
	int percentIndex = 0;
	while (keepFindingPercentPnts)
	{
		float lastPercent = percentDistArr.at(percentIndex);
		float nextPercent = lastPercent + spiralPercentInc;

		if (nextPercent < 1.0)
			percentDistArr.push_back(nextPercent);
		else if ((nextPercent >= 1.0) && (lastPercent < 1.0))
		{
			keepFindingPercentPnts = false;
			percentDistArr.push_back(1.0);
		}
		else
			keepFindingPercentPnts = false;

		percentIndex++;
	}

	std::vector<gp_Pnt> spiralFloatingPnts; // Not exactly the contact points, but approximately are
	std::vector<gp_Vec> spiralFloatingNormals;
	float spiralDistance = 0.0;
	for (int percIndex = 1; percIndex < percentDistArr.size(); percIndex++)
	{
		float currentPcnt = percentDistArr.at(percIndex);
		float lastPcnt = percentDistArr.at(percIndex - 1);
		gp_Pnt lastZHeightPnt, currentZheightPnt, lastXYLastZPnt;

		ampl::planeIntersecter::findDiscretePntByWirePercent(currentPcnt, tempHeightPropsLast.zDepthTopContactPnts, lastIntersectLength, distOfAllLastPnts, lastZHeightPnt);
		ampl::planeIntersecter::findDiscretePntByWirePercent(currentPcnt, tempHeightPropsCurrent.zDepthTopContactPnts, currentIntersectLength, distOfAllCurrentPnts, currentZheightPnt);
		ampl::planeIntersecter::findDiscretePntByWirePercent(lastPcnt, tempHeightPropsLast.zDepthTopContactPnts, lastIntersectLength, distOfAllLastPnts, lastXYLastZPnt);

		if (percIndex == 1)
			spiralFloatingPnts.push_back(lastXYLastZPnt);

		gp_Vec zHeightInterpVec(lastZHeightPnt, currentZheightPnt); // Interpolate between the Z-height contours
		zHeightInterpVec.Scale(currentPcnt);
		gp_Pnt spiralInterpPnt(lastZHeightPnt.X() + zHeightInterpVec.X(), lastZHeightPnt.Y() + zHeightInterpVec.Y(), lastZHeightPnt.Z() + zHeightInterpVec.Z());

		if (spiralInterpPnt.Distance(spiralFloatingPnts.at(percIndex - 1)) < 0.002) // Avoid duplicate points, which would mess up the tangent vector construction
		{
			if (percIndex == percentDistArr.size() - 1)
				spiralFloatingNormals.push_back(spiralFloatingNormals.back()); // Assume the last normal is approximately equal to the second to last normal
			continue;
		}

		spiralFloatingPnts.push_back(spiralInterpPnt);
		float floatPntDistInc = (spiralFloatingPnts.at(percIndex - 1)).Distance(spiralInterpPnt); // Update spiral toolpath length
		spiralDistance = spiralDistance + floatPntDistInc;

		gp_Vec localTangent(spiralFloatingPnts.at(percIndex - 1), spiralInterpPnt); // Approximate the tangent by looking at the previous point 
		gp_Vec localNormal = localTangent.Crossed(zHeightInterpVec);
		localNormal.Scale(1.0 / localNormal.Magnitude());
		spiralFloatingNormals.push_back(localNormal);

		if (percIndex == percentDistArr.size() - 1)
			spiralFloatingNormals.push_back(spiralFloatingNormals.back()); // Assume the last normal is approximately equal to the second to last normal
	}
	tempHeightPropsSaved.zDepthTotalIntersectLength = spiralDistance;

	if (masterHeightProps.localAmplToolpath.removedCollinearContactPoints)
	{
		std::vector<int> indicesKept;
		removeCollinearPnts(0.001, spiralFloatingPnts, indicesKept);

		std::vector<gp_Vec> normalsTempVec;
		for (int i = 0; i < indicesKept.size(); i++)
		{
			int currentIndex = indicesKept.at(i);
			normalsTempVec.push_back(spiralFloatingNormals.at(currentIndex));
		}
		spiralFloatingNormals.clear();
		spiralFloatingNormals = normalsTempVec;
	}

	if (masterHeightProps.localAmplToolpath.useFastSpiralApprox)
	{
		tempHeightPropsSaved.zDepthTopContactPnts = spiralFloatingPnts; 

		// Old versions used this algorithm to try to project the spiral points onto the surface: not reliable
		//ampl::planeIntersecter::getAllProjectedPntsOnSurfAlongVec(*myCurrentPart, spiralFloatingPnts, tempHeightPropsSaved.zDepthTopContactPnts);
	}
	else
		ampl::planeIntersecter::getAllIntersectPntsOnSurfAlongVec(*myCurrentPart, spiralFloatingPnts, spiralFloatingNormals, tempHeightPropsSaved.zDepthTopContactPnts);
}

bool SPIF::correctSphericalInterference(bool topTool, const std::vector<gp_Pnt> &toolCenterPntsIn, const std::vector<gp_Pnt> &toolTipPntsIn, const std::vector<gp_Pnt> &contactPntsIn, const std::vector<gp_Vec> &contactPntNormals,
	float sphereRad, float tol, std::vector<gp_Pnt> &toolTipsModOut, std::vector<gp_Pnt> &toolCentersModOut, float &maxInterferenceOut)
{
	toolTipsModOut.clear();
	toolCentersModOut.clear();
	maxInterferenceOut = 0.0;

	bool foundInterference = false;
	std::vector<gp_Pnt> localTipPntsMod;
	std::vector<int> localTipPntsModIndices;
	std::vector<gp_Pnt> localToolCentersMod;
	std::vector<float> localInterferences;
	for (int m = 0; m < toolCenterPntsIn.size(); m++)
	{
		gp_Pnt curToolCenterPnt = toolCenterPntsIn.at(m);
		gp_Pnt curToolTipPnt = toolTipPntsIn.at(m);

		float maxInterference = 0.0;
		int maxInterferenceIndex;
		bool foundCurrentInterference = false;
		gp_Pnt interferenceContactPnt;
		gp_Dir interferencePntDir;
		for (int n = 0; n < contactPntsIn.size(); n++)
		{
			gp_Pnt curContactPnt = contactPntsIn.at(n);
			float curDist = curToolCenterPnt.Distance(curContactPnt);
			if (curDist < (sphereRad - tol))
			{
				float curInterference = abs((sphereRad - tol) - curDist);
				foundCurrentInterference = true;
				foundInterference = true;
				if (curInterference > maxInterference)
				{
					maxInterference = curInterference;
					maxInterferenceIndex = n;
					interferenceContactPnt = curContactPnt;

					gp_Dir contactToCenterDir(curToolCenterPnt.X() - curContactPnt.X(), curToolCenterPnt.Y() - curContactPnt.Y(), curToolCenterPnt.Z() - curContactPnt.Z());
					gp_Dir currentNormalDir = gp_Dir(contactPntNormals.at(n));
					float relAngleDir = contactToCenterDir.Angle(currentNormalDir);
					if (relAngleDir < 3.14159265358979323846 / 2.0)
					{
						interferencePntDir = currentNormalDir;
					}
					else
					{
						currentNormalDir.Reverse();
						interferencePntDir = currentNormalDir;
					}

					if (abs(interferencePntDir.Z()) > 0.0002 && topTool)
					{
						if (interferencePntDir.Z() < 0.0)
							interferencePntDir.Reverse();
					}
					else if (abs(interferencePntDir.Z()) > 0.0002 && !topTool)
					{
						if (interferencePntDir.Z() > 0.0)
							interferencePntDir.Reverse();
					}
				}
			}
		}
		localInterferences.push_back(maxInterference);

		int interferenceCount = 0;
		while (foundCurrentInterference)
		{
			foundCurrentInterference = false;

			if (interferenceCount >= 10)
				break;

			gp_Vec curTranslationVec(interferencePntDir);
			curTranslationVec.Scale(maxInterference);

			curToolCenterPnt.Translate(curTranslationVec);
			curToolTipPnt.Translate(curTranslationVec);

			maxInterference = 0.0; // Recheck for interference and update again if necessary
			//maxInterferenceIndex;
			foundCurrentInterference = false;
			//interferenceContactPnt;
			//interferencePntDir;
			for (int n = 0; n < contactPntsIn.size(); n++)
			{
				gp_Pnt curContactPnt = contactPntsIn.at(n);
				float curDist = curToolCenterPnt.Distance(curContactPnt);
				if (curDist < (sphereRad - tol))
				{
					float curInterference = abs((sphereRad - tol) - curDist);
					foundCurrentInterference = true;
					if (curInterference > maxInterference)
					{
						maxInterference = curInterference;
						maxInterferenceIndex = n;
						interferenceContactPnt = curContactPnt;

						gp_Dir contactToCenterDir(curToolCenterPnt.X() - curContactPnt.X(), curToolCenterPnt.Y() - curContactPnt.Y(), curToolCenterPnt.Z() - curContactPnt.Z());
						gp_Dir currentNormalDir = gp_Dir(contactPntNormals.at(n));
						float relAngleDir = contactToCenterDir.Angle(currentNormalDir);
						if (relAngleDir < 3.14159265358979323846 / 2.0)
						{
							interferencePntDir = currentNormalDir;
						}
						else
						{
							currentNormalDir.Reverse();
							interferencePntDir = currentNormalDir;
						}

						if (abs(interferencePntDir.Z()) > 0.0002 && topTool)
						{
							if (interferencePntDir.Z() < 0.0)
								interferencePntDir.Reverse();
						}
						else if (abs(interferencePntDir.Z()) > 0.0002 && !topTool)
						{
							if (interferencePntDir.Z() > 0.0)
								interferencePntDir.Reverse();
						}
					}
				}
			}

			interferenceCount++;
		}

		if (interferenceCount > 0)
		{
			localTipPntsMod.push_back(curToolTipPnt);
			localTipPntsModIndices.push_back(m);
			localToolCentersMod.push_back(curToolCenterPnt);
		}
	}

	if (foundInterference)
	{
		toolTipsModOut = toolTipPntsIn;
		toolCentersModOut = toolCenterPntsIn;
		int modPntCounter = 0;
		for (int modIndex : localTipPntsModIndices)
		{
			toolTipsModOut.at(modIndex) = localTipPntsMod.at(modPntCounter);
			toolCentersModOut.at(modIndex) = localToolCentersMod.at(modPntCounter);
			modPntCounter++;
		}

		 std::vector<float>::iterator maxInterferenceIter = std::max_element(localInterferences.begin(), localInterferences.end());
		 maxInterferenceOut = *maxInterferenceIter;
	}

	return foundInterference;
}

bool SPIF::correctFlatTopInterference(bool topTool, const std::vector<gp_Pnt> &toolCenterPntsIn, const std::vector<gp_Pnt> &toolCornerCenterPntsIn, const std::vector<gp_Pnt> &toolTipPntsIn, const std::vector<gp_Pnt> &contactPntsIn,
	const std::vector<gp_Vec> &contactPntNormals, float toolRad, float cornerRad, float tol, std::vector<gp_Pnt> &toolTipsModOut, std::vector<gp_Pnt> &toolCentersModOut, std::vector<gp_Pnt> &toolCornerCentersModOut, float &maxInterferenceOut)
{
	toolTipsModOut.clear();
	toolCentersModOut.clear();
	toolCornerCentersModOut.clear();
	maxInterferenceOut = 0.0;

	bool foundInterference = false;
	std::vector<gp_Pnt> localTipPntsMod;
	std::vector<int> localTipPntsModIndices;
	std::vector<gp_Pnt> localToolCentersMod;
	std::vector<gp_Pnt> localCornerCentersMod;
	std::vector<float> localInterferences;
	for (int m = 0; m < toolCenterPntsIn.size(); m++)
	{
		gp_Pnt curToolCenterPnt = toolCenterPntsIn.at(m);
		gp_Pnt curCornerCenterPnt = toolCornerCenterPntsIn.at(m);
		float torusRad = abs(toolRad - cornerRad);
		float toolCentX = curToolCenterPnt.X();
		float toolCentY = curToolCenterPnt.Y();
		float toolCentZ = curToolCenterPnt.Z();
		gp_Pnt curToolTipPnt = toolTipPntsIn.at(m);

		float maxInterference = 0.0;
		int maxInterferenceIndex;
		bool foundCurrentInterference = false;
		gp_Pnt interferenceContactPnt;
		gp_Dir interferencePntDir;
		for (int n = 0; n < contactPntsIn.size(); n++)
		{
			gp_Pnt curContactPnt = contactPntsIn.at(n);
			float torusLeftTemp = pow(torusRad - sqrt(pow(curContactPnt.X() - toolCentX, 2) + pow(curContactPnt.Y() - toolCentY, 2)), 2) + pow(curContactPnt.Z() - toolCentZ, 2);
			float torusRightTemp = pow(cornerRad - tol, 2);
			float cylindLeftTemp = pow(curContactPnt.X() - toolCentX, 2) + pow(curContactPnt.Y() - toolCentY, 2);

			if ((curContactPnt.Z() < toolCentZ + (cornerRad - tol)) && (curContactPnt.Z() > toolCentZ - (cornerRad - tol)) && (cylindLeftTemp < pow(torusRad, 2)))
			{ // curContactPnt is inside the cylinder within the torus, interference found
				float curInterference, distToCylPlane, circInterference;
				if (abs(curContactPnt.Z() - (toolCentZ + (cornerRad - tol))) < abs(curContactPnt.Z() - (toolCentZ - (cornerRad - tol))))
					distToCylPlane = abs(curContactPnt.Z() - (toolCentZ + (cornerRad - tol)));
				else
					distToCylPlane = abs(curContactPnt.Z() - (toolCentZ - (cornerRad - tol)));

				circInterference = abs(sqrt(cylindLeftTemp) - torusRad);
				//curInterference = sqrt(circInterference*circInterference + distToCylPlane*distToCylPlane);
				curInterference = circInterference;

				foundCurrentInterference = true;
				foundInterference = true;
				if (curInterference > maxInterference)
				{
					maxInterference = curInterference;
					maxInterferenceIndex = n;
					interferenceContactPnt = curContactPnt;

					gp_Dir contactToCenterDir(curToolCenterPnt.X() - curContactPnt.X(), curToolCenterPnt.Y() - curContactPnt.Y(), curToolCenterPnt.Z() - curContactPnt.Z());
					gp_Dir currentNormalDir = gp_Dir(contactPntNormals.at(n));
					float relAngleDir = contactToCenterDir.Angle(currentNormalDir);
					if (relAngleDir < 3.14159265358979323846 / 2.0)
					{
						interferencePntDir = currentNormalDir;
					}
					else
					{
						currentNormalDir.Reverse();
						interferencePntDir = currentNormalDir;
					}

					if (abs(interferencePntDir.Z()) > 0.0002 && topTool)
					{
						if (interferencePntDir.Z() < 0.0)
							interferencePntDir.Reverse();
					}
					else if (abs(interferencePntDir.Z()) > 0.0002 && !topTool)
					{
						if (interferencePntDir.Z() > 0.0)
							interferencePntDir.Reverse();
					}
				}
			}
			else if (torusLeftTemp < torusRightTemp) 
			{ // curContactPnt is inside the torus, interference found
				float curInterference = abs(sqrt(torusLeftTemp) - (cornerRad - tol));

				foundCurrentInterference = true;
				foundInterference = true;
				if (curInterference > maxInterference)
				{
					maxInterference = curInterference;
					maxInterferenceIndex = n;
					interferenceContactPnt = curContactPnt;

					gp_Dir contactToCenterDir(curCornerCenterPnt.X() - curContactPnt.X(), curCornerCenterPnt.Y() - curContactPnt.Y(), curCornerCenterPnt.Z() - curContactPnt.Z());
					gp_Dir currentNormalDir = gp_Dir(contactPntNormals.at(n));
					float relAngleDir = contactToCenterDir.Angle(currentNormalDir);
					if (relAngleDir < 3.14159265358979323846 / 2.0)
					{
						interferencePntDir = currentNormalDir;
					}
					else
					{
						currentNormalDir.Reverse();
						interferencePntDir = currentNormalDir;
					}

					if (abs(interferencePntDir.Z()) > 0.0002 && topTool)
					{
						if (interferencePntDir.Z() < 0.0)
							interferencePntDir.Reverse();
					}
					else if (abs(interferencePntDir.Z()) > 0.0002 && !topTool)
					{
						if (interferencePntDir.Z() > 0.0)
							interferencePntDir.Reverse();
					}
				}
			}
		}
		localInterferences.push_back(maxInterference);

		int interferenceCount = 0;
		while (foundCurrentInterference)
		{
			foundCurrentInterference = false;

			if (interferenceCount >= 10)
				break;

			gp_Vec curTranslationVec(interferencePntDir);
			curTranslationVec.Scale(maxInterference);

			curToolCenterPnt.Translate(curTranslationVec);
			curToolTipPnt.Translate(curTranslationVec);
			curCornerCenterPnt.Translate(curTranslationVec);
			toolCentX = curToolCenterPnt.X();
			toolCentY = curToolCenterPnt.Y();
			toolCentZ = curToolCenterPnt.Z();

			maxInterference = 0.0; // Recheck for interference and update again if necessary
			//maxInterferenceIndex;
			foundCurrentInterference = false;
			//interferenceContactPnt;
			//interferencePntDir;
			for (int n = 0; n < contactPntsIn.size(); n++)
			{
				gp_Pnt curContactPnt = contactPntsIn.at(n);
				float torusLeftTemp = pow(torusRad - sqrt(pow(curContactPnt.X() - toolCentX, 2) + pow(curContactPnt.Y() - toolCentY, 2)), 2) + pow(curContactPnt.Z() - toolCentZ, 2);
				float torusRightTemp = pow(cornerRad - tol, 2);
				float cylindLeftTemp = pow(curContactPnt.X() - toolCentX, 2) + pow(curContactPnt.Y() - toolCentY, 2);

				if ((curContactPnt.Z() < toolCentZ + (cornerRad - tol)) && (curContactPnt.Z() > toolCentZ - (cornerRad - tol)) && (cylindLeftTemp < pow(torusRad, 2)))
				{ // curContactPnt is inside the cylinder within the torus, interference found
					float curInterference, distToCylPlane, circInterference;
					if (abs(curContactPnt.Z() - (toolCentZ + (cornerRad - tol))) < abs(curContactPnt.Z() - (toolCentZ - (cornerRad - tol))))
						distToCylPlane = abs(curContactPnt.Z() - (toolCentZ + (cornerRad - tol)));
					else
						distToCylPlane = abs(curContactPnt.Z() - (toolCentZ - (cornerRad - tol)));

					circInterference = abs(sqrt(cylindLeftTemp) - torusRad);
					//curInterference = sqrt(circInterference*circInterference + distToCylPlane*distToCylPlane);
					curInterference = circInterference;

					foundCurrentInterference = true;
					//foundInterference = true;
					if (curInterference > maxInterference)
					{
						maxInterference = curInterference;
						maxInterferenceIndex = n;
						interferenceContactPnt = curContactPnt;

						gp_Dir contactToCenterDir(curToolCenterPnt.X() - curContactPnt.X(), curToolCenterPnt.Y() - curContactPnt.Y(), curToolCenterPnt.Z() - curContactPnt.Z());
						gp_Dir currentNormalDir = gp_Dir(contactPntNormals.at(n));
						float relAngleDir = contactToCenterDir.Angle(currentNormalDir);
						if (relAngleDir < 3.14159265358979323846 / 2.0)
						{
							interferencePntDir = currentNormalDir;
						}
						else
						{
							currentNormalDir.Reverse();
							interferencePntDir = currentNormalDir;
						}

						if (abs(interferencePntDir.Z()) > 0.0002 && topTool)
						{
							if (interferencePntDir.Z() < 0.0)
								interferencePntDir.Reverse();
						}
						else if (abs(interferencePntDir.Z()) > 0.0002 && !topTool)
						{
							if (interferencePntDir.Z() > 0.0)
								interferencePntDir.Reverse();
						}
					}
				}
				else if (torusLeftTemp < torusRightTemp)
				{ // curContactPnt is inside the torus, interference found
					float curInterference = abs(sqrt(torusLeftTemp) - (cornerRad - tol));

					foundCurrentInterference = true;
					//foundInterference = true;
					if (curInterference > maxInterference)
					{
						maxInterference = curInterference;
						maxInterferenceIndex = n;
						interferenceContactPnt = curContactPnt;

						gp_Dir contactToCenterDir(curCornerCenterPnt.X() - curContactPnt.X(), curCornerCenterPnt.Y() - curContactPnt.Y(), curCornerCenterPnt.Z() - curContactPnt.Z());
						gp_Dir currentNormalDir = gp_Dir(contactPntNormals.at(n));
						float relAngleDir = contactToCenterDir.Angle(currentNormalDir);
						if (relAngleDir < 3.14159265358979323846 / 2.0)
						{
							interferencePntDir = currentNormalDir;
						}
						else
						{
							currentNormalDir.Reverse();
							interferencePntDir = currentNormalDir;
						}

						if (abs(interferencePntDir.Z()) > 0.0002 && topTool)
						{
							if (interferencePntDir.Z() < 0.0)
								interferencePntDir.Reverse();
						}
						else if (abs(interferencePntDir.Z()) > 0.0002 && !topTool)
						{
							if (interferencePntDir.Z() > 0.0)
								interferencePntDir.Reverse();
						}
					}
				}
			}

			interferenceCount++;
		}

		if (interferenceCount > 0)
		{
			localTipPntsMod.push_back(curToolTipPnt);
			localTipPntsModIndices.push_back(m);
			localToolCentersMod.push_back(curToolCenterPnt);
			localCornerCentersMod.push_back(curCornerCenterPnt);
		}
	}

	if (foundInterference)
	{
		toolTipsModOut = toolTipPntsIn; 
		toolCentersModOut = toolCenterPntsIn;
		toolCornerCentersModOut = toolCornerCenterPntsIn;
		int modPntCounter = 0;
		for (int modIndex : localTipPntsModIndices)
		{
			toolTipsModOut.at(modIndex) = localTipPntsMod.at(modPntCounter);
			toolCentersModOut.at(modIndex) = localToolCentersMod.at(modPntCounter);
			toolCornerCentersModOut.at(modIndex) = localCornerCentersMod.at(modPntCounter);

			modPntCounter++;
		}

		std::vector<float>::iterator maxInterferenceIter = std::max_element(localInterferences.begin(), localInterferences.end());
		maxInterferenceOut = *maxInterferenceIter;
	}

	return foundInterference;
}

void SPIF::findLocalTangentDirection(const gp_Pnt &curContactPnt, int curContactPntIndex, const std::vector<gp_Pnt> &contactPnts, const std::vector<gp_Vec> &contactPntNormals, bool reverseNormal, bool goingCCW, gp_Dir &tangentDirOut)
{
	gp_Dir localTanDir;
	if (sqrt(pow(contactPntNormals.at(curContactPntIndex).X(), 2) + pow(contactPntNormals.at(curContactPntIndex).Y(), 2)) >= 0.000175) // More than 0.01deg wall angle
	{
		gp_Vec localNormalVec = contactPntNormals.at(curContactPntIndex);

		if (reverseNormal)
			localNormalVec.Reverse();

		gp_Vec localXYVec(localNormalVec.X(), localNormalVec.Y(), 0.0);
		localTanDir = gp_Dir(localXYVec);
		tangentDirOut = localTanDir;
		return;
	}
	else
	{
		gp_Dir toolDir;
		if (curContactPntIndex == 0)
		{
			gp_Pnt lastPnt = contactPnts.at(0);
			gp_Pnt nextPnt = contactPnts.at(2);
			if (lastPnt.Distance(nextPnt) < 0.005)
				nextPnt = contactPnts.at(3);

			toolDir = gp_Dir(nextPnt.X() - lastPnt.X(), nextPnt.Y() - lastPnt.Y(), nextPnt.Z() - lastPnt.Z());
		}
		else if (curContactPntIndex == contactPnts.size() - 1)
		{
			gp_Pnt lastPnt = contactPnts.at(curContactPntIndex - 2);
			gp_Pnt nextPnt = contactPnts.at(curContactPntIndex);
			if (lastPnt.Distance(nextPnt) < 0.005)
				lastPnt = contactPnts.at(curContactPntIndex - 3);

			toolDir = gp_Dir(nextPnt.X() - lastPnt.X(), nextPnt.Y() - lastPnt.Y(), nextPnt.Z() - lastPnt.Z());
		}
		else
		{
			gp_Pnt lastPnt = contactPnts.at(curContactPntIndex - 1);
			gp_Pnt nextPnt = contactPnts.at(curContactPntIndex + 1);

			if (lastPnt.Distance(nextPnt) < 0.005)
			{
				lastPnt = contactPnts.at(curContactPntIndex - 2);
				nextPnt = contactPnts.at(curContactPntIndex + 2);
			}

			toolDir = gp_Dir(nextPnt.X() - lastPnt.X(), nextPnt.Y() - lastPnt.Y(), nextPnt.Z() - lastPnt.Z());
		}

		gp_Vec localNormalVec = contactPntNormals.at(curContactPntIndex);
		if (reverseNormal)
			localNormalVec.Reverse();

		gp_Dir approxTang;
		if (goingCCW)
		{
			float u1 = localNormalVec.X(); float u2 = localNormalVec.Y(); float u3 = localNormalVec.Z();
			float v1 = toolDir.X(); float v2 = toolDir.Y(); float v3 = toolDir.Z();
			float tempXComponent = u2*v3 - u3*v2;
			float tempYComponent = u3*v1 - u1*v3;
			float tempZComponent = u1*v2 - u2*v1;
			approxTang = gp_Dir(tempXComponent, tempYComponent, tempZComponent);
		}
		else
		{
			float u1 = toolDir.X(); float u2 = toolDir.Y(); float u3 = toolDir.Z();
			float v1 = localNormalVec.X(); float v2 = localNormalVec.Y(); float v3 = localNormalVec.Z();
			float tempXComponent = u2*v3 - u3*v2;
			float tempYComponent = u3*v1 - u1*v3;
			float tempZComponent = u1*v2 - u2*v1;
			approxTang = gp_Dir(tempXComponent, tempYComponent, tempZComponent);
		}

		localTanDir = gp_Dir(approxTang.X(), approxTang.Y(), 0.0);
		tangentDirOut = localTanDir;
		return;
	}
	/*
	std::vector< std::pair<float, int> > contactPntDistances;
	for (int m = 0; m < contactPnts.size(); m++)
	{
		gp_Pnt curPntLocal = contactPnts.at(m);
		float curPntDistLocal = curPntLocal.Distance(curContactPnt);
		std::pair<float, int> localDistPair = std::make_pair(curPntDistLocal, m);
		contactPntDistances.push_back(localDistPair);
	}
	std::sort(contactPntDistances.begin(), contactPntDistances.end(), SPIF::distPairCompare); // Sort distances into ascending order, while preserving their original indices using std::pair<>

	float neighborhoodDist;
	if (contactPntDistances.size() >= 3) // Don't use first element, since that should be the same contact point
		neighborhoodDist = ((contactPntDistances.at(1)).first + (contactPntDistances.at(2)).first) / 2.0;
	else
		neighborhoodDist = (contactPntDistances.at(1)).first;

	bool keepSearching = true;
	int pntIndex = 0;
	while (keepSearching)
	{
		if (pntIndex >= contactPnts.size())
			break;

		std::pair<float, int> localDistPair = contactPntDistances.at(pntIndex);
		if (curContactPntIndex == localDistPair.second)
		{
			pntIndex++; // same contact point, keep searching
			continue;
		}
		else if (localDistPair.first > 3.0*neighborhoodDist)
			break; // No longer in the neighborhood of the contact point, search failed

		gp_Vec localNormalVec = contactPntNormals.at(localDistPair.second);

		if (reverseNormal)
			localNormalVec.Reverse();

		if (sqrt(pow(localNormalVec.X(), 2) + pow(localNormalVec.Y(), 2)) >= 0.00175) // More than 0.1deg wall angle
		{
			gp_Vec localXYVec(localNormalVec.X(), localNormalVec.Y(), 0.0);
			localTanDir = gp_Dir(localXYVec);
			tangentDirOut = localTanDir;
			keepSearching = false;
		}

		pntIndex++;
	}
	*/
}

bool SPIF::distPairCompare(const std::pair<float, int> &firstElem, const std::pair<float, int> &secondElem)
{
	return firstElem.first < secondElem.first;
}

void SPIF::removeInitialPnts(const int numPntsToSkip, std::vector<gp_Pnt> &modifiedPntsInOut)
{
	if (numPntsToSkip <= 0)
		return;
	else if (numPntsToSkip >= modifiedPntsInOut.size())
		return;

	std::vector<gp_Pnt> pntsIn = modifiedPntsInOut;
	modifiedPntsInOut.clear();

	int sizePntsIn = pntsIn.size();
	std::vector<gp_Pnt>::const_iterator firstIter = pntsIn.begin() + numPntsToSkip;
	std::vector<gp_Pnt>::const_iterator lastIter = pntsIn.end();

	modifiedPntsInOut.assign(firstIter, lastIter);
}

void SPIF::correctConstZHeightTips(bool isTopTool, const toolpathZHeightProps &masterHeightProps, float sphereRad, const std::vector<gp_Pnt> &contactPnts, const std::vector<gp_Pnt> &toolCenterPnts,
	const std::vector<gp_Vec> normalVecs, std::vector<gp_Pnt> &toolTipPnts)
{
	bool directionDown = true;
	if (masterHeightProps.localAmplToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::posZDir)
		directionDown = false;

	std::vector<int> contourIndices = masterHeightProps.allContourIndices;
	int numContours = contourIndices.size();

	// Loop through the contours
	int contourCounter;
	int absPntIndex = 0;
	int lastRevEndIndex = -1;
	int curRevEndIndex = 0;
	for (contourCounter = 0; contourCounter < numContours; ++contourCounter)
	{
		std::vector<gp_Pnt> localContactPnts, localToolCenterPnts, localToolTipPnts;
		std::vector<gp_Vec> localNormalVecs, localNormalXYVecs; // Will be [0, 0, 0.001] if N_xy component is zero
		std::vector<float> localWallAngles; // In Radians
		curRevEndIndex = contourIndices.at(contourCounter);

		// Collect current contour points, vectors, angles, etc.
		for (absPntIndex = lastRevEndIndex + 1; absPntIndex <= curRevEndIndex; ++absPntIndex)
		{
			localContactPnts.push_back(contactPnts.at(absPntIndex));
			localToolCenterPnts.push_back(toolCenterPnts.at(absPntIndex));
			localNormalVecs.push_back(normalVecs.at(absPntIndex));
			localToolTipPnts.push_back(toolTipPnts.at(absPntIndex));

			gp_Vec tempCurNormalVec = localNormalVecs.back();
			if (abs(tempCurNormalVec.X()) <= 0.001 && abs(tempCurNormalVec.Y()) <= 0.001)
			{
				gp_Dir tempXYNormalDir(0.0, 0.0, 0.001);
				gp_Vec tempXYNormalVec(tempXYNormalDir);
				localNormalXYVecs.push_back(tempXYNormalVec);
			}
			else
			{
				gp_Dir tempXYNormalDir(tempCurNormalVec.X(), tempCurNormalVec.Y(), 0.0);
				gp_Vec tempXYNormalVec(tempXYNormalDir);
				localNormalXYVecs.push_back(tempXYNormalVec);
			}

			float tempWallAngle;
			tempWallAngle = calcWallAngle(tempCurNormalVec);
			localWallAngles.push_back(tempWallAngle);
		}
		
		// Find limiting (max & min) wall angle for current contour
		auto minMaxResult = std::minmax_element(localWallAngles.begin(), localWallAngles.end());

		float minWallAngle = *minMaxResult.first;
		int minAngleIndex = minMaxResult.first - localWallAngles.begin();

		float maxWallAngle = *minMaxResult.second;
		int maxAngleIndex = minMaxResult.second - localWallAngles.begin();

		float toolLimitAngle;
		if (isTopTool) // If using top tool, move tool upward
			toolLimitAngle = minWallAngle;
		else  // If using bottom tool, move tool downward 
			toolLimitAngle = minWallAngle;

		// Calculate tool tip positions at each contact point using the limiting wall angle
		std::vector<gp_Pnt> localLimitToolCenterPnts, localLimitToolTipPnts;
		for (int m = 0; m < localContactPnts.size(); m++)
		{
			gp_Pnt curPnt = localContactPnts.at(m);
			gp_Vec curNorm = localNormalVecs.at(m);
			gp_Vec curNormXY = localNormalXYVecs.at(m);

			gp_Vec translationVec1;
			if (directionDown) // Ensure the "new" local normal is in the same direction as the real local normal
				translationVec1 = calcLocalNormal(toolLimitAngle, curNormXY, false, true); // SPIF assumes pos-Z normal for direction down
			else
				translationVec1 = calcLocalNormal(toolLimitAngle, curNormXY, false, false); // SPIF assumes neg-z normal for direction up

			translationVec1.Scale(sphereRad);
			//float testWallAngle = calcWallAngle(translationVec1);

			gp_Vec translateZVec;
			if (directionDown)
				translateZVec = gp_Vec(0.0, 0.0, -sphereRad);
			else
				translateZVec = gp_Vec(0.0, 0.0, sphereRad);

			curPnt.Translate(translationVec1);
			localLimitToolCenterPnts.push_back(curPnt);

			curPnt.Translate(translateZVec);
			localLimitToolTipPnts.push_back(curPnt);
		}

		// Based on direction and top/bottom tool, "slide" tool tips to be at constant height
		std::vector<gp_Pnt> toolTipPntsOut;
		for (int m = 0; m < localContactPnts.size(); m++)
		{
			gp_Pnt curRealTipPnt = localToolTipPnts.at(m);
			gp_Pnt curLimitTipPnt = localLimitToolTipPnts.at(m);
			gp_Vec curNormXY = localNormalXYVecs.at(m);
			float curWallAngle = localWallAngles.at(m);

			float zTransMag = abs(curLimitTipPnt.Z() - curRealTipPnt.Z());

			gp_Vec xyzTransVec;
			bool changeToolTip = true;
			if ( (curWallAngle <= 0.00872665) || (abs(curNormXY.X()) <= 0.001 && abs(curNormXY.Y()) <= 0.001) ) // Implying wall angle is nearly zero here
			{
				if(isTopTool)
					xyzTransVec = gp_Vec(0.0, 0.0, zTransMag);
				else
					xyzTransVec = gp_Vec(0.0, 0.0, -zTransMag);
			}
			else if (zTransMag <= 0.002) // No need to do anything if only 2 micron translation exists
			{
				changeToolTip = false;
			}
			else // Find radial component of translation
			{
				float xyTransMag = abs(zTransMag / tan(curWallAngle));
				if (isTopTool)
				{
					gp_Dir xyTransDir(-curNormXY.X(), -curNormXY.Y(), 0.0);
					gp_Vec xyTransVec(xyTransDir);
					xyTransVec.Scale(xyTransMag);

					xyzTransVec = gp_Vec(xyTransVec.X(), xyTransVec.Y(), zTransMag);
				}
				else
				{
					gp_Dir xyTransDir(-curNormXY.X(), -curNormXY.Y(), 0.0);
					gp_Vec xyTransVec(xyTransDir);
					xyTransVec.Scale(xyTransMag);

					xyzTransVec = gp_Vec(xyTransVec.X(), xyTransVec.Y(), -zTransMag);
				}
			}

			gp_Pnt transToolTip = curRealTipPnt;
			if (changeToolTip)
				transToolTip.Translate(xyzTransVec);

			toolTipPntsOut.push_back(transToolTip);
		}

		// For contour, can go one step further and force all tip Z-heights to be equal (which may not be the case due to unequal contact points Z-heights)
		if (masterHeightProps.localAmplToolpath.mytoolpathMethodType == amplToolpath::toolpathMethodType::contour)
		{
			float minZ = 1000000.0; float maxZ = -1000000.0;
			int minZInd = 0; int maxZInd = 0;
			for (int m = 0; m < toolTipPntsOut.size(); ++m) // Find min and max Z-heights of current tool tip points
			{
				float curZ = (toolTipPntsOut.at(m)).Z();

				if (curZ < minZ)
				{
					minZ = curZ;
					minZInd = m;
				}
				if(curZ > maxZ)
				{
					maxZ = curZ;
					maxZInd = m;
				}
			}

			float limitZ;
			if (isTopTool)
				limitZ = (3.0*maxZ + minZ)/4.0;
			else
				limitZ = (3.0*minZ + maxZ)/4.0;

			for (int m = 0; m < toolTipPntsOut.size(); ++m) // Set all Z-heights to limitZ
			{
				(toolTipPntsOut.at(m)).SetZ(limitZ);
			}
		}

		// Load toolTipPntsOut back into the input/output toolTip vector
		int localPntIndex = 0;
		for (absPntIndex = lastRevEndIndex + 1; absPntIndex <= curRevEndIndex; ++absPntIndex)
		{
			toolTipPnts.at(absPntIndex) = toolTipPntsOut.at(localPntIndex);
			localPntIndex++;
		}

		lastRevEndIndex = curRevEndIndex; // Done with current contour, move on to the next one
	}
}

// Calculates wall angle in Radians
float SPIF::calcWallAngle(const gp_Vec &localNormalVec)
{
	float wallAngle; // RADIANS
	if (abs(localNormalVec.X()) <= 0.001 && abs(localNormalVec.Y()) <= 0.001)
	{
		wallAngle = 0.0;;
	}
	else
	{
		gp_Dir localXYNormalDir(localNormalVec.X(), localNormalVec.Y(), 0.0);
		gp_Vec localXYNormalVec(localXYNormalDir);
		wallAngle = (3.14159265358979323846 / 2.0) - localNormalVec.Angle(localXYNormalVec); // localNormalVec.Angle(gp_Vec other) Returns the angle value between 0 and PI in radian
		
		if (wallAngle > 3.14159265358979323846 / 2.0) // This is bad... shouldn't happen
			wallAngle = 3.14159265358979323846 / 2.0;
	}

	return wallAngle;
}

gp_Vec SPIF::calcLocalNormal(float wallAngle, const gp_Vec &localNormalXY, bool useReverseNormalXY, bool usePosZDirection)
{
	gp_Vec localNormalOut;
	gp_Vec tempNormalXY = localNormalXY;

	if (useReverseNormalXY)
		tempNormalXY.Reverse();

	if (wallAngle <= 0.00872665) // 0.5 deg
	{
		gp_Dir tempLocalDir(0.0, 0.0, 1.0);
		if (!usePosZDirection)
			tempLocalDir.Reverse();

		localNormalOut = gp_Vec(tempLocalDir);
		return localNormalOut;
	}
	else if (wallAngle >= 1.56207) // 89.5 deg
	{
		gp_Dir tempLocalDir(tempNormalXY.X(), tempNormalXY.Y(), 0.0);

		localNormalOut = gp_Vec(tempLocalDir);
		return localNormalOut;
	}

	float NxyMag = sqrt(tempNormalXY.X()*tempNormalXY.X() + tempNormalXY.Y()*tempNormalXY.Y());
	float zTemp = NxyMag*tan((3.14159265358979323846 / 2.0) - wallAngle); // Will be positive between 0 and 90 deg
	gp_Dir tempLocalDir; 

	if (usePosZDirection)
		tempLocalDir = gp_Dir(tempNormalXY.X(), tempNormalXY.Y(), zTemp);
	else
		tempLocalDir = gp_Dir(tempNormalXY.X(), tempNormalXY.Y(), -zTemp);

	localNormalOut = gp_Vec(tempLocalDir);
	return localNormalOut;
}