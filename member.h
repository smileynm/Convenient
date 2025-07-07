#ifndef MEMBER_H
#define MEMBER_H

#include <QString>

class Member
{
public:
    Member(QString memberID, QString memberName, QString memberPW);
    ~Member();
    QString getMemberID();
    QString getMemberName();
    bool isManager();
    void setManager(bool managerFlag);

private:
    QString m_memberName;
    QString m_memberID;
    QString m_memberPW;
    bool managerFlag;
};

#endif // MEMBER_H
