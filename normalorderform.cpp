#include "normalorderform.h"
#include "ui_normalorderform.h"

NormalOrderForm::NormalOrderForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalOrderForm)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(6);
}

NormalOrderForm::~NormalOrderForm()
{
    delete ui;
}
