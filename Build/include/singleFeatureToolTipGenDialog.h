#pragma once
#include "stdafx.h"

#include "ui_singFeatureToolTipGenDialog.h"
#include <QtWidgets/QDialog>
#include <QMessageBox>
#include "amplToolpath.h"

class singleFeatureToolTipGenDialog : public QDialog, private Ui::singleFeatureToolTipGenDialog
{
	Q_OBJECT

public:
	singleFeatureToolTipGenDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~singleFeatureToolTipGenDialog(); //Destructor

	void initializeDialog(amplToolpath &amplToolpathIn);
	void updateAmplToolpath(amplToolpath &amplToolpathIn, bool &checkSelfIntersection, int &constToolTipHeightState);

protected:

private:
	Ui::singleFeatureToolTipGenDialog ui;

private slots:
	void checkToolpathInterferenceCheckBox(void);
	void checkConstZHeightCheckBox(void);

signals:

};