#pragma once
#include "stdafx.h"
#include "ui_saveAmplToolpath.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class saveAmplToolpathDialog : public QDialog, private Ui::saveAmplToolpathDialog2
{
	Q_OBJECT

public:
	saveAmplToolpathDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~saveAmplToolpathDialog(); //Destructor

	QString getDirectory(void);
	QString getFileName(void);

protected:

private:
	QString currentDirectory = QDir::currentPath();
	QStringList selectedDirectoryList;
	QString selectedDirectory;
	QString selectedFileName;

	QFileDialog *myFileExplorer = new QFileDialog(this);

	Ui::saveAmplToolpathDialog2 ui;

	private slots:
	void clickedPickDirectoryButtonSlot(void);

};