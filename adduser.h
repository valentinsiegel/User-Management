#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include "user.h"

namespace Ui {
class AddUser;
}

class AddUser : public QDialog
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = 0);
    ~AddUser();


private:
    Ui::AddUser *ui;
    bool isAdmin = false;

signals:
    void refresh();

public slots:
    void UserAdd();
};

#endif // ADDUSER_H
