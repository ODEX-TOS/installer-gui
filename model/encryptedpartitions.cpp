#include "encryptedpartitions.h"

namespace model {
    encryptedPartitions::encryptedPartitions(QString name, QString mountpoint, QString start, QString end, QString encryptionPassword, std::vector<model::logicvolume> logicvolumes) : partition(name, mountpoint, "luks", start, end){
        this->encryptionPassword = encryptionPassword;
        this->logicvolumes = logicvolumes;
    }
    encryptedPartitions::encryptedPartitions(QString name, QString mountpoint, QString start, QString end, int offset, QString encryptionPassword, std::vector<model::logicvolume> logicvolumes): partition(name, mountpoint, "luks", start, end, offset){
        this->encryptionPassword = encryptionPassword;
        this->logicvolumes = logicvolumes;
    }
    QString encryptedPartitions::getPassword(){
           return this->encryptionPassword;
    }

    QString encryptedPartitions::toYaml() {
        if (this->getOffset() != -1){
            return "\t\t\t\t- partition:\n"
                   "\t\t\t\t\tname: \"" + this->getName() + "\"\n"
                   "\t\t\t\t\tmountpoint: \"" + this->getMountpoint() + "\"\n"
                   "\t\t\t\t\tfilesystem: \"" + this->getFilesystem() + "\"\n"
                   "\t\t\t\t\tstart: \"" + this->getStart() + "\"\n"
                   "\t\t\t\t\tend: \"" + this->getEnd() + "\"\n"
                   "\t\t\t\t\toffset: " + QString::number(this->getOffset()) + "\n"
                   "\t\t\t\t\tencrypted: true\n"
                   "\t\t\t\t\tpassword: \"" + this->encryptionPassword + "\"\n"
                   "\t\t\t\t\tlogicvolumes:\n" + this->logicVolumesToYaml();
        }
        return "\t\t\t\t- partition:\n"
               "\t\t\t\t\tname: \"" + this->getName() + "\"\n"
               "\t\t\t\t\tmountpoint: \"" + this->getMountpoint() + "\"\n"
               "\t\t\t\t\tfilesystem: \"" + this->getFilesystem() + "\"\n"
               "\t\t\t\t\tstart: \"" + this->getStart() + "\"\n"
               "\t\t\t\t\tend: \"" + this->getEnd() + "\"\n"
               "\t\t\t\t\tencrypted: true\n"
               "\t\t\t\t\tpassword: \"" + this->encryptionPassword + "\"\n"
               "\t\t\t\t\tlogicvolumes:\n" + this->logicVolumesToYaml();
    }

    QString  encryptedPartitions::logicVolumesToYaml(){
        QString data = "";
        for(model::logicvolume item : this->logicvolumes){
            data += item.toYaml();
        }
        return data;
    }
}
