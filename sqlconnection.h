#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QObject>
#include <QSqlDatabase>

#include <QDir>
#include <QDebug>

class SQLConnection : public QObject
{
    Q_OBJECT
public:

    explicit SQLConnection(QObject *parent = 0);
    ~SQLConnection();
    QSqlDatabase getSQLInstance(QString pathToDb);

private:

    QSqlDatabase connection;

signals:

public slots:
};

#endif // SQLCONNECTION_H
