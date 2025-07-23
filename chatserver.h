#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QMutex>

class ClientHandler : public QThread {
    Q_OBJECT
public:
    explicit ClientHandler(QTcpSocket* socket, QObject* parent = nullptr);
    void run() override;
    QString getClientID();

signals:
    void clientDisconnected(ClientHandler* handler);
    void messageReceived(const QString& sender, const QString& message);

private:
    QTcpSocket* clientSocket;
    QString clientID;
    bool running;
};

class ChatServer : public QTcpServer {
    Q_OBJECT
public:
    static ChatServer& getInstance();
    bool startServer(quint16 port);
    void stopServer();

    void broadcastMessage(const QString& sender, const QString& message);
    void logMessage(const QString& log);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    explicit ChatServer(QObject* parent = nullptr);
    ~ChatServer();

    QMap<ClientHandler*, QString> clients;
    QFile logFile;
    QMutex logMutex;

    // 싱글턴 복사 방지
    ChatServer(const ChatServer&) = delete;
    ChatServer& operator=(const ChatServer&) = delete;
};

#endif // CHATSERVER_H
