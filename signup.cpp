#include "signup.h"
#include "ui_signup.h"
#include "login.h"

SignUp::SignUp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUp)
{
    // 중복 ID 여부 확인 변수
    allow_flag = 0;
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
    //ui->dupLabel->setStyleSheet("color: red;");
    //ui->dupLabel->setText("중복된 아이디 입니다");
    //allow_flag = 0;


    // else // 신규가입
    ui->dupLabel->setStyleSheet("color: green;");
    ui->dupLabel->setText("사용가능");
    allow_flag = 1;

}

void SignUp::on_confirmButton_clicked()
{
    // if( allow_flag == 0 )
    // 주의 dialog 출력
    // 승인 안함

    // allow_flag = 1 일 경우와
    // PW와 chPW가 동일할 경우,
    // 입력된 ID와 PW를 신규로 member Vector에 저장

    // if( pw != ckpw )
    // "패스워드가 일치하지 않습니다"
    ui->ckpwLabel->setStyleSheet("color: red;");
    ui->ckpwLabel->setText("패스워드가 일치하지 않습니다");
    allow_flag = 0;

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

