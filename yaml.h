#ifndef YAML_H
#define YAML_H

#include <QObject>
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
        return this->data + this->getStandard();
    }

    Q_INVOKABLE void setDisk(QString device, QString size, bool bIsGPT, bool bIsNewPartitionTable, std::vector<model::partition> partitions);
    Q_INVOKABLE void setNetwork(QString ssid, QString password);
    Q_INVOKABLE void setSystem(QString local, QString keymap, QString rootpwd, QString hostname);
    Q_INVOKABLE void setUser(QString name, QString password);
    QString getStandard();


signals:

public slots:
private:
    model::disk disk;
    model::network network;
    model::system system;
    model::user user;
    QString data = "models:\n";

};

#endif // YAML_H
