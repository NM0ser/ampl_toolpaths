/********************************************************************************
** Form generated from reading UI file 'exportIGSDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTIGSDIALOG_H
#define UI_EXPORTIGSDIALOG_H

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

class Ui_exportIGSDialog
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
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *exportButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *exportIGSDialog)
    {
        if (exportIGSDialog->objectName().isEmpty())
            exportIGSDialog->setObjectName(QStringLiteral("exportIGSDialog"));
        exportIGSDialog->resize(601, 115);
        verticalLayout = new QVBoxLayout(exportIGSDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(exportIGSDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        directoryLineEdit = new QLineEdit(exportIGSDialog);
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

        pickDirectoryButton = new QPushButton(exportIGSDialog);
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
        label_2 = new QLabel(exportIGSDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        fileNameLineEdit = new QLineEdit(exportIGSDialog);
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        exportButton = new QPushButton(exportIGSDialog);
        exportButton->setObjectName(QStringLiteral("exportButton"));
        exportButton->setFont(font);

        horizontalLayout_3->addWidget(exportButton);

        cancelButton = new QPushButton(exportIGSDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(exportIGSDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), exportIGSDialog, SLOT(reject()));
        QObject::connect(exportButton, SIGNAL(clicked()), exportIGSDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(exportIGSDialog);
    } // setupUi

    void retranslateUi(QDialog *exportIGSDialog)
    {
        exportIGSDialog->setWindowTitle(QApplication::translate("exportIGSDialog", "Export as IGS", Q_NULLPTR));
        label->setText(QApplication::translate("exportIGSDialog", "Folder Directory:", Q_NULLPTR));
        pickDirectoryButton->setText(QApplication::translate("exportIGSDialog", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("exportIGSDialog", "File Name:", Q_NULLPTR));
        fileNameLineEdit->setText(QApplication::translate("exportIGSDialog", "myPart.IGS", Q_NULLPTR));
        exportButton->setText(QApplication::translate("exportIGSDialog", "Export", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("exportIGSDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class exportIGSDialog: public Ui_exportIGSDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTIGSDIALOG_H
