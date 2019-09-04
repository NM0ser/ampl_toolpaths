#include "stdafx.h"

#include "translateDialog.h"

translateDialog::translateDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(TranslatePushButton, SIGNAL(clicked()), this, SLOT(translatePartSlotDialog()));
}

translateDialog::~translateDialog()
{
}

void translateDialog::translatePartSlotDialog(void)
{
	emit translateDialogButtonClicked();
}

QString translateDialog::getXLineEdit(void)
{
	return XLineEdit->text();
}

QString translateDialog::getYLineEdit(void)
{
	return YLineEdit->text();
}

QString translateDialog::getZLineEdit(void)
{
	return ZLineEdit->text();
}

QString translateDialog::getTransFactorLineEdit(void)
{
	return TranslateDistLineEdit->text();
}
