/********************************************************************************
** Form generated from reading UI file 'translateDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATEDIALOG_H
#define UI_TRANSLATEDIALOG_H

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

class Ui_translateDialog
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *TranslateDirectionLabel;
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
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *TranslateDistanceLabel;
    QLineEdit *TranslateDistLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *TranslatePushButton;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *translateDialog)
    {
        if (translateDialog->objectName().isEmpty())
            translateDialog->setObjectName(QStringLiteral("translateDialog"));
        translateDialog->setWindowModality(Qt::NonModal);
        translateDialog->resize(300, 160);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(translateDialog->sizePolicy().hasHeightForWidth());
        translateDialog->setSizePolicy(sizePolicy);
        translateDialog->setModal(false);
        horizontalLayout_5 = new QHBoxLayout(translateDialog);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        TranslateDirectionLabel = new QLabel(translateDialog);
        TranslateDirectionLabel->setObjectName(QStringLiteral("TranslateDirectionLabel"));
        QFont font;
        font.setPointSize(10);
        TranslateDirectionLabel->setFont(font);

        horizontalLayout->addWidget(TranslateDirectionLabel);

        horizontalSpacer_3 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        XLabel = new QLabel(translateDialog);
        XLabel->setObjectName(QStringLiteral("XLabel"));
        XLabel->setFont(font);

        horizontalLayout_2->addWidget(XLabel);

        XLineEdit = new QLineEdit(translateDialog);
        XLineEdit->setObjectName(QStringLiteral("XLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
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

        YLabel = new QLabel(translateDialog);
        YLabel->setObjectName(QStringLiteral("YLabel"));
        YLabel->setFont(font);

        horizontalLayout_2->addWidget(YLabel);

        YLineEdit = new QLineEdit(translateDialog);
        YLineEdit->setObjectName(QStringLiteral("YLineEdit"));
        sizePolicy1.setHeightForWidth(YLineEdit->sizePolicy().hasHeightForWidth());
        YLineEdit->setSizePolicy(sizePolicy1);
        YLineEdit->setMinimumSize(QSize(60, 16));
        YLineEdit->setMaximumSize(QSize(60, 22));
        YLineEdit->setFont(font);

        horizontalLayout_2->addWidget(YLineEdit);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ZLabel = new QLabel(translateDialog);
        ZLabel->setObjectName(QStringLiteral("ZLabel"));
        ZLabel->setFont(font);

        horizontalLayout_2->addWidget(ZLabel);

        ZLineEdit = new QLineEdit(translateDialog);
        ZLineEdit->setObjectName(QStringLiteral("ZLineEdit"));
        sizePolicy1.setHeightForWidth(ZLineEdit->sizePolicy().hasHeightForWidth());
        ZLineEdit->setSizePolicy(sizePolicy1);
        ZLineEdit->setMinimumSize(QSize(60, 16));
        ZLineEdit->setMaximumSize(QSize(60, 22));
        ZLineEdit->setFont(font);

        horizontalLayout_2->addWidget(ZLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        TranslateDistanceLabel = new QLabel(translateDialog);
        TranslateDistanceLabel->setObjectName(QStringLiteral("TranslateDistanceLabel"));
        TranslateDistanceLabel->setFont(font);

        horizontalLayout_3->addWidget(TranslateDistanceLabel);

        TranslateDistLineEdit = new QLineEdit(translateDialog);
        TranslateDistLineEdit->setObjectName(QStringLiteral("TranslateDistLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TranslateDistLineEdit->sizePolicy().hasHeightForWidth());
        TranslateDistLineEdit->setSizePolicy(sizePolicy2);
        TranslateDistLineEdit->setMinimumSize(QSize(60, 16));
        TranslateDistLineEdit->setMaximumSize(QSize(60, 22));
        TranslateDistLineEdit->setFont(font);

        horizontalLayout_3->addWidget(TranslateDistLineEdit);

        horizontalSpacer_4 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        TranslatePushButton = new QPushButton(translateDialog);
        TranslatePushButton->setObjectName(QStringLiteral("TranslatePushButton"));
        TranslatePushButton->setFont(font);

        horizontalLayout_4->addWidget(TranslatePushButton);

        CancelPushButton = new QPushButton(translateDialog);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));
        CancelPushButton->setFont(font);

        horizontalLayout_4->addWidget(CancelPushButton);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);


        retranslateUi(translateDialog);
        QObject::connect(CancelPushButton, SIGNAL(clicked()), translateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(translateDialog);
    } // setupUi

    void retranslateUi(QDialog *translateDialog)
    {
        translateDialog->setWindowTitle(QApplication::translate("translateDialog", "Translate", Q_NULLPTR));
        TranslateDirectionLabel->setText(QApplication::translate("translateDialog", "Translate in Direction:", Q_NULLPTR));
        XLabel->setText(QApplication::translate("translateDialog", "X:", Q_NULLPTR));
        XLineEdit->setText(QApplication::translate("translateDialog", "1.0", Q_NULLPTR));
        YLabel->setText(QApplication::translate("translateDialog", "Y:", Q_NULLPTR));
        YLineEdit->setText(QApplication::translate("translateDialog", "1.0", Q_NULLPTR));
        ZLabel->setText(QApplication::translate("translateDialog", "Z:", Q_NULLPTR));
        ZLineEdit->setText(QApplication::translate("translateDialog", "1.0", Q_NULLPTR));
        TranslateDistanceLabel->setText(QApplication::translate("translateDialog", "Translation Distance:", Q_NULLPTR));
        TranslateDistLineEdit->setText(QApplication::translate("translateDialog", "10.0", Q_NULLPTR));
        TranslatePushButton->setText(QApplication::translate("translateDialog", "Translate", Q_NULLPTR));
        CancelPushButton->setText(QApplication::translate("translateDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class translateDialog: public Ui_translateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATEDIALOG_H
