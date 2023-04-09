/********************************************************************************
** Form generated from reading UI file 'user_management.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_MANAGEMENT_H
#define UI_USER_MANAGEMENT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User_Management
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_account;
    QLineEdit *lineEdit_passwd;
    QPushButton *btn_add;
    QPushButton *btn_remove;

    void setupUi(QMainWindow *User_Management)
    {
        if (User_Management->objectName().isEmpty())
            User_Management->setObjectName(QStringLiteral("User_Management"));
        User_Management->resize(1501, 602);
        User_Management->setStyleSheet(QLatin1String("/*#User_Management{\n"
"	background-image: url(:/img/16pic_591937_s.jpg);\n"
"}*/"));
        centralwidget = new QWidget(User_Management);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(370, 90, 661, 401));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QLatin1String("QGroupBox::title\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top center;\n"
"padding:0 3px;\n"
"}"));
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 30, 641, 361));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableView\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0); \n"
"	alternate-background-color:#e3edf9;\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
"	border-left:1px solid #8faac9;\n"
"}\n"
""));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1040, 110, 81, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1040, 160, 81, 31));
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_account = new QLineEdit(centralwidget);
        lineEdit_account->setObjectName(QStringLiteral("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(1150, 110, 211, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(12);
        lineEdit_account->setFont(font2);
        lineEdit_account->setStyleSheet(QLatin1String("QLineEdit{\n"
"border: 2px solid gray\n"
"}"));
        lineEdit_passwd = new QLineEdit(centralwidget);
        lineEdit_passwd->setObjectName(QStringLiteral("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(1150, 160, 211, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        lineEdit_passwd->setFont(font3);
        lineEdit_passwd->setStyleSheet(QLatin1String("QLineEdit{\n"
"border: 2px solid gray\n"
"}"));
        lineEdit_passwd->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        lineEdit_passwd->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        lineEdit_passwd->setEchoMode(QLineEdit::Password);
        btn_add = new QPushButton(centralwidget);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        btn_add->setGeometry(QRect(1150, 350, 211, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        btn_add->setFont(font4);
        btn_add->setStyleSheet(QLatin1String("\n"
"\n"
"QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:2px groove gray;\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #3C80B1;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(181, 225, 250, 255), stop:0.50001 rgba(222, 242, 251, 255));\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border: 1px solid #5F92B2;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(134, 198, 233, 255), stop:0.50001 rgba(206, 234, 248, 255));\n"
"}\n"
"\n"
""));
        btn_remove = new QPushButton(centralwidget);
        btn_remove->setObjectName(QStringLiteral("btn_remove"));
        btn_remove->setGeometry(QRect(1150, 440, 211, 41));
        btn_remove->setFont(font4);
        btn_remove->setStyleSheet(QLatin1String("\n"
"\n"
"QPushButton {\n"
"color: rgb(255, 255, 255);\n"
" border:2px groove gray;\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #3C80B1;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(181, 225, 250, 255), stop:0.50001 rgba(222, 242, 251, 255));\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    border: 1px solid #5F92B2;\n"
"    background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(134, 198, 233, 255), stop:0.50001 rgba(206, 234, 248, 255));\n"
"}\n"
"\n"
""));
        User_Management->setCentralWidget(centralwidget);

        retranslateUi(User_Management);

        QMetaObject::connectSlotsByName(User_Management);
    } // setupUi

    void retranslateUi(QMainWindow *User_Management)
    {
        User_Management->setWindowTitle(QApplication::translate("User_Management", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("User_Management", "\347\224\250\346\210\267\345\210\227\350\241\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("User_Management", "\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("User_Management", "\347\224\250\346\210\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("User_Management", "\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("User_Management", "\347\224\250\346\210\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("User_Management", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        btn_add->setText(QApplication::translate("User_Management", "\346\267\273\345\212\240", Q_NULLPTR));
        btn_remove->setText(QApplication::translate("User_Management", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class User_Management: public Ui_User_Management {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MANAGEMENT_H
