#ifndef MEMBERMANAGER_H
#define MEMBERMANAGER_H

#include <QString>
#include <QObject>
#include <QMap>
#include "Member.h"

class MemberManager :public QObject {
    Q_OBJECT

public:
    static MemberManager& getInstance();
    bool registerMember(Member* member, const QString& memberID);
    Member* findMemberByID(const QString& memberID);
    bool removeMember(const QString& memberID);

private:
    // 싱글턴 구현을 위한 생성자/소멸자의 private 접근제한
    MemberManager();
    ~MemberManager();

    // 싱글턴 구현을 위한 복사 생성자 및 대입 연산자 삭제
    MemberManager(const MemberManager&) = delete;
    MemberManager& operator=(const MemberManager&) = delete;

    QMap<QString, Member*> membersByID;
};

#endif // MEMBERMANAGER_H
