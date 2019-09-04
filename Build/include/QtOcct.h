#pragma once
#include "stdafx.h"

#define PI 3.14159265358979323846

// AMPL headers
#include "amplToolpath.h"
#include "amplWireIntersection.h"
#include "planeIntersecter.h"
#include "SPIF.h"
#include "TPIF.h"
#include "DSIF.h"
#include "ADSIF.h"

#include "ui_QtOcct.h"
#include "translateDialog.h"
#include "scaleDialog.h"
#include "rotationDialog.h"
#include "trunConeDialog.h"
#include "hotkeysDialog.h"
#include "funnelDialog.h"
#include "exportIGSDialog.h"
#include "importIGSDialog.h"
#include "importCSVContactPntsDialog.h"
#include "exportAmplToolpathDialog.h"
#include "openAmplToolpathDialog.h"
#include "saveAmplToolpathDialog.h"
#include "singFeatureToolpathInputDialog.h"
#include "singleFeatureToolTipGenDialog.h"
#include "toolpathVisibilityDialog.h"
#include "clipPlaneDialog.h"
#include "exportToGen1MachineCodeDialog.h"
#include "exportCrossSectionDialog.h"
#include "calc2SurfDeviationErrorDialog.h"
#include "amplLineRegion.h"
#include "amplRectRegion.h"

class QtOcct : public QMainWindow, private Ui::QtOcctClass
{
	Q_OBJECT

public:
	QtOcct(QWidget *parent = Q_NULLPTR); //Constructor
	~QtOcct(); // Destructor

	const Handle(AIS_InteractiveContext)& getContext() const;

	enum CurrentAction3d
	{
		CurAction3d_Nothing,
		CurAction3d_DynamicZooming,
		CurAction3d_WindowZooming,
		CurAction3d_DynamicPanning,
		CurAction3d_GlobalPanning,
		CurAction3d_DynamicRotation
	};

	enum CurrentRotationAxis
	{
		CurRotAxis_X,
		CurRotAxis_Y,
		CurRotAxis_Z
	};

protected:
	// Paint events.
	virtual void paintEvent(QPaintEvent* e);
	virtual void resizeEvent(QResizeEvent* e);
	
	// Mouse events.
	virtual void mousePressEvent(QMouseEvent* e);
	virtual void mouseMoveEvent(QMouseEvent * e);
	virtual void wheelEvent(QWheelEvent * e);

	// Keyboard events
	virtual void keyPressEvent(QKeyEvent* e);

	// Mouse button tasks.
	virtual void onLButtonDown(const int theFlags, const QPoint thePoint);
	virtual void onMButtonDown(const int theFlags, const QPoint thePoint);
	virtual void onRButtonDown(const int theFlags, const QPoint thePoint);
	virtual void onMouseWheel(const int theFlags, const int theDelta, const QPoint thePoint);
	virtual void onMouseMove(const int theFlags, const QPoint thePoint);

	// Keyboard tasks
	virtual void onUpKeyPress(const int theFlags);
	virtual void onDownKeyPress(const int theFlags);
	virtual void onRightKeyPress(const int theFlags);
	virtual void onLeftKeyPress(const int theFlags);

protected:
	/* Functions that utilize OCC selection features -> Not needed at this time */
	virtual void mouseReleaseEvent(QMouseEvent* e);
	virtual void onLButtonUp(const int theFlags, const QPoint thePoint);
	//virtual void onMButtonUp(const int theFlags, const QPoint thePoint);
	//virtual void onRButtonUp(const int theFlags, const QPoint thePoint);
	//void popup(const int x, const int y);
	//void dragEvent(const int x, const int y);
	//void inputEvent(const int x, const int y);
	//void moveEvent(const int x, const int y);
	//void multiMoveEvent(const int x, const int y);
	//void multiDragEvent(const int x, const int y);
	//void multiInputEvent(const int x, const int y);
	//void drawRubberBand(const int minX, const int minY, const int maxX, const int maxY);
	//! save the degenerate mode state.
	//Standard_Boolean myDegenerateModeIsOn;
	//! rubber rectangle for the mouse selection.
	//QRubberBand* myRectBand;

private:

	void createActions();
	QActionGroup *rotAxisGroup;
	QActionGroup *surfaceShadingGroup;

	//! Initialize the OCC OpenGL context within Qt
	void initOpenGL();

	//! the occ viewer.
	Handle(V3d_Viewer) myViewer = nullptr;

	//! the occ view.
	Handle(V3d_View) myView = nullptr;

	//! the occ context.
	Handle(AIS_InteractiveContext) myContext = nullptr;

	//! the mouse current mode.
	CurrentAction3d myCurrentMode;
	CurrentRotationAxis myCurrentRotAxis;

	//! Current message in text edit
	//QString myCurMsg;

	//! mouse coordinates
	Standard_Integer myXmin;
	Standard_Integer myYmin;
	Standard_Integer myXmax;
	Standard_Integer myYmax;
	Standard_Boolean zoomInBool;

	//! only one compound-surface part can be active at a time, stored in myCurrentPart
	amplToolpath myCurrentToolpath;
	TopoDS_Compound myCurrentPart;
	TopoDS_Compound myCurrentOrigin;
	TopoDS_Compound myCurrentTopToolTips;
	TopoDS_Compound myCurrentBotToolTips;
	TopoDS_Compound myCurrentTopContactPnts;
	TopoDS_Compound myCurrentBotContactPnts;

