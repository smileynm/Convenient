#include "login.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "jsonmanager.h"
#include "membermanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Convenient_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // JsonManager bringup
    JsonManager *json = new JsonManager;
    MemberManager *member = new MemberManager;
    json->loadMemberFromJson(*member, "members.json");
    LogIn *login = new LogIn;
    login->show();
    return a.exec();
}
