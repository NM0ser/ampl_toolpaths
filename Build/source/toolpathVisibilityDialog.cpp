#include "stdafx.h"
#include "toolpathVisibilityDialog.h"

toolpathVisibilityDialog::toolpathVisibilityDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(applyPushButton, SIGNAL(clicked()), this, SLOT(toolpathVisibilityApplyDialogSlot()));
	connect(hideAllPushButton, SIGNAL(clicked()), this, SLOT(toolpathVisibilityHideDialogSlot()));

	topToolContactPntsRadio->setChecked(true);
	botToolContactPntsRadio->setChecked(true);
	showTopToolTipsModCheckBox->setChecked(true);
	showBotToolTipsModCheckBox->setChecked(true);
	topToolTipLinesRadio->setChecked(true);
	botToolTipLinesRadio->setChecked(true);
	topToolContactPntsCombo->setCurrentIndex(comboBoxColors::Blue);
	topToolTipPntsCombo->setCurrentIndex(comboBoxColors::Cyan);
	botToolContactPntsCombo->setCurrentIndex(comboBoxColors::Red);
	botToolTipPntsCombo->setCurrentIndex(comboBoxColors::Magenta);
}

toolpathVisibilityDialog::~toolpathVisibilityDialog()
{

}

void toolpathVisibilityDialog::toolpathVisibilityApplyDialogSlot()
{
	emit toolpathVisibilityApplyButtonPushed(false);
}

void toolpathVisibilityDialog::toolpathVisibilityHideDialogSlot()
{
	emit toolpathVisibilityApplyButtonPushed(true);
}

