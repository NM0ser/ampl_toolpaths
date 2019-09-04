#include "stdafx.h"

#include "clipPlaneDialog.h"

clipPlaneDialog::clipPlaneDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(clippingOnPushButton, SIGNAL(clicked()), this, SLOT(clippingOnButtonClickedSlot()));
	connect(clippingOffPushButton, SIGNAL(clicked()), this, SLOT(clippingOffButtonClickedSlot()));
	connect(reversePushButton, SIGNAL(clicked()), this, SLOT(reversePlaneButtonClickedSlot()));
}

clipPlaneDialog::~clipPlaneDialog()
{

}

QString clipPlaneDialog::getXPtLineEdit(void)
{
	return basePntXLineEdit->text();
}

QString clipPlaneDialog::getYPtLineEdit(void)
{
	return basePntYLineEdit->text();
}

QString clipPlaneDialog::getZPtLineEdit(void)
{
	return basePntZLineEdit->text();
}

QString clipPlaneDialog::getXDirLineEdit(void)
{
	return normalVecXLineEdit->text();
}

QString clipPlaneDialog::getYDirLineEdit(void)
{
	return normalVecYLineEdit->text();
}

QString clipPlaneDialog::getZDirLineEdit(void)
{
	return normalVecZLineEdit->text();
}

void clipPlaneDialog::clippingOnButtonClickedSlot(void)
{
	clippingOn = true;
	emit clippingPlaneButtonClickedSignal();
}

void clipPlaneDialog::clippingOffButtonClickedSlot(void)
{
	clippingOn = false;
	emit clippingPlaneButtonClickedSignal();
}

void clipPlaneDialog::reversePlaneButtonClickedSlot(void)
{
	QString xDirStr = getXDirLineEdit().trimmed();
	QString yDirStr = getYDirLineEdit().trimmed();
	QString zDirStr = getZDirLineEdit().trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;

	xDirStr.toFloat(&str2floatOK1);
	yDirStr.toFloat(&str2floatOK2);
	zDirStr.toFloat(&str2floatOK3);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3)
		return;

	Standard_Real xDirRev = -1*(xDirStr.toFloat());
	Standard_Real yDirRev = -1*(yDirStr.toFloat());
	Standard_Real zDirRev = -1*(zDirStr.toFloat());

	normalVecXLineEdit->setText(QString::number(xDirRev));
	normalVecYLineEdit->setText(QString::number(yDirRev));
	normalVecZLineEdit->setText(QString::number(zDirRev));

	if (reversePlane)
		reversePlane = false;
	else
		reversePlane = true;

	clippingOn = true;
	emit clippingPlaneButtonClickedSignal();
}

bool clipPlaneDialog::getIsClippingOn(void)
{
	return clippingOn;
}

bool clipPlaneDialog::getIsPlaneReversed(void)
{
	return reversePlane;
}