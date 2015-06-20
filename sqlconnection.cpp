#include "sqlconnection.h"
#include <QMessageBox>


SQLConnection::SQLConnection(QObject *parent) : QObject(parent)
{

}

SQLConnection::~SQLConnection()
{

}

QSqlDatabase SQLConnection::getSQLInstance(QString pathToDb){

        connection = QSqlDatabase::addDatabase("QSQLITE");
        connection.setDatabaseName(pathToDb);

        QFileInfo checkfile(pathToDb);

        if(!checkfile.isFile()){

            QMessageBox messageBox;
            messageBox.critical(0,"Error","Base de données introuvable");
            messageBox.setFixedSize(500,200);

            } else if(!connection.open()){

            QMessageBox messageBox;
            messageBox.critical(0,"Error","Impossible d'ouvrir la base de données");
            messageBox.setFixedSize(500,200);

            }
    return connection;
}


