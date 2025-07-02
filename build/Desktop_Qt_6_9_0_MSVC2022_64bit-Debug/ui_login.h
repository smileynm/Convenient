/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogIn
{
public:
    QPushButton *cancelButton;
    QGroupBox *groupBox_SignIn;
    QLabel *label_ID;
    QLabel *label_PW;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_PW;
    QPushButton *signInButton;
    QPushButton *signUpButton;

    void setupUi(QWidget *LogIn)
    {
        if (LogIn->objectName().isEmpty())
            LogIn->setObjectName("LogIn");
        LogIn->resize(376, 140);
        cancelButton = new QPushButton(LogIn);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(279, 101, 88, 29));
        groupBox_SignIn = new QGroupBox(LogIn);
        groupBox_SignIn->setObjectName("groupBox_SignIn");
        groupBox_SignIn->setGeometry(QRect(9, 8, 261, 81));
        label_ID = new QLabel(groupBox_SignIn);
        label_ID->setObjectName("label_ID");
        label_ID->setGeometry(QRect(18, 13, 62, 20));
        label_PW = new QLabel(groupBox_SignIn);
        label_PW->setObjectName("label_PW");
        label_PW->setGeometry(QRect(10, 47, 62, 20));
        lineEdit_ID = new QLineEdit(groupBox_SignIn);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(50, 10, 201, 28));
        lineEdit_PW = new QLineEdit(groupBox_SignIn);
        lineEdit_PW->setObjectName("lineEdit_PW");
        lineEdit_PW->setGeometry(QRect(50, 44, 201, 28));
        signInButton = new QPushButton(LogIn);
        signInButton->setObjectName("signInButton");
        signInButton->setGeometry(QRect(283, 8, 81, 81));
        signUpButton = new QPushButton(LogIn);
        signUpButton->setObjectName("signUpButton");
        signUpButton->setGeometry(QRect(180, 100, 88, 29));

        retranslateUi(LogIn);

        QMetaObject::connectSlotsByName(LogIn);
    } // setupUi

    void retranslateUi(QWidget *LogIn)
    {
        LogIn->setWindowTitle(QCoreApplication::translate("LogIn", "Form", nullptr));
        cancelButton->setText(QCoreApplication::translate("LogIn", "\354\267\250 \354\206\214", nullptr));
        groupBox_SignIn->setTitle(QString());
        label_ID->setText(QCoreApplication::translate("LogIn", "ID :", nullptr));
        label_PW->setText(QCoreApplication::translate("LogIn", "PW :", nullptr));
        signInButton->setText(QCoreApplication::translate("LogIn", "\353\241\234\352\267\270\354\235\270", nullptr));
        signUpButton->setText(QCoreApplication::translate("LogIn", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogIn: public Ui_LogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
