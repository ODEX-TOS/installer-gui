#ifndef YAML_H
#define YAML_H

#include <QObject>
#include <vector>

#include "model/disk.h"
#include "model/network.h"
#include "model/system.h"
#include "model/user.h"

#include "model/resizepartition.h"
#include "model/encryptedpartitions.h"


class yaml : public QObject
{
    Q_OBJECT
public:
    explicit yaml(QObject *parent = nullptr);
    // return a full yaml config
    Q_INVOKABLE QString getConfig(){
        setData();
        return this->data + this->getStandard();
    }

    Q_INVOKABLE void addDisk(QString device, QString size, bool bIsGPT, bool bIsNewPartitionTable, unsigned long diskid);
    Q_INVOKABLE void setNetwork(QString ssid, QString password);
    Q_INVOKABLE void setSystem(QString local, QString keymap, QString rootpwd, QString hostname);
    Q_INVOKABLE void setUser(QString name, QString password);

    // add partitions to a disk
    Q_INVOKABLE void addPartition(unsigned long  disk, QString name, QString mountpoint, QString filesystem, QString start, QString end, int offset);
    Q_INVOKABLE void addPartition(unsigned long  disk, QString name, QString mountpoint, QString filesystem, QString start, QString end);

    // add partitions that need to be resized
    // if you use this then your disk must be marked as bIsNewPartitionTable = false; otherwise you can't resize
    Q_INVOKABLE void addResizePartition(unsigned long  disk, QString name, QString mountpoint, QString filesystem, QString size, int offset);
    Q_INVOKABLE void addResizePartition(unsigned long  disk, QString name, QString mountpoint, QString filesystem, QString size);

    Q_INVOKABLE void addEncryptionPartition(unsigned long  disk, unsigned long logicvolumeID, QString password, QString name, QString mountpoint, QString start, QString end, int offset);
    Q_INVOKABLE void addEncryptionPartition(unsigned long  disk, unsigned long logicvolumeID, QString password, QString name, QString mountpoint, QString start, QString end);

    Q_INVOKABLE void addLogicVolume(unsigned long groupid, QString name, QString size, QString mountpoint);


    // set the data variable to contain the entire yaml file (without the tos specific stuff) aka the model
    void setData();
    QString getStandard();

    // generate the shell script
    void execute(QString file="run.sh");


signals:

public slots:
private:
    std::vector<model::disk> disk;
    // a vector of vectors containing partitions
    // the first index is the disk
    // the second index are the partitions of that disk
    std::vector<std::vector<model::partition*>> partitions;

    // a matrix of logic volumes
    // the first index is represents a logicvolume group
    // the second index represent all the logic volumes
    std::vector<std::vector<model::logicvolume>> volumes;


    model::network network;
    model::system system;
    model::user user;
    QString data = "models:\n";

    QString partitionDisks();
    QString formatDisks();
    QString mountDisks();

};

#endif // YAML_H
