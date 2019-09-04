/********************************************************************************
** Form generated from reading UI file 'exportToolpathAsGen1MachineCodeDialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTTOOLPATHASGEN1MACHINECODEDIALOG2_H
#define UI_EXPORTTOOLPATHASGEN1MACHINECODEDIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_exportToGen1MachineCodeDialog2
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *directoryLineEdit;
    QPushButton *pickDirectoryButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *filePrefixLineEdit;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *maxNumLinesSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QDoubleSpinBox *feedRateSpinBox;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *topToolSafeHeightLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLineEdit *botToolSafeHeightLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *useModifiedTipPointsCheckBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *writePushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *exportToGen1MachineCodeDialog2)
    {
        if (exportToGen1MachineCodeDialog2->objectName().isEmpty())
            exportToGen1MachineCodeDialog2->setObjectName(QStringLiteral("exportToGen1MachineCodeDialog2"));
        exportToGen1MachineCodeDialog2->resize(743, 257);
        verticalLayout = new QVBoxLayout(exportToGen1MachineCodeDialog2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(exportToGen1MachineCodeDialog2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        directoryLineEdit = new QLineEdit(exportToGen1MachineCodeDialog2);
        directoryLineEdit->setObjectName(QStringLiteral("directoryLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(directoryLineEdit->sizePolicy().hasHeightForWidth());
        directoryLineEdit->setSizePolicy(sizePolicy);
        directoryLineEdit->setMinimumSize(QSize(100, 0));
        directoryLineEdit->setFont(font);
        directoryLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(directoryLineEdit);

        pickDirectoryButton = new QPushButton(exportToGen1MachineCodeDialog2);
        pickDirectoryButton->setObjectName(QStringLiteral("pickDirectoryButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pickDirectoryButton->sizePolicy().hasHeightForWidth());
        pickDirectoryButton->setSizePolicy(sizePolicy1);
        pickDirectoryButton->setMinimumSize(QSize(30, 15));
        pickDirectoryButton->setMaximumSize(QSize(30, 16777215));
        pickDirectoryButton->setFont(font);

        horizontalLayout->addWidget(pickDirectoryButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(exportToGen1MachineCodeDialog2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        filePrefixLineEdit = new QLineEdit(exportToGen1MachineCodeDialog2);
        filePrefixLineEdit->setObjectName(QStringLiteral("filePrefixLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(filePrefixLineEdit->sizePolicy().hasHeightForWidth());
        filePrefixLineEdit->setSizePolicy(sizePolicy2);
        filePrefixLineEdit->setFont(font);

        horizontalLayout_2->addWidget(filePrefixLineEdit);

        horizontalSpacer_5 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(exportToGen1MachineCodeDialog2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        maxNumLinesSpinBox = new QSpinBox(exportToGen1MachineCodeDialog2);
        maxNumLinesSpinBox->setObjectName(QStringLiteral("maxNumLinesSpinBox"));
        maxNumLinesSpinBox->setFont(font);
        maxNumLinesSpinBox->setMinimum(30);
        maxNumLinesSpinBox->setMaximum(1000000);
        maxNumLinesSpinBox->setSingleStep(100);
        maxNumLinesSpinBox->setValue(4000);

        horizontalLayout_3->addWidget(maxNumLinesSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_4 = new QLabel(exportToGen1MachineCodeDialog2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        feedRateSpinBox = new QDoubleSpinBox(exportToGen1MachineCodeDialog2);
        feedRateSpinBox->setObjectName(QStringLiteral("feedRateSpinBox"));
        feedRateSpinBox->setFont(font);
        feedRateSpinBox->setMinimum(0.1);
        feedRateSpinBox->setMaximum(100);
        feedRateSpinBox->setValue(5);

        horizontalLayout_3->addWidget(feedRateSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        groupBox = new QGroupBox(exportToGen1MachineCodeDialog2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        topToolSafeHeightLineEdit = new QLineEdit(groupBox);
        topToolSafeHeightLineEdit->setObjectName(QStringLiteral("topToolSafeHeightLineEdit"));

        horizontalLayout_6->addWidget(topToolSafeHeightLineEdit);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        botToolSafeHeightLineEdit = new QLineEdit(groupBox);
        botToolSafeHeightLineEdit->setObjectName(QStringLiteral("botToolSafeHeightLineEdit"));

        horizontalLayout_6->addWidget(botToolSafeHeightLineEdit);


        horizontalLayout_7->addWidget(groupBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_4 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        useModifiedTipPointsCheckBox = new QCheckBox(exportToGen1MachineCodeDialog2);
        useModifiedTipPointsCheckBox->setObjectName(QStringLiteral("useModifiedTipPointsCheckBox"));
        useModifiedTipPointsCheckBox->setFont(font);
        useModifiedTipPointsCheckBox->setChecked(true);

        horizontalLayout_4->addWidget(useModifiedTipPointsCheckBox);

        horizontalSpacer_4 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(408, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        writePushButton = new QPushButton(exportToGen1MachineCodeDialog2);
        writePushButton->setObjectName(QStringLiteral("writePushButton"));
        writePushButton->setFont(font);

        horizontalLayout_5->addWidget(writePushButton);

        cancelPushButton = new QPushButton(exportToGen1MachineCodeDialog2);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setFont(font);

        horizontalLayout_5->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(exportToGen1MachineCodeDialog2);
        QObject::connect(writePushButton, SIGNAL(clicked()), exportToGen1MachineCodeDialog2, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), exportToGen1MachineCodeDialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(exportToGen1MachineCodeDialog2);
    } // setupUi

    void retranslateUi(QDialog *exportToGen1MachineCodeDialog2)
    {
        exportToGen1MachineCodeDialog2->setWindowTitle(QApplication::translate("exportToGen1MachineCodeDialog2", "Export Tool Tips to NU's Gen. 1 DSIF Machine Code", Q_NULLPTR));
        label->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "Folder Directory:", Q_NULLPTR));
        pickDirectoryButton->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "File Prefix Name:", Q_NULLPTR));
        filePrefixLineEdit->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "myGen1Toolpath", Q_NULLPTR));
        label_3->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "Maximum Number of Lines per File:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        maxNumLinesSpinBox->setToolTip(QApplication::translate("exportToGen1MachineCodeDialog2", "A new file is created anytime the number of output points reaches the maximum number of lines. The Delta Tau Controller for the Gen. 1 DSIF Machine at NU usually has just enough memory for up to 4000 lines per file.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "Desired Feed Rate [mm/sec]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        feedRateSpinBox->setToolTip(QApplication::translate("exportToGen1MachineCodeDialog2", "Define the feed rate for the toolpath, noting that the Gen. 1 DSIF Machine at NU does not usually run past 5.0 mm/sec", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("exportToGen1MachineCodeDialog2", "Safe Z-Height (Absolute Coordinates) for the Tools", Q_NULLPTR));
        label_5->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "Top Tool [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        topToolSafeHeightLineEdit->setToolTip(QApplication::translate("exportToGen1MachineCodeDialog2", "At this height, the top tool should be able to move freely in the XY-plane without chance of intersecting the part", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        topToolSafeHeightLineEdit->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "100.0", Q_NULLPTR));
        label_6->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "Bottom Tool [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        botToolSafeHeightLineEdit->setToolTip(QApplication::translate("exportToGen1MachineCodeDialog2", "At this height, the bottom tool should be able to move freely in the XY-plane without chance of intersecting the part", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        botToolSafeHeightLineEdit->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "-100.0", Q_NULLPTR));
        useModifiedTipPointsCheckBox->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "Use Modified Tool-Tip Points if Available", Q_NULLPTR));
        writePushButton->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "Write", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("exportToGen1MachineCodeDialog2", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class exportToGen1MachineCodeDialog2: public Ui_exportToGen1MachineCodeDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTTOOLPATHASGEN1MACHINECODEDIALOG2_H
