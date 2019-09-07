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

    QString resizePartition::toYaml() {
        if (this->getOffset() == -1 ){
            return "\t\t\t\t- partition:\n"
                   "\t\t\t\t\tname: \"" + this->getName() + "\"\n"
                   "\t\t\t\t\tmountpoint: \"" + this->getMountpoint() + "\"\n"
                   "\t\t\t\t\tfilesystem: \"" + this->getFilesystem() + "\"\n"
                   "\t\t\t\t\tsize: \"" + this->size + "\"\n";

        }
        return "\t\t\t\t- partition:\n"
               "\t\t\t\t\tname: \"" + this->getName() + "\"\n"
               "\t\t\t\t\tmountpoint: \"" + this->getMountpoint() + "\"\n"
               "\t\t\t\t\tfilesystem: \"" + this->getFilesystem() + "\"\n"
               "\t\t\t\t\tsize: \"" + this->size + "\"\n"
               "\t\t\t\t\toffset: " + QString::number(this->getOffset()) + "\n";
    }
}
