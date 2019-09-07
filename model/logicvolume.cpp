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
        return "                  - volume:\n"
               "                     name: \"" + this->name + "\"\n"
               "                     size: \"" + this->size + "\"\n"
               "                     mountpoint: \"" + this->getMountPoint() + "\"\n";
    }
}

