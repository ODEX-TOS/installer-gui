#ifndef PARTITION_H
#define PARTITION_H

#include <QString>
#include "logicvolume.h"
#include <vector>
namespace model {
    enum EFilesystem {
        fat32,
        ext4,
        btrfs,
        luks,
        swap
    };
    class partition
    {
    public:
        partition(QString name, QString mountpoint, EFilesystem filesystem, QString start, QString end);
        partition(QString name, QString mountpoint, EFilesystem filesystem, QString start, QString end, int offset);
        // only use this in case you use a resize partition, otherwise start and end are required
        partition(QString name, QString mountpoint, EFilesystem filesystem);
        partition(QString name, QString mountpoint, EFilesystem filesystem, int offset);


        QString getName();
        QString getMountpoint();
        // return the filesystem in a string format for easy generation of a yaml file
        QString getFilesystem();
        QString getStart();
        QString getEnd();
        int getOffset();
        virtual bool isEncrypted(){return false;}
        virtual bool isResizable(){return false;}
        virtual ~partition();
    private:
       // general stuff
       QString name;
       QString mountpoint;
       EFilesystem filesystem;
       QString start;
       QString end;
       // potential offset. If offset is not specified than that means the yaml file calculates the offset
       int offset = -1;
    };
}

#endif // PARTITION_H
