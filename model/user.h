#ifndef USER_H
#define USER_H

#include <QString>
namespace model {

class user {
public:
    user() {}
    user(QString name, QString password);
    user(QString name, QString password, QString shell);

    QString getName();
    QString getPassword();
    QString getShell();
    QString toYaml();

private:
    // The name of the user
    // This name should always be a combination of letters and numbers, special character like a newline can be added but then you can login with a keyboard
    QString name;
    // The same applies for a password
    QString password;
    // The tos installer always sets the shell to zsh
    QString shell = "/bin/zsh";
};
}

#endif // USER_H
