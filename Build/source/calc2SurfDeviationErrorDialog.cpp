#include "stdafx.h"
#include "calc2SurfDeviationErrorDialog.h"

calc2SurfDeviationErrorDialog::calc2SurfDeviationErrorDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(importStpSurf1PushButton, SIGNAL(clicked()), this, SLOT(importSurf1StpSlot()));
	connect(importIgsSurf1PushButton, SIGNAL(clicked()), this, SLOT(importSurf1IgsSlot()));
	connect(importStpSurf2PushButton, SIGNAL(clicked()), this, SLOT(importSurf2StpSlot()));
	connect(importIgsSurf2PushButton, SIGNAL(clicked()), this, SLOT(importSurf2IgsSlot()));
	connect(regionParamPushButton, SIGNAL(clicked()), this, SLOT(regionParamDefinitionSlot()));
	connect(pickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedPickDirectoryButtonSlot()));

	rectRegionRadioButton->setChecked(true);
	myRegionType = regionType::RECT;

	directoryLineEdit->setText(currentDirectory);
	myFileExplorer->setFileMode(QFileDialog::Directory);
	myFileExplorer->setOption(QFileDialog::ShowDirsOnly);
	myFileExplorer->setViewMode(QFileDialog::List);
}

calc2SurfDeviationErrorDialog::~calc2SurfDeviationErrorDialog()
{

}

void calc2SurfDeviationErrorDialog::importSurf1StpSlot(void)
{
	surf1ImportSuccess = importSTP(this, surf1Compound);

	if (surf1ImportSuccess)
		surf1StatusLineEdit->setText("Import Status: SUCCESS");
	else
		surf1StatusLineEdit->setText("Import Status: ERROR");
}

void calc2SurfDeviationErrorDialog::importSurf1IgsSlot(void)
{
	surf1ImportSuccess = importIGS(this, surf1Compound);

	if (surf1ImportSuccess)
		surf1StatusLineEdit->setText("Import Status: SUCCESS");
	else
		surf1StatusLineEdit->setText("Import Status: ERROR");
}

void calc2SurfDeviationErrorDialog::importSurf2StpSlot(void)
{
	surf2ImportSuccess = importSTP(this, surf2Compound);

	if (surf2ImportSuccess)
		surf2StatusLineEdit->setText("Import Status: SUCCESS");
	else
		surf2StatusLineEdit->setText("Import Status: ERROR");
}

void calc2SurfDeviationErrorDialog::importSurf2IgsSlot(void)
{
	surf2ImportSuccess = importIGS(this, surf2Compound);

	if (surf2ImportSuccess)
		surf2StatusLineEdit->setText("Import Status: SUCCESS");
	else
		surf2StatusLineEdit->setText("Import Status: ERROR");
}

