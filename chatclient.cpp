#include "chatclient.h"
#include "ui_normalchatform.h"
#include "normalchatform.h"
#include <QMessageBox>

ChatClient::ChatClient(QWidget *parent)
    : QWidget(parent), ui(new Ui::NormalChatForm), socket(new QTcpSocket(this)) {
    ui->setupUi(this);

    connect(socket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
    connect(socket, &QTcpSocket::connected, this, &ChatClient::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &ChatClient::onDisconnected);
}

ChatClient::~ChatClient() {
    delete ui;
}

void ChatClient::connectToServer(const QString& host, quint16 port) {
    socket->connectToHost(host, port);
}

void ChatClient::on_sendButton_clicked() {
    QString message = ui->chatEdit->toPlainText().trimmed();
    if (!message.isEmpty() && socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8() + "\n");
        ui->chatEdit->clear();
    }
}

void ChatClient::onReadyRead() {
    while (socket->canReadLine()) {
        QByteArray line = socket->readLine().trimmed();
        ui->annChatEdit->append(QString::fromUtf8(line));
    }
}

void ChatClient::onConnected() {
    ui->annChatEdit->append(tr("서버에 연결되었습니다."));
}

void ChatClient::onDisconnected() {
    ui->annChatEdit->append(tr("서버와 연결이 끊어졌습니다."));
}
