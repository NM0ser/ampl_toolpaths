#include "stdafx.h"

#include "amplToolpath.h"

amplToolpath::amplToolpath()
{
	unassignedVal = -999999.999;

	myIncFormingMethodType = incFormingMethodType::INCFORMINGMETHOD_UNKNOWN;
	mytoolpathMethodType = toolpathMethodType::TOOLPATHMETHOD_UNKNOWN;
	myTpifDieType = tpifDieType::TPIFDIETYPE_UNKNOWN;
	myFormingDirectionType = formingDirectionType::FORMINGDIRECTIONTYPE_UNKNOWN;
	topToolProfile = toolProfile::hemispherical;
	botToolProfile = toolProfile::hemispherical;

	modifiedTipPntsBool = false;

	startDepth = unassignedVal;
	endDepth = unassignedVal;
	sheetThickness = unassignedVal;
	incDepth = unassignedVal;
	topToolDiam = unassignedVal;
	botToolDiam = unassignedVal;
	topToolCornerRad = unassignedVal;
	botToolCornerRad = unassignedVal;
	sqzFactor = unassignedVal;
	incToolpathCurve = unassignedVal;
	startAngleFromXAxisDeg = 0.0;
	startRadialDistance = 10000;
	contourRampSkipPnts = 0;

	topContactPnts = { { unassignedVal, unassignedVal, unassignedVal } };
	botContactPnts = { { unassignedVal, unassignedVal, unassignedVal } };
	topContactPntsSurfProps = { { unassignedVal, unassignedVal, unassignedVal, unassignedVal, 
								  unassignedVal, unassignedVal, unassignedVal, unassignedVal, 
								  unassignedVal, unassignedVal, unassignedVal, unassignedVal, unassignedVal } };
	botContactPntsSurfProps = { { unassignedVal, unassignedVal, unassignedVal, unassignedVal,
								  unassignedVal, unassignedVal, unassignedVal, unassignedVal,
								  unassignedVal, unassignedVal, unassignedVal, unassignedVal, unassignedVal } };
	topToolTipPnts = { { unassignedVal, unassignedVal, unassignedVal } };
	botToolTipPnts = { { unassignedVal, unassignedVal, unassignedVal } };
	topToolTipPntsMod = { { unassignedVal, unassignedVal, unassignedVal } };
	botToolTipPntsMod = { { unassignedVal, unassignedVal, unassignedVal } };
	contourIndices = {0};

	toolpathIsActive = false;
	goingCCW = true;
	adaptiveSlicingOn = false;
	useFastSpiralApprox = false;
	keepDsifToolOnSheetBlank = false;
	removedCollinearContactPoints = true;
}

