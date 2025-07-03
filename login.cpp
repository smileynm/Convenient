#include "login.h"
#include "ui_login.h"
#include "normal.h"
#include "admin.h"
#include "signup.h"
#include <QDialog>

LogIn::LogIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);

    // 제목표시줄 설정 : Login
    setWindowTitle(tr("QT25 LogIn"));
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::on_cancelButton_clicked()
{
    QApplication::quit();
}

void LogIn::on_logInButton_clicked()
{
    /* 분기 내용 */
    QString userid = ui->idEdit->text();
    QString userpw = ui->pwEdit->text();
    // Member List 검색하여
    // ID 및 PW 매칭
    qDebug() << tr("사용자 아이디: ") << userid;
    qDebug() << tr("사용자 비밀번호: ") << userpw;
    // if( 관리자 )
    if (userid == "admin") {
        Admin *admin = new Admin;
        admin->show();
        this->close();
    }

    // else if ( 일반회원 )
    else if (userid == "normal") {
        Normal *normal = new Normal;
        normal->show();
        this->close();
    }

    // else // 잘못된 회원 정보
    /*
     * QMessageBox::critical(this, tr("잘못된 회원 정보"), tr("ID 또는 비밀번호를 확인하십시오."), QMessageBox::Ok);
     */
}

void LogIn::on_signUpButton_clicked()
{
    SignUp *signup = new SignUp;
    signup->show();
    this->close();
}

void LogIn::on_idEdit_returnPressed()
{
    on_logInButton_clicked();
}


void LogIn::on_pwEdit_returnPressed()
{
    on_logInButton_clicked();
}


void LogIn::on_pwEdit_cursorPositionChanged(int arg1, int arg2)
{
    ui->pwEdit->setEchoMode(QLineEdit::Password);
}

