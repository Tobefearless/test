#include "pub.h"
#include <QCoreApplication>
#include <QEventLoop>
#include <QSettings>
#include <QElapsedTimer>


bool global_data::update_flag = 0;
bool global_data::rcv_ok = false;
bool global_data::Hear_flag = 0;
bool global_data::mqtt_status = false;

char global_data::id[DEV][20] = {""};

EXECUTE_DATE_Typedef global_data::execute_date[DEV] = {{"","",-1}};
bool global_data::Mode_Lock[DEV] = {Write_lock};


bool global_data::room_flag[DEV] = {true};
bool global_data::Send_onine_flag[DEV] = {true};

bool global_data::Mutual_exclusion[DEV] ={DataBase};

QSerialPort *serial = new QSerialPort();
QMqttClient *mG_client =new QMqttClient();

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
UPDATE_ALL_TABLE_TYPEDEF global_data::update_allTable[DEV]
= {{TABLE_HEAD,"",{0,0},{0,0},{0,0},{0,0,0,0},{0,0},{0,0},0,TABLE_TAIL,0}};

WORK_WAY_TYEP global_data::work_way[DEV]
= {{GET_DEV_STATUS_HEAD,"",0,0,GET_DEV_STATUS_TAIL,0}};

QColor global_data::date_Color       = QColor(255,0,0);
QColor global_data::day_Color        = QColor(255,192,0);
QColor global_data::temp_Color       = QColor(255,255,0);
QColor global_data::humi_Color       = QColor(146,208,80);
QColor global_data::breath_Color     = QColor(0,176,80);
QColor global_data::sensitive_Color  = QColor(0,176,240);
QColor global_data::disinfect_Color  = QColor(0,112,192);
QColor global_data::illumina_Color   = QColor(251,101,28);
const uint16_t g_McRctable_16[256] =
  {
  0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
  0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
  0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
  0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
  0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
  0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
  0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
  0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
  0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
  0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
  0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
  0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
  0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
  0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
  0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
  0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
  0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
  0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
  0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
  0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
  0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
  0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
  0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
  0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
  0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
  0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
  0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
  0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
  0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
  0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
  0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
  0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
  };
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

int Mqtt_publish(int id, UPDATE_ALL_TABLE_TYPEDEF content)
{
    content.crc = CRC16_2_modbus((uint8_t*)&content,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);
    QString topicPub = Send_Topic + QString(global_data::id[0]);
    qDebug()<<id;

    if( mG_client->state() == QMqttClient::Connected ){
        QByteArray byteArray;

        byteArray.append(( char *)&content,sizeof(content));
        mG_client->publish(topicPub,byteArray);
        topicPub = "dev/send/" + QString(global_data::id[0]);
        mG_client->publish(topicPub,byteArray);
        return true;
    }
    return false;
}

int Mqtt_publish(int id, WORK_WAY_TYEP content)
{
    content.crc = CRC16_2_modbus((uint8_t*)&content,sizeof(WORK_WAY_TYEP)-2);
    QString topicPub = Send_Topic + QString(global_data::id[0]);
    qDebug()<<id;

    if( mG_client->state() == QMqttClient::Connected ){
        QByteArray byteArray;

        byteArray.append(( char *)&content,sizeof(content));
        mG_client->publish(topicPub,byteArray);
        topicPub = "dev/send/" + QString(global_data::id[0]);
        mG_client->publish(topicPub,byteArray);
        return true;
    }
    return false;
}

int Mqtt_publish(int id)
{
    QString topicPub =QString(global_data::id[0]);
    qDebug()<<id;

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
