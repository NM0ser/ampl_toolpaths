#include "stdafx.h"

#include "singFeatureToolpathInputDialog.h"

singFeatureToolpathInputDialog::singFeatureToolpathInputDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(firstTimeHelpPushButton, SIGNAL(clicked()), this, SLOT(showFirstTimeUserHelpDialogSlot()));
	connect(isfSetupHelpPushButton, SIGNAL(clicked()), this, SLOT(showIncSheetFormingInfoDialogSlot()));
	connect(toolingParamHelpPushButton, SIGNAL(clicked()), this, SLOT(showToolSheetMetalParamHelpDialogSlot()));
	connect(toolpathParamHelpPushButton, SIGNAL(clicked()), this, SLOT(showToolpathParamHelpDialogSlot()));

	connect(toolingParamAdvPushButton, SIGNAL(clicked()), this, SLOT(showToolingParamAdvDialogSlot()));
	connect(toolpathParamAdvPushButton, SIGNAL(clicked()), this, SLOT(showToolpathParamAdvDialogSlot()));

	connect(startPushButton, SIGNAL(clicked()), this, SLOT(clickedSingFeatureToolpathStartButtonSlot()));

	inputAmplToolpath = std::make_shared<amplToolpath>(); // Use default constructor of amplToolpath class
}

singFeatureToolpathInputDialog::~singFeatureToolpathInputDialog()
{
}

void singFeatureToolpathInputDialog::showFirstTimeUserHelpDialogSlot(void)
{
	myFirstTimeUserHelpDialog->show();
	myFirstTimeUserHelpDialog->raise();
	myFirstTimeUserHelpDialog->activateWindow();
}

void singFeatureToolpathInputDialog::showIncSheetFormingInfoDialogSlot(void)
{
	
	myIncSheetFormingInfoDialog->show();
	myIncSheetFormingInfoDialog->raise();
	myIncSheetFormingInfoDialog->activateWindow();
}

void singFeatureToolpathInputDialog::showToolSheetMetalParamHelpDialogSlot(void)
{
	myToolSheetMetalParamHelpDialog->show();
	myToolSheetMetalParamHelpDialog->raise();
	myToolSheetMetalParamHelpDialog->activateWindow();
}

void singFeatureToolpathInputDialog::showToolpathParamHelpDialogSlot(void)
{
	myToolpathParamHelpDialog->show();
	myToolpathParamHelpDialog->raise();
	myToolpathParamHelpDialog->activateWindow();
}

void singFeatureToolpathInputDialog::showToolingParamAdvDialogSlot(void)
{
	QMessageBox::information(this, QString("Advanced Features are in Development"), 
		QString("No Advanced Features Available at this Time"), QMessageBox::Ok, QMessageBox::Ok);
}

void singFeatureToolpathInputDialog::showToolpathParamAdvDialogSlot(void)
{
	if (myToolpathParamAdvancedDialog->exec())
	{
		advToolpathParamAccepted = true;
	}
}

void singFeatureToolpathInputDialog::clickedSingFeatureToolpathStartButtonSlot()
{
	// It's expected that the signal is emitted manually by the code that instantiates this object

	//emit clickedSingFeatureToolpathStartButtonSignal();
}

void singFeatureToolpathInputDialog::getLocalAmplToolpathClass(amplToolpath &amplToolpathIn)
{
	amplToolpathIn.copy(*inputAmplToolpath);
}

void singFeatureToolpathInputDialog::fillLocalAmplToolpathClass(void)
{
	inputAmplToolpath->toolpathIsActive = true; // Toolpath is active upon collecting user input

	if (spifRadioButton->isChecked())
	{
		inputAmplToolpath->myIncFormingMethodType = amplToolpath::incFormingMethodType::SPIF;
	}
	else if (tpifRadioButton->isChecked())
	{
		inputAmplToolpath->myIncFormingMethodType = amplToolpath::incFormingMethodType::TPIF;
	}
	else if (dsifRadioButton->isChecked())
	{
		inputAmplToolpath->myIncFormingMethodType = amplToolpath::incFormingMethodType::DSIF;
	}
	else if (adsifRadioButton->isChecked())
	{
		inputAmplToolpath->myIncFormingMethodType = amplToolpath::incFormingMethodType::ADSIF;
	}

	if (zLevelSlicingRadioButton->isChecked())
	{
		inputAmplToolpath->mytoolpathMethodType = amplToolpath::toolpathMethodType::contour;
	}
	else if (spiralToolpathRadioButton->isChecked())
	{
		inputAmplToolpath->mytoolpathMethodType = amplToolpath::toolpathMethodType::spiral;
	}

	if (negZFormingDirRadioButton->isChecked())
	{
		inputAmplToolpath->myFormingDirectionType = amplToolpath::formingDirectionType::negZDir;
	}
	else
	{
		inputAmplToolpath->myFormingDirectionType = amplToolpath::formingDirectionType::posZDir;
	}

	if (femaleDieShapeRadioButton->isChecked())
	{
		inputAmplToolpath->myTpifDieType = amplToolpath::tpifDieType::female;
	}
	else
	{
		inputAmplToolpath->myTpifDieType = amplToolpath::tpifDieType::male;
	}

	inputAmplToolpath->startDepth = startHeightSpinBox->value();
	inputAmplToolpath->endDepth = endHeightSpinBox->value();
	inputAmplToolpath->sheetThickness = sheetThickSpinBox->value();
	inputAmplToolpath->incDepth = incDepthSpinBox->value();
	inputAmplToolpath->topToolDiam = topToolDiamSpinBox->value();
	inputAmplToolpath->botToolDiam = botToolDiamSpinBox->value();
	inputAmplToolpath->sqzFactor = sqzFactorSpinBox->value();
	inputAmplToolpath->incToolpathCurve = resolToolpathCurveSpinBox->value();

	if (advToolpathParamAccepted)
	{
		if ((myToolpathParamAdvancedDialog->isGoingCCW()))
			inputAmplToolpath->goingCCW = true;
		else
			inputAmplToolpath->goingCCW = false;

		inputAmplToolpath->startAngleFromXAxisDeg = myToolpathParamAdvancedDialog->getStartingAngle();
		inputAmplToolpath->startRadialDistance = myToolpathParamAdvancedDialog->getStartingRadialDistance();
		inputAmplToolpath->adaptiveSlicingOn = myToolpathParamAdvancedDialog->getAdaptingZSlicingCheckBox();
		inputAmplToolpath->useFastSpiralApprox = myToolpathParamAdvancedDialog->getFastSpiralApproxCheckBox();
		inputAmplToolpath->keepDsifToolOnSheetBlank = myToolpathParamAdvancedDialog->getKeepDsifToolOnSheetBlank();
		inputAmplToolpath->removedCollinearContactPoints = myToolpathParamAdvancedDialog->getRemovedCollinearContactPoints();
		inputAmplToolpath->contourRampSkipPnts = myToolpathParamAdvancedDialog->getNumContourRampSkipPnts();
	}
}