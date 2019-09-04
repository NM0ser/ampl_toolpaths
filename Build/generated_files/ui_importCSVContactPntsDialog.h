/********************************************************************************
** Form generated from reading UI file 'importCSVContactPntsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTCSVCONTACTPNTSDIALOG_H
#define UI_IMPORTCSVCONTACTPNTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_importCSVContactPntsDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QPushButton *expectedCSVFormatButton;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QPushButton *surfNormalHelpButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *topContactFilePathLineEdit;
    QPushButton *topContactPickDirectoryButton;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *topSkipFirstLineCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *botContactFilePathLineEdit;
    QPushButton *botContactPickDirectoryButton;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *botSkipFirstLineCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *importCSVContactPntsDialog)
    {
        if (importCSVContactPntsDialog->objectName().isEmpty())
            importCSVContactPntsDialog->setObjectName(QStringLiteral("importCSVContactPntsDialog"));
        importCSVContactPntsDialog->resize(768, 399);
        verticalLayout_4 = new QVBoxLayout(importCSVContactPntsDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_4 = new QGroupBox(importCSVContactPntsDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QFont font;
        font.setPointSize(10);
        groupBox_4->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_9->addWidget(label_5);

        expectedCSVFormatButton = new QPushButton(groupBox_4);
        expectedCSVFormatButton->setObjectName(QStringLiteral("expectedCSVFormatButton"));
        expectedCSVFormatButton->setFont(font);

        horizontalLayout_9->addWidget(expectedCSVFormatButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_10->addWidget(label_6);

        surfNormalHelpButton = new QPushButton(groupBox_4);
        surfNormalHelpButton->setObjectName(QStringLiteral("surfNormalHelpButton"));
        surfNormalHelpButton->setFont(font);

        horizontalLayout_10->addWidget(surfNormalHelpButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_10);


        verticalLayout_4->addWidget(groupBox_4);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_2);

        groupBox = new QGroupBox(importCSVContactPntsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        topContactFilePathLineEdit = new QLineEdit(groupBox);
        topContactFilePathLineEdit->setObjectName(QStringLiteral("topContactFilePathLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topContactFilePathLineEdit->sizePolicy().hasHeightForWidth());
        topContactFilePathLineEdit->setSizePolicy(sizePolicy);
        topContactFilePathLineEdit->setMinimumSize(QSize(150, 0));
        topContactFilePathLineEdit->setFont(font);
        topContactFilePathLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(topContactFilePathLineEdit);

        topContactPickDirectoryButton = new QPushButton(groupBox);
        topContactPickDirectoryButton->setObjectName(QStringLiteral("topContactPickDirectoryButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topContactPickDirectoryButton->sizePolicy().hasHeightForWidth());
        topContactPickDirectoryButton->setSizePolicy(sizePolicy1);
        topContactPickDirectoryButton->setMinimumSize(QSize(30, 15));
        topContactPickDirectoryButton->setMaximumSize(QSize(30, 16777215));
        topContactPickDirectoryButton->setFont(font);

        horizontalLayout->addWidget(topContactPickDirectoryButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        topSkipFirstLineCheckBox = new QCheckBox(groupBox);
        topSkipFirstLineCheckBox->setObjectName(QStringLiteral("topSkipFirstLineCheckBox"));
        topSkipFirstLineCheckBox->setFont(font);
        topSkipFirstLineCheckBox->setChecked(true);

        horizontalLayout_5->addWidget(topSkipFirstLineCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(importCSVContactPntsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        botContactFilePathLineEdit = new QLineEdit(groupBox_2);
        botContactFilePathLineEdit->setObjectName(QStringLiteral("botContactFilePathLineEdit"));
        sizePolicy.setHeightForWidth(botContactFilePathLineEdit->sizePolicy().hasHeightForWidth());
        botContactFilePathLineEdit->setSizePolicy(sizePolicy);
        botContactFilePathLineEdit->setMinimumSize(QSize(150, 0));
        botContactFilePathLineEdit->setFont(font);
        botContactFilePathLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(botContactFilePathLineEdit);

        botContactPickDirectoryButton = new QPushButton(groupBox_2);
        botContactPickDirectoryButton->setObjectName(QStringLiteral("botContactPickDirectoryButton"));
        sizePolicy1.setHeightForWidth(botContactPickDirectoryButton->sizePolicy().hasHeightForWidth());
        botContactPickDirectoryButton->setSizePolicy(sizePolicy1);
        botContactPickDirectoryButton->setMinimumSize(QSize(30, 15));
        botContactPickDirectoryButton->setMaximumSize(QSize(30, 16777215));
        botContactPickDirectoryButton->setFont(font);

        horizontalLayout_2->addWidget(botContactPickDirectoryButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        botSkipFirstLineCheckBox = new QCheckBox(groupBox_2);
        botSkipFirstLineCheckBox->setObjectName(QStringLiteral("botSkipFirstLineCheckBox"));
        botSkipFirstLineCheckBox->setFont(font);
        botSkipFirstLineCheckBox->setChecked(true);

        horizontalLayout_4->addWidget(botSkipFirstLineCheckBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addWidget(groupBox_2);

        label_3 = new QLabel(importCSVContactPntsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setWordWrap(true);

        verticalLayout_4->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        nextButton = new QPushButton(importCSVContactPntsDialog);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setFont(font);

        horizontalLayout_3->addWidget(nextButton);

        cancelButton = new QPushButton(importCSVContactPntsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(importCSVContactPntsDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), importCSVContactPntsDialog, SLOT(reject()));
        QObject::connect(nextButton, SIGNAL(clicked()), importCSVContactPntsDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(importCSVContactPntsDialog);
    } // setupUi

    void retranslateUi(QDialog *importCSVContactPntsDialog)
    {
        importCSVContactPntsDialog->setWindowTitle(QApplication::translate("importCSVContactPntsDialog", "Import Contact Points", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("importCSVContactPntsDialog", "Information", Q_NULLPTR));
        label_5->setText(QApplication::translate("importCSVContactPntsDialog", "Expected Format:", Q_NULLPTR));
        expectedCSVFormatButton->setText(QApplication::translate("importCSVContactPntsDialog", "Help", Q_NULLPTR));
        label_6->setText(QApplication::translate("importCSVContactPntsDialog", "Expected Surface Normal Orientation:", Q_NULLPTR));
        surfNormalHelpButton->setText(QApplication::translate("importCSVContactPntsDialog", "Help", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("importCSVContactPntsDialog", "Top Contact Points and Local Surface Attributes (.csv)", Q_NULLPTR));
        label->setText(QApplication::translate("importCSVContactPntsDialog", "File Path:", Q_NULLPTR));
        topContactPickDirectoryButton->setText(QApplication::translate("importCSVContactPntsDialog", "...", Q_NULLPTR));
        topSkipFirstLineCheckBox->setText(QApplication::translate("importCSVContactPntsDialog", "Skip First Line", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("importCSVContactPntsDialog", "Bottom Contact Points and Local Surface Attributes (.csv)", Q_NULLPTR));
        label_2->setText(QApplication::translate("importCSVContactPntsDialog", "File Path:", Q_NULLPTR));
        botContactPickDirectoryButton->setText(QApplication::translate("importCSVContactPntsDialog", "...", Q_NULLPTR));
        botSkipFirstLineCheckBox->setText(QApplication::translate("importCSVContactPntsDialog", "Skip First Line", Q_NULLPTR));
        label_3->setText(QApplication::translate("importCSVContactPntsDialog", "The remaining toolpath information is gathered in the next window. Please take your time to choose ALL of the categories correctly, including any advanced features.", Q_NULLPTR));
        nextButton->setText(QApplication::translate("importCSVContactPntsDialog", "Next", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("importCSVContactPntsDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class importCSVContactPntsDialog: public Ui_importCSVContactPntsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTCSVCONTACTPNTSDIALOG_H
