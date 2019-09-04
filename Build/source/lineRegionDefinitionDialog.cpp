#include "stdafx.h"
#include "lineRegionDefinitionDialog.h"

lineRegionDefinitionDialog::lineRegionDefinitionDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);
}

lineRegionDefinitionDialog::~lineRegionDefinitionDialog()
{

}

bool lineRegionDefinitionDialog::getStartPoint(gp_Pnt &startPntOut)
{
	QString xPntStr = (xStartPntLineEdit->text()).trimmed();
	QString yPntStr = (yStartPntLineEdit->text()).trimmed();
	QString zPntStr = (zStartPntLineEdit->text()).trimmed();

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

	startPntOut = gp_Pnt(xPnt, yPnt, zPnt);
	return true;
}

bool lineRegionDefinitionDialog::getEndPoint(gp_Pnt &endPntOut)
{
	QString xPntStr = (xEndPntLineEdit->text()).trimmed();
	QString yPntStr = (yEndPntLineEdit->text()).trimmed();
	QString zPntStr = (zEndPntLineEdit->text()).trimmed();

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

	endPntOut = gp_Pnt(xPnt, yPnt, zPnt);
	return true;
}

bool lineRegionDefinitionDialog::getIncAlongLine(float &incOut)
{
	incOut = xIncSpinBox->value();
	return true;
}

bool lineRegionDefinitionDialog::getLineRegion(amplLineRegion &lineRegionOut)
{
	bool buildLineRegionSuccess = buildLineRegion();
	if (buildLineRegionSuccess)
	{
		lineRegionOut.copyFromOther(myLineRegion);
	}

	return buildLineRegionSuccess;
}

bool lineRegionDefinitionDialog::buildLineRegion(void)
{
	gp_Pnt localStartPnt, localEndPnt;
	float localInc;

	bool startPointSuccess = getStartPoint(localStartPnt);
	bool endPointSuccess = getEndPoint(localEndPnt);
	bool incAlongLineSuccess = getIncAlongLine(localInc);

	if (startPointSuccess && endPointSuccess && incAlongLineSuccess)
	{
		amplLineRegion localLineRegion(localStartPnt, localEndPnt, localInc);
		myLineRegion.copyFromOther(localLineRegion);
		return true;
	}
	else
	{
		return false;
	}
}