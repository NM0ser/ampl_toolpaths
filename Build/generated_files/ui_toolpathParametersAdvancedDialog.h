/********************************************************************************
** Form generated from reading UI file 'toolpathParametersAdvancedDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLPATHPARAMETERSADVANCEDDIALOG_H
#define UI_TOOLPATHPARAMETERSADVANCEDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_toolpathParametersAdvancedDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *toolDirectionCCWRadio;
    QRadioButton *toolDirectionCWRadio;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *startAngleSpinBox;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QDoubleSpinBox *startingDistanceSpinBox;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QSpinBox *contourLinearRampSpinBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *adaptingZSlicingCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *fastSpiralApproxCheckBox;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *removeCollinearPointsCheckBox;
    QCheckBox *keepDsifToolOnSheetBlankCheckBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *acceptPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *toolpathParametersAdvancedDialog)
    {
        if (toolpathParametersAdvancedDialog->objectName().isEmpty())
            toolpathParametersAdvancedDialog->setObjectName(QStringLiteral("toolpathParametersAdvancedDialog"));
        toolpathParametersAdvancedDialog->resize(540, 255);
        verticalLayout = new QVBoxLayout(toolpathParametersAdvancedDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(toolpathParametersAdvancedDialog);
        frame->setObjectName(QStringLiteral("frame"));
        QFont font;
        font.setPointSize(10);
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        toolDirectionCCWRadio = new QRadioButton(frame);
        toolDirectionCCWRadio->setObjectName(QStringLiteral("toolDirectionCCWRadio"));
        toolDirectionCCWRadio->setChecked(true);

        horizontalLayout_5->addWidget(toolDirectionCCWRadio);

        toolDirectionCWRadio = new QRadioButton(frame);
        toolDirectionCWRadio->setObjectName(QStringLiteral("toolDirectionCWRadio"));

        horizontalLayout_5->addWidget(toolDirectionCWRadio);


        horizontalLayout->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(toolpathParametersAdvancedDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(285, 41));
        label->setMaximumSize(QSize(261, 41));
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setWordWrap(true);

        horizontalLayout_2->addWidget(label);

        startAngleSpinBox = new QDoubleSpinBox(toolpathParametersAdvancedDialog);
        startAngleSpinBox->setObjectName(QStringLiteral("startAngleSpinBox"));
        startAngleSpinBox->setFont(font);
        startAngleSpinBox->setDecimals(1);
        startAngleSpinBox->setMaximum(359.9);

        horizontalLayout_2->addWidget(startAngleSpinBox);

        label_2 = new QLabel(toolpathParametersAdvancedDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        startingDistanceSpinBox = new QDoubleSpinBox(toolpathParametersAdvancedDialog);
        startingDistanceSpinBox->setObjectName(QStringLiteral("startingDistanceSpinBox"));
        startingDistanceSpinBox->setFont(font);
        startingDistanceSpinBox->setDecimals(1);
        startingDistanceSpinBox->setMaximum(10000);
        startingDistanceSpinBox->setValue(1000);

        horizontalLayout_2->addWidget(startingDistanceSpinBox);

        label_3 = new QLabel(toolpathParametersAdvancedDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(toolpathParametersAdvancedDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_7->addWidget(label_4);

        contourLinearRampSpinBox = new QSpinBox(toolpathParametersAdvancedDialog);
        contourLinearRampSpinBox->setObjectName(QStringLiteral("contourLinearRampSpinBox"));
        contourLinearRampSpinBox->setFont(font);
        contourLinearRampSpinBox->setMaximum(50);

        horizontalLayout_7->addWidget(contourLinearRampSpinBox);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        adaptingZSlicingCheckBox = new QCheckBox(toolpathParametersAdvancedDialog);
        adaptingZSlicingCheckBox->setObjectName(QStringLiteral("adaptingZSlicingCheckBox"));
        adaptingZSlicingCheckBox->setFont(font);

        horizontalLayout_4->addWidget(adaptingZSlicingCheckBox);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        fastSpiralApproxCheckBox = new QCheckBox(toolpathParametersAdvancedDialog);
        fastSpiralApproxCheckBox->setObjectName(QStringLiteral("fastSpiralApproxCheckBox"));
        fastSpiralApproxCheckBox->setFont(font);

        horizontalLayout_4->addWidget(fastSpiralApproxCheckBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        removeCollinearPointsCheckBox = new QCheckBox(toolpathParametersAdvancedDialog);
        removeCollinearPointsCheckBox->setObjectName(QStringLiteral("removeCollinearPointsCheckBox"));
        removeCollinearPointsCheckBox->setFont(font);
        removeCollinearPointsCheckBox->setChecked(true);

        horizontalLayout_6->addWidget(removeCollinearPointsCheckBox);

        keepDsifToolOnSheetBlankCheckBox = new QCheckBox(toolpathParametersAdvancedDialog);
        keepDsifToolOnSheetBlankCheckBox->setObjectName(QStringLiteral("keepDsifToolOnSheetBlankCheckBox"));
        keepDsifToolOnSheetBlankCheckBox->setFont(font);

        horizontalLayout_6->addWidget(keepDsifToolOnSheetBlankCheckBox);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        acceptPushButton = new QPushButton(toolpathParametersAdvancedDialog);
        acceptPushButton->setObjectName(QStringLiteral("acceptPushButton"));
        acceptPushButton->setFont(font);

        horizontalLayout_3->addWidget(acceptPushButton);

        cancelPushButton = new QPushButton(toolpathParametersAdvancedDialog);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setFont(font);

        horizontalLayout_3->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(toolpathParametersAdvancedDialog);
        QObject::connect(acceptPushButton, SIGNAL(clicked()), toolpathParametersAdvancedDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), toolpathParametersAdvancedDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(toolpathParametersAdvancedDialog);
    } // setupUi

    void retranslateUi(QDialog *toolpathParametersAdvancedDialog)
    {
        toolpathParametersAdvancedDialog->setWindowTitle(QApplication::translate("toolpathParametersAdvancedDialog", "Advanced Toolpath Parameters", Q_NULLPTR));
        toolDirectionCCWRadio->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Toolpath Direction CCW", Q_NULLPTR));
        toolDirectionCWRadio->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Toolpath Direction CW", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("toolpathParametersAdvancedDialog", "A construction point will be created 10m in this XY-direction. On the discretized contour, the closest point to this construction point will be used to start the current increment.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label->setStatusTip(QApplication::translate("toolpathParametersAdvancedDialog", "A construction point will be created 10m in this XY-direction. On the discretized contour, the closest point to this construction point will be used to start the current increment.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Angle (CCW in XY-Plane from X-axis) and Radial Distance of the Starting Construction Point:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        startAngleSpinBox->setToolTip(QApplication::translate("toolpathParametersAdvancedDialog", "A construction point will be created in this XY-direction. On the discretized contour, the closest point to this construction point will be used to start the current increment.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        startAngleSpinBox->setStatusTip(QApplication::translate("toolpathParametersAdvancedDialog", "A construction point will be created in this XY-direction. On the discretized contour, the closest point to this construction point will be used to start the current increment.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("toolpathParametersAdvancedDialog", "[deg]", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        startingDistanceSpinBox->setToolTip(QApplication::translate("toolpathParametersAdvancedDialog", "A construction point will be created at this radial distance from the origin. On the discretized contour, the closest point to this construction point will be used to start the current increment.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        startingDistanceSpinBox->setStatusTip(QApplication::translate("toolpathParametersAdvancedDialog", "A construction point will be created at this radial distance from the origin. On the discretized contour, the closest point to this construction point will be used to start the current increment.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_3->setText(QApplication::translate("toolpathParametersAdvancedDialog", "[mm]", Q_NULLPTR));
        label_4->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Z-Level Contour Slicing Linear Ramping, Number of Initial Points to Skip:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        adaptingZSlicingCheckBox->setToolTip(QApplication::translate("toolpathParametersAdvancedDialog", "Incremental depth is used to constrain the maximum surface arc-length, thus the real incremental depth varies with the max wall angle.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        adaptingZSlicingCheckBox->setStatusTip(QApplication::translate("toolpathParametersAdvancedDialog", "Incremental depth is used to constrain the maximum surface arc-length, thus the real incremental depth varies with the max wall angle.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        adaptingZSlicingCheckBox->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Adaptive Z-Slicing", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        fastSpiralApproxCheckBox->setToolTip(QApplication::translate("toolpathParametersAdvancedDialog", "If a spiral toolpath is chosen, a less accurate and less stable linear projection algorithm will be used. USE CAUTION! This also affects the calculation of the local surface properties.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fastSpiralApproxCheckBox->setStatusTip(QApplication::translate("toolpathParametersAdvancedDialog", "If a spiral toolpath is chosen, a less accurate and less stable linear projection algorithm will be used. USE CAUTION! This also affects the calculation of the local surface properties.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        fastSpiralApproxCheckBox->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Fast Spiral Approximation", Q_NULLPTR));
        removeCollinearPointsCheckBox->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Remove Collinear Contact Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        keepDsifToolOnSheetBlankCheckBox->setToolTip(QApplication::translate("toolpathParametersAdvancedDialog", "In DSIF, the supporting tool will revolve at the first Z-level increment", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        keepDsifToolOnSheetBlankCheckBox->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Keep DSIF Support Tool on the Sheet Blank", Q_NULLPTR));
        acceptPushButton->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Accept", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("toolpathParametersAdvancedDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class toolpathParametersAdvancedDialog: public Ui_toolpathParametersAdvancedDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLPATHPARAMETERSADVANCEDDIALOG_H
