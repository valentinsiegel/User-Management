#ifndef CONFIRM_H
#define CONFIRM_H

#include <QDialog>
#include "QtSql"

namespace Ui {
class Confirm;
}

class Confirm : public QDialog
{
    Q_OBJECT

public:
    explicit Confirm(QWidget *parent = 0, QString username = 0, QString currentPerm = 0);
    ~Confirm();
    bool isAlreadyAdmin(QString username);
    QSqlQuery getConnection();


private:
    Ui::Confirm *ui;
    QString username;
    QString currentPerm;

signals:
    void refresh();

public slots:
    void confirmDelete();
    void confirmPromote();
    void confirmDemote();
};

#endif // CONFIRM_H
