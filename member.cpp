#include "member.h"

Member::Member() {
}

Member::~Member() {
}

QString Member::getMemberID() {
    return memberID;
}

QString Member::getMemberName() {
    return memberName;
}

bool Member::isManager() {
    return managerFlag;
}
