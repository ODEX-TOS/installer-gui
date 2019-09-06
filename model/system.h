#ifndef SYSTEM_H
#define SYSTEM_H

#include <QString>

namespace model {

    class system
    {
    public:
        system(){}
        system(QString local, QString keymap, QString rootpwd);
        system(QString local, QString keymap, QString rootpwd, QString hostname);

        QString getLocal();
        QString getKeymap();
        QString getRootPWD();
        QString getHostname();
        QString toYaml();

    private:
        // always provide a local
        QString local = "en_US.UTF-8";
        // always provide a keymap
        QString keymap="us";
        // always provided the root password
        QString rootpwd;
        // default hostname
        QString hostname = "tos";
    };
}
#endif // SYSTEM_H
