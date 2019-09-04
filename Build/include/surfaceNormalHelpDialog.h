#pragma once
#include "stdafx.h"
#include "ui_surfaceNormalHelpDialog.h"

#include <QtWidgets/QDialog>

class surfaceNormalHelpDialog : public QDialog, private Ui::surfaceNormalHelpDialog2
{
	Q_OBJECT

public:
	surfaceNormalHelpDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~surfaceNormalHelpDialog(); //Destructor

protected:

private:

	Ui::surfaceNormalHelpDialog2 ui;

	private slots:

signals:

};
