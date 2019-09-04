#pragma once
#include "stdafx.h"
#include "ui_rectRegionDefinitionDialog2.h"
#include "amplRectRegion.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class rectRegionDefinitionDialog : public QDialog, private Ui::rectRegionDefinitionDialog2
{
	Q_OBJECT

public:
	rectRegionDefinitionDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~rectRegionDefinitionDialog(); //Destructor

	bool getCenterPoint(gp_Pnt &centerPntOut);
	bool getXWidth(float &xWidthOut);
	bool getYWidth(float &yWidthOut);
	bool getIncAlongX(float &incAlongXOut);
	bool getIncAlongY(float &incAlongYOut);
	bool getRectRegion(amplRectRegion &rectRegionOut);

protected:

private:
	bool buildRectRegion(void);

	amplRectRegion myRectRegion;

	Ui::rectRegionDefinitionDialog2 ui;

	private slots:

};