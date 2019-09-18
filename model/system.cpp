#include "system.h"

namespace model {
system::system(QString local, QString keymap, QString rootpwd) {
    this->local = local;
    this->keymap = keymap;
    this->rootpwd = rootpwd;
}
system::system(QString local, QString keymap, QString rootpwd, QString hostname) {
    this->local = local;
    this->keymap = keymap;
    this->rootpwd = rootpwd;
    this->hostname = hostname;
}

QString system::getLocal() {
    return this->local;
}

QString system::getKeymap() {
    return this->keymap;
}

QString system::getRootPWD() {
    return this->rootpwd;
}

QString system::getHostname() {
    return this->hostname;
}

QString system::toYaml() {
    return "   - system:\n"
           "      local: \""
        + this->local + "\"\n"
                        "      keymap: \""
        + this->keymap + "\"\n"
                         "      password: \""
        + this->rootpwd + "\"\n"
                          "      hostname: \""
        + this->hostname + "\"\n";
}
}
