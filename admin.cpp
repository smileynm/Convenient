// admin.cpp

#include "admin.h"
#include "ui_admin.h"
#include "adminchatform.h"
#include "admininfoform.h"
#include "adminproductform.h"
#include "adminorderlistform.h"
#include "membermanager.h"

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin) {
    ui->setupUi(this);

    // 현재 로그인된 유저 출력 (debug 목적)
    // for문을 돌리는 이유는 여러명이 들어가진 않는지 보기 위함.
    MemberManager& memberManager = MemberManager::getInstance();
    QMap<QString, Member*> member = memberManager.getLoggedinMember();
    for (auto it=member.constBegin(); it!=member.constEnd(); ++it) {
        qDebug() << it.key();
    }

    // 제목표시줄 설정 : 관리자모드
    setWindowTitle(tr("QT25 관리자 시스템: %1").arg(member.begin().key()));

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

Admin::~Admin() {
    delete ui;
}

void Admin::on_actionQuit_triggered() {
    QApplication::quit();
}

