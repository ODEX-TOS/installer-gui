#ifndef RESIZEPARTITION_H
#define RESIZEPARTITION_H

#include "partition.h"
#include "QString"
namespace  model {
    class resizePartition : public partition
    {
    public:
        resizePartition(QString name, QString mountpoint, QString filesystem, QString size);
        resizePartition(QString name, QString mountpoint, QString filesystem, int offset, QString size);
        QString getSize();
        bool isResizable() override {return true;}
        QString toYaml() override;
    private:
        QString size;
    };
}

#endif // RESIZEPARTITION_H
