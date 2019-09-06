#include "user.h"

namespace model {

    user::user(QString name, QString password){
        this->name = name;
        this->password = password;
    }
    user::user(QString name, QString password, QString shell){
        this->name = name;
        this->password = password;
        this->shell = shell;
    }

    QString user::getName(){
        return this->name;
    }
    QString user::getPassword(){
        return this->password;
    }

    QString user::getShell(){
        return this->shell;
    }

}
