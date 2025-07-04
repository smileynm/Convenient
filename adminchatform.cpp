#include "adminchatform.h"
#include "ui_adminchatform.h"

AdminChatForm::AdminChatForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminChatForm)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);
}

AdminChatForm::~AdminChatForm()
{
    delete ui;
}

void AdminChatForm::on_toolBox_currentChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    //qDebug() << tr("QToolBox 페이지 변경됨 -> 인덱스:") << index << tr(", QStackedWidget 페이지 변경됨.");
}

