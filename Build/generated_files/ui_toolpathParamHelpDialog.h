/********************************************************************************
** Form generated from reading UI file 'toolpathParamHelpDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLPATHPARAMHELPDIALOG_H
#define UI_TOOLPATHPARAMHELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_toolpathParamHelpDialog2
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QDialog *toolpathParamHelpDialog2)
    {
        if (toolpathParamHelpDialog2->objectName().isEmpty())
            toolpathParamHelpDialog2->setObjectName(QStringLiteral("toolpathParamHelpDialog2"));
        toolpathParamHelpDialog2->resize(991, 553);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolpathParamHelpDialog2->sizePolicy().hasHeightForWidth());
        toolpathParamHelpDialog2->setSizePolicy(sizePolicy);
        toolpathParamHelpDialog2->setMinimumSize(QSize(991, 553));
        toolpathParamHelpDialog2->setMaximumSize(QSize(991, 553));
        horizontalLayout = new QHBoxLayout(toolpathParamHelpDialog2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(toolpathParamHelpDialog2);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ToolpathHelpPics/toolpathParametersHelp.png")));
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);


        retranslateUi(toolpathParamHelpDialog2);

        QMetaObject::connectSlotsByName(toolpathParamHelpDialog2);
    } // setupUi

    void retranslateUi(QDialog *toolpathParamHelpDialog2)
    {
        toolpathParamHelpDialog2->setWindowTitle(QApplication::translate("toolpathParamHelpDialog2", "Toolpath Parameters Information", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class toolpathParamHelpDialog2: public Ui_toolpathParamHelpDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLPATHPARAMHELPDIALOG_H
