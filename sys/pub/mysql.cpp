#include "mysql.h"
#include "QtNetwork/qnetworkinterface.h"
QMutex mysql::mutex ;
mysql::mysql(QObject *parent) : QObject(parent)
{
    isopen = false;
    room = -1;
    work_way.head = GET_DEV_STATUS_HEAD;
    work_way.tail = GET_DEV_STATUS_TAIL;

}

bool mysql::login(QString userName, QString password)
{
       QString   sql;
       QString area = QString(global_data::id[0]).left(10);
       sql = QString(R"(SELECT *from `user_Maneger` where user='%1' )").arg(userName);
       QSqlQuery  query(db);
       if(query.exec(sql)){
           while (query.next()) {
               qDebug()<<"账号"<<query.value(1).toString()
                      <<"密码:::"<<query.value(2).toString();
               if ( query.value("user").toString() == userName &&
                    query.value("password").toString() == password &&
                    (query.value("area").toString() == "all" ||
                     query.value("area").toString() == area)){
                    return true;
               }
           }
        }
       

       return false;
}

QString mysql::select(QString userName, QString type)
{
    QString   sql;
        sql = QString("SELECT %1 from dataSheet where user='%2'").arg(type,userName);
        QSqlQuery  query(db);
        if(query.exec(sql)){
            while (query.next()) {
               return query.value(0).toString();
            }
         }
        return "error";
}

bool mysql::fromDB(FROM_DB_Typedef *data)
{
    QString   sql;
    sql = QString("SELECT *from `update_all_table` where id='%1'").arg(data->id);

    QSqlQuery  query(db);
    if(query.exec(sql)){
        while (query.next()) {
                     bool ok;
                     QByteArray temp =  HexStringToByteArray(ByteArrayToHexString(query.value("to_app").toString()), &ok);

                     FROM_MCU_Typedef from_mcu;

                     char *rcv = temp.data();
                     uint8_t head = QString(temp.left(1).toHex()).toInt(&ok,16);
                     uint8_t tail = QString(temp.right(3).left(1).toHex()).toInt(&ok,16);

                     if( TO_APP_HEAD == head && TO_APP_TAIL == tail ){

                         memcpy((char*)&from_mcu,rcv,sizeof(FROM_MCU_Typedef));


                         uint16_t crc = CRC16_2_modbus((uint8_t*)&from_mcu,sizeof(FROM_MCU_Typedef)-2);
                         if( crc == from_mcu.crc ){

                                    //离线、在线状态判断
                                    if( query.value("dev_status").toInt() == 1 ){
                                        data->status = ONLINE;
                                    }
                                    else{
                                        data->status = OFFLINE;
                                        return false;
                                    }

                                    //心跳包清零
                                    data->temp = QString::number((double)from_mcu.temp/10,'f',1);
                                    data->humi = QString::number((double)from_mcu.humi/10,'f',1);

                                    data->temp_center = QString::number((double)from_mcu.now_sensor.temp_center/10,'f',1);
                                    data->humi_center = QString::number((double)from_mcu.now_sensor.humi_center/10,'f',1);


                                    //qDebug()<<"中心温度"<<data->temp_center<<"中心湿度"<<data->humi_center;
                                    for( uint8_t i = 0 ; i < Sensor_Number ; i++ ){
                                        data->signle_senser[i] = from_mcu.signle_senser[i];

                                    }

                                    data->air_status = from_mcu.air_status;

                                    data->relay_status = from_mcu.relay_status;

                            return true;
                         }
                     }

        }

     }
    return false;
}

