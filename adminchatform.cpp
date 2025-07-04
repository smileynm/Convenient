#include "adminchatform.h"
#include "ui_adminchatform.h"


AdminChatForm::AdminChatForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminChatForm)
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

void AdminChatForm::on_joinButton_clicked()  //*김민성* 입장 버튼을 누른다면
{
    QStandardItem *item = new QStandardItem("관리자");
     attendanceModel->appendRow(item);
}


