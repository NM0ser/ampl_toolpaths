/********************************************************************************
** Form generated from reading UI file 'exportAmplToolpath.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTAMPLTOOLPATH_H
#define UI_EXPORTAMPLTOOLPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_exportAmplToolpathDialog2
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *directoryLineEdit;
    QPushButton *pickDirectoryButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *filePrefixLineEdit;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QCheckBox *topToolTipPointsCheckBox;
    QCheckBox *botToolTipPointsCheckBox;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *topContactPointsCheckBox;
    QCheckBox *botContactPointsCheckBox;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *normalVectorCheckBox;
    QCheckBox *genToolpathInfoCheckBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *writePushButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *exportAmplToolpathDialog2)
    {
        if (exportAmplToolpathDialog2->objectName().isEmpty())
            exportAmplToolpathDialog2->setObjectName(QStringLiteral("exportAmplToolpathDialog2"));
        exportAmplToolpathDialog2->resize(774, 384);
        verticalLayout_4 = new QVBoxLayout(exportAmplToolpathDialog2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(exportAmplToolpathDialog2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        directoryLineEdit = new QLineEdit(exportAmplToolpathDialog2);
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

        pickDirectoryButton = new QPushButton(exportAmplToolpathDialog2);
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


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(exportAmplToolpathDialog2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        filePrefixLineEdit = new QLineEdit(exportAmplToolpathDialog2);
        filePrefixLineEdit->setObjectName(QStringLiteral("filePrefixLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(filePrefixLineEdit->sizePolicy().hasHeightForWidth());
        filePrefixLineEdit->setSizePolicy(sizePolicy2);
        filePrefixLineEdit->setFont(font);

        horizontalLayout_2->addWidget(filePrefixLineEdit);

        horizontalSpacer_5 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);

        label_3 = new QLabel(exportAmplToolpathDialog2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_4->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        frame = new QFrame(exportAmplToolpathDialog2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        topToolTipPointsCheckBox = new QCheckBox(frame);
        topToolTipPointsCheckBox->setObjectName(QStringLiteral("topToolTipPointsCheckBox"));
        topToolTipPointsCheckBox->setChecked(true);

        verticalLayout->addWidget(topToolTipPointsCheckBox);

        botToolTipPointsCheckBox = new QCheckBox(frame);
        botToolTipPointsCheckBox->setObjectName(QStringLiteral("botToolTipPointsCheckBox"));
        botToolTipPointsCheckBox->setChecked(true);

        verticalLayout->addWidget(botToolTipPointsCheckBox);


        verticalLayout_4->addWidget(frame);

        frame_2 = new QFrame(exportAmplToolpathDialog2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFont(font);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        topContactPointsCheckBox = new QCheckBox(frame_2);
        topContactPointsCheckBox->setObjectName(QStringLiteral("topContactPointsCheckBox"));
        topContactPointsCheckBox->setChecked(true);

        verticalLayout_2->addWidget(topContactPointsCheckBox);

        botContactPointsCheckBox = new QCheckBox(frame_2);
        botContactPointsCheckBox->setObjectName(QStringLiteral("botContactPointsCheckBox"));
        botContactPointsCheckBox->setChecked(true);

        verticalLayout_2->addWidget(botContactPointsCheckBox);


        verticalLayout_4->addWidget(frame_2);

        frame_3 = new QFrame(exportAmplToolpathDialog2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFont(font);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        normalVectorCheckBox = new QCheckBox(frame_3);
        normalVectorCheckBox->setObjectName(QStringLiteral("normalVectorCheckBox"));
        normalVectorCheckBox->setChecked(true);

        verticalLayout_3->addWidget(normalVectorCheckBox);

        genToolpathInfoCheckBox = new QCheckBox(frame_3);
        genToolpathInfoCheckBox->setObjectName(QStringLiteral("genToolpathInfoCheckBox"));
        genToolpathInfoCheckBox->setChecked(true);

        verticalLayout_3->addWidget(genToolpathInfoCheckBox);


        verticalLayout_4->addWidget(frame_3);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        writePushButton = new QPushButton(exportAmplToolpathDialog2);
        writePushButton->setObjectName(QStringLiteral("writePushButton"));
        writePushButton->setFont(font);

        horizontalLayout_3->addWidget(writePushButton);

        cancelButton = new QPushButton(exportAmplToolpathDialog2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(exportAmplToolpathDialog2);
        QObject::connect(cancelButton, SIGNAL(clicked()), exportAmplToolpathDialog2, SLOT(reject()));
        QObject::connect(writePushButton, SIGNAL(clicked()), exportAmplToolpathDialog2, SLOT(accept()));

        QMetaObject::connectSlotsByName(exportAmplToolpathDialog2);
    } // setupUi

    void retranslateUi(QDialog *exportAmplToolpathDialog2)
    {
        exportAmplToolpathDialog2->setWindowTitle(QApplication::translate("exportAmplToolpathDialog2", "Export Toolpath to Text", Q_NULLPTR));
        label->setText(QApplication::translate("exportAmplToolpathDialog2", "Folder Directory:", Q_NULLPTR));
        pickDirectoryButton->setText(QApplication::translate("exportAmplToolpathDialog2", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("exportAmplToolpathDialog2", "Prefix for Exported Files:", Q_NULLPTR));
        filePrefixLineEdit->setText(QApplication::translate("exportAmplToolpathDialog2", "myToolpath", Q_NULLPTR));
        label_3->setText(QApplication::translate("exportAmplToolpathDialog2", "Choose What to Export (Options will be Ignored if not Available):", Q_NULLPTR));
        topToolTipPointsCheckBox->setText(QApplication::translate("exportAmplToolpathDialog2", "Export Top Tool-Tip Points", Q_NULLPTR));
        botToolTipPointsCheckBox->setText(QApplication::translate("exportAmplToolpathDialog2", "Export Bottom Tool-Tip Points", Q_NULLPTR));
        topContactPointsCheckBox->setText(QApplication::translate("exportAmplToolpathDialog2", "Export Top Tool Contact Points", Q_NULLPTR));
        botContactPointsCheckBox->setText(QApplication::translate("exportAmplToolpathDialog2", "Export Bottom Tool Contact Points", Q_NULLPTR));
        normalVectorCheckBox->setText(QApplication::translate("exportAmplToolpathDialog2", "Include the Local Surface Properties (Normal Vectors, Curvature, etc.) with the Contact Points", Q_NULLPTR));
        genToolpathInfoCheckBox->setText(QApplication::translate("exportAmplToolpathDialog2", "Export General Information About the Toolpath ", Q_NULLPTR));
        writePushButton->setText(QApplication::translate("exportAmplToolpathDialog2", "Write", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("exportAmplToolpathDialog2", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class exportAmplToolpathDialog2: public Ui_exportAmplToolpathDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTAMPLTOOLPATH_H