bool mysql::fromDBAll(FROM_DB_Typedef *data)
{
    //qDebug()<<"正在查询";
    static bool rcv_flag[DEV] = {false};
    QString   sql;
     sql = QString("SELECT *from `update_all_table` where id='%1'").arg(data->id);
    bool show_status = true;
    QSqlQuery  query(db);
    if(query.exec(sql)){
        while (query.next()) {

            if( query.value(1).toString().contains(data->id )){

                     bool ok;
                     QByteArray temp =  HexStringToByteArray(ByteArrayToHexString(query.value(5).toString()), &ok);
                     FROM_MCU_Typedef from_mcu;

                     char *rcv = temp.data();
                     uint8_t head = QString(temp.left(1).toHex()).toInt(&ok,16);
                     uint8_t tail = QString(temp.right(3).left(1).toHex()).toInt(&ok,16);

                     if( TO_APP_HEAD == head && TO_APP_TAIL == tail ){

                         memcpy((char*)&from_mcu,rcv,sizeof(FROM_MCU_Typedef));


                         uint16_t crc = CRC16_2_modbus((uint8_t*)&from_mcu,sizeof(FROM_MCU_Typedef)-2);
                         if( crc == from_mcu.crc ){

                                    //离线、在线状态判断
                                    if( query.value(6).toInt() == 1 ){
                                        data->status = ONLINE;
                                    }
                                    else{
                                        data->status = OFFLINE;
                                        show_status = true;
                                    }

                                    //心跳包清零
                                    data->temp = QString::number((double)from_mcu.temp/10,'f',1);
                                    data->humi = QString::number((double)from_mcu.humi/10,'f',1);

                                    data->temp_center = QString::number((double)from_mcu.now_sensor.temp_center/10,'f',1);
                                    data->humi_center = QString::number((double)from_mcu.now_sensor.humi_center/10,'f',1);


                                    //qDebug()<<"中心温度"<<data->temp_center<<"中心湿度"<<data->humi_center;
                                    for( uint8_t i = 0 ; i < Sensor_Number ; i++ ){
                                        data->signle_senser[i] = from_mcu.signle_senser[i];

                                    }

                                    data->air_status = from_mcu.air_status;

                                    data->relay_status = from_mcu.relay_status;

                            show_status = false;
                         }
                     }

            }


            //表格判断
           // qDebug()<<"程序崩盘"<<query.value(4).toInt();
                //Dev_Clear(query.value(1).toString());
                uint8_t id = query.value(1).toString().right(3).toInt() - 1;
                uint8_t temp = 0;
                if( query.value(7).toString() == "1"){
                    if( !rcv_flag[id] ){
                        rcv_flag[id] = true;
                    }
                    else{
                        Dev_Clear(query.value(1).toString());
                        rcv_flag[id] = false;
                    }
                    temp = 4;
                }


                bool ok;
                UPDATE_ALL_TABLE_TYPEDEF From_DB_table;
                QByteArray data =HexStringToByteArray(ByteArrayToHexString(query.value(2).toString()), &ok);

                char *rcv = data.data();
                uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
                uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);

                if( TABLE_HEAD == head && TABLE_TAIL == tail){
                    memcpy((char *)&From_DB_table,rcv,sizeof(UPDATE_ALL_TABLE_TYPEDEF));
                    //qDebug()<<"表数据----------"<<id;
                    uint16_t crc = CRC16_2_modbus((uint8_t*)&From_DB_table,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);
                    if( From_DB_table.crc == crc ){
                        qDebug()<<"房间ID.........."<<id;
                        global_data::update_allTable[id] = From_DB_table;
//                        global_data::room_flag[id] = false;
//                        global_data::update_RoomFlag[id] = true;
                        room = id + temp;
                        emit send_ChangeTable();
                        qDebug()<<"数据查询成功";
                        }
                }



        }
    }
    return (!show_status);
}

bool mysql::toDB()
{
    QString   sql;
        bool result;
        sql = QString("SELECT * from `toapp` ");
        QSqlQuery  query(db);
        result = query.exec(sql);

        return result;
}

