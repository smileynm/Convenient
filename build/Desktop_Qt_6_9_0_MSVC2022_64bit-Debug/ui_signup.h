/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QGroupBox *groupBox;
    QLabel *label_id;
    QLabel *label_pw;
    QLabel *label_ckpw;
    QLabel *label_name;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *confirmButton_2;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(400, 300);
        groupBox = new QGroupBox(SignUp);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 400, 300));
        label_id = new QLabel(groupBox);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(20, 100, 62, 20));
        label_pw = new QLabel(groupBox);
        label_pw->setObjectName("label_pw");
        label_pw->setGeometry(QRect(20, 150, 62, 20));
        label_ckpw = new QLabel(groupBox);
        label_ckpw->setObjectName("label_ckpw");
        label_ckpw->setGeometry(QRect(20, 200, 81, 20));
        label_name = new QLabel(groupBox);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(20, 50, 62, 20));
        confirmButton = new QPushButton(groupBox);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(180, 250, 90, 30));
        cancelButton = new QPushButton(groupBox);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(290, 250, 90, 30));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 50, 170, 30));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 100, 170, 30));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(120, 150, 170, 30));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(120, 200, 170, 30));
        confirmButton_2 = new QPushButton(groupBox);
        confirmButton_2->setObjectName("confirmButton_2");
        confirmButton_2->setGeometry(QRect(300, 100, 80, 30));

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Form", nullptr));
        groupBox->setTitle(QString());
        label_id->setText(QCoreApplication::translate("SignUp", "ID :", nullptr));
        label_pw->setText(QCoreApplication::translate("SignUp", "PW :", nullptr));
        label_ckpw->setText(QCoreApplication::translate("SignUp", "Check PW :", nullptr));
        label_name->setText(QCoreApplication::translate("SignUp", "Name :", nullptr));
        confirmButton->setText(QCoreApplication::translate("SignUp", "\355\231\225 \354\235\270", nullptr));
        cancelButton->setText(QCoreApplication::translate("SignUp", "\354\267\250 \354\206\214", nullptr));
        confirmButton_2->setText(QCoreApplication::translate("SignUp", "\354\244\221\353\263\265\352\262\200\354\202\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
