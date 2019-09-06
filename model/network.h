#ifndef NETWORK_H
#define NETWORK_H

#include <QString>
namespace model {
    class network
    {
    public:
        network(){}
        network(QString ssid, QString password);
        QString getSSID();
        QString getPassword();
        QString toYaml();
    private:
        QString ssid;
        QString password;
    };
}

#endif // NETWORK_H
