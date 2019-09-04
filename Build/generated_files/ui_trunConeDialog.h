/********************************************************************************
** Form generated from reading UI file 'trunConeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRUNCONEDIALOG_H
#define UI_TRUNCONEDIALOG_H

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

class Ui_trunConeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *baseDiameterLabel;
    QLineEdit *baseDiamLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *wallAngleLabel;
    QLineEdit *wallAngleLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *depthLabel;
    QLineEdit *depthLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *filletRadiusLabel;
    QLineEdit *filletRadLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *createTrunConePushButton;
    QPushButton *closePushButton;

    void setupUi(QDialog *trunConeDialog)
    {
        if (trunConeDialog->objectName().isEmpty())
            trunConeDialog->setObjectName(QStringLiteral("trunConeDialog"));
        trunConeDialog->resize(272, 173);
        verticalLayout = new QVBoxLayout(trunConeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        baseDiameterLabel = new QLabel(trunConeDialog);
        baseDiameterLabel->setObjectName(QStringLiteral("baseDiameterLabel"));
        QFont font;
        font.setPointSize(10);
        baseDiameterLabel->setFont(font);

        horizontalLayout_5->addWidget(baseDiameterLabel);

        baseDiamLineEdit = new QLineEdit(trunConeDialog);
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

        horizontalLayout_5->addWidget(baseDiamLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        wallAngleLabel = new QLabel(trunConeDialog);
        wallAngleLabel->setObjectName(QStringLiteral("wallAngleLabel"));
        wallAngleLabel->setFont(font);

        horizontalLayout_4->addWidget(wallAngleLabel);

        wallAngleLineEdit = new QLineEdit(trunConeDialog);
        wallAngleLineEdit->setObjectName(QStringLiteral("wallAngleLineEdit"));
        sizePolicy.setHeightForWidth(wallAngleLineEdit->sizePolicy().hasHeightForWidth());
        wallAngleLineEdit->setSizePolicy(sizePolicy);
        wallAngleLineEdit->setMinimumSize(QSize(100, 0));
        wallAngleLineEdit->setMaximumSize(QSize(100, 16777215));
        wallAngleLineEdit->setBaseSize(QSize(60, 0));
        wallAngleLineEdit->setFont(font);

        horizontalLayout_4->addWidget(wallAngleLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        depthLabel = new QLabel(trunConeDialog);
        depthLabel->setObjectName(QStringLiteral("depthLabel"));
        depthLabel->setFont(font);

        horizontalLayout_3->addWidget(depthLabel);

        depthLineEdit = new QLineEdit(trunConeDialog);
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
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        filletRadiusLabel = new QLabel(trunConeDialog);
        filletRadiusLabel->setObjectName(QStringLiteral("filletRadiusLabel"));
        filletRadiusLabel->setFont(font);

        horizontalLayout_2->addWidget(filletRadiusLabel);

        filletRadLineEdit = new QLineEdit(trunConeDialog);
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
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        createTrunConePushButton = new QPushButton(trunConeDialog);
        createTrunConePushButton->setObjectName(QStringLiteral("createTrunConePushButton"));
        createTrunConePushButton->setFont(font);

        horizontalLayout->addWidget(createTrunConePushButton);

        closePushButton = new QPushButton(trunConeDialog);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setFont(font);

        horizontalLayout->addWidget(closePushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(trunConeDialog);
        QObject::connect(closePushButton, SIGNAL(clicked()), trunConeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(trunConeDialog);
    } // setupUi

    void retranslateUi(QDialog *trunConeDialog)
    {
        trunConeDialog->setWindowTitle(QApplication::translate("trunConeDialog", "Create Cone", Q_NULLPTR));
        baseDiameterLabel->setText(QApplication::translate("trunConeDialog", "Top Opening Diameter:", Q_NULLPTR));
        baseDiamLineEdit->setText(QApplication::translate("trunConeDialog", "100.0", Q_NULLPTR));
        wallAngleLabel->setText(QApplication::translate("trunConeDialog", "Wall Angle [deg]:", Q_NULLPTR));
        wallAngleLineEdit->setText(QApplication::translate("trunConeDialog", "45.0", Q_NULLPTR));
        depthLabel->setText(QApplication::translate("trunConeDialog", "Depth:", Q_NULLPTR));
        depthLineEdit->setText(QApplication::translate("trunConeDialog", "40.0", Q_NULLPTR));
        filletRadiusLabel->setText(QApplication::translate("trunConeDialog", "Fillet Radius:", Q_NULLPTR));
        filletRadLineEdit->setText(QApplication::translate("trunConeDialog", "6.35", Q_NULLPTR));
        createTrunConePushButton->setText(QApplication::translate("trunConeDialog", "Create", Q_NULLPTR));
        closePushButton->setText(QApplication::translate("trunConeDialog", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class trunConeDialog: public Ui_trunConeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRUNCONEDIALOG_H
