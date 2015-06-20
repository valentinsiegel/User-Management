#ifndef EDITUSER_H
#define EDITUSER_H

#include <QDialog>

namespace Ui {
class EditUser;
}

class EditUser : public QDialog
{
    Q_OBJECT

public:
    explicit EditUser(QString username, QWidget *parent = 0);
    ~EditUser();


private:
    Ui::EditUser *ui;
    QString username;

public slots:
    void UserEdit();
};

#endif // EDITUSER_H
