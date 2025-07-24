#include "login.h"
#include "ui_login.h"
#include "normal.h"
#include "admin.h"
#include "signup.h"
#include "membermanager.h"
#include <QString>
#include <QDialog>
#include <QMessageBox>

LogIn::LogIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogIn) {
    ui->setupUi(this);

    // 제목표시줄 설정 : Login
    setWindowTitle(tr("QT25 LogIn"));
}

LogIn::~LogIn() {
    delete ui;
}

void LogIn::on_cancelButton_clicked() {
    QApplication::quit();
}

void LogIn::on_logInButton_clicked() {
    // 분기 내용
    bool logged_in = false;
    MemberManager& memberManager = MemberManager::getInstance();
    QString userid = ui->idEdit->text();
    QString userpw = ui->pwEdit->text();

    QMap<QString, Member*> temp;
    temp = memberManager.getMemberMap();
    for (auto it = temp.constBegin(); it!=temp.constEnd(); ++it) {
        if (it.key() == userid && it.value()->getMemberPW() == userpw) {
            if (it.value()->isManager()==true){
                QMap<QString, Member*> loginMember;
                loginMember.insert(it.key(), it.value());
                memberManager.setLoggedInMember(loginMember);
                logged_in = true;
                Admin *admin = new Admin;
                admin->show();
                this->close();
            } else {
                QMap<QString, Member*> loginMember;
                loginMember.insert(it.key(), it.value());
                memberManager.setLoggedInMember(loginMember);
                logged_in = true;
                Normal *normal = new Normal;
                normal->show();
                this->close();
            }
        }
    }

    // 잘못된 회원 정보
    if (!logged_in){
        QMessageBox::critical(this, tr("Wrong ID or PW"), tr("Check your ID or PW"), QMessageBox::Ok);
    }
}

void LogIn::on_signUpButton_clicked() {
    SignUp *signup = new SignUp;
    signup->show();
    this->close();
}

void LogIn::on_idEdit_returnPressed() {
    on_logInButton_clicked();
}


void LogIn::on_pwEdit_returnPressed() {
    on_logInButton_clicked();
}


void LogIn::on_pwEdit_cursorPositionChanged(int arg1, int arg2) {
    ui->pwEdit->setEchoMode(QLineEdit::Password);
}

