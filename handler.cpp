#include "handler.h"
#include <QProcess>
#include <QDebug>

Handler::Handler(QObject *parent) : QObject(parent)
{

}
// lsblk --noheading -p --list | awk '$6 ~ /disk/{print $1, $4}'
QStringList Handler::getDisks(){
    QProcess process;
    process.start("/bin/bash", QStringList() << "-c" << "lsblk --noheading -p --list -o +MODEL | awk '$6 ~ /disk/{print $1, \"  (\"$4\")  - \", $7}'");
    process.waitForFinished();
    QString result = process.readAllStandardOutput();
    QStringList stringlist = result.split("\n");
    stringlist.removeAll(""); // remove all entries that are empty
    return stringlist;
}

//  echo "$(echo 'en_US.UTF-8' && awk '$0 ~ /^(#){0,1}[a-zA-Z_]*.UTF-8/' /etc/locale.gen)" | sed 's:#::' | awk '{print $1}'
// This prints en_US.UTF-8 first followed by a sorted list of locals
QStringList Handler::getLocals(){
    QProcess process;
    process.start("/bin/bash", QStringList() << "-c" << "echo \"$(echo 'en_US.UTF-8' && awk '$0 ~ /^(#){0,1}[a-zA-Z_]*.UTF-8/' /etc/locale.gen)\" | sed 's:#::' | awk '{print $1}'");
    process.waitForFinished();
    QString result = process.readAllStandardOutput();
    QStringList stringlist = result.split("\n");
    stringlist.removeAll(""); // remove all entries that are empty
    return stringlist;
}

// shopt -s globstar; ls -la /usr/share/kbd/keymaps/**/*.map.gz | awk '{print $9}' | awk -F/ '{print $(NF)}' | sed 's;\.map.gz;;'
// The above is the bash command to use
QStringList Handler::getKeyMaps(){
    QProcess process;
    process.start("/bin/bash", QStringList() << "-c" << "shopt -s globstar; ls -la /usr/share/kbd/keymaps/**/*.map.gz | awk '{print $9}' | awk -F/ '{print $(NF)}' | sed 's;\\.map.gz;;'");
    process.waitForFinished();
    QString result = process.readAllStandardOutput();
    QStringList stringlist = result.split("\n");
    stringlist.removeAll(""); // remove all entries that are empty
    return stringlist;
}


// check if the live environment is efi enabled
bool Handler::isEFI(){
    QProcess process;
    process.start("/bin/bash", QStringList() << "-c" << "if [[ -d '/sys/firmware/efi' ]]; then printf 'efi'; else printf 'mbr'; fi");
    process.waitForFinished();
    return process.readAllStandardOutput() == "efi";
}
