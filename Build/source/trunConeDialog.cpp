#include "stdafx.h"

#include "trunConeDialog.h"

trunConeDialog::trunConeDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(createTrunConePushButton, SIGNAL(clicked()), this, SLOT(trunConeCreateSlotDialog()));
}

trunConeDialog::~trunConeDialog()
{
}

void trunConeDialog::trunConeCreateSlotDialog(void)
{
	if (makingPyramid)
	{
		//setWindowTitle("Create Pyramid");
		emit pyramidCreateButtonClicked();
	}
	else
	{
		//setWindowTitle("Create Cone");
		emit trunConeCreateButtonClicked();
	}
}

bool trunConeDialog::getMakingPyramid(void)
{
	return makingPyramid;
}

void trunConeDialog::setMakingPyramid(const bool &myBoolean)
{
	makingPyramid = myBoolean;
}

void trunConeDialog::setDialogTitle(const QString &winTitle)
{
	setWindowTitle(winTitle);
}

QString trunConeDialog::getBaseDiamLineEdit()
{
	return baseDiamLineEdit->text();
}

QString trunConeDialog::getWallAngleLineEdit()
{
	return wallAngleLineEdit->text();
}

QString trunConeDialog::getDepthLineEdit()
{
	return depthLineEdit->text();
}

QString trunConeDialog::getFilletRadLineEdit()
{
	return filletRadLineEdit->text();
}

void trunConeDialog::setDiameterLabel(const QString &labelStr)
{
	baseDiameterLabel->setText(labelStr);
}
