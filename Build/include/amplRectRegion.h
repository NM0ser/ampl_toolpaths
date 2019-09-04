#pragma once

#include "stdafx.h"

class amplRectRegion
{
public:
	amplRectRegion::amplRectRegion();
	amplRectRegion::amplRectRegion(const gp_Pnt &centerPntIn, const float xWidthIn, const float yWidthIn, const float incAlongXIn, const float incAlongYIn);
	amplRectRegion::~amplRectRegion();

	void getCenterPoint(gp_Pnt &centerPntOut) const;
	void getXWidth(float &xWidthOut) const;
	void getYWidth(float &yWidthOut) const;
	void getIncAlongX(float &incAlongXOut) const;
	void getIncAlongY(float &incAlongYOut) const;
	void copyFromOther(const amplRectRegion &rectRegionOther);

	void setCenterPoint(const gp_Pnt &centerPntIn);
	void setXWidth(const float &xWidthIn);
	void setYWidth(const float &yWidthIn);
	void setIncAlongX(const float &incAlongXIn);
	void setIncAlongY(const float &incAlongYIn);

	double area(void);
	bool getDiscretizedRect(std::vector< std::vector<gp_Pnt> > &pntArrayOut);

protected:

private:
	gp_Pnt centerPnt;
	float xWidth;
	float yWidth;
	float incAlongX;
	float incAlongY;
};