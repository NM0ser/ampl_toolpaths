#include "stdafx.h"
#include "amplLineRegion.h"

amplLineRegion::amplLineRegion()
{
	startPoint = gp_Pnt(0,0,0);
	startPoint = gp_Pnt(1, 0, 0);
	incAlongLine = 0.0;
}

amplLineRegion::amplLineRegion(const gp_Pnt &startPntIn, const gp_Pnt &endPntIn, const float &incAlongLineIn)
{
	startPoint = startPntIn;
	endPoint = endPntIn;
	incAlongLine = incAlongLineIn;
}

amplLineRegion::~amplLineRegion()
{
}

void amplLineRegion::getStartPoint(gp_Pnt &startPntOut) const
{
	startPntOut = startPoint;
}

void amplLineRegion::getEndPoint(gp_Pnt &endPntOut) const
{
	endPntOut = endPoint;
}

void amplLineRegion::getIncAlongLine(float &incAlongLineOut) const
{
	incAlongLineOut = incAlongLine;
}

void amplLineRegion::setStartPoint(const gp_Pnt &startPntIn)
{
	startPoint = startPntIn;
}

void amplLineRegion::setEndPoint(const gp_Pnt &endPntIn)
{
	endPoint = endPntIn;
}

void amplLineRegion::setIncAlongLine(const float &incAlongLineIn)
{
	incAlongLine = incAlongLineIn;
}

double amplLineRegion::lineLength(void)
{
	return startPoint.Distance(endPoint);
}

bool amplLineRegion::getDiscretizedLine(std::vector<gp_Pnt> &pntArrayOut)
{
	if (incAlongLine < 0.001)
		return false;
	else if (lineLength() < 0.001)
		return false;

	pntArrayOut.clear();
	Handle(Geom_TrimmedCurve) lineTrimCurve = GC_MakeSegment(startPoint, endPoint);
	float U1, U2;
	U1 = lineTrimCurve->FirstParameter();
	U2 = lineTrimCurve->LastParameter();

	GeomAdaptor_Curve lineAdaptCurve(lineTrimCurve);
	GCPnts_UniformAbscissa pntBuilder(lineAdaptCurve, incAlongLine, U1, U2);
	if (!pntBuilder.IsDone())
		return false;
	
	int numPoints = pntBuilder.NbPoints();
	for (int m = 1; m <= numPoints; m++)
	{
		float curU = pntBuilder.Parameter(m);
		gp_Pnt curPnt = lineTrimCurve->Value(curU);
		pntArrayOut.push_back(curPnt);
	}

	return true;
}

void amplLineRegion::copyFromOther(const amplLineRegion &lineRegionOther)
{
	lineRegionOther.getStartPoint(this->startPoint);
	lineRegionOther.getEndPoint(this->endPoint);
	lineRegionOther.getIncAlongLine(this->incAlongLine);
}
