// normalorderform.cpp

#include "normalorderform.h"
#include "ui_normalorderform.h"
#include "productmanager.h"

NormalOrderForm::NormalOrderForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalOrderForm) {
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(6);

    QStringList headers;
    headers << "상품명" << "상품ID" << "가격" << "카테고리";
    ui->allWidget->setColumnCount(headers.size());
    ui->allWidget->setHorizontalHeaderLabels(headers);
    ui->beverageWidget->setColumnCount(headers.size());
    ui->beverageWidget->setHorizontalHeaderLabels(headers);
    ui->snackWidget->setColumnCount(headers.size());
    ui->snackWidget->setHorizontalHeaderLabels(headers);
    ui->instantWidget->setColumnCount(headers.size());
    ui->instantWidget->setHorizontalHeaderLabels(headers);
    ui->milkiceWidget->setColumnCount(headers.size());
    ui->milkiceWidget->setHorizontalHeaderLabels(headers);
    ui->drinkWidget->setColumnCount(headers.size());
    ui->drinkWidget->setHorizontalHeaderLabels(headers);
    ui->neceWidget->setColumnCount(headers.size());
    ui->neceWidget->setHorizontalHeaderLabels(headers);
    ui->orderWidget->setColumnCount(headers.size());
    ui->orderWidget->setHorizontalHeaderLabels(headers);

    ProductManager& productManager = ProductManager::getInstance();
    QMap<QString, Product*> productCatalog;
    productCatalog = productManager.getProductMap();

    ui->allWidget->setRowCount(productCatalog.size());
    ui->beverageWidget->setRowCount(productCatalog.size());
    ui->snackWidget->setRowCount(productCatalog.size());
    ui->instantWidget->setRowCount(productCatalog.size());
    ui->milkiceWidget->setRowCount(productCatalog.size());
    ui->drinkWidget->setRowCount(productCatalog.size());
    ui->neceWidget->setRowCount(productCatalog.size());
    ui->orderWidget->setRowCount(orderCount);

    ui->allWidget->setColumnWidth(0, 250);
    ui->beverageWidget->setColumnWidth(0, 250);
    ui->snackWidget->setColumnWidth(0, 250);
    ui->instantWidget->setColumnWidth(0, 250);
    ui->milkiceWidget->setColumnWidth(0, 250);
    ui->drinkWidget->setColumnWidth(0, 250);
    ui->neceWidget->setColumnWidth(0, 250);
    ui->orderWidget->setColumnWidth(0, 250);

    auto it = productCatalog.constBegin();
    int beverageRow = 0;
    int snackRow = 0;
    int instantRow = 0;
    int milkRow = 0;
    int drinkRow = 0;
    int neceRow = 0;

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


    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "음료") {
            QTableWidgetItem *beverageName = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *beverageID = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *beveragePrice = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *beverageCategory = new QTableWidgetItem(it.value()->getProductCategory());
            ui->beverageWidget->setItem(beverageRow, 0, beverageName);
            ui->beverageWidget->setItem(beverageRow, 1, beverageID);
            ui->beverageWidget->setItem(beverageRow, 2, beveragePrice);
            ui->beverageWidget->setItem(beverageRow, 3, beverageCategory);
            beverageRow++;
        }
    }

    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "스낵") {
            QTableWidgetItem *snackName = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *snackID = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *snackPrice = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *snackCategory = new QTableWidgetItem(it.value()->getProductCategory());
            ui->snackWidget->setItem(snackRow, 0, snackName);
            ui->snackWidget->setItem(snackRow, 1, snackID);
            ui->snackWidget->setItem(snackRow, 2, snackPrice);
            ui->snackWidget->setItem(snackRow, 3, snackCategory);
            snackRow++;
        }
    }

    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "즉석식품") {
            QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
            ui->instantWidget->setItem(instantRow, 0, nameItem);
            ui->instantWidget->setItem(instantRow, 1, idItem);
            ui->instantWidget->setItem(instantRow, 2, priceItem);
            ui->instantWidget->setItem(instantRow, 3, categoryItem);
            instantRow++;
        }
    }

    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "유제품/아이스크림") {
            QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
            ui->milkiceWidget->setItem(milkRow, 0, nameItem);
            ui->milkiceWidget->setItem(milkRow, 1, idItem);
            ui->milkiceWidget->setItem(milkRow, 2, priceItem);
            ui->milkiceWidget->setItem(milkRow, 3, categoryItem);
            milkRow++;
        }
    }

    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "주류") {
            QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
            ui->drinkWidget->setItem(drinkRow, 0, nameItem);
            ui->drinkWidget->setItem(drinkRow, 1, idItem);
            ui->drinkWidget->setItem(drinkRow, 2, priceItem);
            ui->drinkWidget->setItem(drinkRow, 3, categoryItem);
            drinkRow++;
        }
    }

    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "생활용품") {
            QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
            ui->neceWidget->setItem(neceRow, 0, nameItem);
            ui->neceWidget->setItem(neceRow, 1, idItem);
            ui->neceWidget->setItem(neceRow, 2, priceItem);
            ui->neceWidget->setItem(neceRow, 3, categoryItem);
            neceRow++;
        }
    }

    ui->beverageWidget->setRowCount(beverageRow);
    ui->snackWidget->setRowCount(snackRow);
    ui->instantWidget->setRowCount(instantRow);
    ui->milkiceWidget->setRowCount(milkRow);
    ui->drinkWidget->setRowCount(drinkRow);
    ui->neceWidget->setRowCount(neceRow);

    ui->allWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->beverageWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->snackWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->instantWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->milkiceWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->drinkWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->neceWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->toolBox->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(6);

    connect(ui->allWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->beverageWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->snackWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->instantWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->milkiceWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->drinkWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->neceWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
}

NormalOrderForm::~NormalOrderForm() {
    delete ui;
}

void NormalOrderForm::on_toolBox_currentChanged(int index) {
    ui->stackedWidget->setCurrentIndex(index);
    //qDebug() << tr("QToolBox 페이지 변경됨 -> 인덱스:") << index << tr(", QStackedWidget 페이지 변경됨.");
}

void NormalOrderForm::onItemDoubleClicked(QTableWidgetItem *item) {
    int row = item->row();
    QTableWidgetItem *nameItem = new QTableWidgetItem();
    QTableWidgetItem *idItem = new QTableWidgetItem();
    QTableWidgetItem *priceItem = new QTableWidgetItem();
    QTableWidgetItem *categoryItem = new QTableWidgetItem();

    nameItem->setText(item->tableWidget()->item(row, 0)->text());
    idItem->setText(item->tableWidget()->item(row, 1)->text());
    priceItem->setText(item->tableWidget()->item(row, 2)->text());
    categoryItem->setText(item->tableWidget()->item(row, 3)->text());

    qDebug() << nameItem->text() << idItem->text() << priceItem->text() << categoryItem->text();

    increaseOrderCount();
    ui->orderWidget->setRowCount(getOrderCount());
    qDebug() << getOrderCount();
    ui->orderWidget->setItem(getOrderCount()-1, 0, nameItem);
    ui->orderWidget->setItem(getOrderCount()-1, 1, idItem);
    ui->orderWidget->setItem(getOrderCount()-1, 2, priceItem);
    ui->orderWidget->setItem(getOrderCount()-1, 3, categoryItem);
}

int NormalOrderForm::getOrderCount() {
    return orderCount;
}

void NormalOrderForm::increaseOrderCount() {
    orderCount++;
}

void NormalOrderForm::decreaseOrderCount() {
    orderCount--;
}
