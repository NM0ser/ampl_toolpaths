/********************************************************************************
** Form generated from reading UI file 'QtOcct.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTOCCT_H
#define UI_QTOCCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtOcctClass
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionMake_Bottle;
    QAction *actionXY_View;
    QAction *actionYZ_View;
    QAction *actionZX_View;
    QAction *actionIsometric;
    QAction *actionPan;
    QAction *actionRotate;
    QAction *actionZoom;
    QAction *actionShaded;
    QAction *actionWireframe;
    QAction *actionFit_All;
    QAction *actionReset_View;
    QAction *actionRot_X;
    QAction *actionRot_Y;
    QAction *actionRot_Z;
    QAction *actionTruncated_Cone;
    QAction *actionTruncated_Pyramid;
    QAction *actionArc_Based_Funnel;
    QAction *actionImport_IGS;
    QAction *actionBox_Demo;
    QAction *actionSphere_Demo;
    QAction *actionTranslate_Part;
    QAction *actionRotate_Part;
    QAction *actionSPIF;
    QAction *actionTPIF;
    QAction *actionDSIF;
    QAction *actionNU_Gen_1_DSIF_Machine;
    QAction *actionNU_Gen_2_DSIF_Machine;
    QAction *actionOptions;
    QAction *actionBackgroundBlack;
    QAction *actionBackgroundLight_Blue;
    QAction *actionBackgroundWhite;
    QAction *actionScale_Part;
    QAction *actionExport_to_IGS;
    QAction *actionHotkeys;
    QAction *actionExtract_Cross_Section;
    QAction *actionSurface_Deviation_Map;
    QAction *actionOrigin_Visible;
    QAction *actionLoad_AMPL_Toolpath;
    QAction *actionSave_AMPL_Toolpath;
    QAction *actionExport_Toolpath_to_CSV;
    QAction *actionContactPntSingleFeature;
    QAction *actionToolTipSingleFeaturePart;
    QAction *actionDev_Sandbox;
    QAction *actionVisibleToolpath;
    QAction *actionVisibleActivePart;
    QAction *actionImport_STEP;
    QAction *actionExport_STEP;
    QAction *actionClippingPlane;
    QAction *actionImport_Contact_Points;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QOpenGLWidget *openGLWidget;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuImport_CAD_Surface;
    QMenu *menuExport_CAD_Surface;
    QMenu *menuToolpath;
    QMenu *menuConvert_to_Machine_Code;
    QMenu *menuCreate_Tool_Tip_Points;
    QMenu *menuGenerate_Contact_Points;
    QMenu *menuHelp;
    QMenu *menuDemo;
    QMenu *menuDemo_Parts;
    QMenu *menuMove_Part;
    QMenu *menuISF_Part_Library;
    QMenu *menuView;
    QMenu *menuSettings;
    QMenu *menuBackground_Color;
    QMenu *menuPost_Tools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtOcctClass)
    {
        if (QtOcctClass->objectName().isEmpty())
            QtOcctClass->setObjectName(QStringLiteral("QtOcctClass"));
        QtOcctClass->resize(1200, 900);
        QIcon icon;
        icon.addFile(QStringLiteral(":/QtOcct/NU_N_Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        QtOcctClass->setWindowIcon(icon);
        actionExit = new QAction(QtOcctClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QtOcct/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionAbout = new QAction(QtOcctClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionMake_Bottle = new QAction(QtOcctClass);
        actionMake_Bottle->setObjectName(QStringLiteral("actionMake_Bottle"));
        actionXY_View = new QAction(QtOcctClass);
        actionXY_View->setObjectName(QStringLiteral("actionXY_View"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/QtOcct/XY_View_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionXY_View->setIcon(icon2);
        actionYZ_View = new QAction(QtOcctClass);
        actionYZ_View->setObjectName(QStringLiteral("actionYZ_View"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/QtOcct/YZ_View_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionYZ_View->setIcon(icon3);
        actionZX_View = new QAction(QtOcctClass);
        actionZX_View->setObjectName(QStringLiteral("actionZX_View"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/QtOcct/XZ_View_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZX_View->setIcon(icon4);
        actionIsometric = new QAction(QtOcctClass);
        actionIsometric->setObjectName(QStringLiteral("actionIsometric"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/QtOcct/Isometric_View_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIsometric->setIcon(icon5);
        actionPan = new QAction(QtOcctClass);
        actionPan->setObjectName(QStringLiteral("actionPan"));
        actionPan->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/QtOcct/PanView_Icon25x25.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPan->setIcon(icon6);
        actionRotate = new QAction(QtOcctClass);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        actionRotate->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/QtOcct/RotateView_Icon50x50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon7);
        actionZoom = new QAction(QtOcctClass);
        actionZoom->setObjectName(QStringLiteral("actionZoom"));
        actionZoom->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/QtOcct/ZoomView_Icon50x50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom->setIcon(icon8);
        actionShaded = new QAction(QtOcctClass);
        actionShaded->setObjectName(QStringLiteral("actionShaded"));
        actionShaded->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/QtOcct/Shaded_Icon48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShaded->setIcon(icon9);
        actionWireframe = new QAction(QtOcctClass);
        actionWireframe->setObjectName(QStringLiteral("actionWireframe"));
        actionWireframe->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/QtOcct/WireFrame_Icon48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWireframe->setIcon(icon10);
        actionFit_All = new QAction(QtOcctClass);
        actionFit_All->setObjectName(QStringLiteral("actionFit_All"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/QtOcct/FitAll_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFit_All->setIcon(icon11);
        actionReset_View = new QAction(QtOcctClass);
        actionReset_View->setObjectName(QStringLiteral("actionReset_View"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/QtOcct/ResetView_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset_View->setIcon(icon12);
        actionRot_X = new QAction(QtOcctClass);
        actionRot_X->setObjectName(QStringLiteral("actionRot_X"));
        actionRot_X->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/QtOcct/RotX_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRot_X->setIcon(icon13);
        actionRot_Y = new QAction(QtOcctClass);
        actionRot_Y->setObjectName(QStringLiteral("actionRot_Y"));
        actionRot_Y->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/QtOcct/RotY_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRot_Y->setIcon(icon14);
        actionRot_Z = new QAction(QtOcctClass);
        actionRot_Z->setObjectName(QStringLiteral("actionRot_Z"));
        actionRot_Z->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/QtOcct/RotZ_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRot_Z->setIcon(icon15);
        actionTruncated_Cone = new QAction(QtOcctClass);
        actionTruncated_Cone->setObjectName(QStringLiteral("actionTruncated_Cone"));
        actionTruncated_Pyramid = new QAction(QtOcctClass);
        actionTruncated_Pyramid->setObjectName(QStringLiteral("actionTruncated_Pyramid"));
        actionArc_Based_Funnel = new QAction(QtOcctClass);
        actionArc_Based_Funnel->setObjectName(QStringLiteral("actionArc_Based_Funnel"));
        actionImport_IGS = new QAction(QtOcctClass);
        actionImport_IGS->setObjectName(QStringLiteral("actionImport_IGS"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/QtOcct/import-file-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport_IGS->setIcon(icon16);
        actionBox_Demo = new QAction(QtOcctClass);
        actionBox_Demo->setObjectName(QStringLiteral("actionBox_Demo"));
        actionSphere_Demo = new QAction(QtOcctClass);
        actionSphere_Demo->setObjectName(QStringLiteral("actionSphere_Demo"));
        actionTranslate_Part = new QAction(QtOcctClass);
        actionTranslate_Part->setObjectName(QStringLiteral("actionTranslate_Part"));
        actionRotate_Part = new QAction(QtOcctClass);
        actionRotate_Part->setObjectName(QStringLiteral("actionRotate_Part"));
        actionSPIF = new QAction(QtOcctClass);
        actionSPIF->setObjectName(QStringLiteral("actionSPIF"));
        actionTPIF = new QAction(QtOcctClass);
        actionTPIF->setObjectName(QStringLiteral("actionTPIF"));
        actionDSIF = new QAction(QtOcctClass);
        actionDSIF->setObjectName(QStringLiteral("actionDSIF"));
        actionNU_Gen_1_DSIF_Machine = new QAction(QtOcctClass);
        actionNU_Gen_1_DSIF_Machine->setObjectName(QStringLiteral("actionNU_Gen_1_DSIF_Machine"));
        actionNU_Gen_2_DSIF_Machine = new QAction(QtOcctClass);
        actionNU_Gen_2_DSIF_Machine->setObjectName(QStringLiteral("actionNU_Gen_2_DSIF_Machine"));
        actionOptions = new QAction(QtOcctClass);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/QtOcct/gear_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptions->setIcon(icon17);
        actionOptions->setVisible(false);
        actionBackgroundBlack = new QAction(QtOcctClass);
        actionBackgroundBlack->setObjectName(QStringLiteral("actionBackgroundBlack"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/QtOcct/black_Color_icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBackgroundBlack->setIcon(icon18);
        actionBackgroundLight_Blue = new QAction(QtOcctClass);
        actionBackgroundLight_Blue->setObjectName(QStringLiteral("actionBackgroundLight_Blue"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/QtOcct/skyBlue_Color_icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBackgroundLight_Blue->setIcon(icon19);
        actionBackgroundWhite = new QAction(QtOcctClass);
        actionBackgroundWhite->setObjectName(QStringLiteral("actionBackgroundWhite"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/QtOcct/white_Color_icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBackgroundWhite->setIcon(icon20);
        actionScale_Part = new QAction(QtOcctClass);
        actionScale_Part->setObjectName(QStringLiteral("actionScale_Part"));
        actionExport_to_IGS = new QAction(QtOcctClass);
        actionExport_to_IGS->setObjectName(QStringLiteral("actionExport_to_IGS"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/QtOcct/export-file-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_to_IGS->setIcon(icon21);
        actionHotkeys = new QAction(QtOcctClass);
        actionHotkeys->setObjectName(QStringLiteral("actionHotkeys"));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/QtOcct/about_Icon24x24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHotkeys->setIcon(icon22);
        actionExtract_Cross_Section = new QAction(QtOcctClass);
        actionExtract_Cross_Section->setObjectName(QStringLiteral("actionExtract_Cross_Section"));
        actionSurface_Deviation_Map = new QAction(QtOcctClass);
        actionSurface_Deviation_Map->setObjectName(QStringLiteral("actionSurface_Deviation_Map"));
        actionOrigin_Visible = new QAction(QtOcctClass);
        actionOrigin_Visible->setObjectName(QStringLiteral("actionOrigin_Visible"));
        actionOrigin_Visible->setCheckable(true);
        actionOrigin_Visible->setChecked(false);
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/QtOcct/VisibleOrigin_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOrigin_Visible->setIcon(icon23);
        actionLoad_AMPL_Toolpath = new QAction(QtOcctClass);
        actionLoad_AMPL_Toolpath->setObjectName(QStringLiteral("actionLoad_AMPL_Toolpath"));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/QtOcct/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_AMPL_Toolpath->setIcon(icon24);
        actionSave_AMPL_Toolpath = new QAction(QtOcctClass);
        actionSave_AMPL_Toolpath->setObjectName(QStringLiteral("actionSave_AMPL_Toolpath"));
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/QtOcct/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_AMPL_Toolpath->setIcon(icon25);
        actionExport_Toolpath_to_CSV = new QAction(QtOcctClass);
        actionExport_Toolpath_to_CSV->setObjectName(QStringLiteral("actionExport_Toolpath_to_CSV"));
        QIcon icon26;
        icon26.addFile(QStringLiteral(":/QtOcct/export-csv-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_Toolpath_to_CSV->setIcon(icon26);
        actionContactPntSingleFeature = new QAction(QtOcctClass);
        actionContactPntSingleFeature->setObjectName(QStringLiteral("actionContactPntSingleFeature"));
        actionToolTipSingleFeaturePart = new QAction(QtOcctClass);
        actionToolTipSingleFeaturePart->setObjectName(QStringLiteral("actionToolTipSingleFeaturePart"));
        actionDev_Sandbox = new QAction(QtOcctClass);
        actionDev_Sandbox->setObjectName(QStringLiteral("actionDev_Sandbox"));
        actionDev_Sandbox->setCheckable(false);
        actionDev_Sandbox->setEnabled(false);
        actionDev_Sandbox->setVisible(false);
        actionDev_Sandbox->setIconVisibleInMenu(false);
        actionVisibleToolpath = new QAction(QtOcctClass);
        actionVisibleToolpath->setObjectName(QStringLiteral("actionVisibleToolpath"));
        QIcon icon27;
        icon27.addFile(QStringLiteral(":/QtOcct/VisibleToolpath48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVisibleToolpath->setIcon(icon27);
        actionVisibleActivePart = new QAction(QtOcctClass);
        actionVisibleActivePart->setObjectName(QStringLiteral("actionVisibleActivePart"));
        actionVisibleActivePart->setCheckable(true);
        actionVisibleActivePart->setChecked(false);
        QIcon icon28;
        icon28.addFile(QStringLiteral(":/QtOcct/VisibleActivePart48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVisibleActivePart->setIcon(icon28);
        actionImport_STEP = new QAction(QtOcctClass);
        actionImport_STEP->setObjectName(QStringLiteral("actionImport_STEP"));
        actionImport_STEP->setIcon(icon16);
        actionExport_STEP = new QAction(QtOcctClass);
        actionExport_STEP->setObjectName(QStringLiteral("actionExport_STEP"));
        actionExport_STEP->setIcon(icon21);
        actionClippingPlane = new QAction(QtOcctClass);
        actionClippingPlane->setObjectName(QStringLiteral("actionClippingPlane"));
        QIcon icon29;
        icon29.addFile(QStringLiteral(":/QtOcct/clippingPlaneIcon_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClippingPlane->setIcon(icon29);
        actionImport_Contact_Points = new QAction(QtOcctClass);
        actionImport_Contact_Points->setObjectName(QStringLiteral("actionImport_Contact_Points"));
        QIcon icon30;
        icon30.addFile(QStringLiteral(":/QtOcct/import-csv-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport_Contact_Points->setIcon(icon30);
        centralWidget = new QWidget(QtOcctClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setMouseTracking(true);

        verticalLayout->addWidget(openGLWidget);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 102));
        QFont font;
        font.setPointSize(10);
        textEdit->setFont(font);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        QtOcctClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtOcctClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuImport_CAD_Surface = new QMenu(menuFile);
        menuImport_CAD_Surface->setObjectName(QStringLiteral("menuImport_CAD_Surface"));
        menuImport_CAD_Surface->setIcon(icon16);
        menuExport_CAD_Surface = new QMenu(menuFile);
        menuExport_CAD_Surface->setObjectName(QStringLiteral("menuExport_CAD_Surface"));
        menuExport_CAD_Surface->setIcon(icon21);
        menuToolpath = new QMenu(menuBar);
        menuToolpath->setObjectName(QStringLiteral("menuToolpath"));
        menuConvert_to_Machine_Code = new QMenu(menuToolpath);
        menuConvert_to_Machine_Code->setObjectName(QStringLiteral("menuConvert_to_Machine_Code"));
        menuCreate_Tool_Tip_Points = new QMenu(menuToolpath);
        menuCreate_Tool_Tip_Points->setObjectName(QStringLiteral("menuCreate_Tool_Tip_Points"));
        menuGenerate_Contact_Points = new QMenu(menuToolpath);
        menuGenerate_Contact_Points->setObjectName(QStringLiteral("menuGenerate_Contact_Points"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuDemo = new QMenu(menuBar);
        menuDemo->setObjectName(QStringLiteral("menuDemo"));
        menuDemo_Parts = new QMenu(menuDemo);
        menuDemo_Parts->setObjectName(QStringLiteral("menuDemo_Parts"));
        menuMove_Part = new QMenu(menuDemo);
        menuMove_Part->setObjectName(QStringLiteral("menuMove_Part"));
        menuISF_Part_Library = new QMenu(menuDemo);
        menuISF_Part_Library->setObjectName(QStringLiteral("menuISF_Part_Library"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuBackground_Color = new QMenu(menuSettings);
        menuBackground_Color->setObjectName(QStringLiteral("menuBackground_Color"));
        menuPost_Tools = new QMenu(menuBar);
        menuPost_Tools->setObjectName(QStringLiteral("menuPost_Tools"));
        QtOcctClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtOcctClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtOcctClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtOcctClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtOcctClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuDemo->menuAction());
        menuBar->addAction(menuToolpath->menuAction());
        menuBar->addAction(menuPost_Tools->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad_AMPL_Toolpath);
        menuFile->addAction(actionSave_AMPL_Toolpath);
        menuFile->addAction(actionImport_Contact_Points);
        menuFile->addAction(actionExport_Toolpath_to_CSV);
        menuFile->addSeparator();
        menuFile->addAction(menuImport_CAD_Surface->menuAction());
        menuFile->addAction(menuExport_CAD_Surface->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuImport_CAD_Surface->addAction(actionImport_IGS);
        menuImport_CAD_Surface->addAction(actionImport_STEP);
        menuExport_CAD_Surface->addAction(actionExport_to_IGS);
        menuExport_CAD_Surface->addAction(actionExport_STEP);
        menuToolpath->addAction(menuGenerate_Contact_Points->menuAction());
        menuToolpath->addSeparator();
        menuToolpath->addAction(menuCreate_Tool_Tip_Points->menuAction());
        menuToolpath->addSeparator();
        menuToolpath->addAction(menuConvert_to_Machine_Code->menuAction());
        menuConvert_to_Machine_Code->addAction(actionNU_Gen_1_DSIF_Machine);
        menuConvert_to_Machine_Code->addAction(actionNU_Gen_2_DSIF_Machine);
        menuCreate_Tool_Tip_Points->addAction(actionToolTipSingleFeaturePart);
        menuGenerate_Contact_Points->addAction(actionContactPntSingleFeature);
        menuHelp->addAction(actionHotkeys);
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionDev_Sandbox);
        menuDemo->addAction(menuISF_Part_Library->menuAction());
        menuDemo->addSeparator();
        menuDemo->addAction(menuDemo_Parts->menuAction());
        menuDemo->addSeparator();
        menuDemo->addAction(menuMove_Part->menuAction());
        menuDemo_Parts->addAction(actionBox_Demo);
        menuDemo_Parts->addAction(actionSphere_Demo);
        menuDemo_Parts->addAction(actionMake_Bottle);
        menuMove_Part->addAction(actionTranslate_Part);
        menuMove_Part->addAction(actionRotate_Part);
        menuMove_Part->addAction(actionScale_Part);
        menuISF_Part_Library->addAction(actionTruncated_Cone);
        menuISF_Part_Library->addAction(actionTruncated_Pyramid);
        menuISF_Part_Library->addAction(actionArc_Based_Funnel);
        menuView->addAction(actionFit_All);
        menuView->addAction(actionReset_View);
        menuView->addSeparator();
        menuView->addAction(actionXY_View);
        menuView->addAction(actionYZ_View);
        menuView->addAction(actionZX_View);
        menuView->addAction(actionIsometric);
        menuView->addSeparator();
        menuView->addAction(actionPan);
        menuView->addAction(actionRotate);
        menuView->addAction(actionZoom);
        menuView->addSeparator();
        menuView->addAction(actionShaded);
        menuView->addAction(actionWireframe);
        menuSettings->addAction(menuBackground_Color->menuAction());
        menuSettings->addSeparator();
        menuSettings->addAction(actionOptions);
        menuBackground_Color->addAction(actionBackgroundBlack);
        menuBackground_Color->addAction(actionBackgroundLight_Blue);
        menuBackground_Color->addAction(actionBackgroundWhite);
        menuPost_Tools->addAction(actionExtract_Cross_Section);
        menuPost_Tools->addAction(actionSurface_Deviation_Map);
        mainToolBar->addAction(actionFit_All);
        mainToolBar->addAction(actionReset_View);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionXY_View);
        mainToolBar->addAction(actionYZ_View);
        mainToolBar->addAction(actionZX_View);
        mainToolBar->addAction(actionIsometric);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPan);
        mainToolBar->addAction(actionRotate);
        mainToolBar->addAction(actionZoom);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRot_X);
        mainToolBar->addAction(actionRot_Y);
        mainToolBar->addAction(actionRot_Z);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionShaded);
        mainToolBar->addAction(actionWireframe);
        mainToolBar->addAction(actionClippingPlane);
        mainToolBar->addAction(actionVisibleActivePart);
        mainToolBar->addAction(actionOrigin_Visible);
        mainToolBar->addAction(actionVisibleToolpath);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionHotkeys);
        mainToolBar->addAction(actionDev_Sandbox);

        retranslateUi(QtOcctClass);
        QObject::connect(actionExit, SIGNAL(triggered()), QtOcctClass, SLOT(close()));

        QMetaObject::connectSlotsByName(QtOcctClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtOcctClass)
    {
        QtOcctClass->setWindowTitle(QApplication::translate("QtOcctClass", "AMPL Toolpaths", Q_NULLPTR));
        actionExit->setText(QApplication::translate("QtOcctClass", "Exit", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionExit->setStatusTip(QApplication::translate("QtOcctClass", "Exit", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionAbout->setText(QApplication::translate("QtOcctClass", "About", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("QtOcctClass", "Show version and development information about AMPL Toolpaths", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("QtOcctClass", "Show version and development information about AMPL Toolpaths", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionMake_Bottle->setText(QApplication::translate("QtOcctClass", "Bottle Demo", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionMake_Bottle->setToolTip(QApplication::translate("QtOcctClass", "Make a thick-walled bottle with threads", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionMake_Bottle->setStatusTip(QApplication::translate("QtOcctClass", "Make a thick-walled bottle with threads", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionXY_View->setText(QApplication::translate("QtOcctClass", "XY-View", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionXY_View->setToolTip(QApplication::translate("QtOcctClass", "View scene normal to the XY-plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionXY_View->setStatusTip(QApplication::translate("QtOcctClass", "View scene normal to the XY-plane", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionYZ_View->setText(QApplication::translate("QtOcctClass", "YZ-View", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionYZ_View->setToolTip(QApplication::translate("QtOcctClass", "View scene normal to the YZ-plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionYZ_View->setStatusTip(QApplication::translate("QtOcctClass", "View scene normal to the YZ-plane", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionZX_View->setText(QApplication::translate("QtOcctClass", "XZ-View", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionZX_View->setToolTip(QApplication::translate("QtOcctClass", "View scene normal to the XZ-plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionZX_View->setStatusTip(QApplication::translate("QtOcctClass", "View scene normal to the XZ-plane", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionIsometric->setText(QApplication::translate("QtOcctClass", "Isometric", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionIsometric->setToolTip(QApplication::translate("QtOcctClass", "View the scene along the [1, 1, 1] vector", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionIsometric->setStatusTip(QApplication::translate("QtOcctClass", "View the scene along the [1, 1, 1] vector", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionPan->setText(QApplication::translate("QtOcctClass", "Pan", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPan->setToolTip(QApplication::translate("QtOcctClass", "Dynamic translation of the scene", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPan->setStatusTip(QApplication::translate("QtOcctClass", "Dynamic translation of the scene", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionRotate->setText(QApplication::translate("QtOcctClass", "Rotate", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRotate->setToolTip(QApplication::translate("QtOcctClass", "Dynamic rotation of the scene", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRotate->setStatusTip(QApplication::translate("QtOcctClass", "Dynamic rotation of the scene", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionZoom->setText(QApplication::translate("QtOcctClass", "Zoom", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionZoom->setToolTip(QApplication::translate("QtOcctClass", "Dynamic zooming of the scene", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionZoom->setStatusTip(QApplication::translate("QtOcctClass", "Dynamic zooming of the scene", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionShaded->setText(QApplication::translate("QtOcctClass", "Shaded", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShaded->setToolTip(QApplication::translate("QtOcctClass", "Change shape visualization mode to shaded", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionShaded->setStatusTip(QApplication::translate("QtOcctClass", "Change shape visualization mode to shaded", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionWireframe->setText(QApplication::translate("QtOcctClass", "Wireframe", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionWireframe->setToolTip(QApplication::translate("QtOcctClass", "Change shape visualization mode to wireframe", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionWireframe->setStatusTip(QApplication::translate("QtOcctClass", "Change shape visualization mode to wireframe", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionFit_All->setText(QApplication::translate("QtOcctClass", "Fit All", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionFit_All->setToolTip(QApplication::translate("QtOcctClass", "Auto-fit whole scene in the viewer", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionFit_All->setStatusTip(QApplication::translate("QtOcctClass", "Auto-fit whole scene in the viewer", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionReset_View->setText(QApplication::translate("QtOcctClass", "Reset View", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionReset_View->setToolTip(QApplication::translate("QtOcctClass", "Reset the view to the default orientation", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionReset_View->setStatusTip(QApplication::translate("QtOcctClass", "Reset the view to the default orientation", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionRot_X->setText(QApplication::translate("QtOcctClass", "Rot. X", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRot_X->setToolTip(QApplication::translate("QtOcctClass", "Use left/right arrow keys to rotate about the x-axis", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRot_X->setStatusTip(QApplication::translate("QtOcctClass", "Use left/right arrow keys to rotate about the x-axis", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionRot_X->setShortcut(QApplication::translate("QtOcctClass", "X", Q_NULLPTR));
        actionRot_Y->setText(QApplication::translate("QtOcctClass", "Rot. Y", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRot_Y->setToolTip(QApplication::translate("QtOcctClass", "Use left/right arrow keys to rotate about the y-axis", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRot_Y->setStatusTip(QApplication::translate("QtOcctClass", "Use left/right arrow keys to rotate about the y-axis", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionRot_Y->setShortcut(QApplication::translate("QtOcctClass", "Y", Q_NULLPTR));
        actionRot_Z->setText(QApplication::translate("QtOcctClass", "Rot. Z", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRot_Z->setToolTip(QApplication::translate("QtOcctClass", "Use left/right arrow keys to rotate about the z-axis", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRot_Z->setStatusTip(QApplication::translate("QtOcctClass", "Use left/right arrow keys to rotate about the z-axis", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionRot_Z->setShortcut(QApplication::translate("QtOcctClass", "Z", Q_NULLPTR));
        actionTruncated_Cone->setText(QApplication::translate("QtOcctClass", "Truncated Cone", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionTruncated_Cone->setToolTip(QApplication::translate("QtOcctClass", "Generate a user-defined truncated cone", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionTruncated_Cone->setStatusTip(QApplication::translate("QtOcctClass", "Generate a user-defined truncated cone", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionTruncated_Pyramid->setText(QApplication::translate("QtOcctClass", "Truncated Pyramid", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionTruncated_Pyramid->setToolTip(QApplication::translate("QtOcctClass", "Generate a user-defined truncated pyramid", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionTruncated_Pyramid->setStatusTip(QApplication::translate("QtOcctClass", "Generate a user-defined truncated pyramid", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionArc_Based_Funnel->setText(QApplication::translate("QtOcctClass", "Arc-Based Funnel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionArc_Based_Funnel->setToolTip(QApplication::translate("QtOcctClass", "Generate a user-defined funnel", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionArc_Based_Funnel->setStatusTip(QApplication::translate("QtOcctClass", "Generate a user-defined funnel", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionImport_IGS->setText(QApplication::translate("QtOcctClass", "Import IGS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionImport_IGS->setToolTip(QApplication::translate("QtOcctClass", "Import an IGS file. Part must be suitable for toolpath generation.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionImport_IGS->setStatusTip(QApplication::translate("QtOcctClass", "Import an IGS file. Part must be suitable for toolpath generation.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionBox_Demo->setText(QApplication::translate("QtOcctClass", "Box Demo", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBox_Demo->setToolTip(QApplication::translate("QtOcctClass", "Make a solid cube", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionBox_Demo->setStatusTip(QApplication::translate("QtOcctClass", "Make a solid cube", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionSphere_Demo->setText(QApplication::translate("QtOcctClass", "Sphere Demo", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSphere_Demo->setToolTip(QApplication::translate("QtOcctClass", "Make a solid sphere", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSphere_Demo->setStatusTip(QApplication::translate("QtOcctClass", "Make a solid sphere", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionTranslate_Part->setText(QApplication::translate("QtOcctClass", "Translate Part", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionTranslate_Part->setToolTip(QApplication::translate("QtOcctClass", "Translate active part", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionTranslate_Part->setStatusTip(QApplication::translate("QtOcctClass", "Translate active part", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionRotate_Part->setText(QApplication::translate("QtOcctClass", "Rotate Part", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRotate_Part->setToolTip(QApplication::translate("QtOcctClass", "Rotate active part", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRotate_Part->setStatusTip(QApplication::translate("QtOcctClass", "Rotate active part", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionSPIF->setText(QApplication::translate("QtOcctClass", "SPIF", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSPIF->setToolTip(QApplication::translate("QtOcctClass", "From contact points, calculate SPIF tool tip points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSPIF->setStatusTip(QApplication::translate("QtOcctClass", "From contact points, calculate SPIF tool tip points", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionTPIF->setText(QApplication::translate("QtOcctClass", "TPIF", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionTPIF->setToolTip(QApplication::translate("QtOcctClass", "From contact points, calculate TPIF tool tip points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionTPIF->setStatusTip(QApplication::translate("QtOcctClass", "From contact points, calculate TPIF tool tip points", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionDSIF->setText(QApplication::translate("QtOcctClass", "DSIF", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDSIF->setToolTip(QApplication::translate("QtOcctClass", "From contact points, calculate DSIF tool tip points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDSIF->setStatusTip(QApplication::translate("QtOcctClass", "From contact points, calculate DSIF tool tip points", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionNU_Gen_1_DSIF_Machine->setText(QApplication::translate("QtOcctClass", "NU Gen. 1 DSIF Machine", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionNU_Gen_1_DSIF_Machine->setToolTip(QApplication::translate("QtOcctClass", "Convert tool tip points into machine code for NU's Gen. 1 DSIF Machine", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionNU_Gen_1_DSIF_Machine->setStatusTip(QApplication::translate("QtOcctClass", "Convert tool tip points into machine code for NU's Gen. 1 DSIF Machine", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionNU_Gen_2_DSIF_Machine->setText(QApplication::translate("QtOcctClass", "NU Gen. 2 Tri-Pyram. DSIF Machine", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionNU_Gen_2_DSIF_Machine->setToolTip(QApplication::translate("QtOcctClass", "Convert tool tip points into machine code for NU's Gen. 2 Tri-Pyram. DSIF Machine", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionNU_Gen_2_DSIF_Machine->setStatusTip(QApplication::translate("QtOcctClass", "Convert tool tip points into machine code for NU's Gen. 2 Tri-Pyram. DSIF Machine", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionOptions->setText(QApplication::translate("QtOcctClass", "Options", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOptions->setToolTip(QApplication::translate("QtOcctClass", "Change settings in viewer updates and input/output buffers", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionOptions->setStatusTip(QApplication::translate("QtOcctClass", "Change settings in viewer updates and input/output buffers", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionBackgroundBlack->setText(QApplication::translate("QtOcctClass", "Black", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBackgroundBlack->setToolTip(QApplication::translate("QtOcctClass", "Change background color to black", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionBackgroundBlack->setStatusTip(QApplication::translate("QtOcctClass", "Change background color to black", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionBackgroundLight_Blue->setText(QApplication::translate("QtOcctClass", "Sky Blue", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBackgroundLight_Blue->setToolTip(QApplication::translate("QtOcctClass", "Change background color to sky blue", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionBackgroundLight_Blue->setStatusTip(QApplication::translate("QtOcctClass", "Change background color to sky blue", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionBackgroundWhite->setText(QApplication::translate("QtOcctClass", "White", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBackgroundWhite->setToolTip(QApplication::translate("QtOcctClass", "Change background color to white", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionBackgroundWhite->setStatusTip(QApplication::translate("QtOcctClass", "Change background color to white", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionScale_Part->setText(QApplication::translate("QtOcctClass", "Scale Part", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionScale_Part->setToolTip(QApplication::translate("QtOcctClass", "Scale active part", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionScale_Part->setStatusTip(QApplication::translate("QtOcctClass", "Scale active part", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionExport_to_IGS->setText(QApplication::translate("QtOcctClass", "Export to IGS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionExport_to_IGS->setToolTip(QApplication::translate("QtOcctClass", "Export current part to an IGS file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionExport_to_IGS->setStatusTip(QApplication::translate("QtOcctClass", "Export current part to an IGS file", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionHotkeys->setText(QApplication::translate("QtOcctClass", "Hotkeys", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionHotkeys->setToolTip(QApplication::translate("QtOcctClass", "Shows useful keyboard short cuts", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionHotkeys->setStatusTip(QApplication::translate("QtOcctClass", "Shows useful keyboard short cuts", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionExtract_Cross_Section->setText(QApplication::translate("QtOcctClass", "Extract Cross Section", Q_NULLPTR));
        actionSurface_Deviation_Map->setText(QApplication::translate("QtOcctClass", "Two-Surface Deviation Map", Q_NULLPTR));
        actionOrigin_Visible->setText(QApplication::translate("QtOcctClass", "Origin Visible", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOrigin_Visible->setToolTip(QApplication::translate("QtOcctClass", "Toggles the visibility of the origin", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionOrigin_Visible->setStatusTip(QApplication::translate("QtOcctClass", "Toggles the visibility of the origin", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionLoad_AMPL_Toolpath->setText(QApplication::translate("QtOcctClass", "Load AMPL Toolpath", Q_NULLPTR));
        actionSave_AMPL_Toolpath->setText(QApplication::translate("QtOcctClass", "Save AMPL Toolpath", Q_NULLPTR));
        actionExport_Toolpath_to_CSV->setText(QApplication::translate("QtOcctClass", "Export Toolpath to CSV", Q_NULLPTR));
        actionContactPntSingleFeature->setText(QApplication::translate("QtOcctClass", "Single Feature Part", Q_NULLPTR));
        actionToolTipSingleFeaturePart->setText(QApplication::translate("QtOcctClass", "Single Feature Part", Q_NULLPTR));
        actionDev_Sandbox->setText(QApplication::translate("QtOcctClass", "Dev. Sandbox", Q_NULLPTR));
        actionVisibleToolpath->setText(QApplication::translate("QtOcctClass", "actionVisibleToolpath", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionVisibleToolpath->setToolTip(QApplication::translate("QtOcctClass", "Change the options related to visualizing the active toolpath", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionVisibleToolpath->setStatusTip(QApplication::translate("QtOcctClass", "Change the options related to visualizing the active toolpath", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionVisibleActivePart->setText(QApplication::translate("QtOcctClass", "visibleActivePart", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionVisibleActivePart->setToolTip(QApplication::translate("QtOcctClass", "Toggle the visibility of the current part", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionVisibleActivePart->setStatusTip(QApplication::translate("QtOcctClass", "Toggle the visibility of the current part", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionImport_STEP->setText(QApplication::translate("QtOcctClass", "Import STEP", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionImport_STEP->setToolTip(QApplication::translate("QtOcctClass", "Import an STEP file using standard AP214. Part must be suitable for toolpath generation.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionImport_STEP->setStatusTip(QApplication::translate("QtOcctClass", "Import an STEP file using standard AP214. Part must be suitable for toolpath generation.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionExport_STEP->setText(QApplication::translate("QtOcctClass", "Export STEP", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionExport_STEP->setToolTip(QApplication::translate("QtOcctClass", "Export current part to an STEP file using standard AP214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionExport_STEP->setStatusTip(QApplication::translate("QtOcctClass", "Export current part to an STEP file using standard AP214", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionClippingPlane->setText(QApplication::translate("QtOcctClass", "ClippingPlane", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionClippingPlane->setToolTip(QApplication::translate("QtOcctClass", "Define a clipping plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionClippingPlane->setStatusTip(QApplication::translate("QtOcctClass", "Define a clipping plane", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionImport_Contact_Points->setText(QApplication::translate("QtOcctClass", "Import Contact Points", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("QtOcctClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("QtOcctClass", "File", Q_NULLPTR));
        menuImport_CAD_Surface->setTitle(QApplication::translate("QtOcctClass", "Import CAD Surface", Q_NULLPTR));
        menuExport_CAD_Surface->setTitle(QApplication::translate("QtOcctClass", "Export CAD Surface", Q_NULLPTR));
        menuToolpath->setTitle(QApplication::translate("QtOcctClass", "Toolpath", Q_NULLPTR));
        menuConvert_to_Machine_Code->setTitle(QApplication::translate("QtOcctClass", "Convert to Machine Code", Q_NULLPTR));
        menuCreate_Tool_Tip_Points->setTitle(QApplication::translate("QtOcctClass", "Calculate Tool Tip Points", Q_NULLPTR));
        menuGenerate_Contact_Points->setTitle(QApplication::translate("QtOcctClass", "Generate Contact Points", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("QtOcctClass", "Help", Q_NULLPTR));
        menuDemo->setTitle(QApplication::translate("QtOcctClass", "Part", Q_NULLPTR));
        menuDemo_Parts->setTitle(QApplication::translate("QtOcctClass", "Demo Shapes", Q_NULLPTR));
        menuMove_Part->setTitle(QApplication::translate("QtOcctClass", "Move Part", Q_NULLPTR));
        menuISF_Part_Library->setTitle(QApplication::translate("QtOcctClass", "ISF Part Library", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("QtOcctClass", "View", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("QtOcctClass", "Settings", Q_NULLPTR));
        menuBackground_Color->setTitle(QApplication::translate("QtOcctClass", "Background Color", Q_NULLPTR));
        menuPost_Tools->setTitle(QApplication::translate("QtOcctClass", "Post Tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtOcctClass: public Ui_QtOcctClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTOCCT_H
