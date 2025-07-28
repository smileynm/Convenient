// adminchatform.cpp

#include "adminchatform.h"
#include "ui_adminchatform.h"
#include "chatserver.h"
#include "membermanager.h"
#include <QMessageBox>
#include <QScrollBar>
#include <QKeyEvent>
#include <QTableWidgetItem>

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

    // ChatServer의 클라이언트 목록 업데이트 시그널과 연결
    connect(&chatServer, &ChatServer::clientListUpdated, this, &AdminChatForm::updateAttendanceList);

    // 서버에 접속 (예: localhost, 포트 12345)
    socket->connectToHost("127.0.0.1", 12345);
    qDebug() << "Trying to Connect Server";

    // attendanceWidget 설정 (ui->attendanceWidget는 .ui 파일에서 변경한 QTableWidget 이름)
    ui->attendanceWidget->setColumnCount(1); // 참여자 이름을 표시할 것이므로 1개 컬럼
    ui->attendanceWidget->setHorizontalHeaderLabels(QStringList() << tr("채팅 참여자")); // 컬럼 헤더 설정
    ui->attendanceWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // 셀 직접 편집 불가
    ui->attendanceWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 행 단위 선택

    // 초기 참여자 목록 업데이트를 한 번 수행합니다.
    updateAttendanceList(); // <<--- 이 부분을 추가합니다.

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
    MemberManager& memberManager = MemberManager::getInstance();
    message = memberManager.getLoggedinMember().firstKey() + " : " + message;
    if (message.isEmpty()) {
        return;
    }
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8() + "\n");
        ui->chatEdit->clear();
        //ui->mainChatEdit->append(message);
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

void AdminChatForm::updateAttendanceList() {
    ChatServer& chatServer = ChatServer::getInstance();
    QStringList clientNames = chatServer.getConnectedClientNames(); // 서버에서 현재 연결된 클라이언트 이름 목록을 가져옴

    ui->attendanceWidget->setRowCount(0); // 기존 항목 모두 제거

    // 가져온 이름을 attendanceWidget에 한 줄씩 추가
    for (int i = 0; i < clientNames.size(); ++i) {
        ui->attendanceWidget->insertRow(i);
        QTableWidgetItem* item = new QTableWidgetItem(clientNames.at(i));
        ui->attendanceWidget->setItem(i, 0, item);
    }
}
