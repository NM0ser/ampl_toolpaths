/********************************************************************************
** Form generated from reading UI file 'toolSheetMetalParamHelpDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSHEETMETALPARAMHELPDIALOG_H
#define UI_TOOLSHEETMETALPARAMHELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_toolSheetMetalParamHelpDialog2
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QDialog *toolSheetMetalParamHelpDialog2)
    {
        if (toolSheetMetalParamHelpDialog2->objectName().isEmpty())
            toolSheetMetalParamHelpDialog2->setObjectName(QStringLiteral("toolSheetMetalParamHelpDialog2"));
        toolSheetMetalParamHelpDialog2->resize(1053, 726);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolSheetMetalParamHelpDialog2->sizePolicy().hasHeightForWidth());
        toolSheetMetalParamHelpDialog2->setSizePolicy(sizePolicy);
        toolSheetMetalParamHelpDialog2->setMinimumSize(QSize(1053, 726));
        toolSheetMetalParamHelpDialog2->setMaximumSize(QSize(1053, 726));
        horizontalLayout = new QHBoxLayout(toolSheetMetalParamHelpDialog2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(toolSheetMetalParamHelpDialog2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8(":/ToolpathHelpPics/TopBotToolDefintionsHelp.png")));
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);


        retranslateUi(toolSheetMetalParamHelpDialog2);

        QMetaObject::connectSlotsByName(toolSheetMetalParamHelpDialog2);
    } // setupUi

    void retranslateUi(QDialog *toolSheetMetalParamHelpDialog2)
    {
        toolSheetMetalParamHelpDialog2->setWindowTitle(QApplication::translate("toolSheetMetalParamHelpDialog2", "Tooling Parameter Definitions", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class toolSheetMetalParamHelpDialog2: public Ui_toolSheetMetalParamHelpDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSHEETMETALPARAMHELPDIALOG_H
