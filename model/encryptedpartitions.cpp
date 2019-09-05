#include "encryptedpartitions.h"

namespace model {
    encryptedPartitions::encryptedPartitions(QString name, QString mountpoint, EFilesystem filesystem, QString start, QString end, QString encryptionPassword, std::vector<model::logicvolume> logicvolumes) : partition(name, mountpoint, filesystem, start, end){
        this->encryptionPassword = encryptionPassword;
        this->logicvolumes = logicvolumes;
    }
    encryptedPartitions::encryptedPartitions(QString name, QString mountpoint, EFilesystem filesystem, QString start, QString end, int offset, QString encryptionPassword, std::vector<model::logicvolume> logicvolumes): partition(name, mountpoint, filesystem, start, end, offset){
        this->encryptionPassword = encryptionPassword;
        this->logicvolumes = logicvolumes;
    }
    QString encryptedPartitions::getPassword(){
           return this->encryptionPassword;
    }
}
