#pragma once
#include "stdafx.h"
#include "ui_incSheetFormingInfoDialog.h"

#include <QtWidgets/QDialog>

class incSheetFormingInfoDialog : public QDialog, private Ui::incSheetFormingInfoDialog
{
	Q_OBJECT

public:
	incSheetFormingInfoDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~incSheetFormingInfoDialog(); //Destructor

protected:

private:

	Ui::incSheetFormingInfoDialog ui;

private slots:

signals:
};
