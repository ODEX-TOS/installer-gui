#include "resizepartition.h"

namespace model {
resizePartition::resizePartition(QString name, QString mountpoint, QString filesystem, QString size)
    : partition(name, mountpoint, filesystem) {
    this->size = size;
}
resizePartition::resizePartition(QString name, QString mountpoint, QString filesystem, int offset, QString size)
    : partition(name, mountpoint, filesystem, offset) {
    this->size = size;
}
QString resizePartition::getSize() {
    return this->size;
}

QString resizePartition::toYaml() {
    if (this->getOffset() == -1) {
        return "            - partition:\n"
               "               name: \""
            + this->getName() + "\"\n"
                                "               mount: \""
            + this->getMountpoint() + "\"\n"
                                      "               filesystem: \""
            + this->getFilesystem() + "\"\n"
                                      "               size: \""
            + this->size + "\"\n";
    }
    return "            - partition:\n"
           "               name: \""
        + this->getName() + "\"\n"
                            "               mount: \""
        + this->getMountpoint() + "\"\n"
                                  "               filesystem: \""
        + this->getFilesystem() + "\"\n"
                                  "               size: \""
        + this->size + "\"\n"
                       "               offset: "
        + QString::number(this->getOffset()) + "\n";
}
}