bool mysql::open(const QString connnectname)
{
if(QSqlDatabase::contains(connnectname)){
       db = QSqlDatabase::database(connnectname);
       isopen = true;
   }
   else{
       db = QSqlDatabase::addDatabase("QMYSQL",connnectname);
       db.setHostName("1.14.26.239");
       db.setPort(3306);
       db.setDatabaseName("user");
       db.setUserName("root");
       db.setPassword("czy123456");
       db.setConnectOptions("MYSQL_OPT_RECONNECT=1;");
   }
    isopen =  db.open();
    qDebug()<<isopen;
    return isopen;
}

bool mysql::close()
{
    db.close();
    return true;
}

bool mysql::AllTableToDB(UPDATE_ALL_TABLE_TYPEDEF data,EXECUTE_DATE_Typedef excute,QString app_status,QString change_status)
{
    data = global_data::update_allTable[0];
    QString   sql;
    data.crc = CRC16_2_modbus((uint8_t*)&data,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);
    QByteArray table_values = Convert_struct((char*)&data,sizeof(data));
    QString id = QString(data.id);
    QDateTime dTime = QDateTime::currentDateTime();
    qDebug()<<"我发的table_values"<<table_values;

    qDebug()<<"id"<<id;
    bool result = true;

    sql = QString("update `update_all_table` set table_values = '%1',sta_date = '%2',end_date = '%3',run_stage = %4,app_change_status = %5,pc_change_status = %6,update_time = %7 "
                   " where id= '%8' ").arg(table_values.toHex(),excute.sta_date,excute.end_date,QString::number(excute.run_stage),app_status,change_status,QString::number(dTime.toTime_t()),id);
    QSqlQuery  query(db);

   // result = query.exec(sql);

    qDebug()<<"写入状态:"<<result;
    qDebug()<<"全部参数更新到数据库";
    return result;
}

bool mysql::AllTableToDB(UPDATE_ALL_TABLE_TYPEDEF data,EXECUTE_DATE_Typedef excute)
{
    QString   sql;
    data.crc = CRC16_2_modbus((uint8_t*)&data,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);
    QByteArray table_values = Convert_struct((char*)&data,sizeof(UPDATE_ALL_TABLE_TYPEDEF));
    QString id = QString(data.id);
    QDateTime dTime = QDateTime::currentDateTime();
    qDebug()<<"我发的table_values"<<table_values;

    qDebug()<<"id"<<id;
    bool result;

    sql = QString("update `update_all_table` set table_values = '%1',sta_date = '%2',end_date = '%3',run_stage = %4,update_time = %5 "
                   " where id= '%6' ").arg(table_values.toHex(),excute.sta_date,excute.end_date,QString::number(excute.run_stage),QString::number(dTime.toTime_t()),id);
    QSqlQuery  query(db);
    result = query.exec(sql);

    qDebug()<<"写入状态:"<<result;
    qDebug()<<"全部参数更新到数据库";
    return result;
}

bool mysql::AllTableToDB(QString id,EXECUTE_DATE_Typedef excute)
{
    QString   sql;
    bool result = false;
    QDateTime dTime = QDateTime::currentDateTime();
    sql = QString("update `update_all_table` set sta_date = '%1',end_date = '%2',run_stage = %3,update_time = %4 "
                   " where id= '%5' ").arg(excute.sta_date,excute.end_date,QString::number(excute.run_stage),QString::number(dTime.toTime_t()),id);
    QSqlQuery  query(db);
    result = query.exec(sql);

    qDebug()<<"写入状态:"<<result;
    qDebug()<<"全部参数更新到数据库";
    return result;
}

