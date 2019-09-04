/********************************************************************************
** Form generated from reading UI file 'incSheetFormingInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCSHEETFORMINGINFODIALOG_H
#define UI_INCSHEETFORMINGINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_incSheetFormingInfoDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *incSheetFormingInfoDialog)
    {
        if (incSheetFormingInfoDialog->objectName().isEmpty())
            incSheetFormingInfoDialog->setObjectName(QStringLiteral("incSheetFormingInfoDialog"));
        incSheetFormingInfoDialog->resize(982, 712);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(incSheetFormingInfoDialog->sizePolicy().hasHeightForWidth());
        incSheetFormingInfoDialog->setSizePolicy(sizePolicy);
        incSheetFormingInfoDialog->setMinimumSize(QSize(982, 712));
        incSheetFormingInfoDialog->setMaximumSize(QSize(982, 712));
        label = new QLabel(incSheetFormingInfoDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 964, 694));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8(":/ToolpathHelpPics/SPIF_vs_TPIF_vs_DSIF.png")));
        label->setScaledContents(false);

        retranslateUi(incSheetFormingInfoDialog);

        QMetaObject::connectSlotsByName(incSheetFormingInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *incSheetFormingInfoDialog)
    {
        incSheetFormingInfoDialog->setWindowTitle(QApplication::translate("incSheetFormingInfoDialog", "Incremental Sheet Forming Information", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class incSheetFormingInfoDialog: public Ui_incSheetFormingInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCSHEETFORMINGINFODIALOG_H
