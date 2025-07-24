#include "normalchatform.h"
#include "ui_normalchatform.h"
#include "membermanager.h"
#include <QMessageBox>
#include <QScrollBar>

NormalChatForm::NormalChatForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalChatForm)
    , socket(new QTcpSocket(this)) {
    ui->setupUi(this);

    // 서버 연결 상태 표시 QLabel 추가 (ui에 QLabel 이름 labelConnectionStatus로 추가 필요)
    //ui->labelConnectionStatus->setText(tr("서버 연결 상태: 연결 안 됨"));

    // 소켓 시그널 연결
    connect(socket, &QTcpSocket::connected, this, &NormalChatForm::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &NormalChatForm::onDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &NormalChatForm::onReadyRead);

    // 서버에 접속 (예: localhost, 포트 12345)
    socket->connectToHost("127.0.0.1", 12345);
    qDebug() << "Trying to Connect Client";

    ui->toolBox->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);
}

NormalChatForm::~NormalChatForm() {
    delete ui;
}

void NormalChatForm::on_toolBox_currentChanged(int index) {
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

void NormalChatForm::on_sendButton_clicked() {
    // 공지사항 페이지에서 클릭할 경우, 미동작
    if (ui->toolBox->currentIndex() == 0) {
        ui->chatEdit->setTextColor(tr("gray"));
        ui->chatEdit->setText(tr("관리자 권한이 필요합니다."));
        return;
    }

    // 일반 채팅에서 클릭할 경우
    QString message = ui->chatEdit->toPlainText().trimmed();
    if (message.isEmpty()) {
        return;
    }

    if (socket->state() == QAbstractSocket::ConnectedState) {
        // 메시지 전송 (예: 사용자 ID와 함께)
        MemberManager& memberManager = MemberManager::getInstance();
        QMap<QString, Member*> member = memberManager.getLoggedinMember();
        QString userId = member.begin().key();

        QString fullMessage = userId + ": " + message;
        socket->write(fullMessage.toUtf8() + "\n");

        // 자신의 메시지도 채팅창에 표시
        //ui->mainChatEdit->append(fullMessage);

        // 입력창 초기화
        ui->chatEdit->clear();
    } else {
        QMessageBox::warning(this, tr("오류"), tr("서버에 연결되어 있지 않습니다."));
    }
}

void NormalChatForm::onConnected() {
    //ui->labelConnectionStatus->setText(tr("서버 연결 상태: 연결됨"));

    // 접속 알림 메시지
    MemberManager& memberManager = MemberManager::getInstance();
    QMap<QString, Member*> member = memberManager.getLoggedinMember();
    QString userId = member.begin().key();

    QString connectMessage = userId + tr(" 님이 접속하셨습니다.");
    socket->write(connectMessage.toUtf8() + "\n");
}

void NormalChatForm::onDisconnected() {
    //ui->labelConnectionStatus->setText(tr("서버 연결 상태: 연결 끊김"));
    ui->mainChatEdit->append(tr("서버와의 연결이 끊어졌습니다."));
}

void NormalChatForm::onReadyRead() {
    while (socket->canReadLine()) {
        QByteArray line = socket->readLine().trimmed();
        QString message = QString::fromUtf8(line);
        ui->mainChatEdit->append(message);

        ui->mainChatEdit->verticalScrollBar()->setValue(ui->mainChatEdit->verticalScrollBar()->maximum());
    }
}
