#include "stdafx.h"

#include "funnelDialog.h"

funnelDialog::funnelDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(createFunnelPushButton, SIGNAL(clicked()), this, SLOT(funnelCreateSlotDialog()));
}

funnelDialog::~funnelDialog()
{
}

void funnelDialog::funnelCreateSlotDialog(void)
{
	emit funnelCreateButtonClicked();
}

QString funnelDialog::getBaseDiamLineEdit(void)
{
	return baseDiamLineEdit->text();
}

QString funnelDialog::getInitWallAngleLineEdit(void)
{
	return initWallAngleLineEdit->text();
}

QString funnelDialog::getDepthLineEdit(void)
{
	return depthLineEdit->text();
}

QString funnelDialog::getRadOfArcLineEdit(void)
{
	return radOfArcLineEdit->text();
}

QString funnelDialog::getFilletRadLineEdit(void)
{
	return filletRadLineEdit->text();
}
