/********************************************************************************
** Form generated from reading UI file 'rectRegionDefinitionDialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTREGIONDEFINITIONDIALOG2_H
#define UI_RECTREGIONDEFINITIONDIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_rectRegionDefinitionDialog2
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *xCenterPntLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *yCenterPntLineEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QLineEdit *zCenterPntLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *xRectWidthSpinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *yRectWidthSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *xIncSpinBox;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QDoubleSpinBox *yIncSpinBox;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *acceptPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *rectRegionDefinitionDialog2)
    {
        if (rectRegionDefinitionDialog2->objectName().isEmpty())
            rectRegionDefinitionDialog2->setObjectName(QStringLiteral("rectRegionDefinitionDialog2"));
        rectRegionDefinitionDialog2->resize(388, 241);
        verticalLayout = new QVBoxLayout(rectRegionDefinitionDialog2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(rectRegionDefinitionDialog2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        xCenterPntLineEdit = new QLineEdit(groupBox);
        xCenterPntLineEdit->setObjectName(QStringLiteral("xCenterPntLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(xCenterPntLineEdit->sizePolicy().hasHeightForWidth());
        xCenterPntLineEdit->setSizePolicy(sizePolicy);
        xCenterPntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(xCenterPntLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        yCenterPntLineEdit = new QLineEdit(groupBox);
        yCenterPntLineEdit->setObjectName(QStringLiteral("yCenterPntLineEdit"));
        sizePolicy.setHeightForWidth(yCenterPntLineEdit->sizePolicy().hasHeightForWidth());
        yCenterPntLineEdit->setSizePolicy(sizePolicy);
        yCenterPntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(yCenterPntLineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        zCenterPntLineEdit = new QLineEdit(groupBox);
        zCenterPntLineEdit->setObjectName(QStringLiteral("zCenterPntLineEdit"));
        zCenterPntLineEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(zCenterPntLineEdit->sizePolicy().hasHeightForWidth());
        zCenterPntLineEdit->setSizePolicy(sizePolicy);
        zCenterPntLineEdit->setMaximumSize(QSize(80, 16777215));
        zCenterPntLineEdit->setReadOnly(true);

        horizontalLayout_5->addWidget(zCenterPntLineEdit);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(rectRegionDefinitionDialog2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        xRectWidthSpinBox = new QDoubleSpinBox(rectRegionDefinitionDialog2);
        xRectWidthSpinBox->setObjectName(QStringLiteral("xRectWidthSpinBox"));
        xRectWidthSpinBox->setFont(font);
        xRectWidthSpinBox->setDecimals(3);
        xRectWidthSpinBox->setMinimum(0.025);
        xRectWidthSpinBox->setMaximum(1000);
        xRectWidthSpinBox->setSingleStep(5);
        xRectWidthSpinBox->setValue(100);

        horizontalLayout_2->addWidget(xRectWidthSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(rectRegionDefinitionDialog2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        yRectWidthSpinBox = new QDoubleSpinBox(rectRegionDefinitionDialog2);
        yRectWidthSpinBox->setObjectName(QStringLiteral("yRectWidthSpinBox"));
        yRectWidthSpinBox->setFont(font);
        yRectWidthSpinBox->setDecimals(3);
        yRectWidthSpinBox->setMinimum(0.025);
        yRectWidthSpinBox->setMaximum(1000);
        yRectWidthSpinBox->setSingleStep(5);
        yRectWidthSpinBox->setValue(100);

        horizontalLayout->addWidget(yRectWidthSpinBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(rectRegionDefinitionDialog2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        xIncSpinBox = new QDoubleSpinBox(rectRegionDefinitionDialog2);
        xIncSpinBox->setObjectName(QStringLiteral("xIncSpinBox"));
        xIncSpinBox->setFont(font);
        xIncSpinBox->setDecimals(3);
        xIncSpinBox->setMinimum(0.001);
        xIncSpinBox->setMaximum(100);
        xIncSpinBox->setSingleStep(5);
        xIncSpinBox->setValue(1);

        horizontalLayout_3->addWidget(xIncSpinBox);

        horizontalSpacer_5 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(rectRegionDefinitionDialog2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_4->addWidget(label_7);

        yIncSpinBox = new QDoubleSpinBox(rectRegionDefinitionDialog2);
        yIncSpinBox->setObjectName(QStringLiteral("yIncSpinBox"));
        yIncSpinBox->setFont(font);
        yIncSpinBox->setDecimals(3);
        yIncSpinBox->setMinimum(0.001);
        yIncSpinBox->setMaximum(100);
        yIncSpinBox->setSingleStep(5);
        yIncSpinBox->setValue(1);

        horizontalLayout_4->addWidget(yIncSpinBox);

        horizontalSpacer_6 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        acceptPushButton = new QPushButton(rectRegionDefinitionDialog2);
        acceptPushButton->setObjectName(QStringLiteral("acceptPushButton"));
        acceptPushButton->setFont(font);

        horizontalLayout_6->addWidget(acceptPushButton);

        cancelPushButton = new QPushButton(rectRegionDefinitionDialog2);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setFont(font);

        horizontalLayout_6->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(rectRegionDefinitionDialog2);
        QObject::connect(acceptPushButton, SIGNAL(clicked()), rectRegionDefinitionDialog2, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), rectRegionDefinitionDialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(rectRegionDefinitionDialog2);
    } // setupUi

    void retranslateUi(QDialog *rectRegionDefinitionDialog2)
    {
        rectRegionDefinitionDialog2->setWindowTitle(QApplication::translate("rectRegionDefinitionDialog2", "Define Rectangular Region", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("rectRegionDefinitionDialog2", "Center Point of Rectangle", Q_NULLPTR));
        label_4->setText(QApplication::translate("rectRegionDefinitionDialog2", "X:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        xCenterPntLineEdit->setToolTip(QApplication::translate("rectRegionDefinitionDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        xCenterPntLineEdit->setText(QApplication::translate("rectRegionDefinitionDialog2", "0.0", Q_NULLPTR));
        label_5->setText(QApplication::translate("rectRegionDefinitionDialog2", "Y:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        yCenterPntLineEdit->setToolTip(QApplication::translate("rectRegionDefinitionDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        yCenterPntLineEdit->setText(QApplication::translate("rectRegionDefinitionDialog2", "0.0", Q_NULLPTR));
        label_6->setText(QApplication::translate("rectRegionDefinitionDialog2", "Z:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zCenterPntLineEdit->setToolTip(QApplication::translate("rectRegionDefinitionDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        zCenterPntLineEdit->setText(QApplication::translate("rectRegionDefinitionDialog2", "0.0", Q_NULLPTR));
        label->setText(QApplication::translate("rectRegionDefinitionDialog2", "Width of Rectangle in X-Direction [mm]:", Q_NULLPTR));
        label_2->setText(QApplication::translate("rectRegionDefinitionDialog2", "Width of Rectangle in Y-Direction [mm]:", Q_NULLPTR));
        label_3->setText(QApplication::translate("rectRegionDefinitionDialog2", "Increment in X-Direction [mm]:", Q_NULLPTR));
        label_7->setText(QApplication::translate("rectRegionDefinitionDialog2", "Increment in Y-Direction [mm]:", Q_NULLPTR));
        acceptPushButton->setText(QApplication::translate("rectRegionDefinitionDialog2", "Accept", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("rectRegionDefinitionDialog2", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rectRegionDefinitionDialog2: public Ui_rectRegionDefinitionDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTREGIONDEFINITIONDIALOG2_H
