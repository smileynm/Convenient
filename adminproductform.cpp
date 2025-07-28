#include "adminproductform.h"
#include "ui_adminproductform.h"
#include "productmanager.h"
// adminproductform.cpp

#include <QMap>
#include <QString>

AdminProductForm::AdminProductForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminProductForm) {
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(6);

    QStringList headers;
    headers << "상품명" << "상품ID" << "가격" << "카테고리";
    ui->allWidget->setColumnCount(headers.size());
    ui->allWidget->setHorizontalHeaderLabels(headers);

    ProductManager& productManager = ProductManager::getInstance();
    QMap<QString, Product*> productCatalog;
    productCatalog = productManager.getProductMap();

    ui->allWidget->setRowCount(productCatalog.size());
    auto it = productCatalog.constBegin();
    for (int row=0; row<productCatalog.size(); ++row, ++it) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
        QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
        QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
        ui->allWidget->setItem(row, 0, nameItem);
        ui->allWidget->setItem(row, 1, idItem);
        ui->allWidget->setItem(row, 2, priceItem);
        ui->allWidget->setItem(row, 3, categoryItem);
    }
    // int row = 0;
    // QTableWidgetItem *nameItem = new QTableWidgetItem("it.value()->getProductName()");
    // ui->allWidget->setItem(row, 0, nameItem);
    // qDebug() << it.value()->getProductName();
}

AdminProductForm::~AdminProductForm() {
    delete ui;
}

void AdminProductForm::on_toolBox_currentChanged(int index) {
    ui->stackedWidget->setCurrentIndex(index);
    //qDebug() << tr("QToolBox 페이지 변경됨 -> 인덱스:") << index << tr(", QStackedWidget 페이지 변경됨.");
}

