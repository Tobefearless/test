#-------------------------------------------------
#
# Project created by QtCreator 2020-11-10T15:46:30
#
#-------------------------------------------------

QT       += core gui mqtt concurrent dbus multimedia
QT       += charts
QT += network
QT       += sql
QT       += serialport
QT       += axcontainer
CONFIG += C++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sys
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        mainwindow.cpp \
    home\historical_curve.cpp \
    pub\qwchartview.cpp \
    home\home.cpp \
    pub\pub.cpp \
    home\system_setting.cpp \
    home\sensor.cpp \
    home\data_report.cpp \
    home\comms_indicate.cpp \
    home\user_management.cpp \
    thread\mythread.cpp \
    pub\mysql.cpp \
    table\seed1.cpp \
    table\co_parenting1.cpp \
    pub\controldelegate.cpp \
    home\help.cpp \
    table\set_parament1.cpp \
    thread\serialthread.cpp \
    main.cpp \

HEADERS += \
        mainwindow.h \
    home\historical_curve.h \
    pub\qwchartview.h \
    home\home.h \
    pub\pub.h \
    home\system_setting.h \
    home\sensor.h \
    home\data_report.h \
    home\comms_indicate.h \
    home\user_management.h \
    thread\mythread.h \
    pub\mysql.h \
    table\seed1.h \
    table\co_parenting1.h \
    pub\controldelegate.h \
    home\help.h \
    table\set_parament1.h \
    thread\serialthread.h \

FORMS += \
        mainwindow.ui \
    home\historical.ui \
    home\system_setting.ui \
    home\sensor.ui \
    home\data_report.ui \
    home\comms_indicate.ui \
    home\user_management.ui \
    table\seed1.ui \
    table\co_parenting1.ui \
    home\help.ui \
    home\homer.ui \
    table\set_parament1.ui \

RC_FILE = uac.rc
RESOURCES += \
    rec.qrc



#开启异常处理
#CONFIG += exceptions
RC_ICONS = main.ico


# 版本信息
VERSION = 1.0.0.1

# 产品名称
QMAKE_TARGET_PRODUCT = "蚕桑管理版"


# 中文（简体）
RC_LANG = 0x0804
