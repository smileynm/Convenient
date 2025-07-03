#include "admininfoform.h"
#include "ui_admininfoform.h"

AdminInfoForm::AdminInfoForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminInfoForm)
{
    ui->setupUi(this);
}

AdminInfoForm::~AdminInfoForm()
{
    delete ui;
}

void AdminInfoForm::on_toolBox_currentChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    //qDebug() << tr("QToolBox 페이지 변경됨 -> 인덱스:") << index << tr(", QStackedWidget 페이지 변경됨.");
}

