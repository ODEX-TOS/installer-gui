#ifndef YAML_H
#define YAML_H

#include <QObject>
#include <vector>
#include "model/disk.h"
#include "model/network.h"
#include "model/system.h"
#include "model/user.h"


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


    // set the data variable to contain the entire yaml file (without the tos specific stuff) aka the model
    void setData();
    QString getStandard();


signals:

public slots:
private:
    std::vector<model::disk> disk;
    // a vector of vectors containing partitions
    // the first index is the disk
    // the second index are the partitions of that disk
    std::vector<std::vector<model::partition>> partitions;

    model::network network;
    model::system system;
    model::user user;
    QString data = "models:\n";

    QString partitionDisks();
    QString formatDisks();
    QString mountDisks();

};

#endif // YAML_H