bool mysql::WORKwayToDB(WORK_WAY_TYEP data,QString status)
{
    QString   sql;
    data.crc = CRC16_2_modbus((uint8_t*)&data,sizeof(WORK_WAY_TYEP)-2);
    QByteArray work_way = Convert_struct((char*)&data,sizeof(data));
    QString id = QString(data.id);
    qDebug()<<"我发的WORK_STATUS"<<work_way.toHex()
           <<id;

    qDebug()<<"id"<<id;
    bool result;

    sql = QString("update `update_all_table` set run_way_to_mcu = '%1',run_way_to_mcu_status = %2 "
                   " where id= '%3' ").arg(work_way.toHex(),status,id);
    QSqlQuery  query(db);
    result = query.exec(sql);

    qDebug()<<"写入状态:"<<result;
    qDebug()<<"全部参数更新到数据库";
    return result;
}

//bool mysql::GetTable()
//{

//    //接收标志位
//    static bool rcv_flag[DEV] = {false};
//    QString sql;

//    //qDebug()<<"表格数据获取";
//    QString area = QString(global_data::id[0]).left(10);
//    QSqlQuery  query(db);
//    sql = QString(R"( SELECT * FROM `update_all_table` WHERE id LIKE '%%1%' )")
//            .arg(area);
//    if(query.exec(sql)){
//        while (query.next()) {


//                uint8_t id = query.value(1).toString().right(3).toInt() - 1;
//                uint8_t temp = 0;
//                if( query.value(7).toString() == "1"){
//                    if( !rcv_flag[id] ){
//                        rcv_flag[id] = true;
//                    }
//                    else{
//                        Dev_Clear(query.value(1).toString());
//                        rcv_flag[id] = false;
//                    }
//                    temp = 4;
//                }

//               // qDebug()<<"设备状态清零"<<Dev_Clear(query.value(1).toString());
//                bool ok;
//                UPDATE_ALL_TABLE_TYPEDEF From_DB_table;
//                QByteArray data =HexStringToByteArray(ByteArrayToHexString(query.value(2).toString()), &ok);


//                char *rcv = data.data();
//                uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
//                uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);
//                //qDebug()<<"head"<<head<<"tail"<<tail;
//                if( TABLE_HEAD == head && TABLE_TAIL == tail){
//                    memcpy((char *)&From_DB_table,rcv,sizeof(UPDATE_ALL_TABLE_TYPEDEF));
//                    //qDebug()<<"表数据----------";
//                    uint16_t crc = CRC16_2_modbus((uint8_t*)&From_DB_table,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);
//                    if( From_DB_table.crc == crc ){
//                        if( global_data::Send_onine_flag[id] || global_data::room_flag[id])
//                        {
//                            global_data::update_allTable[id] = From_DB_table;

//                            room = id + temp;

//                            qDebug()<<"温度矫正"<<global_data::update_allTable[id].set_senser_diff[0].temp_adjust
//                                   <<"湿度矫正"<<global_data::update_allTable[id].set_senser_diff[0].humi_adjust;
//                            emit send_ChangeTable();
//                            qDebug()<<"数据查询成功"<<"信号发送";
//                        }

//                    }
//               sleep(200);
//            }
//     }

//        return true;
//    }
//    return false;
//}

