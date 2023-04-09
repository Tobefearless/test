#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include "pub/mysql.h"
#include <pub/pub.h>
#include <QMutex>
class Mythread : public QObject
{
    Q_OBJECT
public:
    explicit Mythread(QObject *parent = nullptr);

    //线程处理函数
    void myTimeout();
    //显示函数
    void FromDB_Data();

    void Pattern_query();

signals:
    void Data_Signal(QVariant info);

public slots:
private:
    static QMutex mutex;
    bool network_Status;

    //判断文件的谁更新
    void Update_judgment();
    //遍历文件夹，找出最新的时间
    uint getfiles(const QString &dir_path,uint &max_time);
public:
     mysql *DBT;

};

#endif // MYTHREAD_H
