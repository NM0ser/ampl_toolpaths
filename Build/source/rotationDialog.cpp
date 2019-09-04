#include "stdafx.h"

#include "rotationDialog.h"

rotationDialog::rotationDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(RotatePushButton, SIGNAL(clicked()), this, SLOT(rotatePartSlotDialog()));
}

rotationDialog::~rotationDialog()
{
}

void rotationDialog::rotatePartSlotDialog(void)
{
	emit rotateDialogButtonClicked();
}

QString rotationDialog::getXPtLineEdit(void)
{
	return XBasePtLineEdit->text();
}

QString rotationDialog::getYPtLineEdit(void)
{
	return YBasePtLineEdit->text();
}

QString rotationDialog::getZPtLineEdit(void)
{
	return ZBasePtLineEdit->text();
}

QString rotationDialog::getXDirLineEdit(void)
{
	return XRotAxisDirLineEdit->text();
}

QString rotationDialog::getYDirLineEdit(void)
{
	return YRotAxisDirLineEdit->text();
}

QString rotationDialog::getZDirLineEdit(void)
{
	return ZRotAxisDirLineEdit->text();
}

QString rotationDialog::getAngleLineEdit(void)
{
	return RotAngleLineEdit->text();
}