bool mysql::GetMode()
{
    //接收标志位
    QString sql;
    //static int pre[DEV] = {0};
    //qDebug()<<"表格数据获取";
    //QString area = QString(global_data::id[0]).left(10);
    QSqlQuery  query(db);

    for( uint8_t i = 0 ; i < DEV ; i++ ){

        sql = QString(R"( SELECT * FROM `update_all_table` WHERE id = '%1' )")
                .arg(QString(global_data::id[i]));

        if(query.exec(sql)){
            while (query.next()){

                    uint8_t id = i; //query.value(1).toString().right(3).toInt() - 1;
                    if( global_data::Mode_Lock[id] == Write_Unlock ){
                            if( query.value("run_way_from_mcu_status").toInt() == 1){
                                    global_data::Mode_Lock[id] = Write_lock;
                                    bool ok;
                                    WORK_WAY_TYEP work_Contrl_mode;
                                    qDebug()<<"query.value(10).toString()"
                                           <<query.value("run_way_from_mcu").toString()
                                            << query.value("run_way_from_mcu_status").toInt();
                                    QByteArray data =HexStringToByteArray(ByteArrayToHexString(query.value("run_way_from_mcu").toString()), &ok);
                                    char *rcv = data.data();
                                    uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
                                    uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);

                                    if( GET_DEV_STATUS_HEAD == head && GET_DEV_STATUS_TAIL == tail){
                                        memcpy((char *)&work_Contrl_mode,rcv,sizeof(WORK_WAY_TYEP));
                                        //qDebug()<<"表数据----------";
                                        uint16_t crc = CRC16_2_modbus((uint8_t*)&work_Contrl_mode,sizeof(WORK_WAY_TYEP)-2);
                                        if( work_Contrl_mode.crc == crc ){
                                                global_data::control_Mode[id] = work_Contrl_mode.work_status;
                                                //发送模式更改信号
                                                room = id;
                                                emit send_ModeChange();
                                        }
                                }
                                 else{
                                        global_data::work_way[id].work_status = global_data::control_Mode[id];
                                        WORKwayToDB(global_data::work_way[id],"0");
                                }
                                global_data::Mode_Lock[id] = Write_lock;
                                 Mode_Clear(query.value("id").toString());
                                 return true;
                        }

                    }


                    bool ok;
                    WORK_WAY_TYEP work_Contrl_mode;;
                    QByteArray data =HexStringToByteArray(ByteArrayToHexString(query.value("run_way_to_mcu").toString()), &ok);


                    char *rcv = data.data();
                    uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
                    uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);
                    //qDebug()<<"head"<<head<<"tail"<<tail;
                    if( GET_DEV_STATUS_HEAD == head && GET_DEV_STATUS_TAIL == tail){
                        memcpy((char *)&work_Contrl_mode,rcv,sizeof(WORK_WAY_TYEP));
                        //qDebug()<<"表数据----------";

                        uint16_t crc = CRC16_2_modbus((uint8_t*)&work_Contrl_mode,sizeof(WORK_WAY_TYEP)-2);
                        if( work_Contrl_mode.crc == crc ){
                               // uint8_t tempasd = global_data::control_Mode[id];
                                if( global_data::control_Mode[id] != work_Contrl_mode.work_status ){


                                    if( global_data::Mode_Lock[id] != Write_Unlock ){
                                        if( global_data::Mutual_exclusion[id] == __485_Serial ){
                                            qDebug()<<"出错了.............................0";
                                            work_Contrl_mode.work_status = global_data::control_Mode[id];
                                            WORKwayToDB(global_data::work_way[id],"1");
                                            global_data::Mode_Lock[id] = Write_Unlock;
                                        }
                                        else{
                                            global_data::control_Mode[id] = work_Contrl_mode.work_status;
                                            //信号发送，改变
                                            room = id;
                                            //重新判断运行的阶段，不发表
                                            emit send_ModeChange();
                                        }

                                    }
                                    else
                                    {
                                        global_data::Mode_Lock[id] = Write_Unlock;
                                    }
                                }

                        }
                }
         }

        }
    }
    return false;
}

