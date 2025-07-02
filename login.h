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
    void on_signInButton_clicked();
    void on_signUpButton_clicked();
    void on_lineEdit_ID_returnPressed();
    void on_lineEdit_PW_returnPressed();

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
