#include "handler.h"
#include <QProcess>
#include <QDebug>

Handler::Handler(QObject *parent) : QObject(parent)
{

}
//lsblk --noheading -p --list | awk '$6 ~ /disk/{print $1, $4}'

QStringList Handler::getDisks(){
    QProcess process;
    process.start("/bin/bash", QStringList() << "-c" << "lsblk --noheading -p --list -o +MODEL | awk '$6 ~ /disk/{print $1, \"  (\"$4\")  - \", $7}'");
    process.waitForFinished();
    QString result = process.readAllStandardOutput();
    QStringList stringlist = result.split("\n");
    stringlist.removeAll(""); // remove all entries that are empty
    return stringlist;
}
