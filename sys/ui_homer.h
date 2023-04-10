/********************************************************************************
** Form generated from reading UI file 'homer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMER_H
#define UI_HOMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_45;
    QLabel *title;
    QLabel *left_title;
    QLabel *label_12;
    QLabel *right_title;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_10;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_32;
    QLabel *label_233;
    QLabel *label_3;
    QLabel *label_31;
    QLabel *label_57;
    QWidget *page_2;
    QToolBox *toolBox;
    QWidget *page_3;
    QPushButton *pushButton_main;
    QWidget *page_4;
    QPushButton *pushButton_settting;
    QWidget *page_5;
    QPushButton *pushButton_chart;
    QWidget *page_9;
    QPushButton *pushButton_dataP;
    QWidget *page_10;
    QPushButton *pushButton_sensor;
    QWidget *page_6;
    QPushButton *pushButton_comminicat;
    QWidget *page_11;
    QPushButton *pushButton_manage;
    QWidget *page_7;
    QPushButton *pushButton_6;
    QWidget *page_8;
    QPushButton *pushButton_2;
    QLabel *label_30;
    QLabel *label_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName(QStringLiteral("home"));
        home->resize(1737, 840);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(home->sizePolicy().hasHeightForWidth());
        home->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(10);
        home->setFont(font);
        home->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(home);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_11 = new QGridLayout(centralwidget);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        groupBox_45 = new QGroupBox(centralwidget);
        groupBox_45->setObjectName(QStringLiteral("groupBox_45"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_45->sizePolicy().hasHeightForWidth());
        groupBox_45->setSizePolicy(sizePolicy1);
        groupBox_45->setMinimumSize(QSize(0, 91));
        groupBox_45->setStyleSheet(QStringLiteral("border:none"));
        title = new QLabel(groupBox_45);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(10, 10, 1881, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \346\245\267\344\275\223 Std R"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        title->setFont(font1);
        title->setStyleSheet(QStringLiteral(""));
        title->setPixmap(QPixmap(QString::fromUtf8(":/img/head.png")));
        title->setScaledContents(true);
        left_title = new QLabel(groupBox_45);
        left_title->setObjectName(QStringLiteral("left_title"));
        left_title->setGeometry(QRect(20, 20, 491, 61));
        left_title->setStyleSheet(QStringLiteral(""));
        left_title->setPixmap(QPixmap(QString::fromUtf8(":/img/leftTitle.png")));
        left_title->setScaledContents(true);
        label_12 = new QLabel(groupBox_45);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(580, 20, 731, 41));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/img/title_blcak.png")));
        label_12->setScaledContents(true);
        right_title = new QLabel(groupBox_45);
        right_title->setObjectName(QStringLiteral("right_title"));
        right_title->setGeometry(QRect(1540, 30, 171, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        right_title->setFont(font2);
        right_title->setStyleSheet(QStringLiteral("color: rgb(1, 244, 250);"));
        title->raise();
        right_title->raise();
        label_12->raise();
        left_title->raise();

        gridLayout_11->addWidget(groupBox_45, 0, 0, 1, 3);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QLatin1String("#stackedWidget{border-color: rgb(59, 179, 195);\n"
"            border-width: 3px;\n"
"            border-style: solid;\n"
"}\n"
""));
        stackedWidget->setFrameShape(QFrame::Panel);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_10 = new QGridLayout(page);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QLatin1String("QWidget{\n"
"       background-color:transparent;\n"
"}\n"
"\n"
""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1483, 683));
        label_32 = new QLabel(scrollAreaWidgetContents);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(9, 554, 16, 30));
        label_32->setMinimumSize(QSize(0, 30));
        label_233 = new QLabel(scrollAreaWidgetContents);
        label_233->setObjectName(QStringLiteral("label_233"));
        label_233->setGeometry(QRect(9, 792, 16, 100));
        label_233->setMinimumSize(QSize(0, 100));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(9, 1093, 16, 100));
        label_3->setMinimumSize(QSize(0, 100));
        label_31 = new QLabel(scrollAreaWidgetContents);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(9, 1393, 16, 120));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy2);
        label_31->setMinimumSize(QSize(0, 120));
        label_57 = new QLabel(scrollAreaWidgetContents);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(140, 30, 1483, 50));
        label_57->setMinimumSize(QSize(0, 50));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_32->raise();
        label_3->raise();
        label_31->raise();
        label_233->raise();
        label_57->raise();

        gridLayout_10->addWidget(scrollArea, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout_11->addWidget(stackedWidget, 1, 2, 1, 1);

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy3);
        toolBox->setMinimumSize(QSize(150, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setBold(false);
        font3.setWeight(50);
        toolBox->setFont(font3);
        toolBox->setLayoutDirection(Qt::RightToLeft);
        toolBox->setStyleSheet(QString::fromUtf8("QWidget{ background: transparent;}\n"
"\n"
"QToolBoxButton { min-height:30px; }\n"
"QToolBox::tab {background-color:rgba(22,77,255,255);border-color:rgba(0,0,3,255);color: rgba(51, 255, 255,255);border-style:none;border-width:0px;border-radius:0px;font:22px \"\351\273\221\344\275\223\"; font-weight: bold;}\n"
"\n"
"QToolBox::tab:selected \n"
"{\n"
"	color : #ffffff;\n"
"}"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 150, 383));
        pushButton_main = new QPushButton(page_3);
        pushButton_main->setObjectName(QStringLiteral("pushButton_main"));
        pushButton_main->setGeometry(QRect(0, 0, 201, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        pushButton_main->setFont(font4);
        pushButton_main->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);border-color:rgba(0,0,0,255);color: rgba(51, 255, 255,255);border-style:none;border-width:1px;border-radius:0px;font:bold 20px \"\345\256\213\344\275\223\";\n"
"text-align: left;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(42, 46, 49); \n"
"}\n"
"\n"
""));
        toolBox->addItem(page_3, QString::fromUtf8(" \346\230\276\347\244\272\347\225\214\351\235\242"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 150, 383));
        pushButton_settting = new QPushButton(page_4);
        pushButton_settting->setObjectName(QStringLiteral("pushButton_settting"));
        pushButton_settting->setGeometry(QRect(0, 0, 201, 31));
        pushButton_settting->setLayoutDirection(Qt::LeftToRight);
        pushButton_settting->setAutoFillBackground(false);
        pushButton_settting->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);border-color:rgba(0,0,0,255);color: rgba(51, 255, 255,255);border-style:none;border-width:1px;border-radius:0px;font:bold 20px \"\345\256\213\344\275\223\";\n"
"text-align: left;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(42, 46, 49); \n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_settting->setIcon(icon);
        pushButton_settting->setAutoRepeat(false);
        toolBox->addItem(page_4, QString::fromUtf8(" \347\263\273\347\273\237\350\256\276\347\275\256"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 150, 383));
        pushButton_chart = new QPushButton(page_5);
        pushButton_chart->setObjectName(QStringLiteral("pushButton_chart"));
        pushButton_chart->setGeometry(QRect(0, 0, 201, 31));
        pushButton_chart->setLayoutDirection(Qt::LeftToRight);
        pushButton_chart->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);border-color:rgba(0,0,0,255);color: rgba(51, 255, 255,255);border-style:none;border-width:1px;border-radius:0px;font:bold 20px \"\345\256\213\344\275\223\";\n"
"text-align: left;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(42, 46, 49); \n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_chart->setIcon(icon1);
        toolBox->addItem(page_5, QString::fromUtf8(" \345\216\206\345\217\262\346\233\262\347\272\277"));
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        page_9->setGeometry(QRect(0, 0, 150, 383));
        pushButton_dataP = new QPushButton(page_9);
        pushButton_dataP->setObjectName(QStringLiteral("pushButton_dataP"));
        pushButton_dataP->setGeometry(QRect(0, 0, 201, 31));
        pushButton_dataP->setLayoutDirection(Qt::LeftToRight);
        pushButton_dataP->setAutoFillBackground(false);
        pushButton_dataP->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);border-color:rgba(0,0,0,255);color: rgba(51, 255, 255,255);border-style:none;border-width:1px;border-radius:0px;font:bold 20px \"\345\256\213\344\275\223\";\n"
"text-align: left;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(42, 46, 49); \n"
"}\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/Data report.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_dataP->setIcon(icon2);
        toolBox->addItem(page_9, QString::fromUtf8(" \346\225\260\346\215\256\346\212\245\350\241\250"));
        page_10 = new QWidget();
        page_10->setObjectName(QStringLiteral("page_10"));
        page_10->setGeometry(QRect(0, 0, 150, 383));
        pushButton_sensor = new QPushButton(page_10);
        pushButton_sensor->setObjectName(QStringLiteral("pushButton_sensor"));
        pushButton_sensor->setGeometry(QRect(0, 0, 201, 31));
        pushButton_sensor->setLayoutDirection(Qt::LeftToRight);
        pushButton_sensor->setAutoFillBackground(false);
        pushButton_sensor->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);border-color:rgba(0,0,0,255);color: rgba(51, 255, 255,255);border-style:none;border-width:1px;border-radius:0px;font:bold 20px \"\345\256\213\344\275\223\";\n"
"text-align: left;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(42, 46, 49); \n"
"}\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/sensor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_sensor->setIcon(icon3);
        toolBox->addItem(page_10, QString::fromUtf8(" \344\274\240 \346\204\237 \345\231\250"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setGeometry(QRect(0, 0, 150, 383));
        pushButton_comminicat = new QPushButton(page_6);
        pushButton_comminicat->setObjectName(QStringLiteral("pushButton_comminicat"));
        pushButton_comminicat->setGeometry(QRect(0, 0, 201, 31));
        pushButton_comminicat->setLayoutDirection(Qt::LeftToRight);
        pushButton_comminicat->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);border-color:rgba(0,0,0,255);color: rgba(51, 255, 255,255);border-style:none;border-width:1px;border-radius:0px;font:bold 20px \"\345\256\213\344\275\223\";\n"
"text-align: left;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(42, 46, 49); \n"
"}\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/communication.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_comminicat->setIcon(icon4);
        toolBox->addItem(page_6, QString::fromUtf8(" \350\256\276\345\244\207\351\200\232\350\256\257"));
        page_11 = new QWidget();
        page_11->setObjectName(QStringLiteral("page_11"));
        page_11->setGeometry(QRect(0, 0, 150, 383));
        pushButton_manage = new QPushButton(page_11);
        pushButton_manage->setObjectName(QStringLiteral("pushButton_manage"));
        pushButton_manage->setGeometry(QRect(0, 0, 201, 31));
        pushButton_manage->setLayoutDirection(Qt::LeftToRight);
        pushButton_manage->setAutoFillBackground(false);
        pushButton_manage->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);border-color:rgba(0,0,0,255);color: rgba(51, 255, 255,255);border-style:none;border-width:1px;border-radius:0px;font:bold 20px \"\345\256\213\344\275\223\";\n"
"text-align: left;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(42, 46, 49); \n"
"}\n"
"\n"
""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/User Management.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_manage->setIcon(icon5);
        toolBox->addItem(page_11, QString::fromUtf8(" \347\224\250\346\210\267\347\256\241\347\220\206"));
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        page_7->setGeometry(QRect(0, 0, 150, 383));
        pushButton_6 = new QPushButton(page_7);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(0, 0, 201, 31));
        pushButton_6->setLayoutDirection(Qt::LeftToRight);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);border-color:rgba(0,0,0,255);color: rgba(51, 255, 255,255);border-style:none;border-width:1px;border-radius:0px;font:bold 20px \"\345\256\213\344\275\223\";\n"
"text-align: left;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(42, 46, 49); \n"
"}\n"
"\n"
""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon6);
        toolBox->addItem(page_7, QString::fromUtf8(" \345\270\256\345\212\251\346\226\207\346\241\243"));
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        page_8->setGeometry(QRect(0, 0, 150, 383));
        pushButton_2 = new QPushButton(page_8);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 0, 201, 31));
        pushButton_2->setLayoutDirection(Qt::LeftToRight);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);border-color:rgba(0,0,0,255);color: rgba(51, 255, 255,255);border-style:none;border-width:1px;border-radius:0px;font:bold 20px \"\345\256\213\344\275\223\";\n"
"text-align: left;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(42, 46, 49); \n"
"}\n"
"\n"
""));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/qiut.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon7);
        label_30 = new QLabel(page_8);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(0, 180, 211, 81));
        label_30->setMinimumSize(QSize(111, 0));
        toolBox->addItem(page_8, QString::fromUtf8(" \351\200\200\345\207\272\347\263\273\347\273\237"));

        gridLayout_11->addWidget(toolBox, 1, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));

        gridLayout_11->addWidget(label_2, 1, 1, 1, 1);

        home->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(home);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        statusBar->setFont(font5);
        statusBar->setLayoutDirection(Qt::LeftToRight);
        home->setStatusBar(statusBar);

        retranslateUi(home);

        stackedWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QMainWindow *home)
    {
        home->setWindowTitle(QApplication::translate("home", "MainWindow", Q_NULLPTR));
        groupBox_45->setTitle(QString());
        title->setText(QString());
        left_title->setText(QString());
        label_12->setText(QString());
        right_title->setText(QApplication::translate("home", "2020-08-13", Q_NULLPTR));
        label_32->setText(QString());
        label_233->setText(QString());
        label_3->setText(QString());
        label_31->setText(QString());
        label_57->setText(QString());
        pushButton_main->setText(QApplication::translate("home", "  \346\230\276\347\244\272\347\225\214\351\235\242", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("home", " \346\230\276\347\244\272\347\225\214\351\235\242", Q_NULLPTR));
        pushButton_settting->setText(QApplication::translate("home", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("home", " \347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_chart->setText(QApplication::translate("home", "\345\216\206\345\217\262\346\233\262\347\272\277", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("home", " \345\216\206\345\217\262\346\233\262\347\272\277", Q_NULLPTR));
        pushButton_dataP->setText(QApplication::translate("home", "\346\225\260\346\215\256\346\212\245\350\241\250", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_9), QApplication::translate("home", " \346\225\260\346\215\256\346\212\245\350\241\250", Q_NULLPTR));
        pushButton_sensor->setText(QApplication::translate("home", "\344\274\240 \346\204\237 \345\231\250", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_10), QApplication::translate("home", " \344\274\240 \346\204\237 \345\231\250", Q_NULLPTR));
        pushButton_comminicat->setText(QApplication::translate("home", "\350\256\276\345\244\207\351\200\232\350\256\257", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("home", " \350\256\276\345\244\207\351\200\232\350\256\257", Q_NULLPTR));
        pushButton_manage->setText(QApplication::translate("home", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_11), QApplication::translate("home", " \347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("home", "\345\270\256\345\212\251\346\226\207\346\241\243", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_7), QApplication::translate("home", " \345\270\256\345\212\251\346\226\207\346\241\243", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("home", "\351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
        label_30->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page_8), QApplication::translate("home", " \351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMER_H
