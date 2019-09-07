#include "network.h"

namespace model {
    network::network(QString ssid, QString password){
        this->ssid = ssid;
        this->password = password;
    }
    QString network::getSSID(){
        return this->ssid;
    }
    QString network::getPassword(){
        return this->password;
    }
    QString network::toYaml(){
        return "\t- network:\n"
               "\t\tssid: \"" + this->ssid + "\"\n"
               "\t\tpassword: \"" + this->password + "\"\n";
    }

}
