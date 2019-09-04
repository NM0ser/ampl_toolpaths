/********************************************************************************
** Form generated from reading UI file 'rotationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATIONDIALOG_H
#define UI_ROTATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_rotationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *BasePtRotAxisLabel;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *XBasePtLabel;
    QLineEdit *XBasePtLineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *YBasePtLabel;
    QLineEdit *YBasePtLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *ZBasePtLabel;
    QLineEdit *ZBasePtLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *RotationAxisDirLabel;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *XRotDirLabel;
    QLineEdit *XRotAxisDirLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *YRotDirLabel;
    QLineEdit *YRotAxisDirLineEdit;
    QSpacerItem *horizontalSpacer_5;
    QLabel *ZRotDirLabel;
    QLineEdit *ZRotAxisDirLineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *RotAngleLabel;
    QLineEdit *RotAngleLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *RotatePushButton;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *rotationDialog)
    {
        if (rotationDialog->objectName().isEmpty())
            rotationDialog->setObjectName(QStringLiteral("rotationDialog"));
        rotationDialog->setWindowModality(Qt::NonModal);
        rotationDialog->resize(345, 209);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rotationDialog->sizePolicy().hasHeightForWidth());
        rotationDialog->setSizePolicy(sizePolicy);
        rotationDialog->setModal(false);
        verticalLayout = new QVBoxLayout(rotationDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        BasePtRotAxisLabel = new QLabel(rotationDialog);
        BasePtRotAxisLabel->setObjectName(QStringLiteral("BasePtRotAxisLabel"));
        QFont font;
        font.setPointSize(10);
        BasePtRotAxisLabel->setFont(font);

        horizontalLayout_2->addWidget(BasePtRotAxisLabel);

        horizontalSpacer_3 = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        XBasePtLabel = new QLabel(rotationDialog);
        XBasePtLabel->setObjectName(QStringLiteral("XBasePtLabel"));
        XBasePtLabel->setFont(font);

        horizontalLayout_3->addWidget(XBasePtLabel);

        XBasePtLineEdit = new QLineEdit(rotationDialog);
        XBasePtLineEdit->setObjectName(QStringLiteral("XBasePtLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(XBasePtLineEdit->sizePolicy().hasHeightForWidth());
        XBasePtLineEdit->setSizePolicy(sizePolicy1);
        XBasePtLineEdit->setMinimumSize(QSize(60, 16));
        XBasePtLineEdit->setMaximumSize(QSize(60, 22));
        XBasePtLineEdit->setFont(font);

        horizontalLayout_3->addWidget(XBasePtLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        YBasePtLabel = new QLabel(rotationDialog);
        YBasePtLabel->setObjectName(QStringLiteral("YBasePtLabel"));
        YBasePtLabel->setFont(font);

        horizontalLayout_3->addWidget(YBasePtLabel);

        YBasePtLineEdit = new QLineEdit(rotationDialog);
        YBasePtLineEdit->setObjectName(QStringLiteral("YBasePtLineEdit"));
        sizePolicy1.setHeightForWidth(YBasePtLineEdit->sizePolicy().hasHeightForWidth());
        YBasePtLineEdit->setSizePolicy(sizePolicy1);
        YBasePtLineEdit->setMinimumSize(QSize(60, 16));
        YBasePtLineEdit->setMaximumSize(QSize(60, 22));
        YBasePtLineEdit->setFont(font);

        horizontalLayout_3->addWidget(YBasePtLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ZBasePtLabel = new QLabel(rotationDialog);
        ZBasePtLabel->setObjectName(QStringLiteral("ZBasePtLabel"));
        ZBasePtLabel->setFont(font);

        horizontalLayout_3->addWidget(ZBasePtLabel);

        ZBasePtLineEdit = new QLineEdit(rotationDialog);
        ZBasePtLineEdit->setObjectName(QStringLiteral("ZBasePtLineEdit"));
        sizePolicy1.setHeightForWidth(ZBasePtLineEdit->sizePolicy().hasHeightForWidth());
        ZBasePtLineEdit->setSizePolicy(sizePolicy1);
        ZBasePtLineEdit->setMinimumSize(QSize(60, 16));
        ZBasePtLineEdit->setMaximumSize(QSize(60, 22));
        ZBasePtLineEdit->setFont(font);

        horizontalLayout_3->addWidget(ZBasePtLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        RotationAxisDirLabel = new QLabel(rotationDialog);
        RotationAxisDirLabel->setObjectName(QStringLiteral("RotationAxisDirLabel"));
        RotationAxisDirLabel->setFont(font);

        horizontalLayout_4->addWidget(RotationAxisDirLabel);

        horizontalSpacer_8 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        XRotDirLabel = new QLabel(rotationDialog);
        XRotDirLabel->setObjectName(QStringLiteral("XRotDirLabel"));
        XRotDirLabel->setFont(font);

        horizontalLayout_5->addWidget(XRotDirLabel);

        XRotAxisDirLineEdit = new QLineEdit(rotationDialog);
        XRotAxisDirLineEdit->setObjectName(QStringLiteral("XRotAxisDirLineEdit"));
        sizePolicy1.setHeightForWidth(XRotAxisDirLineEdit->sizePolicy().hasHeightForWidth());
        XRotAxisDirLineEdit->setSizePolicy(sizePolicy1);
        XRotAxisDirLineEdit->setMinimumSize(QSize(60, 16));
        XRotAxisDirLineEdit->setMaximumSize(QSize(60, 22));
        XRotAxisDirLineEdit->setFont(font);

        horizontalLayout_5->addWidget(XRotAxisDirLineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        YRotDirLabel = new QLabel(rotationDialog);
        YRotDirLabel->setObjectName(QStringLiteral("YRotDirLabel"));
        YRotDirLabel->setFont(font);

        horizontalLayout_5->addWidget(YRotDirLabel);

        YRotAxisDirLineEdit = new QLineEdit(rotationDialog);
        YRotAxisDirLineEdit->setObjectName(QStringLiteral("YRotAxisDirLineEdit"));
        sizePolicy1.setHeightForWidth(YRotAxisDirLineEdit->sizePolicy().hasHeightForWidth());
        YRotAxisDirLineEdit->setSizePolicy(sizePolicy1);
        YRotAxisDirLineEdit->setMinimumSize(QSize(60, 16));
        YRotAxisDirLineEdit->setMaximumSize(QSize(60, 22));
        YRotAxisDirLineEdit->setFont(font);

        horizontalLayout_5->addWidget(YRotAxisDirLineEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        ZRotDirLabel = new QLabel(rotationDialog);
        ZRotDirLabel->setObjectName(QStringLiteral("ZRotDirLabel"));
        ZRotDirLabel->setFont(font);

        horizontalLayout_5->addWidget(ZRotDirLabel);

        ZRotAxisDirLineEdit = new QLineEdit(rotationDialog);
        ZRotAxisDirLineEdit->setObjectName(QStringLiteral("ZRotAxisDirLineEdit"));
        sizePolicy1.setHeightForWidth(ZRotAxisDirLineEdit->sizePolicy().hasHeightForWidth());
        ZRotAxisDirLineEdit->setSizePolicy(sizePolicy1);
        ZRotAxisDirLineEdit->setMinimumSize(QSize(60, 16));
        ZRotAxisDirLineEdit->setMaximumSize(QSize(60, 22));
        ZRotAxisDirLineEdit->setFont(font);

        horizontalLayout_5->addWidget(ZRotAxisDirLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        RotAngleLabel = new QLabel(rotationDialog);
        RotAngleLabel->setObjectName(QStringLiteral("RotAngleLabel"));
        RotAngleLabel->setFont(font);

        horizontalLayout_6->addWidget(RotAngleLabel);

        RotAngleLineEdit = new QLineEdit(rotationDialog);
        RotAngleLineEdit->setObjectName(QStringLiteral("RotAngleLineEdit"));
        sizePolicy1.setHeightForWidth(RotAngleLineEdit->sizePolicy().hasHeightForWidth());
        RotAngleLineEdit->setSizePolicy(sizePolicy1);
        RotAngleLineEdit->setMinimumSize(QSize(60, 16));
        RotAngleLineEdit->setMaximumSize(QSize(60, 22));
        RotAngleLineEdit->setFont(font);

        horizontalLayout_6->addWidget(RotAngleLineEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        RotatePushButton = new QPushButton(rotationDialog);
        RotatePushButton->setObjectName(QStringLiteral("RotatePushButton"));
        RotatePushButton->setFont(font);

        horizontalLayout_7->addWidget(RotatePushButton);

        CancelPushButton = new QPushButton(rotationDialog);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));
        CancelPushButton->setFont(font);

        horizontalLayout_7->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(rotationDialog);
        QObject::connect(CancelPushButton, SIGNAL(clicked()), rotationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(rotationDialog);
    } // setupUi

    void retranslateUi(QDialog *rotationDialog)
    {
        rotationDialog->setWindowTitle(QApplication::translate("rotationDialog", "Rotate", Q_NULLPTR));
        BasePtRotAxisLabel->setText(QApplication::translate("rotationDialog", "Base Point of Rotation Axis:", Q_NULLPTR));
        XBasePtLabel->setText(QApplication::translate("rotationDialog", "X:", Q_NULLPTR));
        XBasePtLineEdit->setText(QApplication::translate("rotationDialog", "0.0", Q_NULLPTR));
        YBasePtLabel->setText(QApplication::translate("rotationDialog", "Y:", Q_NULLPTR));
        YBasePtLineEdit->setText(QApplication::translate("rotationDialog", "0.0", Q_NULLPTR));
        ZBasePtLabel->setText(QApplication::translate("rotationDialog", "Z:", Q_NULLPTR));
        ZBasePtLineEdit->setText(QApplication::translate("rotationDialog", "0.0", Q_NULLPTR));
        RotationAxisDirLabel->setText(QApplication::translate("rotationDialog", "Rotation Axis Direction:", Q_NULLPTR));
        XRotDirLabel->setText(QApplication::translate("rotationDialog", "X:", Q_NULLPTR));
        XRotAxisDirLineEdit->setText(QApplication::translate("rotationDialog", "1.0", Q_NULLPTR));
        YRotDirLabel->setText(QApplication::translate("rotationDialog", "Y:", Q_NULLPTR));
        YRotAxisDirLineEdit->setText(QApplication::translate("rotationDialog", "0.0", Q_NULLPTR));
        ZRotDirLabel->setText(QApplication::translate("rotationDialog", "Z:", Q_NULLPTR));
        ZRotAxisDirLineEdit->setText(QApplication::translate("rotationDialog", "0.0", Q_NULLPTR));
        RotAngleLabel->setText(QApplication::translate("rotationDialog", "Rotation Angle using Right-Hand Rule [deg]:", Q_NULLPTR));
        RotAngleLineEdit->setText(QApplication::translate("rotationDialog", "180.0", Q_NULLPTR));
        RotatePushButton->setText(QApplication::translate("rotationDialog", "Rotate", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("rotationDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rotationDialog: public Ui_rotationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATIONDIALOG_H
