/********************************************************************************
** Form generated from reading UI file 'set_parament1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_PARAMENT1_H
#define UI_SET_PARAMENT1_H

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

class Ui_set_parament1
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *title;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_head;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *button_save;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *button_stop;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *butto_back;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QMainWindow *set_parament1)
    {
        if (set_parament1->objectName().isEmpty())
            set_parament1->setObjectName(QStringLiteral("set_parament1"));
        set_parament1->resize(1919, 632);
        centralwidget = new QWidget(set_parament1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(13, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        title = new QLabel(centralwidget);
        title->setObjectName(QStringLiteral("title"));
        title->setFont(font);

        horizontalLayout->addWidget(title);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget_head = new QTableWidget(centralwidget);
        if (tableWidget_head->columnCount() < 2)
            tableWidget_head->setColumnCount(2);
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
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        tableWidget_head->setFont(font1);
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
        tableWidget_head->horizontalHeader()->setVisible(true);
        tableWidget_head->horizontalHeader()->setDefaultSectionSize(45);
        tableWidget_head->horizontalHeader()->setHighlightSections(true);
        tableWidget_head->verticalHeader()->setVisible(true);
        tableWidget_head->verticalHeader()->setCascadingSectionResizes(true);

        verticalLayout->addWidget(tableWidget_head);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 40)
            tableWidget->setColumnCount(40);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setBackground(QColor(85, 255, 0));
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
        if (tableWidget->rowCount() < 12)
            tableWidget->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 1, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 2, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 4, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 5, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 6, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 7, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 8, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 9, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        __qtablewidgetitem68->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 10, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        __qtablewidgetitem69->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 11, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        __qtablewidgetitem70->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 12, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        __qtablewidgetitem71->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 13, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        __qtablewidgetitem72->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 14, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        __qtablewidgetitem73->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 15, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        __qtablewidgetitem74->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 16, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        __qtablewidgetitem75->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 17, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        __qtablewidgetitem76->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 18, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        __qtablewidgetitem77->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 19, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        __qtablewidgetitem78->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 20, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        __qtablewidgetitem79->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 21, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        __qtablewidgetitem80->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 22, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        __qtablewidgetitem81->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 23, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget->setItem(0, 24, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget->setItem(0, 25, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        __qtablewidgetitem84->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 26, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        __qtablewidgetitem85->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 27, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        __qtablewidgetitem86->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 28, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        __qtablewidgetitem87->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 29, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        __qtablewidgetitem88->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 30, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        __qtablewidgetitem89->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 31, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        __qtablewidgetitem90->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 32, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        __qtablewidgetitem91->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 33, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        __qtablewidgetitem92->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 34, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        __qtablewidgetitem93->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 35, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        tableWidget->setItem(0, 36, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        tableWidget->setItem(0, 37, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        tableWidget->setItem(0, 38, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        tableWidget->setItem(0, 39, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        tableWidget->setItem(1, 8, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        tableWidget->setItem(1, 9, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        tableWidget->setItem(1, 10, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        tableWidget->setItem(1, 11, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        tableWidget->setItem(1, 12, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        tableWidget->setItem(1, 13, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        tableWidget->setItem(1, 14, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        tableWidget->setItem(1, 15, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        tableWidget->setItem(1, 33, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        tableWidget->setItem(2, 5, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        tableWidget->setItem(2, 6, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        tableWidget->setItem(2, 7, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        tableWidget->setItem(2, 8, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        tableWidget->setItem(2, 9, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        tableWidget->setItem(2, 10, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        tableWidget->setItem(2, 11, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        tableWidget->setItem(2, 12, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        tableWidget->setItem(2, 13, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        tableWidget->setItem(2, 14, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        tableWidget->setItem(2, 15, __qtablewidgetitem125);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        tableWidget->setItem(2, 33, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        tableWidget->setItem(3, 5, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        tableWidget->setItem(3, 6, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        tableWidget->setItem(3, 7, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        tableWidget->setItem(3, 8, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        tableWidget->setItem(3, 9, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        tableWidget->setItem(3, 10, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        tableWidget->setItem(3, 11, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        tableWidget->setItem(3, 12, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        tableWidget->setItem(3, 13, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        tableWidget->setItem(3, 14, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        tableWidget->setItem(3, 15, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        tableWidget->setItem(3, 33, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem142);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        tableWidget->setItem(4, 5, __qtablewidgetitem143);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        tableWidget->setItem(4, 6, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        tableWidget->setItem(4, 7, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        tableWidget->setItem(4, 8, __qtablewidgetitem146);
        QTableWidgetItem *__qtablewidgetitem147 = new QTableWidgetItem();
        tableWidget->setItem(4, 9, __qtablewidgetitem147);
        QTableWidgetItem *__qtablewidgetitem148 = new QTableWidgetItem();
        tableWidget->setItem(4, 10, __qtablewidgetitem148);
        QTableWidgetItem *__qtablewidgetitem149 = new QTableWidgetItem();
        tableWidget->setItem(4, 11, __qtablewidgetitem149);
        QTableWidgetItem *__qtablewidgetitem150 = new QTableWidgetItem();
        tableWidget->setItem(4, 12, __qtablewidgetitem150);
        QTableWidgetItem *__qtablewidgetitem151 = new QTableWidgetItem();
        tableWidget->setItem(4, 13, __qtablewidgetitem151);
        QTableWidgetItem *__qtablewidgetitem152 = new QTableWidgetItem();
        tableWidget->setItem(4, 14, __qtablewidgetitem152);
        QTableWidgetItem *__qtablewidgetitem153 = new QTableWidgetItem();
        tableWidget->setItem(4, 15, __qtablewidgetitem153);
        QTableWidgetItem *__qtablewidgetitem154 = new QTableWidgetItem();
        tableWidget->setItem(4, 33, __qtablewidgetitem154);
        QTableWidgetItem *__qtablewidgetitem155 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem155);
        QTableWidgetItem *__qtablewidgetitem156 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem156);
        QTableWidgetItem *__qtablewidgetitem157 = new QTableWidgetItem();
        tableWidget->setItem(5, 2, __qtablewidgetitem157);
        QTableWidgetItem *__qtablewidgetitem158 = new QTableWidgetItem();
        tableWidget->setItem(5, 5, __qtablewidgetitem158);
        QTableWidgetItem *__qtablewidgetitem159 = new QTableWidgetItem();
        tableWidget->setItem(5, 6, __qtablewidgetitem159);
        QTableWidgetItem *__qtablewidgetitem160 = new QTableWidgetItem();
        tableWidget->setItem(5, 7, __qtablewidgetitem160);
        QTableWidgetItem *__qtablewidgetitem161 = new QTableWidgetItem();
        tableWidget->setItem(5, 8, __qtablewidgetitem161);
        QTableWidgetItem *__qtablewidgetitem162 = new QTableWidgetItem();
        tableWidget->setItem(5, 9, __qtablewidgetitem162);
        QTableWidgetItem *__qtablewidgetitem163 = new QTableWidgetItem();
        tableWidget->setItem(5, 10, __qtablewidgetitem163);
        QTableWidgetItem *__qtablewidgetitem164 = new QTableWidgetItem();
        tableWidget->setItem(5, 11, __qtablewidgetitem164);
        QTableWidgetItem *__qtablewidgetitem165 = new QTableWidgetItem();
        tableWidget->setItem(5, 12, __qtablewidgetitem165);
        QTableWidgetItem *__qtablewidgetitem166 = new QTableWidgetItem();
        tableWidget->setItem(5, 33, __qtablewidgetitem166);
        QTableWidgetItem *__qtablewidgetitem167 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem167);
        QTableWidgetItem *__qtablewidgetitem168 = new QTableWidgetItem();
        tableWidget->setItem(6, 1, __qtablewidgetitem168);
        QTableWidgetItem *__qtablewidgetitem169 = new QTableWidgetItem();
        tableWidget->setItem(6, 5, __qtablewidgetitem169);
        QTableWidgetItem *__qtablewidgetitem170 = new QTableWidgetItem();
        tableWidget->setItem(6, 6, __qtablewidgetitem170);
        QTableWidgetItem *__qtablewidgetitem171 = new QTableWidgetItem();
        tableWidget->setItem(6, 7, __qtablewidgetitem171);
        QTableWidgetItem *__qtablewidgetitem172 = new QTableWidgetItem();
        tableWidget->setItem(6, 8, __qtablewidgetitem172);
        QTableWidgetItem *__qtablewidgetitem173 = new QTableWidgetItem();
        tableWidget->setItem(6, 9, __qtablewidgetitem173);
        QTableWidgetItem *__qtablewidgetitem174 = new QTableWidgetItem();
        tableWidget->setItem(6, 10, __qtablewidgetitem174);
        QTableWidgetItem *__qtablewidgetitem175 = new QTableWidgetItem();
        tableWidget->setItem(6, 11, __qtablewidgetitem175);
        QTableWidgetItem *__qtablewidgetitem176 = new QTableWidgetItem();
        tableWidget->setItem(6, 12, __qtablewidgetitem176);
        QTableWidgetItem *__qtablewidgetitem177 = new QTableWidgetItem();
        tableWidget->setItem(6, 33, __qtablewidgetitem177);
        QTableWidgetItem *__qtablewidgetitem178 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem178);
        QTableWidgetItem *__qtablewidgetitem179 = new QTableWidgetItem();
        tableWidget->setItem(7, 1, __qtablewidgetitem179);
        QTableWidgetItem *__qtablewidgetitem180 = new QTableWidgetItem();
        tableWidget->setItem(7, 5, __qtablewidgetitem180);
        QTableWidgetItem *__qtablewidgetitem181 = new QTableWidgetItem();
        tableWidget->setItem(7, 6, __qtablewidgetitem181);
        QTableWidgetItem *__qtablewidgetitem182 = new QTableWidgetItem();
        tableWidget->setItem(7, 7, __qtablewidgetitem182);
        QTableWidgetItem *__qtablewidgetitem183 = new QTableWidgetItem();
        tableWidget->setItem(7, 8, __qtablewidgetitem183);
        QTableWidgetItem *__qtablewidgetitem184 = new QTableWidgetItem();
        tableWidget->setItem(7, 9, __qtablewidgetitem184);
        QTableWidgetItem *__qtablewidgetitem185 = new QTableWidgetItem();
        tableWidget->setItem(7, 10, __qtablewidgetitem185);
        QTableWidgetItem *__qtablewidgetitem186 = new QTableWidgetItem();
        tableWidget->setItem(7, 11, __qtablewidgetitem186);
        QTableWidgetItem *__qtablewidgetitem187 = new QTableWidgetItem();
        tableWidget->setItem(7, 12, __qtablewidgetitem187);
        QTableWidgetItem *__qtablewidgetitem188 = new QTableWidgetItem();
        tableWidget->setItem(7, 33, __qtablewidgetitem188);
        QTableWidgetItem *__qtablewidgetitem189 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem189);
        QTableWidgetItem *__qtablewidgetitem190 = new QTableWidgetItem();
        tableWidget->setItem(8, 1, __qtablewidgetitem190);
        QTableWidgetItem *__qtablewidgetitem191 = new QTableWidgetItem();
        tableWidget->setItem(8, 5, __qtablewidgetitem191);
        QTableWidgetItem *__qtablewidgetitem192 = new QTableWidgetItem();
        tableWidget->setItem(8, 6, __qtablewidgetitem192);
        QTableWidgetItem *__qtablewidgetitem193 = new QTableWidgetItem();
        tableWidget->setItem(8, 7, __qtablewidgetitem193);
        QTableWidgetItem *__qtablewidgetitem194 = new QTableWidgetItem();
        tableWidget->setItem(8, 8, __qtablewidgetitem194);
        QTableWidgetItem *__qtablewidgetitem195 = new QTableWidgetItem();
        tableWidget->setItem(8, 9, __qtablewidgetitem195);
        QTableWidgetItem *__qtablewidgetitem196 = new QTableWidgetItem();
        tableWidget->setItem(8, 10, __qtablewidgetitem196);
        QTableWidgetItem *__qtablewidgetitem197 = new QTableWidgetItem();
        tableWidget->setItem(8, 11, __qtablewidgetitem197);
        QTableWidgetItem *__qtablewidgetitem198 = new QTableWidgetItem();
        tableWidget->setItem(8, 12, __qtablewidgetitem198);
        QTableWidgetItem *__qtablewidgetitem199 = new QTableWidgetItem();
        tableWidget->setItem(8, 33, __qtablewidgetitem199);
        QTableWidgetItem *__qtablewidgetitem200 = new QTableWidgetItem();
        tableWidget->setItem(9, 0, __qtablewidgetitem200);
        QTableWidgetItem *__qtablewidgetitem201 = new QTableWidgetItem();
        tableWidget->setItem(9, 1, __qtablewidgetitem201);
        QTableWidgetItem *__qtablewidgetitem202 = new QTableWidgetItem();
        tableWidget->setItem(9, 2, __qtablewidgetitem202);
        QTableWidgetItem *__qtablewidgetitem203 = new QTableWidgetItem();
        tableWidget->setItem(9, 4, __qtablewidgetitem203);
        QTableWidgetItem *__qtablewidgetitem204 = new QTableWidgetItem();
        tableWidget->setItem(9, 5, __qtablewidgetitem204);
        QTableWidgetItem *__qtablewidgetitem205 = new QTableWidgetItem();
        tableWidget->setItem(9, 6, __qtablewidgetitem205);
        QTableWidgetItem *__qtablewidgetitem206 = new QTableWidgetItem();
        tableWidget->setItem(9, 7, __qtablewidgetitem206);
        QTableWidgetItem *__qtablewidgetitem207 = new QTableWidgetItem();
        tableWidget->setItem(9, 8, __qtablewidgetitem207);
        QTableWidgetItem *__qtablewidgetitem208 = new QTableWidgetItem();
        tableWidget->setItem(9, 9, __qtablewidgetitem208);
        QTableWidgetItem *__qtablewidgetitem209 = new QTableWidgetItem();
        tableWidget->setItem(9, 10, __qtablewidgetitem209);
        QTableWidgetItem *__qtablewidgetitem210 = new QTableWidgetItem();
        tableWidget->setItem(9, 11, __qtablewidgetitem210);
        QTableWidgetItem *__qtablewidgetitem211 = new QTableWidgetItem();
        tableWidget->setItem(9, 12, __qtablewidgetitem211);
        QTableWidgetItem *__qtablewidgetitem212 = new QTableWidgetItem();
        tableWidget->setItem(10, 0, __qtablewidgetitem212);
        QTableWidgetItem *__qtablewidgetitem213 = new QTableWidgetItem();
        tableWidget->setItem(10, 1, __qtablewidgetitem213);
        QTableWidgetItem *__qtablewidgetitem214 = new QTableWidgetItem();
        tableWidget->setItem(10, 2, __qtablewidgetitem214);
        QTableWidgetItem *__qtablewidgetitem215 = new QTableWidgetItem();
        tableWidget->setItem(10, 5, __qtablewidgetitem215);
        QTableWidgetItem *__qtablewidgetitem216 = new QTableWidgetItem();
        tableWidget->setItem(10, 6, __qtablewidgetitem216);
        QTableWidgetItem *__qtablewidgetitem217 = new QTableWidgetItem();
        tableWidget->setItem(10, 7, __qtablewidgetitem217);
        QTableWidgetItem *__qtablewidgetitem218 = new QTableWidgetItem();
        tableWidget->setItem(10, 8, __qtablewidgetitem218);
        QTableWidgetItem *__qtablewidgetitem219 = new QTableWidgetItem();
        tableWidget->setItem(10, 9, __qtablewidgetitem219);
        QTableWidgetItem *__qtablewidgetitem220 = new QTableWidgetItem();
        tableWidget->setItem(10, 10, __qtablewidgetitem220);
        QTableWidgetItem *__qtablewidgetitem221 = new QTableWidgetItem();
        tableWidget->setItem(10, 11, __qtablewidgetitem221);
        QTableWidgetItem *__qtablewidgetitem222 = new QTableWidgetItem();
        tableWidget->setItem(10, 12, __qtablewidgetitem222);
        QTableWidgetItem *__qtablewidgetitem223 = new QTableWidgetItem();
        tableWidget->setItem(11, 0, __qtablewidgetitem223);
        QTableWidgetItem *__qtablewidgetitem224 = new QTableWidgetItem();
        tableWidget->setItem(11, 1, __qtablewidgetitem224);
        QTableWidgetItem *__qtablewidgetitem225 = new QTableWidgetItem();
        tableWidget->setItem(11, 5, __qtablewidgetitem225);
        QTableWidgetItem *__qtablewidgetitem226 = new QTableWidgetItem();
        tableWidget->setItem(11, 6, __qtablewidgetitem226);
        QTableWidgetItem *__qtablewidgetitem227 = new QTableWidgetItem();
        tableWidget->setItem(11, 7, __qtablewidgetitem227);
        QTableWidgetItem *__qtablewidgetitem228 = new QTableWidgetItem();
        tableWidget->setItem(11, 8, __qtablewidgetitem228);
        QTableWidgetItem *__qtablewidgetitem229 = new QTableWidgetItem();
        tableWidget->setItem(11, 9, __qtablewidgetitem229);
        QTableWidgetItem *__qtablewidgetitem230 = new QTableWidgetItem();
        tableWidget->setItem(11, 10, __qtablewidgetitem230);
        QTableWidgetItem *__qtablewidgetitem231 = new QTableWidgetItem();
        tableWidget->setItem(11, 11, __qtablewidgetitem231);
        QTableWidgetItem *__qtablewidgetitem232 = new QTableWidgetItem();
        tableWidget->setItem(11, 12, __qtablewidgetitem232);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        tableWidget->setFont(font2);
        tableWidget->setFocusPolicy(Qt::WheelFocus);
        tableWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableCornerButton::section{background-color:#d1dff0;}\n"
"\n"
" QTableView\n"
"{\n"
"\n"
"	background-color: rgba(255, 255, 255, 0); \n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#677483;\n"
"	gridline-color: #ccddf0;\n"
"}\n"
"QTableView::item\n"
"{	\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#000000;\n"
"	gridline-color: #ccddf0; \n"
"}\n"
"\n"
" QTableView::item:selected\n"
"{	\n"
"	color:#677483;\n"
"}\n"
"\n"
" QHeaderView::section {	\n"
"	color: black;\n"
"	font:bold 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	text-align:center;\n"
"	height:32px;\n"
"	width :25px;\n"
"	background-color: #d1dff0;\n"
"	border:1px solid #8faac9;\n"
"	border-left:none;\n"
"\n"
"}\n"
"\n"
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
        tableWidget->horizontalHeader()->setDefaultSectionSize(45);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);

        verticalLayout->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        button_save = new QPushButton(centralwidget);
        button_save->setObjectName(QStringLiteral("button_save"));
        button_save->setMinimumSize(QSize(121, 41));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        button_save->setFont(font3);
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

        horizontalSpacer_3 = new QSpacerItem(13, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        button_stop = new QPushButton(centralwidget);
        button_stop->setObjectName(QStringLiteral("button_stop"));
        button_stop->setMinimumSize(QSize(121, 41));
        button_stop->setFont(font3);
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

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        butto_back = new QPushButton(centralwidget);
        butto_back->setObjectName(QStringLiteral("butto_back"));
        butto_back->setMinimumSize(QSize(121, 41));
        butto_back->setFont(font3);
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


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 2);

        set_parament1->setCentralWidget(centralwidget);

        retranslateUi(set_parament1);

        QMetaObject::connectSlotsByName(set_parament1);
    } // setupUi

    void retranslateUi(QMainWindow *set_parament1)
    {
        set_parament1->setWindowTitle(QApplication::translate("set_parament1", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("set_parament1", "\346\217\220\347\244\272\357\274\232\345\217\214\345\207\273\351\274\240\346\240\207\357\274\214\344\277\256\346\224\271\345\217\202\346\225\260\357\274\201", Q_NULLPTR));
        title->setText(QApplication::translate("set_parament1", "\344\270\200\345\217\267\346\210\277\351\227\264\345\202\254\351\235\222\345\256\244\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        label_2->setText(QString());

        const bool __sortingEnabled = tableWidget_head->isSortingEnabled();
        tableWidget_head->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = tableWidget_head->item(0, 0);
        ___qtablewidgetitem->setText(QApplication::translate("set_parament1", "asd", Q_NULLPTR));
        tableWidget_head->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("set_parament1", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("set_parament1", "\346\270\251\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("set_parament1", "\346\271\277\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem11->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem12->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem13->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem14->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem15->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem16->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem17->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(17);
        ___qtablewidgetitem18->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(18);
        ___qtablewidgetitem19->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(19);
        ___qtablewidgetitem20->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->horizontalHeaderItem(20);
        ___qtablewidgetitem21->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->horizontalHeaderItem(21);
        ___qtablewidgetitem22->setText(QApplication::translate("set_parament1", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->horizontalHeaderItem(22);
        ___qtablewidgetitem23->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->horizontalHeaderItem(23);
        ___qtablewidgetitem24->setText(QApplication::translate("set_parament1", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->horizontalHeaderItem(24);
        ___qtablewidgetitem25->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->horizontalHeaderItem(25);
        ___qtablewidgetitem26->setText(QApplication::translate("set_parament1", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->horizontalHeaderItem(26);
        ___qtablewidgetitem27->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->horizontalHeaderItem(27);
        ___qtablewidgetitem28->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->horizontalHeaderItem(28);
        ___qtablewidgetitem29->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->horizontalHeaderItem(29);
        ___qtablewidgetitem30->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->horizontalHeaderItem(30);
        ___qtablewidgetitem31->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->horizontalHeaderItem(31);
        ___qtablewidgetitem32->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->horizontalHeaderItem(32);
        ___qtablewidgetitem33->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->horizontalHeaderItem(33);
        ___qtablewidgetitem34->setText(QApplication::translate("set_parament1", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->horizontalHeaderItem(34);
        ___qtablewidgetitem35->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->horizontalHeaderItem(35);
        ___qtablewidgetitem36->setText(QApplication::translate("set_parament1", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->horizontalHeaderItem(36);
        ___qtablewidgetitem37->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->horizontalHeaderItem(37);
        ___qtablewidgetitem38->setText(QApplication::translate("set_parament1", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->horizontalHeaderItem(38);
        ___qtablewidgetitem39->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->horizontalHeaderItem(39);
        ___qtablewidgetitem40->setText(QApplication::translate("set_parament1", "\347\273\223\346\235\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem41->setText(QApplication::translate("set_parament1", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem42->setText(QApplication::translate("set_parament1", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem43->setText(QApplication::translate("set_parament1", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem44->setText(QApplication::translate("set_parament1", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem45->setText(QApplication::translate("set_parament1", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem46->setText(QApplication::translate("set_parament1", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem47->setText(QApplication::translate("set_parament1", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem48->setText(QApplication::translate("set_parament1", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem49->setText(QApplication::translate("set_parament1", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem50->setText(QApplication::translate("set_parament1", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem51->setText(QApplication::translate("set_parament1", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem52->setText(QApplication::translate("set_parament1", "12", Q_NULLPTR));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget->item(0, 0);
        ___qtablewidgetitem53->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget->item(0, 1);
        ___qtablewidgetitem54->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget->item(0, 2);
        ___qtablewidgetitem55->setText(QApplication::translate("set_parament1", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget->item(0, 3);
        ___qtablewidgetitem56->setText(QApplication::translate("set_parament1", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget->item(0, 4);
        ___qtablewidgetitem57->setText(QApplication::translate("set_parament1", "15:31", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget->item(0, 5);
        ___qtablewidgetitem58->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget->item(0, 6);
        ___qtablewidgetitem59->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget->item(0, 7);
        ___qtablewidgetitem60->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget->item(0, 8);
        ___qtablewidgetitem61->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget->item(0, 9);
        ___qtablewidgetitem62->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget->item(0, 10);
        ___qtablewidgetitem63->setText(QApplication::translate("set_parament1", "15:34", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget->item(0, 11);
        ___qtablewidgetitem64->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget->item(0, 12);
        ___qtablewidgetitem65->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget->item(0, 13);
        ___qtablewidgetitem66->setText(QApplication::translate("set_parament1", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget->item(0, 14);
        ___qtablewidgetitem67->setText(QApplication::translate("set_parament1", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget->item(0, 15);
        ___qtablewidgetitem68->setText(QApplication::translate("set_parament1", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget->item(0, 16);
        ___qtablewidgetitem69->setText(QApplication::translate("set_parament1", "15:37", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget->item(0, 17);
        ___qtablewidgetitem70->setText(QApplication::translate("set_parament1", "7\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget->item(0, 18);
        ___qtablewidgetitem71->setText(QApplication::translate("set_parament1", "15:38", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget->item(0, 19);
        ___qtablewidgetitem72->setText(QApplication::translate("set_parament1", "8\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget->item(0, 20);
        ___qtablewidgetitem73->setText(QApplication::translate("set_parament1", "15:31", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget->item(0, 21);
        ___qtablewidgetitem74->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget->item(0, 22);
        ___qtablewidgetitem75->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget->item(0, 23);
        ___qtablewidgetitem76->setText(QApplication::translate("set_parament1", "15:34", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget->item(0, 24);
        ___qtablewidgetitem77->setText(QApplication::translate("set_parament1", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget->item(0, 25);
        ___qtablewidgetitem78->setText(QApplication::translate("set_parament1", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget->item(0, 26);
        ___qtablewidgetitem79->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget->item(0, 27);
        ___qtablewidgetitem80->setText(QApplication::translate("set_parament1", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget->item(0, 28);
        ___qtablewidgetitem81->setText(QApplication::translate("set_parament1", "15:37", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget->item(0, 29);
        ___qtablewidgetitem82->setText(QApplication::translate("set_parament1", "15:38", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget->item(0, 30);
        ___qtablewidgetitem83->setText(QApplication::translate("set_parament1", "15:31", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem84 = tableWidget->item(0, 31);
        ___qtablewidgetitem84->setText(QApplication::translate("set_parament1", "0\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem85 = tableWidget->item(0, 32);
        ___qtablewidgetitem85->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem86 = tableWidget->item(0, 33);
        ___qtablewidgetitem86->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem87 = tableWidget->item(0, 34);
        ___qtablewidgetitem87->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem88 = tableWidget->item(0, 35);
        ___qtablewidgetitem88->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem89 = tableWidget->item(0, 36);
        ___qtablewidgetitem89->setText(QApplication::translate("set_parament1", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem90 = tableWidget->item(0, 37);
        ___qtablewidgetitem90->setText(QApplication::translate("set_parament1", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem91 = tableWidget->item(0, 38);
        ___qtablewidgetitem91->setText(QApplication::translate("set_parament1", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem92 = tableWidget->item(0, 39);
        ___qtablewidgetitem92->setText(QApplication::translate("set_parament1", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem93 = tableWidget->item(1, 0);
        ___qtablewidgetitem93->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem94 = tableWidget->item(1, 1);
        ___qtablewidgetitem94->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem95 = tableWidget->item(1, 2);
        ___qtablewidgetitem95->setText(QApplication::translate("set_parament1", "56.5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem96 = tableWidget->item(1, 5);
        ___qtablewidgetitem96->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem97 = tableWidget->item(1, 6);
        ___qtablewidgetitem97->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem98 = tableWidget->item(1, 7);
        ___qtablewidgetitem98->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem99 = tableWidget->item(1, 8);
        ___qtablewidgetitem99->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem100 = tableWidget->item(1, 9);
        ___qtablewidgetitem100->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem101 = tableWidget->item(1, 10);
        ___qtablewidgetitem101->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem102 = tableWidget->item(1, 11);
        ___qtablewidgetitem102->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem103 = tableWidget->item(1, 12);
        ___qtablewidgetitem103->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem104 = tableWidget->item(1, 13);
        ___qtablewidgetitem104->setText(QApplication::translate("set_parament1", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem105 = tableWidget->item(1, 14);
        ___qtablewidgetitem105->setText(QApplication::translate("set_parament1", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem106 = tableWidget->item(1, 15);
        ___qtablewidgetitem106->setText(QApplication::translate("set_parament1", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem107 = tableWidget->item(1, 33);
        ___qtablewidgetitem107->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem108 = tableWidget->item(2, 0);
        ___qtablewidgetitem108->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem109 = tableWidget->item(2, 1);
        ___qtablewidgetitem109->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem110 = tableWidget->item(2, 5);
        ___qtablewidgetitem110->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem111 = tableWidget->item(2, 6);
        ___qtablewidgetitem111->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem112 = tableWidget->item(2, 7);
        ___qtablewidgetitem112->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem113 = tableWidget->item(2, 8);
        ___qtablewidgetitem113->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem114 = tableWidget->item(2, 9);
        ___qtablewidgetitem114->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem115 = tableWidget->item(2, 10);
        ___qtablewidgetitem115->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem116 = tableWidget->item(2, 11);
        ___qtablewidgetitem116->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem117 = tableWidget->item(2, 12);
        ___qtablewidgetitem117->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem118 = tableWidget->item(2, 13);
        ___qtablewidgetitem118->setText(QApplication::translate("set_parament1", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem119 = tableWidget->item(2, 14);
        ___qtablewidgetitem119->setText(QApplication::translate("set_parament1", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem120 = tableWidget->item(2, 15);
        ___qtablewidgetitem120->setText(QApplication::translate("set_parament1", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem121 = tableWidget->item(2, 33);
        ___qtablewidgetitem121->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem122 = tableWidget->item(3, 0);
        ___qtablewidgetitem122->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem123 = tableWidget->item(3, 1);
        ___qtablewidgetitem123->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem124 = tableWidget->item(3, 5);
        ___qtablewidgetitem124->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem125 = tableWidget->item(3, 6);
        ___qtablewidgetitem125->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem126 = tableWidget->item(3, 7);
        ___qtablewidgetitem126->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem127 = tableWidget->item(3, 8);
        ___qtablewidgetitem127->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem128 = tableWidget->item(3, 9);
        ___qtablewidgetitem128->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem129 = tableWidget->item(3, 10);
        ___qtablewidgetitem129->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem130 = tableWidget->item(3, 11);
        ___qtablewidgetitem130->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem131 = tableWidget->item(3, 12);
        ___qtablewidgetitem131->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem132 = tableWidget->item(3, 13);
        ___qtablewidgetitem132->setText(QApplication::translate("set_parament1", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem133 = tableWidget->item(3, 14);
        ___qtablewidgetitem133->setText(QApplication::translate("set_parament1", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem134 = tableWidget->item(3, 15);
        ___qtablewidgetitem134->setText(QApplication::translate("set_parament1", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem135 = tableWidget->item(3, 33);
        ___qtablewidgetitem135->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem136 = tableWidget->item(4, 0);
        ___qtablewidgetitem136->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem137 = tableWidget->item(4, 1);
        ___qtablewidgetitem137->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem138 = tableWidget->item(4, 5);
        ___qtablewidgetitem138->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem139 = tableWidget->item(4, 6);
        ___qtablewidgetitem139->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem140 = tableWidget->item(4, 7);
        ___qtablewidgetitem140->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem141 = tableWidget->item(4, 8);
        ___qtablewidgetitem141->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem142 = tableWidget->item(4, 9);
        ___qtablewidgetitem142->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem143 = tableWidget->item(4, 10);
        ___qtablewidgetitem143->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem144 = tableWidget->item(4, 11);
        ___qtablewidgetitem144->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem145 = tableWidget->item(4, 12);
        ___qtablewidgetitem145->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem146 = tableWidget->item(4, 13);
        ___qtablewidgetitem146->setText(QApplication::translate("set_parament1", "5\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem147 = tableWidget->item(4, 14);
        ___qtablewidgetitem147->setText(QApplication::translate("set_parament1", "15:36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem148 = tableWidget->item(4, 15);
        ___qtablewidgetitem148->setText(QApplication::translate("set_parament1", "6\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem149 = tableWidget->item(4, 33);
        ___qtablewidgetitem149->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem150 = tableWidget->item(5, 0);
        ___qtablewidgetitem150->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem151 = tableWidget->item(5, 1);
        ___qtablewidgetitem151->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem152 = tableWidget->item(5, 5);
        ___qtablewidgetitem152->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem153 = tableWidget->item(5, 6);
        ___qtablewidgetitem153->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem154 = tableWidget->item(5, 7);
        ___qtablewidgetitem154->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem155 = tableWidget->item(5, 8);
        ___qtablewidgetitem155->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem156 = tableWidget->item(5, 9);
        ___qtablewidgetitem156->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem157 = tableWidget->item(5, 10);
        ___qtablewidgetitem157->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem158 = tableWidget->item(5, 11);
        ___qtablewidgetitem158->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem159 = tableWidget->item(5, 12);
        ___qtablewidgetitem159->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem160 = tableWidget->item(5, 33);
        ___qtablewidgetitem160->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem161 = tableWidget->item(6, 0);
        ___qtablewidgetitem161->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem162 = tableWidget->item(6, 1);
        ___qtablewidgetitem162->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem163 = tableWidget->item(6, 5);
        ___qtablewidgetitem163->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem164 = tableWidget->item(6, 6);
        ___qtablewidgetitem164->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem165 = tableWidget->item(6, 7);
        ___qtablewidgetitem165->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem166 = tableWidget->item(6, 8);
        ___qtablewidgetitem166->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem167 = tableWidget->item(6, 9);
        ___qtablewidgetitem167->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem168 = tableWidget->item(6, 10);
        ___qtablewidgetitem168->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem169 = tableWidget->item(6, 11);
        ___qtablewidgetitem169->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem170 = tableWidget->item(6, 12);
        ___qtablewidgetitem170->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem171 = tableWidget->item(6, 33);
        ___qtablewidgetitem171->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem172 = tableWidget->item(7, 0);
        ___qtablewidgetitem172->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem173 = tableWidget->item(7, 1);
        ___qtablewidgetitem173->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem174 = tableWidget->item(7, 5);
        ___qtablewidgetitem174->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem175 = tableWidget->item(7, 6);
        ___qtablewidgetitem175->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem176 = tableWidget->item(7, 7);
        ___qtablewidgetitem176->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem177 = tableWidget->item(7, 8);
        ___qtablewidgetitem177->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem178 = tableWidget->item(7, 9);
        ___qtablewidgetitem178->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem179 = tableWidget->item(7, 10);
        ___qtablewidgetitem179->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem180 = tableWidget->item(7, 11);
        ___qtablewidgetitem180->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem181 = tableWidget->item(7, 12);
        ___qtablewidgetitem181->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem182 = tableWidget->item(7, 33);
        ___qtablewidgetitem182->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem183 = tableWidget->item(8, 0);
        ___qtablewidgetitem183->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem184 = tableWidget->item(8, 1);
        ___qtablewidgetitem184->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem185 = tableWidget->item(8, 5);
        ___qtablewidgetitem185->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem186 = tableWidget->item(8, 6);
        ___qtablewidgetitem186->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem187 = tableWidget->item(8, 7);
        ___qtablewidgetitem187->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem188 = tableWidget->item(8, 8);
        ___qtablewidgetitem188->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem189 = tableWidget->item(8, 9);
        ___qtablewidgetitem189->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem190 = tableWidget->item(8, 10);
        ___qtablewidgetitem190->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem191 = tableWidget->item(8, 11);
        ___qtablewidgetitem191->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem192 = tableWidget->item(8, 12);
        ___qtablewidgetitem192->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem193 = tableWidget->item(8, 33);
        ___qtablewidgetitem193->setText(QApplication::translate("set_parament1", "10\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem194 = tableWidget->item(9, 0);
        ___qtablewidgetitem194->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem195 = tableWidget->item(9, 1);
        ___qtablewidgetitem195->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem196 = tableWidget->item(9, 5);
        ___qtablewidgetitem196->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem197 = tableWidget->item(9, 6);
        ___qtablewidgetitem197->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem198 = tableWidget->item(9, 7);
        ___qtablewidgetitem198->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem199 = tableWidget->item(9, 8);
        ___qtablewidgetitem199->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem200 = tableWidget->item(9, 9);
        ___qtablewidgetitem200->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem201 = tableWidget->item(9, 10);
        ___qtablewidgetitem201->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem202 = tableWidget->item(9, 11);
        ___qtablewidgetitem202->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem203 = tableWidget->item(9, 12);
        ___qtablewidgetitem203->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem204 = tableWidget->item(10, 0);
        ___qtablewidgetitem204->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem205 = tableWidget->item(10, 1);
        ___qtablewidgetitem205->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem206 = tableWidget->item(10, 5);
        ___qtablewidgetitem206->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem207 = tableWidget->item(10, 6);
        ___qtablewidgetitem207->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem208 = tableWidget->item(10, 7);
        ___qtablewidgetitem208->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem209 = tableWidget->item(10, 8);
        ___qtablewidgetitem209->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem210 = tableWidget->item(10, 9);
        ___qtablewidgetitem210->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem211 = tableWidget->item(10, 10);
        ___qtablewidgetitem211->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem212 = tableWidget->item(10, 11);
        ___qtablewidgetitem212->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem213 = tableWidget->item(10, 12);
        ___qtablewidgetitem213->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem214 = tableWidget->item(11, 0);
        ___qtablewidgetitem214->setText(QApplication::translate("set_parament1", "2016/12/13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem215 = tableWidget->item(11, 1);
        ___qtablewidgetitem215->setText(QApplication::translate("set_parament1", "2016/12/14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem216 = tableWidget->item(11, 5);
        ___qtablewidgetitem216->setText(QApplication::translate("set_parament1", "1\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem217 = tableWidget->item(11, 6);
        ___qtablewidgetitem217->setText(QApplication::translate("set_parament1", "15:32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem218 = tableWidget->item(11, 7);
        ___qtablewidgetitem218->setText(QApplication::translate("set_parament1", "2\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem219 = tableWidget->item(11, 8);
        ___qtablewidgetitem219->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem220 = tableWidget->item(11, 9);
        ___qtablewidgetitem220->setText(QApplication::translate("set_parament1", "3\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem221 = tableWidget->item(11, 10);
        ___qtablewidgetitem221->setText(QApplication::translate("set_parament1", "15:33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem222 = tableWidget->item(11, 11);
        ___qtablewidgetitem222->setText(QApplication::translate("set_parament1", "4\345\210\206\351\222\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem223 = tableWidget->item(11, 12);
        ___qtablewidgetitem223->setText(QApplication::translate("set_parament1", "15:35", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled1);

        button_save->setText(QApplication::translate("set_parament1", "\345\274\200\345\247\213\345\202\254\351\235\222", Q_NULLPTR));
        button_stop->setText(QApplication::translate("set_parament1", "\345\201\234\346\255\242\345\202\254\351\235\222", Q_NULLPTR));
        butto_back->setText(QApplication::translate("set_parament1", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class set_parament1: public Ui_set_parament1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_PARAMENT1_H
