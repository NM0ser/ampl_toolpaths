#pragma once
#include "stdafx.h"
#include "ui_trunConeDialog.h"
#include <QtWidgets/QDialog>

class trunConeDialog : public QDialog, private Ui::trunConeDialog
{
	Q_OBJECT

public:
	trunConeDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~trunConeDialog(); //Destructor

	QString getBaseDiamLineEdit(void);
	QString getWallAngleLineEdit(void);
	QString getDepthLineEdit(void);
	QString getFilletRadLineEdit(void);

	bool getMakingPyramid(void);
	void setMakingPyramid(const bool &myBoolean);
	void setDialogTitle(const QString &winTitle);
	void setDiameterLabel(const QString &labelStr);

protected:

private:
	bool makingPyramid = false;

	Ui::trunConeDialog ui;

public slots:
	void trunConeCreateSlotDialog(void);

signals:
	void trunConeCreateButtonClicked(void);
	void pyramidCreateButtonClicked(void);

};