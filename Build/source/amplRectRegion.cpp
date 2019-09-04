#include "stdafx.h"
#include "amplRectRegion.h"

amplRectRegion::amplRectRegion()
{
	centerPnt = gp_Pnt(0, 0, 0);
	xWidth = 1.0;
	yWidth = 1.0;
	incAlongX = 0.0;
	incAlongY = 0.0;
}

amplRectRegion::amplRectRegion(const gp_Pnt &centerPntIn, const float xWidthIn, const float yWidthIn, const float incAlongXIn, const float incAlongYIn)
{
	centerPnt = centerPntIn;
	xWidth = xWidthIn;
	yWidth = yWidthIn;
	incAlongX = incAlongXIn;
	incAlongY = incAlongYIn;
}

amplRectRegion::~amplRectRegion()
{

}

void amplRectRegion::getCenterPoint(gp_Pnt &centerPntOut) const
{
	centerPntOut = centerPnt;
}

void amplRectRegion::getXWidth(float &xWidthOut) const
{
	xWidthOut = xWidth;
}

void amplRectRegion::getYWidth(float &yWidthOut) const
{
	yWidthOut = yWidth;
}

void amplRectRegion::getIncAlongX(float &incAlongXOut) const
{
	incAlongXOut = incAlongX;
}

void amplRectRegion::getIncAlongY(float &incAlongYOut) const
{
	incAlongYOut = incAlongY;
}

void amplRectRegion::setCenterPoint(const gp_Pnt &centerPntIn)
{
	centerPnt = centerPntIn;
}

void amplRectRegion::setXWidth(const float &xWidthIn)
{
	xWidth = xWidthIn;
}

void amplRectRegion::setYWidth(const float &yWidthIn)
{
	yWidth = yWidthIn;
}

void amplRectRegion::setIncAlongX(const float &incAlongXIn)
{
	incAlongX = incAlongXIn;
}

void amplRectRegion::setIncAlongY(const float &incAlongYIn)
{
	incAlongY = incAlongYIn;
}

double amplRectRegion::area(void)
{
	return xWidth*yWidth;
}

bool amplRectRegion::getDiscretizedRect(std::vector< std::vector<gp_Pnt> > &pntArrayOut)
{
	if (incAlongY < 0.001 || incAlongX < 0.001)
		return false;
	else if (area() < 1E-6)
		return false;

	pntArrayOut.clear();

	float centerX = centerPnt.X();
	float centerY = centerPnt.Y();
	float centerZ = centerPnt.Z();
	gp_Pnt perimQuad2Pnt(centerX - xWidth/2.0, centerY + yWidth/2.0, centerZ);
	gp_Pnt perimQuad3Pnt(centerX - xWidth/2.0, centerY - yWidth/2.0, centerZ);
	gp_Pnt perimQuad4Pnt(centerX + xWidth/2.0, centerY - yWidth/2.0, centerZ);

	Handle(Geom_TrimmedCurve) line34XTrimCurve = GC_MakeSegment(perimQuad3Pnt, perimQuad4Pnt);
	Handle(Geom_TrimmedCurve) line32YTrimCurve = GC_MakeSegment(perimQuad3Pnt, perimQuad2Pnt);
	float line34U1, line34U2, line32U1, line32U2;
	line34U1 = line34XTrimCurve->FirstParameter();
	line34U2 = line34XTrimCurve->LastParameter();
	line32U1 = line32YTrimCurve->FirstParameter();
	line32U2 = line32YTrimCurve->LastParameter();

	GeomAdaptor_Curve line34XAdaptCurve(line34XTrimCurve);
	GCPnts_UniformAbscissa pntXBuilder(line34XAdaptCurve, incAlongX, line34U1, line34U2);
	if (!pntXBuilder.IsDone())
		return false;

	GeomAdaptor_Curve line32YAdaptCurve(line32YTrimCurve);
	GCPnts_UniformAbscissa pntYBuilder(line32YAdaptCurve, incAlongY, line32U1, line32U2);
	if (!pntYBuilder.IsDone())
		return false;

	std::vector<gp_Pnt> xPntArray;
	int numXPoints = pntXBuilder.NbPoints();
	for(int m = 1; m <= numXPoints; m++)
	{
		float curU = pntXBuilder.Parameter(m);
		gp_Pnt curPnt = line34XTrimCurve->Value(curU);
		xPntArray.push_back(curPnt);
	}

	std::vector<gp_Pnt> yPntArray;
	int numYPoints = pntYBuilder.NbPoints();
	for (int m = 1; m <= numYPoints; m++)
	{
		float curU = pntYBuilder.Parameter(m);
		gp_Pnt curPnt = line32YTrimCurve->Value(curU);
		yPntArray.push_back(curPnt);
	}

	for (int m = 0; m < xPntArray.size(); m++)
	{
		std::vector<gp_Pnt> tempXRow;
		for (int n = 0; n < yPntArray.size(); n++)
		{
			float curX = (xPntArray.at(m)).X();
			float curY = (yPntArray.at(n)).Y();
			float curZ = centerZ;
			gp_Pnt curXYPnt(curX, curY, curZ);
			tempXRow.push_back(curXYPnt);
		}

		pntArrayOut.push_back(tempXRow);
	}

	return true;
}

void amplRectRegion::copyFromOther(const amplRectRegion &rectRegionOther)
{
	rectRegionOther.getCenterPoint(this->centerPnt);
	rectRegionOther.getXWidth(this->xWidth);
	rectRegionOther.getYWidth(this->yWidth);
	rectRegionOther.getIncAlongX(this->incAlongX);
	rectRegionOther.getIncAlongY(this->incAlongY);
}