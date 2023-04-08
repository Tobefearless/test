/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineEdit_Id;
    QPushButton *pushButton_subscription;
    QPushButton *pushButton_unsubscribe;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(328, 109);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 111, 51));
        lineEdit_Id = new QLineEdit(centralWidget);
        lineEdit_Id->setObjectName(QStringLiteral("lineEdit_Id"));
        lineEdit_Id->setGeometry(QRect(130, 20, 191, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lineEdit_Id->setFont(font);
        pushButton_subscription = new QPushButton(centralWidget);
        pushButton_subscription->setObjectName(QStringLiteral("pushButton_subscription"));
        pushButton_subscription->setGeometry(QRect(20, 70, 101, 31));
        pushButton_subscription->setFont(font);
        pushButton_unsubscribe = new QPushButton(centralWidget);
        pushButton_unsubscribe->setObjectName(QStringLiteral("pushButton_unsubscribe"));
        pushButton_unsubscribe->setGeometry(QRect(200, 70, 111, 31));
        pushButton_unsubscribe->setFont(font);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; color:#ff0000;\">\350\256\242\351\230\205\347\232\204ID:</span></p></body></html>", Q_NULLPTR));
        lineEdit_Id->setText(QApplication::translate("MainWindow", "LSSF210601002", Q_NULLPTR));
        pushButton_subscription->setText(QApplication::translate("MainWindow", "\350\256\242\351\230\205", Q_NULLPTR));
        pushButton_unsubscribe->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210\350\256\242\351\230\205", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
