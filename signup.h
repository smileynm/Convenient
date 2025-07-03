#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QTextEdit>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_cancelButton_clicked();
    void on_dupButton_clicked();
    void on_confirmButton_clicked();

    // 비밀번호가 보이지 않게 하기위한 slot
    void on_pwEdit_cursorPositionChanged(int arg1, int arg2);
    void on_ckpwEdit_cursorPositionChanged(int arg1, int arg2);

    void on_ckpwEdit_textChanged(const QString &arg1);

private:
    Ui::SignUp *ui;
    bool allow_flag_id;        // 회원가입 가능한 아이디 플래그
    bool allow_flag_pw;        // 회원가입 가능한 비밀번호 플래그
};

#endif // SIGNUP_H