void amplToolpath::copy(const amplToolpath &amplToolpathIn)
{
	setUnassignedVal(amplToolpathIn.getUnassignedVal());

	myIncFormingMethodType = amplToolpathIn.myIncFormingMethodType;
	mytoolpathMethodType = amplToolpathIn.mytoolpathMethodType;
	myTpifDieType = amplToolpathIn.myTpifDieType;
	myFormingDirectionType = amplToolpathIn.myFormingDirectionType;
	topToolProfile = amplToolpathIn.topToolProfile;
	botToolProfile = amplToolpathIn.botToolProfile;
	contourIndices = amplToolpathIn.contourIndices;

	modifiedTipPntsBool = amplToolpathIn.modifiedTipPntsBool;

	startDepth = amplToolpathIn.startDepth;
	endDepth = amplToolpathIn.endDepth;
	sheetThickness = amplToolpathIn.sheetThickness;
	incDepth = amplToolpathIn.incDepth;
	topToolDiam = amplToolpathIn.topToolDiam;
	botToolDiam = amplToolpathIn.botToolDiam;
	topToolCornerRad = amplToolpathIn.topToolCornerRad;
	botToolCornerRad = amplToolpathIn.botToolCornerRad;
	sqzFactor = amplToolpathIn.sqzFactor;
	incToolpathCurve = amplToolpathIn.incToolpathCurve;
	startAngleFromXAxisDeg = amplToolpathIn.startAngleFromXAxisDeg;
	startRadialDistance = amplToolpathIn.startRadialDistance;
	contourRampSkipPnts = amplToolpathIn.contourRampSkipPnts;

	topContactPnts = amplToolpathIn.topContactPnts;
	botContactPnts = amplToolpathIn.botContactPnts;
	topContactPntsSurfProps = amplToolpathIn.topContactPntsSurfProps;
	botContactPntsSurfProps = amplToolpathIn.botContactPntsSurfProps;
	topToolTipPnts = amplToolpathIn.topToolTipPnts;
	botToolTipPnts = amplToolpathIn.botToolTipPnts;
	topToolTipPntsMod = amplToolpathIn.topToolTipPntsMod;
	botToolTipPntsMod = amplToolpathIn.botToolTipPntsMod;

	toolpathIsActive = amplToolpathIn.toolpathIsActive;
	goingCCW = amplToolpathIn.goingCCW;
	adaptiveSlicingOn = amplToolpathIn.adaptiveSlicingOn;
	useFastSpiralApprox = amplToolpathIn.useFastSpiralApprox;
	keepDsifToolOnSheetBlank = amplToolpathIn.keepDsifToolOnSheetBlank;
	removedCollinearContactPoints = amplToolpathIn.removedCollinearContactPoints;
}

void amplToolpath::initialize(const amplToolpath &amplToolpathIn)
{
	copy(amplToolpathIn);
}

void amplToolpath::reset(void)
{
	amplToolpath defaultAmplObject;
	copy(defaultAmplObject);
}

float amplToolpath::getUnassignedVal(void) const
{
	return unassignedVal;
}

void amplToolpath::setUnassignedVal(float valIn)
{
	bool someMembersWereReset = resetUnassignedMembersValues(valIn);
	unassignedVal = valIn;
}

bool amplToolpath::getModifiedTipPntsBool(void) const
{
	return modifiedTipPntsBool;
}

void amplToolpath::setModifiedTopPntsBool(bool boolIn)
{
	modifiedTipPntsBool = boolIn;
}

bool amplToolpath::myIncFormingMethodTypeActive(void)
{
	if (myIncFormingMethodType == incFormingMethodType::INCFORMINGMETHOD_UNKNOWN)
		return false;
	else
		return true;
}

bool amplToolpath::mytoolpathMethodTypeActive(void)
{
	if (mytoolpathMethodType == toolpathMethodType::TOOLPATHMETHOD_UNKNOWN)
		return false;
	else
		return true;
}

bool amplToolpath::tpifDieTypeActive(void)
{
	if (myTpifDieType == tpifDieType::TPIFDIETYPE_UNKNOWN)
		return false;
	else
		return true;
}

bool amplToolpath::formingDirectionTypeActive(void)
{
	if (myFormingDirectionType == formingDirectionType::FORMINGDIRECTIONTYPE_UNKNOWN)
		return false;
	else
		return true;
}

