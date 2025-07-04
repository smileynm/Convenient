/********************************************************************************
** Form generated from reading UI file 'adminchatform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINCHATFORM_H
#define UI_ADMINCHATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminChatForm
{
public:
    QTextEdit *chatEdit;
    QPushButton *sendButton;
    QToolBox *toolBox;
    QWidget *annTool;
    QWidget *chatTool;
    QPushButton *joinButton;
    QPushButton *exitButton;
    QTableView *attendanceView;
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QTextEdit *annChatEdit;
    QWidget *page_1;
    QTextEdit *mainChatEdit;

    void setupUi(QWidget *AdminChatForm)
    {
        if (AdminChatForm->objectName().isEmpty())
            AdminChatForm->setObjectName("AdminChatForm");
        AdminChatForm->resize(800, 550);
        chatEdit = new QTextEdit(AdminChatForm);
        chatEdit->setObjectName("chatEdit");
        chatEdit->setGeometry(QRect(5, 480, 700, 60));
        sendButton = new QPushButton(AdminChatForm);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(715, 480, 80, 60));
        toolBox = new QToolBox(AdminChatForm);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(620, 10, 170, 460));
        annTool = new QWidget();
        annTool->setObjectName("annTool");
        annTool->setGeometry(QRect(0, 0, 170, 388));
        toolBox->addItem(annTool, QString::fromUtf8("\352\263\265\354\247\200\354\202\254\355\225\255"));
        chatTool = new QWidget();
        chatTool->setObjectName("chatTool");
        chatTool->setGeometry(QRect(0, 0, 170, 388));
        joinButton = new QPushButton(chatTool);
        joinButton->setObjectName("joinButton");
        joinButton->setGeometry(QRect(10, 350, 70, 30));
        exitButton = new QPushButton(chatTool);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(90, 350, 70, 30));
        attendanceView = new QTableView(chatTool);
        attendanceView->setObjectName("attendanceView");
        attendanceView->setGeometry(QRect(10, 10, 150, 320));
        toolBox->addItem(chatTool, QString::fromUtf8("\354\261\204\355\214\205\353\260\251"));
        stackedWidget = new QStackedWidget(AdminChatForm);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 600, 460));
        page_0 = new QWidget();
        page_0->setObjectName("page_0");
        annChatEdit = new QTextEdit(page_0);
        annChatEdit->setObjectName("annChatEdit");
        annChatEdit->setGeometry(QRect(0, 0, 600, 460));
        annChatEdit->setReadOnly(true);
        stackedWidget->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        mainChatEdit = new QTextEdit(page_1);
        mainChatEdit->setObjectName("mainChatEdit");
        mainChatEdit->setGeometry(QRect(0, 0, 600, 460));
        mainChatEdit->setReadOnly(true);
        stackedWidget->addWidget(page_1);

        retranslateUi(AdminChatForm);

        toolBox->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AdminChatForm);
    } // setupUi

    void retranslateUi(QWidget *AdminChatForm)
    {
        AdminChatForm->setWindowTitle(QCoreApplication::translate("AdminChatForm", "Form", nullptr));
        sendButton->setText(QCoreApplication::translate("AdminChatForm", "Send", nullptr));
        toolBox->setItemText(toolBox->indexOf(annTool), QCoreApplication::translate("AdminChatForm", "\352\263\265\354\247\200\354\202\254\355\225\255", nullptr));
        joinButton->setText(QCoreApplication::translate("AdminChatForm", "\354\236\205 \354\236\245", nullptr));
        exitButton->setText(QCoreApplication::translate("AdminChatForm", "\355\207\264 \354\236\245", nullptr));
        toolBox->setItemText(toolBox->indexOf(chatTool), QCoreApplication::translate("AdminChatForm", "\354\261\204\355\214\205\353\260\251", nullptr));
#if QT_CONFIG(tooltip)
        annChatEdit->setToolTip(QCoreApplication::translate("AdminChatForm", "<html><head/><body><p>ann_chat_edit</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mainChatEdit->setToolTip(QCoreApplication::translate("AdminChatForm", "<html><head/><body><p>main_chat_edit</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class AdminChatForm: public Ui_AdminChatForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINCHATFORM_H