bool calc2SurfDeviationErrorDialog::importIGS(QWidget *parent, TopoDS_Compound &surfOut)
{
	importIGSDialog myImportIgsDialog(parent);

	if (myImportIgsDialog.exec())
	{
		bool performShapeHealing = myImportIgsDialog.getCheckBoxState();
		QString fullImportPath = myImportIgsDialog.getFilePath();
		QString sewTolStr = myImportIgsDialog.getSewingTolStr();

		bool str2floatOK1 = false;

		sewTolStr.toFloat(&str2floatOK1);
		if (!str2floatOK1)
		{
			//textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}

		Standard_Real sewTol = abs(sewTolStr.toFloat());

		if (fullImportPath.isEmpty())
		{
			//textEdit->insertPlainText("ERROR: Empty path, could not find the file to import.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}

		//textEdit->insertPlainText("Opening: ");
		//textEdit->insertPlainText(fullImportPath);
		//textEdit->insertPlainText("\n");
		//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		//textEdit->repaint();

		// Perform OpenCASCADE Import Functions
		std::string fullImportPathTemp = fullImportPath.toStdString();
		const char *fullImportPathTempPtr = fullImportPathTemp.c_str();
		IGESControl_Reader IGESReader;
		IFSelect_ReturnStatus igesReaderStatus = IGESReader.ReadFile(fullImportPathTempPtr);
		if (igesReaderStatus != IFSelect_ReturnStatus::IFSelect_RetDone)
		{
			//textEdit->insertPlainText("ERROR: Could not read/find file.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}

		if (!Interface_Static::SetIVal("read.precision.mode", 1))
		{
		} // Handle error

		if (!Interface_Static::SetRVal("read.precision.val", 0.001))
		{
		} // Handle error

		Handle(TColStd_HSequenceOfTransient)  faceListFromReader = IGESReader.GiveList("iges-faces");
		//textEdit->insertPlainText("Translating all face entities... ");

		Standard_Integer listIter;
		Standard_Integer listLength = faceListFromReader->Length();
		for (listIter = 1; listIter <= listLength; listIter++)
		{
			Handle(Standard_Transient) faceEntity = faceListFromReader->Value(listIter);
			Standard_Boolean OK = IGESReader.TransferEntity(faceEntity);
			if (!OK)
			{
				//textEdit->insertPlainText("\nERROR: A face failed to translate successfully into the OpenCASCADE library.\n");
				//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return false;
			}
		}
		TopoDS_Shape importedShapeRaw = IGESReader.OneShape();
		if (importedShapeRaw.IsNull())
		{
			//textEdit->insertPlainText("\nERROR: Imported shape is NULL.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}
		//textEdit->insertPlainText("Success!\n");
		//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		//textEdit->repaint();

		// Now sew surfaces together
		BRepBuilderAPI_Sewing sewBuilder;
		sewBuilder.SetTolerance(sewTol*1.0);
		sewBuilder.SetMaxTolerance(sewTol*3.0);
		sewBuilder.SetMinTolerance(sewTol / 2.0);
		TopExp_Explorer explorerFace(importedShapeRaw, TopAbs_ShapeEnum::TopAbs_FACE);
		for (; explorerFace.More(); explorerFace.Next())
		{
			sewBuilder.Add(TopoDS::Face(explorerFace.Current()));
		}
		sewBuilder.Perform();
		TopoDS_Shape importedShapeSewn = sewBuilder.SewedShape();
		if (importedShapeSewn.IsNull())
		{
			//textEdit->insertPlainText("ERROR: Imported faces could not be sewn together.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}
		//textEdit->insertPlainText("Imported faces have been successfully sewn together.\n");
		//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		//textEdit->repaint();

		// Rebuild shape as a single shell entity
		TopoDS_Shell importedShapeShell;
		BRep_Builder TopoDsShellBuilder;
		TopoDsShellBuilder.MakeShell(importedShapeShell);

		explorerFace.Init(importedShapeSewn, TopAbs_ShapeEnum::TopAbs_FACE);
		while (explorerFace.More())
		{
			TopoDsShellBuilder.Add(importedShapeShell, TopoDS::Face(explorerFace.Current()));
			explorerFace.Next();
		}

		if (importedShapeShell.IsNull())
		{
			//textEdit->insertPlainText("ERROR: Resultant shape failed to be cast into a single shell type.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}

		TopoDS_Shape importedShapeFixed;
		if (performShapeHealing)
		{
			// Perform shape healing and fixing small edges
			Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape;
			sfs->Init(importedShapeShell);
			sfs->SetPrecision(sewTol);
			sfs->SetMaxTolerance(sewTol*3.0);
			sfs->SetMinTolerance(sewTol / 2.0);
			sfs->Perform();
			TopoDS_Shape importedShapeHealed = sfs->Shape();

			Handle(ShapeFix_Wireframe) SFWF = new ShapeFix_Wireframe(importedShapeHealed);
			SFWF->SetPrecision(sewTol);
			SFWF->SetMaxTolerance(sewTol*3.0);
			SFWF->ModeDropSmallEdges() = Standard_True;
			SFWF->FixSmallEdges();
			SFWF->FixWireGaps();
			importedShapeFixed = SFWF->Shape();

			//textEdit->insertPlainText("Completed face healing and edge fixing.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			//textEdit->repaint();
		}
		else
		{
			importedShapeFixed = importedShapeRaw;
		}

		//if (partIsActive)
		//	myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
		//else
		//	partIsActive = true; // First time a part has been added to context

		TopoDS_Compound tempTopoDsCompound;
		BRep_Builder TopoDsCompoundBuilder;
		TopoDsCompoundBuilder.MakeCompound(tempTopoDsCompound);
		TopoDsCompoundBuilder.Add(tempTopoDsCompound, importedShapeFixed);
		surfOut = tempTopoDsCompound;

		/*if (myAisShape.IsNull())
			myAisShape = new AIS_Shape(myCurrentPart);
		else
		{
			myAisShape.Nullify();
			myAisShape = new AIS_Shape(myCurrentPart);
		}

		myContext->Display(myAisShape);
		textEdit->insertPlainText("Visualizing imported surface... Success!\n");
		textEdit->insertPlainText("NOTE: Check that there are no unwanted free edges (visualized in green) by clicking 'Wireframe' mode. If there are, increase Sewing Tolerance.\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());*/

		return true;
	}

	return false;
}

bool calc2SurfDeviationErrorDialog::importSTP(QWidget *parent, TopoDS_Compound &surfOut)
{
	importIGSDialog myImportIgsDialog(parent);
	myImportIgsDialog.changeWindowTitle("Import as STEP");
	myImportIgsDialog.setFileFilterToSTEP(true);

	if (myImportIgsDialog.exec())
	{
		bool performShapeHealing = myImportIgsDialog.getCheckBoxState();
		QString fullImportPath = myImportIgsDialog.getFilePath();
		QString sewTolStr = myImportIgsDialog.getSewingTolStr();

		bool str2floatOK1 = false;

		sewTolStr.toFloat(&str2floatOK1);
		if (!str2floatOK1)
		{
			//textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}

		Standard_Real sewTol = abs(sewTolStr.toFloat());

		if (fullImportPath.isEmpty())
		{
			//textEdit->insertPlainText("ERROR: Empty path, could not find the file to import.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}

		//textEdit->insertPlainText("Opening: ");
		//textEdit->insertPlainText(fullImportPath);
		//textEdit->insertPlainText("\n");
		//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		//textEdit->repaint();

		// Perform OpenCASCADE Import Functions
		std::string fullImportPathTemp = fullImportPath.toStdString();
		const char *fullImportPathTempPtr = fullImportPathTemp.c_str();
		STEPControl_Reader stepReader;
		IFSelect_ReturnStatus readStatus = stepReader.ReadFile(fullImportPathTempPtr);
		if (readStatus != IFSelect_ReturnStatus::IFSelect_RetDone)
		{
			//textEdit->insertPlainText("ERROR: Could not read/find file.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}

		Standard_Integer NbRoots = stepReader.NbRootsForTransfer();
		Standard_Integer numRootsTransferred = stepReader.TransferRoots();

		TopoDS_Shape importedShapeRaw = stepReader.OneShape();
		if (importedShapeRaw.IsNull())
		{
			//textEdit->insertPlainText("ERROR: Translation of the STEP file into OpenCASCADE objects failed.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}
		else
		{
			//textEdit->insertPlainText("Translating the surfaces from the STEP file into OpenCASCADE objects... Success!\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			//textEdit->repaint();
		}

		// Now sew surfaces together
		BRepBuilderAPI_Sewing sewBuilder;
		sewBuilder.SetTolerance(sewTol*1.0);
		sewBuilder.SetMaxTolerance(sewTol*3.0);
		sewBuilder.SetMinTolerance(sewTol / 2.0);
		TopExp_Explorer explorerFace(importedShapeRaw, TopAbs_ShapeEnum::TopAbs_FACE);
		for (; explorerFace.More(); explorerFace.Next())
		{
			sewBuilder.Add(TopoDS::Face(explorerFace.Current()));
		}
		sewBuilder.Perform();
		TopoDS_Shape importedShapeSewn = sewBuilder.SewedShape();
		if (importedShapeSewn.IsNull())
		{
			//textEdit->insertPlainText("ERROR: Imported faces could not be sewn together.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}
		//textEdit->insertPlainText("Imported faces have been successfully sewn together.\n");
		//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		//textEdit->repaint();

		// Rebuild shape as a single shell entity
		TopoDS_Shell importedShapeShell;
		BRep_Builder TopoDsShellBuilder;
		TopoDsShellBuilder.MakeShell(importedShapeShell);

		explorerFace.Init(importedShapeSewn, TopAbs_ShapeEnum::TopAbs_FACE);
		while (explorerFace.More())
		{
			TopoDsShellBuilder.Add(importedShapeShell, TopoDS::Face(explorerFace.Current()));
			explorerFace.Next();
		}

		if (importedShapeShell.IsNull())
		{
			//textEdit->insertPlainText("ERROR: Resultant shape failed to be cast into a single shell type.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return false;
		}

		TopoDS_Shape importedShapeFixed;
		if (performShapeHealing)
		{
			// Perform shape healing and fixing small edges
			Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape;
			sfs->Init(importedShapeShell);
			sfs->SetPrecision(sewTol);
			sfs->SetMaxTolerance(sewTol*3.0);
			sfs->SetMinTolerance(sewTol / 2.0);
			sfs->Perform();
			TopoDS_Shape importedShapeHealed = sfs->Shape();

			Handle(ShapeFix_Wireframe) SFWF = new ShapeFix_Wireframe(importedShapeHealed);
			SFWF->SetPrecision(sewTol);
			SFWF->SetMaxTolerance(sewTol*3.0);
			SFWF->ModeDropSmallEdges() = Standard_True;
			SFWF->FixSmallEdges();
			SFWF->FixWireGaps();
			importedShapeFixed = SFWF->Shape();

			//textEdit->insertPlainText("Completed face healing and edge fixing.\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			//textEdit->repaint();
		}
		else
		{
			importedShapeFixed = importedShapeRaw;
		}

		//if (partIsActive)
		//	myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
		//else
		//	partIsActive = true; // First time a part has been added to context

		TopoDS_Compound tempTopoDsCompound;
		BRep_Builder TopoDsCompoundBuilder;
		TopoDsCompoundBuilder.MakeCompound(tempTopoDsCompound);
		TopoDsCompoundBuilder.Add(tempTopoDsCompound, importedShapeFixed);
		surfOut = tempTopoDsCompound;

		/*if (myAisShape.IsNull())
			myAisShape = new AIS_Shape(myCurrentPart);
		else
		{
			myAisShape.Nullify();
			myAisShape = new AIS_Shape(myCurrentPart);
		}

		myContext->Display(myAisShape);
		textEdit->insertPlainText("Visualizing imported surface... Success!\n");
		textEdit->insertPlainText("NOTE: Check that there are no unwanted free edges (visualized in green) by clicking 'Wireframe' mode. If there are, increase Sewing Tolerance.\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());*/

		return true;
	}

	return false;
}

QString calc2SurfDeviationErrorDialog::getDirectory(void)
{
	selectedDirectory = directoryLineEdit->text();

	if (!selectedDirectory.isEmpty())
		return selectedDirectory;
	else
		return currentDirectory;
}

QString calc2SurfDeviationErrorDialog::getPrefixName(void)
{
	selectedPrefixName = prefixNameLineEdit->text();

	if (!selectedPrefixName.isEmpty())
	{
		return selectedPrefixName;
	}
	else
	{
		return "myDeviationValues";
	}
}

void calc2SurfDeviationErrorDialog::clickedPickDirectoryButtonSlot()
{
	myFileExplorer->setDirectory(directoryLineEdit->text());
	if (myFileExplorer->exec())
	{
		selectedDirectoryList = myFileExplorer->selectedFiles();
		if (selectedDirectoryList.isEmpty())
		{
		}
		else
		{
			directoryLineEdit->setText(selectedDirectoryList.first());
		}
	}
}

void calc2SurfDeviationErrorDialog::regionParamDefinitionSlot(void)
{
	if (rectRegionRadioButton->isChecked())
		myRegionType = regionType::RECT;
	else if (lineRegionRadioButton->isChecked())
		myRegionType = regionType::LINE;

	if (myRegionType == regionType::RECT)
	{
		rectRegionDefinitionDialog myRectRegionDialog(this);
		
		if (myRectRegionDialog.exec())
		{
			regionDefinedSuccess = myRectRegionDialog.getRectRegion(myRectRegion);

			if (regionDefinedSuccess)
				regionStatusLineEdit->setText("Region Definition: SUCCESS, Rectangle");
			else
				regionStatusLineEdit->setText("Region Definition: ERROR");
		}
	}
	else if (myRegionType == regionType::LINE)
	{
		lineRegionDefinitionDialog myLineRegionDialog(this);

		if (myLineRegionDialog.exec())
		{
			regionDefinedSuccess = myLineRegionDialog.getLineRegion(myLineRegion);

			if (regionDefinedSuccess)
				regionStatusLineEdit->setText("Region Definition: SUCCESS, Line");
			else
				regionStatusLineEdit->setText("Region Definition: ERROR");
		}
	}
}

bool calc2SurfDeviationErrorDialog::getSurf1(TopoDS_Compound &surf1Out) const
{
	surf1Out = surf1Compound;
	return surf1ImportSuccess;
}

bool calc2SurfDeviationErrorDialog::getSurf2(TopoDS_Compound &surf2Out) const
{
	surf2Out = surf2Compound;
	return surf2ImportSuccess;
}

calc2SurfDeviationErrorDialog::regionType calc2SurfDeviationErrorDialog::getRegionType(void) const
{
	return myRegionType;
}

bool calc2SurfDeviationErrorDialog::getLineRegion(amplLineRegion &lineRegionOut) const
{
	lineRegionOut.copyFromOther(myLineRegion);
	return regionDefinedSuccess;
}

bool calc2SurfDeviationErrorDialog::getRectRegion(amplRectRegion &rectRegionOut) const
{
	rectRegionOut.copyFromOther(myRectRegion);
	return regionDefinedSuccess;
}
