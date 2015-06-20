#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QDialog>
#include "user.h"

namespace Ui {
class UserManagement;
}

class UserManagement : public QDialog
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = 0);
    ~UserManagement();
    QList<User*> getAllUsers();
    void addUser(User *user);


private:
    Ui::UserManagement *ui;
    QList<User*> users;
    QString currentSelectedUser;

signals:

    void refresh();

public slots:

    void fillUserList();
    void openAddUser();
    void openEditUser();
    void openConfirmDelete();
    void changePerm();

};

#endif // USERMANAGEMENT_H
