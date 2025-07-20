#include "jsonmanager.h"

JsonManager::JsonManager() {
}

bool JsonManager::loadMemberFromJson(MemberManager& memberManager, const QString& filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray jsonData = file.readAll();
        file.close();

        // 읽은 데이터로 Json 파싱
        QJsonDocument doc = QJsonDocument::fromJson(jsonData);
        //if (doc.isNull() || !doc.isArray()) {
        if (doc.isNull() || !doc.isArray()) {
            qDebug() << "유효하지 않은 Json 파일이 로드됨";
            return false;
        }

        // JsonArray에 Obj 형태로 저장
        QJsonArray membersArray = doc.array();
        for (auto it = membersArray.begin(); it != membersArray.end(); ++it) {
            if (!it->isObject())
                continue;
            QJsonObject memberObj = it->toObject();
            QString id = memberObj["id"].toString();
            QString password = memberObj["password"].toString();
            QString name = memberObj["name"].toString();

            Member* member = new Member(id, name, password);
            memberManager.registerMember(member, id);

            // 확인을 위한 qDebug Line
            qDebug() << member->getMemberID() << "registered.";
        }
        return true;
    } else {
        qDebug() << "Cannot open File:" << filePath;
        return false;
    }
}

bool JsonManager::addMemberToJson(QString id, QString name, QString pw) {
    QFile file("members.json");
    QJsonObject newMember;
    newMember["id"] = id;
    newMember["isManager"] = false;
    newMember["name"] = name;
    newMember["password"] = pw;

    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QByteArray memberData = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(memberData);
        if (doc.isNull() || !doc.isArray()) {
            qDebug() << "유효하지 않은 Json 파일이 로드됨";
            return false;
        }
        QJsonArray memberArray = doc.array();
        memberArray.append(newMember);
        doc = QJsonDocument(memberArray);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Cannot open File";
            return false;
        }
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();

        return true;
    } else {
        qDebug() << "Cannot open File";
        file.close();
        return false;
    }
}
