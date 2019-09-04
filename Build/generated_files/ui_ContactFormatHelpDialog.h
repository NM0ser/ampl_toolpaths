/********************************************************************************
** Form generated from reading UI file 'ContactFormatHelpDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTFORMATHELPDIALOG_H
#define UI_CONTACTFORMATHELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ContactFormatHelpDialog2
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *ContactFormatHelpDialog2)
    {
        if (ContactFormatHelpDialog2->objectName().isEmpty())
            ContactFormatHelpDialog2->setObjectName(QStringLiteral("ContactFormatHelpDialog2"));
        ContactFormatHelpDialog2->resize(1069, 526);
        horizontalLayout = new QHBoxLayout(ContactFormatHelpDialog2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ContactFormatHelpDialog2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(ContactFormatHelpDialog2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/ToolpathHelpPics/ContactPnts_FormatHelp.png")));

        horizontalLayout->addWidget(label_2);


        retranslateUi(ContactFormatHelpDialog2);

        QMetaObject::connectSlotsByName(ContactFormatHelpDialog2);
    } // setupUi

    void retranslateUi(QDialog *ContactFormatHelpDialog2)
    {
        ContactFormatHelpDialog2->setWindowTitle(QApplication::translate("ContactFormatHelpDialog2", "Import Format", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContactFormatHelpDialog2: public Ui_ContactFormatHelpDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTFORMATHELPDIALOG_H
