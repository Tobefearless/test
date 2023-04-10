#include "pub.h"
#include <QCoreApplication>
#include <QEventLoop>
#include <QSettings>
#include <QElapsedTimer>

#if DEV==4
char global_data::id[DEV][20] = {"LSSF210601001","LSSF210601002","LSSF210601003"
                              ,"LSSF210601004"};
#elif DEV==3
char global_data::id[DEV][20] = {"LSSF210601001","LSSF210601002","LSSF210601003"};
#elif DEV==2
char global_data::id[DEV][20] = {"SXZC220801001","SXZC220801002"};
#elif DEV==11
char global_data::id[DEV][20] = {"LSSF210601001","LSSF210601002"
                                ,"LSSF210601003","LSSF210601004"
                                ,"LSSF210601005","LSSF210601006"
                                ,"LSSF210601007","LSSF210601008"
                                ,"LSSF210601009","LSSF210601010"
                                ,"LSSF210601011"};
#elif DEV==1
char global_data::id[DEV][20] = {"SCDT210510001"};
#endif

bool global_data::update_flag = 0;
bool global_data::rcv_ok = false;
bool global_data::Hear_flag = 0;
bool global_data::mqtt_status = false;
bool global_data::temp_flag = false;

EXECUTE_DATE_Typedef global_data::execute_date[DEV];
bool global_data::Mode_Lock[DEV];


bool global_data::room_flag[DEV];
bool global_data::Send_onine_flag[DEV] ;

uint8_t global_data::Mutual_exclusion[DEV];

QMqttClient *mG_client =new QMqttClient();
QSerialPort *serial = new QSerialPort();

bool global_data::update_RoomFlag[DEV] = {0};
//心跳包计数（包括串口和数据库）
uint8_t global_data::heart_beat_count[DEV] = {0};
//房间工作的模式
uint8_t global_data::control_Mode[DEV] = {0};
//电脑是否联网
bool global_data::on_line = false;

bool global_data::mode_rcv_flag = false;

bool global_data::Default_flag = false;

//软件启动的天数
QDate global_data::sensor_Date = QDate::fromString("1999-01-01","yyyy-MM-dd");

//更新的参数表
UPDATE_ALL_TABLE_TYPEDEF global_data::update_allTable[DEV];/*
= {{TABLE_HEAD,"",{0,0},{0,0},{0,0},{0,0,0,0},{0,0},{0,0},0,TABLE_TAIL,0},
    {TABLE_HEAD,"",{0,0},{0,0},{0,0},{0,0,0,0},{0,0},{0,0},0,TABLE_TAIL,0},
  {TABLE_HEAD,"",{0,0},{0,0},{0,0},{0,0,0,0},{0,0},{0,0},0,TABLE_TAIL,0},
  {TABLE_HEAD,"",{0,0},{0,0},{0,0},{0,0,0,0},{0,0},{0,0},0,TABLE_TAIL,0}};
*/

WORK_WAY_TYEP global_data::work_way[DEV];/*
= {{GET_DEV_STATUS_HEAD,"",0,0,GET_DEV_STATUS_TAIL,0},
   {GET_DEV_STATUS_HEAD,"",0,0,GET_DEV_STATUS_TAIL,0},
   {GET_DEV_STATUS_HEAD,"",0,0,GET_DEV_STATUS_TAIL,0},
   {GET_DEV_STATUS_HEAD,"",0,0,GET_DEV_STATUS_TAIL,0}};
*/
QColor global_data::date_Color       = QColor(255,0,0);
QColor global_data::day_Color        = QColor(255,192,0);
QColor global_data::temp_Color       = QColor(255,255,0);
QColor global_data::humi_Color       = QColor(146,208,80);
QColor global_data::breath_Color     = QColor(0,176,80);
QColor global_data::sensitive_Color  = QColor(0,176,240);
QColor global_data::disinfect_Color  = QColor(0,112,192);
QColor global_data::illumina_Color   = QColor(251,101,28);


SENSOR_JUST_TYPE global_data::sensor_just_data[DEV] = {{0,0,0,0}};
//uint16_t GetRevCrc_16(uint8_t *pData, int nLength)
//{
//    uint16_t cRc_16 = 0xffff;
//    uint8_t temp;

//      while(nLength-- > 0)
//      {
//        temp = cRc_16 & 0xFF;
//        cRc_16 = (cRc_16 >> 8) ^ g_McRctable_16[(temp ^ *pData++) & 0xFF];
//      }

