#include "stdafx.h"

#include "hotkeysDialog.h"

hotkeysDialog::hotkeysDialog(QWidget *parent) : 
	QDialog(parent)
{
	setupUi(this);
	//setWindowFlags(Qt::FramelessWindowHint);
	//setAttribute(Qt::WA_TranslucentBackground);
}