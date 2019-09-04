#pragma once
#include "stdafx.h"
#include "ui_openAmplToolpath.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class openAmplToolpathDialog : public QDialog, private Ui::openAmplToolpathDialog2
{
	Q_OBJECT

public:
	openAmplToolpathDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~openAmplToolpathDialog(); //Destructor

	QString getFilePath(void);

protected:

private:
	QStringList selectedFile;

	QFileDialog *myFileExplorer = new QFileDialog(this);

	Ui::openAmplToolpathDialog2 ui;

	private slots:
	void clickedPickDirectoryButtonSlot(void);

};