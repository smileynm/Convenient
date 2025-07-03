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
    QGroupBox *logInGroupBox;
    QLabel *idLabel;
    QLabel *pwLabel;
    QLineEdit *idEdit;
    QLineEdit *pwEdit;
    QPushButton *logInButton;
    QPushButton *signUpButton;

    void setupUi(QWidget *LogIn)
    {
        if (LogIn->objectName().isEmpty())
            LogIn->setObjectName("LogIn");
        LogIn->resize(376, 140);
        cancelButton = new QPushButton(LogIn);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(279, 101, 88, 29));
        logInGroupBox = new QGroupBox(LogIn);
        logInGroupBox->setObjectName("logInGroupBox");
        logInGroupBox->setGeometry(QRect(9, 8, 261, 81));
        idLabel = new QLabel(logInGroupBox);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(18, 13, 62, 20));
        pwLabel = new QLabel(logInGroupBox);
        pwLabel->setObjectName("pwLabel");
        pwLabel->setGeometry(QRect(10, 47, 62, 20));
        idEdit = new QLineEdit(logInGroupBox);
        idEdit->setObjectName("idEdit");
        idEdit->setGeometry(QRect(50, 10, 201, 28));
        pwEdit = new QLineEdit(logInGroupBox);
        pwEdit->setObjectName("pwEdit");
        pwEdit->setGeometry(QRect(50, 44, 201, 28));
        logInButton = new QPushButton(LogIn);
        logInButton->setObjectName("logInButton");
        logInButton->setGeometry(QRect(283, 8, 81, 81));
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
        logInGroupBox->setTitle(QString());
        idLabel->setText(QCoreApplication::translate("LogIn", "ID :", nullptr));
        pwLabel->setText(QCoreApplication::translate("LogIn", "PW :", nullptr));
        logInButton->setText(QCoreApplication::translate("LogIn", "\353\241\234\352\267\270\354\235\270", nullptr));
        signUpButton->setText(QCoreApplication::translate("LogIn", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogIn: public Ui_LogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
