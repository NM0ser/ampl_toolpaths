#pragma once

#include "stdafx.h"
#include "ui_toolpathVisibilityDialog.h"
#include <QtWidgets/QDialog>

class toolpathVisibilityDialog : public QDialog, private Ui::toolpathVisibilityDialog2
{
	Q_OBJECT

public:
	enum toolpathName {TOP_CONTACT, BOT_CONTACT, TOP_TIP, BOT_TIP};
	enum comboBoxColors {None=0, Red=1, Green=2, Blue=3, Magenta=4, Cyan=5, Yellow=6, Purple=7, Orange=8, Black=9, White=10};

	toolpathVisibilityDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~toolpathVisibilityDialog(); //Destructor

	void buildToolpathRenderObject(toolpathName toolpathTypeIn, const std::vector< std::vector<float> > &pointsIn,
		TopoDS_Compound &topoCompoundIn, Handle(AIS_Shape) &aisToolpathIn, Handle(AIS_InteractiveContext) &myContextIn);

	bool showModPointsChecked(toolpathName toolpathTypeIn);

protected:

private:
	Ui::toolpathVisibilityDialog2 ui;

private slots:
	void toolpathVisibilityApplyDialogSlot(void);
	void toolpathVisibilityHideDialogSlot(void);

signals:
	void toolpathVisibilityApplyButtonPushed(bool);

};