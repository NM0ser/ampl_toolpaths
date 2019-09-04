/********************************************************************************
** Form generated from reading UI file 'singFeatureToolTipGenDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGFEATURETOOLTIPGENDIALOG_H
#define UI_SINGFEATURETOOLTIPGENDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_singleFeatureToolTipGenDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *spifRadioButton;
    QRadioButton *tpifRadioButton;
    QRadioButton *dsifRadioButton;
    QRadioButton *adsifRadioButton;
    QLabel *label;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *hemisphericalTopToolProfileRadioButton;
    QRadioButton *doubleRadiusTopToolProfileRadioButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QDoubleSpinBox *topToolDiamSpinBox;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QDoubleSpinBox *topToolCornerRadiusSpinBox;
    QLabel *label_7;
    QCheckBox *topToolConstZHeightCheckBox;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *hemisphericalBotToolProfileRadioButton;
    QRadioButton *doubleRadiusBotToolProfileRadioButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *botToolDiamSpinBox;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDoubleSpinBox *botToolCornerRadiusSpinBox;
    QLabel *label_8;
    QCheckBox *botToolConstZHeightCheckBox;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *correctSelfInterferenceCheckBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *startPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *singleFeatureToolTipGenDialog)
    {
        if (singleFeatureToolTipGenDialog->objectName().isEmpty())
            singleFeatureToolTipGenDialog->setObjectName(QStringLiteral("singleFeatureToolTipGenDialog"));
        singleFeatureToolTipGenDialog->resize(471, 614);
        verticalLayout_4 = new QVBoxLayout(singleFeatureToolTipGenDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(singleFeatureToolTipGenDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(false);
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        spifRadioButton = new QRadioButton(groupBox);
        spifRadioButton->setObjectName(QStringLiteral("spifRadioButton"));
        spifRadioButton->setFont(font);
        spifRadioButton->setChecked(true);

        verticalLayout->addWidget(spifRadioButton);

        tpifRadioButton = new QRadioButton(groupBox);
        tpifRadioButton->setObjectName(QStringLiteral("tpifRadioButton"));
        tpifRadioButton->setFont(font);

        verticalLayout->addWidget(tpifRadioButton);

        dsifRadioButton = new QRadioButton(groupBox);
        dsifRadioButton->setObjectName(QStringLiteral("dsifRadioButton"));
        dsifRadioButton->setFont(font);

        verticalLayout->addWidget(dsifRadioButton);

        adsifRadioButton = new QRadioButton(groupBox);
        adsifRadioButton->setObjectName(QStringLiteral("adsifRadioButton"));
        adsifRadioButton->setFont(font);

        verticalLayout->addWidget(adsifRadioButton);


        verticalLayout_4->addWidget(groupBox);

        label = new QLabel(singleFeatureToolTipGenDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout_4->addWidget(label);

        groupBox_2 = new QGroupBox(singleFeatureToolTipGenDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        hemisphericalTopToolProfileRadioButton = new QRadioButton(groupBox_2);
        hemisphericalTopToolProfileRadioButton->setObjectName(QStringLiteral("hemisphericalTopToolProfileRadioButton"));
        hemisphericalTopToolProfileRadioButton->setChecked(true);

        verticalLayout_2->addWidget(hemisphericalTopToolProfileRadioButton);

        doubleRadiusTopToolProfileRadioButton = new QRadioButton(groupBox_2);
        doubleRadiusTopToolProfileRadioButton->setObjectName(QStringLiteral("doubleRadiusTopToolProfileRadioButton"));
        doubleRadiusTopToolProfileRadioButton->setEnabled(true);

        verticalLayout_2->addWidget(doubleRadiusTopToolProfileRadioButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_1 = new QLabel(groupBox_2);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setFont(font);

        horizontalLayout->addWidget(label_1);

        topToolDiamSpinBox = new QDoubleSpinBox(groupBox_2);
        topToolDiamSpinBox->setObjectName(QStringLiteral("topToolDiamSpinBox"));
        topToolDiamSpinBox->setFont(font);
        topToolDiamSpinBox->setDecimals(3);
        topToolDiamSpinBox->setMinimum(0.01);
        topToolDiamSpinBox->setMaximum(250);
        topToolDiamSpinBox->setValue(10);

        horizontalLayout->addWidget(topToolDiamSpinBox);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        topToolCornerRadiusSpinBox = new QDoubleSpinBox(groupBox_2);
        topToolCornerRadiusSpinBox->setObjectName(QStringLiteral("topToolCornerRadiusSpinBox"));
        topToolCornerRadiusSpinBox->setDecimals(3);
        topToolCornerRadiusSpinBox->setMinimum(0.001);
        topToolCornerRadiusSpinBox->setMaximum(15);
        topToolCornerRadiusSpinBox->setSingleStep(0.5);
        topToolCornerRadiusSpinBox->setValue(1);

        horizontalLayout_5->addWidget(topToolCornerRadiusSpinBox);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);


        verticalLayout_2->addLayout(horizontalLayout_5);

        topToolConstZHeightCheckBox = new QCheckBox(groupBox_2);
        topToolConstZHeightCheckBox->setObjectName(QStringLiteral("topToolConstZHeightCheckBox"));

        verticalLayout_2->addWidget(topToolConstZHeightCheckBox);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(singleFeatureToolTipGenDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        hemisphericalBotToolProfileRadioButton = new QRadioButton(groupBox_3);
        hemisphericalBotToolProfileRadioButton->setObjectName(QStringLiteral("hemisphericalBotToolProfileRadioButton"));
        hemisphericalBotToolProfileRadioButton->setChecked(true);

        verticalLayout_3->addWidget(hemisphericalBotToolProfileRadioButton);

        doubleRadiusBotToolProfileRadioButton = new QRadioButton(groupBox_3);
        doubleRadiusBotToolProfileRadioButton->setObjectName(QStringLiteral("doubleRadiusBotToolProfileRadioButton"));
        doubleRadiusBotToolProfileRadioButton->setEnabled(true);

        verticalLayout_3->addWidget(doubleRadiusBotToolProfileRadioButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        botToolDiamSpinBox = new QDoubleSpinBox(groupBox_3);
        botToolDiamSpinBox->setObjectName(QStringLiteral("botToolDiamSpinBox"));
        botToolDiamSpinBox->setFont(font);
        botToolDiamSpinBox->setDecimals(3);
        botToolDiamSpinBox->setMinimum(0.01);
        botToolDiamSpinBox->setMaximum(250);
        botToolDiamSpinBox->setValue(10);

        horizontalLayout_2->addWidget(botToolDiamSpinBox);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        botToolCornerRadiusSpinBox = new QDoubleSpinBox(groupBox_3);
        botToolCornerRadiusSpinBox->setObjectName(QStringLiteral("botToolCornerRadiusSpinBox"));
        botToolCornerRadiusSpinBox->setDecimals(3);
        botToolCornerRadiusSpinBox->setMinimum(0.001);
        botToolCornerRadiusSpinBox->setMaximum(15);
        botToolCornerRadiusSpinBox->setSingleStep(0.5);
        botToolCornerRadiusSpinBox->setValue(1);

        horizontalLayout_4->addWidget(botToolCornerRadiusSpinBox);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);


        verticalLayout_3->addLayout(horizontalLayout_4);

        botToolConstZHeightCheckBox = new QCheckBox(groupBox_3);
        botToolConstZHeightCheckBox->setObjectName(QStringLiteral("botToolConstZHeightCheckBox"));

        verticalLayout_3->addWidget(botToolConstZHeightCheckBox);


        verticalLayout_4->addWidget(groupBox_3);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_4);

        correctSelfInterferenceCheckBox = new QCheckBox(singleFeatureToolTipGenDialog);
        correctSelfInterferenceCheckBox->setObjectName(QStringLiteral("correctSelfInterferenceCheckBox"));
        correctSelfInterferenceCheckBox->setEnabled(true);
        correctSelfInterferenceCheckBox->setFont(font);
        correctSelfInterferenceCheckBox->setChecked(true);

        verticalLayout_4->addWidget(correctSelfInterferenceCheckBox);

        verticalSpacer_2 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        startPushButton = new QPushButton(singleFeatureToolTipGenDialog);
        startPushButton->setObjectName(QStringLiteral("startPushButton"));
        startPushButton->setFont(font);

        horizontalLayout_3->addWidget(startPushButton);

        cancelPushButton = new QPushButton(singleFeatureToolTipGenDialog);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setFont(font);

        horizontalLayout_3->addWidget(cancelPushButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(singleFeatureToolTipGenDialog);
        QObject::connect(startPushButton, SIGNAL(clicked()), singleFeatureToolTipGenDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), singleFeatureToolTipGenDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(singleFeatureToolTipGenDialog);
    } // setupUi

    void retranslateUi(QDialog *singleFeatureToolTipGenDialog)
    {
        singleFeatureToolTipGenDialog->setWindowTitle(QApplication::translate("singleFeatureToolTipGenDialog", "Single-Feature Tool-Tip Generation from Contact Points", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("singleFeatureToolTipGenDialog", "Current Incremental Sheet Forming Setup", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spifRadioButton->setToolTip(QApplication::translate("singleFeatureToolTipGenDialog", "One tool that forms the sheet", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        spifRadioButton->setStatusTip(QApplication::translate("singleFeatureToolTipGenDialog", "One tool that forms the sheet", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        spifRadioButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Single-Point Incremental Forming (SPIF)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tpifRadioButton->setToolTip(QApplication::translate("singleFeatureToolTipGenDialog", "One tool and a partial die to support the sheet during forming", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tpifRadioButton->setStatusTip(QApplication::translate("singleFeatureToolTipGenDialog", "One tool and a partial die to support the sheet during forming", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tpifRadioButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Two-Point Incremental Forming (TPIF)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        dsifRadioButton->setToolTip(QApplication::translate("singleFeatureToolTipGenDialog", "Two independent tools, one on each side of the sheet", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        dsifRadioButton->setStatusTip(QApplication::translate("singleFeatureToolTipGenDialog", "Two independent tools, one on each side of the sheet", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        dsifRadioButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Double-Sided Incremental Forming (DSIF)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        adsifRadioButton->setToolTip(QApplication::translate("singleFeatureToolTipGenDialog", "Two independent tools, one on each side of the sheet", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        adsifRadioButton->setStatusTip(QApplication::translate("singleFeatureToolTipGenDialog", "Two independent tools, one on each side of the sheet", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        adsifRadioButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Accumulated-DSIF (ADSIF)", Q_NULLPTR));
        label->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Settings for Calculating Tool-Tip Positions:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("singleFeatureToolTipGenDialog", "Top Tool Profile", Q_NULLPTR));
        hemisphericalTopToolProfileRadioButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Hemispherical, Symmetric", Q_NULLPTR));
        doubleRadiusTopToolProfileRadioButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Corner-Radius (Flat Top), Symmetric", Q_NULLPTR));
        label_1->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Top Tool Diameter [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        topToolDiamSpinBox->setToolTip(QApplication::translate("singleFeatureToolTipGenDialog", "Diameter of the top tool", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("singleFeatureToolTipGenDialog", "(May not be Used in SPIF or TPIF)", Q_NULLPTR));
        label_6->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Top Tool Corner Radius [mm]:", Q_NULLPTR));
        label_7->setText(QApplication::translate("singleFeatureToolTipGenDialog", "(Only for Flat Top Tools)", Q_NULLPTR));
        topToolConstZHeightCheckBox->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Attempt Constant Z-Height Tool Tips", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("singleFeatureToolTipGenDialog", "Bottom Tool Profile", Q_NULLPTR));
        hemisphericalBotToolProfileRadioButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Hemispherical, Symmetric", Q_NULLPTR));
        doubleRadiusBotToolProfileRadioButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Corner-Radius (Flat Top), Symmetric", Q_NULLPTR));
        label_2->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Bottom Tool Diameter [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        botToolDiamSpinBox->setToolTip(QApplication::translate("singleFeatureToolTipGenDialog", "Diameter of the bottom tool", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("singleFeatureToolTipGenDialog", "(May not be Used in SPIF or TPIF)", Q_NULLPTR));
        label_5->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Bottom Tool Corner Radius [mm]:", Q_NULLPTR));
        label_8->setText(QApplication::translate("singleFeatureToolTipGenDialog", "(Only for Flat Top Tools)", Q_NULLPTR));
        botToolConstZHeightCheckBox->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Attempt Constant Z-Height Tool Tips", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        correctSelfInterferenceCheckBox->setToolTip(QApplication::translate("singleFeatureToolTipGenDialog", "Correct against tool-to-part interference, such as when the tool is larger than a fillet on the part", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        correctSelfInterferenceCheckBox->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Check and Correct for Toolpath Self-Intersections", Q_NULLPTR));
        startPushButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Start", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("singleFeatureToolTipGenDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class singleFeatureToolTipGenDialog: public Ui_singleFeatureToolTipGenDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGFEATURETOOLTIPGENDIALOG_H
