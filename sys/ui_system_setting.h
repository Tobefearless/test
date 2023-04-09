/********************************************************************************
** Form generated from reading UI file 'system_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_SETTING_H
#define UI_SYSTEM_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_System_Setting
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_4;
    QPushButton *btn_connect;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *combox_port;
    QComboBox *comboBox_baud;
    QPushButton *btn_scan;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *Temp_Diff;
    QLabel *label_3;
    QLineEdit *Humi_Diff;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *WindDiff;
    QLabel *label_7;
    QGroupBox *groupBox_3;
    QPushButton *Heat_Learn;
    QPushButton *Cold_Learn;
    QPushButton *Close_Learn;
    QGroupBox *groupBox_5;
    QPushButton *btn_Wconnect;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_passwd;
    QComboBox *comboBox_wifi;
    QPushButton *Modify;
    QLabel *label;
    QComboBox *Room_Choose;
    QGroupBox *groupBox_6;
    QRadioButton *Button_Cui;
    QRadioButton *Button_Bao;
    QRadioButton *Button_Gong;

    void setupUi(QMainWindow *System_Setting)
    {
        if (System_Setting->objectName().isEmpty())
            System_Setting->setObjectName(QStringLiteral("System_Setting"));
        System_Setting->resize(1224, 678);
        centralwidget = new QWidget(System_Setting);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(570, 440, 221, 181));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        groupBox_4->setFont(font);
        groupBox_4->setStyleSheet(QLatin1String("QGroupBox::title\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top center;\n"
"padding:0 3px;\n"
"}"));
        btn_connect = new QPushButton(groupBox_4);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));
        btn_connect->setGeometry(QRect(10, 30, 91, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        btn_connect->setFont(font1);
        btn_connect->setStyleSheet(QLatin1String("QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:5px outset rgb(39,118,129);\n"
" background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(46, 138, 149, 255), stop:0.50001 rgba(55, 158, 169, 255));\n"
"\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border:5px outset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"	position:relative; top:1px; left:1px\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px inset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"	border-bottom: 1px;\n"
"\n"
"}"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 80, 71, 20));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 140, 71, 20));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        combox_port = new QComboBox(groupBox_4);
        combox_port->setObjectName(QStringLiteral("combox_port"));
        combox_port->setGeometry(QRect(110, 80, 91, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        combox_port->setFont(font2);
        combox_port->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"border:3px solid rgb(255,255,255);\n"
"\n"
""));
        comboBox_baud = new QComboBox(groupBox_4);
        comboBox_baud->setObjectName(QStringLiteral("comboBox_baud"));
        comboBox_baud->setGeometry(QRect(110, 140, 91, 22));
        comboBox_baud->setFont(font2);
        comboBox_baud->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"border:3px solid rgb(255,255,255);\n"
"\n"
""));
        btn_scan = new QPushButton(groupBox_4);
        btn_scan->setObjectName(QStringLiteral("btn_scan"));
        btn_scan->setGeometry(QRect(110, 30, 91, 31));
        btn_scan->setFont(font1);
        btn_scan->setStyleSheet(QLatin1String("QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:5px outset rgb(39,118,129);\n"
" background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(46, 138, 149, 255), stop:0.50001 rgba(55, 158, 169, 255));\n"
"\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border:5px outset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"	position:relative; top:1px; left:1px\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px inset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"	border-bottom: 1px;\n"
"\n"
"}"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(570, 170, 501, 171));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(17);
        font3.setBold(true);
        font3.setWeight(75);
        groupBox_2->setFont(font3);
        groupBox_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 461, 80));
        QFont font4;
        font4.setPointSize(17);
        font4.setBold(true);
        font4.setWeight(75);
        groupBox->setFont(font4);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 91, 20));
        label_2->setFont(font);
        Temp_Diff = new QLineEdit(groupBox);
        Temp_Diff->setObjectName(QStringLiteral("Temp_Diff"));
        Temp_Diff->setGeometry(QRect(120, 40, 61, 21));
        Temp_Diff->setFont(font2);
        Temp_Diff->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        Temp_Diff->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 40, 91, 20));
        label_3->setFont(font);
        Humi_Diff = new QLineEdit(groupBox);
        Humi_Diff->setObjectName(QStringLiteral("Humi_Diff"));
        Humi_Diff->setGeometry(QRect(360, 40, 61, 20));
        Humi_Diff->setFont(font2);
        Humi_Diff->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        Humi_Diff->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 40, 21, 20));
        QFont font5;
        font5.setPointSize(15);
        label_4->setFont(font5);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(440, 40, 21, 20));
        label_5->setFont(font5);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 130, 201, 20));
        label_6->setFont(font);
        WindDiff = new QLineEdit(groupBox_2);
        WindDiff->setObjectName(QStringLiteral("WindDiff"));
        WindDiff->setGeometry(QRect(240, 130, 71, 20));
        WindDiff->setFont(font2);
        WindDiff->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        WindDiff->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(360, 130, 21, 20));
        label_7->setFont(font5);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(570, 340, 501, 91));
        groupBox_3->setFont(font1);
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox::title\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top center;\n"
"padding:0 3px;\n"
"}"));
        Heat_Learn = new QPushButton(groupBox_3);
        Heat_Learn->setObjectName(QStringLiteral("Heat_Learn"));
        Heat_Learn->setGeometry(QRect(30, 40, 101, 31));
        Heat_Learn->setFont(font2);
        Heat_Learn->setStyleSheet(QLatin1String("QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:5px outset rgb(39,118,129);\n"
" background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(46, 138, 149, 255), stop:0.50001 rgba(55, 158, 169, 255));\n"
"\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border:5px outset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"	position:relative; top:1px; left:1px\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px inset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"	border-bottom: 1px;\n"
"\n"
"}"));
        Cold_Learn = new QPushButton(groupBox_3);
        Cold_Learn->setObjectName(QStringLiteral("Cold_Learn"));
        Cold_Learn->setGeometry(QRect(190, 40, 101, 31));
        Cold_Learn->setFont(font2);
        Cold_Learn->setStyleSheet(QLatin1String("QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:5px outset rgb(39,118,129);\n"
" background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(46, 138, 149, 255), stop:0.50001 rgba(55, 158, 169, 255));\n"
"\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border:5px outset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"	position:relative; top:1px; left:1px\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px inset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"	border-bottom: 1px;\n"
"\n"
"}"));
        Close_Learn = new QPushButton(groupBox_3);
        Close_Learn->setObjectName(QStringLiteral("Close_Learn"));
        Close_Learn->setGeometry(QRect(350, 40, 101, 31));
        Close_Learn->setFont(font2);
        Close_Learn->setStyleSheet(QLatin1String("QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:5px outset rgb(39,118,129);\n"
" background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(46, 138, 149, 255), stop:0.50001 rgba(55, 158, 169, 255));\n"
"\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border:5px outset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"	position:relative; top:1px; left:1px\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px inset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"	border-bottom: 1px;\n"
"\n"
"}"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(800, 440, 271, 181));
        groupBox_5->setFont(font);
        groupBox_5->setStyleSheet(QLatin1String("QGroupBox::title\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top center;\n"
"padding:0 3px;\n"
"}"));
        btn_Wconnect = new QPushButton(groupBox_5);
        btn_Wconnect->setObjectName(QStringLiteral("btn_Wconnect"));
        btn_Wconnect->setGeometry(QRect(130, 30, 111, 31));
        btn_Wconnect->setFont(font1);
        btn_Wconnect->setStyleSheet(QLatin1String("QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:5px outset rgb(39,118,129);\n"
" background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(46, 138, 149, 255), stop:0.50001 rgba(55, 158, 169, 255));\n"
"\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border:5px outset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"	position:relative; top:1px; left:1px\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px inset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"	border-bottom: 1px;\n"
"\n"
"}"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 80, 101, 21));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 140, 101, 21));
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_name = new QLineEdit(groupBox_5);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(130, 80, 121, 20));
        QFont font6;
        font6.setPointSize(12);
        lineEdit_name->setFont(font6);
        lineEdit_passwd = new QLineEdit(groupBox_5);
        lineEdit_passwd->setObjectName(QStringLiteral("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(130, 140, 121, 20));
        lineEdit_passwd->setFont(font6);
        lineEdit_passwd->setEchoMode(QLineEdit::Password);
        comboBox_wifi = new QComboBox(groupBox_5);
        comboBox_wifi->setObjectName(QStringLiteral("comboBox_wifi"));
        comboBox_wifi->setGeometry(QRect(10, 30, 91, 31));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font7.setPointSize(18);
        font7.setBold(true);
        font7.setWeight(75);
        comboBox_wifi->setFont(font7);
        comboBox_wifi->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"border:3px solid rgb(255,255,255);\n"
"\n"
""));
        Modify = new QPushButton(centralwidget);
        Modify->setObjectName(QStringLiteral("Modify"));
        Modify->setGeometry(QRect(570, 630, 501, 41));
        Modify->setFont(font2);
        Modify->setStyleSheet(QLatin1String("QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:5px outset rgb(39,118,129);\n"
" background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(46, 138, 149, 255), stop:0.50001 rgba(55, 158, 169, 255));\n"
"\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border:5px outset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"	position:relative; top:1px; left:1px\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px inset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"	border-bottom: 1px;\n"
"\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(760, 30, 151, 31));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font8.setPointSize(24);
        font8.setBold(true);
        font8.setWeight(75);
        label->setFont(font8);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        Room_Choose = new QComboBox(centralwidget);
        Room_Choose->setObjectName(QStringLiteral("Room_Choose"));
        Room_Choose->setGeometry(QRect(570, 80, 171, 31));
        Room_Choose->setFont(font1);
        Room_Choose->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"border:3px solid rgb(255,255,255);\n"
"\n"
""));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(570, 110, 501, 51));
        groupBox_6->setFont(font2);
        groupBox_6->setStyleSheet(QLatin1String("QGroupBox::title\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top center;\n"
"padding:0 3px;\n"
"}"));
        Button_Cui = new QRadioButton(groupBox_6);
        Button_Cui->setObjectName(QStringLiteral("Button_Cui"));
        Button_Cui->setGeometry(QRect(20, 25, 89, 16));
        QFont font9;
        font9.setPointSize(12);
        font9.setBold(true);
        font9.setWeight(75);
        Button_Cui->setFont(font9);
        Button_Cui->setStyleSheet(QLatin1String("\n"
"QRadioButton{\n"
"    spacing: 2px;\n"
"    color: white;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width:                  12px;\n"
"    height:                 12px;\n"
"    border-radius:          8px;\n"
"	\n"
"}\n"
" \n"
"QRadioButton::indicator:checked {\n"
"	\n"
"    background-color:       green;\n"
"    border:                 2px solid white;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
" \n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       white;\n"
"    border:                 2px solid white;\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        Button_Cui->setChecked(true);
        Button_Bao = new QRadioButton(groupBox_6);
        Button_Bao->setObjectName(QStringLiteral("Button_Bao"));
        Button_Bao->setGeometry(QRect(200, 25, 89, 16));
        Button_Bao->setFont(font9);
        Button_Bao->setStyleSheet(QLatin1String("\n"
"QRadioButton{\n"
"    spacing: 2px;\n"
"    color: white;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width:                  12px;\n"
"    height:                 12px;\n"
"    border-radius:          8px;\n"
"	\n"
"}\n"
" \n"
"QRadioButton::indicator:checked {\n"
"	\n"
"    background-color:       green;\n"
"    border:                 2px solid white;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
" \n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       white;\n"
"    border:                 2px solid white;\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        Button_Gong = new QRadioButton(groupBox_6);
        Button_Gong->setObjectName(QStringLiteral("Button_Gong"));
        Button_Gong->setGeometry(QRect(390, 25, 89, 16));
        Button_Gong->setFont(font9);
        Button_Gong->setStyleSheet(QLatin1String("\n"
"QRadioButton{\n"
"    spacing: 2px;\n"
"    color: white;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width:                  12px;\n"
"    height:                 12px;\n"
"    border-radius:          8px;\n"
"	\n"
"}\n"
" \n"
"QRadioButton::indicator:checked {\n"
"	\n"
"    background-color:       green;\n"
"    border:                 2px solid white;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
" \n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       white;\n"
"    border:                 2px solid white;\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        System_Setting->setCentralWidget(centralwidget);

        retranslateUi(System_Setting);

        comboBox_baud->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(System_Setting);
    } // setupUi

    void retranslateUi(QMainWindow *System_Setting)
    {
        System_Setting->setWindowTitle(QApplication::translate("System_Setting", "MainWindow", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("System_Setting", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        btn_connect->setText(QApplication::translate("System_Setting", "\350\277\236\346\216\245", Q_NULLPTR));
        label_8->setText(QApplication::translate("System_Setting", "\344\270\262  \345\217\243", Q_NULLPTR));
        label_9->setText(QApplication::translate("System_Setting", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        comboBox_baud->clear();
        comboBox_baud->insertItems(0, QStringList()
         << QApplication::translate("System_Setting", "9600", Q_NULLPTR)
         << QApplication::translate("System_Setting", "19200", Q_NULLPTR)
         << QApplication::translate("System_Setting", "38400", Q_NULLPTR)
         << QApplication::translate("System_Setting", "115200", Q_NULLPTR)
        );
        btn_scan->setText(QApplication::translate("System_Setting", "\346\211\253\346\217\217", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("System_Setting", "\345\233\236\345\267\256\345\200\274", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("System_Setting", "\345\233\236\345\267\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("System_Setting", "\346\270\251\345\272\246\345\233\236\345\267\256", Q_NULLPTR));
        Temp_Diff->setText(QApplication::translate("System_Setting", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("System_Setting", "\346\271\277\345\272\246\345\233\236\345\267\256", Q_NULLPTR));
        Humi_Diff->setText(QApplication::translate("System_Setting", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("System_Setting", "\342\204\203", Q_NULLPTR));
        label_5->setText(QApplication::translate("System_Setting", "%", Q_NULLPTR));
        label_6->setText(QApplication::translate("System_Setting", "\345\214\200\351\243\216\346\211\207\345\220\257\345\212\250\346\270\251\345\267\256\345\200\274", Q_NULLPTR));
        WindDiff->setText(QApplication::translate("System_Setting", "0", Q_NULLPTR));
        label_7->setText(QApplication::translate("System_Setting", "\342\204\203", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("System_Setting", "\347\251\272\350\260\203\345\255\246\344\271\240", Q_NULLPTR));
        Heat_Learn->setText(QApplication::translate("System_Setting", "\345\212\240\347\203\255\345\255\246\344\271\240", Q_NULLPTR));
        Cold_Learn->setText(QApplication::translate("System_Setting", "\345\210\266\345\206\267\345\255\246\344\271\240", Q_NULLPTR));
        Close_Learn->setText(QApplication::translate("System_Setting", "\345\205\263\351\227\255\345\255\246\344\271\240", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("System_Setting", "WIFI/4G\350\256\276\347\275\256", Q_NULLPTR));
        btn_Wconnect->setText(QApplication::translate("System_Setting", "\350\277\236\346\216\245", Q_NULLPTR));
        label_10->setText(QApplication::translate("System_Setting", "WIFI\345\220\215\345\255\227", Q_NULLPTR));
        label_11->setText(QApplication::translate("System_Setting", "WIFI\345\257\206\347\240\201", Q_NULLPTR));
        comboBox_wifi->clear();
        comboBox_wifi->insertItems(0, QStringList()
         << QApplication::translate("System_Setting", "WIFI", Q_NULLPTR)
         << QApplication::translate("System_Setting", "4G", Q_NULLPTR)
        );
        Modify->setText(QApplication::translate("System_Setting", "\344\277\256\346\224\271", Q_NULLPTR));
        label->setText(QApplication::translate("System_Setting", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("System_Setting", "\346\250\241\345\274\217\351\200\211\346\213\251", Q_NULLPTR));
        Button_Cui->setText(QApplication::translate("System_Setting", "\345\202\254\351\235\222", Q_NULLPTR));
        Button_Bao->setText(QApplication::translate("System_Setting", "\344\277\235\347\247\215", Q_NULLPTR));
        Button_Gong->setText(QApplication::translate("System_Setting", "\345\205\261\350\202\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class System_Setting: public Ui_System_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_SETTING_H
