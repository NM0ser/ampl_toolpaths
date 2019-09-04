#pragma once
#include "stdafx.h"
#include "ui_exportAmplToolpath.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class exportAmplToolpathDialog : public QDialog, private Ui::exportAmplToolpathDialog2
{
	Q_OBJECT

public:
	exportAmplToolpathDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~exportAmplToolpathDialog(); //Destructor

	QString getDirectory(void);
	QString getPrefixName(void);

	bool topToolTipPointsCheckBoxChecked(void);
	bool botToolTipPointsCheckBoxChecked(void);
	bool topContactPointsCheckBoxChecked(void);
	bool botContactPointsCheckBoxChecked(void);
	bool normalVectorCheckBoxChecked(void);
	bool genToolpathInfoCheckBoxChecked(void);

protected:

private:
	QString currentDirectory = QDir::currentPath();
	QStringList selectedDirectoryList;
	QString selectedDirectory;
	QString selectedFileName;

	QFileDialog *myFileExplorer = new QFileDialog(this);

	Ui::exportAmplToolpathDialog2 ui;

private slots:
	void clickedPickDirectoryButtonSlot(void);

};