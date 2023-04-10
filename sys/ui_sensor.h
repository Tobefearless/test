/********************************************************************************
** Form generated from reading UI file 'sensor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_H
#define UI_SENSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sensor
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QPushButton *btn_save;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btn_other_save;

    void setupUi(QMainWindow *Sensor)
    {
        if (Sensor->objectName().isEmpty())
            Sensor->setObjectName(QStringLiteral("Sensor"));
        Sensor->resize(1332, 729);
        QFont font;
        font.setPointSize(8);
        Sensor->setFont(font);
        Sensor->setStyleSheet(QLatin1String("/*#Sensor{\n"
"background-color: rgb(14, 159, 255);\n"
"}\n"
""));
        centralwidget = new QWidget(Sensor);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/sensor_table.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setIcon(icon);
        __qtablewidgetitem13->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem15->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem16->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 5, __qtablewidgetitem18);
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem19->setBackground(brush);
        __qtablewidgetitem19->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 6, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setIcon(icon);
        __qtablewidgetitem20->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(1, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(1, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem22->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(1, 2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem23->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(1, 3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 5, __qtablewidgetitem25);
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem26->setBackground(brush1);
        __qtablewidgetitem26->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(1, 6, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setIcon(icon);
        __qtablewidgetitem27->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(2, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(2, 1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem29->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(2, 2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem30->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(2, 3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 4, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 5, __qtablewidgetitem32);
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem33->setBackground(brush2);
        __qtablewidgetitem33->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(2, 6, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setIcon(icon);
        __qtablewidgetitem34->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(3, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(3, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem36->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(3, 2, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem37->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(3, 3, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 4, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 5, __qtablewidgetitem39);
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem40->setBackground(brush3);
        __qtablewidgetitem40->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(3, 6, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setIcon(icon);
        __qtablewidgetitem41->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(4, 0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(4, 1, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem43->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(4, 2, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem44->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(4, 3, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 4, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 5, __qtablewidgetitem46);
        QBrush brush4(QColor(255, 0, 0, 255));
        brush4.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem47->setBackground(brush4);
        __qtablewidgetitem47->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(4, 6, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setIcon(icon);
        __qtablewidgetitem48->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(5, 0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(5, 1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem50->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(5, 2, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem51->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(5, 3, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 4, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 5, __qtablewidgetitem53);
        QBrush brush5(QColor(255, 0, 0, 255));
        brush5.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem54->setBackground(brush5);
        __qtablewidgetitem54->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(5, 6, __qtablewidgetitem54);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(370, 130, 821, 301));
        tableWidget->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QTableView\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0); \n"
"	alternate-background-color:#e3edf9;\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-weight:bold;\n"
"	color:#677483;\n"
"	gridline-color: #ccddf0;\n"
"	background-color:transparent\n"
"}\n"
" \n"
"QTableView::item\n"
"{	\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"\n"
"	color:#677483;\n"
"	gridline-color: #ccddf0; \n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
" \n"
"QTableView::item:selected\n"
"{	\n"
"	color:#677483;\n"
"}\n"
" \n"
"QHeaderView::section {	\n"
"	color: black;\n"
"	font:bold 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	text-align:center;\n"
"	height:32px;\n"
"	background-color: #d1dff0;\n"
"	border:1px solid #8faac9;\n"
"	border-left:none;\n"
"}\n"
" \n"
"// border-left:none;\351\230\262\346\255\242\344\270\255\351\227\264\350\241\250\345\244\264\347\232\204border\351\207\215\345\217\240\n"
"QHeaderView::section:first \n"
"{\n"
"	border"
                        "-left:1px solid #8faac9;\n"
"}\n"
""));
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(false);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(370, 30, 331, 51));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(255, 255, 255);\n"
"			background-color: rgb(255, 255, 127);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 321, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        btn_save = new QPushButton(centralwidget);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setGeometry(QRect(1060, 70, 131, 41));
        btn_save->setFont(font1);
        btn_save->setStyleSheet(QLatin1String("QPushButton {\n"
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
        tableWidget_2 = new QTableWidget(centralwidget);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem58);
        if (tableWidget_2->rowCount() < 3)
            tableWidget_2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem61);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/CO.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setIcon(icon1);
        __qtablewidgetitem62->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(0, 0, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem63->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(0, 1, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget_2->setItem(0, 2, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem65->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(0, 3, __qtablewidgetitem65);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/CO2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setIcon(icon2);
        __qtablewidgetitem66->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(1, 0, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem67->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(1, 1, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        __qtablewidgetitem68->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget_2->setItem(1, 2, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        __qtablewidgetitem69->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem69->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(1, 3, __qtablewidgetitem69);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/NH3.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        __qtablewidgetitem70->setIcon(icon3);
        __qtablewidgetitem70->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(2, 0, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        __qtablewidgetitem71->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem71->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(2, 1, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        __qtablewidgetitem72->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget_2->setItem(2, 2, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        __qtablewidgetitem73->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem73->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(2, 3, __qtablewidgetitem73);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(370, 510, 821, 156));
        tableWidget_2->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QTableView\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0); \n"
"	alternate-background-color:#e3edf9;\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-weight:bold;\n"
"	color:#677483;\n"
"	gridline-color: #ccddf0;\n"
"	background-color:transparent\n"
"}\n"
" \n"
"QTableView::item\n"
"{	\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"\n"
"	color:#677483;\n"
"	gridline-color: #ccddf0; \n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
" \n"
"QTableView::item:selected\n"
"{	\n"
"	color:#677483;\n"
"}\n"
" \n"
"QHeaderView::section {	\n"
"	color: black;\n"
"	font:bold 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	text-align:center;\n"
"	height:32px;\n"
"	background-color: #d1dff0;\n"
"	border:1px solid #8faac9;\n"
"	border-left:none;\n"
"}\n"
" \n"
"// border-left:none;\351\230\262\346\255\242\344\270\255\351\227\264\350\241\250\345\244\264\347\232\204border\351\207\215\345\217\240\n"
"QHeaderView::section:first \n"
"{\n"
"	border"
                        "-left:1px solid #8faac9;\n"
"}\n"
""));
        tableWidget_2->setAlternatingRowColors(false);
        tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_2->setSortingEnabled(false);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(40);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(670, 90, 161, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(19);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(680, 470, 171, 31));
        label_3->setFont(font2);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        btn_other_save = new QPushButton(centralwidget);
        btn_other_save->setObjectName(QStringLiteral("btn_other_save"));
        btn_other_save->setGeometry(QRect(1070, 460, 131, 41));
        btn_other_save->setFont(font1);
        btn_other_save->setStyleSheet(QLatin1String("QPushButton {\n"
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
        Sensor->setCentralWidget(centralwidget);

        retranslateUi(Sensor);

        QMetaObject::connectSlotsByName(Sensor);
    } // setupUi

    void retranslateUi(QMainWindow *Sensor)
    {
        Sensor->setWindowTitle(QApplication::translate("Sensor", "MainWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Sensor", "\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Sensor", "\350\256\276\345\244\207\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Sensor", "\345\256\236\346\227\266\346\270\251\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Sensor", "\345\256\236\346\227\266\346\271\277\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Sensor", "\346\270\251\345\272\246\344\277\256\346\255\243", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Sensor", "\346\271\277\345\272\246\344\277\256\346\255\243", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Sensor", "\347\212\266\346\200\201", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("Sensor", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("Sensor", "SCSQ210124001-1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 2);
        ___qtablewidgetitem9->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 3);
        ___qtablewidgetitem10->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 4);
        ___qtablewidgetitem11->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 5);
        ___qtablewidgetitem12->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 6);
        ___qtablewidgetitem13->setText(QApplication::translate("Sensor", "\345\274\202\345\270\270", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("Sensor", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 1);
        ___qtablewidgetitem15->setText(QApplication::translate("Sensor", "SCSQ210124001-2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 2);
        ___qtablewidgetitem16->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 3);
        ___qtablewidgetitem17->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(1, 4);
        ___qtablewidgetitem18->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(1, 5);
        ___qtablewidgetitem19->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(1, 6);
        ___qtablewidgetitem20->setText(QApplication::translate("Sensor", "\345\274\202\345\270\270", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("Sensor", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("Sensor", "SCSQ210124001-3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 2);
        ___qtablewidgetitem23->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(2, 3);
        ___qtablewidgetitem24->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(2, 4);
        ___qtablewidgetitem25->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(2, 5);
        ___qtablewidgetitem26->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(2, 6);
        ___qtablewidgetitem27->setText(QApplication::translate("Sensor", "\345\274\202\345\270\270", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(3, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("Sensor", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(3, 1);
        ___qtablewidgetitem29->setText(QApplication::translate("Sensor", "SCSQ210124001-4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(3, 2);
        ___qtablewidgetitem30->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(3, 3);
        ___qtablewidgetitem31->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(3, 4);
        ___qtablewidgetitem32->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(3, 5);
        ___qtablewidgetitem33->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(3, 6);
        ___qtablewidgetitem34->setText(QApplication::translate("Sensor", "\345\274\202\345\270\270", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(4, 0);
        ___qtablewidgetitem35->setText(QApplication::translate("Sensor", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(4, 1);
        ___qtablewidgetitem36->setText(QApplication::translate("Sensor", "SCSQ210124002-1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(4, 2);
        ___qtablewidgetitem37->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(4, 3);
        ___qtablewidgetitem38->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(4, 4);
        ___qtablewidgetitem39->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(4, 5);
        ___qtablewidgetitem40->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(4, 6);
        ___qtablewidgetitem41->setText(QApplication::translate("Sensor", "\345\274\202\345\270\270", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(5, 0);
        ___qtablewidgetitem42->setText(QApplication::translate("Sensor", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(5, 1);
        ___qtablewidgetitem43->setText(QApplication::translate("Sensor", "SCSQ210124002-2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(5, 2);
        ___qtablewidgetitem44->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->item(5, 3);
        ___qtablewidgetitem45->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->item(5, 4);
        ___qtablewidgetitem46->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->item(5, 5);
        ___qtablewidgetitem47->setText(QApplication::translate("Sensor", "0.0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->item(5, 6);
        ___qtablewidgetitem48->setText(QApplication::translate("Sensor", "\345\274\202\345\270\270", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Sensor", "\346\217\220\347\244\272\357\274\232\345\217\214\345\207\273\351\274\240\346\240\207\357\274\214\344\277\256\346\224\271\345\217\202\346\225\260\357\274\201", Q_NULLPTR));
        btn_save->setText(QApplication::translate("Sensor", "\344\277\235\345\255\230", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem49->setText(QApplication::translate("Sensor", "\350\256\276\345\244\207\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem50->setText(QApplication::translate("Sensor", "\345\256\236\346\227\266\346\265\223\345\272\246\357\274\210ppm\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem51->setText(QApplication::translate("Sensor", "\344\277\256\346\255\243\346\265\223\345\272\246\357\274\210ppm\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem52->setText(QApplication::translate("Sensor", "\346\230\276\347\244\272\346\265\223\345\272\246\357\274\210ppm\357\274\211", Q_NULLPTR));

        const bool __sortingEnabled1 = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget_2->item(0, 0);
        ___qtablewidgetitem53->setText(QApplication::translate("Sensor", "\344\270\200\346\260\247\345\214\226\347\242\263", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget_2->item(0, 1);
        ___qtablewidgetitem54->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget_2->item(0, 2);
        ___qtablewidgetitem55->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget_2->item(0, 3);
        ___qtablewidgetitem56->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget_2->item(1, 0);
        ___qtablewidgetitem57->setText(QApplication::translate("Sensor", "\344\272\214\346\260\247\345\214\226\347\242\263", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget_2->item(1, 1);
        ___qtablewidgetitem58->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget_2->item(1, 2);
        ___qtablewidgetitem59->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget_2->item(1, 3);
        ___qtablewidgetitem60->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget_2->item(2, 0);
        ___qtablewidgetitem61->setText(QApplication::translate("Sensor", "\346\260\250\346\260\224", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget_2->item(2, 1);
        ___qtablewidgetitem62->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget_2->item(2, 2);
        ___qtablewidgetitem63->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget_2->item(2, 3);
        ___qtablewidgetitem64->setText(QApplication::translate("Sensor", "0", Q_NULLPTR));
        tableWidget_2->setSortingEnabled(__sortingEnabled1);

        label_2->setText(QApplication::translate("Sensor", "\346\270\251\346\271\277\345\272\246\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        label_3->setText(QApplication::translate("Sensor", "\345\205\266\344\273\226\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        btn_other_save->setText(QApplication::translate("Sensor", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Sensor: public Ui_Sensor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_H
