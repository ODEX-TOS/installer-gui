#include "resizepartition.h"

namespace model {
    resizePartition::resizePartition(QString name, QString mountpoint, QString filesystem, QString size) : partition(name, mountpoint, filesystem){
        this->size = size;
    }
    resizePartition::resizePartition(QString name, QString mountpoint, QString filesystem, int offset, QString size): partition(name, mountpoint, filesystem, offset){
        this->size = size;
    }
    QString resizePartition::getSize(){
        return this->size;
    }
}
