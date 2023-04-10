/********************************************************************************
** Form generated from reading UI file 'historical.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORICAL_H
#define UI_HISTORICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <pub/qwchartview.h>

QT_BEGIN_NAMESPACE

class Ui_Historical_curve
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWChartView *chartView;
    QSpacerItem *horizontalSpacer_3;
    QDateEdit *time_sta;
    QComboBox *com_room;
    QLabel *label;
    QDateEdit *time_end;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QComboBox *com_interval;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QMainWindow *Historical_curve)
    {
        if (Historical_curve->objectName().isEmpty())
            Historical_curve->setObjectName(QStringLiteral("Historical_curve"));
        Historical_curve->resize(1385, 612);
        centralwidget = new QWidget(Historical_curve);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        chartView = new QWChartView(centralwidget);
        chartView->setObjectName(QStringLiteral("chartView"));
        chartView->setStyleSheet(QStringLiteral("background: transparent;"));

        gridLayout->addWidget(chartView, 1, 0, 1, 12);

        horizontalSpacer_3 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        time_sta = new QDateEdit(centralwidget);
        time_sta->setObjectName(QStringLiteral("time_sta"));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        time_sta->setFont(font);
        time_sta->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(time_sta, 0, 3, 1, 1);

        com_room = new QComboBox(centralwidget);
        com_room->setObjectName(QStringLiteral("com_room"));
        com_room->setMinimumSize(QSize(240, 0));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        com_room->setFont(font1);
        com_room->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"border:3px solid rgb(255,255,255);\n"
"\n"
""));

        gridLayout->addWidget(com_room, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        time_end = new QDateEdit(centralwidget);
        time_end->setObjectName(QStringLiteral("time_end"));
        time_end->setFont(font);
        time_end->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(time_end, 0, 6, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setPointSize(26);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 7, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(120, 0));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
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

        gridLayout->addWidget(pushButton, 0, 11, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 8, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 10, 1, 1);

        com_interval = new QComboBox(centralwidget);
        com_interval->setObjectName(QStringLiteral("com_interval"));
        com_interval->setFont(font);
        com_interval->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"border:3px solid rgb(255,255,255);\n"
"\n"
""));

        gridLayout->addWidget(com_interval, 0, 9, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        Historical_curve->setCentralWidget(centralwidget);

        retranslateUi(Historical_curve);

        QMetaObject::connectSlotsByName(Historical_curve);
    } // setupUi

    void retranslateUi(QMainWindow *Historical_curve)
    {
        Historical_curve->setWindowTitle(QApplication::translate("Historical_curve", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("Historical_curve", "<html><head/><body><p><span style=\" font-weight:600;\">\345\274\200\345\247\213\346\227\245\346\234\237</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Historical_curve", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">\347\273\223\346\235\237\346\227\245\346\234\237</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Historical_curve", "\346\237\245\350\257\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("Historical_curve", "<html><head/><body><p>\346\227\266\351\227\264\345\210\206\350\276\250\347\216\207</p></body></html>", Q_NULLPTR));
        com_interval->clear();
        com_interval->insertItems(0, QStringList()
         << QApplication::translate("Historical_curve", "3 \345\210\206\351\222\237", Q_NULLPTR)
         << QApplication::translate("Historical_curve", "5 \345\210\206\351\222\237", Q_NULLPTR)
         << QApplication::translate("Historical_curve", "10 \345\210\206\351\222\237", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class Historical_curve: public Ui_Historical_curve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORICAL_H
