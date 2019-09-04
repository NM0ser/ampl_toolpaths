/********************************************************************************
** Form generated from reading UI file 'scaleDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALEDIALOG_H
#define UI_SCALEDIALOG_H

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

class Ui_scaleDialog
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *ScaleWRTPointLabel;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *XLabel;
    QLineEdit *XLineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *YLabel;
    QLineEdit *YLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *ZLabel;
    QLineEdit *ZLineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ScaleFactLabel;
    QLineEdit *ScaleFactorLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ScalePushButton;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *scaleDialog)
    {
        if (scaleDialog->objectName().isEmpty())
            scaleDialog->setObjectName(QStringLiteral("scaleDialog"));
        scaleDialog->setWindowModality(Qt::NonModal);
        scaleDialog->resize(300, 160);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scaleDialog->sizePolicy().hasHeightForWidth());
        scaleDialog->setSizePolicy(sizePolicy);
        scaleDialog->setModal(false);
        horizontalLayout_5 = new QHBoxLayout(scaleDialog);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ScaleWRTPointLabel = new QLabel(scaleDialog);
        ScaleWRTPointLabel->setObjectName(QStringLiteral("ScaleWRTPointLabel"));
        QFont font;
        font.setPointSize(10);
        ScaleWRTPointLabel->setFont(font);

        horizontalLayout->addWidget(ScaleWRTPointLabel);

        horizontalSpacer_3 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        XLabel = new QLabel(scaleDialog);
        XLabel->setObjectName(QStringLiteral("XLabel"));
        XLabel->setFont(font);

        horizontalLayout_2->addWidget(XLabel);

        XLineEdit = new QLineEdit(scaleDialog);
        XLineEdit->setObjectName(QStringLiteral("XLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(XLineEdit->sizePolicy().hasHeightForWidth());
        XLineEdit->setSizePolicy(sizePolicy1);
        XLineEdit->setMinimumSize(QSize(60, 16));
        XLineEdit->setMaximumSize(QSize(60, 22));
        XLineEdit->setFont(font);

        horizontalLayout_2->addWidget(XLineEdit);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        YLabel = new QLabel(scaleDialog);
        YLabel->setObjectName(QStringLiteral("YLabel"));
        YLabel->setFont(font);

        horizontalLayout_2->addWidget(YLabel);

        YLineEdit = new QLineEdit(scaleDialog);
        YLineEdit->setObjectName(QStringLiteral("YLineEdit"));
        sizePolicy1.setHeightForWidth(YLineEdit->sizePolicy().hasHeightForWidth());
        YLineEdit->setSizePolicy(sizePolicy1);
        YLineEdit->setMinimumSize(QSize(60, 16));
        YLineEdit->setMaximumSize(QSize(60, 22));
        YLineEdit->setFont(font);

        horizontalLayout_2->addWidget(YLineEdit);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ZLabel = new QLabel(scaleDialog);
        ZLabel->setObjectName(QStringLiteral("ZLabel"));
        ZLabel->setFont(font);

        horizontalLayout_2->addWidget(ZLabel);

        ZLineEdit = new QLineEdit(scaleDialog);
        ZLineEdit->setObjectName(QStringLiteral("ZLineEdit"));
        sizePolicy1.setHeightForWidth(ZLineEdit->sizePolicy().hasHeightForWidth());
        ZLineEdit->setSizePolicy(sizePolicy1);
        ZLineEdit->setMinimumSize(QSize(60, 16));
        ZLineEdit->setMaximumSize(QSize(60, 22));
        ZLineEdit->setFont(font);

        horizontalLayout_2->addWidget(ZLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ScaleFactLabel = new QLabel(scaleDialog);
        ScaleFactLabel->setObjectName(QStringLiteral("ScaleFactLabel"));
        ScaleFactLabel->setFont(font);

        horizontalLayout_3->addWidget(ScaleFactLabel);

        ScaleFactorLineEdit = new QLineEdit(scaleDialog);
        ScaleFactorLineEdit->setObjectName(QStringLiteral("ScaleFactorLineEdit"));
        sizePolicy1.setHeightForWidth(ScaleFactorLineEdit->sizePolicy().hasHeightForWidth());
        ScaleFactorLineEdit->setSizePolicy(sizePolicy1);
        ScaleFactorLineEdit->setMinimumSize(QSize(60, 16));
        ScaleFactorLineEdit->setMaximumSize(QSize(60, 22));
        ScaleFactorLineEdit->setFont(font);

        horizontalLayout_3->addWidget(ScaleFactorLineEdit);

        horizontalSpacer_4 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        ScalePushButton = new QPushButton(scaleDialog);
        ScalePushButton->setObjectName(QStringLiteral("ScalePushButton"));
        ScalePushButton->setFont(font);

        horizontalLayout_4->addWidget(ScalePushButton);

        CancelPushButton = new QPushButton(scaleDialog);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));
        CancelPushButton->setFont(font);

        horizontalLayout_4->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);


        retranslateUi(scaleDialog);
        QObject::connect(CancelPushButton, SIGNAL(clicked()), scaleDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(scaleDialog);
    } // setupUi

    void retranslateUi(QDialog *scaleDialog)
    {
        scaleDialog->setWindowTitle(QApplication::translate("scaleDialog", "Scale", Q_NULLPTR));
        ScaleWRTPointLabel->setText(QApplication::translate("scaleDialog", "Scale Part with respect to Point:", Q_NULLPTR));
        XLabel->setText(QApplication::translate("scaleDialog", "X:", Q_NULLPTR));
        XLineEdit->setText(QApplication::translate("scaleDialog", "0.0", Q_NULLPTR));
        YLabel->setText(QApplication::translate("scaleDialog", "Y:", Q_NULLPTR));
        YLineEdit->setText(QApplication::translate("scaleDialog", "0.0", Q_NULLPTR));
        ZLabel->setText(QApplication::translate("scaleDialog", "Z:", Q_NULLPTR));
        ZLineEdit->setText(QApplication::translate("scaleDialog", "0.0", Q_NULLPTR));
        ScaleFactLabel->setText(QApplication::translate("scaleDialog", "Scale Factor:", Q_NULLPTR));
        ScaleFactorLineEdit->setText(QApplication::translate("scaleDialog", "2.0", Q_NULLPTR));
        ScalePushButton->setText(QApplication::translate("scaleDialog", "Scale", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("scaleDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class scaleDialog: public Ui_scaleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALEDIALOG_H
