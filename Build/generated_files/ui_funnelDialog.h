/********************************************************************************
** Form generated from reading UI file 'funnelDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNNELDIALOG_H
#define UI_FUNNELDIALOG_H

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

class Ui_funnelDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *baseDiameterLabel;
    QLineEdit *baseDiamLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *wallAngleLabel;
    QLineEdit *initWallAngleLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *funnelRadLabel;
    QLineEdit *radOfArcLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *depthLabel;
    QLineEdit *depthLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *filletRadiusLabel;
    QLineEdit *filletRadLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *createFunnelPushButton;
    QPushButton *closePushButton;

    void setupUi(QDialog *funnelDialog)
    {
        if (funnelDialog->objectName().isEmpty())
            funnelDialog->setObjectName(QStringLiteral("funnelDialog"));
        funnelDialog->resize(273, 203);
        verticalLayout = new QVBoxLayout(funnelDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        baseDiameterLabel = new QLabel(funnelDialog);
        baseDiameterLabel->setObjectName(QStringLiteral("baseDiameterLabel"));
        QFont font;
        font.setPointSize(10);
        baseDiameterLabel->setFont(font);

        horizontalLayout_6->addWidget(baseDiameterLabel);

        baseDiamLineEdit = new QLineEdit(funnelDialog);
        baseDiamLineEdit->setObjectName(QStringLiteral("baseDiamLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(baseDiamLineEdit->sizePolicy().hasHeightForWidth());
        baseDiamLineEdit->setSizePolicy(sizePolicy);
        baseDiamLineEdit->setMinimumSize(QSize(100, 0));
        baseDiamLineEdit->setMaximumSize(QSize(100, 16777215));
        baseDiamLineEdit->setBaseSize(QSize(60, 0));
        baseDiamLineEdit->setFont(font);

        horizontalLayout_6->addWidget(baseDiamLineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        wallAngleLabel = new QLabel(funnelDialog);
        wallAngleLabel->setObjectName(QStringLiteral("wallAngleLabel"));
        wallAngleLabel->setFont(font);

        horizontalLayout_5->addWidget(wallAngleLabel);

        initWallAngleLineEdit = new QLineEdit(funnelDialog);
        initWallAngleLineEdit->setObjectName(QStringLiteral("initWallAngleLineEdit"));
        sizePolicy.setHeightForWidth(initWallAngleLineEdit->sizePolicy().hasHeightForWidth());
        initWallAngleLineEdit->setSizePolicy(sizePolicy);
        initWallAngleLineEdit->setMinimumSize(QSize(100, 0));
        initWallAngleLineEdit->setMaximumSize(QSize(100, 16777215));
        initWallAngleLineEdit->setBaseSize(QSize(60, 0));
        initWallAngleLineEdit->setFont(font);

        horizontalLayout_5->addWidget(initWallAngleLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        funnelRadLabel = new QLabel(funnelDialog);
        funnelRadLabel->setObjectName(QStringLiteral("funnelRadLabel"));
        funnelRadLabel->setFont(font);

        horizontalLayout_4->addWidget(funnelRadLabel);

        radOfArcLineEdit = new QLineEdit(funnelDialog);
        radOfArcLineEdit->setObjectName(QStringLiteral("radOfArcLineEdit"));
        sizePolicy.setHeightForWidth(radOfArcLineEdit->sizePolicy().hasHeightForWidth());
        radOfArcLineEdit->setSizePolicy(sizePolicy);
        radOfArcLineEdit->setMinimumSize(QSize(100, 0));
        radOfArcLineEdit->setMaximumSize(QSize(100, 16777215));
        radOfArcLineEdit->setBaseSize(QSize(60, 0));
        radOfArcLineEdit->setFont(font);

        horizontalLayout_4->addWidget(radOfArcLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        depthLabel = new QLabel(funnelDialog);
        depthLabel->setObjectName(QStringLiteral("depthLabel"));
        depthLabel->setFont(font);

        horizontalLayout_3->addWidget(depthLabel);

        depthLineEdit = new QLineEdit(funnelDialog);
        depthLineEdit->setObjectName(QStringLiteral("depthLineEdit"));
        sizePolicy.setHeightForWidth(depthLineEdit->sizePolicy().hasHeightForWidth());
        depthLineEdit->setSizePolicy(sizePolicy);
        depthLineEdit->setMinimumSize(QSize(100, 0));
        depthLineEdit->setMaximumSize(QSize(100, 16777215));
        depthLineEdit->setBaseSize(QSize(60, 0));
        depthLineEdit->setFont(font);

        horizontalLayout_3->addWidget(depthLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        filletRadiusLabel = new QLabel(funnelDialog);
        filletRadiusLabel->setObjectName(QStringLiteral("filletRadiusLabel"));
        filletRadiusLabel->setFont(font);

        horizontalLayout_2->addWidget(filletRadiusLabel);

        filletRadLineEdit = new QLineEdit(funnelDialog);
        filletRadLineEdit->setObjectName(QStringLiteral("filletRadLineEdit"));
        sizePolicy.setHeightForWidth(filletRadLineEdit->sizePolicy().hasHeightForWidth());
        filletRadLineEdit->setSizePolicy(sizePolicy);
        filletRadLineEdit->setMinimumSize(QSize(100, 0));
        filletRadLineEdit->setMaximumSize(QSize(100, 16777215));
        filletRadLineEdit->setBaseSize(QSize(60, 0));
        filletRadLineEdit->setFont(font);

        horizontalLayout_2->addWidget(filletRadLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        createFunnelPushButton = new QPushButton(funnelDialog);
        createFunnelPushButton->setObjectName(QStringLiteral("createFunnelPushButton"));
        createFunnelPushButton->setFont(font);

        horizontalLayout->addWidget(createFunnelPushButton);

        closePushButton = new QPushButton(funnelDialog);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setFont(font);

        horizontalLayout->addWidget(closePushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(funnelDialog);
        QObject::connect(closePushButton, SIGNAL(clicked()), funnelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(funnelDialog);
    } // setupUi

    void retranslateUi(QDialog *funnelDialog)
    {
        funnelDialog->setWindowTitle(QApplication::translate("funnelDialog", "Create Funnel", Q_NULLPTR));
        baseDiameterLabel->setText(QApplication::translate("funnelDialog", "Top Opening Diameter:", Q_NULLPTR));
        baseDiamLineEdit->setText(QApplication::translate("funnelDialog", "120.0", Q_NULLPTR));
        wallAngleLabel->setText(QApplication::translate("funnelDialog", "Initial Wall Angle [deg]:", Q_NULLPTR));
        initWallAngleLineEdit->setText(QApplication::translate("funnelDialog", "15.0", Q_NULLPTR));
        funnelRadLabel->setText(QApplication::translate("funnelDialog", "Funnel's Radius of Arc:", Q_NULLPTR));
        radOfArcLineEdit->setText(QApplication::translate("funnelDialog", "60.0", Q_NULLPTR));
        depthLabel->setText(QApplication::translate("funnelDialog", "Depth:", Q_NULLPTR));
        depthLineEdit->setText(QApplication::translate("funnelDialog", "55.0", Q_NULLPTR));
        filletRadiusLabel->setText(QApplication::translate("funnelDialog", "Fillet Radius:", Q_NULLPTR));
        filletRadLineEdit->setText(QApplication::translate("funnelDialog", "6.35", Q_NULLPTR));
        createFunnelPushButton->setText(QApplication::translate("funnelDialog", "Create", Q_NULLPTR));
        closePushButton->setText(QApplication::translate("funnelDialog", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class funnelDialog: public Ui_funnelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNNELDIALOG_H
