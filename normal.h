#ifndef NORMAL_H
#define NORMAL_H

#include <QMainWindow>

namespace Ui {
class Normal;
}

class Normal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Normal(QWidget *parent = nullptr);
    ~Normal();

private:
    Ui::Normal *ui;
};

#endif // NORMAL_H
