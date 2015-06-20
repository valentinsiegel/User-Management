#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QString username, QString password, bool isAdmin, QObject *parent = 0);

    QString getUsername();
    bool getIsAdmin();

private:
    QString username;
    QString password;
    bool isAdmin;


signals:

public slots:


};

#endif // USER_H
