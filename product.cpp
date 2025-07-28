// product.cpp

#include "product.h"

Product::Product(QString productName, QString productID, int productPrice, QString productCategory) :
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

int Product::getProductPrice() {
    return m_productPrice;
}

QString Product::getProductCategory() {
    return m_productCategory;
}
