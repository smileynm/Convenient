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

private:
    Ui::SignUp *ui;
    bool allow_flag;        // 회원가입 가능한 아이디 플래그
};

#endif // SIGNUP_H
