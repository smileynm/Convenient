QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminchatform.cpp \
    admininfoform.cpp \
    adminorderlistform.cpp \
    adminproductform.cpp \
    login.cpp \
    main.cpp \
    normal.cpp \
    signup.cpp

HEADERS += \
    admin.h \
    adminchatform.h \
    admininfoform.h \
    adminorderlistform.h \
    adminproductform.h \
    login.h \
    normal.h \
    signup.h

FORMS += \
    admin.ui \
    adminchatform.ui \
    admininfoform.ui \
    adminorderlistform.ui \
    adminproductform.ui \
    login.ui \
    normal.ui \
    signup.ui

TRANSLATIONS += \
    Convenient_ko_KR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
