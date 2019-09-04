#include "stdafx.h"
#include "rectRegionDefinitionDialog.h"

rectRegionDefinitionDialog::rectRegionDefinitionDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);
}

rectRegionDefinitionDialog::~rectRegionDefinitionDialog()
{

}

bool rectRegionDefinitionDialog::getCenterPoint(gp_Pnt &centerPntOut)
{
	QString xPntStr = (xCenterPntLineEdit->text()).trimmed();
	QString yPntStr = (yCenterPntLineEdit->text()).trimmed();
	QString zPntStr = (zCenterPntLineEdit->text()).trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;

	xPntStr.toFloat(&str2floatOK1);
	yPntStr.toFloat(&str2floatOK2);
	zPntStr.toFloat(&str2floatOK3);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3)
	{
		return false;
	}

	float xPnt = xPntStr.toFloat();
	float yPnt = yPntStr.toFloat();
	float zPnt = zPntStr.toFloat();

	centerPntOut = gp_Pnt(xPnt, yPnt, zPnt);
	return true;
}

bool rectRegionDefinitionDialog::getXWidth(float &xWidthOut)
{
	xWidthOut = xRectWidthSpinBox->value();
	return true;
}

bool rectRegionDefinitionDialog::getYWidth(float &yWidthOut)
{
	yWidthOut = yRectWidthSpinBox->value();
	return true;
}

bool rectRegionDefinitionDialog::getIncAlongX(float &incAlongXOut)
{
	incAlongXOut = xIncSpinBox->value();
	return true;
}

bool rectRegionDefinitionDialog::getIncAlongY(float &incAlongYOut)
{
	incAlongYOut = yIncSpinBox->value();
	return true;
}

bool rectRegionDefinitionDialog::getRectRegion(amplRectRegion &rectRegionOut)
{
	bool buildRectRegionSuccess = buildRectRegion();
	if (buildRectRegionSuccess)
	{
		rectRegionOut.copyFromOther(myRectRegion);
	}

	return buildRectRegionSuccess;
}

bool rectRegionDefinitionDialog::buildRectRegion(void)
{
	gp_Pnt centerPnt;
	float xWidth, yWidth, incAlongX, incAlongY;

	bool centPntSuccess = getCenterPoint(centerPnt);
	bool xWidthSuccess = getXWidth(xWidth);
	bool yWidthSuccess = getYWidth(yWidth);
	bool incAlongXSuccess = getIncAlongX(incAlongX);
	bool incAlongYSuccess = getIncAlongY(incAlongY);

	if (centPntSuccess && xWidthSuccess && yWidthSuccess && incAlongXSuccess && incAlongYSuccess)
	{
		amplRectRegion localRectRegion(centerPnt, xWidth, yWidth, incAlongX, incAlongY);
		myRectRegion.copyFromOther(localRectRegion);

		return true;
	}
	else
	{
		return false;
	}
}
