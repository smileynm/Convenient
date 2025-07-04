#include "normal.h"
#include "ui_normal.h"
#include "normalchatform.h"
#include "normalorderform.h"

Normal::Normal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Normal)
{
    ui->setupUi(this);

    // 제목표시줄 설정 : 일반 점주 모드
    setWindowTitle(tr("QT25 발주관리 시스템"));

    // tab에 추가할 객체 생성
    NormalChatForm *normalchatform = new NormalChatForm;
    NormalOrderForm *normalorderform = new NormalOrderForm;

    // tab에 객체 추가
    ui->tabWidget->addTab(normalchatform, tr("채팅서버"));
    ui->tabWidget->addTab(normalorderform, tr("발주관리"));
}

Normal::~Normal()
{
    delete ui;
}
