#include "adminproductform.h"
#include "ui_adminproductform.h"

AdminProductForm::AdminProductForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminProductForm)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(6);
}

AdminProductForm::~AdminProductForm()
{
    delete ui;
}

void AdminProductForm::on_toolBox_currentChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    //qDebug() << tr("QToolBox 페이지 변경됨 -> 인덱스:") << index << tr(", QStackedWidget 페이지 변경됨.");
}

