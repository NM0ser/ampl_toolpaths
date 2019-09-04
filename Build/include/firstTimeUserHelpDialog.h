#pragma once
#include "stdafx.h"
#include "ui_firstTimeUserHelpDialog.h"

#include <QtWidgets/QDialog>

class firstTimeUserHelpDialog : public QDialog, private Ui::firstTimeUserHelpDialog2
{
	Q_OBJECT

public:
	firstTimeUserHelpDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~firstTimeUserHelpDialog(); //Destructor

protected:

private:

	Ui::firstTimeUserHelpDialog2 ui;

private slots:

signals:

};