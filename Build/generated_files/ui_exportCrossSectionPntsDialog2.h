/********************************************************************************
** Form generated from reading UI file 'exportCrossSectionPntsDialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTCROSSSECTIONPNTSDIALOG2_H
#define UI_EXPORTCROSSSECTIONPNTSDIALOG2_H

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

class Ui_exportCrossSectionPntsDialog2
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *directoryLineEdit;
    QPushButton *pickDirectoryButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *fileNameLineEdit;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *xBasePntLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *yBasePntLineEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QLineEdit *zBasePntLineEdit;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *xNormalDirLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_8;
    QLineEdit *yNormalDirLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_9;
    QLineEdit *zNormalDirLineEdit;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *xStartingPntLineEdit;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_11;
    QLineEdit *yStartingPntLineEdit;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_12;
    QLineEdit *zStartingPntLineEdit;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *distBetweenPntsSpinBox;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *exportButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *exportCrossSectionPntsDialog2)
    {
        if (exportCrossSectionPntsDialog2->objectName().isEmpty())
            exportCrossSectionPntsDialog2->setObjectName(QStringLiteral("exportCrossSectionPntsDialog2"));
        exportCrossSectionPntsDialog2->resize(740, 380);
        verticalLayout = new QVBoxLayout(exportCrossSectionPntsDialog2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(exportCrossSectionPntsDialog2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        directoryLineEdit = new QLineEdit(exportCrossSectionPntsDialog2);
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

        pickDirectoryButton = new QPushButton(exportCrossSectionPntsDialog2);
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
        label_2 = new QLabel(exportCrossSectionPntsDialog2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        fileNameLineEdit = new QLineEdit(exportCrossSectionPntsDialog2);
        fileNameLineEdit->setObjectName(QStringLiteral("fileNameLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fileNameLineEdit->sizePolicy().hasHeightForWidth());
        fileNameLineEdit->setSizePolicy(sizePolicy2);
        fileNameLineEdit->setFont(font);

        horizontalLayout_2->addWidget(fileNameLineEdit);

        horizontalSpacer_5 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        groupBox = new QGroupBox(exportCrossSectionPntsDialog2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        xBasePntLineEdit = new QLineEdit(groupBox);
        xBasePntLineEdit->setObjectName(QStringLiteral("xBasePntLineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(xBasePntLineEdit->sizePolicy().hasHeightForWidth());
        xBasePntLineEdit->setSizePolicy(sizePolicy3);
        xBasePntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(xBasePntLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        yBasePntLineEdit = new QLineEdit(groupBox);
        yBasePntLineEdit->setObjectName(QStringLiteral("yBasePntLineEdit"));
        sizePolicy3.setHeightForWidth(yBasePntLineEdit->sizePolicy().hasHeightForWidth());
        yBasePntLineEdit->setSizePolicy(sizePolicy3);
        yBasePntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(yBasePntLineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        zBasePntLineEdit = new QLineEdit(groupBox);
        zBasePntLineEdit->setObjectName(QStringLiteral("zBasePntLineEdit"));
        sizePolicy3.setHeightForWidth(zBasePntLineEdit->sizePolicy().hasHeightForWidth());
        zBasePntLineEdit->setSizePolicy(sizePolicy3);
        zBasePntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(zBasePntLineEdit);


        horizontalLayout_8->addWidget(groupBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        groupBox_2 = new QGroupBox(exportCrossSectionPntsDialog2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        horizontalLayout_6 = new QHBoxLayout(groupBox_2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        xNormalDirLineEdit = new QLineEdit(groupBox_2);
        xNormalDirLineEdit->setObjectName(QStringLiteral("xNormalDirLineEdit"));
        sizePolicy3.setHeightForWidth(xNormalDirLineEdit->sizePolicy().hasHeightForWidth());
        xNormalDirLineEdit->setSizePolicy(sizePolicy3);
        xNormalDirLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(xNormalDirLineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        yNormalDirLineEdit = new QLineEdit(groupBox_2);
        yNormalDirLineEdit->setObjectName(QStringLiteral("yNormalDirLineEdit"));
        sizePolicy3.setHeightForWidth(yNormalDirLineEdit->sizePolicy().hasHeightForWidth());
        yNormalDirLineEdit->setSizePolicy(sizePolicy3);
        yNormalDirLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(yNormalDirLineEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        zNormalDirLineEdit = new QLineEdit(groupBox_2);
        zNormalDirLineEdit->setObjectName(QStringLiteral("zNormalDirLineEdit"));
        sizePolicy3.setHeightForWidth(zNormalDirLineEdit->sizePolicy().hasHeightForWidth());
        zNormalDirLineEdit->setSizePolicy(sizePolicy3);
        zNormalDirLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(zNormalDirLineEdit);


        horizontalLayout_7->addWidget(groupBox_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        groupBox_3 = new QGroupBox(exportCrossSectionPntsDialog2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        horizontalLayout_9 = new QHBoxLayout(groupBox_3);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_9->addWidget(label_10);

        xStartingPntLineEdit = new QLineEdit(groupBox_3);
        xStartingPntLineEdit->setObjectName(QStringLiteral("xStartingPntLineEdit"));
        sizePolicy3.setHeightForWidth(xStartingPntLineEdit->sizePolicy().hasHeightForWidth());
        xStartingPntLineEdit->setSizePolicy(sizePolicy3);
        xStartingPntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_9->addWidget(xStartingPntLineEdit);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_10);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_9->addWidget(label_11);

        yStartingPntLineEdit = new QLineEdit(groupBox_3);
        yStartingPntLineEdit->setObjectName(QStringLiteral("yStartingPntLineEdit"));
        sizePolicy3.setHeightForWidth(yStartingPntLineEdit->sizePolicy().hasHeightForWidth());
        yStartingPntLineEdit->setSizePolicy(sizePolicy3);
        yStartingPntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_9->addWidget(yStartingPntLineEdit);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_9->addWidget(label_12);

        zStartingPntLineEdit = new QLineEdit(groupBox_3);
        zStartingPntLineEdit->setObjectName(QStringLiteral("zStartingPntLineEdit"));
        sizePolicy3.setHeightForWidth(zStartingPntLineEdit->sizePolicy().hasHeightForWidth());
        zStartingPntLineEdit->setSizePolicy(sizePolicy3);
        zStartingPntLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_9->addWidget(zStartingPntLineEdit);


        horizontalLayout_10->addWidget(groupBox_3);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_10);

        verticalSpacer_3 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(exportCrossSectionPntsDialog2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        distBetweenPntsSpinBox = new QDoubleSpinBox(exportCrossSectionPntsDialog2);
        distBetweenPntsSpinBox->setObjectName(QStringLiteral("distBetweenPntsSpinBox"));
        distBetweenPntsSpinBox->setFont(font);
        distBetweenPntsSpinBox->setMinimum(0.02);
        distBetweenPntsSpinBox->setMaximum(10);
        distBetweenPntsSpinBox->setSingleStep(0.5);
        distBetweenPntsSpinBox->setValue(1);

        horizontalLayout_4->addWidget(distBetweenPntsSpinBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        exportButton = new QPushButton(exportCrossSectionPntsDialog2);
        exportButton->setObjectName(QStringLiteral("exportButton"));
        exportButton->setFont(font);

        horizontalLayout_3->addWidget(exportButton);

        cancelButton = new QPushButton(exportCrossSectionPntsDialog2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(exportCrossSectionPntsDialog2);
        QObject::connect(cancelButton, SIGNAL(clicked()), exportCrossSectionPntsDialog2, SLOT(reject()));
        QObject::connect(exportButton, SIGNAL(clicked()), exportCrossSectionPntsDialog2, SLOT(accept()));

        QMetaObject::connectSlotsByName(exportCrossSectionPntsDialog2);
    } // setupUi

    void retranslateUi(QDialog *exportCrossSectionPntsDialog2)
    {
        exportCrossSectionPntsDialog2->setWindowTitle(QApplication::translate("exportCrossSectionPntsDialog2", "Export Discretized Cross Section as CSV", Q_NULLPTR));
        label->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Folder Directory:", Q_NULLPTR));
        pickDirectoryButton->setText(QApplication::translate("exportCrossSectionPntsDialog2", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("exportCrossSectionPntsDialog2", "File Name (.CSV):", Q_NULLPTR));
        fileNameLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "myCrossSection.csv", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("exportCrossSectionPntsDialog2", "Base Point of Intersecting Plane", Q_NULLPTR));
        label_4->setText(QApplication::translate("exportCrossSectionPntsDialog2", "X:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        xBasePntLineEdit->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        xBasePntLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "0.0", Q_NULLPTR));
        label_5->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Y:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        yBasePntLineEdit->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        yBasePntLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "0.0", Q_NULLPTR));
        label_6->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Z:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zBasePntLineEdit->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "Partially define a plane using a point that lies on the plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        zBasePntLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "0.0", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("exportCrossSectionPntsDialog2", "Normal Direction of Intersecting Plane", Q_NULLPTR));
        label_7->setText(QApplication::translate("exportCrossSectionPntsDialog2", "X:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        xNormalDirLineEdit->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "Partially define a plane with a vector representing the plane's normal direction", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        xNormalDirLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "0.0", Q_NULLPTR));
        label_8->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Y:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        yNormalDirLineEdit->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "Partially define a plane with a vector representing the plane's normal direction", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        yNormalDirLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "1.0", Q_NULLPTR));
        label_9->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Z:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zNormalDirLineEdit->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "Partially define a plane with a vector representing the plane's normal direction", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        zNormalDirLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "0.0", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("exportCrossSectionPntsDialog2", "Construction Point used to Order the Sequence of the Points", Q_NULLPTR));
        label_10->setText(QApplication::translate("exportCrossSectionPntsDialog2", "X:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        xStartingPntLineEdit->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "The closest point in the discretized intersection to this construction point will be used to start the sequence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        xStartingPntLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "1000.0", Q_NULLPTR));
        label_11->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Y:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        yStartingPntLineEdit->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "The closest point in the discretized intersection to this construction point will be used to start the sequence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        yStartingPntLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "0.0", Q_NULLPTR));
        label_12->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Z:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zStartingPntLineEdit->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "The closest point in the discretized intersection to this construction point will be used to start the sequence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        zStartingPntLineEdit->setText(QApplication::translate("exportCrossSectionPntsDialog2", "0.0", Q_NULLPTR));
        label_3->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Maximum Distance Between Points [mm]:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        distBetweenPntsSpinBox->setToolTip(QApplication::translate("exportCrossSectionPntsDialog2", "The distance between subsequent points along the intersection", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        exportButton->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Export", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("exportCrossSectionPntsDialog2", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class exportCrossSectionPntsDialog2: public Ui_exportCrossSectionPntsDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTCROSSSECTIONPNTSDIALOG2_H
