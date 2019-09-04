/********************************************************************************
** Form generated from reading UI file 'importIGSDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTIGSDIALOG_H
#define UI_IMPORTIGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_importIGSDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *filePathLineEdit;
    QPushButton *pickDirectoryButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *sewingTolLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *importButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *importIGSDialog)
    {
        if (importIGSDialog->objectName().isEmpty())
            importIGSDialog->setObjectName(QStringLiteral("importIGSDialog"));
        importIGSDialog->resize(604, 143);
        verticalLayout = new QVBoxLayout(importIGSDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(importIGSDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        filePathLineEdit = new QLineEdit(importIGSDialog);
        filePathLineEdit->setObjectName(QStringLiteral("filePathLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filePathLineEdit->sizePolicy().hasHeightForWidth());
        filePathLineEdit->setSizePolicy(sizePolicy);
        filePathLineEdit->setMinimumSize(QSize(150, 0));
        filePathLineEdit->setFont(font);
        filePathLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(filePathLineEdit);

        pickDirectoryButton = new QPushButton(importIGSDialog);
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
        label_2 = new QLabel(importIGSDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        sewingTolLineEdit = new QLineEdit(importIGSDialog);
        sewingTolLineEdit->setObjectName(QStringLiteral("sewingTolLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sewingTolLineEdit->sizePolicy().hasHeightForWidth());
        sewingTolLineEdit->setSizePolicy(sizePolicy2);
        sewingTolLineEdit->setMinimumSize(QSize(100, 0));
        sewingTolLineEdit->setFont(font);
        sewingTolLineEdit->setReadOnly(false);

        horizontalLayout_2->addWidget(sewingTolLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox = new QCheckBox(importIGSDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);
        checkBox->setChecked(true);

        horizontalLayout_3->addWidget(checkBox);

        horizontalSpacer_4 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        importButton = new QPushButton(importIGSDialog);
        importButton->setObjectName(QStringLiteral("importButton"));
        importButton->setFont(font);

        horizontalLayout_4->addWidget(importButton);

        cancelButton = new QPushButton(importIGSDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_4->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(importIGSDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), importIGSDialog, SLOT(reject()));
        QObject::connect(importButton, SIGNAL(clicked()), importIGSDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(importIGSDialog);
    } // setupUi

    void retranslateUi(QDialog *importIGSDialog)
    {
        importIGSDialog->setWindowTitle(QApplication::translate("importIGSDialog", "Import IGS", Q_NULLPTR));
        label->setText(QApplication::translate("importIGSDialog", "File Path:", Q_NULLPTR));
        pickDirectoryButton->setText(QApplication::translate("importIGSDialog", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("importIGSDialog", "Surface Sewing Tolerance:", Q_NULLPTR));
        sewingTolLineEdit->setText(QApplication::translate("importIGSDialog", "0.01", Q_NULLPTR));
        checkBox->setText(QApplication::translate("importIGSDialog", "Perform Shape Healing", Q_NULLPTR));
        importButton->setText(QApplication::translate("importIGSDialog", "Import", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("importIGSDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class importIGSDialog: public Ui_importIGSDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTIGSDIALOG_H
