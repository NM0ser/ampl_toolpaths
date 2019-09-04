/********************************************************************************
** Form generated from reading UI file 'surfaceNormalHelpDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACENORMALHELPDIALOG_H
#define UI_SURFACENORMALHELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_surfaceNormalHelpDialog2
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QDialog *surfaceNormalHelpDialog2)
    {
        if (surfaceNormalHelpDialog2->objectName().isEmpty())
            surfaceNormalHelpDialog2->setObjectName(QStringLiteral("surfaceNormalHelpDialog2"));
        surfaceNormalHelpDialog2->resize(1298, 738);
        horizontalLayout = new QHBoxLayout(surfaceNormalHelpDialog2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(surfaceNormalHelpDialog2);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ToolpathHelpPics/ContactPnts_AssumedNormalDirectionHelp.png")));

        horizontalLayout->addWidget(label);


        retranslateUi(surfaceNormalHelpDialog2);

        QMetaObject::connectSlotsByName(surfaceNormalHelpDialog2);
    } // setupUi

    void retranslateUi(QDialog *surfaceNormalHelpDialog2)
    {
        surfaceNormalHelpDialog2->setWindowTitle(QApplication::translate("surfaceNormalHelpDialog2", "Expected Import Definitions", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class surfaceNormalHelpDialog2: public Ui_surfaceNormalHelpDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACENORMALHELPDIALOG_H
