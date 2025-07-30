// normalorderform.h

#ifndef NORMALORDERFORM_H
#define NORMALORDERFORM_H

#include <QWidget>

namespace Ui {
class NormalOrderForm;
}

class NormalOrderForm : public QWidget {
    Q_OBJECT

public:
    explicit NormalOrderForm(QWidget *parent = nullptr);
    ~NormalOrderForm();

private slots:
    void on_toolBox_currentChanged(int index);

private:
    Ui::NormalOrderForm *ui;
};

#endif // NORMALORDERFORM_H
