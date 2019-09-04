#pragma once
#include "stdafx.h"
#include "ui_calc2SurfDeviationErrorDialog2.h"
#include "rectRegionDefinitionDialog.h"
#include "lineRegionDefinitionDialog.h"
#include "amplLineRegion.h"
#include "amplRectRegion.h"
#include "importIGSDialog.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class calc2SurfDeviationErrorDialog : public QDialog, private Ui::calc2SurfDeviationErrorDialog2
{
	Q_OBJECT

public:
	enum regionType {RECT, LINE};

	calc2SurfDeviationErrorDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~calc2SurfDeviationErrorDialog(); //Destructor

	QString getDirectory(void);
	QString getPrefixName(void);
	bool getSurf1(TopoDS_Compound &surf1Out) const;
	bool getSurf2(TopoDS_Compound &surf2Out) const;
	regionType getRegionType(void) const;
	bool getLineRegion(amplLineRegion &lineRegionOut) const;
	bool getRectRegion(amplRectRegion &rectRegionOut) const;

protected:

private:
	TopoDS_Compound surf1Compound;
	TopoDS_Compound surf2Compound;
	TopoDS_Compound surf1And2Compound;
	bool surf1ImportSuccess = false;
	bool surf2ImportSuccess = false;

	regionType myRegionType;
	amplLineRegion myLineRegion;
	amplRectRegion myRectRegion;
	bool regionDefinedSuccess = false;

	QString currentDirectory = QDir::currentPath();
	QFileDialog *myFileExplorer = new QFileDialog(this);
	QStringList selectedDirectoryList;
	QString selectedDirectory;
	QString selectedPrefixName;

	Ui::calc2SurfDeviationErrorDialog2 ui;

	static bool importIGS(QWidget *parent, TopoDS_Compound &surfOut);
	static bool importSTP(QWidget *parent, TopoDS_Compound &surfOut);

private slots:
	void importSurf1StpSlot(void); 
	void importSurf1IgsSlot(void);
	void importSurf2StpSlot(void);
	void importSurf2IgsSlot(void);
	void regionParamDefinitionSlot(void);
	void clickedPickDirectoryButtonSlot(void);
};