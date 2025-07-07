#include "chatserver.h"
#include <QDebug>
//ChatServer 생성자
ChatServer::ChatServer(QObject *parent)
    : QTcpServer(parent) {}
//ChatServer 소멸자
ChatServer::~ChatServer() {}
//ChatServer 시작시 실행하는 함수
bool ChatServer::startServer(quint16 port)
{
    //AHostAddress를 받지 못해서, 서버 실행 안됬을때 시작할수 없다는 코드.
    if (!listen(QHostAddress::Any, port)){
        qDebug() << "Server could not start:" << errorString();
        //실패를 반환합니다.
        return false;
    }
    //서버가 실행되면, 실행되었다고 출력하는 코드
    qDebug() << "Server started on port" << port;
    //성공을 반환합니다.
    return true;
}

void ChatServer::onReadyRead() {
    // 시그널을 보낸 객체(데이터를 보낸 클라이언트)가 누구인지 알아냅니다.
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (!client){       //만약 client가 유효하지 않으면 아무것도 하지 알고 종료
        return;
    }
    // 클라이언트가 보낸 데이터를 모두 읽어옵니다.
    QByteArray data = client->readAll();
    //반은 데이터를 UI로 전달하기 위해 시그널을 발생시킵니다.
    emit newMessageReceived(QString::fromUtf8(data));
    //모든 클라이언트에게 다시 방송합니다.
    for (QTcpSocket *otherClient : m_clients)
    {
        otherClient->write(data);
    }
};

//새로운 클라이언트가 서버에 연결을 시도할 때 호출되는 함수
void ChatServer::incomingConnection(qintptr socketDescriptor)
{
    //연결되었다면, 메세지를 출력하는 함수
    qDebug() << "New connection received. Socket descriptor:" << socketDescriptor;
    //새로운 클라이언트 소켓 객체를 생성. QTcpSocket은 Qt에서 제공하는 Tcp 통신용 소켓 클래스, this는 Chatserver 객체를 가르키며,이 소켓의 부모로 설정됩니다. 메모리 관리는 Qt가 해줍니다.
    QTcpSocket *clientSocket = new QTcpSocket(this);
    //socketDescriptor는 OS가 생성한 기존 연결을 식별, QTcpSocket 객체에 해당 연결을 바인딩하는 역할. clientSocket이 클라이언트와 연결된 상태가 됩니다.
    clientSocket->setSocketDescriptor(socketDescriptor);

    // 클라이언트 목록(m_clients)에 새로 접속한 클라이언트를 추가 합니다.
    m_clients.append(clientSocket);

    //클라이언트의 접속 시작 시그널을 우리 서버의 onreadyRead 슬롯에 연결합니다.
    connect(clientSocket, &QTcpSocket::readyRead, this, &ChatServer::onReadyRead);

    //클라이언트의 접속 종료 시그널을 우리 서버의 onDisconnected 슬롯에 연결합니다.
    connect(clientSocket, &QTcpSocket::disconnected, this, &ChatServer::onDisconnected);
    //현재 연결된 클라이언트 수를 출력합니다. 실시간 클라이언트 수 모니터링.
    qDebug() << "New client added. Total clients:" << m_clients.count();
}

//
void ChatServer::onDisconnected()
{
    //접속을 종료한 클라이언트가 누구인지 알아냅니다.
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (!client)
    {
        return;
    }

    //클라이언트 목록에서 해당 클라이언트를 제거합니다.
    m_clients.removeAll(client);
    //소켓 객체를 나중에 안전하게 삭제하도록 예약합니다.
    client->deleteLater();
    //현재 클라이언트 수 모니터링.
    qDebug() << "client disconnected. Ramaining clients : " << m_clients.count();
}

void ChatServer::broadcastMessage(const QString &message)
{
    if (message.isEmpty()){
        return;             //빈 메세지는 보내지 않습니다.
    }

    QByteArray data = message.toUtf8();

    qDebug() << "Broadcasting message: " << data;

    //m_clients 리스트를 순화하며 모든 클라이언트에게 메세지를 보냅니다.
    for (QTcpSocket *client : m_clients)
    {
        client->write(data);
    }

    //관리자가 보낸 메세지도 UI에 표시하기 위해 시그널을 발생시킵니다.
    emit newMessageReceived(message);
}
