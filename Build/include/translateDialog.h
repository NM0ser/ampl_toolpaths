#pragma once
#include "stdafx.h"
#include "ui_translateDialog.h"
#include <QtWidgets/QDialog>

class translateDialog : public QDialog, private Ui::translateDialog
{
	Q_OBJECT

public:
	translateDialog::translateDialog(QWidget *parent = Q_NULLPTR); //Constructor
	translateDialog::~translateDialog(); //Destructor

	QString getXLineEdit(void);
	QString getYLineEdit(void);
	QString getZLineEdit(void);
	QString getTransFactorLineEdit(void);

protected:

private:
	Ui::translateDialog ui;

public slots:
	void translatePartSlotDialog(void);

signals:
	void translateDialogButtonClicked(void);

};