//      return cRc_16;
//}

uint16_t CRC16_2_modbus(unsigned char *buf, int len)
{
    unsigned int crc = 0xFFFF;
    for (int pos = 0; pos < len; pos++)
    {
        crc ^= (unsigned int)buf[pos];
        for (int i = 8; i != 0; i--)
        {
            if ((crc & 0x0001) != 0)
            {
                crc >>= 1;
                crc ^= 0xA001;
            }
            else // Else LSB is not set
            {
                crc >>= 1;
            }
        }
    }

    //crc = ((crc & 0x00ff) << 8) | ((crc & 0xff00) >> 8);
    return crc;
}


void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Delay_MSec_Suspend(unsigned int msec)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<msec);

}


bool update_All_table(UPDATE_ALL_TABLE_TYPEDEF data)
{
    uint8_t time_out = 0;
    serial->flush();
    data.crc = CRC16_2_modbus((uint8_t*)&data,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);
    serial->write( ( char *)&data,sizeof( UPDATE_ALL_TABLE_TYPEDEF));
    global_data::rcv_ok = false;
    while( global_data::rcv_ok == false ){
        sleep(100);
        if( time_out++ > 10 )
            return false;
    }
    return true;
}



bool Write_Work_Way(WORK_WAY_TYEP data)
{
    uint8_t time_out = 0;
    serial->flush();
    data.crc = CRC16_2_modbus((uint8_t*)&data,sizeof(WORK_WAY_TYEP)-2);
    serial->write( ( char *)&data,sizeof( WORK_WAY_TYEP));

    global_data::mode_rcv_flag = false;
    while( global_data::mode_rcv_flag == false ){
        sleep(100);
        if( time_out++ > 10 )
            return false;
    }
    return true;
}

void Mode_Save(uint8_t id)
{
    QSettings *settings = new QSettings(QString(FILENAME )+"/config.ini", QSettings::IniFormat);
    settings->setValue("Mode/Device" + QString::number(id + 1),global_data::control_Mode[id]);
    delete settings;
}

int ID_lookup(QString id)
{
    int room = -1;

    QStringList list;
    list << "SXZC220808001"<<"SXZC220808002";
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( id.contains(QString(global_data::id[i]))){
            room = i;
        }
    }

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( id.contains( list.at(i))){
            room = i;
        }
    }

    return room;
}


int Mqtt_publish(int id,UPDATE_ALL_TABLE_TYPEDEF content)
{
    content.crc = CRC16_2_modbus((uint8_t*)&content,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);
    QString topicPub = Send_Topic + QString(global_data::id[id]);


    if( mG_client->state() == QMqttClient::Connected ){
        QByteArray byteArray;

        byteArray.append(( char *)&content,sizeof(content));
        mG_client->publish(topicPub,byteArray);
        //sleep(1);
        topicPub = "dev/send/" + QString(global_data::id[id]);
        mG_client->publish(topicPub,byteArray);
        return true;
    }
    return false;
}

int Mqtt_publish(int id, WORK_WAY_TYEP content)
{
    content.crc = CRC16_2_modbus((uint8_t*)&content,sizeof(WORK_WAY_TYEP)-2);
    QString topicPub = Send_Topic + QString(global_data::id[id]);

    qDebug()<<topicPub;

    if( mG_client->state() == QMqttClient::Connected ){
        QByteArray byteArray;

        byteArray.append(( char *)&content,sizeof(content));
        mG_client->publish(topicPub,byteArray);
        topicPub = "dev/send/" + QString(global_data::id[id]);

        mG_client->publish(topicPub,byteArray);
        return true;
    }
    return false;
}

int Mqtt_publish(int id)
{

    QString topicPub =QString(global_data::id[id]);


    if( mG_client->state() == QMqttClient::Connected ){
        QByteArray byteArray;

        byteArray.append(( char *)&global_data::work_way[0],sizeof(global_data::work_way[0]));
        mG_client->publish(topicPub,byteArray);

        return true;
    }
    return false;
}

