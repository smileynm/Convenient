/********************************************************************************
** Form generated from reading UI file 'adminorderlistform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINORDERLISTFORM_H
#define UI_ADMINORDERLISTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminOrderListForm
{
public:
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;

    void setupUi(QWidget *AdminOrderListForm)
    {
        if (AdminOrderListForm->objectName().isEmpty())
            AdminOrderListForm->setObjectName("AdminOrderListForm");
        AdminOrderListForm->resize(800, 600);
        tableWidget = new QTableWidget(AdminOrderListForm);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 10, 600, 460));
        tableWidget_2 = new QTableWidget(AdminOrderListForm);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(620, 10, 170, 460));

        retranslateUi(AdminOrderListForm);

        QMetaObject::connectSlotsByName(AdminOrderListForm);
    } // setupUi

    void retranslateUi(QWidget *AdminOrderListForm)
    {
        AdminOrderListForm->setWindowTitle(QCoreApplication::translate("AdminOrderListForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminOrderListForm: public Ui_AdminOrderListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINORDERLISTFORM_H
