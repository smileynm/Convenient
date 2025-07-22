#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QJsonObject>

class Product {
public:
    Product(QString productName, QString productID, QString productPrice, QString productCategory);
    ~Product();
    QString getProductName();
    QString getProductID();
    QString getProductPrice();
    QString getProductCategory();

private:
    QString m_productName;
    QString m_productID;
    QString m_productPrice;
    QString m_productCategory;
};

#endif // PRODUCT_H
