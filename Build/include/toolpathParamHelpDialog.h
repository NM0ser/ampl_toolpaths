#pragma once
#include "stdafx.h"
#include "ui_toolpathParamHelpDialog.h"

#include <QtWidgets/QDialog>

class toolpathParamHelpDialog : public QDialog, private Ui::toolpathParamHelpDialog2
{
	Q_OBJECT

public:
	toolpathParamHelpDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~toolpathParamHelpDialog(); //Destructor

protected:

private:

	Ui::toolpathParamHelpDialog2 ui;

	private slots:

signals:
};