void initHeadFrame(QTableWidget *tableWiegt,QString tableName)
{

    tableWiegt->setEnabled(false);
    tableWiegt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度

    //ui->tableWidget->setStyleSheet("QTableWidget::item{border:1px solid ;}");
   // ui->tableWidget->horizontalHeader()->setVisible(false);//表头不可见
    //ui->tableWidget->verticalHeader()->setVisible(false);//表头不可见
    //ui->tableWidget->setShowGrid(false);//网格线不可见
    tableWiegt->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置单元格不可编辑
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);//最后一个单元格扩展
    tableWiegt->setFocusPolicy(Qt::NoFocus);//解决选中虚框问题
    tableWiegt->setFrameShape(QFrame::NoFrame);//去除边框 尴尬
    tableWiegt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏滚动条
    tableWiegt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//

    tableWiegt->setColumnCount(41);//header10列
    tableWiegt->setRowCount(3);//header2行

    tableWiegt->setRowHeight(0, 20);//第一行设置高度20px
    tableWiegt->setRowHeight(1, 20);//第二行设置高度20px
    tableWiegt->setRowHeight(2, 75);//第二行设置高度75px

//        tableWiegt->setRowHeight(0, 20);//第一行设置高度20px
//        tableWiegt->setRowHeight(1, 20);//第二行设置高度20px
//        tableWiegt->setRowHeight(2, 40);//第二行设置高度75px
//    for (int row = 2; row < tableWiegt->rowCount(); ++row)//隐藏2行后的行
//              tableWiegt->setRowHidden(row, true);

    tableWiegt->setSpan(0, 0, 2, 2);//共育时间
    tableWiegt->setSpan(0, 2, 3, 1);//天数
    tableWiegt->setSpan(0, 3, 3, 1);//温度设置
    tableWiegt->setSpan(0, 4, 3, 1);//湿度设置

    tableWiegt->setSpan(0, 5, 1, 16);//换气

    tableWiegt->setSpan(0, 21, 1, 6);//感光

    tableWiegt->setSpan(0, 27, 1, 8);//消毒

    tableWiegt->setSpan(0, 35, 1, 6);//光照

    /******************第二行**************************/
//     ui->tableWidget->setSpan(1,0 , 2, 1);//开始
//     ui->tableWidget->setSpan(1,1 , 2, 1);//结束

     uint8_t i = 0;
     QStringList list ;
     list<<"第一次"<<"第二次"<<"第三次"<<"第四次"<<"第五次"<<
           "第六次"<<"第七次"<<"第八次";
     for( i  = 5 ; i < 2*8+5 ; i+=2 ){
         ///换气
         tableWiegt->setSpan(1,i,1,2);
         tableWiegt->setItem(1, i, new QTableWidgetItem(list.at((i-5)/2)));
         tableWiegt->item(1,i)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(1, i)->setBackground(global_data::breath_Color);
         tableWiegt->item(1, i)->setTextColor(Qt::black);

         ///换气开始与结束
         tableWiegt->setItem(2, i, new QTableWidgetItem("开始时间"));
         tableWiegt->item(2,i)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(2, i)->setBackground(global_data::breath_Color);

         tableWiegt->setItem(2, i+1, new QTableWidgetItem("运行时间(分)"));
         tableWiegt->item(2,i+1)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(2, i+1)->setBackground(global_data::breath_Color);

         tableWiegt->item(2, i)->setTextColor(Qt::black);
         tableWiegt->item(2, i+1)->setTextColor(Qt::black);
     }

     //感光
     uint8_t j = i;
     for( ; i < 2*3+j ; i+=2 ){
         ///感光
         tableWiegt->setSpan(1,i,1,2);
         tableWiegt->setItem(1, i, new QTableWidgetItem(list.at((i-j)/2)));
         tableWiegt->item(1,i)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(1, i)->setBackground(global_data::sensitive_Color);
         tableWiegt->item(1, i)->setTextColor(Qt::black);


         ///感光开始与结束
         tableWiegt->setItem(2, i, new QTableWidgetItem("开始时间"));
         tableWiegt->item(2,i)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(2, i)->setBackground(global_data::sensitive_Color);

         tableWiegt->setItem(2, i+1, new QTableWidgetItem("结束时间"));
         tableWiegt->item(2,i+1)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(2, i+1)->setBackground(global_data::sensitive_Color);

         tableWiegt->item(2, i)->setTextColor(Qt::black);
         tableWiegt->item(2, i+1)->setTextColor(Qt::black);


     }

     //消毒
     j = i;
     for( ; i < 2*4+j ; i+=2 ){
         //消毒
         tableWiegt->setSpan(1,i,1,2);
         tableWiegt->setItem(1, i, new QTableWidgetItem(list.at((i-j)/2)));
         tableWiegt->item(1,i)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(1, i)->setBackground(global_data::disinfect_Color);
         tableWiegt->item(1, i)->setTextColor(Qt::black);


         //消毒开始与结束
         tableWiegt->setItem(2, i, new QTableWidgetItem("开始时间"));
         tableWiegt->item(2,i)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(2, i)->setBackground(global_data::disinfect_Color);

         tableWiegt->setItem(2, i+1, new QTableWidgetItem("运行时间(分)"));
         tableWiegt->item(2,i+1)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(2, i+1)->setBackground(global_data::disinfect_Color);

         tableWiegt->item(2, i)->setTextColor(Qt::black);
         tableWiegt->item(2, i+1)->setTextColor(Qt::black);
     }

     //光照
     j = i;
     for( ; i < 2*3+j ; i+=2 ){
         ///光照
         tableWiegt->setSpan(1,i,1,2);
         tableWiegt->setItem(1, i, new QTableWidgetItem(list.at((i-j)/2)));
         tableWiegt->item(1,i)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(1, i)->setBackground(global_data::illumina_Color);
         tableWiegt->item(1, i)->setTextColor(Qt::black);

         ///光照开始与结束
         tableWiegt->setItem(2, i, new QTableWidgetItem("开始时间"));
         tableWiegt->item(2,i)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(2, i)->setBackground(global_data::illumina_Color);

         tableWiegt->setItem(2, i+1, new QTableWidgetItem("结束时间"));
         tableWiegt->item(2,i+1)->setTextAlignment(Qt::AlignCenter);
         tableWiegt->item(2, i+1)->setBackground(global_data::illumina_Color);

         tableWiegt->item(2, i)->setTextColor(Qt::black);
         tableWiegt->item(2, i+1)->setTextColor(Qt::black);
     }

    //ui->tableWidget->setEnabled(false);

    tableWiegt->setItem(0, 0, new QTableWidgetItem(tableName));
    tableWiegt->item(0, 0)->setBackground(global_data::date_Color);
    tableWiegt->item(0,0)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(0, 0)->setTextColor(Qt::black);

    tableWiegt->setItem(0, 2, new QTableWidgetItem("天数"));
    tableWiegt->item(0, 2)->setBackground(global_data::day_Color);
    tableWiegt->item(0, 2)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(0, 2)->setTextColor(Qt::black);

    tableWiegt->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    tableWiegt->setItem(0, 3, new QTableWidgetItem("温度设置(℃)"));
    tableWiegt->item(0, 3)->setBackground(global_data::temp_Color);
    tableWiegt->item(0, 3)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(0, 3)->setTextColor(Qt::black);
