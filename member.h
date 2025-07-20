#ifndef MEMBER_H
#define MEMBER_H

#include <QString>
#include <QJsonObject>

class Member {
public:
    Member(QString memberID, QString memberName, QString memberPW);
    ~Member();
    QString getMemberID();
    QString getMemberName();
    bool isManager();
    void setManager(bool managerFlag);
    QJsonObject toJson() const;

private:
    QString m_memberName;
    QString m_memberID;
    QString m_memberPW;
    bool managerFlag;
};

#endif // MEMBER_H
