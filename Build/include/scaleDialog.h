#pragma once
#include "stdafx.h"
#include "ui_scaleDialog.h"
#include <QtWidgets/QDialog>

class scaleDialog : public QDialog, private Ui::scaleDialog
{
	Q_OBJECT

public:
	scaleDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~scaleDialog(); //Destructor

	QString getXLineEdit(void);
	QString getYLineEdit(void);
	QString getZLineEdit(void);
	QString getScaleFactorLineEdit(void);

protected:
	
private:
	Ui::scaleDialog ui;

public slots:
	void scalePartSlotDialog(void);

signals:
	void scaleDialogButtonClicked(void);
};