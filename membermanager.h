#ifndef MEMBERMANAGER_H
#define MEMBERMANAGER_H

#include <QVector>
#include <QMap>
#include "Member.h"

class MemberManager
{
public:
    MemberManager();
    ~MemberManager();

    bool registerMember(Member* member, const QString& memberID);
    Member* findMemberByID(const QString& memberID);
    bool removeMember(const QString& memberID);

private:
    QMap<QString, Member*> membersByID;
};

#endif // MEMBERMANAGER_H
