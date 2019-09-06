#include "yaml.h"
#include <QFile>
#include <QCoreApplication>

QString getResourcesPath()
{
#if defined(Q_OS_WIN)
    return QCoreApplication::applicationDirPath() + "/";
#elif defined(Q_OS_OSX)
    return QCoreApplication::applicationDirPath() + "/../Resources/";
#elif defined(Q_OS_LINUX)
    return QCoreApplication::applicationDirPath() + "/../share/installer/";
#else
    return QCoreApplication::applicationDirPath() + "/";
#endif
}

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
    this->data += this->system.toYaml();
}
void yaml::setUser(QString name, QString password){
    this->user = model::user(name, password);
    this->data += this->user.toYaml();
}

QString yaml::getStandard(){
    QFile file("/home/zeus/tos/installer-gui/config/standard.yaml");
    // if the file is not openend then this string is isn't changed
    QString data = "Error";
    if(file.open(QIODevice::ReadOnly)) {
        data = file.readAll();
        // If multiple disks are used then the partitiontable, format and mount entries must be duplicated
        data.replace("#disk#", "/dev/sda/replace");
        data.replace("#user#", "user/replace");
    }
    return data;
}


