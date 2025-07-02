#include "normal.h"
#include "ui_normal.h"

Normal::Normal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Normal)
{
    ui->setupUi(this);
}

Normal::~Normal()
{
    delete ui;
}
