#include "stdafx.h"

#include "QtOcct.h"


static Handle(Graphic3d_GraphicDriver)& GetGraphicDriver()
{
	static Handle(Graphic3d_GraphicDriver) aGraphicDriver;
	return aGraphicDriver;
}

QtOcct::QtOcct(QWidget *parent)
	: QMainWindow(parent)
{
	// Initialize main window and OpenGL widget
	setupUi(this);

	openGLWidget->setBackgroundRole(QPalette::NoRole); // No background/foreground colors
	openGLWidget->setForegroundRole(QPalette::NoRole);
	openGLWidget->setMouseTracking(true); // By default, mouse tracking is set to false
	openGLWidget->setUpdatesEnabled(false); // Updates are handled by OCC, don't let Qt interfere. 
	openGLWidget->setFocusPolicy(Qt::ClickFocus); // Allow the OpenGLWidget to accept/track keyboard inputs
	initOpenGL(); // Initialize OpenGL context in the OpenGLWidget

	createActions();
	textEdit->insertPlainText("\nThanks for using AMPL Toolpaths - Created by Newell Moser\nLike the software? Give thanks to Newell and buy him a coffee.\n\n");

	//myHotKeysDialog->show();
	//QPoint topLeftPtWindow(0,0);
	//this->mapToGlobal(topLeftPtWindow);
	//myHotKeysDialog->move(topLeftPtWindow);
	openGLWidget->setFocus(); // Initialize the window with the widget in focus
}

QtOcct::~QtOcct()
{

}

void QtOcct::initOpenGL()
{
	QString initOpenGLMsg = "Initializing OpenGL context... ";

	// Create Aspect_DisplayConnection
	Handle(Aspect_DisplayConnection) aDisplayConnection = new Aspect_DisplayConnection();
	
	// Get graphic driver if it exists, otherwise initialise it
	if (GetGraphicDriver().IsNull())
		GetGraphicDriver() = new OpenGl_GraphicDriver(aDisplayConnection);

	// Get window handle. This is not great practice in portability coding... deal with it.
    HWND window_handle = (HWND)openGLWidget->winId();
	//WId window_handle = (WId)winId();

	Handle(WNT_Window) wind = new WNT_Window((Aspect_Handle)window_handle);
	
	// Create V3dViewer and V3d_View
	myViewer = new V3d_Viewer(GetGraphicDriver());

	myView = myViewer->CreateView();

	myView->SetWindow(wind);
	if (!wind->IsMapped()) wind->Map();
	myView->MustBeResized();

	// Create AISInteractiveContext
	myContext = new AIS_InteractiveContext(myViewer);

	// Set up lights etc
	myViewer->SetDefaultLights();
	myViewer->SetLightOn();

	myView->SetBackgroundColor(Quantity_NOC_BLACK);
	myView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);
	
	// AIS_Shaded or AIS_WireFrame
	myContext->SetDisplayMode(AIS_Shaded);
	textEdit->insertPlainText(initOpenGLMsg.append("Success!  Expected units are [mm].\n"));
}

