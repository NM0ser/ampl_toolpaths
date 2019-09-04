#include "stdafx.h"

#include "singleFeatureToolTipGenDialog.h"

singleFeatureToolTipGenDialog::singleFeatureToolTipGenDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(hemisphericalTopToolProfileRadioButton, SIGNAL(clicked()), this, SLOT(checkToolpathInterferenceCheckBox()));
	connect(hemisphericalBotToolProfileRadioButton, SIGNAL(clicked()), this, SLOT(checkToolpathInterferenceCheckBox()));
	connect(doubleRadiusTopToolProfileRadioButton, SIGNAL(clicked()), this, SLOT(checkToolpathInterferenceCheckBox()));
	connect(doubleRadiusBotToolProfileRadioButton, SIGNAL(clicked()), this, SLOT(checkToolpathInterferenceCheckBox()));
	connect(topToolConstZHeightCheckBox, SIGNAL(clicked()), this, SLOT(checkConstZHeightCheckBox()));
	connect(botToolConstZHeightCheckBox, SIGNAL(clicked()), this, SLOT(checkConstZHeightCheckBox()));
}

singleFeatureToolTipGenDialog::~singleFeatureToolTipGenDialog()
{
}

void singleFeatureToolTipGenDialog::initializeDialog(amplToolpath &amplToolpathIn)
{
	if (amplToolpathIn.myIncFormingMethodType == amplToolpath::incFormingMethodType::SPIF)
	{
		spifRadioButton->setChecked(true);
	}
	else if (amplToolpathIn.myIncFormingMethodType == amplToolpath::incFormingMethodType::TPIF)
	{
		tpifRadioButton->setChecked(true);
	}
	else if (amplToolpathIn.myIncFormingMethodType == amplToolpath::incFormingMethodType::DSIF)
	{
		dsifRadioButton->setChecked(true);
	}
	else if (amplToolpathIn.myIncFormingMethodType == amplToolpath::incFormingMethodType::ADSIF)
	{
		adsifRadioButton->setChecked(true);
		correctSelfInterferenceCheckBox->setChecked(false);
		correctSelfInterferenceCheckBox->setEnabled(false);
	}

	if(amplToolpathIn.topToolProfile == amplToolpath::toolProfile::hemispherical)
	{
		hemisphericalTopToolProfileRadioButton->setChecked(true);
	}
	else if (amplToolpathIn.topToolProfile == amplToolpath::toolProfile::flatTop)
	{
		doubleRadiusTopToolProfileRadioButton->setChecked(true);
	}

	if (amplToolpathIn.botToolProfile == amplToolpath::toolProfile::hemispherical)
	{
		hemisphericalBotToolProfileRadioButton->setChecked(true);
	}
	else if (amplToolpathIn.botToolProfile == amplToolpath::toolProfile::flatTop)
	{
		doubleRadiusBotToolProfileRadioButton->setChecked(true);
	}

	topToolDiamSpinBox->setValue(amplToolpathIn.topToolDiam);
	botToolDiamSpinBox->setValue(amplToolpathIn.botToolDiam);

	if (amplToolpathIn.topToolCornerRadiusActive())
	{
		topToolCornerRadiusSpinBox->setValue(amplToolpathIn.topToolCornerRad);
	}
	if (amplToolpathIn.botToolCornerRadiusActive())
	{
		botToolCornerRadiusSpinBox->setValue(amplToolpathIn.botToolCornerRad);
	}

	topToolConstZHeightCheckBox->setChecked(false);
	botToolConstZHeightCheckBox->setChecked(false);
}

