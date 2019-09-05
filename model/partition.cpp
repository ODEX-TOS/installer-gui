#include "partition.h"

namespace model {
    partition::partition(QString name, QString mountpoint, EFilesystem filesystem, QString start, QString end){
        this->name = name;
        this->mountpoint = mountpoint;
        this->filesystem = filesystem;
        this->start = start;
        this->end = end;
    }
    partition::partition(QString name, QString mountpoint, EFilesystem filesystem, QString start, QString end, int offset){
        this->name = name;
        this->mountpoint = mountpoint;
        this->filesystem = filesystem;
        this->start = start;
        this->end = end;
        this->offset = offset;
    }
        // only use this in case you use a resize partition, otherwise start and end are required
    partition::partition(QString name, QString mountpoint, EFilesystem filesystem){
        this->name = name;
        this->mountpoint = mountpoint;
        this->filesystem = filesystem;
    }
    partition::partition(QString name, QString mountpoint, EFilesystem filesystem, int offset){
        this->name = name;
        this->mountpoint = mountpoint;
        this->filesystem = filesystem;
        this->offset = offset;
    }


    QString partition::getName(){
        return this->name;
    }
    QString partition::getMountpoint(){
        return this->mountpoint;
    }
        // return the filesystem in a string format for easy generation of a yaml file
    QString partition::getFilesystem(){
        switch (this->filesystem) {
            case EFilesystem::ext4:
                return "ext4";
            case EFilesystem::btrfs:
                return "btrfs";
            case EFilesystem::fat32:
                return "fat32";
            case EFilesystem::luks:
                return "luks";
            case EFilesystem::swap:
                return "swap";
        }
        return "error";
    }
    QString partition::getStart(){
        return this->start;
    }
    QString partition::getEnd(){
        return this->end;
    }
    int partition::getOffset(){
        return this->offset;
    }
}
