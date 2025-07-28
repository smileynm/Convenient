// productmanager.cpp

#include "productmanager.h"

ProductManager& ProductManager::getInstance() {
    static ProductManager instance;
    return instance;
}

ProductManager::ProductManager() {
    qDebug() << QObject::tr("ProductManager created.");
}

ProductManager::~ProductManager() {
    for (auto it = productsByName.begin(); it != productsByName.end(); ++it) {
        QString productName = it.key();
        Product* product = it.value();
        qDebug() << QObject::tr("Deleting product: %1 %2").arg(product->getProductName()).arg(product->getProductID());
        delete product; // Product 객체의 메모리 해제
    }
    productsByName.clear(); // 맵 비우기
    qDebug() << QObject::tr("ProductManager destroyed.");
}

bool ProductManager::registerProduct(Product* product, const QString& productName) {
    if (productsByName.count(productName)) {
        qDebug() << QObject::tr("Error: Already exist Product");
        return false;
    }
    productsByName[productName] = product;
    qDebug() << QObject::tr("Product registered: %1 %2").arg(product->getProductName()).arg(product->getProductID());
    return true;
}

bool ProductManager::removeProduct(const QString& productName) {
    // 맵에서 이름으로 상품 찾기
    auto it = productsByName.find(productName);
    if (it == productsByName.end()) {
        qDebug() << QObject::tr("Error: Product with Name %1").arg(productName) << " not found for removal.";
        return false; // 해당 상품이 없으면 삭제 실패
    }

    // 찾은 Product 객체의 메모리 해제
    delete it.value();

    // 맵에서 해당 상품 제거
    productsByName.erase(it);
    qDebug() << QObject::tr("Product removed: %1").arg(productName);
    return true; // 탈퇴 성공
}

Product* ProductManager::findProductByCategory(const QString& productCategory) {
    auto it = productsByName.find(productCategory);
    if (it != productsByName.end()) {
        return it.value();
    }
    return nullptr;
}

const QMap<QString, Product*>& ProductManager::getProductMap() const {
    return productsByName;
}
