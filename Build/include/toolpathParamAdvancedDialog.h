#pragma once
#include "stdafx.h"

#include "ui_toolpathParametersAdvancedDialog.h"
#include <QtWidgets/QDialog>

class toolpathParamAdvancedDialog : public QDialog, public Ui::toolpathParametersAdvancedDialog
{
	Q_OBJECT

public:
	toolpathParamAdvancedDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~toolpathParamAdvancedDialog(); //Destructor

	bool isGoingCCW(void);
	float getStartingAngle(void);
	float getStartingRadialDistance(void);
	bool getAdaptingZSlicingCheckBox(void);
	bool getFastSpiralApproxCheckBox(void);
	bool getKeepDsifToolOnSheetBlank(void);
	bool getRemovedCollinearContactPoints(void);
	int getNumContourRampSkipPnts(void);

protected:

private:
	//Ui::toolpathParametersAdvancedDialog ui;

signals:

};