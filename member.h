#ifndef MEMBER_H
#define MEMBER_H

#include <QString>

class Member
{
public:
    Member();
    ~Member();
    QString getMemberID();
    bool isManager(Member);

private:
    QString memberName;
    QString memberID;
    QString memberPW;
    bool managerFlag;
};

#endif // MEMBER_H
