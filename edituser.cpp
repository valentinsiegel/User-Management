#include "edituser.h"
#include "ui_edituser.h"
#include "sqlconnection.h"
#include "QtSql"
#include "qdebug.h"
#include "qmessagebox.h"

EditUser::EditUser(QString username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUser)
{
    ui->setupUi(this);
    this->username = username;

    ui->titleLabel->setText(ui->titleLabel->text()+username);

    connect(ui->confirmButton, SIGNAL(clicked(bool)), this, SLOT(UserEdit()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

EditUser::~EditUser()
{
    delete ui;
}

void EditUser::UserEdit(){

    if(ui->passwordField->text() == ui->confirmPasswordField->text()){
        SQLConnection *sqlConnection = new SQLConnection(this);
        sqlConnection->getSQLInstance(QDir::currentPath()+"/fish.db");
        QSqlQuery query;
        if(ui->passwordField->text().count()<50){
            query.exec("UPDATE users SET PASSWORD ='"+ui->confirmPasswordField->text()+"' WHERE USERNAME='"+username+"'");
        } else {
            QMessageBox messageBox;
            messageBox.critical(0,"Erreur","Le mot de passe doit compter moins de 50 caractères");
            messageBox.setFixedSize(500,200);
        }

    } else {
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur","Les deux champs mot de passe ne sont pas identiques");
        messageBox.setFixedSize(500,200);

    }

    this->close();
}
