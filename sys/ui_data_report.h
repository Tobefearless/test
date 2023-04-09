/********************************************************************************
** Form generated from reading UI file 'data_report.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_REPORT_H
#define UI_DATA_REPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Data_report
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QComboBox *com_sensor;
    QWidget *tab_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_3;
    QComboBox *com_room;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *btn_sure;

    void setupUi(QMainWindow *Data_report)
    {
        if (Data_report->objectName().isEmpty())
            Data_report->setObjectName(QStringLiteral("Data_report"));
        Data_report->resize(1328, 792);
        Data_report->setStyleSheet(QLatin1String("/****#Data_report{\n"
"background-image: url(:/img/room.jpg);\n"
"}*/"));
        centralwidget = new QWidget(Data_report);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(580, 110, 531, 591));
        groupBox_2->setStyleSheet(QStringLiteral("/*background-color: rgb(231, 231, 231);"));
        tabWidget = new QTabWidget(groupBox_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 40, 461, 281));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QLatin1String(" QTabWidget{\n"
"                background-color:transparent;\n"
"}\n"
"                QTabWidget::pane{\n"
"                    border:2px;\n"
"                }\n"
"                QTabWidget::tab-bar{\n"
"                       background:transparent;\n"
"						subcontrol-position:center;\n"
"                }\n"
"                QTabBar::tab{\n"
"                    background:rgb(14, 106, 175);\n"
"                    color:white;\n"
"					min-width:70px;\n"
"					min-height:55px;\n"
"                }\n"
"                QTabBar::tab:hover{\n"
"                    background:rgb(255, 255, 255, 100);\n"
"                color:black;\n"
"                }\n"
"                QTabBar::tab:selected{\n"
"                    border-color: black;\n"
"                    background:red;\n"
"                    color:white;\n"
"                }\n"
""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 161, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 140, 191, 51));
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(220, 30, 191, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        comboBox->setFont(font2);
        comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        com_sensor = new QComboBox(tab);
        com_sensor->setObjectName(QStringLiteral("com_sensor"));
        com_sensor->setGeometry(QRect(220, 150, 191, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        com_sensor->setFont(font3);
        com_sensor->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 30, 181, 31));
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 150, 191, 31));
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        comboBox_3 = new QComboBox(tab_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(220, 30, 191, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        comboBox_3->setFont(font4);
        comboBox_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        com_room = new QComboBox(tab_2);
        com_room->setObjectName(QStringLiteral("com_room"));
        com_room->setGeometry(QRect(220, 150, 191, 31));
        com_room->setFont(font4);
        com_room->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_2, QString());
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 360, 421, 101));
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QLatin1String("QGroupBox::title\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top center;\n"
"padding:0 3px;\n"
"}"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 50, 91, 31));
        QFont font5;
        font5.setPointSize(20);
        font5.setBold(true);
        font5.setWeight(75);
        radioButton->setFont(font5);
        radioButton->setStyleSheet(QLatin1String("\n"
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
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(140, 50, 121, 31));
        radioButton_2->setFont(font5);
        radioButton_2->setStyleSheet(QLatin1String("\n"
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
        radioButton_2->setChecked(false);
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(270, 50, 131, 31));
        radioButton_3->setFont(font5);
        radioButton_3->setStyleSheet(QLatin1String("\n"
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
        btn_sure = new QPushButton(groupBox_2);
        btn_sure->setObjectName(QStringLiteral("btn_sure"));
        btn_sure->setGeometry(QRect(50, 500, 431, 51));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setWeight(75);
        btn_sure->setFont(font6);
        btn_sure->setStyleSheet(QLatin1String("QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:5px outset rgb(39,118,129);\n"
" background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(46, 138, 149, 255), stop:0.50001 rgba(55, 158, 169, 255));\n"
"border-radius:10px;\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border:5px outset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"    border-radius:10px;\n"
"	position:relative; top:1px; left:1px\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px inset gray;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"	border-bottom: 1px;\n"
"    border-radius:10px;\n"
"}"));
        btn_sure->setAutoDefault(false);
        btn_sure->setFlat(false);
        Data_report->setCentralWidget(centralwidget);

        retranslateUi(Data_report);

        tabWidget->setCurrentIndex(0);
        btn_sure->setDefault(false);


        QMetaObject::connectSlotsByName(Data_report);
    } // setupUi

    void retranslateUi(QMainWindow *Data_report)
    {
        Data_report->setWindowTitle(QApplication::translate("Data_report", "MainWindow", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("Data_report", "\346\212\245\350\241\250\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Data_report", "\344\274\240 \346\204\237 \345\231\250\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Data_report", "2021\345\271\2641\346\234\21027\346\227\245", Q_NULLPTR)
        );
        com_sensor->clear();
        com_sensor->insertItems(0, QStringList()
         << QApplication::translate("Data_report", "SCSQ210124001-1", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124001-2", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124001-3", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124001-4", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124001-5", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124001-6", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124002-1", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124002-2", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124002-3", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124002-4", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124002-5", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124002-6", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124003-1", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124003-2", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124003-3", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124003-4", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124003-5", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124003-6", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124004-1", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124004-2", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124004-3", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124004-4", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124004-5", Q_NULLPTR)
         << QApplication::translate("Data_report", "SCSQ210124004-6", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Data_report", "\344\274\240\346\204\237\345\231\250\346\212\245\350\241\250", Q_NULLPTR));
        label_3->setText(QApplication::translate("Data_report", "\346\212\245\350\241\250\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Data_report", "\350\257\267 \351\200\211 \346\213\251\357\274\232", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Data_report", "2021\345\271\2641\346\234\21027\346\227\245", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Data_report", "\346\210\277\351\227\264\346\212\245\350\241\250", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Data_report", "\347\224\237\346\210\220\346\225\260\346\215\256\351\227\264\351\232\224", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Data_report", "3\345\210\206\351\222\237", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Data_report", "15\345\210\206\351\222\237", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("Data_report", "30\345\210\206\351\222\237", Q_NULLPTR));
        btn_sure->setText(QApplication::translate("Data_report", "\347\224\237\346\210\220\346\212\245\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Data_report: public Ui_Data_report {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_REPORT_H
