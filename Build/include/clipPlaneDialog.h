#pragma once
#include "stdafx.h"
#include "ui_clippingPlaneDialog.h"
#include <QtWidgets/QDialog>

class clipPlaneDialog : public QDialog, private Ui::clippingPlaneDialog
{
	Q_OBJECT

public:
	clipPlaneDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~clipPlaneDialog(); //Destructor

	QString getXPtLineEdit(void);
	QString getYPtLineEdit(void);
	QString getZPtLineEdit(void);
	QString getXDirLineEdit(void);
	QString getYDirLineEdit(void);
	QString getZDirLineEdit(void);

	bool getIsClippingOn(void);
	bool getIsPlaneReversed(void);

protected:

private:
	Ui::clippingPlaneDialog ui;

	bool clippingOn = false;
	bool reversePlane = false;

public slots:
	void clippingOnButtonClickedSlot(void);
	void clippingOffButtonClickedSlot(void);
	void reversePlaneButtonClickedSlot(void);

signals:
	void clippingPlaneButtonClickedSignal(void);
};