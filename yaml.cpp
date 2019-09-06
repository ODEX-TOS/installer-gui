#include "yaml.h"

yaml::yaml(QObject *parent) : QObject(parent)
{
}

void yaml::setDisk(QString device, QString size, bool bIsGPT, bool bIsNewPartitionTable, std::vector<model::partition> partitions){
    this->disk = model::disk(device, size, bIsGPT, bIsNewPartitionTable, partitions);
}
void yaml::setNetwork(QString ssid, QString password){
    this->network = model::network(ssid, password);
    this->data += this->network.toYaml();
}
void yaml::setSystem(QString local, QString keymap, QString rootpwd, QString hostname){
    this->system = model::system(local, keymap, rootpwd, hostname);
}
void yaml::setUser(QString name, QString password){
    this->user = model::user(name, password);
}
