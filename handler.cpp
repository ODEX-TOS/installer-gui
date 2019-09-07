#include "handler.h"

Handler::Handler(QObject *parent) : QObject(parent)
{

}

QStringList Handler::getDisks(){
    QStringList list = QStringList();
    list.append("sda");
    list.append("sdb");
    return list;
}
