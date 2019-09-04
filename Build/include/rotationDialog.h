#pragma once
#include "stdafx.h"
#include "ui_rotationDialog.h"
#include <QtWidgets/QDialog>

class rotationDialog : public QDialog, private Ui::rotationDialog
{
	Q_OBJECT

public:
	rotationDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~rotationDialog(); //Destructor

	QString getXPtLineEdit(void);
	QString getYPtLineEdit(void);
	QString getZPtLineEdit(void);
	QString getXDirLineEdit(void);
	QString getYDirLineEdit(void);
	QString getZDirLineEdit(void);
	QString getAngleLineEdit(void);

protected:

private:
	Ui::rotationDialog ui;

public slots:
	void rotatePartSlotDialog(void);

signals:
	void rotateDialogButtonClicked(void);

};