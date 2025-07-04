#include "normalchatform.h"
#include "ui_normalchatform.h"

NormalChatForm::NormalChatForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalChatForm)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);
}

NormalChatForm::~NormalChatForm()
{
    delete ui;
}

void NormalChatForm::on_toolBox_currentChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index); // toolBox와 stackedWidget 연동
    if (ui->toolBox->currentIndex() == 0) {
        ui->chatEdit->setReadOnly(true);
        ui->chatEdit->clear();
    }
    else {
        ui->chatEdit->setReadOnly(false);
        ui->chatEdit->setTextColor(tr("black"));
        ui->chatEdit->clear();
    }
}

void NormalChatForm::on_sendButton_clicked()
{
    // 공지사항 페이지에서 클릭할 경우, 미동작
    if (ui->toolBox->currentIndex() == 0) {
        ui->chatEdit->setTextColor(tr("gray"));
        ui->chatEdit->setText(tr("관리자 권한이 필요합니다."));
    }
    // 일반 채팅에서 클릭할 경우
    else {
        /* 통신 구현 */
    }
}

