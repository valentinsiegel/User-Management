#include "confirm.h"
#include "qtablewidget.h"
#include "ui_confirm.h"
#include "sqlconnection.h"
#include "QtSql"

Confirm::Confirm(QWidget *parent, QString username, QString currentPerm) :
    QDialog(parent),
    ui(new Ui::Confirm)
{
    ui->setupUi(this);

    this->username = username;
    this->currentPerm = currentPerm;

    connect(ui->cancelButton, SIGNAL(clicked(bool)), this , SLOT(close()));


    connect(this, SIGNAL(refresh()), parentWidget(), SLOT(fillUserList()) );

    if(currentPerm == 0){
        QWidget::setWindowTitle("Supprimer un utilisateur");
        ui->warningLabel->setText("Êtes-vous sûr de vouloir supprimer l'utilisateur "+username+"?");
        connect(ui->confirmButton, SIGNAL(clicked(bool)), this , SLOT(confirmDelete()));
    } else {
        QWidget::setWindowTitle("Modifier les permissions d'un utilisateur");
        if(currentPerm=="Oui"){
            ui->warningLabel->setText("Supprimer les droits d'administration de l'utilisateur "+username+"?");
            connect(ui->confirmButton, SIGNAL(clicked(bool)), this , SLOT(confirmDemote()));
        } else {
            ui->warningLabel->setText("Êtes-vous sûr de vouloir rendre l'utilisateur "+username+" administrateur?");
            connect(ui->confirmButton, SIGNAL(clicked(bool)), this , SLOT(confirmPromote()));
        }
    }



}

Confirm::~Confirm()
{
    delete ui;
}


void Confirm::confirmDelete(){

    SQLConnection *sqlConnection = new SQLConnection(this);
    sqlConnection->getSQLInstance(QDir::currentPath()+"/fish.db");
    QSqlQuery query;

    query.exec("DELETE FROM users WHERE USERNAME='"+username+"'");
    qDebug()<<query.executedQuery();

    emit refresh();
    this->close();
}

void Confirm::confirmDemote(){

    SQLConnection *sqlConnection = new SQLConnection(this);
    sqlConnection->getSQLInstance(QDir::currentPath()+"/fish.db");
    QSqlQuery query;

    query.exec("UPDATE users SET ISADMIN='0' WHERE USERNAME='"+username+"'");

    emit refresh();
    this->close();
}

void Confirm::confirmPromote(){
    qDebug()<<username;
    SQLConnection *sqlConnection = new SQLConnection(this);
    sqlConnection->getSQLInstance(QDir::currentPath()+"/fish.db");
    QSqlQuery query;

    query.exec("UPDATE users SET ISADMIN ='1' WHERE USERNAME='"+username+"'");
    qDebug()<<query.executedQuery();
    emit refresh();
    this->close();
}

