#include "logicvolume.h"

namespace model {
    logicvolume::logicvolume(QString name, QString size, QString mountpoint){
        this->name = name;
        this->size = size;
        this->mountpoint = mountpoint;
    }
    QString logicvolume::getName(){
        return this->name;
    }
    QString logicvolume::getSize(){
        return this->size;
    }
    QString logicvolume::getMountPoint(){
        return this->mountpoint;
    }

    QString logicvolume::toYaml(){
        return "\t\t\t\t\t\t- volume:\n"
               "\t\t\t\t\t\t\tname: \"" + this->name + "\"\n"
               "\t\t\t\t\t\t\tsize: \"" + this->size + "\"\n"
               "\t\t\t\t\t\t\tmountpoint: \"" + this->getMountPoint() + "\"\n";
    }
}

