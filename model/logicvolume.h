#ifndef LOGICVOLME_H
#define LOGICVOLME_H

#include <QString>

namespace model {
    class logicvolume
    {
    public:
        logicvolume(QString name, QString size, QString mountpoint);
        QString getName();
        QString getSize();
        QString getMountPoint();
        QString toYaml();
    private:
        QString name;
        QString size;
        QString mountpoint;
    };
}

#endif // LOGICVOLME_H
