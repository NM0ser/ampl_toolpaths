#include "stdafx.h"

#include "scaleDialog.h"

scaleDialog::scaleDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(ScalePushButton, SIGNAL(clicked()), this, SLOT(scalePartSlotDialog()));
}

scaleDialog::~scaleDialog()
{
}

void scaleDialog::scalePartSlotDialog(void)
{
	emit scaleDialogButtonClicked();
}

QString scaleDialog::getXLineEdit(void)
{
	return XLineEdit->text();
}

QString scaleDialog::getYLineEdit(void)
{
	return YLineEdit->text();
}

QString scaleDialog::getZLineEdit(void)
{
	return ZLineEdit->text();
}

QString scaleDialog::getScaleFactorLineEdit(void)
{
	return ScaleFactorLineEdit->text();
}