bool amplToolpath::startDepthActive(void)
{
	if (startDepth == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::endDepthActive(void)
{
	if (endDepth == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::sheetThicknessActive(void)
{
	if (sheetThickness == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::incDepthActive(void)
{
	if (incDepth == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::topToolDiamActive(void)
{
	if (topToolDiam == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::botToolDiamActive(void)
{
	if (botToolDiam == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::topToolCornerRadiusActive(void)
{
	if (topToolCornerRad == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::botToolCornerRadiusActive(void)
{
	if (botToolCornerRad == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::sqzFactorActive(void)
{
	if (sqzFactor == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::incToolpathCurveActive(void)
{
	if (incToolpathCurve == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::topContactPntsActive(void)
{
	if (topContactPnts.empty())
		return false;
	else if ((topContactPnts.front()).front() == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::botContactPntsActive(void)
{
	if (botContactPnts.empty())
		return false;
	else if ((botContactPnts.front()).front() == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::topContactPntsSurfPropsActive(void)
{
	if (topContactPntsSurfProps.empty())
		return false;
	else if ((topContactPntsSurfProps.front()).front() == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::botContactPntsSurfPropsActive(void)
{
	if (botContactPntsSurfProps.empty())
		return false;
	else if ((botContactPntsSurfProps.front()).front() == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::topToolTipPntsActive(void)
{
	if (topToolTipPnts.empty())
		return false;
	else if ((topToolTipPnts.front()).front() == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::botToolTipPntsActive(void)
{
	if (botToolTipPnts.empty())
		return false;
	else if ((botToolTipPnts.front()).front() == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::topToolTipPntsModActive(void)
{
	if (topToolTipPntsMod.empty())
		return false;
	else if ((topToolTipPntsMod.front()).front() == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::botToolTipPntsModActive(void)
{
	if (botToolTipPntsMod.empty())
		return false;
	else if ((botToolTipPntsMod.front()).front() == unassignedVal)
		return false;
	else
		return true;
}

bool amplToolpath::resetUnassignedMembersValues(float valToCheck)
{
	if (valToCheck == unassignedVal)
		return false; // Nothing needs to be updated, so reset does not happen
	
	//if (!myIncFormingMethodTypeActive())
	//{}

	//if (!mytoolpathMethodTypeActive())
	//{}

	//if(!tpifDieTypeActive())
	//{}

	//if (!formingDirectionTypeActive())
	//{}

	modifiedTipPntsBool = false;

	if (!startDepthActive())
		startDepth = valToCheck;

	if (!endDepthActive())
		endDepth = valToCheck;

	if (!sheetThicknessActive())
		sheetThickness = valToCheck;

	if (!incDepthActive())
		incDepth = valToCheck;

	if (!topToolDiamActive())
		topToolDiam = valToCheck;

	if (!botToolDiamActive())
		botToolDiam = valToCheck;

	if (!topToolCornerRadiusActive())
		topToolCornerRad = valToCheck;

	if (!botToolCornerRadiusActive())
		botToolCornerRad = valToCheck;

	if (!sqzFactorActive())
		sqzFactor = valToCheck;

	if (!incToolpathCurveActive())
		incToolpathCurve = valToCheck;

	if (!topContactPntsActive())
		topContactPnts = { { valToCheck, valToCheck, valToCheck } };

	if (!botContactPntsActive())
		botContactPnts = { { valToCheck, valToCheck, valToCheck } };

	if (!topContactPntsSurfPropsActive())
		topContactPntsSurfProps = { { valToCheck, valToCheck, valToCheck, valToCheck,
									  valToCheck, valToCheck, valToCheck, valToCheck,
									  valToCheck, valToCheck, valToCheck, valToCheck, valToCheck } };

	if (!botContactPntsSurfPropsActive())
		botContactPntsSurfProps = { { valToCheck, valToCheck, valToCheck, valToCheck,
									  valToCheck, valToCheck, valToCheck, valToCheck,
									  valToCheck, valToCheck, valToCheck, valToCheck, valToCheck } };

	if (!topToolTipPntsActive())
		topToolTipPnts = { { valToCheck, valToCheck, valToCheck } };

	if (!botToolTipPntsActive())
		botToolTipPnts = { { valToCheck, valToCheck, valToCheck } };

	if (!topToolTipPntsModActive())
		topToolTipPntsMod = { { valToCheck, valToCheck, valToCheck } };
	else
		modifiedTipPntsBool = true;

	if (!botToolTipPntsModActive())
		botToolTipPntsMod = { { valToCheck, valToCheck, valToCheck } };
	else
		modifiedTipPntsBool = true;

	return true;
}


