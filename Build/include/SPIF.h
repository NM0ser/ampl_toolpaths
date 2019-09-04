#pragma once

#include "stdafx.h"
#include "amplToolpath.h"
#include "amplWireIntersection.h"
#include "planeIntersecter.h"
#include "toolpathZHeightProps.h"

class SPIF
{
public:
	SPIF::SPIF();

	bool initContactPnts(amplToolpath &myCurrentToolpathIn, TopoDS_Compound &myCurrentTopContactPntsIn,
		TopoDS_Compound &myCurrentBotContactPntsIn, Handle(AIS_Shape) &myAisTopContactPntsIn, Handle(AIS_Shape) &myAisBotContactPntsIn, TopoDS_Compound &myCurrentPartIn,
		Handle(V3d_Viewer) &myViewerIn, Handle(V3d_View) &myViewIn, Handle(AIS_InteractiveContext) &myContextIn, Handle(AIS_Shape) &myAisShapeIn, QTextEdit *textEditIn, QEventLoop &myEventLoopIn);

	bool initToolTipPnts(amplToolpath &myCurrentToolpathIn, TopoDS_Compound &myCurrentTopToolTipsIn,
		TopoDS_Compound &myCurrentBotToolTipsIn, Handle(AIS_Shape) &myAisTopToolTipsIn, Handle(AIS_Shape) &myAisBotToolTipsIn, TopoDS_Compound &myCurrentPartIn,
		Handle(V3d_Viewer) &myViewerIn, Handle(V3d_View) &myViewIn, Handle(AIS_InteractiveContext) &myContextIn, Handle(AIS_Shape) &myAisShapeIn, QTextEdit *textEditIn, QEventLoop &myEventLoopIn);

	bool calcContactPnts();
	bool calcToolTipPnts(const bool checkToolpathInterference, const int performConstZHeightTips);

protected:

private:
	bool toolpathPreprocessing(toolpathZHeightProps &masterHeightProps, std::vector<float> &allZDepthSlices);
	bool toolTipPreprocessing(toolpathZHeightProps &masterHeightProps);
	bool getDiscretizedIntersection(ampl::planeIntersecter &contourObj, toolpathZHeightProps &tempHeightPropsCurrent, const toolpathZHeightProps &masterHeightProps);
	void calcSurfInfo(ampl::planeIntersecter &contourObj, toolpathZHeightProps &tempHeightPropsSaved, toolpathZHeightProps &masterHeightProps);
	void calcApproxSpiralSurfInfo(ampl::planeIntersecter &contourObj, toolpathZHeightProps &tempHeightPropsLast, toolpathZHeightProps &tempHeightPropsCurrent, toolpathZHeightProps &tempHeightPropsSaved, toolpathZHeightProps &masterHeightProps);
	bool findNextAdaptiveZSlice(const toolpathZHeightProps &tempHeightPropsCurrent, const toolpathZHeightProps &masterHeightProps, float &nextZHeightOut);
	void getSpiralPoints(const toolpathZHeightProps &tempHeightPropsLast, const toolpathZHeightProps &tempHeightPropsCurrent, const toolpathZHeightProps &masterHeightProps, toolpathZHeightProps &tempHeightPropsSaved);
	void getToolTipPoints(const toolpathZHeightProps &masterHeightProps, toolpathZHeightProps &tempHeightPropsSaved, bool checkForInterference, int performConstZHeightTips);

	void correctConstZHeightTips(const bool isTopTool, const toolpathZHeightProps &masterHeightProps, float sphereRad, const std::vector<gp_Pnt> &contactPnts, const std::vector<gp_Pnt> &toolCenterPnts,
		const std::vector<gp_Vec> normalVecs, std::vector<gp_Pnt> &toolTipPnts);
	float calcWallAngle(const gp_Vec &localNormalVec);
	gp_Vec calcLocalNormal(float wallAngle, const gp_Vec &localNormalXY, bool useReverseNormalXY, bool usePosZDirection);
	static bool correctSphericalInterference(bool topTool, const std::vector<gp_Pnt> &toolCenterPntsIn, const std::vector<gp_Pnt> &toolTipPntsIn, const std::vector<gp_Pnt> &contactPntsIn, const std::vector<gp_Vec> &contactPntNormals, 
		float sphereRad, float tol, std::vector<gp_Pnt> &toolTipsModOut, std::vector<gp_Pnt> &toolCentersModOut, float &maxInterferenceOut);
	static bool correctFlatTopInterference(bool topTool, const std::vector<gp_Pnt> &toolCenterPntsIn, const std::vector<gp_Pnt> &toolCornerCenterPntsIn, const std::vector<gp_Pnt> &toolTipPntsIn, const std::vector<gp_Pnt> &contactPntsIn,
		const std::vector<gp_Vec> &contactPntNormals, float toolRad, float cornerRad, float tol, std::vector<gp_Pnt> &toolTipsModOut, std::vector<gp_Pnt> &toolCentersModOut, std::vector<gp_Pnt> &toolCornerCentersModOut, float &maxInterferenceOut);
	void findLocalTangentDirection(const gp_Pnt &curContactPnt, int curContactPntIndex, const std::vector<gp_Pnt> &contactPnts, const std::vector<gp_Vec> &contactPntNormals, bool reverseNormal, bool goingCCW, gp_Dir &tangentDirOut);
	void refreshGraphics(const toolpathZHeightProps &masterHeightProps, bool refreshContactPnts, bool refreshToolTipPnts);
	static void removeCollinearPnts(Standard_Real relAngleTolDeg, std::vector<gp_Pnt> &orderdPntsArrInOut, std::vector<int> &indicesKept);
	static bool distPairCompare(const std::pair<float, int> &firstElem, const std::pair<float, int> &secondElem);
	static void removeInitialPnts(const int numPntsToSkip, std::vector<gp_Pnt> &modifiedPntsInOut);

	amplToolpath *myCurrentToolpath;
	Handle(AIS_Shape) *myAisTopContactPnts;
	Handle(AIS_Shape) *myAisBotContactPnts;
	Handle(AIS_Shape) *myAisTopToolTips;
	Handle(AIS_Shape) *myAisBotToolTips;
	Handle(V3d_Viewer) myViewer;
	Handle(V3d_View) myView;
	Handle(AIS_InteractiveContext) myContext;
	Handle(AIS_Shape) *myAisShape;
	TopoDS_Compound *myCurrentPart;
	TopoDS_Compound *myCurrentBotContactPnts;
	TopoDS_Compound *myCurrentTopContactPnts;
	TopoDS_Compound *myCurrentTopToolTips;
	TopoDS_Compound *myCurrentBotToolTips;
	QTextEdit *textEdit;
	QEventLoop *myEventLoop;

	//bool directionDown;
};