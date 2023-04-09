/********************************************************************************
** Form generated from reading UI file 'comms_indicate.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMS_INDICATE_H
#define UI_COMMS_INDICATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_COMMS_indicate
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *COMMS_indicate)
    {
        if (COMMS_indicate->objectName().isEmpty())
            COMMS_indicate->setObjectName(QStringLiteral("COMMS_indicate"));
        COMMS_indicate->resize(1449, 792);
        COMMS_indicate->setStyleSheet(QLatin1String("/*#COMMS_indicate{\n"
"	\n"
"	background-image: url(:/img/16pic_591937_s.jpg);\n"
"}"));
        centralwidget = new QWidget(COMMS_indicate);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(300, 130, 921, 571));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        listWidget->setFont(font);
        listWidget->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"	background-color:transparent"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1240, 160, 101, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
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
        COMMS_indicate->setCentralWidget(centralwidget);

        retranslateUi(COMMS_indicate);

        QMetaObject::connectSlotsByName(COMMS_indicate);
    } // setupUi

    void retranslateUi(QMainWindow *COMMS_indicate)
    {
        COMMS_indicate->setWindowTitle(QApplication::translate("COMMS_indicate", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("COMMS_indicate", "\346\232\202\345\201\234", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class COMMS_indicate: public Ui_COMMS_indicate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMS_INDICATE_H
