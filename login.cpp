#include "login.h"
#include "ui_login.h"
#include "normal.h"
#include "admin.h"
#include "signup.h"

LogIn::LogIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::on_cancelButton_clicked()
{
    QApplication::quit();
}


void LogIn::on_signInButton_clicked()
{
    /* 분기 내용 */
    // Member List 검색하여
    // ID 및 PW 매칭

    // if( 관리자 )
    Admin *admin = new Admin;
    admin->show();
    this->close();
}


void LogIn::on_signUpButton_clicked()
{
    SignUp *signup = new SignUp;
    signup->show();
    this->close();
}


void LogIn::on_lineEdit_ID_returnPressed()
{
    on_signInButton_clicked();
}


void LogIn::on_lineEdit_PW_returnPressed()
{
    on_signInButton_clicked();
}

