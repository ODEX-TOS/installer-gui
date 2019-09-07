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
    // initialize the disk array
    this->disk = std::vector<model::disk>(0);
    this->partitions = std::vector<std::vector<model::partition*>>(1);
    this->volumes = std::vector<std::vector<model::logicvolume>>(1);
}

void yaml::addDisk(QString device, QString size, bool bIsGPT, bool bIsNewPartitionTable,  unsigned long diskid){
    this->disk.push_back(model::disk(device, size, bIsGPT, bIsNewPartitionTable, this->partitions[diskid]));
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

void yaml::setData(){
    // we can assume the disks vector exists since you are installing on at least one disk
    QString disk = "\t-disks:\n";
    for (model::disk item : this->disk) {
        disk += item.toYaml();
    }
    this->data = "models:\n" + disk + this->network.toYaml() + this->system.toYaml() + this->user.toYaml() + "\n";
}

QString yaml::getStandard(){
    // TODO: Move these files to a global state eg /usr/share, to be defined
    QFile file("/home/zeus/tos/installer-gui/config/standard.yaml");
    // if the file is not openend then this string is isn't changed
    QString data = "Error";
    if(file.open(QIODevice::ReadOnly)) {
        data = file.readAll();
        // If multiple disks are used then the partitiontable, format and mount entries must be duplicated
        data.replace(" - partitiontable: \"#disk#\"", this->partitionDisks());
        data.replace(" - format: \"#disk#\"", this->mountDisks());
        data.replace(" - mount: \"#disk#\"", this->formatDisks());
        data.replace("#disk#", this->disk[0].getDevice());
        data.replace("#user#", this->user.getName());
    }
    return data;
}

// add a partition to the partition disk, if such a disk doesn't exisit create one
void yaml::addPartition(unsigned long disk, QString name, QString mountpoint, QString filesystem, QString start, QString end, int offset){
    if (this->partitions.size() > disk) {
        this->partitions[disk].push_back(new model::partition(name, mountpoint, filesystem, start, end, offset));
        return;
    }
    while (this->partitions.size() < disk) {
        this->partitions.push_back(std::vector<model::partition*>());
    }
    this->partitions[disk].push_back(new model::partition(name, mountpoint, filesystem, start, end, offset));
}
// add a partition to the partition disk, if such a disk doesn't exist create one
void yaml::addPartition(unsigned long  disk, QString name, QString mountpoint, QString filesystem, QString start, QString end){
    if (this->partitions.size() > disk) {
        this->partitions[disk].push_back(new model::partition(name, mountpoint, filesystem, start, end));
        return;
    }
    while (this->partitions.size() < disk) {
        this->partitions.push_back(std::vector<model::partition*>());
    }
    this->partitions[disk].push_back(new model::partition(name, mountpoint, filesystem, start, end));
}

void yaml::addResizePartition(unsigned long  disk, QString name, QString mountpoint, QString filesystem, QString size, int offset){
       if (this->partitions.size() > disk) {
           this->partitions[disk].push_back(new model::resizePartition(name, mountpoint, filesystem, offset, size));
           return;
       }
       while (this->partitions.size() < disk) {
           this->partitions.push_back(std::vector<model::partition*>());
       }
       this->partitions[disk].push_back(new model::resizePartition(name, mountpoint, filesystem, offset, size));
}
void yaml::addResizePartition(unsigned long  disk, QString name, QString mountpoint, QString filesystem, QString size){
    if (this->partitions.size() > disk) {
        this->partitions[disk].push_back(new model::resizePartition(name, mountpoint, filesystem, size));
        return;
    }
    while (this->partitions.size() < disk) {
        this->partitions.push_back(std::vector<model::partition*>());
    }
    this->partitions[disk].push_back(new model::resizePartition(name, mountpoint, filesystem, size));
}

void yaml::addEncryptionPartition(unsigned long  disk, unsigned long logicvolumeID, QString password, QString name, QString mountpoint, QString start, QString end, int offset){
    if (this->partitions.size() > disk){
        this->partitions[disk].push_back(new model::encryptedPartitions(name, mountpoint, start, end, offset, password, this->volumes[logicvolumeID]));
        return;
    }
    while(this->partitions.size() < disk){
        this->partitions.push_back(std::vector<model::partition*>());
    }
    this->partitions[disk].push_back(new model::encryptedPartitions(name, mountpoint, start, end, offset, password, this->volumes[logicvolumeID]));

}
void yaml::addEncryptionPartition(unsigned long  disk, unsigned long logicvolumeID, QString password, QString name, QString mountpoint, QString start, QString end){
    if (this->partitions.size() > disk){
        this->partitions[disk].push_back(new model::encryptedPartitions(name, mountpoint, start, end, password, this->volumes[logicvolumeID]));
        return;
    }
    while(this->partitions.size() < disk){
        this->partitions.push_back(std::vector<model::partition*>());
    }
    this->partitions[disk].push_back(new model::encryptedPartitions(name, mountpoint, start, end, password, this->volumes[logicvolumeID]));
}

void yaml::addLogicVolume(unsigned long groupid, QString name, QString size, QString mountpoint) {
    if (this->volumes.size() > groupid){
       this->volumes[groupid].push_back(model::logicvolume(name, size, mountpoint));
       return;
    }
    while (this->volumes.size() > groupid) {
        this->volumes.push_back(std::vector<model::logicvolume>());
    }
    this->volumes[groupid].push_back(model::logicvolume(name, size, mountpoint));
}


QString yaml::partitionDisks(){
    QString data = "";
    for(model::disk item : this->disk){
        data += " - partitiontable: \"" + item.getDevice() + "\"\n";
    }
    return data;
}
QString yaml::formatDisks(){
    QString data = "";
    for(model::disk item : this->disk){
        data += " - format: \"" + item.getDevice() + "\"\n";
    }
    return data;
}
QString yaml::mountDisks(){
    QString data = "";
    for(model::disk item : this->disk){
        data += " - mount: \"" + item.getDevice() + "\"\n";
    }
    return data;
}

void yaml::execute(QString file){
    QFile out(file);
}


