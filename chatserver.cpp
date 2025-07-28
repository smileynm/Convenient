// chatserver.cpp

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

    // 클라이언트가 첫 메시지로 자신의 이름을 보낼 때 까지는 'Unknown'으로 저장
    // 이후 메시지에서 사용자명을 파싱하여 사용
    m_connectedClientNames[socket] = "Unknown";
    emit clientListUpdated();

    connect(handler, &ClientHandler::messageReceived, this, [this, socket](const QString& message) {

        QString senderName = "Unknown";
        if (message.contains("님이 접속하셨습니다.")) {
            senderName = message.split("님이 접속하셨습니다.")[0].trimmed();
        } else {
            int colonPos = message.indexOf(':');
            if (colonPos != -1) {
                senderName = message.left(colonPos).trimmed();
            }
        }

        // m_connectedClientNames에 사용자 이름을 업데이트하고, 목록이 변경되었음을 알립
        if (m_connectedClientNames.value(socket) == "Unknown" || m_connectedClientNames.value(socket) != senderName) {
            m_connectedClientNames[socket] = senderName;
            emit clientListUpdated(); // 이름이 업데이트되면 목록 갱신 시그널 발생
        }

        QString logEntry = QString("[%1] %2")
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
            .arg(message);
        logMessage(logEntry);
        broadcastMessage(message);
    });

    // connect(handler, &ClientHandler::finished, this, [this, handler]() {
    //     clients.remove(handler);
    //     handler->deleteLater();
    // });

    // 클라이언트 소켓 연결 해제 시그널 연결
    // QTcpSocket의 disconnected 시그널을 사용
    connect(socket, &QTcpSocket::disconnected, this, [this, socket, handler]() {
        qDebug() << "Client disconnected: " << m_connectedClientNames.value(socket);

        handler->quit();      // 스레드 이벤트 루프 종료 요청
        handler->wait();      // 스레드가 완전히 종료될 때까지 대기

        // m_connectedClientNames에서 제거
        m_connectedClientNames.remove(socket);
        // ClientHandler 및 연결된 스레드 객체 해제
        clients.remove(handler);
        //handler->deleteLater();

        emit clientListUpdated(); // 목록 갱신 시그널 발생
    });

    handler->start();
}

QStringList ChatServer::getConnectedClientNames() const {
    QStringList names;
    for (const QString& name : m_connectedClientNames.values()) {
        if (name != "Unknown" && !name.isEmpty()) { // 'Unknown'이거나 빈 이름은 제외
            names.append(name);
        }
    }
    // 중복된 이름이 있을 경우 제거하고 정렬
    // names.removeDuplicates();
    // names.sort();
    return names;
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
