#include "adminchatform.h"
#include "ui_adminchatform.h"


AdminChatForm::AdminChatForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminChatForm)
    , m_chatServer(nullptr)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);

    //*김민성* 모델 초기화
    attendanceModel = new QStandardItemModel(this);
    attendanceModel->setColumnCount(1); // 열 1개
    attendanceModel->setHeaderData(0, Qt::Horizontal, "참석자");

    //*김민성* 모델을 QTableView 연결
    ui->attendanceView->setModel(attendanceModel);

    //ChatServer의 시그널과 AdminChatForm의 슬롯을 연결합니다.
    m_chatServer = new ChatServer(this);
    //ChatServer의 시그널과 AdminChatForm의 슬롯을 연결합니다.
    connect(m_chatServer, &ChatServer::newMessageReceived, this, &AdminChatForm::updateChatView);
}

AdminChatForm::~AdminChatForm()
{
    delete ui;
}

void AdminChatForm::on_toolBox_currentChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    //qDebug() << tr("QToolBox 페이지 변경됨 -> 인덱스:") << index << tr(", QStackedWidget 페이지 변경됨.");
}

void AdminChatForm::on_joinButton_clicked()                 //*김민성* 입장 버튼을 누른다면
{
    QStandardItem *item = new QStandardItem("관리자");       //*김민성* item에 관리자라는 객체 생성
    attendanceModel->appendRow(item);                      //*김민성* 목록에 관리자 추가.

    //서버 시작을 시도라고 결과를 확인합니다.
    //m_chatServer 객체에서 startServer() 함수를 호출합니다.성공과 실패를 반환합니다.
    if (m_chatServer->startServer())
    {
        ui->mainChatEdit->append("관리자의 서버가 성공적으로 시작되었습니다."
                                 "\n클라이언트들의 접속을 기다립니다.");
    }
    else
    {
        ui->mainChatEdit->append("서버 시작이 실패하였습니다."
                                 "\n오류 : " + m_chatServer->errorString());
    }
}

void AdminChatForm::on_sendButton_clicked()
{
    QString message = ui->chatEdit->toPlainText();  //QTextEdit()은 toPlainText()으로 받음. QlineEdit은 text()로 받음.
    if (message.isEmpty()){
        return;                                     //빈 메세지는 전송하지 않습니다.
    }

    //관리자가 보낸 메세지임을 표시하는 접두사를 붙여줍니다.
    QString formattedMessage = "[관리자] : " + message;

    //서버의 방송 기능을 호출합니다!
    m_chatServer->broadcastMessage(formattedMessage);
    //메세지를 보낸 후 입력창을 깨끗하게 비웁니다.
    ui->chatEdit->clear();
    //사용자가 입력하기 편하도록 보내고 나서, 다시 입력할수 있게 셋팅
    ui->chatEdit->setFocus();
}

void AdminChatForm::updateChatView(const QString &message)
{
    ui->mainChatEdit->append(message);
}
