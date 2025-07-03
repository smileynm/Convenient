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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Normal
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Normal)
    {
        if (Normal->objectName().isEmpty())
            Normal->setObjectName("Normal");
        Normal->resize(800, 600);
        centralwidget = new QWidget(Normal);
        centralwidget->setObjectName("centralwidget");
        Normal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Normal);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Normal->setMenuBar(menubar);
        statusbar = new QStatusBar(Normal);
        statusbar->setObjectName("statusbar");
        Normal->setStatusBar(statusbar);

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
