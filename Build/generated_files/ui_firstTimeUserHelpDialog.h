/********************************************************************************
** Form generated from reading UI file 'firstTimeUserHelpDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTTIMEUSERHELPDIALOG_H
#define UI_FIRSTTIMEUSERHELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_firstTimeUserHelpDialog2
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QDialog *firstTimeUserHelpDialog2)
    {
        if (firstTimeUserHelpDialog2->objectName().isEmpty())
            firstTimeUserHelpDialog2->setObjectName(QStringLiteral("firstTimeUserHelpDialog2"));
        firstTimeUserHelpDialog2->resize(1255, 718);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(firstTimeUserHelpDialog2->sizePolicy().hasHeightForWidth());
        firstTimeUserHelpDialog2->setSizePolicy(sizePolicy);
        firstTimeUserHelpDialog2->setMinimumSize(QSize(1255, 718));
        firstTimeUserHelpDialog2->setMaximumSize(QSize(1255, 718));
        horizontalLayout = new QHBoxLayout(firstTimeUserHelpDialog2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(firstTimeUserHelpDialog2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8(":/ToolpathHelpPics/FirstTimeUserHelp.png")));
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);


        retranslateUi(firstTimeUserHelpDialog2);

        QMetaObject::connectSlotsByName(firstTimeUserHelpDialog2);
    } // setupUi

    void retranslateUi(QDialog *firstTimeUserHelpDialog2)
    {
        firstTimeUserHelpDialog2->setWindowTitle(QApplication::translate("firstTimeUserHelpDialog2", "One-Stage Single-Feature Toolpath Overview", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class firstTimeUserHelpDialog2: public Ui_firstTimeUserHelpDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTTIMEUSERHELPDIALOG_H
