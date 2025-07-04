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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Normal
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;

    void setupUi(QMainWindow *Normal)
    {
        if (Normal->objectName().isEmpty())
            Normal->setObjectName("Normal");
        Normal->resize(800, 600);
        centralwidget = new QWidget(Normal);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 800, 600));
        Normal->setCentralWidget(centralwidget);

        retranslateUi(Normal);

        QMetaObject::connectSlotsByName(Normal);
    } // setupUi

    void retranslateUi(QMainWindow *Normal)
    {
        Normal->setWindowTitle(QCoreApplication::translate("Normal", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Normal: public Ui_Normal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMAL_H
