#-------------------------------------------------
#
# Project created by QtCreator 2015-06-19T11:21:39
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UserManage
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        usermanagement.cpp\
        sqlconnection.cpp \
    user.cpp \
    adduser.cpp \
    edituser.cpp \
    confirm.cpp

HEADERS  += mainwindow.h\
            usermanagement.h\
            sqlconnection.h \
    user.h \
    adduser.h \
    edituser.h \
    confirm.h

FORMS    += mainwindow.ui\
            usermanagement.ui \
    adduser.ui \
    edituser.ui \
    deleteuser.ui \
    confirm.ui
