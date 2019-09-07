#ifndef ENCRYPTEDPARTITIONS_H
#define ENCRYPTEDPARTITIONS_H

#include "partition.h"
#include <QString>

namespace model {
    class encryptedPartitions : public partition
    {
    public:
        encryptedPartitions(QString name, QString mountpoint, QString start, QString end, QString encryptionPassword, std::vector<model::logicvolume> logicvolumes);
        encryptedPartitions(QString name, QString mountpoint, QString start, QString end, int offset, QString encryptionPassword, std::vector<model::logicvolume> logicvolumes);
        QString getPassword();
        bool isEncrypted() override {return true;}
        QString toYaml() override;
    private:
        QString logicVolumesToYaml();
        // used for encrypted partitions
        QString encryptionPassword;
        std::vector<model::logicvolume> logicvolumes;
    };
}

#endif // ENCRYPTEDPARTITIONS_H
