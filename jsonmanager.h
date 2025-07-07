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

class JsonManager
{
public:
    JsonManager();

    bool loadMemberFromJson(MemberManager& memberManager, const QString& filePath);
    //bool loadProductFromJson(const QString& filePath);
    bool saveMemberToJson(const Member*);
    //bool saveProductToJson(const Product*);
};

#endif // JSONMANAGER_H
