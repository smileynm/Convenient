#include "member.h"

Member::Member(QString memberID, QString memberName, QString memberPW) :
    m_memberID(memberID), m_memberName(memberName), m_memberPW(memberPW) {
    if (memberID == "admin")
        this->managerFlag = true;
    else
        this->managerFlag = false;
}

Member::~Member() {
}

QString Member::getMemberID() {
    return m_memberID;
}

QString Member::getMemberName() {
    return m_memberName;
}

bool Member::isManager() {
    return managerFlag;
}

QJsonObject Member::toJson() const {
    QJsonObject obj;
    obj["id"] = m_memberID;
    obj["password"] = m_memberPW;
    obj["name"] = m_memberName;
    obj["isManager"] = managerFlag;

    return obj;
}
