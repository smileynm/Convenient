#include "adminchatform.h"
#include "ui_adminchatform.h"
#include "chatserver.h"
#include <QMessageBox>
#include <QScrollBar>
#include <QKeyEvent>

AdminChatForm::AdminChatForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminChatForm)
    , socket(new QTcpSocket(this)) {
    ui->setupUi(this);

    // 서버 연결 상태 표시 QLabel 추가 (ui에 QLabel 이름 labelConnectionStatus로 추가 필요)
    //ui->labelConnectionStatus->setText(tr("서버 연결 상태: 연결 안 됨"));
    ChatServer& chatServer = ChatServer::getInstance();
    chatServer.startServer(12345);
    // 소켓 시그널 연결
    connect(socket, &QTcpSocket::connected, this, &AdminChatForm::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &AdminChatForm::onDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &AdminChatForm::onReadyRead);

    // 서버에 접속 (예: localhost, 포트 12345)

    socket->connectToHost("127.0.0.1", 12345);
    qDebug() << "Trying to Connect Server";

    ui->toolBox->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);
}

AdminChatForm::~AdminChatForm() {
    delete ui;
}

void AdminChatForm::on_toolBox_currentChanged(int index) {
    ui->stackedWidget->setCurrentIndex(index);
}

void AdminChatForm::on_sendButton_clicked() {
    QString message = ui->chatEdit->toPlainText().trimmed();
    if (message.isEmpty()) {
        return;
    }
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8() + "\n");
        ui->chatEdit->clear();
        ui->mainChatEdit->append(message);
    } else {
        QMessageBox::warning(this, tr("오류"), tr("서버에 연결되어 있지 않습니다."));
    }
}

void AdminChatForm::onConnected() {
    //ui->labelConnectionStatus->setText(tr("서버 연결 상태: 연결됨"));
}

void AdminChatForm::onDisconnected() {
    //ui->labelConnectionStatus->setText(tr("서버 연결 상태: 연결 끊김"));
}

void AdminChatForm::onReadyRead() {
    while (socket->canReadLine()) {
        QByteArray line = socket->readLine().trimmed();
        QString message = QString::fromUtf8(line);
        ui->mainChatEdit->append(message);
        ui->mainChatEdit->verticalScrollBar()->setValue(ui->mainChatEdit->verticalScrollBar()->maximum());
        qDebug() << "Message recieved";
    }
}
