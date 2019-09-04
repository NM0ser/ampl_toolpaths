#pragma once

#include "stdafx.h"

class amplLineRegion
{
public:
	amplLineRegion::amplLineRegion();
	amplLineRegion::amplLineRegion(const gp_Pnt &startPntIn, const gp_Pnt &endPntIn, const float &incAlongLineIn);
	amplLineRegion::~amplLineRegion();

	void getStartPoint(gp_Pnt &startPntOut) const;
	void getEndPoint(gp_Pnt &endPntOut) const;
	void getIncAlongLine(float &incAlongLineOut) const;
	void setStartPoint(const gp_Pnt &startPntIn);
	void setEndPoint(const gp_Pnt &endPntIn);
	void setIncAlongLine(const float &incAlongLineIn);
	void copyFromOther(const amplLineRegion &lineRegionOther);

	double lineLength(void);
	bool getDiscretizedLine(std::vector<gp_Pnt> &pntArrayOut);

protected:

private:
	gp_Pnt startPoint;
	gp_Pnt endPoint;
	float incAlongLine;
};