#ifndef ADMINPRODUCTFORM_H
#define ADMINPRODUCTFORM_H

#include <QWidget>

namespace Ui {
class AdminProductForm;
}

class AdminProductForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdminProductForm(QWidget *parent = nullptr);
    ~AdminProductForm();

private slots:
    void on_toolBox_currentChanged(int index);

private:
    Ui::AdminProductForm *ui;
};

#endif // ADMINPRODUCTFORM_H
