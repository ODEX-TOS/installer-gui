#ifndef ENCRYPTEDPARTITIONS_H
#define ENCRYPTEDPARTITIONS_H

#include "partition.h"
#include <QString>

namespace model {
    class encryptedPartitions : partition
    {
    public:
        encryptedPartitions(QString name, QString mountpoint, EFilesystem filesystem, QString start, QString end, QString encryptionPassword, std::vector<model::logicvolume> logicvolumes);
        encryptedPartitions(QString name, QString mountpoint, EFilesystem filesystem, QString start, QString end, int offset, QString encryptionPassword, std::vector<model::logicvolume> logicvolumes);
        QString getPassword();
        bool isEncrypted() override {return true;}
    private:
        // used for encrypted partitions
        QString encryptionPassword;
        std::vector<model::logicvolume> logicvolumes;
    };
}

#endif // ENCRYPTEDPARTITIONS_H