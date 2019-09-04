#pragma once
#include "stdafx.h"
#include "ui_lineRegionDefinitionDialog2.h"
#include "amplLineRegion.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class lineRegionDefinitionDialog : public QDialog, private Ui::lineRegionDefinitionDialog2
{
	Q_OBJECT

public:
	lineRegionDefinitionDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~lineRegionDefinitionDialog(); //Destructor

	bool getStartPoint(gp_Pnt &startPntOut);
	bool getEndPoint(gp_Pnt &endPntOut);
	bool getIncAlongLine(float &incOut);
	bool getLineRegion(amplLineRegion &lineRegionOut);

protected:

private:
	bool buildLineRegion(void);

	amplLineRegion myLineRegion;

	Ui::lineRegionDefinitionDialog2 ui;

private slots:

};