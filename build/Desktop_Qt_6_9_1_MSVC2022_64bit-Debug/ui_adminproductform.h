/********************************************************************************
** Form generated from reading UI file 'adminproductform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPRODUCTFORM_H
#define UI_ADMINPRODUCTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminProductForm
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QTableWidget *beverageWidget;
    QWidget *page_1;
    QTableWidget *snackWidget;
    QWidget *page_2;
    QTableWidget *instantWidget;
    QWidget *page_3;
    QTableWidget *milkiceWidget;
    QWidget *page_4;
    QTableWidget *drinkWidget;
    QWidget *page_5;
    QTableWidget *neceWidget;
    QWidget *page_6;
    QTableWidget *allWidget;
    QToolBox *toolBox;
    QWidget *beveraageTool;
    QWidget *snackTool;
    QWidget *instantTool;
    QWidget *mikiceTool;
    QWidget *drinkTool;
    QWidget *neceTool;
    QWidget *allTool;

    void setupUi(QWidget *AdminProductForm)
    {
        if (AdminProductForm->objectName().isEmpty())
            AdminProductForm->setObjectName("AdminProductForm");
        AdminProductForm->resize(800, 600);
        stackedWidget = new QStackedWidget(AdminProductForm);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 600, 460));
        page_0 = new QWidget();
        page_0->setObjectName("page_0");
        beverageWidget = new QTableWidget(page_0);
        beverageWidget->setObjectName("beverageWidget");
        beverageWidget->setGeometry(QRect(0, 0, 600, 460));
        stackedWidget->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        snackWidget = new QTableWidget(page_1);
        snackWidget->setObjectName("snackWidget");
        snackWidget->setGeometry(QRect(0, 0, 600, 460));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        instantWidget = new QTableWidget(page_2);
        instantWidget->setObjectName("instantWidget");
        instantWidget->setGeometry(QRect(0, 0, 600, 460));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        milkiceWidget = new QTableWidget(page_3);
        milkiceWidget->setObjectName("milkiceWidget");
        milkiceWidget->setGeometry(QRect(0, 0, 600, 460));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        drinkWidget = new QTableWidget(page_4);
        drinkWidget->setObjectName("drinkWidget");
        drinkWidget->setGeometry(QRect(0, 0, 600, 460));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        neceWidget = new QTableWidget(page_5);
        neceWidget->setObjectName("neceWidget");
        neceWidget->setGeometry(QRect(0, 0, 600, 460));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        allWidget = new QTableWidget(page_6);
        allWidget->setObjectName("allWidget");
        allWidget->setGeometry(QRect(0, 0, 600, 460));
        stackedWidget->addWidget(page_6);
        toolBox = new QToolBox(AdminProductForm);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(620, 10, 170, 460));
        beveraageTool = new QWidget();
        beveraageTool->setObjectName("beveraageTool");
        beveraageTool->setGeometry(QRect(0, 0, 170, 208));
        toolBox->addItem(beveraageTool, QString::fromUtf8("\354\235\214\353\243\214"));
        snackTool = new QWidget();
        snackTool->setObjectName("snackTool");
        snackTool->setGeometry(QRect(0, 0, 170, 208));
        toolBox->addItem(snackTool, QString::fromUtf8("\354\212\244\353\202\265"));
        instantTool = new QWidget();
        instantTool->setObjectName("instantTool");
        instantTool->setGeometry(QRect(0, 0, 170, 208));
        toolBox->addItem(instantTool, QString::fromUtf8("\354\246\211\354\204\235\354\213\235\355\222\210"));
        mikiceTool = new QWidget();
        mikiceTool->setObjectName("mikiceTool");
        mikiceTool->setGeometry(QRect(0, 0, 170, 208));
        toolBox->addItem(mikiceTool, QString::fromUtf8("\354\234\240\354\240\234\355\222\210/\354\225\204\354\235\264\354\212\244\355\201\254\353\246\274"));
        drinkTool = new QWidget();
        drinkTool->setObjectName("drinkTool");
        drinkTool->setGeometry(QRect(0, 0, 170, 208));
        toolBox->addItem(drinkTool, QString::fromUtf8("\354\243\274\353\245\230"));
        neceTool = new QWidget();
        neceTool->setObjectName("neceTool");
        neceTool->setGeometry(QRect(0, 0, 170, 208));
        toolBox->addItem(neceTool, QString::fromUtf8("\354\203\235\355\231\234\354\232\251\355\222\210"));
        allTool = new QWidget();
        allTool->setObjectName("allTool");
        allTool->setGeometry(QRect(0, 0, 170, 208));
        toolBox->addItem(allTool, QString::fromUtf8("\354\240\204\354\262\264"));

        retranslateUi(AdminProductForm);

        stackedWidget->setCurrentIndex(4);
        toolBox->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(AdminProductForm);
    } // setupUi

    void retranslateUi(QWidget *AdminProductForm)
    {
        AdminProductForm->setWindowTitle(QCoreApplication::translate("AdminProductForm", "Form", nullptr));
        toolBox->setItemText(toolBox->indexOf(beveraageTool), QCoreApplication::translate("AdminProductForm", "\354\235\214\353\243\214", nullptr));
        toolBox->setItemText(toolBox->indexOf(snackTool), QCoreApplication::translate("AdminProductForm", "\354\212\244\353\202\265", nullptr));
        toolBox->setItemText(toolBox->indexOf(instantTool), QCoreApplication::translate("AdminProductForm", "\354\246\211\354\204\235\354\213\235\355\222\210", nullptr));
        toolBox->setItemText(toolBox->indexOf(mikiceTool), QCoreApplication::translate("AdminProductForm", "\354\234\240\354\240\234\355\222\210/\354\225\204\354\235\264\354\212\244\355\201\254\353\246\274", nullptr));
        toolBox->setItemText(toolBox->indexOf(drinkTool), QCoreApplication::translate("AdminProductForm", "\354\243\274\353\245\230", nullptr));
        toolBox->setItemText(toolBox->indexOf(neceTool), QCoreApplication::translate("AdminProductForm", "\354\203\235\355\231\234\354\232\251\355\222\210", nullptr));
        toolBox->setItemText(toolBox->indexOf(allTool), QCoreApplication::translate("AdminProductForm", "\354\240\204\354\262\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminProductForm: public Ui_AdminProductForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPRODUCTFORM_H
