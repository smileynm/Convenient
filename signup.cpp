#include "signup.h"
#include "ui_signup.h"
#include "login.h"
#include <QMessageBox>

SignUp::SignUp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUp)
{
    // 중복 ID 여부 확인 변수
    allow_flag_id = 0;
    allow_flag_pw = 0;
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_cancelButton_clicked()
{
    LogIn *login = new LogIn;
    login->show();
    this->close();
}

void SignUp::on_dupButton_clicked()
{
    /* ID List 검색 */

    // 중복 발생시
    // if( 중복 )
    //ui->dupLabel->setStyleSheet(tr("color: red;"));
    //ui->dupLabel->setText(tr("중복된 아이디 입니다"));
    //allow_flag_id = 0;


    // else // 신규가입
    ui->dupLabel->setStyleSheet("color: green;");
    ui->dupLabel->setText(tr("사용가능"));
    allow_flag_id = 1;

}

void SignUp::on_confirmButton_clicked()
{
    // if( allow_flag == 0 )
    QMessageBox::critical(this, tr("주의"), tr("ID 중복검사를 진행하십시오."), QMessageBox::Ok);
    // 승인 안함

    // allow_flag_id = 1 일 경우와
    // PW와 chPW가 동일할 경우, ( allow_flag_pw = 1 )
    // 입력된 ID와 PW를 신규로 member Vector에 저장

    //LogIn *login = new LogIn;
    //login->show();
    //this->close();
}


void SignUp::on_pwEdit_cursorPositionChanged(int arg1, int arg2)
{
    // 패스워드 안보이게 하기
    ui->pwEdit->setEchoMode(QLineEdit::Password);
    ui->ckpwEdit->setEchoMode(QLineEdit::Password);
}


void SignUp::on_ckpwEdit_cursorPositionChanged(int arg1, int arg2)
{
    // 패스워드 안보이게 하기
    ui->pwEdit->setEchoMode(QLineEdit::Password);
    ui->ckpwEdit->setEchoMode(QLineEdit::Password);
}


void SignUp::on_ckpwEdit_textChanged(const QString &arg1)
{
    QString pw = ui->pwEdit->text();
    QString ckpw = ui->ckpwEdit->text();
    if( pw != ckpw ) {
        // "패스워드가 일치하지 않습니다"
        ui->ckpwLabel->setStyleSheet(tr("color: red;"));
        ui->ckpwLabel->setText(tr("패스워드가 일치하지 않습니다"));
        allow_flag_pw = 0;
    }
    else {
        ui->ckpwLabel->setStyleSheet(tr("color: green;"));
        ui->ckpwLabel->setText(tr("패스워드가 일치합니다"));
        allow_flag_pw = 1;
    }

}