void QtOcct::createActions()
{
	rotAxisGroup = new QActionGroup(this);
	surfaceShadingGroup = new QActionGroup(this);

	connect(actionExport_to_IGS, SIGNAL(triggered()), this, SLOT(showExportAsIGSDialogSlot()));
	connect(actionImport_IGS, SIGNAL(triggered()), this, SLOT(showImportIGSDialogSlot()));
	connect(actionExport_STEP, SIGNAL(triggered()), this, SLOT(showExportAsSTEPDialogSlot()));
	connect(actionImport_STEP, SIGNAL(triggered()), this, SLOT(showImportSTEPDialogSlot()));
	connect(actionLoad_AMPL_Toolpath, SIGNAL(triggered()), this, SLOT(showOpenAmplToolpathDialogSlot()));
	connect(actionSave_AMPL_Toolpath, SIGNAL(triggered()), this, SLOT(showSaveAmplToolpathDialogSlot()));
	connect(actionExport_Toolpath_to_CSV, SIGNAL(triggered()), this, SLOT(showExportAmplToolpathDialogSlot()));
	connect(actionImport_Contact_Points, SIGNAL(triggered()), this, SLOT(showImportContactPntsDialogSlot()));

	connect(actionMake_Bottle, SIGNAL(triggered()), this, SLOT(makeBottleSlot()));
	connect(actionBox_Demo, SIGNAL(triggered()), this, SLOT(makeBoxSlot()));
	connect(actionSphere_Demo, SIGNAL(triggered()), this, SLOT(makeSphereSlot()));

	connect(myRotDialog, SIGNAL(rotateDialogButtonClicked()), this, SLOT(rotatePartSlot()));
	connect(actionRotate_Part, SIGNAL(triggered()), this, SLOT(showRotatePartDialogSlot()));
	connect(actionTranslate_Part, SIGNAL(triggered()), this, SLOT(showTranslatePartDialogSlot()));
	connect(myTransDialog, SIGNAL(translateDialogButtonClicked()), this, SLOT(translatePartSlot()));
	connect(actionScale_Part, SIGNAL(triggered()), this, SLOT(showScalePartDialogSlot()));
	connect(myScaleDialog, SIGNAL(scaleDialogButtonClicked()), this, SLOT(scalePartSlot()));

	connect(actionZoom, SIGNAL(triggered()), this, SLOT(zoom()));
	connect(actionPan, SIGNAL(triggered()), this, SLOT(pan()));
	connect(actionRotate, SIGNAL(triggered()), this, SLOT(rotate()));
	connect(actionReset_View, SIGNAL(triggered()), this, SLOT(reset()));
	connect(actionFit_All, SIGNAL(triggered()), this, SLOT(fitAll()));
	connect(actionWireframe, SIGNAL(triggered()), this, SLOT(wireFrameSlot()));
	connect(actionShaded, SIGNAL(triggered()), this, SLOT(shadedSlot()));
	connect(actionRot_X, SIGNAL(triggered()), this, SLOT(changeRotAxisX_Slot()));
	connect(actionRot_Y, SIGNAL(triggered()), this, SLOT(changeRotAxisY_Slot()));
	connect(actionRot_Z, SIGNAL(triggered()), this, SLOT(changeRotAxisZ_Slot()));
	connect(actionXY_View, SIGNAL(triggered()), this, SLOT(setXYViewSlot()));
	connect(actionYZ_View, SIGNAL(triggered()), this, SLOT(setYZViewSlot()));
	connect(actionZX_View, SIGNAL(triggered()), this, SLOT(setZXViewSlot()));
	connect(actionIsometric, SIGNAL(triggered()), this, SLOT(setIsometricViewSlot()));
	connect(actionBackgroundBlack, SIGNAL(triggered()), this, SLOT(setBackgroundColorBlackSlot()));
	connect(actionBackgroundWhite, SIGNAL(triggered()), this, SLOT(setBackgroundColorWhiteSlot()));
	connect(actionBackgroundLight_Blue, SIGNAL(triggered()), this, SLOT(setBackgroundColorBlueSlot()));
	connect(actionHotkeys, SIGNAL(triggered()), this, SLOT(showHotKeysDialogSlot()));
	connect(actionAbout, SIGNAL(triggered()), this, SLOT(showAboutDialogSlot()));
	connect(actionOrigin_Visible, SIGNAL(triggered()), this, SLOT(showOriginSlot()));
	connect(actionVisibleActivePart, SIGNAL(triggered()), this, SLOT(showActivePartSlot()));
	connect(actionVisibleToolpath, SIGNAL(triggered()), this, SLOT(showToolpathVisibilityDialogSlot()));
	connect(myToolpathVisibilityDialog, SIGNAL(toolpathVisibilityApplyButtonPushed(bool)), this, SLOT(setToolpathVisibilitySlot(bool)));
	connect(actionClippingPlane, SIGNAL(triggered()), this, SLOT(showClippingPlaneDialogSlot()));
	connect(myClippingPlaneDialog, SIGNAL(clippingPlaneButtonClickedSignal()), this, SLOT(setClippingPlaneDialogSlot()));

	connect(actionTruncated_Cone, SIGNAL(triggered()), this, SLOT(showTrunConeDialogSlot()));
	connect(myTrunConeDialog, SIGNAL(trunConeCreateButtonClicked()), this, SLOT(makeTrunConeSlot()));
	connect(actionTruncated_Pyramid, SIGNAL(triggered()), this, SLOT(showPyramidDialogSlot()));
	connect(myPyramidDialog, SIGNAL(pyramidCreateButtonClicked()), this, SLOT(makePyramidSlot()));
	connect(actionArc_Based_Funnel, SIGNAL(triggered()), this, SLOT(showFunnelDialogSlot()));
	connect(myFunnelDialog, SIGNAL(funnelCreateButtonClicked()), this, SLOT(makeFunnelSlot()));

	connect(actionContactPntSingleFeature, SIGNAL(triggered()), this, SLOT(showSingFeatureToolpathInputDialogSlot()));
	connect(actionToolTipSingleFeaturePart, SIGNAL(triggered()), this, SLOT(showSingFeatureCalcToolTipsDialogSlot()));
	connect(actionNU_Gen_1_DSIF_Machine, SIGNAL(triggered()), this, SLOT(showExportToGen1MachineCodeDialogSlot()));
	connect(actionNU_Gen_2_DSIF_Machine, SIGNAL(triggered()), this, SLOT(showExportToGen2MachineCodeDialogSlot()));

	connect(actionExtract_Cross_Section, SIGNAL(triggered()), this, SLOT(showExtractCrossSectionToolDialogSlot()));
	connect(actionSurface_Deviation_Map, SIGNAL(triggered()), this, SLOT(showCalcTwoSurfDeviationDialogSlot()));

	connect(actionDev_Sandbox, SIGNAL(triggered()), this, SLOT(startDeveloperSandboxRoutines()));

	rotAxisGroup->addAction(actionRot_X);
	rotAxisGroup->addAction(actionRot_Y);
	rotAxisGroup->addAction(actionRot_Z);
	rotAxisGroup->isExclusive();
	actionRot_Z->setChecked(true);
	myCurrentRotAxis = CurRotAxis_Z;

	surfaceShadingGroup->addAction(actionWireframe);
	surfaceShadingGroup->addAction(actionShaded);
	surfaceShadingGroup->isExclusive();
	actionShaded->setChecked(true);
	actionVisibleActivePart->setChecked(true);
}

