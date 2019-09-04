#pragma once
#include "stdafx.h"
#include "ui_hotkeysDialog.h"
#include <QtWidgets/QDialog>

class hotkeysDialog : public QDialog, private Ui::hotkeysDialog
{
	Q_OBJECT

public:
	hotkeysDialog(QWidget *parent = Q_NULLPTR); //Constructor
	//hotkeysDialog::~hotkeysDialog(); //Destructor

protected:

private:
	Ui::hotkeysDialog ui;
};