#pragma once
#include "stdafx.h"
#include "ui_exportToolpathAsGen1MachineCodeDialog2.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class exportToGen1MachineCodeDialog : public QDialog, private Ui::exportToGen1MachineCodeDialog2
{
	Q_OBJECT

public:
	exportToGen1MachineCodeDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~exportToGen1MachineCodeDialog(); //Destructor

	QString getDirectory(void);
	QString getPrefixName(void);
	float getMaxNumLinesPerFile(void);
	float getFeedRate(void);
	bool getTopToolSafeHeight(float &topToolSafeHeightOut);
	bool getBotToolSafeHeight(float &botToolSafeHeightOut);
	bool useModToolTipPoints(void);

protected:

private:
	QString currentDirectory = QDir::currentPath();
	QFileDialog *myFileExplorer = new QFileDialog(this);
	QStringList selectedDirectoryList;
	QString selectedDirectory;
	QString selectedPrefixName;

	Ui::exportToGen1MachineCodeDialog2 ui;

private slots:
	void clickedPickDirectoryButtonSlot(void);
};
