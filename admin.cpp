#include "admin.h"
#include "ui_admin.h"
#include "adminchatform.h"
#include "admininfoform.h"
#include "adminproductform.h"
#include "adminorderlistform.h"

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);

    // 제목표시줄 설정 : 관리자모드
    setWindowTitle(tr("QT25 관리자모드"));

    // tab에 추가할 객체 생성
    AdminInfoForm *admininfoform = new AdminInfoForm(this);
    AdminChatForm *adminchatform = new AdminChatForm(this);
    AdminProductForm *adminproductform = new AdminProductForm(this);
    AdminOrderListForm *adminorderlistform = new AdminOrderListForm(this);

    // tab에 객체 추가
    ui->tabWidget->addTab(admininfoform, tr("고객정보"));
    ui->tabWidget->addTab(adminchatform, tr("채팅서버"));
    ui->tabWidget->addTab(adminproductform, tr("상품관리"));
    ui->tabWidget->addTab(adminorderlistform, tr("발주목록"));
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_actionQuit_triggered()
{
    QApplication::quit();
}

