/********************************************************************************
** Form generated from reading UI file 'singFeatureToolpathInputDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGFEATURETOOLPATHINPUTDIALOG_H
#define UI_SINGFEATURETOOLPATHINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_singFeatureToolpathInputDialog
{
public:
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_10;
    QFrame *frame_16;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_59;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_60;
    QPushButton *firstTimeHelpPushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_11;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_21;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *spifRadioButton;
    QRadioButton *tpifRadioButton;
    QRadioButton *dsifRadioButton;
    QRadioButton *adsifRadioButton;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *isfSetupHelpPushButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_13;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_56;
    QDoubleSpinBox *sheetThickSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_57;
    QDoubleSpinBox *topToolDiamSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_58;
    QDoubleSpinBox *botToolDiamSpinBox;
    QFrame *frame_22;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *negZFormingDirRadioButton;
    QRadioButton *posZFormingDirRadioButton;
    QFrame *frame_23;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *femaleDieShapeRadioButton;
    QRadioButton *maleDieShapeRadioButton;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *toolingParamAdvPushButton;
    QPushButton *toolingParamHelpPushButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_14;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_24;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *zLevelSlicingRadioButton;
    QRadioButton *spiralToolpathRadioButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_65;
    QDoubleSpinBox *startHeightSpinBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_62;
    QDoubleSpinBox *endHeightSpinBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_61;
    QDoubleSpinBox *incDepthSpinBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_63;
    QDoubleSpinBox *sqzFactorSpinBox;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_64;
    QDoubleSpinBox *resolToolpathCurveSpinBox;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *toolpathParamAdvPushButton;
    QPushButton *toolpathParamHelpPushButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *startPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *singFeatureToolpathInputDialog)
    {
        if (singFeatureToolpathInputDialog->objectName().isEmpty())
            singFeatureToolpathInputDialog->setObjectName(QStringLiteral("singFeatureToolpathInputDialog"));
        singFeatureToolpathInputDialog->resize(742, 579);
        verticalLayout_9 = new QVBoxLayout(singFeatureToolpathInputDialog);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_10 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_10);

        frame_16 = new QFrame(singFeatureToolpathInputDialog);
        frame_16->setObjectName(QStringLiteral("frame_16"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame_16);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_59 = new QLabel(frame_16);
        label_59->setObjectName(QStringLiteral("label_59"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(13);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_59->setFont(font);
        label_59->setAlignment(Qt::AlignCenter);
        label_59->setWordWrap(true);

        verticalLayout->addWidget(label_59);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_60 = new QLabel(frame_16);
        label_60->setObjectName(QStringLiteral("label_60"));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_60->setFont(font1);

        horizontalLayout->addWidget(label_60);

        firstTimeHelpPushButton = new QPushButton(frame_16);
        firstTimeHelpPushButton->setObjectName(QStringLiteral("firstTimeHelpPushButton"));
        QFont font2;
        font2.setPointSize(10);
        firstTimeHelpPushButton->setFont(font2);

        horizontalLayout->addWidget(firstTimeHelpPushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_14->addWidget(frame_16);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_11);

        groupBox_10 = new QGroupBox(singFeatureToolpathInputDialog);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        groupBox_10->setFont(font3);
        verticalLayout_3 = new QVBoxLayout(groupBox_10);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame_21 = new QFrame(groupBox_10);
        frame_21->setObjectName(QStringLiteral("frame_21"));
        frame_21->setFrameShape(QFrame::NoFrame);
        frame_21->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_21);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        spifRadioButton = new QRadioButton(frame_21);
        spifRadioButton->setObjectName(QStringLiteral("spifRadioButton"));
        spifRadioButton->setFont(font2);
        spifRadioButton->setChecked(true);

        verticalLayout_2->addWidget(spifRadioButton);

        tpifRadioButton = new QRadioButton(frame_21);
        tpifRadioButton->setObjectName(QStringLiteral("tpifRadioButton"));
        tpifRadioButton->setFont(font2);

        verticalLayout_2->addWidget(tpifRadioButton);

        dsifRadioButton = new QRadioButton(frame_21);
        dsifRadioButton->setObjectName(QStringLiteral("dsifRadioButton"));
        dsifRadioButton->setFont(font2);

        verticalLayout_2->addWidget(dsifRadioButton);

        adsifRadioButton = new QRadioButton(frame_21);
        adsifRadioButton->setObjectName(QStringLiteral("adsifRadioButton"));
        adsifRadioButton->setEnabled(true);

        verticalLayout_2->addWidget(adsifRadioButton);


        verticalLayout_3->addWidget(frame_21);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        isfSetupHelpPushButton = new QPushButton(groupBox_10);
        isfSetupHelpPushButton->setObjectName(QStringLiteral("isfSetupHelpPushButton"));

        horizontalLayout_2->addWidget(isfSetupHelpPushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_14->addWidget(groupBox_10);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_12);


        verticalLayout_9->addLayout(horizontalLayout_14);

        verticalSpacer_6 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_6);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_13);

        groupBox_11 = new QGroupBox(singFeatureToolpathInputDialog);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setFont(font2);
        groupBox_11->setFlat(false);
        verticalLayout_6 = new QVBoxLayout(groupBox_11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_56 = new QLabel(groupBox_11);
        label_56->setObjectName(QStringLiteral("label_56"));

        horizontalLayout_3->addWidget(label_56);

        sheetThickSpinBox = new QDoubleSpinBox(groupBox_11);
        sheetThickSpinBox->setObjectName(QStringLiteral("sheetThickSpinBox"));
        sheetThickSpinBox->setDecimals(3);
        sheetThickSpinBox->setMinimum(0.005);
        sheetThickSpinBox->setMaximum(50);
        sheetThickSpinBox->setSingleStep(0.25);
        sheetThickSpinBox->setValue(1);

        horizontalLayout_3->addWidget(sheetThickSpinBox);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_57 = new QLabel(groupBox_11);
        label_57->setObjectName(QStringLiteral("label_57"));

        horizontalLayout_4->addWidget(label_57);

        topToolDiamSpinBox = new QDoubleSpinBox(groupBox_11);
        topToolDiamSpinBox->setObjectName(QStringLiteral("topToolDiamSpinBox"));
        topToolDiamSpinBox->setDecimals(3);
        topToolDiamSpinBox->setMinimum(0.01);
        topToolDiamSpinBox->setMaximum(250);
        topToolDiamSpinBox->setValue(10);

        horizontalLayout_4->addWidget(topToolDiamSpinBox);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_58 = new QLabel(groupBox_11);
        label_58->setObjectName(QStringLiteral("label_58"));

        horizontalLayout_5->addWidget(label_58);

        botToolDiamSpinBox = new QDoubleSpinBox(groupBox_11);
        botToolDiamSpinBox->setObjectName(QStringLiteral("botToolDiamSpinBox"));
        botToolDiamSpinBox->setDecimals(3);
        botToolDiamSpinBox->setMinimum(0.01);
        botToolDiamSpinBox->setMaximum(250);
        botToolDiamSpinBox->setValue(10);

        horizontalLayout_5->addWidget(botToolDiamSpinBox);


        verticalLayout_6->addLayout(horizontalLayout_5);

        frame_22 = new QFrame(groupBox_11);
        frame_22->setObjectName(QStringLiteral("frame_22"));
        frame_22->setFrameShape(QFrame::NoFrame);
        frame_22->setFrameShadow(QFrame::Plain);
        verticalLayout_4 = new QVBoxLayout(frame_22);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        negZFormingDirRadioButton = new QRadioButton(frame_22);
        negZFormingDirRadioButton->setObjectName(QStringLiteral("negZFormingDirRadioButton"));
        negZFormingDirRadioButton->setCheckable(true);
        negZFormingDirRadioButton->setChecked(true);
        negZFormingDirRadioButton->setAutoExclusive(true);

        verticalLayout_4->addWidget(negZFormingDirRadioButton);

        posZFormingDirRadioButton = new QRadioButton(frame_22);
        posZFormingDirRadioButton->setObjectName(QStringLiteral("posZFormingDirRadioButton"));

        verticalLayout_4->addWidget(posZFormingDirRadioButton);


        verticalLayout_6->addWidget(frame_22);

        frame_23 = new QFrame(groupBox_11);
        frame_23->setObjectName(QStringLiteral("frame_23"));
        frame_23->setFrameShape(QFrame::NoFrame);
        frame_23->setFrameShadow(QFrame::Sunken);
        verticalLayout_5 = new QVBoxLayout(frame_23);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        femaleDieShapeRadioButton = new QRadioButton(frame_23);
        femaleDieShapeRadioButton->setObjectName(QStringLiteral("femaleDieShapeRadioButton"));
        femaleDieShapeRadioButton->setCheckable(true);
        femaleDieShapeRadioButton->setChecked(true);

        verticalLayout_5->addWidget(femaleDieShapeRadioButton);

        maleDieShapeRadioButton = new QRadioButton(frame_23);
        maleDieShapeRadioButton->setObjectName(QStringLiteral("maleDieShapeRadioButton"));

        verticalLayout_5->addWidget(maleDieShapeRadioButton);


        verticalLayout_6->addWidget(frame_23);

        verticalSpacer_4 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        toolingParamAdvPushButton = new QPushButton(groupBox_11);
        toolingParamAdvPushButton->setObjectName(QStringLiteral("toolingParamAdvPushButton"));

        horizontalLayout_6->addWidget(toolingParamAdvPushButton);

        toolingParamHelpPushButton = new QPushButton(groupBox_11);
        toolingParamHelpPushButton->setObjectName(QStringLiteral("toolingParamHelpPushButton"));
        toolingParamHelpPushButton->setFont(font2);

        horizontalLayout_6->addWidget(toolingParamHelpPushButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_6);


        horizontalLayout_15->addWidget(groupBox_11);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_14);

        groupBox_12 = new QGroupBox(singFeatureToolpathInputDialog);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        groupBox_12->setFont(font2);
        verticalLayout_8 = new QVBoxLayout(groupBox_12);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        frame_24 = new QFrame(groupBox_12);
        frame_24->setObjectName(QStringLiteral("frame_24"));
        frame_24->setFrameShape(QFrame::NoFrame);
        frame_24->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_24);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        zLevelSlicingRadioButton = new QRadioButton(frame_24);
        zLevelSlicingRadioButton->setObjectName(QStringLiteral("zLevelSlicingRadioButton"));
        zLevelSlicingRadioButton->setChecked(true);

        verticalLayout_7->addWidget(zLevelSlicingRadioButton);

        spiralToolpathRadioButton = new QRadioButton(frame_24);
        spiralToolpathRadioButton->setObjectName(QStringLiteral("spiralToolpathRadioButton"));

        verticalLayout_7->addWidget(spiralToolpathRadioButton);


        verticalLayout_8->addWidget(frame_24);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_65 = new QLabel(groupBox_12);
        label_65->setObjectName(QStringLiteral("label_65"));

        horizontalLayout_7->addWidget(label_65);

        startHeightSpinBox = new QDoubleSpinBox(groupBox_12);
        startHeightSpinBox->setObjectName(QStringLiteral("startHeightSpinBox"));
        startHeightSpinBox->setDecimals(3);
        startHeightSpinBox->setMinimum(-10000);
        startHeightSpinBox->setMaximum(9999.99);
        startHeightSpinBox->setValue(-0.01);

        horizontalLayout_7->addWidget(startHeightSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_62 = new QLabel(groupBox_12);
        label_62->setObjectName(QStringLiteral("label_62"));

        horizontalLayout_8->addWidget(label_62);

        endHeightSpinBox = new QDoubleSpinBox(groupBox_12);
        endHeightSpinBox->setObjectName(QStringLiteral("endHeightSpinBox"));
        endHeightSpinBox->setDecimals(3);
        endHeightSpinBox->setMinimum(-10000);
        endHeightSpinBox->setMaximum(10000);
        endHeightSpinBox->setValue(-50);

        horizontalLayout_8->addWidget(endHeightSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_61 = new QLabel(groupBox_12);
        label_61->setObjectName(QStringLiteral("label_61"));

        horizontalLayout_9->addWidget(label_61);

        incDepthSpinBox = new QDoubleSpinBox(groupBox_12);
        incDepthSpinBox->setObjectName(QStringLiteral("incDepthSpinBox"));
        incDepthSpinBox->setDecimals(3);
        incDepthSpinBox->setMinimum(0.009);
        incDepthSpinBox->setMaximum(999.999);
        incDepthSpinBox->setSingleStep(0.25);
        incDepthSpinBox->setValue(0.5);

        horizontalLayout_9->addWidget(incDepthSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_63 = new QLabel(groupBox_12);
        label_63->setObjectName(QStringLiteral("label_63"));

        horizontalLayout_10->addWidget(label_63);

        sqzFactorSpinBox = new QDoubleSpinBox(groupBox_12);
        sqzFactorSpinBox->setObjectName(QStringLiteral("sqzFactorSpinBox"));
        sqzFactorSpinBox->setDecimals(3);
        sqzFactorSpinBox->setMinimum(0.001);
        sqzFactorSpinBox->setMaximum(1000);
        sqzFactorSpinBox->setSingleStep(0.05);
        sqzFactorSpinBox->setValue(1);

        horizontalLayout_10->addWidget(sqzFactorSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_64 = new QLabel(groupBox_12);
        label_64->setObjectName(QStringLiteral("label_64"));

        horizontalLayout_11->addWidget(label_64);

        resolToolpathCurveSpinBox = new QDoubleSpinBox(groupBox_12);
        resolToolpathCurveSpinBox->setObjectName(QStringLiteral("resolToolpathCurveSpinBox"));
        resolToolpathCurveSpinBox->setDecimals(3);
        resolToolpathCurveSpinBox->setMinimum(0.005);
        resolToolpathCurveSpinBox->setMaximum(999.999);
        resolToolpathCurveSpinBox->setSingleStep(0.2);
        resolToolpathCurveSpinBox->setValue(1);

        horizontalLayout_11->addWidget(resolToolpathCurveSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_11);

        verticalSpacer_5 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_5);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_8);

        toolpathParamAdvPushButton = new QPushButton(groupBox_12);
        toolpathParamAdvPushButton->setObjectName(QStringLiteral("toolpathParamAdvPushButton"));

        horizontalLayout_12->addWidget(toolpathParamAdvPushButton);

        toolpathParamHelpPushButton = new QPushButton(groupBox_12);
        toolpathParamHelpPushButton->setObjectName(QStringLiteral("toolpathParamHelpPushButton"));
        toolpathParamHelpPushButton->setFont(font2);

        horizontalLayout_12->addWidget(toolpathParamHelpPushButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_7);


        verticalLayout_8->addLayout(horizontalLayout_12);


        horizontalLayout_15->addWidget(groupBox_12);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_15);


        verticalLayout_9->addLayout(horizontalLayout_15);

        verticalSpacer_7 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_7);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_9 = new QSpacerItem(538, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_9);

        startPushButton = new QPushButton(singFeatureToolpathInputDialog);
        startPushButton->setObjectName(QStringLiteral("startPushButton"));
        startPushButton->setFont(font2);

        horizontalLayout_13->addWidget(startPushButton);

        cancelPushButton = new QPushButton(singFeatureToolpathInputDialog);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setFont(font2);

        horizontalLayout_13->addWidget(cancelPushButton);


        verticalLayout_9->addLayout(horizontalLayout_13);


        retranslateUi(singFeatureToolpathInputDialog);
        QObject::connect(startPushButton, SIGNAL(clicked()), singFeatureToolpathInputDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), singFeatureToolpathInputDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(singFeatureToolpathInputDialog);
    } // setupUi

    void retranslateUi(QDialog *singFeatureToolpathInputDialog)
    {
        singFeatureToolpathInputDialog->setWindowTitle(QApplication::translate("singFeatureToolpathInputDialog", "One-Stage Single-Feature Toolpath Input", Q_NULLPTR));
        label_59->setText(QApplication::translate("singFeatureToolpathInputDialog", "One-Stage, Single-Feature Toolpath Input", Q_NULLPTR));
        label_60->setText(QApplication::translate("singFeatureToolpathInputDialog", "First Time? Start Here --->", Q_NULLPTR));
        firstTimeHelpPushButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Help", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("singFeatureToolpathInputDialog", "1) Incremental Sheet Forming Setup", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spifRadioButton->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "One tool that forms the sheet", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        spifRadioButton->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "One tool that forms the sheet", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        spifRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Single-Point Incremental Forming (SPIF)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tpifRadioButton->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "One tool and a partial die to support the sheet during forming", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tpifRadioButton->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "One tool and a partial die to support the sheet during forming", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tpifRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Two-Point Incremental Forming (TPIF)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        dsifRadioButton->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Two independent tools, one on each side of the sheet", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        dsifRadioButton->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "Two independent tools, one on each side of the sheet", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        dsifRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Double-Sided Incremental Forming (DSIF)", Q_NULLPTR));
        adsifRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Accumulated-DSIF (ADSIF)", Q_NULLPTR));
        isfSetupHelpPushButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Information", Q_NULLPTR));
        groupBox_11->setTitle(QApplication::translate("singFeatureToolpathInputDialog", "2) Tooling and Sheet Metal Parameters", Q_NULLPTR));
        label_56->setText(QApplication::translate("singFeatureToolpathInputDialog", "Sheet Thickness [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sheetThickSpinBox->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Thickness of the virgin sheet metal", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_57->setText(QApplication::translate("singFeatureToolpathInputDialog", "Top Tool Diameter [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        topToolDiamSpinBox->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Diameter of the hemispherical top tool", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        topToolDiamSpinBox->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "Diameter of the hemispherical top tool", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_58->setText(QApplication::translate("singFeatureToolpathInputDialog", "Bottom Tool Diameter [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        botToolDiamSpinBox->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Diameter of the hemispherical bottom tool", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        botToolDiamSpinBox->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "Diameter of the hemispherical bottom tool", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        negZFormingDirRadioButton->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "The toolpath progresses in the negative Z-direction", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        negZFormingDirRadioButton->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "The toolpath progresses in the negative Z-direction", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        negZFormingDirRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Forming in Negative Z-Direction", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        posZFormingDirRadioButton->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "The toolpath progresses in the positive Z-direction", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        posZFormingDirRadioButton->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "The toolpath progresses in the positive Z-direction", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        posZFormingDirRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Forming in Positive Z-Direction", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        femaleDieShapeRadioButton->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "For a female die, the sheet is formed into the die", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        femaleDieShapeRadioButton->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        femaleDieShapeRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Female Die (TPIF Only)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        maleDieShapeRadioButton->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "For a male die, the sheet is formed around the die", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        maleDieShapeRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Male Die (TPIF Only) ", Q_NULLPTR));
        toolingParamAdvPushButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Advanced", Q_NULLPTR));
        toolingParamHelpPushButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Information", Q_NULLPTR));
        groupBox_12->setTitle(QApplication::translate("singFeatureToolpathInputDialog", "3) Toolpath Parameters", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zLevelSlicingRadioButton->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Toolpath points lie on successive, discrete contours", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        zLevelSlicingRadioButton->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "Toolpath points lie on successive, discrete contours", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        zLevelSlicingRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Z-Level Contour Slicing", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spiralToolpathRadioButton->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Toolpath points are continuous and traverse in a spiral", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        spiralToolpathRadioButton->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "Toolpath points are continuous and traverse in a spiral", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        spiralToolpathRadioButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Continuous Spiral", Q_NULLPTR));
        label_65->setText(QApplication::translate("singFeatureToolpathInputDialog", "Toolpath Algorithm Start Height [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        startHeightSpinBox->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Provide the intersection algorithm the height to start the toolpath", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        startHeightSpinBox->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "0", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_62->setText(QApplication::translate("singFeatureToolpathInputDialog", "Toolpath Algorithm End Height [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        endHeightSpinBox->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Provide the intersection algorithm the height to start the toolpath", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        endHeightSpinBox->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "0", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_61->setText(QApplication::translate("singFeatureToolpathInputDialog", "Incremental Depth [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        incDepthSpinBox->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Incremental depth (contour slicing) or pitch (spiral) of the toolpath", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        incDepthSpinBox->setStatusTip(QApplication::translate("singFeatureToolpathInputDialog", "Incremental depth (contour slicing) or pitch (spiral) of the toolpath", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_63->setText(QApplication::translate("singFeatureToolpathInputDialog", "Squeeze Factor (not applicable in SPIF):", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sqzFactorSpinBox->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Change the tool gap with respect to the predicted thickness", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_64->setText(QApplication::translate("singFeatureToolpathInputDialog", "Resolution Along Toolpath Curve [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        resolToolpathCurveSpinBox->setToolTip(QApplication::translate("singFeatureToolpathInputDialog", "Provide the spacing between subsequent toolpath points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        resolToolpathCurveSpinBox->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        toolpathParamAdvPushButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Advanced", Q_NULLPTR));
        toolpathParamHelpPushButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Information", Q_NULLPTR));
        startPushButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Start", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("singFeatureToolpathInputDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class singFeatureToolpathInputDialog: public Ui_singFeatureToolpathInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGFEATURETOOLPATHINPUTDIALOG_H
