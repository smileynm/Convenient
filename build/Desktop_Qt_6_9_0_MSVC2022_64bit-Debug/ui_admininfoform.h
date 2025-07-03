/********************************************************************************
** Form generated from reading UI file 'admininfoform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMININFOFORM_H
#define UI_ADMININFOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminInfoForm
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QTableWidget *reqWidget;
    QWidget *page_1;
    QTableWidget *membWidget;
    QToolBox *toolBox;
    QWidget *reqTool;
    QWidget *membTool;

    void setupUi(QWidget *AdminInfoForm)
    {
        if (AdminInfoForm->objectName().isEmpty())
            AdminInfoForm->setObjectName("AdminInfoForm");
        AdminInfoForm->resize(800, 600);
        stackedWidget = new QStackedWidget(AdminInfoForm);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 600, 460));
        page_0 = new QWidget();
        page_0->setObjectName("page_0");
        reqWidget = new QTableWidget(page_0);
        reqWidget->setObjectName("reqWidget");
        reqWidget->setGeometry(QRect(0, 0, 600, 460));
        stackedWidget->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        membWidget = new QTableWidget(page_1);
        membWidget->setObjectName("membWidget");
        membWidget->setGeometry(QRect(0, 0, 600, 460));
        stackedWidget->addWidget(page_1);
        toolBox = new QToolBox(AdminInfoForm);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(620, 10, 170, 460));
        reqTool = new QWidget();
        reqTool->setObjectName("reqTool");
        reqTool->setGeometry(QRect(0, 0, 170, 390));
        toolBox->addItem(reqTool, QString::fromUtf8("\352\260\200\354\236\205\354\232\224\354\262\255"));
        membTool = new QWidget();
        membTool->setObjectName("membTool");
        membTool->setGeometry(QRect(0, 0, 170, 390));
        toolBox->addItem(membTool, QString::fromUtf8("\353\251\244\353\262\204\353\252\251\353\241\235"));

        retranslateUi(AdminInfoForm);

        stackedWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AdminInfoForm);
    } // setupUi

    void retranslateUi(QWidget *AdminInfoForm)
    {
        AdminInfoForm->setWindowTitle(QCoreApplication::translate("AdminInfoForm", "Form", nullptr));
        toolBox->setItemText(toolBox->indexOf(reqTool), QCoreApplication::translate("AdminInfoForm", "\352\260\200\354\236\205\354\232\224\354\262\255", nullptr));
        toolBox->setItemText(toolBox->indexOf(membTool), QCoreApplication::translate("AdminInfoForm", "\353\251\244\353\262\204\353\252\251\353\241\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminInfoForm: public Ui_AdminInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMININFOFORM_H
