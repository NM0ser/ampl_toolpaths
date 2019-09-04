#include "stdafx.h"
#include "toolpathParamAdvancedDialog.h"

toolpathParamAdvancedDialog::toolpathParamAdvancedDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	toolDirectionCCWRadio->setChecked(true);
}

toolpathParamAdvancedDialog::~toolpathParamAdvancedDialog()
{

}

bool toolpathParamAdvancedDialog::isGoingCCW(void)
{
	if (toolDirectionCCWRadio->isChecked())
		return true;
	else
		return false;
}

float toolpathParamAdvancedDialog::getStartingAngle(void)
{
	return startAngleSpinBox->value();
}

float toolpathParamAdvancedDialog::getStartingRadialDistance(void)
{
	return startingDistanceSpinBox->value();
}

bool toolpathParamAdvancedDialog::getAdaptingZSlicingCheckBox(void)
{
	return adaptingZSlicingCheckBox->isChecked();
}

bool toolpathParamAdvancedDialog::getFastSpiralApproxCheckBox(void)
{
	return fastSpiralApproxCheckBox->isChecked();
}

bool toolpathParamAdvancedDialog::getKeepDsifToolOnSheetBlank(void)
{
	return keepDsifToolOnSheetBlankCheckBox->isChecked();
}

bool toolpathParamAdvancedDialog::getRemovedCollinearContactPoints(void)
{
	return removeCollinearPointsCheckBox->isChecked();
}

int toolpathParamAdvancedDialog::getNumContourRampSkipPnts(void)
{
	return contourLinearRampSpinBox->value();
}