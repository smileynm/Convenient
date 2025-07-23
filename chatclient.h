#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include "normalchatform.h"

namespace Ui {
class ChatClient;
}

class ChatClient : public QWidget {
    Q_OBJECT

public:
    explicit ChatClient(QWidget *parent = nullptr);
    ~ChatClient();

    void connectToServer(const QString& host, quint16 port);

private slots:
    void on_sendButton_clicked();
    void onReadyRead();
    void onConnected();
    void onDisconnected();

private:
    Ui::NormalChatForm *ui;
    QTcpSocket* socket;
};

#endif // CHATCLIENT_H
