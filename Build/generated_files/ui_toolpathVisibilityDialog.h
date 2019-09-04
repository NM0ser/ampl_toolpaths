/********************************************************************************
** Form generated from reading UI file 'toolpathVisibilityDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLPATHVISIBILITYDIALOG_H
#define UI_TOOLPATHVISIBILITYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_toolpathVisibilityDialog2
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *topToolContactPntsRadio;
    QRadioButton *topToolContactLinesRadio;
    QRadioButton *topToolContactPntsLinesRadio;
    QComboBox *topToolContactPntsCombo;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *botToolContactPntsRadio;
    QRadioButton *botToolContactLinesRadio;
    QRadioButton *botToolContactPntsLinesRadio;
    QComboBox *botToolContactPntsCombo;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *showTopToolTipsModCheckBox;
    QRadioButton *topToolTipPntsRadio;
    QRadioButton *topToolTipLinesRadio;
    QRadioButton *topToolTipPntsLinesRadio;
    QComboBox *topToolTipPntsCombo;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *showBotToolTipsModCheckBox;
    QRadioButton *botToolTipPntsRadio;
    QRadioButton *botToolTipLinesRadio;
    QRadioButton *botToolTipPntsLinesRadio;
    QComboBox *botToolTipPntsCombo;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *hideAllPushButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *applyPushButton;
    QPushButton *closePushButton;

    void setupUi(QDialog *toolpathVisibilityDialog2)
    {
        if (toolpathVisibilityDialog2->objectName().isEmpty())
            toolpathVisibilityDialog2->setObjectName(QStringLiteral("toolpathVisibilityDialog2"));
        toolpathVisibilityDialog2->resize(387, 380);
        verticalLayout_5 = new QVBoxLayout(toolpathVisibilityDialog2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        groupBox = new QGroupBox(toolpathVisibilityDialog2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        topToolContactPntsRadio = new QRadioButton(groupBox);
        topToolContactPntsRadio->setObjectName(QStringLiteral("topToolContactPntsRadio"));
        topToolContactPntsRadio->setChecked(true);

        verticalLayout->addWidget(topToolContactPntsRadio);

        topToolContactLinesRadio = new QRadioButton(groupBox);
        topToolContactLinesRadio->setObjectName(QStringLiteral("topToolContactLinesRadio"));

        verticalLayout->addWidget(topToolContactLinesRadio);

        topToolContactPntsLinesRadio = new QRadioButton(groupBox);
        topToolContactPntsLinesRadio->setObjectName(QStringLiteral("topToolContactPntsLinesRadio"));

        verticalLayout->addWidget(topToolContactPntsLinesRadio);

        topToolContactPntsCombo = new QComboBox(groupBox);
        topToolContactPntsCombo->setObjectName(QStringLiteral("topToolContactPntsCombo"));
        topToolContactPntsCombo->setFont(font);

        verticalLayout->addWidget(topToolContactPntsCombo);


        horizontalLayout_2->addWidget(groupBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        groupBox_2 = new QGroupBox(toolpathVisibilityDialog2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        botToolContactPntsRadio = new QRadioButton(groupBox_2);
        botToolContactPntsRadio->setObjectName(QStringLiteral("botToolContactPntsRadio"));
        botToolContactPntsRadio->setChecked(true);

        verticalLayout_2->addWidget(botToolContactPntsRadio);

        botToolContactLinesRadio = new QRadioButton(groupBox_2);
        botToolContactLinesRadio->setObjectName(QStringLiteral("botToolContactLinesRadio"));

        verticalLayout_2->addWidget(botToolContactLinesRadio);

        botToolContactPntsLinesRadio = new QRadioButton(groupBox_2);
        botToolContactPntsLinesRadio->setObjectName(QStringLiteral("botToolContactPntsLinesRadio"));

        verticalLayout_2->addWidget(botToolContactPntsLinesRadio);

        botToolContactPntsCombo = new QComboBox(groupBox_2);
        botToolContactPntsCombo->setObjectName(QStringLiteral("botToolContactPntsCombo"));
        botToolContactPntsCombo->setFont(font);

        verticalLayout_2->addWidget(botToolContactPntsCombo);


        horizontalLayout_2->addWidget(groupBox_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox_3 = new QGroupBox(toolpathVisibilityDialog2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        showTopToolTipsModCheckBox = new QCheckBox(groupBox_3);
        showTopToolTipsModCheckBox->setObjectName(QStringLiteral("showTopToolTipsModCheckBox"));
        showTopToolTipsModCheckBox->setChecked(true);

        verticalLayout_3->addWidget(showTopToolTipsModCheckBox);

        topToolTipPntsRadio = new QRadioButton(groupBox_3);
        topToolTipPntsRadio->setObjectName(QStringLiteral("topToolTipPntsRadio"));

        verticalLayout_3->addWidget(topToolTipPntsRadio);

        topToolTipLinesRadio = new QRadioButton(groupBox_3);
        topToolTipLinesRadio->setObjectName(QStringLiteral("topToolTipLinesRadio"));
        topToolTipLinesRadio->setChecked(true);

        verticalLayout_3->addWidget(topToolTipLinesRadio);

        topToolTipPntsLinesRadio = new QRadioButton(groupBox_3);
        topToolTipPntsLinesRadio->setObjectName(QStringLiteral("topToolTipPntsLinesRadio"));

        verticalLayout_3->addWidget(topToolTipPntsLinesRadio);

        topToolTipPntsCombo = new QComboBox(groupBox_3);
        topToolTipPntsCombo->setObjectName(QStringLiteral("topToolTipPntsCombo"));
        topToolTipPntsCombo->setFont(font);

        verticalLayout_3->addWidget(topToolTipPntsCombo);


        horizontalLayout->addWidget(groupBox_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        groupBox_4 = new QGroupBox(toolpathVisibilityDialog2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font);
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        showBotToolTipsModCheckBox = new QCheckBox(groupBox_4);
        showBotToolTipsModCheckBox->setObjectName(QStringLiteral("showBotToolTipsModCheckBox"));
        showBotToolTipsModCheckBox->setChecked(true);

        verticalLayout_4->addWidget(showBotToolTipsModCheckBox);

        botToolTipPntsRadio = new QRadioButton(groupBox_4);
        botToolTipPntsRadio->setObjectName(QStringLiteral("botToolTipPntsRadio"));

        verticalLayout_4->addWidget(botToolTipPntsRadio);

        botToolTipLinesRadio = new QRadioButton(groupBox_4);
        botToolTipLinesRadio->setObjectName(QStringLiteral("botToolTipLinesRadio"));
        botToolTipLinesRadio->setChecked(true);

        verticalLayout_4->addWidget(botToolTipLinesRadio);

        botToolTipPntsLinesRadio = new QRadioButton(groupBox_4);
        botToolTipPntsLinesRadio->setObjectName(QStringLiteral("botToolTipPntsLinesRadio"));

        verticalLayout_4->addWidget(botToolTipPntsLinesRadio);

        botToolTipPntsCombo = new QComboBox(groupBox_4);
        botToolTipPntsCombo->setObjectName(QStringLiteral("botToolTipPntsCombo"));
        botToolTipPntsCombo->setFont(font);

        verticalLayout_4->addWidget(botToolTipPntsCombo);


        horizontalLayout->addWidget(groupBox_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        hideAllPushButton = new QPushButton(toolpathVisibilityDialog2);
        hideAllPushButton->setObjectName(QStringLiteral("hideAllPushButton"));
        hideAllPushButton->setFont(font);

        horizontalLayout_3->addWidget(hideAllPushButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        applyPushButton = new QPushButton(toolpathVisibilityDialog2);
        applyPushButton->setObjectName(QStringLiteral("applyPushButton"));
        applyPushButton->setFont(font);

        horizontalLayout_3->addWidget(applyPushButton);

        closePushButton = new QPushButton(toolpathVisibilityDialog2);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setFont(font);

        horizontalLayout_3->addWidget(closePushButton);


        verticalLayout_5->addLayout(horizontalLayout_3);


        retranslateUi(toolpathVisibilityDialog2);
        QObject::connect(closePushButton, SIGNAL(clicked()), toolpathVisibilityDialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(toolpathVisibilityDialog2);
    } // setupUi

    void retranslateUi(QDialog *toolpathVisibilityDialog2)
    {
        toolpathVisibilityDialog2->setWindowTitle(QApplication::translate("toolpathVisibilityDialog2", "Change Toolpath Visibility", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("toolpathVisibilityDialog2", "Top Tool Contact Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        topToolContactPntsRadio->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        topToolContactPntsRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        topToolContactLinesRadio->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using line segments", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        topToolContactLinesRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Lines", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        topToolContactPntsLinesRadio->setStatusTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using points and line segments", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        topToolContactPntsLinesRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Points and Lines", Q_NULLPTR));
        topToolContactPntsCombo->clear();
        topToolContactPntsCombo->insertItems(0, QStringList()
         << QApplication::translate("toolpathVisibilityDialog2", "None", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Red", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Green", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Blue", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Magenta", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Cyan", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Yellow", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Purple", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Orange", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Black", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "White", Q_NULLPTR)
        );
        topToolContactPntsCombo->setCurrentText(QApplication::translate("toolpathVisibilityDialog2", "None", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("toolpathVisibilityDialog2", "Bottom Tool Contact Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        botToolContactPntsRadio->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        botToolContactPntsRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        botToolContactLinesRadio->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using line segments", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        botToolContactLinesRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Lines", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        botToolContactPntsLinesRadio->setStatusTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using points and line segments", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        botToolContactPntsLinesRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Points and Lines", Q_NULLPTR));
        botToolContactPntsCombo->clear();
        botToolContactPntsCombo->insertItems(0, QStringList()
         << QApplication::translate("toolpathVisibilityDialog2", "None", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Red", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Green", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Blue", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Magenta", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Cyan", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Yellow", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Purple", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Orange", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Black", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "White", Q_NULLPTR)
        );
        botToolContactPntsCombo->setCurrentText(QApplication::translate("toolpathVisibilityDialog2", "None", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("toolpathVisibilityDialog2", "Top Tool Tip Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        showTopToolTipsModCheckBox->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "If a modified toolpath has been generated, show it instead of the original tool tip toolpath", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        showTopToolTipsModCheckBox->setStatusTip(QApplication::translate("toolpathVisibilityDialog2", "If a modified toolpath has been generated, show it instead of the original tool tip toolpath", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        showTopToolTipsModCheckBox->setText(QApplication::translate("toolpathVisibilityDialog2", "Show Modified Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        topToolTipPntsRadio->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        topToolTipPntsRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        topToolTipLinesRadio->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using line segments", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        topToolTipLinesRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Lines", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        topToolTipPntsLinesRadio->setStatusTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using points and line segments", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        topToolTipPntsLinesRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Points and Lines", Q_NULLPTR));
        topToolTipPntsCombo->clear();
        topToolTipPntsCombo->insertItems(0, QStringList()
         << QApplication::translate("toolpathVisibilityDialog2", "None", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Red", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Green", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Blue", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Magenta", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Cyan", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Yellow", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Purple", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Orange", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Black", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "White", Q_NULLPTR)
        );
        topToolTipPntsCombo->setCurrentText(QApplication::translate("toolpathVisibilityDialog2", "None", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("toolpathVisibilityDialog2", "Bottom Tool Tip Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        showBotToolTipsModCheckBox->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "If a modified toolpath has been generated, show it instead of the original tool tip toolpath", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        showBotToolTipsModCheckBox->setStatusTip(QApplication::translate("toolpathVisibilityDialog2", "If a modified toolpath has been generated, show it instead of the original tool tip toolpath", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        showBotToolTipsModCheckBox->setText(QApplication::translate("toolpathVisibilityDialog2", "Show Modified Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        botToolTipPntsRadio->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        botToolTipPntsRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        botToolTipLinesRadio->setToolTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using line segments", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        botToolTipLinesRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Lines", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        botToolTipPntsLinesRadio->setStatusTip(QApplication::translate("toolpathVisibilityDialog2", "Visualize using points and line segments", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        botToolTipPntsLinesRadio->setText(QApplication::translate("toolpathVisibilityDialog2", "Points and Lines", Q_NULLPTR));
        botToolTipPntsCombo->clear();
        botToolTipPntsCombo->insertItems(0, QStringList()
         << QApplication::translate("toolpathVisibilityDialog2", "None", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Red", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Green", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Blue", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Magenta", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Cyan", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Yellow", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Purple", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Orange", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "Black", Q_NULLPTR)
         << QApplication::translate("toolpathVisibilityDialog2", "White", Q_NULLPTR)
        );
        botToolTipPntsCombo->setCurrentText(QApplication::translate("toolpathVisibilityDialog2", "None", Q_NULLPTR));
        hideAllPushButton->setText(QApplication::translate("toolpathVisibilityDialog2", "Hide All", Q_NULLPTR));
        applyPushButton->setText(QApplication::translate("toolpathVisibilityDialog2", "Apply", Q_NULLPTR));
        closePushButton->setText(QApplication::translate("toolpathVisibilityDialog2", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class toolpathVisibilityDialog2: public Ui_toolpathVisibilityDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLPATHVISIBILITYDIALOG_H
