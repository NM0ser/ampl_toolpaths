#pragma once
#include "stdafx.h"

#include "ui_singFeatureToolpathInputDialog.h"
#include <QtWidgets/QDialog>

#include "firstTimeUserHelpDialog.h"
#include "incSheetFormingInfoDialog.h"
#include "toolpathParamHelpDialog.h"
#include "toolSheetMetalParamHelpDialog.h"
#include "toolpathParamAdvancedDialog.h"

#include "amplToolpath.h"

#include <QMessageBox>

class singFeatureToolpathInputDialog : public QDialog, public Ui::singFeatureToolpathInputDialog
{
	Q_OBJECT

public:
	singFeatureToolpathInputDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~singFeatureToolpathInputDialog(); //Destructor

	void fillLocalAmplToolpathClass(void);
	void getLocalAmplToolpathClass(amplToolpath &amplToolpathIn);

	toolpathParamAdvancedDialog *myToolpathParamAdvancedDialog = new toolpathParamAdvancedDialog(this);
	bool advToolpathParamAccepted = false;

protected:
	
private:
	firstTimeUserHelpDialog *myFirstTimeUserHelpDialog = new firstTimeUserHelpDialog(this);
	incSheetFormingInfoDialog *myIncSheetFormingInfoDialog = new incSheetFormingInfoDialog(this);
	toolpathParamHelpDialog *myToolpathParamHelpDialog = new toolpathParamHelpDialog(this);
	toolSheetMetalParamHelpDialog *myToolSheetMetalParamHelpDialog = new toolSheetMetalParamHelpDialog(this);
	
	//Ui::singFeatureToolpathInputDialog ui;

	// Local copy of amplToolpath class
	std::shared_ptr<amplToolpath> inputAmplToolpath;

private slots:
	void showFirstTimeUserHelpDialogSlot(void);
	void showIncSheetFormingInfoDialogSlot(void);
	void showToolSheetMetalParamHelpDialogSlot(void);
	void showToolpathParamHelpDialogSlot(void);

	void showToolpathParamAdvDialogSlot(void);
	void showToolingParamAdvDialogSlot(void);

	void clickedSingFeatureToolpathStartButtonSlot(void);

signals:
	void clickedSingFeatureToolpathStartButtonSignal(void);
};