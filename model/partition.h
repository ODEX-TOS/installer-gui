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
        partition() {}
        partition(QString name, QString mountpoint, QString filesystem, QString start, QString end);
        partition(QString name, QString mountpoint, QString filesystem, QString start, QString end, int offset);
        // only use this in case you use a resize partition, otherwise start and end are required
        partition(QString name, QString mountpoint, QString filesystem);
        partition(QString name, QString mountpoint, QString filesystem, int offset);


        QString getName();
        QString getMountpoint();
        // return the filesystem in a string format for easy generation of a yaml file
        QString getFilesystem();
        QString getStart();
        QString getEnd();
        int getOffset();
        virtual bool isEncrypted() {return false;}
        virtual bool isResizable() {return false;}
        QString baseYaml() {
            if (this->offset == -1 ){
                return "\t\t\t\t- partition:\n"
                       "\t\t\t\t\tname: \"" + this->name + "\"\n"
                       "\t\t\t\t\tmountpoint: \"" + this->mountpoint + "\"\n"
                       "\t\t\t\t\tfilesystem: \"" + this->filesystem + "\"\n"
                       "\t\t\t\t\tstart: \"" + this->start + "\"\n"
                       "\t\t\t\t\tend: \"" + this->end + "\"\n";

            }
            return "\t\t\t\t- partition:\n"
                   "\t\t\t\t\tname: \"" + this->name + "\"\n"
                   "\t\t\t\t\tmountpoint: \"" + this->mountpoint + "\"\n"
                   "\t\t\t\t\tfilesystem: \"" + this->filesystem + "\"\n"
                   "\t\t\t\t\tstart: \"" + this->start + "\"\n"
                   "\t\t\t\t\tend: \"" + this->end + "\"\n"
                   "\t\t\t\t\toffset: " + QString::number(this->offset) + "\n";
        }
        virtual QString toYaml() {
            return this->baseYaml();
        }
    private:
       // general stuff
       QString name;
       QString mountpoint;
       QString filesystem;
       QString start;
       QString end;
       // potential offset. If offset is not specified than that means the yaml file calculates the offset
       int offset = -1;
    };
}

#endif // PARTITION_H