bool mysql::GetMode(QString device)
{
    //接收标志位
    static bool rcv_flag[DEV] = {false};

    QString sql;

    //qDebug()<<"表格数据获取";

    QSqlQuery  query(db);
    sql = QString(R"( SELECT * FROM `update_all_table` WHERE id = '%1' )")
            .arg(device);

    if(query.exec(sql)){
        while (query.next()){

                uint8_t id = query.value(1).toString().right(3).toInt() - 1;

                if( global_data::Mode_Lock[id] == Write_Unlock ){
                        if( query.value(11).toInt() ){
                            if( rcv_flag[id] == false){
                                bool ok;
                                WORK_WAY_TYEP work_Contrl_mode;
                                qDebug()<<"query.value(10).toString()"
                                       <<query.value(10).toString();
                                QByteArray data =HexStringToByteArray(ByteArrayToHexString(query.value(10).toString()), &ok);
                                char *rcv = data.data();
                                uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
                                uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);

                                if( GET_DEV_STATUS_HEAD == head && GET_DEV_STATUS_TAIL == tail){
                                    memcpy((char *)&work_Contrl_mode,rcv,sizeof(WORK_WAY_TYEP));
                                    //qDebug()<<"表数据----------";
                                    uint16_t crc = CRC16_2_modbus((uint8_t*)&work_Contrl_mode,sizeof(WORK_WAY_TYEP)-2);
                                    if( work_Contrl_mode.crc == crc ){
                                            global_data::control_Mode[id] = work_Contrl_mode.work_status;
                                            global_data::work_way[id].reasure_count = work_Contrl_mode.reasure_count;
                                            //发送模式更改信号
                                            room = id;
                                            emit send_ModeChange();
                                    }
                                    else{
                                        //global_data::work_way[id].work_status = global_data::control_Mode[id];
                                        //WORKwayToDB(global_data::work_way[id],"0");
                                    }
                            }
                             else{
                                    global_data::work_way[id].work_status = global_data::control_Mode[id];
                                    WORKwayToDB(global_data::work_way[id],"0");
                            }
                        }
                           // global_data::Mode_Lock[id] = Write_lock;
                            Mode_Clear(query.value(1).toString());
                    }
                }
                else{
                    rcv_flag[id] = false;
                }


                bool ok;
                WORK_WAY_TYEP work_Contrl_mode;;
                QByteArray data =HexStringToByteArray(ByteArrayToHexString(query.value(8).toString()), &ok);


                char *rcv = data.data();
                uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
                uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);
                //qDebug()<<"head"<<head<<"tail"<<tail;
                if( GET_DEV_STATUS_HEAD == head && GET_DEV_STATUS_TAIL == tail){
                    memcpy((char *)&work_Contrl_mode,rcv,sizeof(WORK_WAY_TYEP));
                    //qDebug()<<"表数据----------";
                    uint16_t crc = CRC16_2_modbus((uint8_t*)&work_Contrl_mode,sizeof(WORK_WAY_TYEP)-2);
                    if( work_Contrl_mode.crc == crc ){
                            if( global_data::control_Mode[id] != work_Contrl_mode.work_status ){
                                if( global_data::Mode_Lock[id] != Write_Unlock ){
                                    if( global_data::Mutual_exclusion[id] == __485_Serial ){
                                        work_Contrl_mode.work_status = global_data::control_Mode[id];
                                        global_data::work_way[id].reasure_count = work_Contrl_mode.reasure_count;
                                        WORKwayToDB(global_data::work_way[id],"1");
                                        global_data::Mode_Lock[id] = Write_Unlock;
                                    }
                                    else{
                                        global_data::control_Mode[id] = work_Contrl_mode.work_status;
                                        //信号发送，改变
                                        room = id;

                                        //重新判断运行的阶段，不发表
                                        emit send_ModeChange();
                                    }

                                }
                            }

                    }
            }
                        return true;
     }

    }
    return false;
}

