#pragma once
#include "stdafx.h"
#include "ui_exportIGSDialog.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class exportIGSDialog : public QDialog, private Ui::exportIGSDialog
{
	Q_OBJECT

public:
	exportIGSDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~exportIGSDialog(); //Destructor

	QString getDirectory(void);
	QString getIGSFileName(void);
	QString getSTEPFileName(void);
	void changeWindowTitle(QString nameIn);
	void changeFileNameText(QString nameIn);

protected:

private:
	QString currentDirectory = QDir::currentPath();
	QStringList selectedDirectoryList;
	QString selectedDirectory;
	QString selectedFileName;

	QFileDialog *myFileExplorer = new QFileDialog(this);

	Ui::exportIGSDialog ui;

private slots:
	void clickedPickDirectoryButtonSlot(void);

};