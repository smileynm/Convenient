#include "normal.h"
#include "ui_normal.h"

Normal::Normal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Normal)
{
    ui->setupUi(this);

    // 제목표시줄 설정 : 일반 점주 모드
    setWindowTitle(tr("QT25 발주관리 시스템"));
}

Normal::~Normal()
{
    delete ui;
}
