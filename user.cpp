#include "user.h"

User::User(QString username, QString password, bool isAdmin, QObject *parent) : QObject(parent)
{
    this->username = username;
    this->password = password;
    this->isAdmin = isAdmin;
}

QString User::getUsername(){
    return this->username;
}

bool User::getIsAdmin(){
    return this->isAdmin;
}
