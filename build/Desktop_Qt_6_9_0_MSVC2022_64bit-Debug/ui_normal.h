/********************************************************************************
** Form generated from reading UI file 'normal.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMAL_H
#define UI_NORMAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Normal
{
public:

    void setupUi(QWidget *Normal)
    {
        if (Normal->objectName().isEmpty())
            Normal->setObjectName("Normal");
        Normal->resize(800, 600);

        retranslateUi(Normal);

        QMetaObject::connectSlotsByName(Normal);
    } // setupUi

    void retranslateUi(QWidget *Normal)
    {
        Normal->setWindowTitle(QCoreApplication::translate("Normal", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Normal: public Ui_Normal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMAL_H
