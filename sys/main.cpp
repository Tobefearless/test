#include "mainwindow.h"
#include <QApplication>
#include <QTranslator> //新增
#include "QtConcurrent"
#include <table/set_parament1.h>
#include <table/seed1.h>
#include <table/co_parenting1.h>
mysql DB;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator; //新建翻译类
    translator.load(":/img/qt_zh_CN"); //导入生成的文件
    a.installTranslator(&translator); //装入
    MainWindow w;
    //w.setWindowIcon(QIcon(":/img/登录主图.jpg"));
   // QApplication::addLibraryPath("./plugins");
   // QString strLibPath(QDir::toNativeSeparators(QApplication::applicationDirPath())+QDir::separator()+“plugins”);
   // a.addLibraryPath(strLibPath);

    w.show();

    return a.exec();
}
