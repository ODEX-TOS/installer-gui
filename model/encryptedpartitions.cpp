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
            return "            - partition:\n"
                   "               name: \"" + this->getName() + "\"\n"
                   "               mount: \"" + this->getMountpoint() + "\"\n"
                   "               filesystem: \"" + this->getFilesystem() + "\"\n"
                   "               start: \"" + this->getStart() + "\"\n"
                   "               end: \"" + this->getEnd() + "\"\n"
                   "               offset: " + QString::number(this->getOffset()) + "\n"
                   "               encrypted: true\n"
                   "               password: \"" + this->encryptionPassword + "\"\n"
                   "               logicvolumes:\n" + this->logicVolumesToYaml();
        }
        return "            - partition:\n"
               "               name: \"" + this->getName() + "\"\n"
               "               mount: \"" + this->getMountpoint() + "\"\n"
               "               filesystem: \"" + this->getFilesystem() + "\"\n"
               "               start: \"" + this->getStart() + "\"\n"
               "               end: \"" + this->getEnd() + "\"\n"
               "               encrypted: true\n"
               "               password: \"" + this->encryptionPassword + "\"\n"
               "               logicvolumes:\n" + this->logicVolumesToYaml();
    }

    QString  encryptedPartitions::logicVolumesToYaml(){
        QString data = "";
        for(model::logicvolume item : this->logicvolumes){
            data += item.toYaml();
        }
        return data;
    }
}