void singleFeatureToolTipGenDialog::updateAmplToolpath(amplToolpath &amplToolpathIn, bool &checkSelfIntersection, int &constToolTipHeightState)
{
	if (hemisphericalTopToolProfileRadioButton->isChecked())
	{
		amplToolpathIn.topToolProfile = amplToolpath::toolProfile::hemispherical;
	}
	else if (doubleRadiusTopToolProfileRadioButton->isChecked())
	{
		amplToolpathIn.topToolProfile = amplToolpath::toolProfile::flatTop;
		amplToolpathIn.topToolCornerRad = topToolCornerRadiusSpinBox->value();
	}

	if (hemisphericalBotToolProfileRadioButton->isChecked())
	{
		amplToolpathIn.botToolProfile = amplToolpath::toolProfile::hemispherical;
	}
	else if (doubleRadiusBotToolProfileRadioButton->isChecked())
	{
		amplToolpathIn.botToolProfile = amplToolpath::toolProfile::flatTop;
		amplToolpathIn.botToolCornerRad = botToolCornerRadiusSpinBox->value();
	}

	amplToolpathIn.topToolDiam = topToolDiamSpinBox->value();
	amplToolpathIn.botToolDiam = botToolDiamSpinBox->value();

	checkSelfIntersection = correctSelfInterferenceCheckBox->isChecked();

	if (topToolConstZHeightCheckBox->isChecked() && botToolConstZHeightCheckBox->isChecked())
		constToolTipHeightState = 2;
	else if (topToolConstZHeightCheckBox->isChecked())
		constToolTipHeightState = 1;
	else if (botToolConstZHeightCheckBox->isChecked())
		constToolTipHeightState = -1;
	else
		constToolTipHeightState = 0;

	if (amplToolpathIn.topToolCornerRadiusActive()) // If bad input given for flatTop profile, switch it back to hemispherical
	{
		if (amplToolpathIn.topToolCornerRad >= (amplToolpathIn.topToolDiam / 2.0))
		{
			amplToolpathIn.topToolProfile = amplToolpath::toolProfile::hemispherical;
			amplToolpathIn.topToolCornerRad = amplToolpathIn.getUnassignedVal();
		}
	}

	if (amplToolpathIn.botToolCornerRadiusActive())
	{
		if (amplToolpathIn.botToolCornerRad >= (amplToolpathIn.botToolDiam / 2.0))
		{
			amplToolpathIn.botToolProfile = amplToolpath::toolProfile::hemispherical;
			amplToolpathIn.botToolCornerRad = amplToolpathIn.getUnassignedVal();
		}
	}
}

void singleFeatureToolTipGenDialog::checkConstZHeightCheckBox(void)
{
	if (topToolConstZHeightCheckBox->isChecked() && doubleRadiusTopToolProfileRadioButton->isCheckable())
	{
		hemisphericalTopToolProfileRadioButton->setChecked(true);
		doubleRadiusTopToolProfileRadioButton->setCheckable(false);
	}
	else if (!topToolConstZHeightCheckBox->isChecked() && !doubleRadiusTopToolProfileRadioButton->isCheckable())
	{
		doubleRadiusTopToolProfileRadioButton->setCheckable(true);
		doubleRadiusTopToolProfileRadioButton->setChecked(false);
	}

	if (botToolConstZHeightCheckBox->isChecked() && doubleRadiusBotToolProfileRadioButton->isCheckable())
	{
		hemisphericalBotToolProfileRadioButton->setChecked(true);
		doubleRadiusBotToolProfileRadioButton->setCheckable(false);
	}
	else if (!botToolConstZHeightCheckBox->isChecked() && !doubleRadiusBotToolProfileRadioButton->isCheckable())
	{
		doubleRadiusBotToolProfileRadioButton->setCheckable(true);
		doubleRadiusBotToolProfileRadioButton->setChecked(false);
	}
}

void singleFeatureToolTipGenDialog::checkToolpathInterferenceCheckBox(void)
{
	/*if (hemisphericalTopToolProfileRadioButton->isChecked() && hemisphericalBotToolProfileRadioButton->isChecked())
	{
		correctSelfInterferenceCheckBox->setEnabled(true);
	}
	else
	{
		correctSelfInterferenceCheckBox->setChecked(false);
		correctSelfInterferenceCheckBox->setEnabled(false);
	}*/
}