	Handle(AIS_Shape) myAisShape = nullptr;
	Handle(AIS_Shape) myAisOrigin = nullptr;
	Handle(AIS_Shape) myAisTopToolTips = nullptr;
	Handle(AIS_Shape) myAisBotToolTips = nullptr;
	Handle(AIS_Shape) myAisTopContactPnts = nullptr;
	Handle(AIS_Shape) myAisBotContactPnts = nullptr;
	Handle(Graphic3d_ClipPlane) myClippingPlane = nullptr;
	bool partIsActive = false;

	Ui::QtOcctClass ui;

	translateDialog *myTransDialog = new translateDialog(this);
	scaleDialog *myScaleDialog  = new scaleDialog(this);
	rotationDialog *myRotDialog = new rotationDialog(this);
	trunConeDialog *myTrunConeDialog = new trunConeDialog(this);
	trunConeDialog *myPyramidDialog = new trunConeDialog(this);
	hotkeysDialog *myHotKeysDialog = new hotkeysDialog(this);
	funnelDialog *myFunnelDialog = new funnelDialog(this);
	singFeatureToolpathInputDialog *myToolpathInputDialog = new singFeatureToolpathInputDialog(this);
	singleFeatureToolTipGenDialog *myToolTipGenerationDialog = new singleFeatureToolTipGenDialog(this);
	toolpathVisibilityDialog *myToolpathVisibilityDialog = new toolpathVisibilityDialog(this);
	clipPlaneDialog *myClippingPlaneDialog = new clipPlaneDialog(this);
	
	void startSingFeatureToolpathInput(void);
	void startSingFeatureToolTipCalculation(const bool checkSelfIntersectingToolpath, const int performConstZHeightTips);

private slots:
	void showExportAsIGSDialogSlot(void);
	void showImportIGSDialogSlot(void);
	void showExportAsSTEPDialogSlot(void);
	void showImportSTEPDialogSlot(void);
	void showImportContactPntsDialogSlot(void);
	void showSaveAmplToolpathDialogSlot(void);
	void showOpenAmplToolpathDialogSlot(void);
	void showExportAmplToolpathDialogSlot(void);

	void makeBottleSlot(void);
	void makeBoxSlot(void);
	void makeSphereSlot(void);
	void showTranslatePartDialogSlot(void);
	void translatePartSlot(void);
	void showRotatePartDialogSlot(void);
	void rotatePartSlot(void);
	void showScalePartDialogSlot(void);
	void scalePartSlot(void);

	void pan(void);
	void fitAll(void);
	void reset(void);
	void zoom(void);
	void rotate(void);
	void wireFrameSlot(void);
	void shadedSlot(void);
	void changeRotAxisX_Slot(void);
	void changeRotAxisY_Slot(void);
	void changeRotAxisZ_Slot(void);
	void setXYViewSlot(void);
	void setYZViewSlot(void);
	void setZXViewSlot(void);
	void setIsometricViewSlot(void);
	void setBackgroundColorBlackSlot(void);
	void setBackgroundColorWhiteSlot(void);
	void setBackgroundColorBlueSlot(void);
	void showHotKeysDialogSlot(void);
	void showAboutDialogSlot(void);
	void showOriginSlot(void);
	void showActivePartSlot(void);
	void showToolpathVisibilityDialogSlot(void);
	void setToolpathVisibilitySlot(bool hideAll);
	void showClippingPlaneDialogSlot(void);
	void setClippingPlaneDialogSlot(void);

	void showTrunConeDialogSlot(void);
	void makeTrunConeSlot(void);
	void showPyramidDialogSlot(void);
	void makePyramidSlot(void);
	void showFunnelDialogSlot(void);
	void makeFunnelSlot(void);

	void showSingFeatureToolpathInputDialogSlot(void);
	void showSingFeatureCalcToolTipsDialogSlot(void);
	void showExportToGen1MachineCodeDialogSlot(void);
	void showExportToGen2MachineCodeDialogSlot(void);
	void showExtractCrossSectionToolDialogSlot(void);
	void showCalcTwoSurfDeviationDialogSlot(void);

	void startDeveloperSandboxRoutines(void);

signals:
	//void selectionChanged(void);
};

namespace part
{
	bool makeTrunCone(const Standard_Real &baseRad, const Standard_Real &wallAngle,
		const Standard_Real &depth, const Standard_Real &filletRad,
		const Standard_Real &TOL, TopoDS_Compound &myTrunConeOut, QString &logOut);

	bool makePyramid(const Standard_Real &baseWidth, const Standard_Real &wallAngle,
		const Standard_Real &depth, const Standard_Real &filletRad,
		const Standard_Real &TOL, TopoDS_Compound &myPyramidOut, QString &logOut);;

	bool makeFunnel(const Standard_Real &baseRad, const Standard_Real &initWallAng,
		const Standard_Real &funArcRad, const Standard_Real &depth, const Standard_Real &filletRad,
		const Standard_Real &TOL, TopoDS_Compound &myFunnelOut, QString &logOut);
}
