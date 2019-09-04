#pragma once

#include "stdafx.h"
#include "amplToolpath.h"

class toolpathZHeightProps
{
public:
	toolpathZHeightProps();
	void init(const amplToolpath &amplToolpathIn);
	void copyAllFromOther(const toolpathZHeightProps &other);
	void copyZDepthFromOther(const toolpathZHeightProps &other);
	void resetMembers(bool resetLocalAmplObject = false);
	void resetZDepthContactPnts(void);
	void resetZDepthToolTipPnts(void);
	void resetZDepthToolTipPntsMod(void);
	void resetZDepthLocalSurfProps(void);
	void resetAllContactPnts(bool resetZDepth = false);
	void resetAllToolTipPnts(bool resetZDepth = false);
	void resetAllToolTipPntsMod(bool resetZDepth = false);
	void resetAllLocalSurfProps(bool resetZDepth = false);
	void interpolateZDepthContactContours(const std::vector<gp_Pnt> &pntsIn, const toolpathZHeightProps &lastZHeight, const toolpathZHeightProps &currentZHeight, toolpathZHeightProps &outZHeight);

	// Properties used in toolpath algorithms; anything with zDepth in the name means it changes for each increment in the Z-direction
	float currentZDepth;
	float zDepthMaxDistanceFromCOM;
	gp_Pnt zDepthAvgCoM;
	gp_Pnt zDepthStartAnglePnt;
	float zDepthTotalIntersectLength;

	std::vector<gp_Pnt> zDepthTopContactPnts; // These are temporary vectors corresponding to properties 
	std::vector<gp_Pnt> zDepthBotContactPnts; // only for the contact points at the current Z-slice.
	std::vector<gp_Pnt> zDepthTopToolTipPnts;
	std::vector<gp_Pnt> zDepthBotToolTipPnts;
	std::vector<gp_Pnt> zDepthTopToolTipPntsMod;
	std::vector<gp_Pnt> zDepthBotToolTipPntsMod;

	std::vector<gp_Vec> zDepthNormals; // Assumed that these properties hold approximately true for both the top and bottom contacts
	std::vector<gp_Vec> zDepthKappaMaxDirections;
	std::vector<gp_Vec> zDepthKappaMinDirections;
	std::vector<float> zDepthKappaMax;
	std::vector<float> zDepthKappaMin;
	std::vector<float> zDepthKappaMean;
	std::vector<float> zDepthKappaGaussian;

	// Properties related to amplToolpath.h which get added to after each Z-slice
	amplToolpath localAmplToolpath;
	std::vector<gp_Pnt> allTopContactPnts;
	std::vector<gp_Pnt> allBotContactPnts;
	std::vector<gp_Pnt> allTopToolTipPnts;
	std::vector<gp_Pnt> allBotToolTipPnts;
	std::vector<gp_Pnt> allTopToolTipPntsMod;
	std::vector<gp_Pnt> allBotToolTipPntsMod;

	std::vector<gp_Vec> allNormals; // Assumed that these properties hold approximately true for both the top and bottom contacts
	std::vector<gp_Vec> allKappaMaxDirections;
	std::vector<gp_Vec> allKappaMinDirections;
	std::vector<float> allKappaMax;
	std::vector<float> allKappaMin;
	std::vector<float> allKappaMean;
	std::vector<float> allKappaGaussian;
	std::vector<int> allContourIndices;

	void pushBackZDepthTopContactPnts(bool addToLocalAmplToolpath, bool useSineLawOffset, bool useReverseNormal = false);
	void pushBackZDepthBotContactPnts(bool addToLocalAmplToolpath, bool useSineLawOffset, bool useReverseNormal = false);
	void pushBackZDepthTopToolTipPnts(bool addToLocalAmplToolpath);
	void pushBackZDepthBotToolTipPnts(bool addToLocalAmplToolpath);
	void pushBackZDepthTopToolTipPntsMod(bool addToLocalAmplToolpath);
	void pushBackZDepthBotToolTipPntsMod(bool addToLocalAmplToolpath);
	//! topOrBotContactSurfProps = -1 to push_back bottom contact pnt surf props
	//! topOrBotContactSurfProps = 1 to push_back top contact pnt surf props
	//! topOrBotContactSurfProps = 0 to push_back both top and bottom contact pnt surf props
	void pushBackZDepthContactPntsSurfProps(bool addToLocalAmplToolpath, int topOrBotContactSurfProps);
	
	void copyAllContactPntsToLocalAmpl(void);
	void copyAllToolTipPntsToLocalAmpl(void);
	void copyAllToolTipPntsModToLocalAmpl(void);
	void copyAllSurfPropsToLocalAmpl(void);

	void copyAmplContactPntsToOther(amplToolpath &other);
	void copyAmplToolTipPntsToOther(amplToolpath &other);
	void copyAmplToolTipPntsModToOther(amplToolpath &other);
	void copyAmplSurfPropsToOther(amplToolpath &other);

	void pushBackAllContactPntsToOther(toolpathZHeightProps &other, bool localAmplOnly);
	void pushBackAllToolTipPntsToOther(toolpathZHeightProps &other, bool localAmplOnly);
	void pushBackAllToolTipPntsModToOther(toolpathZHeightProps &other, bool localAmplOnly);
	//! topOrBotContactSurfProps = -1 to push_back bottom contact pnt surf props
	//! topOrBotContactSurfProps = 1 to push_back top contact pnt surf props
	//! topOrBotContactSurfProps = 0 to push_back both top and bottom contact pnt surf props
	void pushBackAllSurfPropsToOther(toolpathZHeightProps &other, int topOrBotContactSurfProps, bool localAmplOnly);

protected:

private:
	
};