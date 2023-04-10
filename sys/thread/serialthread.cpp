#include "serialthread.h"

SerialThread::SerialThread(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    buffer.clear();
    m_timer->setInterval(2);
   connect(serial,&QSerialPort::readyRead,[=]{
       //if( !m_timer->isActive())
            m_timer->start();

        timer_flag = true;
        //qApp->processEvents();
        buffer.append(serial->readAll());
        //timer_flag = false;
    });

    connect(m_timer,&QTimer::timeout,this,&SerialThread::Time_Out);

}

void SerialThread::Time_Out()
{
    if( timer_flag == false ){
        m_timer->stop();
        emit Serial_data(buffer);
        buffer.clear();
        buffer.squeeze();

    }

        timer_flag = false;
}
