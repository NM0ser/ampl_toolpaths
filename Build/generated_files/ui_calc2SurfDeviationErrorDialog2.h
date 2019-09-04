/********************************************************************************
** Form generated from reading UI file 'calc2SurfDeviationErrorDialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALC2SURFDEVIATIONERRORDIALOG2_H
#define UI_CALC2SURFDEVIATIONERRORDIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_calc2SurfDeviationErrorDialog2
{
public:
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *importStpSurf1PushButton;
    QPushButton *importIgsSurf1PushButton;
    QLineEdit *surf1StatusLineEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *importStpSurf2PushButton;
    QPushButton *importIgsSurf2PushButton;
    QLineEdit *surf2StatusLineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *rectRegionRadioButton;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *lineRegionRadioButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *regionParamPushButton;
    QLineEdit *regionStatusLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *directoryLineEdit;
    QPushButton *pickDirectoryButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *prefixNameLineEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *startPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *calc2SurfDeviationErrorDialog2)
    {
        if (calc2SurfDeviationErrorDialog2->objectName().isEmpty())
            calc2SurfDeviationErrorDialog2->setObjectName(QStringLiteral("calc2SurfDeviationErrorDialog2"));
        calc2SurfDeviationErrorDialog2->resize(603, 602);
        verticalLayout_5 = new QVBoxLayout(calc2SurfDeviationErrorDialog2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox = new QGroupBox(calc2SurfDeviationErrorDialog2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(500, 55));
        label->setMaximumSize(QSize(500, 55));
        label->setFont(font);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        importStpSurf1PushButton = new QPushButton(groupBox);
        importStpSurf1PushButton->setObjectName(QStringLiteral("importStpSurf1PushButton"));
        importStpSurf1PushButton->setMinimumSize(QSize(0, 27));
        importStpSurf1PushButton->setMaximumSize(QSize(16777215, 27));
        importStpSurf1PushButton->setFont(font);

        horizontalLayout->addWidget(importStpSurf1PushButton);

        importIgsSurf1PushButton = new QPushButton(groupBox);
        importIgsSurf1PushButton->setObjectName(QStringLiteral("importIgsSurf1PushButton"));
        importIgsSurf1PushButton->setMinimumSize(QSize(0, 27));
        importIgsSurf1PushButton->setMaximumSize(QSize(16777215, 27));
        importIgsSurf1PushButton->setFont(font);

        horizontalLayout->addWidget(importIgsSurf1PushButton);

        surf1StatusLineEdit = new QLineEdit(groupBox);
        surf1StatusLineEdit->setObjectName(QStringLiteral("surf1StatusLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(surf1StatusLineEdit->sizePolicy().hasHeightForWidth());
        surf1StatusLineEdit->setSizePolicy(sizePolicy1);
        surf1StatusLineEdit->setMinimumSize(QSize(300, 25));
        surf1StatusLineEdit->setMaximumSize(QSize(300, 25));
        surf1StatusLineEdit->setFont(font);
        surf1StatusLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(surf1StatusLineEdit);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_5->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(calc2SurfDeviationErrorDialog2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(500, 35));
        label_2->setMaximumSize(QSize(500, 35));
        label_2->setFont(font);
        label_2->setWordWrap(true);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        importStpSurf2PushButton = new QPushButton(groupBox_2);
        importStpSurf2PushButton->setObjectName(QStringLiteral("importStpSurf2PushButton"));
        importStpSurf2PushButton->setMinimumSize(QSize(0, 27));
        importStpSurf2PushButton->setMaximumSize(QSize(16777215, 27));
        importStpSurf2PushButton->setFont(font);

        horizontalLayout_2->addWidget(importStpSurf2PushButton);

        importIgsSurf2PushButton = new QPushButton(groupBox_2);
        importIgsSurf2PushButton->setObjectName(QStringLiteral("importIgsSurf2PushButton"));
        importIgsSurf2PushButton->setMinimumSize(QSize(0, 27));
        importIgsSurf2PushButton->setMaximumSize(QSize(16777215, 27));
        importIgsSurf2PushButton->setFont(font);

        horizontalLayout_2->addWidget(importIgsSurf2PushButton);

        surf2StatusLineEdit = new QLineEdit(groupBox_2);
        surf2StatusLineEdit->setObjectName(QStringLiteral("surf2StatusLineEdit"));
        sizePolicy1.setHeightForWidth(surf2StatusLineEdit->sizePolicy().hasHeightForWidth());
        surf2StatusLineEdit->setSizePolicy(sizePolicy1);
        surf2StatusLineEdit->setMinimumSize(QSize(300, 25));
        surf2StatusLineEdit->setMaximumSize(QSize(300, 25));
        surf2StatusLineEdit->setFont(font);
        surf2StatusLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(surf2StatusLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_5->addWidget(groupBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        groupBox_3 = new QGroupBox(calc2SurfDeviationErrorDialog2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setWordWrap(true);

        verticalLayout_4->addWidget(label_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        frame = new QFrame(groupBox_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        rectRegionRadioButton = new QRadioButton(frame);
        rectRegionRadioButton->setObjectName(QStringLiteral("rectRegionRadioButton"));
        rectRegionRadioButton->setChecked(true);

        horizontalLayout_4->addWidget(rectRegionRadioButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        lineRegionRadioButton = new QRadioButton(frame);
        lineRegionRadioButton->setObjectName(QStringLiteral("lineRegionRadioButton"));

        horizontalLayout_4->addWidget(lineRegionRadioButton);


        horizontalLayout_8->addWidget(frame);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        regionParamPushButton = new QPushButton(groupBox_3);
        regionParamPushButton->setObjectName(QStringLiteral("regionParamPushButton"));
        regionParamPushButton->setMinimumSize(QSize(0, 27));
        regionParamPushButton->setMaximumSize(QSize(16777215, 27));

        horizontalLayout_3->addWidget(regionParamPushButton);

        regionStatusLineEdit = new QLineEdit(groupBox_3);
        regionStatusLineEdit->setObjectName(QStringLiteral("regionStatusLineEdit"));
        sizePolicy1.setHeightForWidth(regionStatusLineEdit->sizePolicy().hasHeightForWidth());
        regionStatusLineEdit->setSizePolicy(sizePolicy1);
        regionStatusLineEdit->setMinimumSize(QSize(300, 25));
        regionStatusLineEdit->setMaximumSize(QSize(300, 25));
        regionStatusLineEdit->setFont(font);
        regionStatusLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(regionStatusLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_9->addWidget(groupBox_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_9);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        groupBox_4 = new QGroupBox(calc2SurfDeviationErrorDialog2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        directoryLineEdit = new QLineEdit(groupBox_4);
        directoryLineEdit->setObjectName(QStringLiteral("directoryLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(directoryLineEdit->sizePolicy().hasHeightForWidth());
        directoryLineEdit->setSizePolicy(sizePolicy2);
        directoryLineEdit->setMinimumSize(QSize(100, 0));
        directoryLineEdit->setMaximumSize(QSize(1000, 16777215));
        directoryLineEdit->setFont(font);
        directoryLineEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(directoryLineEdit);

        pickDirectoryButton = new QPushButton(groupBox_4);
        pickDirectoryButton->setObjectName(QStringLiteral("pickDirectoryButton"));
        sizePolicy1.setHeightForWidth(pickDirectoryButton->sizePolicy().hasHeightForWidth());
        pickDirectoryButton->setSizePolicy(sizePolicy1);
        pickDirectoryButton->setMinimumSize(QSize(30, 15));
        pickDirectoryButton->setMaximumSize(QSize(30, 16777215));
        pickDirectoryButton->setFont(font);

        horizontalLayout_6->addWidget(pickDirectoryButton);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_7->addWidget(label_4);

        prefixNameLineEdit = new QLineEdit(groupBox_4);
        prefixNameLineEdit->setObjectName(QStringLiteral("prefixNameLineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(prefixNameLineEdit->sizePolicy().hasHeightForWidth());
        prefixNameLineEdit->setSizePolicy(sizePolicy3);
        prefixNameLineEdit->setMinimumSize(QSize(100, 0));
        prefixNameLineEdit->setMaximumSize(QSize(500, 16777215));
        prefixNameLineEdit->setFont(font);

        horizontalLayout_7->addWidget(prefixNameLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_5->addWidget(groupBox_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        startPushButton = new QPushButton(calc2SurfDeviationErrorDialog2);
        startPushButton->setObjectName(QStringLiteral("startPushButton"));
        startPushButton->setFont(font);

        horizontalLayout_5->addWidget(startPushButton);

        cancelPushButton = new QPushButton(calc2SurfDeviationErrorDialog2);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setFont(font);

        horizontalLayout_5->addWidget(cancelPushButton);


        verticalLayout_5->addLayout(horizontalLayout_5);


        retranslateUi(calc2SurfDeviationErrorDialog2);
        QObject::connect(startPushButton, SIGNAL(clicked()), calc2SurfDeviationErrorDialog2, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), calc2SurfDeviationErrorDialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(calc2SurfDeviationErrorDialog2);
    } // setupUi

    void retranslateUi(QDialog *calc2SurfDeviationErrorDialog2)
    {
        calc2SurfDeviationErrorDialog2->setWindowTitle(QApplication::translate("calc2SurfDeviationErrorDialog2", "Surface-to-Surface Deviation Calculation", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("calc2SurfDeviationErrorDialog2", "Surface 1", Q_NULLPTR));
        label->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Surface 1 will be used to calculate the local normal vectors which define the directions of the deviation measurements. For Surface 1, it's recommended to use the top surface for thickness deviations, or the desired surface for geometry error deviations.", Q_NULLPTR));
        importStpSurf1PushButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Import .STP", Q_NULLPTR));
        importIgsSurf1PushButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Import .IGS", Q_NULLPTR));
        surf1StatusLineEdit->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Import Status: SURFACE UNDEFINED", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("calc2SurfDeviationErrorDialog2", "Surface 2", Q_NULLPTR));
        label_2->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "A line will be drawn along the local normal vectors of Surface 1 and the distance between Surface 1 and Surface 2 represents the deviation error at that location. ", Q_NULLPTR));
        importStpSurf2PushButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Import .STP", Q_NULLPTR));
        importIgsSurf2PushButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Import .IGS", Q_NULLPTR));
        surf2StatusLineEdit->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Import Status: SURFACE UNDEFINED", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("calc2SurfDeviationErrorDialog2", "Define Region of Interest", Q_NULLPTR));
        label_5->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Regions are defined in the XY-plane where the query points are then projected along the Z-axis towards Surface 1.", Q_NULLPTR));
        rectRegionRadioButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Rectangular Grid", Q_NULLPTR));
        lineRegionRadioButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "1D Line", Q_NULLPTR));
        regionParamPushButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Region Parameters", Q_NULLPTR));
        regionStatusLineEdit->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Region Definition: UNDEFINED", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("calc2SurfDeviationErrorDialog2", "Output Files", Q_NULLPTR));
        label_3->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Folder Directory:", Q_NULLPTR));
        pickDirectoryButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Prefix Name:", Q_NULLPTR));
        prefixNameLineEdit->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "myDeviationValues", Q_NULLPTR));
        startPushButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Start", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("calc2SurfDeviationErrorDialog2", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class calc2SurfDeviationErrorDialog2: public Ui_calc2SurfDeviationErrorDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALC2SURFDEVIATIONERRORDIALOG2_H
