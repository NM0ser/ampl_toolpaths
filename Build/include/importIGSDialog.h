#pragma once
#include "stdafx.h"
#include "ui_importIGSDialog.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class importIGSDialog : public QDialog, private Ui::importIGSDialog
{
	Q_OBJECT

public:
	importIGSDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~importIGSDialog(); //Destructor

	QString getFilePath(void);
	QString getSewingTolStr(void);
	bool getCheckBoxState(void);
	void changeWindowTitle(QString nameIn);

	void setFileFilterToSTEP(bool boolIn);

protected:

private:
	QStringList selectedFile;

	QFileDialog *myFileExplorer = new QFileDialog(this);

	Ui::importIGSDialog ui;

	bool pickSTEPFiles = false;

private slots:
	void clickedPickDirectoryButtonSlot(void);
};