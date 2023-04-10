#include "mythread.h"

QMutex Mythread::mutex;
Mythread::Mythread(QObject *parent) : QObject(parent)
{
    DBT = new mysql(this);

    network_Status = false;

}

void Mythread::myTimeout()
{
    if(!DBT->open("test2")){
        global_data::on_line = false;
    }
    else{
        global_data::on_line = true;
    }

    while( !QThread::currentThread()->isInterruptionRequested() ){
        //for( uint8_t i = 0 ; i < DEV ; i++ ){

            if( !DBT->toDB() ){
                DBT->open("test2");
                global_data::on_line = false;
                QThread::sleep(10);
            }
            else{
                global_data::on_line = true;
            }

            if( global_data::on_line ){
                    Mythread::mutex.lock();
                    DBT->GetTable(QString(global_data::id[0]));
                    Mythread::mutex.unlock();
            }

            QThread::sleep(5);
        //}
    }

}

void Mythread::FromDB_Data()
{
    if(!DBT->open("data_recive")){
        global_data::on_line = false;
    }
    else{
        global_data::on_line = true;
    }
    global_data::on_line = DBT->open("data_recive");
    FROM_DB_Typedef From_data;
    QVariant data;
    qDebug()<<"线程结束标志位"<<QThread::currentThread()->isInterruptionRequested();

    while( !QThread::currentThread()->isInterruptionRequested() ){

       // for( uint8_t i = 0 ; i < DEV  ; i++ ){
           // uint8_t i = 0;
            if( global_data::Mutual_exclusion[0] == DataBase){
                From_data.id = QString(global_data::id[0]);
                if( !DBT->toDB() ){
                    DBT->open("data_recive");
                    global_data::on_line = false;
                }
                else{
                    global_data::on_line = true;
                }
                if( global_data::on_line ){
                    Mythread::mutex.lock();
                    if ( !DBT->fromDB(&From_data)){

                             From_data.status = OFFLINE;
                    }
                    Mythread::mutex.unlock();
                    data.setValue(From_data);
                    emit Data_Signal(data);
                }
                else{
                     qDebug()<<"设备ID"<<From_data.id;
                     From_data.status = OFFLINE;
                     data.setValue(From_data);
                     emit Data_Signal(data);
                }


            }

                QThread::sleep(5);
        //}
    }
}

void Mythread::Pattern_query()
{

    global_data::on_line = DBT->open("mode_query");
    qDebug()<<"线程结束标志位"<<QThread::currentThread()->isInterruptionRequested();
    while( !QThread::currentThread()->isInterruptionRequested() ){


                    if( !DBT->toDB() ){
                        DBT->open("mode_query");
                        global_data::on_line = false;
                    }
                    else{
                        global_data::on_line = true;
                    }

                    if( global_data::on_line ){
                            Mythread::mutex.lock();
                            DBT->GetMode();
                            Mythread::mutex.unlock();
                    }

                    QThread::sleep(2);

    }
}

void Mythread::Update_judgment()
{
        //1.获取本地文件最新更新时间
        uint local_time = 0,data_time = 0;
        bool status = false;
        getfiles(QString(FILENAME),local_time);
        //2.获取数据库最新更新时间
        data_time = DBT->Get_Update_Time();
        //3.比较哪一个时间更新
        if( local_time > data_time){
            for( uint8_t i = 0 ; i < DEV ; i++ ){
                status = DBT->AllTableToDB(global_data::update_allTable[i],global_data::execute_date[i],"1","1");
            }
        }
        else{
            network_Status = false;
        }

        if( status ){
            network_Status = false;
        }

}

uint Mythread::getfiles(const QString &dir_path, uint &max_time)
{
    QDir dir(dir_path);
    if(!dir.exists())
    {
        qDebug() << "it is not true dir_path";
    }

    /*设置过滤参数，QDir::NoDotAndDotDot表示不会去遍历上层目录*/
    QDirIterator dir_iterator(dir_path,QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot,QDirIterator::Subdirectories);

    while(dir_iterator.hasNext())
    {
        dir_iterator.next();
        QFileInfo file_info = dir_iterator.fileInfo();
        QString files = file_info.absoluteFilePath();
        QDateTime dt = file_info.lastModified();
        QString modify_time = tr("%1").arg(dt.toString("yyyy-MM-dd hh:mm:ss"));
        if( max_time < dt.toTime_t() && !files.contains("user.txt")){
            max_time = dt.toTime_t();
        }
        qDebug()<<files<<modify_time;
    }

    return max_time;
}