bool mysql::GetTable(QString id)
{
    //接收标志位
        static bool rcv_flag[DEV] = {false};
        static uint16_t pre_crc[DEV] = {0};
//        static uint8_t Count[DEV] = {0};
        QString sql;

        //qDebug()<<"表格数据获取";

        QSqlQuery  query(db);

        sql = QString(R"( SELECT * FROM `update_all_table` WHERE id = '%1' )").arg(id);
        if(query.exec(sql)){
            while (query.next()) {
                    int id  = -1 ; //= query.value(1).toString().right(3).toInt() - 1;
                    for( uint8_t i = 0 ; i < DEV ; i++ ){
                        if( !QString::compare(query.value("id").toString(), (global_data::id[i])) ){
                            id = i;
                            break;
                        }
                    }

                    if( id < 0 )
                        return false;

                    uint8_t temp = 0;
                    if( query.value("pc_change_status").toString() == "1"){
                        if( !rcv_flag[id] ){
                            rcv_flag[id] = true;
                        }
                        else{
                            Dev_Clear(query.value("id").toString());
                            rcv_flag[id] = false;
                        }
                        temp = 4;
                    }
                    else{
                        rcv_flag[id] = false;
                    }


                    if( query.value("dev_change_status").toInt()){
                        Screen_update(query.value("id").toString());
                    }

                   // qDebug()<<"设备状态清零"<<Dev_Clear(query.value(1).toString());
                    bool ok;
                    UPDATE_ALL_TABLE_TYPEDEF From_DB_table;
                    QByteArray data =HexStringToByteArray(ByteArrayToHexString(query.value("table_values").toString()), &ok);



                    char *rcv = data.data();
                    uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
                    uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);
                    //qDebug()<<"head"<<head<<"tail"<<tail;
                    if( TABLE_HEAD == head && TABLE_TAIL == tail){
                        memcpy((char *)&From_DB_table,rcv,sizeof(UPDATE_ALL_TABLE_TYPEDEF));
                        //qDebug()<<"表数据----------";
                        uint16_t crc = CRC16_2_modbus((uint8_t*)&From_DB_table,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);
                        if( From_DB_table.crc == crc ){
                            if( global_data::Send_onine_flag[id] == true ){


                                room = id + temp;

                               qDebug()<<"温度矫正"<<global_data::update_allTable[id].set_senser_diff[0].temp_adjust
                                      <<"湿度矫正"<<global_data::update_allTable[id].set_senser_diff[0].humi_adjust;




                               global_data::update_allTable[id] = From_DB_table;
//                               Count[id]++;
//                               if( Count[id] >= Parameters_Udate_Times ){
//                                   Count[id] = 0;
//                                   pre_crc[id] = 0;
//                               }

                               if( pre_crc[id] != global_data::update_allTable[id].crc ||
                                       global_data::execute_date[id].sta_date != query.value("sta_date").toString() ||
                                       global_data::execute_date[id].end_date != query.value("end_date").toString()){

                                    global_data::execute_date[id].run_stage = query.value("run_stage").toInt();
                                    global_data::execute_date[id].sta_date = query.value("sta_date").toString();
                                    global_data::execute_date[id].end_date = query.value("end_date").toString();

                                   emit send_ChangeTable();

                                   pre_crc[id] = global_data::update_allTable[id].crc;

                               }

                               qDebug()<<"数据查询成功"<<"信号发送";
                            }

                        }

                }
         }

            return true;
        }

        return false;
}


bool mysql::Updata_All()
{
    bool result;
    QString sql = QString("UPDATE `update_all_table` SET dev_change_status= 1");

    QSqlQuery  query(db);
    result = query.exec(sql);

    qDebug()<<"获取数据库参数"<<result;
    return result;
}

bool mysql::Screen_update(QString name)
{
    QSqlQuery query(db);
    bool status = false;
    uint time  = QDateTime::currentDateTime().toTime_t();
    QString sql = QString("UPDATE `update_all_table` set dev_change_status = 0,update_time = '%1' "
                          " WHERE id='%2' ").arg(QString::number(time),name);
    status = query.exec(sql);
    return status;
}

bool mysql::Dev_Clear(QString name)
{
    QSqlQuery query(db);
    QString sql = QString("UPDATE `update_all_table` set pc_change_status = 0"
                          " WHERE id='%1' ").arg(name);
    return query.exec(sql);
}

bool mysql::Mode_Clear(QString name)
{
    QSqlQuery query(db);
    QString sql = QString("UPDATE `update_all_table` set run_way_from_mcu = %1,run_way_from_mcu_status = %2 "
                          " WHERE id='%3' ").arg("0","0",name);
    return query.exec(sql);
    return true;
}

