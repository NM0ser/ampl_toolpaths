#pragma once
#include "stdafx.h"
#include <vector>
#include <cereal/archives/xml.hpp>
#include <cereal/types/vector.hpp>

class amplToolpath
{
public:
	amplToolpath::amplToolpath(); // Default constructor;
	void initialize(const amplToolpath &amplToolpathIn);
	void copy(const amplToolpath &amplToolpathIn);
	void reset(void);

	enum incFormingMethodType { SPIF, TPIF, DSIF, ADSIF, INCFORMINGMETHOD_UNKNOWN };
	enum toolpathMethodType { contour, spiral, TOOLPATHMETHOD_UNKNOWN };
	enum tpifDieType {female, male, TPIFDIETYPE_UNKNOWN};
	enum formingDirectionType {posZDir, negZDir, FORMINGDIRECTIONTYPE_UNKNOWN};
	enum toolProfile {hemispherical, flatTop};

	// --- Start of public Members that get saved/serialized into the .ampl file --- //
	incFormingMethodType myIncFormingMethodType;
	toolpathMethodType mytoolpathMethodType;
	tpifDieType myTpifDieType;
	formingDirectionType myFormingDirectionType;
	toolProfile topToolProfile;
	toolProfile botToolProfile;

	float startDepth;
	float endDepth;
	float sheetThickness;
	float incDepth;
	float topToolDiam;
	float botToolDiam;
	float topToolCornerRad;
	float botToolCornerRad;
	float sqzFactor;
	float incToolpathCurve;
	float startAngleFromXAxisDeg;
	float startRadialDistance;
	int contourRampSkipPnts;

	std::vector< std::vector<float> > topContactPnts;
	std::vector< std::vector<float> > botContactPnts;
	std::vector< std::vector<float> > topContactPntsSurfProps;
	std::vector< std::vector<float> > botContactPntsSurfProps;
	std::vector< std::vector<float> > topToolTipPnts;
	std::vector< std::vector<float> > botToolTipPnts;
	std::vector< std::vector<float> > topToolTipPntsMod;
	std::vector< std::vector<float> > botToolTipPntsMod;
	std::vector< int > contourIndices;

	bool goingCCW;
	bool adaptiveSlicingOn;
	bool toolpathIsActive;
	bool useFastSpiralApprox;
	bool keepDsifToolOnSheetBlank;
	bool removedCollinearContactPoints;
	// --- End of public Members that get saved/serialized into the .ampl file --- //

	// "Getters" and "setters"
	float getUnassignedVal(void) const;
	bool getModifiedTipPntsBool(void) const;
	void setModifiedTopPntsBool(bool boolIn);

	// Functions to check if inputs have been filled
	bool myIncFormingMethodTypeActive(void);
	bool mytoolpathMethodTypeActive(void);
	bool tpifDieTypeActive(void);
	bool formingDirectionTypeActive(void);
	bool startDepthActive(void);
	bool endDepthActive(void);
	bool sheetThicknessActive(void);
	bool incDepthActive(void);
	bool topToolDiamActive(void);
	bool botToolDiamActive(void);
	bool topToolCornerRadiusActive(void);
	bool botToolCornerRadiusActive(void);
	bool sqzFactorActive(void);
	bool incToolpathCurveActive(void);
	bool topContactPntsActive(void);
	bool botContactPntsActive(void);
	bool topContactPntsSurfPropsActive(void);
	bool botContactPntsSurfPropsActive(void);
	bool topToolTipPntsActive(void);
	bool botToolTipPntsActive(void);
	bool topToolTipPntsModActive(void);
	bool botToolTipPntsModActive(void);

protected:

private:
	float unassignedVal;
	void setUnassignedVal(float valIn);
	bool modifiedTipPntsBool;

	bool resetUnassignedMembersValues(float valToCheck);
};

// These lines of code tell cereal what members to serialize of amplToolpath class
template<class Archive>
void serialize(Archive & archive,
	amplToolpath & m)
{
	archive(m.myIncFormingMethodType,
		m.mytoolpathMethodType,
		m.myTpifDieType,
		m.myFormingDirectionType,
		m.topToolProfile,
		m.botToolProfile,
		m.startDepth,
		m.endDepth,
		m.sheetThickness,
		m.incDepth,
		m.topToolDiam,
		m.botToolDiam,
		m.topToolCornerRad,
		m.botToolCornerRad,
		m.sqzFactor,
		m.incToolpathCurve,
		m.startAngleFromXAxisDeg,
		m.startRadialDistance,
		m.contourRampSkipPnts,
		m.topContactPnts,
		m.botContactPnts,
		m.topContactPntsSurfProps,
		m.botContactPntsSurfProps,
		m.topToolTipPnts,
		m.botToolTipPnts,
		m.topToolTipPntsMod,
		m.botToolTipPntsMod,
		m.contourIndices,
		m.toolpathIsActive,
		m.goingCCW,
		m.adaptiveSlicingOn,
		m.useFastSpiralApprox,
		m.keepDsifToolOnSheetBlank,
		m.removedCollinearContactPoints);
}