#include "disk.h"
namespace model {
    disk::disk(QString device, QString size, bool bIsGPT, bool bIsNewPartitionTable, std::vector<model::partition> partitions){
        this->device = device;
        this->size = size;
        this->bIsGPT = bIsGPT;
        this->bIsNewPartitionTable = bIsNewPartitionTable;
        this->partitions = partitions;
    }
    QString disk::getDevice(){
        return this->device;
    }
    QString disk::getSize(){
        return this->size;
    }
    bool disk::isGPT(){
        return this->bIsGPT;
    }
    bool disk::isNewPartitionTable(){
        return this->bIsNewPartitionTable;
    }
    std::vector<model::partition> disk::getPartitions(){
        return this->partitions;
    }
}
