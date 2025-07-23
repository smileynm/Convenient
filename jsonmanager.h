#ifndef JSONMANAGER_H
#define JSONMANAGER_H
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <QFile>
#include <QIODevice>
#include <QDebug>

#include "membermanager.h"
#include "productmanager.h"

class JsonManager {
public:
    JsonManager();

    bool loadMemberFromJson(MemberManager& memberManager, const QString& filePath);
    bool loadProductFromJson(ProductManager& productManager, const QString& filePath);
    bool addMemberToJson(QString id, QString name, QString pw);
    //bool saveProductToJson(const Product*);
};

#endif // JSONMANAGER_H