//    ui->tableWidget->setColumnWidth(3,40);
//    ui->tableWidget->setColumnWidth(4,40);



    tableWiegt->setItem(0, 4, new QTableWidgetItem("湿度设置(%)"));
    tableWiegt->item(0, 4)->setBackground(global_data::humi_Color);
    tableWiegt->item(0, 4)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(0, 4)->setTextColor(Qt::black);

    tableWiegt->setItem(0, 5, new QTableWidgetItem("换气"));
    tableWiegt->item(0, 5)->setBackground(global_data::breath_Color);
    tableWiegt->item(0, 5)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(0, 5)->setTextColor(Qt::black);


    tableWiegt->setItem(0, 21, new QTableWidgetItem("感光"));
    tableWiegt->item(0, 21)->setBackground(global_data::sensitive_Color);
    tableWiegt->item(0, 21)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(0, 21)->setTextColor(Qt::black);

    tableWiegt->setItem(0, 27, new QTableWidgetItem("消毒"));
    tableWiegt->item(0, 27)->setBackground(global_data::disinfect_Color);
    tableWiegt->item(0, 27)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(0, 27)->setTextColor(Qt::black);

    tableWiegt->setItem(0, 35, new QTableWidgetItem("光照"));
    tableWiegt->item(0, 35)->setBackground(global_data::illumina_Color);
    tableWiegt->item(0, 35)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(0, 35)->setTextColor(Qt::black);

    tableWiegt->setItem(2, 0, new QTableWidgetItem("开始"));
    tableWiegt->item(2,0)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(2, 0)->setBackground(global_data::date_Color);
    tableWiegt->item(2, 0)->setTextColor(Qt::black);

    tableWiegt->setItem(2, 1, new QTableWidgetItem("结束"));
    tableWiegt->item(2,1)->setTextAlignment(Qt::AlignCenter);
    tableWiegt->item(2, 1)->setBackground(global_data::date_Color);
    tableWiegt->item(2, 1)->setTextColor(Qt::black);

//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    //ui->tableWidget_2->setColumnWidth(2,100);
}
