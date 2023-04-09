/********************************************************************************
** Form generated from reading UI file 'seed1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEED1_H
#define UI_SEED1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Seed
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *button_save;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *button_stop;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *butto_back;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *title;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_head;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *Seed)
    {
        if (Seed->objectName().isEmpty())
            Seed->setObjectName(QStringLiteral("Seed"));
        Seed->resize(1927, 421);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(9);
        Seed->setFont(font);
        centralwidget = new QWidget(Seed);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        button_save = new QPushButton(centralwidget);
        button_save->setObjectName(QStringLiteral("button_save"));
        button_save->setMinimumSize(QSize(121, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("AcadEref"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        button_save->setFont(font1);
        button_save->setStyleSheet(QLatin1String("QPushButton {\n"
"    border:5px  outset grey;\n"
"    padding:2px 4px;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(204, 204, 204, 255), stop:0.50001 rgba(216, 216, 216, 255));\n"
"\n"
"   \n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    border:5px  outset grey;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"\n"
"    \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px  inset grey;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"\n"
"}"));

        horizontalLayout_2->addWidget(button_save);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        button_stop = new QPushButton(centralwidget);
        button_stop->setObjectName(QStringLiteral("button_stop"));
        button_stop->setMinimumSize(QSize(121, 41));
        button_stop->setFont(font1);
        button_stop->setStyleSheet(QLatin1String("QPushButton {\n"
"    border:5px  outset grey;\n"
"    padding:2px 4px;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(204, 204, 204, 255), stop:0.50001 rgba(216, 216, 216, 255));\n"
"\n"
"   \n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    border:5px  outset grey;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"\n"
"    \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px  inset grey;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"\n"
"}"));

        horizontalLayout_2->addWidget(button_stop);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        butto_back = new QPushButton(centralwidget);
        butto_back->setObjectName(QStringLiteral("butto_back"));
        butto_back->setMinimumSize(QSize(121, 41));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        butto_back->setFont(font2);
        butto_back->setStyleSheet(QLatin1String("QPushButton {\n"
"    border:5px  outset grey;\n"
"    padding:2px 4px;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(204, 204, 204, 255), stop:0.50001 rgba(216, 216, 216, 255));\n"
"\n"
"   \n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    border:5px  outset grey;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
"\n"
"\n"
"    \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border:3px  inset grey;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
"\n"
"}"));

        horizontalLayout_2->addWidget(butto_back);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(255, 255, 255);\n"
"			background-color: rgb(255, 255, 127);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        title = new QLabel(centralwidget);
        title->setObjectName(QStringLiteral("title"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(28);
        font4.setBold(true);
        font4.setWeight(75);
        title->setFont(font4);

        horizontalLayout->addWidget(title);

        horizontalSpacer_2 = new QSpacerItem(54, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget_head = new QTableWidget(centralwidget);
        if (tableWidget_head->columnCount() < 41)
            tableWidget_head->setColumnCount(41);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_head->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_head->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget_head->rowCount() < 3)
            tableWidget_head->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_head->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_head->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_head->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_head->setItem(0, 0, __qtablewidgetitem5);
        tableWidget_head->setObjectName(QStringLiteral("tableWidget_head"));
        tableWidget_head->setMaximumSize(QSize(16777215, 115));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        tableWidget_head->setFont(font5);
        tableWidget_head->setStyleSheet(QString::fromUtf8("\n"
" \n"
"QHeaderView::section {	\n"
"	color: black;\n"
"	font:bold 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	text-align:center;\n"
"	background-color: #d1dff0;\n"
"	border:1px solid #8faac9;\n"
"	border-left:none;\n"
"	width :25px;\n"
"\n"
"}\n"
" \n"
"\n"
"\n"
""));
        tableWidget_head->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_head->setTabKeyNavigation(false);
        tableWidget_head->setProperty("showDropIndicator", QVariant(false));
        tableWidget_head->setDragDropOverwriteMode(false);
        tableWidget_head->setShowGrid(true);
        tableWidget_head->setGridStyle(Qt::SolidLine);
        tableWidget_head->setSortingEnabled(false);
        tableWidget_head->setCornerButtonEnabled(false);
        tableWidget_head->setColumnCount(41);
        tableWidget_head->horizontalHeader()->setVisible(false);
        tableWidget_head->horizontalHeader()->setDefaultSectionSize(45);
        tableWidget_head->horizontalHeader()->setHighlightSections(true);
        tableWidget_head->verticalHeader()->setVisible(true);
        tableWidget_head->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget_head->verticalHeader()->setHighlightSections(true);

        verticalLayout->addWidget(tableWidget_head);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 41)
            tableWidget->setColumnCount(41);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(17, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(18, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(19, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(20, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(21, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(22, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(23, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(24, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(25, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(26, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(27, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(28, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(29, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(30, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(31, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(32, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(33, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(34, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(35, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(36, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(37, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(38, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(39, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(40, __qtablewidgetitem46);
        if (tableWidget->rowCount() < 30)
            tableWidget->setRowCount(30);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(21, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(22, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(23, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(24, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(25, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(26, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(27, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(28, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(29, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        __qtablewidgetitem77->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        __qtablewidgetitem78->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 1, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        __qtablewidgetitem79->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 3, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        __qtablewidgetitem80->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 5, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        __qtablewidgetitem81->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 6, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        __qtablewidgetitem82->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 7, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        __qtablewidgetitem83->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 8, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        __qtablewidgetitem84->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 9, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        __qtablewidgetitem85->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 10, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        __qtablewidgetitem86->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 11, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        __qtablewidgetitem87->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 12, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        __qtablewidgetitem88->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 13, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        __qtablewidgetitem89->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 14, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        __qtablewidgetitem90->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 15, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        __qtablewidgetitem91->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 16, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        __qtablewidgetitem92->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 17, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        __qtablewidgetitem93->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 18, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        __qtablewidgetitem94->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 19, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        __qtablewidgetitem95->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 20, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        __qtablewidgetitem96->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 21, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        __qtablewidgetitem97->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 22, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        __qtablewidgetitem98->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 23, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        __qtablewidgetitem99->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 24, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        __qtablewidgetitem100->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 25, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        __qtablewidgetitem101->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 26, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        __qtablewidgetitem102->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 27, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        __qtablewidgetitem103->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 28, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        __qtablewidgetitem104->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 29, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        __qtablewidgetitem105->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 30, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        __qtablewidgetitem106->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 31, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        __qtablewidgetitem107->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 32, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        __qtablewidgetitem108->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 35, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        __qtablewidgetitem109->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 36, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        tableWidget->setItem(1, 8, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        tableWidget->setItem(1, 9, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        tableWidget->setItem(1, 10, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        tableWidget->setItem(1, 11, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        tableWidget->setItem(1, 12, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        tableWidget->setItem(1, 13, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        tableWidget->setItem(1, 14, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        tableWidget->setItem(1, 15, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        tableWidget->setItem(1, 16, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        tableWidget->setItem(1, 32, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem125);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        tableWidget->setItem(2, 6, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        tableWidget->setItem(2, 7, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        tableWidget->setItem(2, 8, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        tableWidget->setItem(2, 9, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        tableWidget->setItem(2, 10, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        tableWidget->setItem(2, 11, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        tableWidget->setItem(2, 12, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        tableWidget->setItem(2, 13, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        tableWidget->setItem(2, 14, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        tableWidget->setItem(2, 15, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        tableWidget->setItem(2, 16, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        tableWidget->setItem(2, 32, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        tableWidget->setItem(3, 6, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        tableWidget->setItem(3, 7, __qtablewidgetitem142);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        tableWidget->setItem(3, 8, __qtablewidgetitem143);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        tableWidget->setItem(3, 9, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        tableWidget->setItem(3, 10, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        tableWidget->setItem(3, 11, __qtablewidgetitem146);
        QTableWidgetItem *__qtablewidgetitem147 = new QTableWidgetItem();
        tableWidget->setItem(3, 12, __qtablewidgetitem147);
        QTableWidgetItem *__qtablewidgetitem148 = new QTableWidgetItem();
        tableWidget->setItem(3, 13, __qtablewidgetitem148);
        QTableWidgetItem *__qtablewidgetitem149 = new QTableWidgetItem();
        tableWidget->setItem(3, 14, __qtablewidgetitem149);
        QTableWidgetItem *__qtablewidgetitem150 = new QTableWidgetItem();
        tableWidget->setItem(3, 15, __qtablewidgetitem150);
        QTableWidgetItem *__qtablewidgetitem151 = new QTableWidgetItem();
        tableWidget->setItem(3, 16, __qtablewidgetitem151);
        QTableWidgetItem *__qtablewidgetitem152 = new QTableWidgetItem();
        tableWidget->setItem(3, 32, __qtablewidgetitem152);
        QTableWidgetItem *__qtablewidgetitem153 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem153);
        QTableWidgetItem *__qtablewidgetitem154 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem154);
        QTableWidgetItem *__qtablewidgetitem155 = new QTableWidgetItem();
        tableWidget->setItem(4, 6, __qtablewidgetitem155);
        QTableWidgetItem *__qtablewidgetitem156 = new QTableWidgetItem();
        tableWidget->setItem(4, 7, __qtablewidgetitem156);
        QTableWidgetItem *__qtablewidgetitem157 = new QTableWidgetItem();
        tableWidget->setItem(4, 8, __qtablewidgetitem157);
        QTableWidgetItem *__qtablewidgetitem158 = new QTableWidgetItem();
        tableWidget->setItem(4, 9, __qtablewidgetitem158);
        QTableWidgetItem *__qtablewidgetitem159 = new QTableWidgetItem();
        tableWidget->setItem(4, 10, __qtablewidgetitem159);
        QTableWidgetItem *__qtablewidgetitem160 = new QTableWidgetItem();
        tableWidget->setItem(4, 11, __qtablewidgetitem160);
        QTableWidgetItem *__qtablewidgetitem161 = new QTableWidgetItem();
        tableWidget->setItem(4, 12, __qtablewidgetitem161);
        QTableWidgetItem *__qtablewidgetitem162 = new QTableWidgetItem();
        tableWidget->setItem(4, 13, __qtablewidgetitem162);
        QTableWidgetItem *__qtablewidgetitem163 = new QTableWidgetItem();
        tableWidget->setItem(4, 14, __qtablewidgetitem163);
        QTableWidgetItem *__qtablewidgetitem164 = new QTableWidgetItem();
        tableWidget->setItem(4, 15, __qtablewidgetitem164);
        QTableWidgetItem *__qtablewidgetitem165 = new QTableWidgetItem();
        tableWidget->setItem(4, 16, __qtablewidgetitem165);
        QTableWidgetItem *__qtablewidgetitem166 = new QTableWidgetItem();
        tableWidget->setItem(4, 32, __qtablewidgetitem166);
        QTableWidgetItem *__qtablewidgetitem167 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem167);
        QTableWidgetItem *__qtablewidgetitem168 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem168);
        QTableWidgetItem *__qtablewidgetitem169 = new QTableWidgetItem();
        tableWidget->setItem(5, 3, __qtablewidgetitem169);
        QTableWidgetItem *__qtablewidgetitem170 = new QTableWidgetItem();
        tableWidget->setItem(5, 6, __qtablewidgetitem170);
        QTableWidgetItem *__qtablewidgetitem171 = new QTableWidgetItem();
        tableWidget->setItem(5, 7, __qtablewidgetitem171);
        QTableWidgetItem *__qtablewidgetitem172 = new QTableWidgetItem();
        tableWidget->setItem(5, 8, __qtablewidgetitem172);
        QTableWidgetItem *__qtablewidgetitem173 = new QTableWidgetItem();
        tableWidget->setItem(5, 9, __qtablewidgetitem173);
        QTableWidgetItem *__qtablewidgetitem174 = new QTableWidgetItem();
        tableWidget->setItem(5, 10, __qtablewidgetitem174);
        QTableWidgetItem *__qtablewidgetitem175 = new QTableWidgetItem();
        tableWidget->setItem(5, 11, __qtablewidgetitem175);
        QTableWidgetItem *__qtablewidgetitem176 = new QTableWidgetItem();
        tableWidget->setItem(5, 12, __qtablewidgetitem176);
        QTableWidgetItem *__qtablewidgetitem177 = new QTableWidgetItem();
        tableWidget->setItem(5, 13, __qtablewidgetitem177);
        QTableWidgetItem *__qtablewidgetitem178 = new QTableWidgetItem();
        tableWidget->setItem(5, 32, __qtablewidgetitem178);
        QTableWidgetItem *__qtablewidgetitem179 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem179);
        QTableWidgetItem *__qtablewidgetitem180 = new QTableWidgetItem();
        tableWidget->setItem(6, 1, __qtablewidgetitem180);
        QTableWidgetItem *__qtablewidgetitem181 = new QTableWidgetItem();
        tableWidget->setItem(6, 6, __qtablewidgetitem181);
        QTableWidgetItem *__qtablewidgetitem182 = new QTableWidgetItem();
        tableWidget->setItem(6, 7, __qtablewidgetitem182);
        QTableWidgetItem *__qtablewidgetitem183 = new QTableWidgetItem();
        tableWidget->setItem(6, 8, __qtablewidgetitem183);
        QTableWidgetItem *__qtablewidgetitem184 = new QTableWidgetItem();
        tableWidget->setItem(6, 9, __qtablewidgetitem184);
        QTableWidgetItem *__qtablewidgetitem185 = new QTableWidgetItem();
        tableWidget->setItem(6, 10, __qtablewidgetitem185);
        QTableWidgetItem *__qtablewidgetitem186 = new QTableWidgetItem();
        tableWidget->setItem(6, 11, __qtablewidgetitem186);
        QTableWidgetItem *__qtablewidgetitem187 = new QTableWidgetItem();
        tableWidget->setItem(6, 12, __qtablewidgetitem187);
        QTableWidgetItem *__qtablewidgetitem188 = new QTableWidgetItem();
        tableWidget->setItem(6, 13, __qtablewidgetitem188);
        QTableWidgetItem *__qtablewidgetitem189 = new QTableWidgetItem();
        tableWidget->setItem(6, 32, __qtablewidgetitem189);
        QTableWidgetItem *__qtablewidgetitem190 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem190);
        QTableWidgetItem *__qtablewidgetitem191 = new QTableWidgetItem();
        tableWidget->setItem(7, 1, __qtablewidgetitem191);
        QTableWidgetItem *__qtablewidgetitem192 = new QTableWidgetItem();
        tableWidget->setItem(7, 6, __qtablewidgetitem192);
        QTableWidgetItem *__qtablewidgetitem193 = new QTableWidgetItem();
        tableWidget->setItem(7, 7, __qtablewidgetitem193);
        QTableWidgetItem *__qtablewidgetitem194 = new QTableWidgetItem();
        tableWidget->setItem(7, 8, __qtablewidgetitem194);
        QTableWidgetItem *__qtablewidgetitem195 = new QTableWidgetItem();
        tableWidget->setItem(7, 9, __qtablewidgetitem195);
        QTableWidgetItem *__qtablewidgetitem196 = new QTableWidgetItem();
        tableWidget->setItem(7, 10, __qtablewidgetitem196);
        QTableWidgetItem *__qtablewidgetitem197 = new QTableWidgetItem();
        tableWidget->setItem(7, 11, __qtablewidgetitem197);
        QTableWidgetItem *__qtablewidgetitem198 = new QTableWidgetItem();
        tableWidget->setItem(7, 12, __qtablewidgetitem198);
        QTableWidgetItem *__qtablewidgetitem199 = new QTableWidgetItem();
        tableWidget->setItem(7, 13, __qtablewidgetitem199);
        QTableWidgetItem *__qtablewidgetitem200 = new QTableWidgetItem();
        tableWidget->setItem(7, 32, __qtablewidgetitem200);
        QTableWidgetItem *__qtablewidgetitem201 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem201);
        QTableWidgetItem *__qtablewidgetitem202 = new QTableWidgetItem();
        tableWidget->setItem(8, 1, __qtablewidgetitem202);
        QTableWidgetItem *__qtablewidgetitem203 = new QTableWidgetItem();
        tableWidget->setItem(8, 6, __qtablewidgetitem203);
        QTableWidgetItem *__qtablewidgetitem204 = new QTableWidgetItem();
        tableWidget->setItem(8, 7, __qtablewidgetitem204);
        QTableWidgetItem *__qtablewidgetitem205 = new QTableWidgetItem();
        tableWidget->setItem(8, 8, __qtablewidgetitem205);
        QTableWidgetItem *__qtablewidgetitem206 = new QTableWidgetItem();
        tableWidget->setItem(8, 9, __qtablewidgetitem206);
        QTableWidgetItem *__qtablewidgetitem207 = new QTableWidgetItem();
        tableWidget->setItem(8, 10, __qtablewidgetitem207);
        QTableWidgetItem *__qtablewidgetitem208 = new QTableWidgetItem();
        tableWidget->setItem(8, 11, __qtablewidgetitem208);
        QTableWidgetItem *__qtablewidgetitem209 = new QTableWidgetItem();
        tableWidget->setItem(8, 12, __qtablewidgetitem209);
        QTableWidgetItem *__qtablewidgetitem210 = new QTableWidgetItem();
        tableWidget->setItem(8, 13, __qtablewidgetitem210);
        QTableWidgetItem *__qtablewidgetitem211 = new QTableWidgetItem();
        tableWidget->setItem(8, 32, __qtablewidgetitem211);
        QTableWidgetItem *__qtablewidgetitem212 = new QTableWidgetItem();
        tableWidget->setItem(9, 0, __qtablewidgetitem212);
        QTableWidgetItem *__qtablewidgetitem213 = new QTableWidgetItem();
        tableWidget->setItem(9, 1, __qtablewidgetitem213);
        QTableWidgetItem *__qtablewidgetitem214 = new QTableWidgetItem();
        tableWidget->setItem(9, 3, __qtablewidgetitem214);
        QTableWidgetItem *__qtablewidgetitem215 = new QTableWidgetItem();
        tableWidget->setItem(9, 5, __qtablewidgetitem215);
        QTableWidgetItem *__qtablewidgetitem216 = new QTableWidgetItem();
        tableWidget->setItem(9, 6, __qtablewidgetitem216);
        QTableWidgetItem *__qtablewidgetitem217 = new QTableWidgetItem();
        tableWidget->setItem(9, 7, __qtablewidgetitem217);
        QTableWidgetItem *__qtablewidgetitem218 = new QTableWidgetItem();
        tableWidget->setItem(9, 8, __qtablewidgetitem218);
        QTableWidgetItem *__qtablewidgetitem219 = new QTableWidgetItem();
        tableWidget->setItem(9, 9, __qtablewidgetitem219);
        QTableWidgetItem *__qtablewidgetitem220 = new QTableWidgetItem();
        tableWidget->setItem(9, 10, __qtablewidgetitem220);
        QTableWidgetItem *__qtablewidgetitem221 = new QTableWidgetItem();
        tableWidget->setItem(9, 11, __qtablewidgetitem221);
        QTableWidgetItem *__qtablewidgetitem222 = new QTableWidgetItem();
        tableWidget->setItem(9, 12, __qtablewidgetitem222);
        QTableWidgetItem *__qtablewidgetitem223 = new QTableWidgetItem();
        tableWidget->setItem(9, 13, __qtablewidgetitem223);
        QTableWidgetItem *__qtablewidgetitem224 = new QTableWidgetItem();
        tableWidget->setItem(10, 0, __qtablewidgetitem224);
        QTableWidgetItem *__qtablewidgetitem225 = new QTableWidgetItem();
        tableWidget->setItem(10, 1, __qtablewidgetitem225);
        QTableWidgetItem *__qtablewidgetitem226 = new QTableWidgetItem();
        tableWidget->setItem(10, 3, __qtablewidgetitem226);
        QTableWidgetItem *__qtablewidgetitem227 = new QTableWidgetItem();
        tableWidget->setItem(10, 6, __qtablewidgetitem227);
        QTableWidgetItem *__qtablewidgetitem228 = new QTableWidgetItem();
        tableWidget->setItem(10, 7, __qtablewidgetitem228);
        QTableWidgetItem *__qtablewidgetitem229 = new QTableWidgetItem();
        tableWidget->setItem(10, 8, __qtablewidgetitem229);
        QTableWidgetItem *__qtablewidgetitem230 = new QTableWidgetItem();
        tableWidget->setItem(10, 9, __qtablewidgetitem230);
        QTableWidgetItem *__qtablewidgetitem231 = new QTableWidgetItem();
        tableWidget->setItem(10, 10, __qtablewidgetitem231);
        QTableWidgetItem *__qtablewidgetitem232 = new QTableWidgetItem();
        tableWidget->setItem(10, 11, __qtablewidgetitem232);
        QTableWidgetItem *__qtablewidgetitem233 = new QTableWidgetItem();
        tableWidget->setItem(10, 12, __qtablewidgetitem233);
        QTableWidgetItem *__qtablewidgetitem234 = new QTableWidgetItem();
        tableWidget->setItem(10, 13, __qtablewidgetitem234);
        QTableWidgetItem *__qtablewidgetitem235 = new QTableWidgetItem();
        tableWidget->setItem(11, 0, __qtablewidgetitem235);
        QTableWidgetItem *__qtablewidgetitem236 = new QTableWidgetItem();
        tableWidget->setItem(11, 1, __qtablewidgetitem236);
        QTableWidgetItem *__qtablewidgetitem237 = new QTableWidgetItem();
        tableWidget->setItem(11, 6, __qtablewidgetitem237);
        QTableWidgetItem *__qtablewidgetitem238 = new QTableWidgetItem();
        tableWidget->setItem(11, 7, __qtablewidgetitem238);
        QTableWidgetItem *__qtablewidgetitem239 = new QTableWidgetItem();
        tableWidget->setItem(11, 8, __qtablewidgetitem239);
        QTableWidgetItem *__qtablewidgetitem240 = new QTableWidgetItem();
        tableWidget->setItem(11, 9, __qtablewidgetitem240);
        QTableWidgetItem *__qtablewidgetitem241 = new QTableWidgetItem();
        tableWidget->setItem(11, 10, __qtablewidgetitem241);
        QTableWidgetItem *__qtablewidgetitem242 = new QTableWidgetItem();
        tableWidget->setItem(11, 11, __qtablewidgetitem242);
        QTableWidgetItem *__qtablewidgetitem243 = new QTableWidgetItem();
        tableWidget->setItem(11, 12, __qtablewidgetitem243);
        QTableWidgetItem *__qtablewidgetitem244 = new QTableWidgetItem();
        tableWidget->setItem(11, 13, __qtablewidgetitem244);
        QTableWidgetItem *__qtablewidgetitem245 = new QTableWidgetItem();
        tableWidget->setItem(12, 0, __qtablewidgetitem245);
        QTableWidgetItem *__qtablewidgetitem246 = new QTableWidgetItem();
        tableWidget->setItem(12, 1, __qtablewidgetitem246);
        QTableWidgetItem *__qtablewidgetitem247 = new QTableWidgetItem();
        tableWidget->setItem(12, 6, __qtablewidgetitem247);
        QTableWidgetItem *__qtablewidgetitem248 = new QTableWidgetItem();
        tableWidget->setItem(12, 7, __qtablewidgetitem248);
        QTableWidgetItem *__qtablewidgetitem249 = new QTableWidgetItem();
        tableWidget->setItem(12, 8, __qtablewidgetitem249);
        QTableWidgetItem *__qtablewidgetitem250 = new QTableWidgetItem();
        tableWidget->setItem(12, 9, __qtablewidgetitem250);
        QTableWidgetItem *__qtablewidgetitem251 = new QTableWidgetItem();
        tableWidget->setItem(12, 10, __qtablewidgetitem251);
        QTableWidgetItem *__qtablewidgetitem252 = new QTableWidgetItem();
        tableWidget->setItem(12, 11, __qtablewidgetitem252);
        QTableWidgetItem *__qtablewidgetitem253 = new QTableWidgetItem();
        tableWidget->setItem(12, 12, __qtablewidgetitem253);
        QTableWidgetItem *__qtablewidgetitem254 = new QTableWidgetItem();
        tableWidget->setItem(13, 0, __qtablewidgetitem254);
        QTableWidgetItem *__qtablewidgetitem255 = new QTableWidgetItem();
        tableWidget->setItem(13, 1, __qtablewidgetitem255);
        QTableWidgetItem *__qtablewidgetitem256 = new QTableWidgetItem();
        tableWidget->setItem(13, 6, __qtablewidgetitem256);
        QTableWidgetItem *__qtablewidgetitem257 = new QTableWidgetItem();
        tableWidget->setItem(13, 7, __qtablewidgetitem257);
        QTableWidgetItem *__qtablewidgetitem258 = new QTableWidgetItem();
        tableWidget->setItem(13, 8, __qtablewidgetitem258);
        QTableWidgetItem *__qtablewidgetitem259 = new QTableWidgetItem();
        tableWidget->setItem(13, 9, __qtablewidgetitem259);
        QTableWidgetItem *__qtablewidgetitem260 = new QTableWidgetItem();
        tableWidget->setItem(13, 10, __qtablewidgetitem260);
        QTableWidgetItem *__qtablewidgetitem261 = new QTableWidgetItem();
        tableWidget->setItem(13, 11, __qtablewidgetitem261);
        QTableWidgetItem *__qtablewidgetitem262 = new QTableWidgetItem();
        tableWidget->setItem(13, 12, __qtablewidgetitem262);
        QTableWidgetItem *__qtablewidgetitem263 = new QTableWidgetItem();
        tableWidget->setItem(14, 0, __qtablewidgetitem263);
        QTableWidgetItem *__qtablewidgetitem264 = new QTableWidgetItem();
        tableWidget->setItem(14, 1, __qtablewidgetitem264);
        QTableWidgetItem *__qtablewidgetitem265 = new QTableWidgetItem();
        tableWidget->setItem(14, 6, __qtablewidgetitem265);
        QTableWidgetItem *__qtablewidgetitem266 = new QTableWidgetItem();
        tableWidget->setItem(14, 7, __qtablewidgetitem266);
        QTableWidgetItem *__qtablewidgetitem267 = new QTableWidgetItem();
        tableWidget->setItem(14, 8, __qtablewidgetitem267);
        QTableWidgetItem *__qtablewidgetitem268 = new QTableWidgetItem();
        tableWidget->setItem(14, 9, __qtablewidgetitem268);
        QTableWidgetItem *__qtablewidgetitem269 = new QTableWidgetItem();
        tableWidget->setItem(14, 10, __qtablewidgetitem269);
        QTableWidgetItem *__qtablewidgetitem270 = new QTableWidgetItem();
        tableWidget->setItem(14, 11, __qtablewidgetitem270);
        QTableWidgetItem *__qtablewidgetitem271 = new QTableWidgetItem();
        tableWidget->setItem(14, 12, __qtablewidgetitem271);
        QTableWidgetItem *__qtablewidgetitem272 = new QTableWidgetItem();
        tableWidget->setItem(15, 0, __qtablewidgetitem272);
        QTableWidgetItem *__qtablewidgetitem273 = new QTableWidgetItem();
        tableWidget->setItem(15, 1, __qtablewidgetitem273);
        QTableWidgetItem *__qtablewidgetitem274 = new QTableWidgetItem();
        tableWidget->setItem(15, 6, __qtablewidgetitem274);
        QTableWidgetItem *__qtablewidgetitem275 = new QTableWidgetItem();
        tableWidget->setItem(15, 7, __qtablewidgetitem275);
        QTableWidgetItem *__qtablewidgetitem276 = new QTableWidgetItem();
        tableWidget->setItem(15, 8, __qtablewidgetitem276);
        QTableWidgetItem *__qtablewidgetitem277 = new QTableWidgetItem();
        tableWidget->setItem(15, 9, __qtablewidgetitem277);
        QTableWidgetItem *__qtablewidgetitem278 = new QTableWidgetItem();
        tableWidget->setItem(15, 10, __qtablewidgetitem278);
        QTableWidgetItem *__qtablewidgetitem279 = new QTableWidgetItem();
        tableWidget->setItem(15, 11, __qtablewidgetitem279);
        QTableWidgetItem *__qtablewidgetitem280 = new QTableWidgetItem();
        tableWidget->setItem(15, 12, __qtablewidgetitem280);
        QTableWidgetItem *__qtablewidgetitem281 = new QTableWidgetItem();
        tableWidget->setItem(16, 0, __qtablewidgetitem281);
        QTableWidgetItem *__qtablewidgetitem282 = new QTableWidgetItem();
        tableWidget->setItem(16, 1, __qtablewidgetitem282);
        QTableWidgetItem *__qtablewidgetitem283 = new QTableWidgetItem();
        tableWidget->setItem(16, 6, __qtablewidgetitem283);
        QTableWidgetItem *__qtablewidgetitem284 = new QTableWidgetItem();
        tableWidget->setItem(16, 7, __qtablewidgetitem284);
        QTableWidgetItem *__qtablewidgetitem285 = new QTableWidgetItem();
        tableWidget->setItem(16, 8, __qtablewidgetitem285);
        QTableWidgetItem *__qtablewidgetitem286 = new QTableWidgetItem();
        tableWidget->setItem(16, 9, __qtablewidgetitem286);
        QTableWidgetItem *__qtablewidgetitem287 = new QTableWidgetItem();
        tableWidget->setItem(16, 10, __qtablewidgetitem287);
        QTableWidgetItem *__qtablewidgetitem288 = new QTableWidgetItem();
        tableWidget->setItem(16, 11, __qtablewidgetitem288);
        QTableWidgetItem *__qtablewidgetitem289 = new QTableWidgetItem();
        tableWidget->setItem(16, 12, __qtablewidgetitem289);
        QTableWidgetItem *__qtablewidgetitem290 = new QTableWidgetItem();
        tableWidget->setItem(17, 0, __qtablewidgetitem290);
        QTableWidgetItem *__qtablewidgetitem291 = new QTableWidgetItem();
        tableWidget->setItem(17, 1, __qtablewidgetitem291);
        QTableWidgetItem *__qtablewidgetitem292 = new QTableWidgetItem();
        tableWidget->setItem(17, 6, __qtablewidgetitem292);
        QTableWidgetItem *__qtablewidgetitem293 = new QTableWidgetItem();
        tableWidget->setItem(17, 7, __qtablewidgetitem293);
        QTableWidgetItem *__qtablewidgetitem294 = new QTableWidgetItem();
        tableWidget->setItem(17, 8, __qtablewidgetitem294);
        QTableWidgetItem *__qtablewidgetitem295 = new QTableWidgetItem();
        tableWidget->setItem(17, 9, __qtablewidgetitem295);
        QTableWidgetItem *__qtablewidgetitem296 = new QTableWidgetItem();
        tableWidget->setItem(17, 10, __qtablewidgetitem296);
        QTableWidgetItem *__qtablewidgetitem297 = new QTableWidgetItem();
        tableWidget->setItem(17, 11, __qtablewidgetitem297);
        QTableWidgetItem *__qtablewidgetitem298 = new QTableWidgetItem();
        tableWidget->setItem(17, 12, __qtablewidgetitem298);
        QTableWidgetItem *__qtablewidgetitem299 = new QTableWidgetItem();
        tableWidget->setItem(18, 0, __qtablewidgetitem299);
        QTableWidgetItem *__qtablewidgetitem300 = new QTableWidgetItem();
        tableWidget->setItem(18, 1, __qtablewidgetitem300);
        QTableWidgetItem *__qtablewidgetitem301 = new QTableWidgetItem();
        tableWidget->setItem(18, 6, __qtablewidgetitem301);
        QTableWidgetItem *__qtablewidgetitem302 = new QTableWidgetItem();
        tableWidget->setItem(18, 7, __qtablewidgetitem302);
        QTableWidgetItem *__qtablewidgetitem303 = new QTableWidgetItem();
        tableWidget->setItem(18, 8, __qtablewidgetitem303);
        QTableWidgetItem *__qtablewidgetitem304 = new QTableWidgetItem();
        tableWidget->setItem(18, 9, __qtablewidgetitem304);
        QTableWidgetItem *__qtablewidgetitem305 = new QTableWidgetItem();
        tableWidget->setItem(18, 10, __qtablewidgetitem305);
        QTableWidgetItem *__qtablewidgetitem306 = new QTableWidgetItem();
        tableWidget->setItem(18, 11, __qtablewidgetitem306);
        QTableWidgetItem *__qtablewidgetitem307 = new QTableWidgetItem();
        tableWidget->setItem(18, 12, __qtablewidgetitem307);
        QTableWidgetItem *__qtablewidgetitem308 = new QTableWidgetItem();
        tableWidget->setItem(19, 0, __qtablewidgetitem308);
        QTableWidgetItem *__qtablewidgetitem309 = new QTableWidgetItem();
        tableWidget->setItem(19, 1, __qtablewidgetitem309);
        QTableWidgetItem *__qtablewidgetitem310 = new QTableWidgetItem();
        tableWidget->setItem(19, 6, __qtablewidgetitem310);
        QTableWidgetItem *__qtablewidgetitem311 = new QTableWidgetItem();
        tableWidget->setItem(19, 7, __qtablewidgetitem311);
        QTableWidgetItem *__qtablewidgetitem312 = new QTableWidgetItem();
        tableWidget->setItem(19, 8, __qtablewidgetitem312);
        QTableWidgetItem *__qtablewidgetitem313 = new QTableWidgetItem();
        tableWidget->setItem(19, 9, __qtablewidgetitem313);
        QTableWidgetItem *__qtablewidgetitem314 = new QTableWidgetItem();
        tableWidget->setItem(19, 10, __qtablewidgetitem314);
        QTableWidgetItem *__qtablewidgetitem315 = new QTableWidgetItem();
        tableWidget->setItem(19, 11, __qtablewidgetitem315);
        QTableWidgetItem *__qtablewidgetitem316 = new QTableWidgetItem();
        tableWidget->setItem(19, 12, __qtablewidgetitem316);
        QTableWidgetItem *__qtablewidgetitem317 = new QTableWidgetItem();
        tableWidget->setItem(20, 0, __qtablewidgetitem317);
        QTableWidgetItem *__qtablewidgetitem318 = new QTableWidgetItem();
        tableWidget->setItem(20, 1, __qtablewidgetitem318);
        QTableWidgetItem *__qtablewidgetitem319 = new QTableWidgetItem();
        tableWidget->setItem(20, 6, __qtablewidgetitem319);
        QTableWidgetItem *__qtablewidgetitem320 = new QTableWidgetItem();
        tableWidget->setItem(20, 7, __qtablewidgetitem320);
        QTableWidgetItem *__qtablewidgetitem321 = new QTableWidgetItem();
        tableWidget->setItem(20, 8, __qtablewidgetitem321);
        QTableWidgetItem *__qtablewidgetitem322 = new QTableWidgetItem();
        tableWidget->setItem(20, 9, __qtablewidgetitem322);
        QTableWidgetItem *__qtablewidgetitem323 = new QTableWidgetItem();
        tableWidget->setItem(20, 10, __qtablewidgetitem323);
        QTableWidgetItem *__qtablewidgetitem324 = new QTableWidgetItem();
        tableWidget->setItem(20, 11, __qtablewidgetitem324);
        QTableWidgetItem *__qtablewidgetitem325 = new QTableWidgetItem();
        tableWidget->setItem(20, 12, __qtablewidgetitem325);
        QTableWidgetItem *__qtablewidgetitem326 = new QTableWidgetItem();
        tableWidget->setItem(21, 0, __qtablewidgetitem326);
        QTableWidgetItem *__qtablewidgetitem327 = new QTableWidgetItem();
        tableWidget->setItem(21, 1, __qtablewidgetitem327);
        QTableWidgetItem *__qtablewidgetitem328 = new QTableWidgetItem();
        tableWidget->setItem(21, 6, __qtablewidgetitem328);
        QTableWidgetItem *__qtablewidgetitem329 = new QTableWidgetItem();
        tableWidget->setItem(21, 7, __qtablewidgetitem329);
        QTableWidgetItem *__qtablewidgetitem330 = new QTableWidgetItem();
        tableWidget->setItem(21, 8, __qtablewidgetitem330);
        QTableWidgetItem *__qtablewidgetitem331 = new QTableWidgetItem();
        tableWidget->setItem(21, 9, __qtablewidgetitem331);
        QTableWidgetItem *__qtablewidgetitem332 = new QTableWidgetItem();
        tableWidget->setItem(21, 10, __qtablewidgetitem332);
        QTableWidgetItem *__qtablewidgetitem333 = new QTableWidgetItem();
        tableWidget->setItem(21, 11, __qtablewidgetitem333);
        QTableWidgetItem *__qtablewidgetitem334 = new QTableWidgetItem();
        tableWidget->setItem(21, 12, __qtablewidgetitem334);
        QTableWidgetItem *__qtablewidgetitem335 = new QTableWidgetItem();
        tableWidget->setItem(22, 0, __qtablewidgetitem335);
        QTableWidgetItem *__qtablewidgetitem336 = new QTableWidgetItem();
        tableWidget->setItem(22, 1, __qtablewidgetitem336);
        QTableWidgetItem *__qtablewidgetitem337 = new QTableWidgetItem();
        tableWidget->setItem(22, 6, __qtablewidgetitem337);
        QTableWidgetItem *__qtablewidgetitem338 = new QTableWidgetItem();
        tableWidget->setItem(22, 7, __qtablewidgetitem338);
        QTableWidgetItem *__qtablewidgetitem339 = new QTableWidgetItem();
        tableWidget->setItem(22, 8, __qtablewidgetitem339);
        QTableWidgetItem *__qtablewidgetitem340 = new QTableWidgetItem();
        tableWidget->setItem(22, 9, __qtablewidgetitem340);
        QTableWidgetItem *__qtablewidgetitem341 = new QTableWidgetItem();
        tableWidget->setItem(22, 10, __qtablewidgetitem341);
        QTableWidgetItem *__qtablewidgetitem342 = new QTableWidgetItem();
        tableWidget->setItem(22, 11, __qtablewidgetitem342);
        QTableWidgetItem *__qtablewidgetitem343 = new QTableWidgetItem();
        tableWidget->setItem(22, 12, __qtablewidgetitem343);
        QTableWidgetItem *__qtablewidgetitem344 = new QTableWidgetItem();
        tableWidget->setItem(23, 0, __qtablewidgetitem344);
        QTableWidgetItem *__qtablewidgetitem345 = new QTableWidgetItem();
        tableWidget->setItem(23, 1, __qtablewidgetitem345);
        QTableWidgetItem *__qtablewidgetitem346 = new QTableWidgetItem();
        tableWidget->setItem(23, 6, __qtablewidgetitem346);
        QTableWidgetItem *__qtablewidgetitem347 = new QTableWidgetItem();
        tableWidget->setItem(23, 7, __qtablewidgetitem347);
        QTableWidgetItem *__qtablewidgetitem348 = new QTableWidgetItem();
        tableWidget->setItem(23, 8, __qtablewidgetitem348);
        QTableWidgetItem *__qtablewidgetitem349 = new QTableWidgetItem();
        tableWidget->setItem(23, 9, __qtablewidgetitem349);
        QTableWidgetItem *__qtablewidgetitem350 = new QTableWidgetItem();
        tableWidget->setItem(23, 10, __qtablewidgetitem350);
        QTableWidgetItem *__qtablewidgetitem351 = new QTableWidgetItem();
        tableWidget->setItem(23, 11, __qtablewidgetitem351);
        QTableWidgetItem *__qtablewidgetitem352 = new QTableWidgetItem();
        tableWidget->setItem(23, 12, __qtablewidgetitem352);
        QTableWidgetItem *__qtablewidgetitem353 = new QTableWidgetItem();
        tableWidget->setItem(24, 0, __qtablewidgetitem353);
        QTableWidgetItem *__qtablewidgetitem354 = new QTableWidgetItem();
        tableWidget->setItem(24, 1, __qtablewidgetitem354);
        QTableWidgetItem *__qtablewidgetitem355 = new QTableWidgetItem();
        tableWidget->setItem(24, 6, __qtablewidgetitem355);
        QTableWidgetItem *__qtablewidgetitem356 = new QTableWidgetItem();
        tableWidget->setItem(24, 7, __qtablewidgetitem356);
        QTableWidgetItem *__qtablewidgetitem357 = new QTableWidgetItem();
        tableWidget->setItem(24, 8, __qtablewidgetitem357);
        QTableWidgetItem *__qtablewidgetitem358 = new QTableWidgetItem();
        tableWidget->setItem(24, 9, __qtablewidgetitem358);
        QTableWidgetItem *__qtablewidgetitem359 = new QTableWidgetItem();
        tableWidget->setItem(24, 10, __qtablewidgetitem359);
        QTableWidgetItem *__qtablewidgetitem360 = new QTableWidgetItem();
        tableWidget->setItem(24, 11, __qtablewidgetitem360);
        QTableWidgetItem *__qtablewidgetitem361 = new QTableWidgetItem();
        tableWidget->setItem(24, 12, __qtablewidgetitem361);
        QTableWidgetItem *__qtablewidgetitem362 = new QTableWidgetItem();
        tableWidget->setItem(25, 0, __qtablewidgetitem362);
        QTableWidgetItem *__qtablewidgetitem363 = new QTableWidgetItem();
        tableWidget->setItem(25, 1, __qtablewidgetitem363);
        QTableWidgetItem *__qtablewidgetitem364 = new QTableWidgetItem();
        tableWidget->setItem(25, 6, __qtablewidgetitem364);
        QTableWidgetItem *__qtablewidgetitem365 = new QTableWidgetItem();
        tableWidget->setItem(25, 7, __qtablewidgetitem365);
        QTableWidgetItem *__qtablewidgetitem366 = new QTableWidgetItem();
        tableWidget->setItem(25, 8, __qtablewidgetitem366);
        QTableWidgetItem *__qtablewidgetitem367 = new QTableWidgetItem();
        tableWidget->setItem(25, 9, __qtablewidgetitem367);
        QTableWidgetItem *__qtablewidgetitem368 = new QTableWidgetItem();
        tableWidget->setItem(25, 10, __qtablewidgetitem368);
        QTableWidgetItem *__qtablewidgetitem369 = new QTableWidgetItem();
        tableWidget->setItem(25, 11, __qtablewidgetitem369);
        QTableWidgetItem *__qtablewidgetitem370 = new QTableWidgetItem();
        tableWidget->setItem(25, 12, __qtablewidgetitem370);
        QTableWidgetItem *__qtablewidgetitem371 = new QTableWidgetItem();
        tableWidget->setItem(26, 0, __qtablewidgetitem371);
        QTableWidgetItem *__qtablewidgetitem372 = new QTableWidgetItem();
        tableWidget->setItem(26, 1, __qtablewidgetitem372);
        QTableWidgetItem *__qtablewidgetitem373 = new QTableWidgetItem();
        tableWidget->setItem(26, 6, __qtablewidgetitem373);
        QTableWidgetItem *__qtablewidgetitem374 = new QTableWidgetItem();
        tableWidget->setItem(26, 7, __qtablewidgetitem374);
        QTableWidgetItem *__qtablewidgetitem375 = new QTableWidgetItem();
        tableWidget->setItem(26, 8, __qtablewidgetitem375);
        QTableWidgetItem *__qtablewidgetitem376 = new QTableWidgetItem();
        tableWidget->setItem(26, 9, __qtablewidgetitem376);
        QTableWidgetItem *__qtablewidgetitem377 = new QTableWidgetItem();
        tableWidget->setItem(26, 10, __qtablewidgetitem377);
        QTableWidgetItem *__qtablewidgetitem378 = new QTableWidgetItem();
        tableWidget->setItem(26, 11, __qtablewidgetitem378);
        QTableWidgetItem *__qtablewidgetitem379 = new QTableWidgetItem();
        tableWidget->setItem(26, 12, __qtablewidgetitem379);
        QTableWidgetItem *__qtablewidgetitem380 = new QTableWidgetItem();
        tableWidget->setItem(27, 0, __qtablewidgetitem380);
        QTableWidgetItem *__qtablewidgetitem381 = new QTableWidgetItem();
        tableWidget->setItem(27, 1, __qtablewidgetitem381);
        QTableWidgetItem *__qtablewidgetitem382 = new QTableWidgetItem();
        tableWidget->setItem(27, 6, __qtablewidgetitem382);
        QTableWidgetItem *__qtablewidgetitem383 = new QTableWidgetItem();
        tableWidget->setItem(27, 7, __qtablewidgetitem383);
        QTableWidgetItem *__qtablewidgetitem384 = new QTableWidgetItem();
        tableWidget->setItem(27, 8, __qtablewidgetitem384);
        QTableWidgetItem *__qtablewidgetitem385 = new QTableWidgetItem();
        tableWidget->setItem(27, 9, __qtablewidgetitem385);
        QTableWidgetItem *__qtablewidgetitem386 = new QTableWidgetItem();
        tableWidget->setItem(27, 10, __qtablewidgetitem386);
        QTableWidgetItem *__qtablewidgetitem387 = new QTableWidgetItem();
        tableWidget->setItem(27, 11, __qtablewidgetitem387);
        QTableWidgetItem *__qtablewidgetitem388 = new QTableWidgetItem();
        tableWidget->setItem(27, 12, __qtablewidgetitem388);
        QTableWidgetItem *__qtablewidgetitem389 = new QTableWidgetItem();
        tableWidget->setItem(28, 0, __qtablewidgetitem389);
        QTableWidgetItem *__qtablewidgetitem390 = new QTableWidgetItem();
        tableWidget->setItem(28, 1, __qtablewidgetitem390);
        QTableWidgetItem *__qtablewidgetitem391 = new QTableWidgetItem();
        tableWidget->setItem(29, 0, __qtablewidgetitem391);
        QTableWidgetItem *__qtablewidgetitem392 = new QTableWidgetItem();
        tableWidget->setItem(29, 1, __qtablewidgetitem392);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 0));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(50);
        tableWidget->setFont(font6);
        tableWidget->setFocusPolicy(Qt::WheelFocus);
        tableWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableCornerButton::section{background-color:#d1dff0;}\n"
"QTableView\n"
"{\n"
"\n"
"	background-color: rgba(255, 255, 255, 0); \n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#677483;\n"
"	gridline-color: #ccddf0;\n"
"}\n"
" \n"
"QTableView::item\n"
"{	\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#677483;\n"
"	gridline-color: #ccddf0; \n"
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
"	height:30px;\n"
"	width :25px;\n"
"	background-color: #d1dff0;\n"
"	border:1px solid #8faac9;\n"
"	border-left:none;\n"
"\n"
"}\n"
" \n"
"// border-left:none;\351\230\262\346\255\242\344\270\255\351\227\264\350\241\250\345\244\264\347\232\204border\351\207\215\345\217\240\n"
"QHeaderView::section:first \n"
"{\n"
"	border-left:1px solid #8faac9;\n"
"}\n"
"\n"
"\n"
""));
        tableWidget->setInputMethodHints(Qt::ImhNone);
        tableWidget->setDragEnabled(true);
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(35);
        tableWidget->verticalHeader()->setDefaultSectionSize(26);

        verticalLayout->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        Seed->setCentralWidget(centralwidget);

        retranslateUi(Seed);

        QMetaObject::connectSlotsByName(Seed);
    } // setupUi

    void retranslateUi(QMainWindow *Seed)
    {
        Seed->setWindowTitle(QApplication::translate("Seed", "MainWindow", Q_NULLPTR));
        button_save->setText(QApplication::translate("Seed", "\345\274\200\345\247\213\344\277\235\347\247\215", Q_NULLPTR));
        button_stop->setText(QApplication::translate("Seed", "\345\201\234\346\255\242\344\277\235\347\247\215", Q_NULLPTR));
        butto_back->setText(QApplication::translate("Seed", "\350\277\224\345\233\236", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Seed", "\346\217\220\347\244\272\357\274\232\345\217\214\345\207\273\351\274\240\346\240\207\357\274\214\344\277\256\346\224\271\345\217\202\346\225\260\357\274\201", Q_NULLPTR));
        title->setText(QApplication::translate("Seed", "\344\270\200\345\217\267\346\210\277\351\227\264\344\277\235\347\247\215\345\256\244\345\217\202\346\225\260\350\256\276\345\256\232", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget_head->isSortingEnabled();
        tableWidget_head->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = tableWidget_head->item(0, 0);
        ___qtablewidgetitem->setText(QApplication::translate("Seed", "asd", Q_NULLPTR));
        tableWidget_head->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("Seed", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("Seed", "\345\244\251\346\225\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("Seed", "\346\270\251\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("Seed", "\346\271\277\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem11->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem12->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem13->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem14->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem15->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem16->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem17->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(17);
        ___qtablewidgetitem18->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(18);
        ___qtablewidgetitem19->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(19);
        ___qtablewidgetitem20->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->horizontalHeaderItem(20);
        ___qtablewidgetitem21->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->horizontalHeaderItem(21);
        ___qtablewidgetitem22->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->horizontalHeaderItem(22);
        ___qtablewidgetitem23->setText(QApplication::translate("Seed", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->horizontalHeaderItem(23);
        ___qtablewidgetitem24->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->horizontalHeaderItem(24);
        ___qtablewidgetitem25->setText(QApplication::translate("Seed", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->horizontalHeaderItem(25);
        ___qtablewidgetitem26->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->horizontalHeaderItem(26);
        ___qtablewidgetitem27->setText(QApplication::translate("Seed", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->horizontalHeaderItem(27);
        ___qtablewidgetitem28->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->horizontalHeaderItem(28);
        ___qtablewidgetitem29->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->horizontalHeaderItem(29);
        ___qtablewidgetitem30->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->horizontalHeaderItem(30);
        ___qtablewidgetitem31->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->horizontalHeaderItem(31);
        ___qtablewidgetitem32->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->horizontalHeaderItem(32);
        ___qtablewidgetitem33->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->horizontalHeaderItem(33);
        ___qtablewidgetitem34->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->horizontalHeaderItem(34);
        ___qtablewidgetitem35->setText(QApplication::translate("Seed", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->horizontalHeaderItem(35);
        ___qtablewidgetitem36->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->horizontalHeaderItem(36);
        ___qtablewidgetitem37->setText(QApplication::translate("Seed", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->horizontalHeaderItem(37);
        ___qtablewidgetitem38->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->horizontalHeaderItem(38);
        ___qtablewidgetitem39->setText(QApplication::translate("Seed", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->horizontalHeaderItem(39);
        ___qtablewidgetitem40->setText(QApplication::translate("Seed", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->horizontalHeaderItem(40);
        ___qtablewidgetitem41->setText(QApplication::translate("Seed", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem42->setText(QApplication::translate("Seed", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem43->setText(QApplication::translate("Seed", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem44->setText(QApplication::translate("Seed", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem45->setText(QApplication::translate("Seed", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem46->setText(QApplication::translate("Seed", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem47->setText(QApplication::translate("Seed", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem48->setText(QApplication::translate("Seed", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem49->setText(QApplication::translate("Seed", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem50->setText(QApplication::translate("Seed", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem51->setText(QApplication::translate("Seed", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem52->setText(QApplication::translate("Seed", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem53->setText(QApplication::translate("Seed", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem54->setText(QApplication::translate("Seed", "13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem55->setText(QApplication::translate("Seed", "14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem56->setText(QApplication::translate("Seed", "15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem57->setText(QApplication::translate("Seed", "16", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem58->setText(QApplication::translate("Seed", "17", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem59->setText(QApplication::translate("Seed", "18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem60->setText(QApplication::translate("Seed", "19", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem61->setText(QApplication::translate("Seed", "20", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem62->setText(QApplication::translate("Seed", "21", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem63->setText(QApplication::translate("Seed", "22", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem64->setText(QApplication::translate("Seed", "23", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem65->setText(QApplication::translate("Seed", "24", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget->verticalHeaderItem(24);
        ___qtablewidgetitem66->setText(QApplication::translate("Seed", "25", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget->verticalHeaderItem(25);
        ___qtablewidgetitem67->setText(QApplication::translate("Seed", "26", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget->verticalHeaderItem(26);
        ___qtablewidgetitem68->setText(QApplication::translate("Seed", "27", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget->verticalHeaderItem(27);
        ___qtablewidgetitem69->setText(QApplication::translate("Seed", "28", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget->verticalHeaderItem(28);
        ___qtablewidgetitem70->setText(QApplication::translate("Seed", "29", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget->verticalHeaderItem(29);
        ___qtablewidgetitem71->setText(QApplication::translate("Seed", "30", Q_NULLPTR));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget->item(0, 0);
        ___qtablewidgetitem72->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget->item(0, 1);
        ___qtablewidgetitem73->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget->item(0, 5);
        ___qtablewidgetitem74->setText(QApplication::translate("Seed", "15:31", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget->item(0, 6);
        ___qtablewidgetitem75->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget->item(0, 7);
        ___qtablewidgetitem76->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget->item(0, 8);
        ___qtablewidgetitem77->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget->item(0, 9);
        ___qtablewidgetitem78->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget->item(0, 10);
        ___qtablewidgetitem79->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget->item(0, 11);
        ___qtablewidgetitem80->setText(QApplication::translate("Seed", "15:34", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget->item(0, 12);
        ___qtablewidgetitem81->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget->item(0, 13);
        ___qtablewidgetitem82->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget->item(0, 14);
        ___qtablewidgetitem83->setText(QApplication::translate("Seed", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem84 = tableWidget->item(0, 15);
        ___qtablewidgetitem84->setText(QApplication::translate("Seed", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem85 = tableWidget->item(0, 16);
        ___qtablewidgetitem85->setText(QApplication::translate("Seed", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem86 = tableWidget->item(0, 17);
        ___qtablewidgetitem86->setText(QApplication::translate("Seed", "15:37", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem87 = tableWidget->item(0, 18);
        ___qtablewidgetitem87->setText(QApplication::translate("Seed", "7\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem88 = tableWidget->item(0, 19);
        ___qtablewidgetitem88->setText(QApplication::translate("Seed", "15:38", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem89 = tableWidget->item(0, 20);
        ___qtablewidgetitem89->setText(QApplication::translate("Seed", "8\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem90 = tableWidget->item(0, 21);
        ___qtablewidgetitem90->setText(QApplication::translate("Seed", "15:31", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem91 = tableWidget->item(0, 22);
        ___qtablewidgetitem91->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem92 = tableWidget->item(0, 23);
        ___qtablewidgetitem92->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem93 = tableWidget->item(0, 24);
        ___qtablewidgetitem93->setText(QApplication::translate("Seed", "15:34", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem94 = tableWidget->item(0, 25);
        ___qtablewidgetitem94->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem95 = tableWidget->item(0, 26);
        ___qtablewidgetitem95->setText(QApplication::translate("Seed", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem96 = tableWidget->item(0, 27);
        ___qtablewidgetitem96->setText(QApplication::translate("Seed", "15:37", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem97 = tableWidget->item(0, 28);
        ___qtablewidgetitem97->setText(QApplication::translate("Seed", "15:38", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem98 = tableWidget->item(0, 29);
        ___qtablewidgetitem98->setText(QApplication::translate("Seed", "15:31", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem99 = tableWidget->item(0, 30);
        ___qtablewidgetitem99->setText(QApplication::translate("Seed", "0\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem100 = tableWidget->item(0, 31);
        ___qtablewidgetitem100->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem101 = tableWidget->item(0, 32);
        ___qtablewidgetitem101->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem102 = tableWidget->item(0, 35);
        ___qtablewidgetitem102->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem103 = tableWidget->item(0, 36);
        ___qtablewidgetitem103->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem104 = tableWidget->item(1, 0);
        ___qtablewidgetitem104->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem105 = tableWidget->item(1, 1);
        ___qtablewidgetitem105->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem106 = tableWidget->item(1, 3);
        ___qtablewidgetitem106->setText(QApplication::translate("Seed", "56.5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem107 = tableWidget->item(1, 6);
        ___qtablewidgetitem107->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem108 = tableWidget->item(1, 7);
        ___qtablewidgetitem108->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem109 = tableWidget->item(1, 8);
        ___qtablewidgetitem109->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem110 = tableWidget->item(1, 9);
        ___qtablewidgetitem110->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem111 = tableWidget->item(1, 10);
        ___qtablewidgetitem111->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem112 = tableWidget->item(1, 11);
        ___qtablewidgetitem112->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem113 = tableWidget->item(1, 12);
        ___qtablewidgetitem113->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem114 = tableWidget->item(1, 13);
        ___qtablewidgetitem114->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem115 = tableWidget->item(1, 14);
        ___qtablewidgetitem115->setText(QApplication::translate("Seed", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem116 = tableWidget->item(1, 15);
        ___qtablewidgetitem116->setText(QApplication::translate("Seed", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem117 = tableWidget->item(1, 16);
        ___qtablewidgetitem117->setText(QApplication::translate("Seed", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem118 = tableWidget->item(1, 32);
        ___qtablewidgetitem118->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem119 = tableWidget->item(2, 0);
        ___qtablewidgetitem119->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem120 = tableWidget->item(2, 1);
        ___qtablewidgetitem120->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem121 = tableWidget->item(2, 6);
        ___qtablewidgetitem121->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem122 = tableWidget->item(2, 7);
        ___qtablewidgetitem122->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem123 = tableWidget->item(2, 8);
        ___qtablewidgetitem123->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem124 = tableWidget->item(2, 9);
        ___qtablewidgetitem124->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem125 = tableWidget->item(2, 10);
        ___qtablewidgetitem125->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem126 = tableWidget->item(2, 11);
        ___qtablewidgetitem126->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem127 = tableWidget->item(2, 12);
        ___qtablewidgetitem127->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem128 = tableWidget->item(2, 13);
        ___qtablewidgetitem128->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem129 = tableWidget->item(2, 14);
        ___qtablewidgetitem129->setText(QApplication::translate("Seed", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem130 = tableWidget->item(2, 15);
        ___qtablewidgetitem130->setText(QApplication::translate("Seed", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem131 = tableWidget->item(2, 16);
        ___qtablewidgetitem131->setText(QApplication::translate("Seed", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem132 = tableWidget->item(2, 32);
        ___qtablewidgetitem132->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem133 = tableWidget->item(3, 0);
        ___qtablewidgetitem133->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem134 = tableWidget->item(3, 1);
        ___qtablewidgetitem134->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem135 = tableWidget->item(3, 6);
        ___qtablewidgetitem135->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem136 = tableWidget->item(3, 7);
        ___qtablewidgetitem136->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem137 = tableWidget->item(3, 8);
        ___qtablewidgetitem137->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem138 = tableWidget->item(3, 9);
        ___qtablewidgetitem138->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem139 = tableWidget->item(3, 10);
        ___qtablewidgetitem139->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem140 = tableWidget->item(3, 11);
        ___qtablewidgetitem140->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem141 = tableWidget->item(3, 12);
        ___qtablewidgetitem141->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem142 = tableWidget->item(3, 13);
        ___qtablewidgetitem142->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem143 = tableWidget->item(3, 14);
        ___qtablewidgetitem143->setText(QApplication::translate("Seed", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem144 = tableWidget->item(3, 15);
        ___qtablewidgetitem144->setText(QApplication::translate("Seed", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem145 = tableWidget->item(3, 16);
        ___qtablewidgetitem145->setText(QApplication::translate("Seed", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem146 = tableWidget->item(3, 32);
        ___qtablewidgetitem146->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem147 = tableWidget->item(4, 0);
        ___qtablewidgetitem147->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem148 = tableWidget->item(4, 1);
        ___qtablewidgetitem148->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem149 = tableWidget->item(4, 6);
        ___qtablewidgetitem149->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem150 = tableWidget->item(4, 7);
        ___qtablewidgetitem150->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem151 = tableWidget->item(4, 8);
        ___qtablewidgetitem151->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem152 = tableWidget->item(4, 9);
        ___qtablewidgetitem152->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem153 = tableWidget->item(4, 10);
        ___qtablewidgetitem153->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem154 = tableWidget->item(4, 11);
        ___qtablewidgetitem154->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem155 = tableWidget->item(4, 12);
        ___qtablewidgetitem155->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem156 = tableWidget->item(4, 13);
        ___qtablewidgetitem156->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem157 = tableWidget->item(4, 14);
        ___qtablewidgetitem157->setText(QApplication::translate("Seed", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem158 = tableWidget->item(4, 15);
        ___qtablewidgetitem158->setText(QApplication::translate("Seed", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem159 = tableWidget->item(4, 16);
        ___qtablewidgetitem159->setText(QApplication::translate("Seed", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem160 = tableWidget->item(4, 32);
        ___qtablewidgetitem160->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem161 = tableWidget->item(5, 0);
        ___qtablewidgetitem161->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem162 = tableWidget->item(5, 1);
        ___qtablewidgetitem162->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem163 = tableWidget->item(5, 6);
        ___qtablewidgetitem163->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem164 = tableWidget->item(5, 7);
        ___qtablewidgetitem164->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem165 = tableWidget->item(5, 8);
        ___qtablewidgetitem165->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem166 = tableWidget->item(5, 9);
        ___qtablewidgetitem166->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem167 = tableWidget->item(5, 10);
        ___qtablewidgetitem167->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem168 = tableWidget->item(5, 11);
        ___qtablewidgetitem168->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem169 = tableWidget->item(5, 12);
        ___qtablewidgetitem169->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem170 = tableWidget->item(5, 13);
        ___qtablewidgetitem170->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem171 = tableWidget->item(5, 32);
        ___qtablewidgetitem171->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem172 = tableWidget->item(6, 0);
        ___qtablewidgetitem172->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem173 = tableWidget->item(6, 1);
        ___qtablewidgetitem173->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem174 = tableWidget->item(6, 6);
        ___qtablewidgetitem174->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem175 = tableWidget->item(6, 7);
        ___qtablewidgetitem175->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem176 = tableWidget->item(6, 8);
        ___qtablewidgetitem176->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem177 = tableWidget->item(6, 9);
        ___qtablewidgetitem177->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem178 = tableWidget->item(6, 10);
        ___qtablewidgetitem178->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem179 = tableWidget->item(6, 11);
        ___qtablewidgetitem179->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem180 = tableWidget->item(6, 12);
        ___qtablewidgetitem180->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem181 = tableWidget->item(6, 13);
        ___qtablewidgetitem181->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem182 = tableWidget->item(6, 32);
        ___qtablewidgetitem182->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem183 = tableWidget->item(7, 0);
        ___qtablewidgetitem183->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem184 = tableWidget->item(7, 1);
        ___qtablewidgetitem184->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem185 = tableWidget->item(7, 6);
        ___qtablewidgetitem185->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem186 = tableWidget->item(7, 7);
        ___qtablewidgetitem186->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem187 = tableWidget->item(7, 8);
        ___qtablewidgetitem187->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem188 = tableWidget->item(7, 9);
        ___qtablewidgetitem188->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem189 = tableWidget->item(7, 10);
        ___qtablewidgetitem189->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem190 = tableWidget->item(7, 11);
        ___qtablewidgetitem190->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem191 = tableWidget->item(7, 12);
        ___qtablewidgetitem191->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem192 = tableWidget->item(7, 13);
        ___qtablewidgetitem192->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem193 = tableWidget->item(7, 32);
        ___qtablewidgetitem193->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem194 = tableWidget->item(8, 0);
        ___qtablewidgetitem194->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem195 = tableWidget->item(8, 1);
        ___qtablewidgetitem195->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem196 = tableWidget->item(8, 6);
        ___qtablewidgetitem196->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem197 = tableWidget->item(8, 7);
        ___qtablewidgetitem197->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem198 = tableWidget->item(8, 8);
        ___qtablewidgetitem198->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem199 = tableWidget->item(8, 9);
        ___qtablewidgetitem199->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem200 = tableWidget->item(8, 10);
        ___qtablewidgetitem200->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem201 = tableWidget->item(8, 11);
        ___qtablewidgetitem201->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem202 = tableWidget->item(8, 12);
        ___qtablewidgetitem202->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem203 = tableWidget->item(8, 13);
        ___qtablewidgetitem203->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem204 = tableWidget->item(8, 32);
        ___qtablewidgetitem204->setText(QApplication::translate("Seed", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem205 = tableWidget->item(9, 0);
        ___qtablewidgetitem205->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem206 = tableWidget->item(9, 1);
        ___qtablewidgetitem206->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem207 = tableWidget->item(9, 6);
        ___qtablewidgetitem207->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem208 = tableWidget->item(9, 7);
        ___qtablewidgetitem208->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem209 = tableWidget->item(9, 8);
        ___qtablewidgetitem209->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem210 = tableWidget->item(9, 9);
        ___qtablewidgetitem210->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem211 = tableWidget->item(9, 10);
        ___qtablewidgetitem211->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem212 = tableWidget->item(9, 11);
        ___qtablewidgetitem212->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem213 = tableWidget->item(9, 12);
        ___qtablewidgetitem213->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem214 = tableWidget->item(9, 13);
        ___qtablewidgetitem214->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem215 = tableWidget->item(10, 0);
        ___qtablewidgetitem215->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem216 = tableWidget->item(10, 1);
        ___qtablewidgetitem216->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem217 = tableWidget->item(10, 6);
        ___qtablewidgetitem217->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem218 = tableWidget->item(10, 7);
        ___qtablewidgetitem218->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem219 = tableWidget->item(10, 8);
        ___qtablewidgetitem219->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem220 = tableWidget->item(10, 9);
        ___qtablewidgetitem220->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem221 = tableWidget->item(10, 10);
        ___qtablewidgetitem221->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem222 = tableWidget->item(10, 11);
        ___qtablewidgetitem222->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem223 = tableWidget->item(10, 12);
        ___qtablewidgetitem223->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem224 = tableWidget->item(10, 13);
        ___qtablewidgetitem224->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem225 = tableWidget->item(11, 0);
        ___qtablewidgetitem225->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem226 = tableWidget->item(11, 1);
        ___qtablewidgetitem226->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem227 = tableWidget->item(11, 6);
        ___qtablewidgetitem227->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem228 = tableWidget->item(11, 7);
        ___qtablewidgetitem228->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem229 = tableWidget->item(11, 8);
        ___qtablewidgetitem229->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem230 = tableWidget->item(11, 9);
        ___qtablewidgetitem230->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem231 = tableWidget->item(11, 10);
        ___qtablewidgetitem231->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem232 = tableWidget->item(11, 11);
        ___qtablewidgetitem232->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem233 = tableWidget->item(11, 12);
        ___qtablewidgetitem233->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem234 = tableWidget->item(11, 13);
        ___qtablewidgetitem234->setText(QApplication::translate("Seed", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem235 = tableWidget->item(12, 0);
        ___qtablewidgetitem235->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem236 = tableWidget->item(12, 1);
        ___qtablewidgetitem236->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem237 = tableWidget->item(12, 6);
        ___qtablewidgetitem237->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem238 = tableWidget->item(12, 7);
        ___qtablewidgetitem238->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem239 = tableWidget->item(12, 8);
        ___qtablewidgetitem239->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem240 = tableWidget->item(12, 9);
        ___qtablewidgetitem240->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem241 = tableWidget->item(12, 10);
        ___qtablewidgetitem241->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem242 = tableWidget->item(12, 11);
        ___qtablewidgetitem242->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem243 = tableWidget->item(12, 12);
        ___qtablewidgetitem243->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem244 = tableWidget->item(13, 0);
        ___qtablewidgetitem244->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem245 = tableWidget->item(13, 1);
        ___qtablewidgetitem245->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem246 = tableWidget->item(13, 6);
        ___qtablewidgetitem246->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem247 = tableWidget->item(13, 7);
        ___qtablewidgetitem247->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem248 = tableWidget->item(13, 8);
        ___qtablewidgetitem248->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem249 = tableWidget->item(13, 9);
        ___qtablewidgetitem249->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem250 = tableWidget->item(13, 10);
        ___qtablewidgetitem250->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem251 = tableWidget->item(13, 11);
        ___qtablewidgetitem251->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem252 = tableWidget->item(13, 12);
        ___qtablewidgetitem252->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem253 = tableWidget->item(14, 0);
        ___qtablewidgetitem253->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem254 = tableWidget->item(14, 1);
        ___qtablewidgetitem254->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem255 = tableWidget->item(14, 6);
        ___qtablewidgetitem255->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem256 = tableWidget->item(14, 7);
        ___qtablewidgetitem256->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem257 = tableWidget->item(14, 8);
        ___qtablewidgetitem257->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem258 = tableWidget->item(14, 9);
        ___qtablewidgetitem258->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem259 = tableWidget->item(14, 10);
        ___qtablewidgetitem259->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem260 = tableWidget->item(14, 11);
        ___qtablewidgetitem260->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem261 = tableWidget->item(14, 12);
        ___qtablewidgetitem261->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem262 = tableWidget->item(15, 0);
        ___qtablewidgetitem262->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem263 = tableWidget->item(15, 1);
        ___qtablewidgetitem263->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem264 = tableWidget->item(15, 6);
        ___qtablewidgetitem264->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem265 = tableWidget->item(15, 7);
        ___qtablewidgetitem265->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem266 = tableWidget->item(15, 8);
        ___qtablewidgetitem266->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem267 = tableWidget->item(15, 9);
        ___qtablewidgetitem267->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem268 = tableWidget->item(15, 10);
        ___qtablewidgetitem268->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem269 = tableWidget->item(15, 11);
        ___qtablewidgetitem269->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem270 = tableWidget->item(15, 12);
        ___qtablewidgetitem270->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem271 = tableWidget->item(16, 0);
        ___qtablewidgetitem271->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem272 = tableWidget->item(16, 1);
        ___qtablewidgetitem272->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem273 = tableWidget->item(16, 6);
        ___qtablewidgetitem273->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem274 = tableWidget->item(16, 7);
        ___qtablewidgetitem274->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem275 = tableWidget->item(16, 8);
        ___qtablewidgetitem275->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem276 = tableWidget->item(16, 9);
        ___qtablewidgetitem276->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem277 = tableWidget->item(16, 10);
        ___qtablewidgetitem277->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem278 = tableWidget->item(16, 11);
        ___qtablewidgetitem278->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem279 = tableWidget->item(16, 12);
        ___qtablewidgetitem279->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem280 = tableWidget->item(17, 0);
        ___qtablewidgetitem280->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem281 = tableWidget->item(17, 1);
        ___qtablewidgetitem281->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem282 = tableWidget->item(17, 6);
        ___qtablewidgetitem282->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem283 = tableWidget->item(17, 7);
        ___qtablewidgetitem283->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem284 = tableWidget->item(17, 8);
        ___qtablewidgetitem284->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem285 = tableWidget->item(17, 9);
        ___qtablewidgetitem285->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem286 = tableWidget->item(17, 10);
        ___qtablewidgetitem286->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem287 = tableWidget->item(17, 11);
        ___qtablewidgetitem287->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem288 = tableWidget->item(17, 12);
        ___qtablewidgetitem288->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem289 = tableWidget->item(18, 0);
        ___qtablewidgetitem289->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem290 = tableWidget->item(18, 1);
        ___qtablewidgetitem290->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem291 = tableWidget->item(18, 6);
        ___qtablewidgetitem291->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem292 = tableWidget->item(18, 7);
        ___qtablewidgetitem292->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem293 = tableWidget->item(18, 8);
        ___qtablewidgetitem293->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem294 = tableWidget->item(18, 9);
        ___qtablewidgetitem294->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem295 = tableWidget->item(18, 10);
        ___qtablewidgetitem295->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem296 = tableWidget->item(18, 11);
        ___qtablewidgetitem296->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem297 = tableWidget->item(18, 12);
        ___qtablewidgetitem297->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem298 = tableWidget->item(19, 0);
        ___qtablewidgetitem298->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem299 = tableWidget->item(19, 1);
        ___qtablewidgetitem299->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem300 = tableWidget->item(19, 6);
        ___qtablewidgetitem300->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem301 = tableWidget->item(19, 7);
        ___qtablewidgetitem301->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem302 = tableWidget->item(19, 8);
        ___qtablewidgetitem302->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem303 = tableWidget->item(19, 9);
        ___qtablewidgetitem303->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem304 = tableWidget->item(19, 10);
        ___qtablewidgetitem304->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem305 = tableWidget->item(19, 11);
        ___qtablewidgetitem305->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem306 = tableWidget->item(19, 12);
        ___qtablewidgetitem306->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem307 = tableWidget->item(20, 0);
        ___qtablewidgetitem307->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem308 = tableWidget->item(20, 1);
        ___qtablewidgetitem308->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem309 = tableWidget->item(20, 6);
        ___qtablewidgetitem309->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem310 = tableWidget->item(20, 7);
        ___qtablewidgetitem310->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem311 = tableWidget->item(20, 8);
        ___qtablewidgetitem311->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem312 = tableWidget->item(20, 9);
        ___qtablewidgetitem312->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem313 = tableWidget->item(20, 10);
        ___qtablewidgetitem313->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem314 = tableWidget->item(20, 11);
        ___qtablewidgetitem314->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem315 = tableWidget->item(20, 12);
        ___qtablewidgetitem315->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem316 = tableWidget->item(21, 0);
        ___qtablewidgetitem316->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem317 = tableWidget->item(21, 1);
        ___qtablewidgetitem317->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem318 = tableWidget->item(21, 6);
        ___qtablewidgetitem318->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem319 = tableWidget->item(21, 7);
        ___qtablewidgetitem319->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem320 = tableWidget->item(21, 8);
        ___qtablewidgetitem320->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem321 = tableWidget->item(21, 9);
        ___qtablewidgetitem321->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem322 = tableWidget->item(21, 10);
        ___qtablewidgetitem322->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem323 = tableWidget->item(21, 11);
        ___qtablewidgetitem323->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem324 = tableWidget->item(21, 12);
        ___qtablewidgetitem324->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem325 = tableWidget->item(22, 0);
        ___qtablewidgetitem325->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem326 = tableWidget->item(22, 1);
        ___qtablewidgetitem326->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem327 = tableWidget->item(22, 6);
        ___qtablewidgetitem327->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem328 = tableWidget->item(22, 7);
        ___qtablewidgetitem328->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem329 = tableWidget->item(22, 8);
        ___qtablewidgetitem329->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem330 = tableWidget->item(22, 9);
        ___qtablewidgetitem330->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem331 = tableWidget->item(22, 10);
        ___qtablewidgetitem331->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem332 = tableWidget->item(22, 11);
        ___qtablewidgetitem332->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem333 = tableWidget->item(22, 12);
        ___qtablewidgetitem333->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem334 = tableWidget->item(23, 0);
        ___qtablewidgetitem334->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem335 = tableWidget->item(23, 1);
        ___qtablewidgetitem335->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem336 = tableWidget->item(23, 6);
        ___qtablewidgetitem336->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem337 = tableWidget->item(23, 7);
        ___qtablewidgetitem337->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem338 = tableWidget->item(23, 8);
        ___qtablewidgetitem338->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem339 = tableWidget->item(23, 9);
        ___qtablewidgetitem339->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem340 = tableWidget->item(23, 10);
        ___qtablewidgetitem340->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem341 = tableWidget->item(23, 11);
        ___qtablewidgetitem341->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem342 = tableWidget->item(23, 12);
        ___qtablewidgetitem342->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem343 = tableWidget->item(24, 0);
        ___qtablewidgetitem343->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem344 = tableWidget->item(24, 1);
        ___qtablewidgetitem344->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem345 = tableWidget->item(24, 6);
        ___qtablewidgetitem345->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem346 = tableWidget->item(24, 7);
        ___qtablewidgetitem346->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem347 = tableWidget->item(24, 8);
        ___qtablewidgetitem347->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem348 = tableWidget->item(24, 9);
        ___qtablewidgetitem348->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem349 = tableWidget->item(24, 10);
        ___qtablewidgetitem349->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem350 = tableWidget->item(24, 11);
        ___qtablewidgetitem350->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem351 = tableWidget->item(24, 12);
        ___qtablewidgetitem351->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem352 = tableWidget->item(25, 0);
        ___qtablewidgetitem352->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem353 = tableWidget->item(25, 1);
        ___qtablewidgetitem353->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem354 = tableWidget->item(25, 6);
        ___qtablewidgetitem354->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem355 = tableWidget->item(25, 7);
        ___qtablewidgetitem355->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem356 = tableWidget->item(25, 8);
        ___qtablewidgetitem356->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem357 = tableWidget->item(25, 9);
        ___qtablewidgetitem357->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem358 = tableWidget->item(25, 10);
        ___qtablewidgetitem358->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem359 = tableWidget->item(25, 11);
        ___qtablewidgetitem359->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem360 = tableWidget->item(25, 12);
        ___qtablewidgetitem360->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem361 = tableWidget->item(26, 0);
        ___qtablewidgetitem361->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem362 = tableWidget->item(26, 1);
        ___qtablewidgetitem362->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem363 = tableWidget->item(26, 6);
        ___qtablewidgetitem363->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem364 = tableWidget->item(26, 7);
        ___qtablewidgetitem364->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem365 = tableWidget->item(26, 8);
        ___qtablewidgetitem365->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem366 = tableWidget->item(26, 9);
        ___qtablewidgetitem366->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem367 = tableWidget->item(26, 10);
        ___qtablewidgetitem367->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem368 = tableWidget->item(26, 11);
        ___qtablewidgetitem368->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem369 = tableWidget->item(26, 12);
        ___qtablewidgetitem369->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem370 = tableWidget->item(27, 0);
        ___qtablewidgetitem370->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem371 = tableWidget->item(27, 1);
        ___qtablewidgetitem371->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem372 = tableWidget->item(27, 6);
        ___qtablewidgetitem372->setText(QApplication::translate("Seed", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem373 = tableWidget->item(27, 7);
        ___qtablewidgetitem373->setText(QApplication::translate("Seed", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem374 = tableWidget->item(27, 8);
        ___qtablewidgetitem374->setText(QApplication::translate("Seed", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem375 = tableWidget->item(27, 9);
        ___qtablewidgetitem375->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem376 = tableWidget->item(27, 10);
        ___qtablewidgetitem376->setText(QApplication::translate("Seed", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem377 = tableWidget->item(27, 11);
        ___qtablewidgetitem377->setText(QApplication::translate("Seed", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem378 = tableWidget->item(27, 12);
        ___qtablewidgetitem378->setText(QApplication::translate("Seed", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem379 = tableWidget->item(28, 0);
        ___qtablewidgetitem379->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem380 = tableWidget->item(28, 1);
        ___qtablewidgetitem380->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem381 = tableWidget->item(29, 0);
        ___qtablewidgetitem381->setText(QApplication::translate("Seed", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem382 = tableWidget->item(29, 1);
        ___qtablewidgetitem382->setText(QApplication::translate("Seed", "2016/12/14", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class Seed: public Ui_Seed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEED1_H
