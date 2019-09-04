/********************************************************************************
** Form generated from reading UI file 'openAmplToolpath.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENAMPLTOOLPATH_H
#define UI_OPENAMPLTOOLPATH_H

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

class Ui_openAmplToolpathDialog2
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *filePathLineEdit;
    QPushButton *pickDirectoryButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *openPushButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *openAmplToolpathDialog2)
    {
        if (openAmplToolpathDialog2->objectName().isEmpty())
            openAmplToolpathDialog2->setObjectName(QStringLiteral("openAmplToolpathDialog2"));
        openAmplToolpathDialog2->resize(604, 85);
        verticalLayout = new QVBoxLayout(openAmplToolpathDialog2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(openAmplToolpathDialog2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        filePathLineEdit = new QLineEdit(openAmplToolpathDialog2);
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

        pickDirectoryButton = new QPushButton(openAmplToolpathDialog2);
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

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        openPushButton = new QPushButton(openAmplToolpathDialog2);
        openPushButton->setObjectName(QStringLiteral("openPushButton"));
        openPushButton->setFont(font);

        horizontalLayout_4->addWidget(openPushButton);

        cancelButton = new QPushButton(openAmplToolpathDialog2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_4->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(openAmplToolpathDialog2);
        QObject::connect(cancelButton, SIGNAL(clicked()), openAmplToolpathDialog2, SLOT(reject()));
        QObject::connect(openPushButton, SIGNAL(clicked()), openAmplToolpathDialog2, SLOT(accept()));

        QMetaObject::connectSlotsByName(openAmplToolpathDialog2);
    } // setupUi

    void retranslateUi(QDialog *openAmplToolpathDialog2)
    {
        openAmplToolpathDialog2->setWindowTitle(QApplication::translate("openAmplToolpathDialog2", "Open Toolpath", Q_NULLPTR));
        label->setText(QApplication::translate("openAmplToolpathDialog2", "File Path:", Q_NULLPTR));
        pickDirectoryButton->setText(QApplication::translate("openAmplToolpathDialog2", "...", Q_NULLPTR));
        openPushButton->setText(QApplication::translate("openAmplToolpathDialog2", "Open", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("openAmplToolpathDialog2", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class openAmplToolpathDialog2: public Ui_openAmplToolpathDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENAMPLTOOLPATH_H