void toolpathVisibilityDialog::buildToolpathRenderObject(toolpathName toolpathTypeIn, const std::vector< std::vector<float> > &pointsIn,
	TopoDS_Compound &topoCompoundIn, Handle(AIS_Shape) &aisToolpathIn, Handle(AIS_InteractiveContext) &myContextIn)
{
	bool pointsTrue;
	bool linesTrue;
	bool pointsLinesTrue;
	int activeColorIndex;
	Quantity_NameOfColor activeColor;

	if (toolpathTypeIn == toolpathName::TOP_CONTACT)
	{
		if (topToolContactPntsCombo->currentIndex() == 0)
		{
			myContextIn->Remove(aisToolpathIn);
			aisToolpathIn.Nullify();
			topoCompoundIn.Nullify();
			return;
		}

		pointsTrue = topToolContactPntsRadio->isChecked();
		linesTrue = topToolContactLinesRadio->isChecked();
		pointsLinesTrue = topToolContactPntsLinesRadio->isChecked();
		activeColorIndex = topToolContactPntsCombo->currentIndex();
	}
	else if (toolpathTypeIn == toolpathName::BOT_CONTACT)
	{
		if (botToolContactPntsCombo->currentIndex() == 0)
		{
			myContextIn->Remove(aisToolpathIn);
			aisToolpathIn.Nullify();
			topoCompoundIn.Nullify();
			return;
		}

		pointsTrue = botToolContactPntsRadio->isChecked();
		linesTrue = botToolContactLinesRadio->isChecked();
		pointsLinesTrue = botToolContactPntsLinesRadio->isChecked();
		activeColorIndex = botToolContactPntsCombo->currentIndex();
	}
	else if (toolpathTypeIn == toolpathName::TOP_TIP)
	{
		if (topToolTipPntsCombo->currentIndex() == 0)
		{
			myContextIn->Remove(aisToolpathIn);
			aisToolpathIn.Nullify();
			topoCompoundIn.Nullify();
			return;
		}

		pointsTrue = topToolTipPntsRadio->isChecked();
		linesTrue = topToolTipLinesRadio->isChecked();
		pointsLinesTrue = topToolTipPntsLinesRadio->isChecked();
		activeColorIndex = topToolTipPntsCombo->currentIndex();
	}
	else if (toolpathTypeIn == toolpathName::BOT_TIP)
	{
		if (botToolTipPntsCombo->currentIndex() == 0)
		{
			myContextIn->Remove(aisToolpathIn);
			aisToolpathIn.Nullify();
			topoCompoundIn.Nullify();
			return;
		}

		pointsTrue = botToolTipPntsRadio->isChecked();
		linesTrue = botToolTipLinesRadio->isChecked();
		pointsLinesTrue = botToolTipPntsLinesRadio->isChecked();
		activeColorIndex = botToolTipPntsCombo->currentIndex();
	}

	switch (activeColorIndex)
	{
	case comboBoxColors::Red:
	{
		activeColor = Quantity_NOC_RED1;
		break;
	}
	case comboBoxColors::Green:
	{
		activeColor = Quantity_NOC_GREEN1;
		break;
	}
	case comboBoxColors::Blue:
	{
		activeColor = Quantity_NOC_BLUE1;
		break;
	}
	case comboBoxColors::Magenta:
	{
		activeColor = Quantity_NOC_MAGENTA1;
		break;
	}
	case comboBoxColors::Cyan:
	{
		activeColor = Quantity_NOC_CYAN1;
		break;
	}
	case comboBoxColors::Yellow:
	{
		activeColor = Quantity_NOC_YELLOW1;
		break;
	}
	case comboBoxColors::Purple:
	{
		activeColor = Quantity_NOC_PURPLE1;
		break;
	}
	case comboBoxColors::Orange:
	{
		activeColor = Quantity_NOC_ORANGE1;
		break;
	}
	case comboBoxColors::Black:
	{
		activeColor = Quantity_NOC_BLACK;
		break;
	}
	case comboBoxColors::White:
	{
		activeColor = Quantity_NOC_WHITE;
		break;
	}
	}
	
	if (!aisToolpathIn.IsNull())
	{
		myContextIn->Remove(aisToolpathIn);
		aisToolpathIn.Nullify();
		topoCompoundIn.Nullify();
	}

	if (pointsTrue)
	{
		BRep_Builder compoundBuilder;
		compoundBuilder.MakeCompound(topoCompoundIn);
		Standard_Integer arrLen = pointsIn.size();
		for (int m = 0; m < arrLen; m++)
		{
			gp_Pnt localPnt((pointsIn.at(m)).at(0), (pointsIn.at(m)).at(1), (pointsIn.at(m)).at(2));
			TopoDS_Vertex localVertex = BRepBuilderAPI_MakeVertex(localPnt);
			compoundBuilder.Add(topoCompoundIn, localVertex);
		}
		aisToolpathIn = new AIS_Shape(topoCompoundIn);
		aisToolpathIn->SetColor(activeColor);
		myContextIn->Display(aisToolpathIn);
	}
	else if (linesTrue)
	{
		BRep_Builder compoundBuilder;
		compoundBuilder.MakeCompound(topoCompoundIn);
		Standard_Integer arrLen = pointsIn.size();
		for (int m = 1; m < arrLen; m++)
		{
			gp_Pnt localPnt0((pointsIn.at(m - 1)).at(0), (pointsIn.at(m - 1)).at(1), (pointsIn.at(m - 1)).at(2));
			gp_Pnt localPnt1((pointsIn.at(m)).at(0), (pointsIn.at(m)).at(1), (pointsIn.at(m)).at(2));
			if (localPnt0.Distance(localPnt1) < 0.002)
				continue;
			TopoDS_Edge localEdge = BRepBuilderAPI_MakeEdge(localPnt0, localPnt1);
			compoundBuilder.Add(topoCompoundIn, localEdge);
		}
		aisToolpathIn = new AIS_Shape(topoCompoundIn);
		aisToolpathIn->SetColor(activeColor);
		myContextIn->Display(aisToolpathIn);
	}
	else // pointsLinesTrue
	{
		BRep_Builder compoundBuilder;
		compoundBuilder.MakeCompound(topoCompoundIn);
		Standard_Integer arrLen = pointsIn.size();
		for (int m = 1; m < arrLen; m++)
		{
			gp_Pnt localPnt0((pointsIn.at(m - 1)).at(0), (pointsIn.at(m - 1)).at(1), (pointsIn.at(m - 1)).at(2));
			gp_Pnt localPnt1((pointsIn.at(m)).at(0), (pointsIn.at(m)).at(1), (pointsIn.at(m)).at(2));
			if (localPnt0.Distance(localPnt1) < 0.002)
				continue;
			TopoDS_Edge localEdge = BRepBuilderAPI_MakeEdge(localPnt0, localPnt1);
			compoundBuilder.Add(topoCompoundIn, localEdge);
		}
		for (int m = 0; m < arrLen; m++)
		{
			gp_Pnt localPnt((pointsIn.at(m)).at(0), (pointsIn.at(m)).at(1), (pointsIn.at(m)).at(2));
			TopoDS_Vertex localVertex = BRepBuilderAPI_MakeVertex(localPnt);
			compoundBuilder.Add(topoCompoundIn, localVertex);
		}
		aisToolpathIn = new AIS_Shape(topoCompoundIn);
		aisToolpathIn->SetColor(activeColor);
		myContextIn->Display(aisToolpathIn);
	}
}

bool toolpathVisibilityDialog::showModPointsChecked(toolpathName toolpathTypeIn)
{
	if (toolpathTypeIn == toolpathName::TOP_TIP)
	{
		return showTopToolTipsModCheckBox->isChecked();
	}
	else if (toolpathTypeIn == toolpathName::BOT_TIP)
	{
		return showBotToolTipsModCheckBox->isChecked();
	}
	else
	{
		return true;
	}
}