#include "chatserver.h"
#include <QDateTime>
#include <QDebug>

ClientHandler::ClientHandler(QTcpSocket* socket, QObject* parent)
    : QThread(parent), clientSocket(socket), running(true) {
    clientID = QString::number(reinterpret_cast<quintptr>(socket));
}

void ClientHandler::run() {
    connect(clientSocket, &QTcpSocket::readyRead, [this]() {
        while (clientSocket->canReadLine()) {
            QByteArray line = clientSocket->readLine().trimmed();
            QString message = QString::fromUtf8(line);
            emit messageReceived(message);
        }
    });

    exec();

    clientSocket->disconnectFromHost();
    clientSocket->waitForDisconnected();
    clientSocket->deleteLater();
}

QString ClientHandler::getClientID() {
    return clientID;
}

QTcpSocket* ClientHandler::getSocket() const {
    return clientSocket;
}

ChatServer& ChatServer::getInstance() {
    static ChatServer instance;
    return instance;
}

ChatServer::ChatServer(QObject* parent)
    : QTcpServer(parent), logFile("chat_log.txt") {
    if (!logFile.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Failed to open log file";
    }
}

ChatServer::~ChatServer() {
    stopServer();
    if (logFile.isOpen()) {
        logFile.close();
    }
}

bool ChatServer::startServer(quint16 port) {
    if (!this->listen(QHostAddress::Any, port)) {
        qWarning() << "Server failed to start";
        return false;
    }
    qDebug() << "Server started on port" << port;
    return true;
}

void ChatServer::stopServer() {
    for (auto handler : clients.keys()) {
        handler->quit();
        handler->wait();
        delete handler;
    }
    clients.clear();
    this->close();
}

void ChatServer::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket* socket = new QTcpSocket;
    if (!socket->setSocketDescriptor(socketDescriptor)) {
        delete socket;
        return;
    }

    ClientHandler* handler = new ClientHandler(socket);
    clients[handler] = handler->getClientID();

    connect(handler, &ClientHandler::messageReceived, this, [this](const QString& message) {
        QString logEntry = QString("[%1] %2: %3")
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
            .arg(message);
        logMessage(logEntry);
        broadcastMessage(message);
    });

    connect(handler, &ClientHandler::finished, this, [this, handler]() {
        clients.remove(handler);
        handler->deleteLater();
    });

    handler->start();
}

void ChatServer::broadcastMessage(const QString& message) {
    for (auto handler : clients.keys()) {
        QTcpSocket* socket = handler->getSocket();
        if (socket && socket->isOpen()) {
            socket->write(QString("%1\n").arg(message).toUtf8());
            socket->flush();
        }

    }
}

void ChatServer::logMessage(const QString& log) {
    QMutexLocker locker(&logMutex);
    if (logFile.isOpen()) {
        QTextStream out(&logFile);
        out << log << "\n";
        out.flush();
    }
}
