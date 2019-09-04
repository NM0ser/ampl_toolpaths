/********************************************************************************
** Form generated from reading UI file 'lineRegionDefinitionDialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEREGIONDEFINITIONDIALOG2_H
#define UI_LINEREGIONDEFINITIONDIALOG2_H

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

class Ui_lineRegionDefinitionDialog2
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *xStartPntLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *yStartPntLineEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QLineEdit *zStartPntLineEdit;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *xEndPntLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_8;
    QLineEdit *yEndPntLineEdit;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_9;
    QLineEdit *zEndPntLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDoubleSpinBox *xIncSpinBox;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *lineRegionDefinitionDialog2)
    {
        if (lineRegionDefinitionDialog2->objectName().isEmpty())
            lineRegionDefinitionDialog2->setObjectName(QStringLiteral("lineRegionDefinitionDialog2"));
        lineRegionDefinitionDialog2->resize(387, 218);
        verticalLayout = new QVBoxLayout(lineRegionDefinitionDialog2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(lineRegionDefinitionDialog2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        xStartPntLineEdit = new QLineEdit(groupBox);
        xStartPntLineEdit->setObjectName(QStringLiteral("xStartPntLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(xStartPntLineEdit->sizePolicy().hasHeightForWidth());
        xStartPntLineEdit->setSizePolicy(sizePolicy);
        xStartPntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(xStartPntLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        yStartPntLineEdit = new QLineEdit(groupBox);
        yStartPntLineEdit->setObjectName(QStringLiteral("yStartPntLineEdit"));
        sizePolicy.setHeightForWidth(yStartPntLineEdit->sizePolicy().hasHeightForWidth());
        yStartPntLineEdit->setSizePolicy(sizePolicy);
        yStartPntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(yStartPntLineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        zStartPntLineEdit = new QLineEdit(groupBox);
        zStartPntLineEdit->setObjectName(QStringLiteral("zStartPntLineEdit"));
        zStartPntLineEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(zStartPntLineEdit->sizePolicy().hasHeightForWidth());
        zStartPntLineEdit->setSizePolicy(sizePolicy);
        zStartPntLineEdit->setMaximumSize(QSize(80, 16777215));
        zStartPntLineEdit->setReadOnly(true);

        horizontalLayout_5->addWidget(zStartPntLineEdit);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(lineRegionDefinitionDialog2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        horizontalLayout_6 = new QHBoxLayout(groupBox_2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        xEndPntLineEdit = new QLineEdit(groupBox_2);
        xEndPntLineEdit->setObjectName(QStringLiteral("xEndPntLineEdit"));
        sizePolicy.setHeightForWidth(xEndPntLineEdit->sizePolicy().hasHeightForWidth());
        xEndPntLineEdit->setSizePolicy(sizePolicy);
        xEndPntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(xEndPntLineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        yEndPntLineEdit = new QLineEdit(groupBox_2);
        yEndPntLineEdit->setObjectName(QStringLiteral("yEndPntLineEdit"));
        sizePolicy.setHeightForWidth(yEndPntLineEdit->sizePolicy().hasHeightForWidth());
        yEndPntLineEdit->setSizePolicy(sizePolicy);
        yEndPntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(yEndPntLineEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        zEndPntLineEdit = new QLineEdit(groupBox_2);
        zEndPntLineEdit->setObjectName(QStringLiteral("zEndPntLineEdit"));
        zEndPntLineEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(zEndPntLineEdit->sizePolicy().hasHeightForWidth());
        zEndPntLineEdit->setSizePolicy(sizePolicy);
        zEndPntLineEdit->setMaximumSize(QSize(80, 16777215));
        zEndPntLineEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(zEndPntLineEdit);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(lineRegionDefinitionDialog2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        xIncSpinBox = new QDoubleSpinBox(lineRegionDefinitionDialog2);
        xIncSpinBox->setObjectName(QStringLiteral("xIncSpinBox"));
        xIncSpinBox->setFont(font);
        xIncSpinBox->setDecimals(3);
        xIncSpinBox->setMinimum(0.001);
        xIncSpinBox->setMaximum(100);
        xIncSpinBox->setSingleStep(5);
        xIncSpinBox->setValue(1);

        horizontalLayout->addWidget(xIncSpinBox);

        horizontalSpacer_6 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(lineRegionDefinitionDialog2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(lineRegionDefinitionDialog2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(lineRegionDefinitionDialog2);
        QObject::connect(pushButton, SIGNAL(clicked()), lineRegionDefinitionDialog2, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lineRegionDefinitionDialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(lineRegionDefinitionDialog2);
    } // setupUi

    void retranslateUi(QDialog *lineRegionDefinitionDialog2)
    {
        lineRegionDefinitionDialog2->setWindowTitle(QApplication::translate("lineRegionDefinitionDialog2", "Define Line Region", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("lineRegionDefinitionDialog2", "Start Point of Line", Q_NULLPTR));
        label_4->setText(QApplication::translate("lineRegionDefinitionDialog2", "X:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        xStartPntLineEdit->setToolTip(QApplication::translate("lineRegionDefinitionDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        xStartPntLineEdit->setText(QApplication::translate("lineRegionDefinitionDialog2", "-10.0", Q_NULLPTR));
        label_5->setText(QApplication::translate("lineRegionDefinitionDialog2", "Y:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        yStartPntLineEdit->setToolTip(QApplication::translate("lineRegionDefinitionDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        yStartPntLineEdit->setText(QApplication::translate("lineRegionDefinitionDialog2", "0.0", Q_NULLPTR));
        label_6->setText(QApplication::translate("lineRegionDefinitionDialog2", "Z:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zStartPntLineEdit->setToolTip(QApplication::translate("lineRegionDefinitionDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        zStartPntLineEdit->setText(QApplication::translate("lineRegionDefinitionDialog2", "0.0", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("lineRegionDefinitionDialog2", "End Point of Line", Q_NULLPTR));
        label_7->setText(QApplication::translate("lineRegionDefinitionDialog2", "X:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        xEndPntLineEdit->setToolTip(QApplication::translate("lineRegionDefinitionDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        xEndPntLineEdit->setText(QApplication::translate("lineRegionDefinitionDialog2", "10.0", Q_NULLPTR));
        label_8->setText(QApplication::translate("lineRegionDefinitionDialog2", "Y:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        yEndPntLineEdit->setToolTip(QApplication::translate("lineRegionDefinitionDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        yEndPntLineEdit->setText(QApplication::translate("lineRegionDefinitionDialog2", "0.0", Q_NULLPTR));
        label_9->setText(QApplication::translate("lineRegionDefinitionDialog2", "Z:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zEndPntLineEdit->setToolTip(QApplication::translate("lineRegionDefinitionDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        zEndPntLineEdit->setText(QApplication::translate("lineRegionDefinitionDialog2", "0.0", Q_NULLPTR));
        label_3->setText(QApplication::translate("lineRegionDefinitionDialog2", "Increment Along the Line [mm]:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("lineRegionDefinitionDialog2", "Accept", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("lineRegionDefinitionDialog2", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lineRegionDefinitionDialog2: public Ui_lineRegionDefinitionDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEREGIONDEFINITIONDIALOG2_H
