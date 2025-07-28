#include "admininfoform.h"
#include "ui_admininfoform.h"
#include "membermanager.h"

AdminInfoForm::AdminInfoForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminInfoForm) {
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);

    QStringList headers;
    headers << "사용자 ID" << "이름" << "관리자 여부" << "비밀번호";
    ui->membWidget->setColumnCount(headers.size());
    ui->membWidget->setHorizontalHeaderLabels(headers);

    MemberManager& memberManager = MemberManager::getInstance();
    QMap<QString, Member*> memberList;
    memberList = memberManager.getMemberMap();

    ui->membWidget->setRowCount(memberList.size());
    auto it = memberList.constBegin();
    for (int row=0; row<memberList.size(); ++row, ++it) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getMemberName());
        QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getMemberID());
        QTableWidgetItem *isManagerItem = new QTableWidgetItem((it.value()->isManager()==true? "true" : "false"));
        QTableWidgetItem *pwItem = new QTableWidgetItem(it.value()->getMemberPW());
        ui->membWidget->setItem(row, 0, idItem);
        ui->membWidget->setItem(row, 1, nameItem);
        ui->membWidget->setItem(row, 2, isManagerItem);
        ui->membWidget->setItem(row, 3, pwItem);
    }
}

AdminInfoForm::~AdminInfoForm() {
    delete ui;
}

void AdminInfoForm::on_toolBox_currentChanged(int index) {
    ui->stackedWidget->setCurrentIndex(index);
    //qDebug() << tr("QToolBox 페이지 변경됨 -> 인덱스:") << index << tr(", QStackedWidget 페이지 변경됨.");
}

