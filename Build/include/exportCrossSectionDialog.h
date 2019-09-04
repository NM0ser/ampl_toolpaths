#pragma once
#include "stdafx.h"
#include "ui_exportCrossSectionPntsDialog2.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class exportCrossSectionDialog : public QDialog, private Ui::exportCrossSectionPntsDialog2
{
	Q_OBJECT

public:
	exportCrossSectionDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~exportCrossSectionDialog(); //Destructor

	QString getDirectory(void);
	QString getFileName(void);
	bool getBasePntOfPlane(gp_Pnt &basePntOut);
	bool getNormalDirOfPlane(gp_Dir &normalDirOut);
	bool getStartingPnt(gp_Pnt &startingPntOut);
	float getMaxDistBetweenPnts(void);

protected:

private:
	QString currentDirectory = QDir::currentPath();
	QFileDialog *myFileExplorer = new QFileDialog(this);
	QStringList selectedDirectoryList;
	QString selectedDirectory;
	QString selectedFileName;

	Ui::exportCrossSectionPntsDialog2 ui;

private slots:
	void clickedPickDirectoryButtonSlot(void);
};