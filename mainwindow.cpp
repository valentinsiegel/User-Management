#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usermanagement.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UserManagement *userManagement = new UserManagement(this);
    userManagement->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
