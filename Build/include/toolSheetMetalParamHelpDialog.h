#pragma once
#include "stdafx.h"
#include "ui_toolSheetMetalParamHelpDialog.h"

#include <QtWidgets/QDialog>

class toolSheetMetalParamHelpDialog : public QDialog, private Ui::toolSheetMetalParamHelpDialog2
{
	Q_OBJECT

public:
	toolSheetMetalParamHelpDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~toolSheetMetalParamHelpDialog(); //Destructor

protected:

private:

	Ui::toolSheetMetalParamHelpDialog2 ui;

	private slots:

signals:
};