bool mysql::addUser(QString name, QString passwd)
{
    QSqlQuery query(db);
    //在数据库插入空行
    QString sql = QString ("insert into toapp(user,password) values('%1','%2') ").arg(name,passwd);
    return query.exec(sql);
}

bool mysql::User_data_lookup(QTableWidget *table)
{
    QString sql = QString(" SELECT *from `toapp` ");
    uint8_t coulmn = table->rowCount();
    QSqlQuery  query(db);
    if(query.exec(sql)){
        while (query.next()) {
            table->insertRow(coulmn);
            qDebug()<<query.value(0).toString();
            table->setItem(coulmn,0,new QTableWidgetItem(QString::number(coulmn+1)));
            table->setItem(coulmn,1,new QTableWidgetItem(query.value(1).toString()));
            table->setItem(coulmn++,2,new QTableWidgetItem(query.value(2).toString()));
        }
        return true;
     }
    return false;
}

bool mysql::del_user(QString name)
{
    QSqlQuery query(db);
    //在数据库插入空行
    QString sql = QString ("DELETE FROM `toapp` WHERE user = '%1' ").arg(name);
    return query.exec(sql);
}

uint mysql::Get_Update_Time()
{
    int max_time = 0;
    QSqlQuery query(db);
    //QString name = QString(global_data::id[0]).left(10);
    //在数据库插入空行

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        QString sql = QString ("SELECT update_time FROM `update_all_table` WHERE id = '%1' ").arg(QString(global_data::id[i]));
        if(query.exec(sql)){
            while (query.next()) {
                if( max_time < query.value(0).toInt()){
                    max_time = query.value(0).toInt();
                    break;
                }
            }
        }

    }

    if( max_time >= 0 )
        return max_time;
    return 0;
}

QByteArray mysql::HexStringToByteArray(QString hex, bool *ok)
{
    int p;

       QByteArray ret;
       QStringList lst = hex.simplified().split(' ');//转化为字符串数组
       ret.resize(lst.count());
       for(int i = 0; i < lst.count(); i++)
       {
           p = lst[i].toInt(ok, 16);
           if(!(*ok) || p > 255 )
           {
               return 0;
           }
           ret[i] = p;
       }
       return ret;
}

QString mysql::ByteArrayToHexString(QString data)
{
    QString ret = data.toUpper();//data.toHex().toUpper());
    int len = ret.length()/2;
    //qDebug()<<data<<len;
    for(int i=1;i<len;i++)
    {
        //qDebug()<<i;
        ret.insert(2*i+i-1," ");
    }

        return ret;
}

QByteArray mysql::Convert_struct(const char *data, qint64 len)
{
    QByteArray result;
    for( qint64 i = 0 ; i < len ; i++ ){
        result.append(data[i]);
    }

    return result;
}

void mysql::Change_Save(uint8_t id)
{
    QDateTime dTime = QDateTime::currentDateTime();
    QString date = dTime.toString("/yyyy-MM-dd");
    QString pTime = dTime.toString("hh:mm:ss");

    global_data::update_allTable[id].crc = CRC16_2_modbus((uint8_t*)&global_data::update_allTable[id],sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);
    QByteArray table_values = Convert_struct((char*)&global_data::update_allTable[id],sizeof(UPDATE_ALL_TABLE_TYPEDEF));
    QFile file(RecordFILE+ date + ".txt");//此路径下没有就会自己创建一个

    while(!file.open(QIODevice::ReadWrite | QIODevice::Append));//以读写切追加写入的方式操作文本
    QTextStream txtOutput(&file);

    txtOutput <<table_values.toHex()<<"/"<<getMacAddress()<<"/"<<pTime<<"\r\n";

    file.close();
}

QString mysql::getMacAddress()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    int nCnt = nets.count();
    QString strMacAddr = "";
    for(int i = 0; i < nCnt; i ++)
    {
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    return strMacAddr;
}
