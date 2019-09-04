/********************************************************************************
** Form generated from reading UI file 'saveAmplToolpath.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEAMPLTOOLPATH_H
#define UI_SAVEAMPLTOOLPATH_H

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

class Ui_saveAmplToolpathDialog2
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
    QPushButton *savePushButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *saveAmplToolpathDialog2)
    {
        if (saveAmplToolpathDialog2->objectName().isEmpty())
            saveAmplToolpathDialog2->setObjectName(QStringLiteral("saveAmplToolpathDialog2"));
        saveAmplToolpathDialog2->resize(601, 115);
        verticalLayout = new QVBoxLayout(saveAmplToolpathDialog2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(saveAmplToolpathDialog2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        directoryLineEdit = new QLineEdit(saveAmplToolpathDialog2);
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

        pickDirectoryButton = new QPushButton(saveAmplToolpathDialog2);
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
        label_2 = new QLabel(saveAmplToolpathDialog2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        fileNameLineEdit = new QLineEdit(saveAmplToolpathDialog2);
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

        savePushButton = new QPushButton(saveAmplToolpathDialog2);
        savePushButton->setObjectName(QStringLiteral("savePushButton"));
        savePushButton->setFont(font);

        horizontalLayout_3->addWidget(savePushButton);

        cancelButton = new QPushButton(saveAmplToolpathDialog2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(saveAmplToolpathDialog2);
        QObject::connect(cancelButton, SIGNAL(clicked()), saveAmplToolpathDialog2, SLOT(reject()));
        QObject::connect(savePushButton, SIGNAL(clicked()), saveAmplToolpathDialog2, SLOT(accept()));

        QMetaObject::connectSlotsByName(saveAmplToolpathDialog2);
    } // setupUi

    void retranslateUi(QDialog *saveAmplToolpathDialog2)
    {
        saveAmplToolpathDialog2->setWindowTitle(QApplication::translate("saveAmplToolpathDialog2", "Save Toolpath", Q_NULLPTR));
        label->setText(QApplication::translate("saveAmplToolpathDialog2", "Folder Directory:", Q_NULLPTR));
        pickDirectoryButton->setText(QApplication::translate("saveAmplToolpathDialog2", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("saveAmplToolpathDialog2", "File Name:", Q_NULLPTR));
        fileNameLineEdit->setText(QApplication::translate("saveAmplToolpathDialog2", "myToolpath.ampl", Q_NULLPTR));
        savePushButton->setText(QApplication::translate("saveAmplToolpathDialog2", "Save", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("saveAmplToolpathDialog2", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class saveAmplToolpathDialog2: public Ui_saveAmplToolpathDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEAMPLTOOLPATH_H
