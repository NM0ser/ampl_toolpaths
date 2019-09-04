/********************************************************************************
** Form generated from reading UI file 'clippingPlaneDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIPPINGPLANEDIALOG_H
#define UI_CLIPPINGPLANEDIALOG_H

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

class Ui_clippingPlaneDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_7;
    QLineEdit *basePntXLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QLineEdit *basePntYLineEdit;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_6;
    QLineEdit *basePntZLineEdit;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *normalVecXLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLineEdit *normalVecYLineEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QLineEdit *normalVecZLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *reversePushButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *clippingOnPushButton;
    QPushButton *clippingOffPushButton;

    void setupUi(QDialog *clippingPlaneDialog)
    {
        if (clippingPlaneDialog->objectName().isEmpty())
            clippingPlaneDialog->setObjectName(QStringLiteral("clippingPlaneDialog"));
        clippingPlaneDialog->resize(361, 182);
        verticalLayout = new QVBoxLayout(clippingPlaneDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(clippingPlaneDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_7 = new QLabel(clippingPlaneDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout->addWidget(label_7);

        basePntXLineEdit = new QLineEdit(clippingPlaneDialog);
        basePntXLineEdit->setObjectName(QStringLiteral("basePntXLineEdit"));
        basePntXLineEdit->setFont(font);

        horizontalLayout->addWidget(basePntXLineEdit);

        horizontalSpacer_6 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        label_8 = new QLabel(clippingPlaneDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout->addWidget(label_8);

        basePntYLineEdit = new QLineEdit(clippingPlaneDialog);
        basePntYLineEdit->setObjectName(QStringLiteral("basePntYLineEdit"));
        basePntYLineEdit->setFont(font);

        horizontalLayout->addWidget(basePntYLineEdit);

        horizontalSpacer_7 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        label_6 = new QLabel(clippingPlaneDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout->addWidget(label_6);

        basePntZLineEdit = new QLineEdit(clippingPlaneDialog);
        basePntZLineEdit->setObjectName(QStringLiteral("basePntZLineEdit"));
        basePntZLineEdit->setFont(font);

        horizontalLayout->addWidget(basePntZLineEdit);

        horizontalSpacer_8 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(clippingPlaneDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(clippingPlaneDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        normalVecXLineEdit = new QLineEdit(clippingPlaneDialog);
        normalVecXLineEdit->setObjectName(QStringLiteral("normalVecXLineEdit"));
        normalVecXLineEdit->setFont(font);

        horizontalLayout_2->addWidget(normalVecXLineEdit);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_4 = new QLabel(clippingPlaneDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        normalVecYLineEdit = new QLineEdit(clippingPlaneDialog);
        normalVecYLineEdit->setObjectName(QStringLiteral("normalVecYLineEdit"));
        normalVecYLineEdit->setFont(font);

        horizontalLayout_2->addWidget(normalVecYLineEdit);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_5 = new QLabel(clippingPlaneDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        normalVecZLineEdit = new QLineEdit(clippingPlaneDialog);
        normalVecZLineEdit->setObjectName(QStringLiteral("normalVecZLineEdit"));
        normalVecZLineEdit->setFont(font);

        horizontalLayout_2->addWidget(normalVecZLineEdit);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        reversePushButton = new QPushButton(clippingPlaneDialog);
        reversePushButton->setObjectName(QStringLiteral("reversePushButton"));
        reversePushButton->setFont(font);

        horizontalLayout_3->addWidget(reversePushButton);

        horizontalSpacer_9 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        clippingOnPushButton = new QPushButton(clippingPlaneDialog);
        clippingOnPushButton->setObjectName(QStringLiteral("clippingOnPushButton"));
        clippingOnPushButton->setFont(font);

        horizontalLayout_3->addWidget(clippingOnPushButton);

        clippingOffPushButton = new QPushButton(clippingPlaneDialog);
        clippingOffPushButton->setObjectName(QStringLiteral("clippingOffPushButton"));
        clippingOffPushButton->setFont(font);

        horizontalLayout_3->addWidget(clippingOffPushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        QWidget::setTabOrder(basePntXLineEdit, basePntYLineEdit);
        QWidget::setTabOrder(basePntYLineEdit, basePntZLineEdit);
        QWidget::setTabOrder(basePntZLineEdit, normalVecXLineEdit);
        QWidget::setTabOrder(normalVecXLineEdit, normalVecYLineEdit);
        QWidget::setTabOrder(normalVecYLineEdit, normalVecZLineEdit);
        QWidget::setTabOrder(normalVecZLineEdit, clippingOnPushButton);
        QWidget::setTabOrder(clippingOnPushButton, clippingOffPushButton);
        QWidget::setTabOrder(clippingOffPushButton, reversePushButton);

        retranslateUi(clippingPlaneDialog);

        QMetaObject::connectSlotsByName(clippingPlaneDialog);
    } // setupUi

    void retranslateUi(QDialog *clippingPlaneDialog)
    {
        clippingPlaneDialog->setWindowTitle(QApplication::translate("clippingPlaneDialog", "Clipping Plane Definition", Q_NULLPTR));
        label->setText(QApplication::translate("clippingPlaneDialog", "Base Point of Plane:", Q_NULLPTR));
        label_7->setText(QApplication::translate("clippingPlaneDialog", "X:", Q_NULLPTR));
        basePntXLineEdit->setText(QApplication::translate("clippingPlaneDialog", "0.0", Q_NULLPTR));
        label_8->setText(QApplication::translate("clippingPlaneDialog", "Y:", Q_NULLPTR));
        basePntYLineEdit->setText(QApplication::translate("clippingPlaneDialog", "0.0", Q_NULLPTR));
        label_6->setText(QApplication::translate("clippingPlaneDialog", "Z:", Q_NULLPTR));
        basePntZLineEdit->setText(QApplication::translate("clippingPlaneDialog", "0.0", Q_NULLPTR));
        label_2->setText(QApplication::translate("clippingPlaneDialog", "Normal Vector of Plane:", Q_NULLPTR));
        label_3->setText(QApplication::translate("clippingPlaneDialog", "X:", Q_NULLPTR));
        normalVecXLineEdit->setText(QApplication::translate("clippingPlaneDialog", "1.0", Q_NULLPTR));
        label_4->setText(QApplication::translate("clippingPlaneDialog", "Y:", Q_NULLPTR));
        normalVecYLineEdit->setText(QApplication::translate("clippingPlaneDialog", "0.0", Q_NULLPTR));
        label_5->setText(QApplication::translate("clippingPlaneDialog", "Z:", Q_NULLPTR));
        normalVecZLineEdit->setText(QApplication::translate("clippingPlaneDialog", "0.0", Q_NULLPTR));
        reversePushButton->setText(QApplication::translate("clippingPlaneDialog", "Reverse", Q_NULLPTR));
        clippingOnPushButton->setText(QApplication::translate("clippingPlaneDialog", "Clipping On", Q_NULLPTR));
        clippingOffPushButton->setText(QApplication::translate("clippingPlaneDialog", "Clipping Off", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class clippingPlaneDialog: public Ui_clippingPlaneDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIPPINGPLANEDIALOG_H
