#include "product.h"

Product::Product(QString productName, QString productID, QString productPrice, QString productCategory) :
    m_productName(productName), m_productID(productID), m_productPrice(productPrice), m_productCategory(productCategory) {
}

Product::~Product() {
}

QString Product::getProductName() {
    return m_productName;
}

QString Product::getProductID() {
    return m_productID;
}

QString Product::getProductPrice() {
    return m_productPrice;
}

QString Product::getProductCategory() {
    return m_productCategory;
}
