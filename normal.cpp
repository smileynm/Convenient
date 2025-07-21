#include "normal.h"
#include "ui_normal.h"
#include "normalchatform.h"
#include "normalorderform.h"
#include "membermanager.h"
#include <QMap>

Normal::Normal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Normal) {
    ui->setupUi(this);

    // 현재 로그인된 유저 출력 (debug 목적)
    // for문을 돌리는 이유는 여러명이 들어가진 않는지 보기 위함.
    MemberManager& memberManager = MemberManager::getInstance();
    QMap<QString, Member*> member = memberManager.getLoggedinMember();
    for (auto it=member.constBegin(); it!=member.constEnd(); ++it) {
        qDebug() << it.key();
    }

    // 제목표시줄 설정 : 일반 점주 모드
    setWindowTitle(tr("QT25 발주관리 시스템: %1").arg(member.begin().key()));



    // tab에 추가할 객체 생성
    NormalChatForm *normalchatform = new NormalChatForm;
    NormalOrderForm *normalorderform = new NormalOrderForm;

    // tab에 객체 추가
    ui->tabWidget->addTab(normalchatform, tr("채팅서버"));
    ui->tabWidget->addTab(normalorderform, tr("발주관리"));
}

Normal::~Normal() {
    delete ui;
}
