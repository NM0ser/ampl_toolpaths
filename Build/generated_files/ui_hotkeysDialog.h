/********************************************************************************
** Form generated from reading UI file 'hotkeysDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTKEYSDIALOG_H
#define UI_HOTKEYSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_hotkeysDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *mousePanImageLabel;
    QSpacerItem *horizontalSpacer_5;
    QLabel *or1Label;
    QSpacerItem *horizontalSpacer_6;
    QLabel *keyPanImageLabel;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *mouseZoomImageLabel;
    QSpacerItem *horizontalSpacer_7;
    QLabel *or2Label;
    QSpacerItem *horizontalSpacer_8;
    QLabel *keyZoomImageLabel;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *mouseRotateImageLabel;
    QSpacerItem *horizontalSpacer_9;
    QLabel *or3Label;
    QSpacerItem *horizontalSpacer_10;
    QLabel *keyRotateImageLabel;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *keyChangeRotAxisImageLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *closePushButton;

    void setupUi(QDialog *hotkeysDialog)
    {
        if (hotkeysDialog->objectName().isEmpty())
            hotkeysDialog->setObjectName(QStringLiteral("hotkeysDialog"));
        hotkeysDialog->resize(512, 648);
        hotkeysDialog->setWindowOpacity(1);
        hotkeysDialog->setAutoFillBackground(false);
        hotkeysDialog->setModal(false);
        verticalLayout = new QVBoxLayout(hotkeysDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(hotkeysDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mousePanImageLabel = new QLabel(groupBox);
        mousePanImageLabel->setObjectName(QStringLiteral("mousePanImageLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mousePanImageLabel->sizePolicy().hasHeightForWidth());
        mousePanImageLabel->setSizePolicy(sizePolicy);
        mousePanImageLabel->setMinimumSize(QSize(100, 100));
        mousePanImageLabel->setMaximumSize(QSize(100, 100));
        QFont font1;
        font1.setPointSize(10);
        mousePanImageLabel->setFont(font1);
        mousePanImageLabel->setAutoFillBackground(false);
        mousePanImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/QtOcct/mouseKeyPan_200x200.png")));
        mousePanImageLabel->setScaledContents(true);

        horizontalLayout->addWidget(mousePanImageLabel);

        horizontalSpacer_5 = new QSpacerItem(30, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        or1Label = new QLabel(groupBox);
        or1Label->setObjectName(QStringLiteral("or1Label"));
        or1Label->setFont(font);

        horizontalLayout->addWidget(or1Label);

        horizontalSpacer_6 = new QSpacerItem(30, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        keyPanImageLabel = new QLabel(groupBox);
        keyPanImageLabel->setObjectName(QStringLiteral("keyPanImageLabel"));
        sizePolicy.setHeightForWidth(keyPanImageLabel->sizePolicy().hasHeightForWidth());
        keyPanImageLabel->setSizePolicy(sizePolicy);
        keyPanImageLabel->setMinimumSize(QSize(240, 80));
        keyPanImageLabel->setMaximumSize(QSize(240, 80));
        keyPanImageLabel->setFont(font1);
        keyPanImageLabel->setAutoFillBackground(false);
        keyPanImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/QtOcct/keyboardPan_300x100.png")));
        keyPanImageLabel->setScaledContents(true);

        horizontalLayout->addWidget(keyPanImageLabel);


        verticalLayout->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        groupBox_2 = new QGroupBox(hotkeysDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        mouseZoomImageLabel = new QLabel(groupBox_2);
        mouseZoomImageLabel->setObjectName(QStringLiteral("mouseZoomImageLabel"));
        sizePolicy.setHeightForWidth(mouseZoomImageLabel->sizePolicy().hasHeightForWidth());
        mouseZoomImageLabel->setSizePolicy(sizePolicy);
        mouseZoomImageLabel->setMinimumSize(QSize(100, 100));
        mouseZoomImageLabel->setMaximumSize(QSize(100, 100));
        mouseZoomImageLabel->setFont(font1);
        mouseZoomImageLabel->setAutoFillBackground(false);
        mouseZoomImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/QtOcct/mouseKeyZoom_200x200.png")));
        mouseZoomImageLabel->setScaledContents(true);

        horizontalLayout_2->addWidget(mouseZoomImageLabel);

        horizontalSpacer_7 = new QSpacerItem(30, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        or2Label = new QLabel(groupBox_2);
        or2Label->setObjectName(QStringLiteral("or2Label"));
        or2Label->setFont(font);

        horizontalLayout_2->addWidget(or2Label);

        horizontalSpacer_8 = new QSpacerItem(30, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        keyZoomImageLabel = new QLabel(groupBox_2);
        keyZoomImageLabel->setObjectName(QStringLiteral("keyZoomImageLabel"));
        sizePolicy.setHeightForWidth(keyZoomImageLabel->sizePolicy().hasHeightForWidth());
        keyZoomImageLabel->setSizePolicy(sizePolicy);
        keyZoomImageLabel->setMinimumSize(QSize(240, 80));
        keyZoomImageLabel->setMaximumSize(QSize(240, 80));
        keyZoomImageLabel->setFont(font1);
        keyZoomImageLabel->setAutoFillBackground(false);
        keyZoomImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/QtOcct/keyboardZoom_300x100.png")));
        keyZoomImageLabel->setScaledContents(true);

        horizontalLayout_2->addWidget(keyZoomImageLabel);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        groupBox_3 = new QGroupBox(hotkeysDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        mouseRotateImageLabel = new QLabel(groupBox_3);
        mouseRotateImageLabel->setObjectName(QStringLiteral("mouseRotateImageLabel"));
        sizePolicy.setHeightForWidth(mouseRotateImageLabel->sizePolicy().hasHeightForWidth());
        mouseRotateImageLabel->setSizePolicy(sizePolicy);
        mouseRotateImageLabel->setMinimumSize(QSize(100, 100));
        mouseRotateImageLabel->setMaximumSize(QSize(100, 100));
        mouseRotateImageLabel->setFont(font1);
        mouseRotateImageLabel->setAutoFillBackground(false);
        mouseRotateImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/QtOcct/mouseKeyRotate_200x200.png")));
        mouseRotateImageLabel->setScaledContents(true);

        horizontalLayout_3->addWidget(mouseRotateImageLabel);

        horizontalSpacer_9 = new QSpacerItem(30, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        or3Label = new QLabel(groupBox_3);
        or3Label->setObjectName(QStringLiteral("or3Label"));
        or3Label->setFont(font);

        horizontalLayout_3->addWidget(or3Label);

        horizontalSpacer_10 = new QSpacerItem(30, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        keyRotateImageLabel = new QLabel(groupBox_3);
        keyRotateImageLabel->setObjectName(QStringLiteral("keyRotateImageLabel"));
        sizePolicy.setHeightForWidth(keyRotateImageLabel->sizePolicy().hasHeightForWidth());
        keyRotateImageLabel->setSizePolicy(sizePolicy);
        keyRotateImageLabel->setMinimumSize(QSize(240, 80));
        keyRotateImageLabel->setMaximumSize(QSize(240, 80));
        keyRotateImageLabel->setFont(font1);
        keyRotateImageLabel->setAutoFillBackground(false);
        keyRotateImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/QtOcct/keyboardRotate_300x100.png")));
        keyRotateImageLabel->setScaledContents(true);

        horizontalLayout_3->addWidget(keyRotateImageLabel);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        groupBox_4 = new QGroupBox(hotkeysDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font);
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(315, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        keyChangeRotAxisImageLabel = new QLabel(groupBox_4);
        keyChangeRotAxisImageLabel->setObjectName(QStringLiteral("keyChangeRotAxisImageLabel"));
        sizePolicy.setHeightForWidth(keyChangeRotAxisImageLabel->sizePolicy().hasHeightForWidth());
        keyChangeRotAxisImageLabel->setSizePolicy(sizePolicy);
        keyChangeRotAxisImageLabel->setMinimumSize(QSize(240, 80));
        keyChangeRotAxisImageLabel->setMaximumSize(QSize(240, 80));
        keyChangeRotAxisImageLabel->setFont(font1);
        keyChangeRotAxisImageLabel->setAutoFillBackground(false);
        keyChangeRotAxisImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/QtOcct/keyboardChangeRotAxes_300x100.png")));
        keyChangeRotAxisImageLabel->setScaledContents(true);

        horizontalLayout_4->addWidget(keyChangeRotAxisImageLabel);


        verticalLayout->addWidget(groupBox_4);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_11 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        closePushButton = new QPushButton(hotkeysDialog);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setFont(font1);

        horizontalLayout_5->addWidget(closePushButton);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(hotkeysDialog);
        QObject::connect(closePushButton, SIGNAL(clicked()), hotkeysDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(hotkeysDialog);
    } // setupUi

    void retranslateUi(QDialog *hotkeysDialog)
    {
        hotkeysDialog->setWindowTitle(QApplication::translate("hotkeysDialog", "Hotkeys", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("hotkeysDialog", "Pan:", Q_NULLPTR));
        mousePanImageLabel->setText(QString());
        or1Label->setText(QApplication::translate("hotkeysDialog", "OR", Q_NULLPTR));
        keyPanImageLabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("hotkeysDialog", "Zoom:", Q_NULLPTR));
        mouseZoomImageLabel->setText(QString());
        or2Label->setText(QApplication::translate("hotkeysDialog", "OR", Q_NULLPTR));
        keyZoomImageLabel->setText(QString());
        groupBox_3->setTitle(QApplication::translate("hotkeysDialog", "Rotate:", Q_NULLPTR));
        mouseRotateImageLabel->setText(QString());
        or3Label->setText(QApplication::translate("hotkeysDialog", "OR", Q_NULLPTR));
        keyRotateImageLabel->setText(QString());
        groupBox_4->setTitle(QApplication::translate("hotkeysDialog", "Change Rotation Axis:", Q_NULLPTR));
        keyChangeRotAxisImageLabel->setText(QString());
        closePushButton->setText(QApplication::translate("hotkeysDialog", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class hotkeysDialog: public Ui_hotkeysDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTKEYSDIALOG_H
