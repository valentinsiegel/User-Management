#include "usermanagement.h"
#include "ui_usermanagement.h"
#include "QtSql"
#include "sqlconnection.h"
#include "user.h"
#include "edituser.h"
#include "adduser.h"
#include "qmessagebox.h"
#include "confirm.h"

UserManagement::UserManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);

    fillUserList();
    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(openAddUser()));
    connect(ui->editButton, SIGNAL(clicked(bool)), this, SLOT(openEditUser()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(openConfirmDelete()));
    connect(ui->changePermButton, SIGNAL(clicked(bool)), this, SLOT(changePerm()));
    connect(this, SIGNAL(refresh()), this, SLOT(fillUserList()));

    ui->tableWidget->setColumnWidth( 0, 305 );
    ui->tableWidget->setColumnWidth( 1, 150 );
    ui->tableWidget->setHorizontalHeaderLabels(QString("Nom d'utilisateur;Statut Admin").split(";"));


}

UserManagement::~UserManagement()
{
    delete ui;
}

QList<User*> UserManagement::getAllUsers(){
    users.clear();
    SQLConnection *sqlConnection = new SQLConnection(this);
    sqlConnection->getSQLInstance(QDir::currentPath()+"/fish.db");
    QSqlQuery query;

    if(query.exec("SELECT * FROM users")){
            while(query.next()){
                User *user = new User(query.value(0).toString(), query.value(1).toString(), query.value(2).toBool());
                users.append(user);
            }
    }
    return users;
}

void UserManagement::fillUserList(){

    getAllUsers();
    ui->tableWidget->clear();
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setRowCount(getAllUsers().count());
    int i = 0;
    foreach (User* user, users) {

            ui->tableWidget->setItem(i, 0,new QTableWidgetItem(user->getUsername()));
            QTableWidgetItem *item = new QTableWidgetItem();
            if(user->getIsAdmin()){

                item->setText("Oui");
            } else {
                item->setText("Non");
            }

             ui->tableWidget->setItem(i, 1, item);

            i++;
    }
}

void UserManagement::openAddUser(){
    AddUser *addUser = new AddUser(this);
    addUser->show();
}

void UserManagement::openEditUser(){
    QTableWidgetItem *item = ui->tableWidget->item(ui->tableWidget->currentRow(), 0);
    if(item!=NULL){
        QString username = item->text();
        EditUser  *editUser = new EditUser(username);
        editUser->show();
    }
}

void UserManagement::openConfirmDelete(){
    QTableWidgetItem *item = ui->tableWidget->item(ui->tableWidget->currentRow(), 0);
    if(item!=NULL){
        QString username = item->text();
        Confirm *confirm = new Confirm(this, username, "");
        confirm->show();
    }


}

void UserManagement::changePerm(){
    QTableWidgetItem *item = ui->tableWidget->item(ui->tableWidget->currentRow(), 0);
    QTableWidgetItem *item2 = ui->tableWidget->item(ui->tableWidget->currentRow(), 1);

    if(item!=NULL){
        QString username = item->text();
        QString currentPerm = item2->text();
        Confirm *confirm = new Confirm(this, username, currentPerm);
        confirm->show();
    }
}
