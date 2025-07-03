#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class LogIn;
}

class LogIn : public QWidget
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();

private slots:
    void on_cancelButton_clicked();
    void on_signUpButton_clicked();
    void on_logInButton_clicked();
    void on_idEdit_returnPressed();
    void on_pwEdit_returnPressed();
    void on_pwEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
