#include "membermanager.h"
#include <QDebug>

MemberManager::MemberManager() {
    qDebug() << "MemberManager created.";
}

MemberManager::~MemberManager() {
    for (auto it = membersByID.begin(); it != membersByID.end(); ++it) {
        QString memberID = it.key();
        Member* member_ptr = it.value();
        qDebug() << "Deleting member: " << member_ptr->getMemberName() << " (" << memberID << ")";
        delete member_ptr; // Member 객체의 메모리 해제
    }
    membersByID.clear(); // 맵 비우기
    qDebug() << "MemberManager destroyed.";
}

bool MemberManager::registerMember(Member* member, const QString& id) {
    if (membersByID.count(id)) {
        qDebug() << "에러: 이미 있는 회원 ID";
        return false;
    }

    membersByID[id] = member;
    qDebug() << "회원가입 완료:" << member->getMemberName() << "(" << id;
    return true;
}

Member* MemberManager::findMemberByID(const QString& memberID) {
    auto it = membersByID.find(memberID);
    if (it != membersByID.end()) {
        return it.value();
    }

    return nullptr;
}

bool MemberManager::removeMember(const QString& memberID) {
    // 맵에서 ID로 회원 찾기
    auto it = membersByID.find(memberID);
    if (it == membersByID.end()) {
        qDebug() << "Error: Member with ID " << memberID << " not found for removal.";
        return false; // 회원이 없으면 탈퇴 실패
    }

    // 찾은 Member 객체의 메모리 해제
    delete it.value();

    // 맵에서 해당 항목 제거
    membersByID.erase(it);
    qDebug() << "Member removed: " << memberID;
    return true; // 탈퇴 성공
}
