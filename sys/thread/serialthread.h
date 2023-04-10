#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QObject>
#include "pub/mysql.h"
#include <pub/pub.h>
#include <QMutex>
class SerialThread : public QObject
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = nullptr);
signals:
     void Serial_data(QByteArray data);
     void data_com();
public slots:
     void Time_Out();
private:
    QMutex mutex;
    QTimer *m_timer;
    QByteArray buffer;
    bool timer_flag;
};

#endif // SERIALTHREAD_H
