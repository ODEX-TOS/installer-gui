#ifndef DISK_H
#define DISK_H

#include <QString>
#include <vector>
#include "partition.h"

namespace model {
    class disk
    {
    public:
        disk(){}
        disk(QString device, QString size, bool bIsGPT, bool bIsNewPartitionTable, std::vector<model::partition> partitions);
        QString getDevice();
        QString getSize();
        bool isGPT();
        bool isNewPartitionTable();
        std::vector<model::partition> getPartitions();
        QString toYaml();
    private:
        QString device;
        QString size;
        bool bIsGPT;
        bool bIsNewPartitionTable;
        std::vector<model::partition> partitions;
    };
}


#endif // DISK_H
