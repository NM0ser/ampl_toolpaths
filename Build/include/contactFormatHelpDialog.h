#pragma once
#include "stdafx.h"
#include "ui_ContactFormatHelpDialog.h"

#include <QtWidgets/QDialog>

class contactFormatHelpDialog : public QDialog, private Ui::ContactFormatHelpDialog2
{
	Q_OBJECT

public:
	contactFormatHelpDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~contactFormatHelpDialog(); //Destructor

protected:

private:

	Ui::ContactFormatHelpDialog2 ui;

private slots:

signals:

};
