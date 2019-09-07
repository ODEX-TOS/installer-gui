#include "disk.h"

QString boolToYaml(bool value) {
    if(value){
        return "true";
    }
    return "false";
}

namespace model {
    disk::disk(QString device, QString size, bool bIsGPT, bool bIsNewPartitionTable, std::vector<model::partition*> partitions){
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
    std::vector<model::partition*> disk::getPartitions(){
        return this->partitions;
    }
    QString disk::toYaml(){
        QString partitions = "";
        for (model::partition* item : this->partitions) {
            partitions += (*item).toYaml();
        }
        return "\t\t- disk:\n"
               "\t\t\tdevice: \"" + this->device + "\"\n"
               "\t\t\tsize: \"" + this->size + "\"\n"
               "\t\t\tgpt: " + boolToYaml(this->bIsGPT) + "\n"
               "\t\t\ttable: " + boolToYaml(this->bIsNewPartitionTable) + "\n"
               "\t\t\tpartitions:\n" +
                partitions + "\n";


    }

}