void QtOcct::setXYViewSlot()
{
	myView->Reset();
	myView->MustBeResized();
	myView->Rotate(V3d_Z, -45 * PI / 180.0, 0.0, 0.0, 0.0);
	myView->Rotate(V3d_X, -55 * PI / 180.0, 0.0, 0.0, 0.0);
	myView->FitAll();
	myView->ZFitAll();
	myView->Redraw();;
	textEdit->insertPlainText("Change to XY-view\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::setYZViewSlot()
{
	myView->Reset();
	myView->MustBeResized();
	myView->Rotate(V3d_Z, 45 * PI / 180.0, 0.0, 0.0, 0.0);
	myView->Rotate(V3d_Y, 35 * PI / 180.0, 0.0, 0.0, 0.0);
	myView->FitAll();
	myView->ZFitAll();
	myView->Redraw();;
	textEdit->insertPlainText("Change to YZ-view\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::setZXViewSlot()
{
	myView->Reset();
	myView->MustBeResized();
	myView->Rotate(V3d_Z, -45 * PI / 180.0, 0.0, 0.0, 0.0);
	myView->Rotate(V3d_X, 35 * PI / 180.0, 0.0, 0.0, 0.0);
	myView->FitAll();
	myView->ZFitAll();
	myView->Redraw();;
	textEdit->insertPlainText("Change to XZ-view\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::setIsometricViewSlot()
{
	myView->Reset();
	myView->MustBeResized(); 
	myView->Rotate(V3d_Z, 45 * PI / 180.0, 0.0, 0.0, 0.0);
	myView->Rotate(V3d_Y, 35 * PI / 180.0, 0.0, 0.0, 0.0); // Now in YZ-view

	myView->Rotate(V3d_Y, -45 * PI / 180.0, 0.0, 0.0, 0.0);
	myView->Rotate(V3d_Z, 45.0 * PI / 180.0, 0.0, 0.0, 0.0);
	 
	myView->FitAll();
	myView->ZFitAll();
	myView->Redraw();;
	textEdit->insertPlainText("Change to Isometric view\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::changeRotAxisX_Slot()
{
	myCurrentRotAxis = CurRotAxis_X;
	textEdit->insertPlainText("Use left/right arrow keys to rotate about the X-axis\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}
void QtOcct::changeRotAxisY_Slot()
{
	myCurrentRotAxis = CurRotAxis_Y;
	textEdit->insertPlainText("Use left/right arrow keys to rotate about the Y-axis\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}
void QtOcct::changeRotAxisZ_Slot()
{
	myCurrentRotAxis = CurRotAxis_Z;
	textEdit->insertPlainText("Use left/right arrow keys to rotate about the Z-axis\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::wireFrameSlot()
{
	myContext->SetDisplayMode(AIS_WireFrame);
	myView->Redraw();
	textEdit->insertPlainText("Change to wireframe mode\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::shadedSlot()
{
	myContext->SetDisplayMode(AIS_Shaded);
	myView->Redraw();
	textEdit->insertPlainText("Change to shaded mode\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::paintEvent(QPaintEvent* e)
{
	// eliminate the warning C4100: 'e' : unreferenced formal parameter
	Q_UNUSED(e);

	if (myContext.IsNull())
		initOpenGL();

	myView->MustBeResized(); // For some reason, this must be called to get desired functionality
	myView->Redraw();
}

void QtOcct::resizeEvent(QResizeEvent* e)
{
	Q_UNUSED(e);

	if (!myView.IsNull())
		myView->MustBeResized();
}

const Handle(AIS_InteractiveContext)& QtOcct::getContext() const
{
	return myContext;
}

void QtOcct::fitAll(void)
{
	myView->FitAll();
	myView->ZFitAll();
	myView->Redraw();
	textEdit->insertPlainText("Fit all objects into the viewer\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::reset(void)
{
	myView->Reset();
	myView->MustBeResized();
	textEdit->insertPlainText("Reset the view to default orientation\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::pan(void)
{
	if (actionRotate->isChecked())
		actionRotate->setChecked(false);
	else if (actionZoom->isChecked())
		actionZoom->setChecked(false);

	if (actionPan->isChecked())
	{
		myCurrentMode = CurAction3d_DynamicPanning;
		textEdit->insertPlainText("Enable left-click dynamic mode: Pan\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
	else
	{
		myCurrentMode = CurAction3d_Nothing;
		textEdit->insertPlainText("Disable left-click dynamic mode\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
}

void QtOcct::zoom(void)
{
	if (actionRotate->isChecked())
		actionRotate->setChecked(false);
	else if (actionPan->isChecked())
		actionPan->setChecked(false);

	if (actionZoom->isChecked())
	{
		myCurrentMode = CurAction3d_DynamicZooming;
		zoomInBool = true;
		textEdit->insertPlainText("Enable left-click dynamic mode: Zoom\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
	else
	{
		myCurrentMode = CurAction3d_Nothing;
		textEdit->insertPlainText("Disable left-click dynamic mode\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
}

void QtOcct::rotate(void)
{
	if (actionPan->isChecked())
		actionPan->setChecked(false);
	else if (actionZoom->isChecked())
		actionZoom->setChecked(false);

	if (actionRotate->isChecked())
	{
		myCurrentMode = CurAction3d_DynamicRotation;
		textEdit->insertPlainText("Enable left-click dynamic mode: Rotation\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
	else
	{
		myCurrentMode = CurAction3d_Nothing;
		textEdit->insertPlainText("Disable left-click dynamic mode\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
}

void QtOcct::setBackgroundColorBlackSlot(void)
{
	myView->TriedronErase();
	myView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);
	myView->SetBackgroundColor(Quantity_NOC_BLACK);

	if (!myAisOrigin.IsNull())
	{
		myAisOrigin->SetColor(Quantity_NOC_WHITE);
	}

	textEdit->insertPlainText("Background set to black\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::setBackgroundColorWhiteSlot(void)
{
	myView->TriedronErase();
	myView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_BLACK, 0.08, V3d_ZBUFFER);
	myView->SetBackgroundColor(Quantity_NOC_WHITE);

	if (!myAisOrigin.IsNull())
	{
		myAisOrigin->SetColor(Quantity_NOC_BLACK);
	}

	textEdit->insertPlainText("Background set to white\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::setBackgroundColorBlueSlot(void)
{
	myView->TriedronErase();
	myView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_BLACK, 0.08, V3d_ZBUFFER);
	myView->SetBackgroundColor(Quantity_NOC_SKYBLUE);

	if (!myAisOrigin.IsNull())
	{
		myAisOrigin->SetColor(Quantity_NOC_BLACK);
	}

	textEdit->insertPlainText("Background set to sky blue\n");
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::showTranslatePartDialogSlot(void)
{
	if (myCurrentPart.IsNull()) // Cannot translate a part that does not exist
	{
		textEdit->insertPlainText("No current part active to translate\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	myTransDialog->show();
	myTransDialog->raise();
	myTransDialog->activateWindow();
}

void QtOcct::translatePartSlot(void)
{
	QString transformMsg;
	QTextStream transformMsgStream(&transformMsg);
	QString xDir = myTransDialog->getXLineEdit().trimmed();
	QString yDir = myTransDialog->getYLineEdit().trimmed();
	QString zDir = myTransDialog->getZLineEdit().trimmed();
	QString scaleFact = myTransDialog->getTransFactorLineEdit().trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;
	bool str2floatOK4 = false;

	xDir.toFloat(&str2floatOK1);
	yDir.toFloat(&str2floatOK2);
	zDir.toFloat(&str2floatOK3);
	scaleFact.toFloat(&str2floatOK4);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3 || !str2floatOK4)
	{
		textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}


	Standard_Real xFloat = xDir.toFloat();
	Standard_Real yFloat = yDir.toFloat();
	Standard_Real zFloat = zDir.toFloat();
	Standard_Real scaleFloat = scaleFact.toFloat();

	Standard_Real xyzDirMag = sqrt(xFloat*xFloat + yFloat*yFloat + zFloat*zFloat);
	if (xyzDirMag == 0.0)
	{
		textEdit->insertPlainText("ERROR: Direction input has zero magnitude and connot be defined\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	gp_Dir aDirection(xFloat, yFloat, zFloat); // Need a direction,
	Standard_Real scaleFactor = scaleFloat; // and a magnitude

	gp_Vec translationVector(aDirection); // Initializes as a unit vector
	translationVector.Scale(scaleFactor);
	Standard_Real xTransFinal = translationVector.X();
	Standard_Real yTransFinal = translationVector.Y();
	Standard_Real zTransFinal = translationVector.Z();

	gp_Trsf aTranslation;
	aTranslation.SetTranslation(translationVector); // Build a translation object for the shape compound

	TopLoc_Location aTopLocTranslation(aTranslation);
	myCurrentPart.Move(aTopLocTranslation); // Translates the part object, but the visual part being displayed is not changed!

	//myContext->RemoveAll();
	//myAisShape = new AIS_Shape(myCurrentPart);
	//myContext->Display(myAisShape);
	aTranslation.Multiply(myAisShape->LocalTransformation()); // Need to combine the transformation to the current one
	myAisShape->SetLocalTransformation(aTranslation); // Translates the visual part in the scene
	myAisShape->UpdateTransformation();
	myContext->Redisplay(AIS_KOI_Shape); // Redisplay all shape parts

	transformMsgStream << "Translated current part by: Vector = ["<< xTransFinal <<", "<< yTransFinal <<", "<< zTransFinal << "]" << endl;
	textEdit->insertPlainText(transformMsg);
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::showRotatePartDialogSlot()
{
	if (myCurrentPart.IsNull()) // Cannot rotate a part that does not exist
	{
		textEdit->insertPlainText("No current part active to rotate\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	myRotDialog->show();
	myRotDialog->raise();
	myRotDialog->activateWindow();
}

void QtOcct::rotatePartSlot(void)
{
	QString transformMsg;
	QTextStream transformMsgStream(&transformMsg);
	QString xPtStr = myRotDialog->getXPtLineEdit().trimmed();
	QString yPtStr = myRotDialog->getYPtLineEdit().trimmed();
	QString zPtStr = myRotDialog->getZPtLineEdit().trimmed();
	QString xDirStr = myRotDialog->getXDirLineEdit().trimmed();
	QString yDirStr = myRotDialog->getYDirLineEdit().trimmed();
	QString zDirStr = myRotDialog->getZDirLineEdit().trimmed();
	QString angleStr = myRotDialog->getAngleLineEdit().trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;
	bool str2floatOK4 = false;
	bool str2floatOK5 = false;
	bool str2floatOK6 = false;
	bool str2floatOK7 = false;

	xPtStr.toFloat(&str2floatOK1);
	yPtStr.toFloat(&str2floatOK2);
	zPtStr.toFloat(&str2floatOK3);
	xDirStr.toFloat(&str2floatOK4);
	yDirStr.toFloat(&str2floatOK5);
	zDirStr.toFloat(&str2floatOK6);
	angleStr.toFloat(&str2floatOK7);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3 || !str2floatOK4 || !str2floatOK5 || !str2floatOK6 || !str2floatOK7)
	{
		textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	Standard_Real xPt = xPtStr.toFloat();
	Standard_Real yPt = yPtStr.toFloat();
	Standard_Real zPt = zPtStr.toFloat();
	Standard_Real xDir = xDirStr.toFloat();
	Standard_Real yDir = yDirStr.toFloat();
	Standard_Real zDir = zDirStr.toFloat();
	Standard_Real angleFloat = angleStr.toFloat();

	Standard_Real xyzDirMag = sqrt(xDir*xDir + yDir*yDir + zDir*zDir);
	if (xyzDirMag == 0.0)
	{
		textEdit->insertPlainText("ERROR: Direction input has zero magnitude and connot be defined\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}
	Standard_Real xDirUnit = xDir / xyzDirMag;
	Standard_Real yDirUnit = yDir / xyzDirMag;
	Standard_Real zDirUnit = zDir / xyzDirMag;

	gp_Pnt axisBasePt(xPt, yPt, zPt); // Need to define an axis using a base point,
	gp_Dir axisDirection(xDirUnit, yDirUnit, zDirUnit); // and a direction.
	Standard_Real rotAngle = angleFloat*PI / 180.0; // Also need to define the angle of rotation [radians]

	gp_Ax1 rotationAxis(axisBasePt, axisDirection);
	gp_Trsf aRotTransform;
	aRotTransform.SetRotation(rotationAxis, rotAngle); // Build a rotation transformation object

	TopLoc_Location aTopLocRotation(aRotTransform);
	myCurrentPart.Move(aTopLocRotation); // Rotates the part object, but the visual part being displayed is not changed!

	//myContext->RemoveAll();
	//myAisShape = new AIS_Shape(myCurrentPart);
	//myContext->Display(myAisShape);
	aRotTransform.Multiply(myAisShape->LocalTransformation()); // Need to combine the transformation to the current one
	myAisShape->SetLocalTransformation(aRotTransform); // Rotates the visual part in the scene
	myAisShape->UpdateTransformation();
	myContext->Redisplay(AIS_KOI_Shape); // Redisplays all shape parts

	transformMsgStream << "Rotated current part by " << angleFloat << "deg about: Axis Point = ["
		<< xPt << ", " << yPt << ", " << zPt << "] ; Axis Direction = [" << xDirUnit << ", " << yDirUnit << ", " << zDirUnit << "]" << endl;
	textEdit->insertPlainText(transformMsg);
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::showScalePartDialogSlot(void)
{
	if (myCurrentPart.IsNull()) // Cannot scale a part that does not exist
	{
		textEdit->insertPlainText("No current part active to scale\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	myScaleDialog->show();
	myScaleDialog->raise();
	myScaleDialog->activateWindow();
}

void QtOcct::scalePartSlot(void) 
{
	QString transformMsg;
	QTextStream transformMsgStream(&transformMsg);
	QString xPoint = (myScaleDialog->getXLineEdit()).trimmed();
	QString yPoint = myScaleDialog->getYLineEdit().trimmed();
	QString zPoint = myScaleDialog->getZLineEdit().trimmed();
	QString scaleFact = myScaleDialog->getScaleFactorLineEdit().trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;
	bool str2floatOK4 = false;

	xPoint.toFloat(&str2floatOK1);
	yPoint.toFloat(&str2floatOK2);
	zPoint.toFloat(&str2floatOK3);
	scaleFact.toFloat(&str2floatOK4);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3 || !str2floatOK4)
	{
		textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	Standard_Real xFloat = xPoint.toFloat();
	Standard_Real yFloat = yPoint.toFloat();
	Standard_Real zFloat = zPoint.toFloat();
	Standard_Real scaleFloat = scaleFact.toFloat();

	gp_Pnt centerPt(xFloat, yFloat, zFloat); // Need a point to scale the part with respect to,
	Standard_Real scaleFactor = scaleFloat; // and a factor to scale by

	gp_Trsf aScaleTransformation;
	aScaleTransformation.SetScale(centerPt, scaleFactor); // Build a scaling object for the shape compound

	TopLoc_Location aTopLocScaling(aScaleTransformation);
	myCurrentPart.Move(aTopLocScaling); // Scales the part object, but the visual part being displayed is not changed!

	//myContext->RemoveAll();
	//myAisShape = new AIS_Shape(myCurrentPart);
	//myContext->Display(myAisShape);
	aScaleTransformation.Multiply(myAisShape->LocalTransformation()); // Need to combine the transformation to the current one
	myAisShape->SetLocalTransformation(aScaleTransformation); // Translates the visual part in the scene
	myAisShape->UpdateTransformation();
	myContext->Redisplay(AIS_KOI_Shape); // Redisplay all shape parts

	transformMsgStream << "Scaled current part by a factor of "<< scaleFloat <<" about: Point = [" 
		<< xFloat<<", "<< yFloat <<", " << zFloat << "]" << endl;
	textEdit->insertPlainText(transformMsg);
	textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
}

void QtOcct::showTrunConeDialogSlot()
{
	//myTrunConeDialog->setMakingPyramid(false);
	//myTrunConeDialog->update();
	myTrunConeDialog->show();
	myTrunConeDialog->raise();
	myTrunConeDialog->activateWindow();
}

void QtOcct::showPyramidDialogSlot()
{
	myPyramidDialog->setMakingPyramid(true);
	myPyramidDialog->setDialogTitle("Create Pyramid");
	myPyramidDialog->setDiameterLabel("Top Opening Width:");
	myPyramidDialog->show();
	myPyramidDialog->raise();
	myPyramidDialog->activateWindow();
}

void QtOcct::showFunnelDialogSlot()
{
	myFunnelDialog->show();
	myFunnelDialog->raise();
	myFunnelDialog->activateWindow();
}

void QtOcct::showHotKeysDialogSlot()
{
	myHotKeysDialog->show();
	myHotKeysDialog->raise();
	myHotKeysDialog->activateWindow();
}

void QtOcct::showAboutDialogSlot()
{
	QString msg1 = "Beta Version (March 27th, 2019): 0.9.6\n\n";
	QString msg2 = "Thanks for using AMPL Toolpaths, created by:\n";
	QString msg3 = "Newell Moser\nPhD Candidate\nMechanical Engineering, Northwestern University\n\n";
	QString msg4 = "AMPL Toolpaths is built using Open Source software:\n";
	QString msg5 = "Open CASCADE Technology 7.1.0 (GNU Lesser General Public License (LGPL) V2.1)\n";
	QString msg6 = "Qt 5.8.0 (GNU Lesser General Public License (LGPL) V3)\n";
	QString msg7 = "Ben Strasser - Fast C++ CSV Parser (BSD 3 License)\n";
	QString msg8 = "Cereal 1.2.2 (BSD 3 License)\n\n\n";
	QString msg9 = "Copyright & License Notice\n\nAMPL Toolpaths is copyrighted, patent pending, and is owned by Lightweight Innovations for Tomorrow (LIFT), a Michigan not-for-profit corporation, having a place of business at 1400 Rosa Parks Blvd, Detroit, MI 48216. It can be freely used for educational and research purposes by non-profit institutions and US government agencies only. Other organizations are allowed to use AMPL Toolpaths only for evaluation purposes, and any further uses will require prior approval. The software may not be sold or redistributed without prior approval. One may make copies of the software for their use provided that the copies are not sold or distributed and are used under the same terms and conditions.\n\n";
	QString msg10 = "As unestablished research software, this code is provided on an 'as is' basis without warranty of any kind, either expressed or implied. The downloading, or executing any part of this software constitutes an implicit agreement to these terms. These terms and conditions are subject to change at any time without prior notice.";
	QMessageBox::about(this, QString("About AMPL Toolpaths (C++11)"), msg1 + msg2 + msg3 + msg4 + msg5 + msg6 + msg7 + msg8 + msg9 + msg10);
}

void QtOcct::showOriginSlot()
{
	if (actionOrigin_Visible->isChecked())
	{
		if (myAisOrigin.IsNull())
		{
			gp_Pnt origin(0.0, 0.0, 0.0);
			gp_Pnt xAxisPnt(10.0, 0.0, 0.0);
			gp_Pnt yAxisPnt(0.0, 10.0, 0.0);
			gp_Pnt zAxisPnt(0.0, 0.0, 10.0);

			Handle(Geom_TrimmedCurve) xAxisTrimCurve = GC_MakeSegment(origin, xAxisPnt);
			Handle(Geom_TrimmedCurve) yAxisTrimCurve = GC_MakeSegment(origin, yAxisPnt);
			Handle(Geom_TrimmedCurve) zAxisTrimCurve = GC_MakeSegment(origin, zAxisPnt);

			TopoDS_Vertex originVertex = BRepBuilderAPI_MakeVertex(origin);
			TopoDS_Edge xAxisEdge = BRepBuilderAPI_MakeEdge(xAxisTrimCurve);
			TopoDS_Edge yAxisEdge = BRepBuilderAPI_MakeEdge(yAxisTrimCurve);
			TopoDS_Edge zAxisEdge = BRepBuilderAPI_MakeEdge(zAxisTrimCurve);

			TopoDS_Compound tempCompound;
			BRep_Builder aBuilder;
			aBuilder.MakeCompound(tempCompound);
			aBuilder.Add(tempCompound, originVertex);
			aBuilder.Add(tempCompound, xAxisEdge);
			aBuilder.Add(tempCompound, yAxisEdge);
			aBuilder.Add(tempCompound, zAxisEdge);
			myCurrentOrigin = tempCompound;

			myAisOrigin = new AIS_Shape(myCurrentOrigin);

			Quantity_Color currentBackColor = myView->BackgroundColor();
			if(currentBackColor == Quantity_NOC_WHITE)
				myAisOrigin->SetColor(Quantity_NOC_BLACK);
			else if(currentBackColor == Quantity_NOC_SKYBLUE)
				myAisOrigin->SetColor(Quantity_NOC_BLACK);
			else
				myAisOrigin->SetColor(Quantity_NOC_WHITE);
		}

		myContext->Display(myAisOrigin);
	}
	else
	{
		myContext->Remove(myAisOrigin);
	}
}

void QtOcct::showActivePartSlot(void)
{
	if (!actionVisibleActivePart->isChecked()) // Hide the part
	{
		if (partIsActive)
		{
			//myContext->Remove(myAisShape);
			//myAisShape.Nullify();
			myContext->Erase(myAisShape);
		}
	}
	else
	{
		if (partIsActive)
		{
			if (myAisShape.IsNull())
				myAisShape = new AIS_Shape(myCurrentPart);
			else
			{
				myContext->Remove(myAisShape);
				myAisShape.Nullify();
				myAisShape = new AIS_Shape(myCurrentPart);
			}
			myContext->Display(myAisShape);
		}
	}
}

void QtOcct::showToolpathVisibilityDialogSlot()
{
	myToolpathVisibilityDialog->show();
	myToolpathVisibilityDialog->raise();
	myToolpathVisibilityDialog->activateWindow();
}

void QtOcct::showClippingPlaneDialogSlot()
{
	myClippingPlaneDialog->show();
	myClippingPlaneDialog->raise();
	myClippingPlaneDialog->activateWindow();
}

void QtOcct::setClippingPlaneDialogSlot()
{
	QString xPntStr = myClippingPlaneDialog->getXPtLineEdit().trimmed();
	QString yPntStr = myClippingPlaneDialog->getYPtLineEdit().trimmed();
	QString zPntStr = myClippingPlaneDialog->getZPtLineEdit().trimmed();
	QString xDirStr = myClippingPlaneDialog->getXDirLineEdit().trimmed();
	QString yDirStr = myClippingPlaneDialog->getYDirLineEdit().trimmed();
	QString zDirStr = myClippingPlaneDialog->getZDirLineEdit().trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;
	bool str2floatOK4 = false;
	bool str2floatOK5 = false;
	bool str2floatOK6 = false;

	xPntStr.toFloat(&str2floatOK1);
	yPntStr.toFloat(&str2floatOK2);
	zPntStr.toFloat(&str2floatOK3);
	xDirStr.toFloat(&str2floatOK4);
	yDirStr.toFloat(&str2floatOK5);
	zDirStr.toFloat(&str2floatOK6);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3 || !str2floatOK4 || !str2floatOK5 || !str2floatOK6)
	{
		textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}
		
	Standard_Real xPnt = xPntStr.toFloat();
	Standard_Real yPnt = yPntStr.toFloat();
	Standard_Real zPnt = zPntStr.toFloat();
	Standard_Real xDir = xDirStr.toFloat();
	Standard_Real yDir = yDirStr.toFloat();
	Standard_Real zDir = zDirStr.toFloat();

	gp_Pnt clipPlaneBasePnt(xPnt, yPnt, zPnt);
	gp_Dir clipPlaneDir(xDir, yDir, zDir);
	gp_Pln clipPlane(clipPlaneBasePnt, clipPlaneDir);
	
	bool clippingPlaneIsOn = myClippingPlaneDialog->getIsClippingOn();
	if (clippingPlaneIsOn)
	{
		if (myClippingPlane.IsNull())
		{
			myClippingPlane = new Graphic3d_ClipPlane();
			myView->AddClipPlane(myClippingPlane);
		}
		else if (myClippingPlane->IsOn())
			myClippingPlane->SetOn(false);

		myClippingPlane->SetEquation(clipPlane);
		myClippingPlane->SetOn(true);
		myView->Update();

		textEdit->insertPlainText("Clipping plane on\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
	else
	{
		if (myClippingPlane.IsNull())
		{
			myClippingPlane = new Graphic3d_ClipPlane();
			myView->AddClipPlane(myClippingPlane);
		}
		else if (myClippingPlane->IsOn())
			myClippingPlane->SetOn(false);

		myClippingPlane->SetEquation(clipPlane);
		myClippingPlane->SetOn(false);
		myView->Update();

		textEdit->insertPlainText("Clipping plane off\n");
	}
}

void QtOcct::startDeveloperSandboxRoutines()
{
	//TopoDS_Compound funnelCompound;
	//QString makeFunnelMsg;

	Standard_Real baseRad = 60.0;
	Standard_Real initWallAng = 15.0;
	Standard_Real funArcRad = 60.0;
	Standard_Real depth = 55.0;
	Standard_Real filletRad = 6.35;
	Standard_Real TOL = 0.002;

	//bool makeFunnelSuccess = part::makeFunnel(baseRad, initWallAng, funArcRad, depth, filletRad, TOL, funnelCompound, makeFunnelMsg);

	gp_Pnt botFaceLocation(0.0, 0.0, -57.25);
	gp_Dir botFaceNormal(0.0, 0.0, 1.0);
	gp_Pln botFacePlane(botFaceLocation, botFaceNormal);

	ampl::planeIntersecter contourObj(myCurrentPart, botFacePlane);
	contourObj.setEdgeToEdgeTol(0.50);
	std::string logMsg;
	if (!contourObj.performIntersect())
	{
		textEdit->insertPlainText(QString::fromStdString(logMsg));
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	contourObj.sortIntersection();

	Standard_Integer numWires;
	Standard_Integer numClosedWires;
	std::vector<int> closedWireIndices;
	TopoDS_Wire wireIntersect1;

	contourObj.getNumWires(numWires);
	contourObj.getNumClosedWires(numClosedWires, closedWireIndices);
	contourObj.toOcctWire(0, wireIntersect1);

	Handle(AIS_Shape) wireAis1 = new AIS_Shape(wireIntersect1);
	wireAis1->SetColor(Quantity_NOC_GREEN1);
	myContext->Display(wireAis1);

	// Discretize points
	//std::vector<gp_Pnt> pointsOnIntersect;
	//std::vector<TopoDS_Vertex> verticesOnIntersect;
	//TopoDS_Compound verticesAisOnIntersect;
	//BRep_Builder vertexCompoundBuilder;
	//vertexCompoundBuilder.MakeCompound(verticesAisOnIntersect);
	//contourObj.discretizeIntersection(0, 2.0, gp_Pnt(200.0, 0.0, 0.0), ampl::amplWireIntersection::CCW, pointsOnIntersect);

	//Standard_Integer numPoints = pointsOnIntersect.size();
	//TopoDS_Vertex localVertex;
	//for (Standard_Integer arrIndex = 0; arrIndex < numPoints; arrIndex++)
	//{
	//	localVertex = BRepBuilderAPI_MakeVertex(pointsOnIntersect.at(arrIndex));
	//	verticesOnIntersect.push_back(localVertex);
	//	vertexCompoundBuilder.Add(verticesAisOnIntersect, localVertex);
	//}

	//Handle(AIS_Shape) localAisPntArr = new AIS_Shape(verticesAisOnIntersect);
	//myContext->Display(localAisPntArr);
}