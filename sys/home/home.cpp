  #include "home.h"
#include "ui_homer.h"
#include "QDesktopWidget"
#include <QSharedPointer>
#pragma GCC diagnostic ignored "-Wwrite-strings"
home::home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    qDebug()<<1;
    table_timer = new QTimer(this);
    Heart_timer = new QTimer(this);
    //h_timer.start(400, Qt::PreciseTimer, this);

    changeRoom = false;
//    //创建线程
    myT = new Mythread();

    thread = new QThread(this);

    myT->moveToThread(thread);

    ModeT =new Mythread() ;
    modeThread = new QThread(this);
    ModeT->moveToThread(modeThread);

    system_Setting = new System_Setting();
    data_report = new Data_report();
    sensor = new Sensor();
    user_management = new User_Management();

    for( uint8_t i = 0 ; i < DEV ; i++ ){
         Set_parment[i] = new set_parament1(i);
         seed[i] = new Seed(i);
         co_Parenting[i] = new Co_parenting(i);
    }

    charview = new Historical_curve();
    State_assignment();

    comms_indicate = new COMMS_indicate();


    //状态栏信息显示
    //状态栏信息显示
    QLabel  *Qlabel=new QLabel(this);
    communi = new QLabel(this);
    QString str = "                          四川省南充市桃园生物化学研究开发有限公司                                                                  联系电话：19938536220 19938535370  ";
    Qlabel->setStyleSheet(" color:#ffffff;font: bold 16px");
    Qlabel->setText(str);
    ui->statusBar->setStyleSheet(QString("QStatusBar::item{border: 0px; color:(255,255,255)}")); // 设置不显示label的边框
    ui->statusBar->addPermanentWidget(Qlabel);
    ui->statusBar->setSizeGripEnabled(false); //不显示右边的大小控制点

    communi->setText("串口未连接");
    communi->setStyleSheet(" color:#ffffff;font: bold 16px");
    ui->statusBar->addWidget(communi);


    this->setWindowTitle("催青管理系统");                 //设置窗口标题
    this->setWindowIcon(QIcon(":/img/登录主图.jpg"));        //设置窗口图片


//    //设置图片全屏显示且自动适应屏幕大小
    QRect screenSize;    //设备屏幕（设备分辨率）

    screenSize = QApplication::desktop()->screenGeometry();

    int dev_width = screenSize.width();    //屏幕宽
    int dev_height = screenSize.height();    //屏幕高

     setAutoFillBackground(true);
     QPixmap back_icon(":/img/Dark_Blue.png");
     QPalette palette;
     palette.setBrush(this->backgroundRole(),QBrush(back_icon.scaled(dev_width,dev_height).scaled(dev_width,dev_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

      //催青开始/结束
     //数据库更新表格参数
    connect(mG_client, &QMqttClient::messageReceived,this,&home::topicMessageReceived);
    connect(myT->DBT,SIGNAL(send_ChangeTable()),this,SLOT(Table_Change()));
     //窗口关闭事件
     //网络显示数据
     //connect(DaT,SIGNAL(Data_Signal(QVariant)),this,SLOT(timeUpdate(QVariant)));
     //房间模式发生改变
     connect(ModeT->DBT,&mysql::send_ModeChange,[=](){
         ModeChangeDeal(ModeT->DBT->room,0);
     });

     //把表更新到单片机的定时器
     connect(table_timer,SIGNAL(timeout()),this,SLOT(update_table_485()));
     //发送心跳包的定时器
     connect(Heart_timer,SIGNAL(timeout()),this,SLOT(Send_Heart()));

     //解开表格锁
     for( uint8_t i = 0 ; i < DEV ; i++ ){
         connect(Set_parment[i],SIGNAL(Table_UnCLOCK()),this,SLOT(table_unlock()));
         connect(seed[i],SIGNAL(Table_UnCLOCK()),this,SLOT(table_unlock()));
         connect(co_Parenting[i],SIGNAL(Table_UnCLOCK()),this,SLOT(table_unlock()));
     }

     connect(system_Setting,&System_Setting::Contral_adjust,[&](uint8_t room){
         ModeChangeDeal(room,0);
     });

     //启动线程
     connect(this,&home::startThread,myT,&Mythread::myTimeout);
     //connect(this,&home::startThread,DaT,&Mythread::FromDB_Data);
     connect(this,&home::startThread,ModeT,&Mythread::Pattern_query);
     //connect(this,&home::startThread,serialT,&SerialThread::Recive_data);
     connect(this,&home::destroyed,[=](){
         qDebug()<<"窗口关闭";

     });

     this->setPalette(palette);
      //stackWidget界面添加

      ui->stackedWidget->addWidget(system_Setting);
      ui->stackedWidget->addWidget(charview);
      ui->stackedWidget->addWidget(data_report);
      ui->stackedWidget->addWidget(sensor);
      ui->stackedWidget->addWidget(comms_indicate);
      ui->stackedWidget->addWidget(user_management);
      ui->stackedWidget->addWidget(&help);

      //时间
      ui->right_title->setText(QDate::currentDate().toString("yyyy-MM-dd"));

      //系统托盘初始化
      //System_tray();
      qDebug()<<"表结构体"<<sizeof(UPDATE_ALL_TABLE_TYPEDEF)
               <<"基本命令结构体"<<sizeof(FROM_MCU_Typedef)
              <<"WIFI结构体"<<sizeof(SEND_WIFI_DATA_Type)
             <<"时间结构体"<<sizeof(SEND_TIME_TAMP_Type)
            <<"工作状态结构体"<<sizeof(WORK_WAY_TYEP);


}

home::~home()
{
    if( thread->isRunning() == true ){
        //myT->setflag(true);
        thread->requestInterruption();
        thread->quit();
        thread->wait();
    }

    if( modeThread->isRunning() == true ){
        //DaT->setflag(true);
        modeThread->requestInterruption();
        modeThread->quit();
        modeThread->wait();   
    }

    delete sensor;
    delete myT;
    delete ModeT;

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        delete Set_parment[i];
        delete seed[i] ;
        delete co_Parenting[i] ;
    }

    delete system_Setting;
    delete data_report;
    delete user_management;
    delete charview ;
    delete comms_indicate;
    delete serial;
    delete ui;
}

bool home::create_connect()
{
    if(mG_client->state() == QMqttClient::Disconnected){
        //mG_client->setClientId("12345678");
        mG_client->setHostname("1.14.26.239");
        //m_client->setHostname("47.96.154.99");

        mG_client->setPort(1883);
        mG_client->setUsername("admin");
        mG_client->setPassword("czy123456");
        mG_client->setWillQoS(1);

        //重新收到离线期间错过的消息的设备
        mG_client->setCleanSession(false);
       // mG_client->setKeepAlive(10000);
        mG_client->setKeepAlive(30);
        mG_client->setAutoKeepAlive(true);
        mG_client->autoKeepAliveChanged(true);
//        //设置自动保持连接
//        mG_client->setAutoKeepAlive(true);

        mG_client->connectToHost();
        global_data::mqtt_status = false;
        return false;
    }
    else{
        global_data::mqtt_status = true;
        return true;
        //mG_client->disconnectFromHost();
    }
}

bool home::mqtt_subscribe(uint8_t id)
{
    //QString topic = Recive_Topic + QString(global_data::id[id]);
    Q_UNUSED(id);
    QString topic = "dev/recive/#";
    qDebug()<<"订阅"<<topic<<"mqtt连接状态"<<mG_client->state();
    if(mG_client->state() == QMqttClient::Connected){
        qDebug()<<"连接asdasdasdasdasdasdasd";

        //程序
        QMqttSubscription *subscription = mG_client->subscribe(topic,2);
        qDebug()<<"订阅成功";
        if (!subscription) {
            QMessageBox::warning(NULL, "警告", "不能订阅，这是一个有效连接嘛？", "确定");
            return false;
        }
        return true;
    }
    return false;
}

void home::WriteTo_txt()
{
    qDebug()<<"正在写数据";
#if 1
    for( uint8_t i = 0 ; i < DEV ; i++ )
    {
        mkMutiDir(QDir::currentPath()+ "/room/" + QString(global_data::id[i]));
    }

    QDateTime current_date_time = QDateTime::currentDateTime();
//    current_date_time = current_date_time.addSecs(60);
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");;
    QString filename = current_date_time.toString("yyyy-MM-dd");
    filename = filename + ".txt";


    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( show_data[i].temp.toDouble() == 0 || show_data[i].humi.toDouble() == 0)
            continue;

        QFile file(QDir::currentPath()+ "/room/" + QString(global_data::id[i])+"/"+filename);//此路径下没有就会自己创建一个
        qDebug()<<"文件路径为"<<QDir::currentPath()+ "/room/" + QString(global_data::id[i])+"/"+filename;
        while(!file.open(QIODevice::ReadWrite | QIODevice::Append));//以读写切追加写入的方式操作文本
        QTextStream txtOutput(&file);

        txtOutput << (char*)&global_data::id[i] << "/" <<show_data[i].temp << "/"
                  <<show_data[i].humi<<"/"<<current_date<<"\n";

        file.close();
    }

    WriteTO_Sensor();
#endif
}

void home::WriteTO_Sensor()
{
    qDebug()<<"正在存储传感器数据";

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm");;
    QString date = current_date_time.toString("yyyy-MM-dd"),id;
    QString filename = QDir::currentPath() + "/sensor/";
    //创建文件夹

     mkMutiDir(QDir::currentPath() + "/sensor/");

    for( uint8_t i = 0 ; i < DEV ; i++ ){
         id = QString(show_data[i].id);
         QFile file(filename + id +" " +date +".txt");
         while(!file.open(QIODevice::ReadWrite | QIODevice::Append));//以读写切追加写入的方式操作文本
         QTextStream txtOutput(&file);

        for( uint8_t j = 0 ; j < 6 ; j++ ){
            //这里可以提前判断传感器的值是否符合要求
            //要确定是否创建文件和将数据写入文件
            if( show_data[i].signle_senser[j].senser_status != SENSER_DIS_CON &&
                    show_data[i].signle_senser[j].signle_temp != 0){
                    txtOutput <<id + "_" + QString::number(j+1)<<"/"<<(double)show_data[i].signle_senser[j].signle_temp/10<< "/"
                      <<(double)show_data[i].signle_senser[j].signle_humi/10<<"/"<<current_date<<"\n";
            }
        }
        file.close();

    }

}

QString home::mkMutiDir(const QString path)
{
    QDir dir(path);
    if ( dir.exists(path)){
        return path;
    }
    QString parentDir = mkMutiDir(path.mid(0,path.lastIndexOf('/')));
    QString dirname = path.mid(path.lastIndexOf('/') + 1);
    QDir parentPath(parentDir);
    if ( !dirname.isEmpty() )
        parentPath.mkpath(dirname);
    return parentDir + "/" + dirname;

}

void home::show_relay(QLabel *label, bool status)
{
       if(status){
          label->setStyleSheet("font-size:14pt; font-weight:600; color:#00ff00;");
          label->setText("开启");
       }else{
           label->setStyleSheet("font-size:14pt; font-weight:600; color:#ff0000;");
           label->setText("关闭");
       }
}

void home::show_air_relay(QLabel *label, uint8_t status)
{
    switch (status) {
    case AIR_CLOSE:
        label->setText("关闭");
        label->setStyleSheet("font-size:14pt; font-weight:600; color:#ff0000;");
        break;
    case AIR_HEAT:
        label->setText("制热");
        label->setStyleSheet("font-size:14pt; font-weight:600; color:#00ff00;");
        break;
    case AIR_COLD:
        label->setText("制冷");
        label->setStyleSheet("font-size:14pt; font-weight:600; color:#00ff00;");
        break;
    default:
        label->setText("关闭");
        label->setStyleSheet("font-size:14pt; font-weight:600; color:#ff0000;");
        break;
    }
}

void home::State_assignment()
{
        DEVICE_name[0] = ui->Device_Name1;
        for( uint8_t i = 0 ; i < DEV ; i++ ){
            DEVICE_name[i]->setText(QString().sprintf(R"(<html><head/><body><p><span style=" font-size:18pt; font-weight:600;">%s</span></p></body></html>)",global_data::id[i]));
            data_report->room_name->addItem(QString(global_data::id[i]));
            charview->Device->addItem(QString(global_data::id[i]));
            system_Setting->ui->Room_Choose->addItem(QString(global_data::id[i]));
        }

        system_Setting->ui->Room_Choose->setCurrentIndex(0);
        //心跳包赋值
        for( uint8_t i = 0; i < DEV ; i++ ){
             global_data::heart_beat_count[i] = 0;
             show_data[i].status = OFFLINE;
             global_data::room_flag[i] = true;

             //id赋值
             show_data[i].id = QString(global_data::id[i]);
             co_Parenting[i]->setEnabled(false);
             Set_parment[i]->setEnabled(false);
             seed[i]->setEnabled(false );
        }

        //上电，传感器默认断开
        for( uint8_t i = 0 ; i < DEV ; i++ ){
            for( uint8_t j = 0 ; j < 6 ; j++ ){
                show_data[i].signle_senser[j].senser_status = SENSER_DIS_CON;
            }
            qDebug()<<"阶段赋值"<<i;
        }

        for( uint8_t i = 0 ; i < DEV ; i++ ){
            //加锁
            table_LOCK[i] = Write_Unlock;

            switch (global_data::control_Mode[i] / 2) {
            case baozhong:
                Conservation_Renewal(i,0);
                break;
            case gongyu:
                Cobreeding_renewal(i,0);
                break;
            case cuiqing:
                Cui_Rejuvenate(i,0);
                break;
            default:
                 global_data::control_Mode[i] = BAOZHONG_END;
                 Conservation_Renewal(i,0);
                break;
            }
        }


        //参数更新标志
        global_data::update_flag = 0;

        //时间戳头尾赋值
        send_time.head = TIME_TAMP_HEAD ;
        send_time.tail = TIME_TAMP_TAIL;


        Abnormal_Widegt = ui->Abnormal_device;

        Equipment[0] = ui->Equipment1;


        Temperature[0] = ui->Temperature1;


        Humidity[0] = ui->Humidity1;


        Heating[0] = ui->Heating1;


        fall[0] = ui->fall1;


        Air_status[0] = ui->Air_status1;


        Heat_status[0] = ui->Heat_status1;


        Moiste_status[0] = ui->Moiste_status1;


        Dehumi_status[0] = ui->Dehumi_status1;


        Breathe_status[0] = ui->Breathe_status1;


        Sensitive_status[0] = ui->Sensitive_status1;


        Wind_status[0] = ui->Wind_status1;


        Disinfect_status[0] = ui->Disinfect_status1;


        Light_status[0] = ui->Light_status1;
        Sensor_status[0] = ui->Sensor_Status;


        //设备工作模式
        Mode[0] = ui->mode1;


//        for( uint8_t i = 0 ; i < DEV ; i++ ){
//            setLED(Mode[i],RED,16);
//        }

        Send_485_cmd.head = _485_CMD_HEAD ;
        Send_485_cmd.tail = _485_CMD_TAIL ;



        sensor_LOCK = Write_Unlock;
        system_LOCK = Write_Unlock;

        Silkworm_Area = ui->com_area;
        Silkworm_device = ui->com_device;

        DeviceChangeFlag = Write_Unlock;
        room_Change = Write_Unlock;

        pre_name  = global_data::id[0];

        Ctronl_Drawer(false);

}

void home::Interface_display(uint8_t room,FROM_DB_Typedef data,DataStatus method)
{
    room_show(data,room-1);

    if( comms_indicate->start_flag && data.status == ONLINE && method == __485_Serial){
        //qDebug()<<"通讯界面显示";
        QByteArray qa2((char *)global_data::id[room-1],20);
        QString qstr(qa2);
        QString str = qstr + "设备发送数据 " + QTime::currentTime().toString("hh:mm:ss");
        comms_indicate->list_show->addItem(str);
        if( comms_indicate->list_show->count() > 5000 ){
            comms_indicate->list_show->takeItem(0);

        }
        comms_indicate->list_show->scrollToBottom();
    }

}

void home::__485_CMD_Del(__485_CMD_Type cmd,uint8_t id)
{
    qDebug()<<"命令"<<cmd.cmd;
    switch (cmd.cmd) {
        //wifi连接成功
    case WIFI_CON_OK:
        system_Setting->ui->btn_Wconnect->setText("已连接");
        system_Setting->ui->btn_Wconnect->setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        qDebug()<<"WIfi连接处理函数";
        //设置样式表
        break;

        //连接失败
    case WIFI_CON_FAIL:
        system_Setting->ui->btn_Wconnect->setText("连接");
        system_Setting->ui->btn_Wconnect->setStyleSheet("background-color: rgb(255, 85, 0);font-family:'楷体';font:bold 16pt;");
        QMessageBox::warning(NULL, "WIFI连接", "WIFI连接失败", "确定");
        break;
        //4G连接成功
    case _4G_CON_OK:
        system_Setting->ui->btn_Wconnect->setText("已连接");
        system_Setting->ui->btn_Wconnect->setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        break;
        //4G连接失败
    case _4G_CON_FAIL:
        system_Setting->ui->btn_Wconnect->setText("连接");
        system_Setting->ui->btn_Wconnect->setStyleSheet("background-color: rgb(255, 85, 0);font-family:'楷体';font:bold 16pt;");
        QMessageBox::warning(NULL, "4G连接", "连接失败", "确定");
        break;
        //加热学习完成
    case AIR_HEAT_LEARN_END:
        qDebug()<<"加热完成";
        system_Setting->room_setting[id].Air.heat = "学习完成";
        system_Setting->ui->Heat_Learn->setText("学习完成");
        system_Setting->ui->Heat_Learn->setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        break;
        //制冷学习完成
    case AIR_CLOD_LEARN_END:
         qDebug()<<"制冷学习完成";
        system_Setting->room_setting[id].Air.cold = "学习完成";
        system_Setting->ui->Cold_Learn->setText("学习完成");
        system_Setting->ui->Cold_Learn->setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        break;
        //关闭学习完成
    case AIR_CLOSE_LEARN_END:
        qDebug()<<"关闭学习完成";
        system_Setting->room_setting[id].Air.clsoe = "学习完成";
        system_Setting->ui->Close_Learn->setText("学习完成");
        system_Setting->ui->Close_Learn->setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        break;
        //设备端回应心跳包
    case DEV_ALIVE_PACK_BACK:
        global_data::rcv_ok = true;
        qDebug()<<"回应心跳包";
        break;

    default:
        qDebug()<<"什么也没有";
        break;
    }
}

void home::Device_disengaged(FROM_DB_Typedef &data)
{
   //qDebug()<<data.id<<"房间离线";
   //QString temp = data.id;
   int room = 1;
//   for( uint8_t i = 0 ; i < DEV ; i++ ){
//       if( data.id.contains(global_data::id[i])){
//           room = i+1;
//           break;
//       }
//   }
    //temp.right(3).toInt();

   if( room == -1 )
       return ;
   data.temp = "0.0";
   data.humi = "0.0";

   data.status = OFFLINE;

   data.temp_center = "0.0";
   data.humi_center = "0.0";

   data.next_light_sta = "00:00";
   data.next_light_end = "00:00";

   data.next_breath_time = "00:00";
   data.next_breath_len = "0";

   data.next_sterilize_time = "00:00";
   data.next_sterilize_len = "0";
   data.air_status = 0;
   data.relay_status.relay_vale = 0;
   for( uint8_t i = 0 ; i <  6 ; i++ ){
       data.signle_senser[i].senser_status = SENSER_DIS_CON;
   }
   Interface_display(room,show_data[room-1],Invalid);
}

void home::setLED(QLabel *label, int color, int size)
{
    // 将label中的文字清空
        label->setText("");
        // 先设置矩形大小
        // 如果ui界面设置的label大小比最小宽度和高度小，矩形将被设置为最小宽度和最小高度；
        // 如果ui界面设置的label大小比最小宽度和高度大，矩形将被设置为最大宽度和最大高度；
        QString min_width = QString("min-width: %1px;").arg(size);              // 最小宽度：size
        QString min_height = QString("min-height: %1px;").arg(size);            // 最小高度：size
        QString max_width = QString("max-width: %1px;").arg(size);              // 最小宽度：size
        QString max_height = QString("max-height: %1px;").arg(size);            // 最小高度：size
        // 再设置边界形状及边框
        QString border_radius = QString("border-radius: %1px;").arg(size/2);    // 边框是圆角，半径为size/2
        //QString border_radius = QString("border-radius: %1px;").arg(0);
        QString border = QString("border:1px solid black;");                    // 边框为1px黑色
        // 最后设置背景颜色
        QString background = "background-color:";
        switch (color) {
        case 0:
            // 灰色
            background += "rgb(190,190,190)";
            break;
        case 1:
            // 红色
            background += "rgb(255,0,0)";
            break;
        case 2:
            // 绿色
            background += "rgb(0,255,0)";
            break;
        case 3:
            // 黄色
            background += "rgb(255,255,0)";
            break;
        case 4:
            //蓝色
            background +="rgb(170,255,255)";
            break;
        default:
            break;
        }

        const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
        label->setStyleSheet(SheetStyle);
}


QString home::Set_font_Style(char *fontsize,char *weight,char *color,char *data)
{
    QString result =
            QString().sprintf(R"(<html><head/><body><p><span style=" font-size:%s; %s color:#%s;">%s</span></p></body></html>)",fontsize,weight,color,data);
    return result;
}

void home::Sensor_show(uint8_t room)
{
    double temp,humi;
    uint8_t j;
    QString id = QString(global_data::update_allTable[room].id);
    QString tempJust,humi_Just;
    bool flag = true;
    for( uint8_t i = 0 ; i < Sensor_Number ; i++ ){
        temp = (double)show_data[room].signle_senser[i].signle_temp/10;
        humi = (double)show_data[room].signle_senser[i].signle_humi/10;
        tempJust =QString::number((double)global_data::update_allTable[room].set_senser_diff[i].temp_adjust/10,
                                  'f',1);
        humi_Just = QString::number((double)global_data::update_allTable[room].set_senser_diff[i].humi_adjust/10,
                                    'f',1);
        //查找数据位置
        QString name = id + "-"+ QString::number(i+1);
        uint8_t rowCount = sensor->sensor_table->rowCount();
        for( j = 0 ; j < rowCount ; j++ ){
            if( sensor->sensor_table->item(j,1)->text().contains(name)){

                break;
            }
        }

        //情况判断
        //这里不是断开的话，都可以判断
        //分为两种情况，一种为断开，一种为非断开
        if( show_data[room].signle_senser[i].senser_status == SENSER_DIS_CON){
            //这种情况视为断开
            if( j != rowCount ){
                Delete_Sensor_Line(j);
                sensor->sensor_table->removeRow(j);               
                qDebug()<<"传感器断开";
            }
        }
        else {

            //没有断开的情况，且在表格内没有找到这个传感器
            bool status  = false;
            if( j == rowCount){
                sensor->sensor_table->insertRow(rowCount);


                sensor->sensor_table->setItem(rowCount,0,new QTableWidgetItem(QString::number(rowCount)));
                sensor->sensor_table->setItem(rowCount,1,new QTableWidgetItem(name));
                qDebug()<<"行添加";
                status = true;
            }

            Sensor_Status_Setting(j,temp,humi,tempJust,humi_Just,status);

            if( show_data[room].signle_senser[i].senser_status == SENSER_FAIL ){
                //异常情况处理

                sensor->sensor_table->setItem(j,6,
                                              new QTableWidgetItem("异常"));

                sensor->sensor_table->item(j,6)->setBackgroundColor(QColor(255,0,0));
                flag = false;
            }

        }
    }

    sensor->sensor_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    sensor->sensor_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    sensor->sensor_table->sortByColumn(1,Qt::AscendingOrder);

    uint8_t rowCount = sensor->sensor_table->rowCount();

    if( flag )
    {
        Sensor_status[0]->setText(R"(<html><head/><body><p><span style=" font-size:16pt; font-weight:600; color:#00ff7f;">传感器正常    </span></p></body></html>)");
    }
    else
    {
        Sensor_status[0]->setText(R"(<html><head/><body><p><span style=" font-size:16pt; font-weight:600; color:#ff0000;">传感器异常    </span></p></body></html>)");
    }

    for( uint8_t i = 0 ; i < rowCount ; i++ ){

        QTableWidgetItem *item = sensor->sensor_table->item(i,0);
        if( item )
            delete item;
        sensor->sensor_table->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
    }
}

void home::Sensor_Status_Setting(uint8_t room,double temp,double humi,
                                 QString tempAdjust,QString humiAdjust,bool rowStatus)
{
       uint8_t array[3] = {2,3,6};
       for( uint8_t m = 0 ; m < 3 ; m++ ){
               QTableWidgetItem  *item = sensor->sensor_table->item(room,array[m]);
               if( item )
                    delete item;
       }

    sensor->sensor_table->setItem(room,2,
                                  new QTableWidgetItem(QString::number(temp,'f',1)));
    sensor->sensor_table->setItem(room,3,
                                  new QTableWidgetItem(QString::number(humi,'f',1)));


    if( rowStatus ){
        sensor->sensor_table->setItem(room,4,
                                          new QTableWidgetItem(tempAdjust));

        sensor->sensor_table->setItem(room,5,
                                          new QTableWidgetItem(humiAdjust));
    }

    sensor->sensor_table->setItem(room,6,
                                  new QTableWidgetItem("正常"));

      for( uint8_t i  = 0 ; i < 7 ; i++ ){
          if( i != 4 && i != 5 ){
              sensor->sensor_table->item(room,i)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
          }
      }

    sensor->sensor_table->item(room,6)->setBackgroundColor(QColor(0,255,0));

}

void home::Del_Sensor(QString id)
{
    uint8_t rowCount;

    bool status = false;
    for( uint8_t i = 0 ; i < 6 ; i++ ){
        rowCount = sensor->sensor_table->rowCount();
        for( uint8_t j = 0 ; j < rowCount ; j++ ){
            if( sensor->sensor_table->item(j,1)->text().contains(id)){
                Delete_Sensor_Line(j);
                sensor->sensor_table->removeRow(j);
                status = true;
                break;
            }
        }
    }

    if( status ){
        sensor->sensor_table->sortByColumn(1);
        rowCount = sensor->sensor_table->rowCount();
        for( uint8_t i = 0 ; i < rowCount ; i++ ){
            QTableWidgetItem *item = sensor->sensor_table->item(i,0);
            if( item )
                delete item;

            sensor->sensor_table->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
        }
    }
}

void home::Set_stage(uint8_t room, int stage)
{

    global_data::execute_date[room].run_stage = stage;
    qDebug()<<"阶段赋值成功";
}

bool home::Device_off(uint8_t room, WORK_WAY_STATUS way)
{

    qDebug()<<"设备进行关闭 "<<room+1<<"号房间";
    bool status = false;
    //485发送指令
    global_data::Mode_Lock[room] = Write_Unlock;
    global_data::work_way[room].work_status = way;

    if( global_data::Hear_flag ){
        status = Write_Work_Way(global_data::work_way[room]);
    }

    QFuture<void> f1;
    if( global_data::on_line ){
        bool temp;
        if( status ){
            f1 = QtConcurrent::run( [&temp,room](){
                temp = DB.WORKwayToDB(global_data::work_way[room],"0");
            });
        }
        else{
            f1 = QtConcurrent::run( [&temp,room](){
                temp = DB.WORKwayToDB(global_data::work_way[room],"1");
            });
        }

        sleep(1000);
        if( !temp ){
            DB.open("test1");
        }

        status |= temp;
    }
    f1.cancel();

    if( !status)
        return false;

    uint8_t times = 0;
    while(global_data::Mode_Lock[room] == Write_Unlock){
        if( times >= 8 ){
            return false;
        }

         times++;
         sleep(1000);
    }


    return true;
}

void home::Send_update_Message(uint8_t room)
{
    bool status = false;
    if( global_data::Hear_flag ){
       status =  update_All_table(global_data::update_allTable[room]);
    }

    QFuture<void> f1;
    if( global_data::on_line ){
        bool flag = false;
        if( status ){
            f1 = QtConcurrent::run([&flag,room]{
                flag = DB.AllTableToDB(global_data::update_allTable[room],global_data::execute_date[room]);
            });

        }
        else{
            f1 = QtConcurrent::run([&flag,room]{
                flag = DB.AllTableToDB(global_data::update_allTable[room],global_data::execute_date[room],"1","1");
            });
        }
        sleep(3 * 1000);
        f1.cancel();
        if( !flag ){
            DB.open("test1");
        }
    }
}

void home::List_Sensor(uint8_t room,uint8_t i)
{
    QString name = QString(global_data::update_allTable[room].id);
    uint8_t rowCount = sensor->sensor_table->rowCount();

    for( i = 0 ; i < rowCount ; i++ ){
        if( sensor->sensor_table->item(i,1)->text().contains(name)){
            break;
        }
    }

    if( i == rowCount ){
        //没有查查询到这个传感器的数据
//        for( uint8_t j = 0 ; j < 6 ; j++ ){
//            global_data::update_allTable[room].set_senser_diff[j]
//                    .humi_adjust = 0;
//            global_data::update_allTable[room].set_senser_diff[j]
//                    .temp_adjust = 0;
//        }
    }
    else
    {
        QString id;
        uint8_t n;
        for( uint8_t m = 0 ; m < 6 ; m++ ){
            id = name + "-" + QString::number(m+1);
            for( n  = i ;  n < i + 6 &&  n < rowCount; n++ ){
                if( sensor->sensor_table->item(n,1)->text().contains(id)){
                    global_data::update_allTable[room].set_senser_diff[m]
                            .humi_adjust = (uint16_t)(sensor->sensor_table->item(n,4)->text().toDouble()*10+0.001);
                    global_data::update_allTable[room].set_senser_diff[m]
                            .temp_adjust = (uint16_t)(sensor->sensor_table->item(n,5)->text().toDouble()*10+0.001);
                    break;
                }
            }

//            if( n == ( i + 6 )){
//                global_data::update_allTable[room].set_senser_diff[m]
//                        .humi_adjust = 0;
//                global_data::update_allTable[room].set_senser_diff[m]
//                        .temp_adjust = 0;
//            }
        }
    }
}

void home::Sensor_diff_Refresh(UPDATE_ALL_TABLE_TYPEDEF data)
{
    uint8_t rowCount = sensor->sensor_table->rowCount();
    QString id,name = QString(data.id),temp;
    uint8_t tempIndex ;
    for( tempIndex = 0 ; tempIndex < rowCount ; tempIndex++ ){
        if( sensor->sensor_table->item(tempIndex,1)->text().contains(name)){
            break;
        }
    }

    //tempIndex记录着最先传感器名字出现的地方
    if( tempIndex < rowCount ){
        for( uint8_t i = 0 ; i < 6 ; i++ ){
            id = name + "-" + QString::number(i+1);
            for( uint8_t j = tempIndex ; j < tempIndex + 6 && j < rowCount ; j++ ){
                  if( sensor->sensor_table->item(j,1)->text().contains(id)){

                        QTableWidgetItem *item = sensor->sensor_table->item(j,4);
                        if( item )
                            delete item;
                        item = sensor->sensor_table->item(j,5);
                        if( item )
                            delete item;

                        temp =QString::number((double)data.set_senser_diff[i].temp_adjust/10,'f',1);
                        sensor->sensor_table->setItem(j,4
                                                      ,new QTableWidgetItem(temp));

                        temp =QString::number((double)data.set_senser_diff[i].humi_adjust/10,'f',1);
                        sensor->sensor_table->setItem(j,5
                                                      ,new QTableWidgetItem(temp));

                  }
            }

        }
    }
}

void home::Seed_Table_color_change(uint8_t id,int pre_stage)
{
    uint8_t column = seed[id]->tableWiegt->columnCount();

    for( uint8_t i = 0 ; i < column ; i++ ){
        if( pre_stage != global_data::execute_date[id].run_stage && pre_stage >= 0){
            //seed[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(QColor(227,237,249));
            if( i < 2 )  co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::date_Color);
            else if(i ==2 ) seed[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::day_Color);
            else if(i ==3 ) seed[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::temp_Color);
            else if(i ==4 ) seed[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::humi_Color);
            else if(i < 21 ) seed[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::breath_Color);
            else if(i < 27 ) seed[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::sensitive_Color);
            else if(i < 35 ) seed[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::disinfect_Color);
            else if(i < 41 ) seed[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::illumina_Color);
        }

        seed[id]->tableWiegt->item(global_data::execute_date[id].run_stage,i)->setBackgroundColor(QColor(Qt::green));
    }

}

void home::Conservat_Table_color_change(uint8_t id,int pre_stage)
{
    uint8_t column = co_Parenting[id]->tableWiegt->columnCount();

    for( uint8_t i = 0 ; i < column ; i++ ){
        if( pre_stage != global_data::execute_date[id].run_stage && pre_stage >= 0){
            //co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(QColor(227,237,249));
            if( i < 2 )  co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::date_Color);
            else if(i == 2 ) co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::temp_Color);
            else if(i == 3 ) co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::temp_Color);
            else if(i == 4 ) co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::humi_Color);
            else if(i < 21 ) co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::breath_Color);
            else if(i < 27 ) co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::sensitive_Color);
            else if(i < 35 ) co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::disinfect_Color);
            else if(i < 41 ) co_Parenting[id]->tableWiegt->item(pre_stage,i)->setBackgroundColor(global_data::illumina_Color);
        }
        co_Parenting[id]->tableWiegt->item(global_data::execute_date[id].run_stage,i)->setBackgroundColor(QColor(Qt::green));
    }
}

void home::Cui_Table_color_change(uint8_t id,int pre_stage)
{
    uint8_t column = Set_parment[id]->tableWidget->columnCount();
    for( uint8_t i = 0 ; i < column ; i++ ){
        if( pre_stage != global_data::execute_date[id].run_stage && pre_stage >= 0){
            //Set_parment[id]->tableWidget->item(pre_stage,i)->setBackgroundColor(QColor(227,237,249));
            if( i < 2 )
                Set_parment[id]->tableWidget->item(pre_stage,i)->setBackgroundColor(global_data::date_Color);
            else if( i == 2 )   Set_parment[id]->tableWidget->item(pre_stage,i)->setBackgroundColor(global_data::temp_Color);
            else if( i == 3 )   Set_parment[id]->tableWidget->item(pre_stage,i)->setBackgroundColor(global_data::humi_Color);
            else if( i < 20 )  Set_parment[id]->tableWidget->item(pre_stage,i)->setBackgroundColor(global_data::breath_Color);
            else if ( i < 26 ) Set_parment[id]->tableWidget->item(pre_stage,i)->setBackgroundColor(global_data::sensitive_Color);
            else if ( i < 34 ) Set_parment[id]->tableWidget->item(pre_stage,i)->setBackgroundColor(global_data::disinfect_Color);
            else if ( i < 40 ) Set_parment[id]->tableWidget->item(pre_stage,i)->setBackgroundColor(global_data::illumina_Color);
        }
        Set_parment[id]->tableWidget->item(global_data::execute_date[id].run_stage,i)->setBackgroundColor(QColor(Qt::green));
    }
}

int home::ID_lookup(QString id)
{
    int room = -1;
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( id.contains(QString(global_data::id[i]))){
            room = i;
        }
    }

    return room;
}

void home::Default_Paremeter_Chagne()
{
    QSettings *settings = new QSettings(QString(FILENAME )+"/config.ini", QSettings::IniFormat);
    settings->setValue("Default_parameter/flag",true);
    delete settings;
}

void home::System_tray()
{

    m_systemTray = new QSystemTrayIcon(this);
    m_menu = new QMenu;

    m_action1 = new QAction(tr("打开主界面"),this);
    m_action2 = new QAction(tr("退出系统"),this);

    m_menu->addSeparator();
    m_menu->addAction(m_action1);
    m_menu->addAction(m_action2);
    m_systemTray->setToolTip(tr("蚕桑大数据管理平台"));
    m_systemTray->setIcon(QIcon(":/img/2.ico"));
    m_systemTray->setContextMenu(m_menu);     //设置托盘上下文菜单

    connect(m_action1, &QAction::triggered,[=]{
        this->show();
    });
    connect(m_action2, &QAction::triggered,[=](){
        qApp->quit();
    });

    connect(m_systemTray, &QSystemTrayIcon::activated, this, &home::activeTray);

}

void home::System_parameter_change(UPDATE_ALL_TABLE_TYPEDEF data)
{
    system_Setting->ui->Temp_Diff->setText(QString::number((double)data.set_sensor[0].temp_diff/10,'f',1));
    system_Setting->ui->Humi_Diff->setText(QString::number((double)data.set_sensor[0].humi_diff/10,'f',1));
    system_Setting->ui->WindDiff->setText(QString::number((double)data.set_wind_temp_diff/10,'f',1));

    switch (global_data::control_Mode[0] / 2) {
    case 0:
        system_Setting->ui->Button_Bao->setChecked(true);
        break;
    case 1:
        system_Setting->ui->Button_Gong->setChecked(true);
        break;
    case 2:
        system_Setting->ui->Button_Cui->setChecked(true);
        break;
    default:
        system_Setting->ui->Button_Bao->setChecked(true);
        break;
    }

}

void home::Cui_Rejuvenate(uint8_t room,bool assigemnt)
{
   // qDebug()<<"催青"<<room+1<<"房间得时间更新";
    uint8_t i;
    QDate staDate,endDate;

    QDate curDate = QDate::currentDate();

    QString year = QDate::currentDate().toString("yyyy/");

    uint8_t row = Set_parment[room]->tableWidget->rowCount();

    //qDebug()<<"崩了"<<"表格的行数"<<row<<"时间的年数"<<year;
    for(  i = 0 ; i < row ; i++ ){

        staDate = QDate::fromString(year + Set_parment[room]->tableWidget->item(i,0)->text(),"yyyy/MM/dd");
        endDate = QDate::fromString(year + Set_parment[room]->tableWidget->item(i,1)->text(),"yyyy/MM/dd");

        if( curDate.daysTo(endDate) == 0){
            global_data::execute_date[room].sta_date = staDate.toString("MM/dd");
            global_data::execute_date[room].end_date = endDate.toString("MM/dd");
            global_data::execute_date[room].run_stage = i;
            break;
        }
    }


    //没有找到条件符合的
    if( i == row ){
        global_data::execute_date[room].run_stage = -1;
        return ;
    }


    //参数赋值开始时
    if( global_data::execute_date[room].run_stage != -1 ){
        if( assigemnt ){
            global_data::Send_onine_flag[room] = false;
        }
        QString temp;
        uint8_t stage = global_data::execute_date[room].run_stage;


        temp = Set_parment[room]->tableWidget->item(stage,2)->text();
        global_data::update_allTable[room].set_sensor[0].temp_center=
                (uint16_t)(temp.toDouble()*10+0.001);

        temp = Set_parment[room]->tableWidget->item(stage,3)->text();
        global_data::update_allTable[room].set_sensor[0].humi_center=
                (uint16_t)(temp.toDouble()*10+0.001);

        for( uint8_t i = 0 ,tempIndex = 2; i < 8 ; i++ ,tempIndex++){

            temp = Set_parment[room]->tableWidget->item(stage,2*tempIndex)
                    ->text();

            global_data::update_allTable[room].set_breath[i].time_sta
                    = (QTime::fromString(temp,"hh:mm")).msecsSinceStartOfDay()/1000;

            temp = Set_parment[room]->tableWidget->item(stage,2*tempIndex+1)
                    ->text().split("分")[0];
            qDebug()<<"分钟"<<temp;
            global_data::update_allTable[room].set_breath[i].min_len
                    =temp.toInt();
        }

        for( uint8_t i = 0 ,tempIndex = 10; i < 4 ; i++ ,tempIndex++){
            if( i < 3 ){
                temp = Set_parment[room]->tableWidget->item(stage,2*tempIndex)->text();
                global_data::update_allTable[room].set_sensitive[i].time_sta
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
                temp = Set_parment[room]->tableWidget->item(stage,2*tempIndex+1)->text();

                global_data::update_allTable[room].set_sensitive[i].time_end
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
            }

                temp = Set_parment[room]->tableWidget->item(stage,2*tempIndex+6)->text();
                global_data::update_allTable[room].set_sterilize[i].time_sta
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

                temp = Set_parment[room]->tableWidget->item(stage,2*tempIndex+7)->text().split("分")[0];
                global_data::update_allTable[room].set_sterilize[i].min_len
                        =temp.toInt();

                if( i < 3){
                    temp = Set_parment[room]->tableWidget->item(stage,2*tempIndex+14)->text();
                    global_data::update_allTable[room].set_light[i].time_sta
                            =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

                    temp = Set_parment[room]->tableWidget->item(stage,2*tempIndex+15)->text();
                    global_data::update_allTable[room].set_light[i].time_end
                            =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
                }
        }

        global_data::update_allTable[room].set_sensor[0].temp_center =
                uint16_t(Set_parment[room]->tableWidget->item(stage,2)->text().toDouble()*10+0.001);

        global_data::update_allTable[room].set_sensor[0].humi_center =
                uint16_t(Set_parment[room]->tableWidget->item(stage,3)->text().toDouble()*10+0.001);


        //开始遍历传感器表格
        //List_Sensor(room,i);

        if( assigemnt ){
            Send_update_Message(room);
            //global_data::Send_onine_flag[room] = true;
        }
    }//        //满足条件，设置更新标志位

    //UPDATE_ALL_TABLE_TYPEDEF data = global_data::update_allTable[room];

}

void home::Cui_UpdateTable(uint8_t room,DataStatus status)
{
   // qDebug()<<"room"<<room<<global_data::execute_date[room].run_stage;

    int stage = global_data::execute_date[room].run_stage;
    //将数据填入表中
    UPDATE_ALL_TABLE_TYPEDEF data = global_data::update_allTable[room];
    System_parameter_change(data);

    if( stage < 0 || stage > 11)
        return;
        qDebug()<<"房间号"<<room;
        QString temp;

        //设置相应的更新标志位
        global_data::update_flag = true;
        if( status == __485_Serial ){
            if( global_data::on_line ){
                DB.AllTableToDB(global_data::update_allTable[room],global_data::execute_date[room]);
            }
        }
        else if( status == DataBase ){
            //global_data::room_flag[room] = false;
            if( global_data::Hear_flag ){
                update_All_table(global_data::update_allTable[room]);
            }
        }
        

        //uint8_t stage = global_data::stage[room];

        if( stage < 0 )
            return ;
        /*******************表格***********************/

//            qDebug()<<"阶段"<<stage;
            uint8_t column = Set_parment[room]->tableWidget->columnCount();

            for( uint8_t i = 0 ; i < column ; i++ ){
                QTableWidgetItem *item = Set_parment[room]->tableWidget->item(stage,i);
                if( item )
                    delete item;
            }

            Set_parment[room]->tableWidget->
                    setItem(stage,0,new
                            QTableWidgetItem(global_data::execute_date[room].end_date));

            Set_parment[room]->tableWidget->
                    setItem(stage,1,new
                            QTableWidgetItem(global_data::execute_date[room].end_date));

            //设置参数表的值   
            temp = QString::number((double)data.set_sensor[0].temp_center/10,'f',1);
            Set_parment[room]->tableWidget->
                    setItem(stage,2,new
                            QTableWidgetItem(temp));


            temp = QString::number((double)data.set_sensor[0].humi_center/10,'f',1);
            Set_parment[room]->tableWidget->
                    setItem(stage,3,new
                            QTableWidgetItem(temp));

            for( uint8_t i = 0 ,tempIndex = 2; i < 8 ; i++ ,tempIndex++){
                temp = QTime::fromMSecsSinceStartOfDay(data.set_breath[i].time_sta*1000).toString("hh:mm");
                qDebug()<<temp;
                Set_parment[room]->tableWidget->setItem(stage,2*tempIndex,
                                                        new QTableWidgetItem(temp));

                temp = QString::number(data.set_breath[i].min_len) + "分钟";
//                qDebug()<<"分钟数"<<temp;

                Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+1,
                                                        new QTableWidgetItem(temp));
            }

            for( uint8_t i = 0 ,tempIndex = 10; i < 4 ; i++ ,tempIndex++){

                //感光
                if( i < 3 ){
                    temp =QTime::fromMSecsSinceStartOfDay(data.set_sensitive[i].time_sta *1000).toString("hh:mm");
                    Set_parment[room]->tableWidget->setItem(stage,2*tempIndex,
                                                            new QTableWidgetItem(temp));

                    temp = QTime::fromMSecsSinceStartOfDay(data.set_sensitive[i].time_end *1000).toString("hh:mm");
                    Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+1,
                                                            new QTableWidgetItem(temp));
                }

                //消毒
                temp = QTime::fromMSecsSinceStartOfDay(data.set_sterilize[i].time_sta *1000).toString("hh:mm");
                Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+6,
                                                                        new QTableWidgetItem(temp));
                temp = QString::number(data.set_sterilize[i].min_len) + "分钟";
                Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+7,
                                                                        new QTableWidgetItem(temp));

                //光照
                if( i < 3 ){
                    temp =QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_sta *1000).toString("hh:mm");
                    Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+14,
                                                            new QTableWidgetItem(temp));

                    temp = QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_end *1000).toString("hh:mm");
                    Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+15,
                                                            new QTableWidgetItem(temp));
                }

            }

            Set_parment[room]->tableWidget->item(stage,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Set_parment[room]->tableWidget->item(stage,3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            //将数据写入txt文本
            Set_parment[room]->DataTo_txt(stage);

        /************传感器的校准值***********************/


            Sensor_diff_Refresh(data);
            sensor->Sensor_Save(room);


           system_Setting->Diff_Save(room);

           uint8_t rowCount = Set_parment[room]->tableWidget->rowCount();
           uint8_t colCount = Set_parment[room]->tableWidget->columnCount();

           for( uint8_t i = 0 ; i < rowCount ; i++ ){
               for( uint8_t j = 0; j < colCount ; j++){
                   Set_parment[room]->tableWidget->item(i,j)->setTextColor(Qt::black);
                   Set_parment[room]->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
               }
           }
}

void home::Conservation_Renewal(uint8_t room,bool assigemnt)
{

//    qDebug()<<"保种"<<room+1<<"房间更新";
    uint8_t i;
    QDate staDate,endDate;
    QDate curDate = QDate::fromString(QDate::currentDate().toString("yyyy-MM-dd"),"yyyy-MM-dd");

    QString year = QDate::currentDate().toString("yyyy/");
    uint8_t row = seed[room]->tableWiegt->rowCount();
    for( i = 0 ; i < row ; i++ ){
        staDate = QDate::fromString(year + seed[room]->tableWiegt->item(i,0)->text(),"yyyy/MM/dd");
        endDate = QDate::fromString(year + seed[room]->tableWiegt->item(i,1)->text(),"yyyy/MM/dd");
        if( curDate.daysTo(endDate) >=0 && staDate.daysTo(curDate) >= 0){
            global_data::execute_date[room].sta_date = staDate.toString("MM/dd");
            global_data::execute_date[room].end_date = endDate.toString("MM/dd");
            global_data::execute_date[room].run_stage = i;
            break;
        }
    }
    //没有找到条件符合的
    if( i == row){
        global_data::execute_date[room].run_stage = -1;
        return ;
    }


    //参数赋值开始时
    if( global_data::execute_date[room].run_stage != -1){

        if( assigemnt ){
            global_data::Send_onine_flag[room] = false;
        }
        QString temp;
        uint8_t stage = global_data::execute_date[room].run_stage;

        temp = seed[room]->tableWiegt->item(stage,3)
                ->text();
        global_data::update_allTable[room].set_sensor[0].temp_center =
                (uint16_t)(temp.toDouble()*10+0.001);
        temp = seed[room]->tableWiegt->item(stage,4)
               ->text();
        global_data::update_allTable[room].set_sensor[0].humi_center =
               (uint16_t)(temp.toDouble()*10+0.001);

        for( uint8_t i = 0 ,tempIndex = 3; i < 8 ; i++ ,tempIndex++){
            temp = seed[room]->tableWiegt->item(stage,2*tempIndex-1)
                    ->text();
            global_data::update_allTable[room].set_breath[i].time_sta
                    = (QTime::fromString(temp,"hh:mm")).msecsSinceStartOfDay()/1000;

            temp = seed[room]->tableWiegt->item(stage,2*tempIndex)
                    ->text().split("分")[0];
            global_data::update_allTable[room].set_breath[i].min_len
                    =temp.toInt();
        }

        for( uint8_t i = 0 ,tempIndex = 11; i < 4 ; i++ ,tempIndex++){
            if( i < 3 ){
                temp = seed[room]->tableWiegt->item(stage,2*tempIndex-1)->text();
                global_data::update_allTable[room].set_sensitive[i].time_sta
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
                temp = seed[room]->tableWiegt->item(stage,2*tempIndex)->text();

                global_data::update_allTable[room].set_sensitive[i].time_end
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
            }

                temp = seed[room]->tableWiegt->item(stage,2*tempIndex+5)->text();
                global_data::update_allTable[room].set_sterilize[i].time_sta
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

                temp = seed[room]->tableWiegt->item(stage,2*tempIndex+6)->text().split("分")[0];
                global_data::update_allTable[room].set_sterilize[i].min_len
                        =temp.toInt();

                if( i < 3){
                    temp = seed[room]->tableWiegt->item(stage,2*tempIndex+13)->text();
                    global_data::update_allTable[room].set_light[i].time_sta
                            =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

                    temp = seed[room]->tableWiegt->item(stage,2*tempIndex+14)->text();
                    global_data::update_allTable[room].set_light[i].time_end
                            =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
                }
        }

        global_data::update_allTable[room].set_sensor[0].temp_center=
                (uint16_t)(seed[room]->tableWiegt->item(stage,3)->text().toDouble()*10+0.001);

        global_data::update_allTable[room].set_sensor[0].humi_center=
                (uint16_t)(seed[room]->tableWiegt->item(stage,4)->text().toDouble()*10+0.001);


        //满足条件，设置更新标志位
        if( assigemnt ){
            Send_update_Message(room);
        }
    }

}

void home::Conservation_UpdateTable(uint8_t room, DataStatus status)
{
        int stage = global_data::execute_date[room].run_stage;
        //将数据填入表中
        UPDATE_ALL_TABLE_TYPEDEF data = global_data::update_allTable[room];
        System_parameter_change(data);

        if( stage < 0 || stage > 29)
            return;
        QString temp;
        //设置相应的更新标志位
        global_data::update_flag = true;
        if( status == __485_Serial ){
            if( global_data::on_line ){
                DB.AllTableToDB(global_data::update_allTable[room],global_data::execute_date[room]);
            }
        }
        else if( status == DataBase ){
            //global_data::room_flag[room] = false;
            if( global_data::Hear_flag ){
                update_All_table(global_data::update_allTable[room]);
            }

        }


//        uint8_t stage = global_data::stage[room];


        //设置参数表的值


            uint8_t column = seed[room]->tableWiegt->columnCount();

            for( uint8_t i = 0 ; i < column ; i++ ){
                QTableWidgetItem *item = seed[room]->tableWiegt->item(stage,i);
                if( item )
                    delete item;
            }

            QString year = QDate::currentDate().toString("yyyy/");
            QDate sta_date,end_date;
            sta_date = QDate::fromString(year+global_data::execute_date[room].sta_date,"yyyy/MM/dd");
            end_date = QDate::fromString(year+global_data::execute_date[room].end_date,"yyyy/MM/dd");

            seed[room]->tableWiegt->
                    setItem(stage,0,new
                            QTableWidgetItem(global_data::execute_date[room].sta_date));
            seed[room]->tableWiegt->
                    setItem(stage,1,new
                            QTableWidgetItem(global_data::execute_date[room].end_date));
            seed[room]->tableWiegt->
                    setItem(stage,2,new
                            QTableWidgetItem(QString::number(sta_date.daysTo(end_date) + 1)));



            temp = QString::number((double)data.set_sensor[0].temp_center/10,'f',1);
            seed[room]->tableWiegt->
                    setItem(stage,3,new
                            QTableWidgetItem(temp));

            temp = QString::number((double)data.set_sensor[0].humi_center/10,'f',1);
            seed[room]->tableWiegt->
                    setItem(stage,4,new
                            QTableWidgetItem(temp));

            seed[room]->tableWiegt->item(stage,3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            seed[room]->tableWiegt->item(stage,4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


            for( uint8_t i = 0 ,tempIndex = 3; i < 8 ; i++ ,tempIndex++){
                temp = QTime::fromMSecsSinceStartOfDay(data.set_breath[i].time_sta*1000).toString("hh:mm");
                seed[room]->tableWiegt->setItem(stage,2*tempIndex-1,
                                                        new QTableWidgetItem(temp));

                temp = QString::number(data.set_breath[i].min_len) + "分钟";
                seed[room]->tableWiegt->setItem(stage,2*tempIndex,
                                                        new QTableWidgetItem(temp));
            }

            for( uint8_t i = 0 ,tempIndex = 11; i < 4 ; i++ ,tempIndex++){

                //感光
                if( i < 3 ){
                    temp =QTime::fromMSecsSinceStartOfDay(data.set_sensitive[i].time_sta *1000).toString("hh:mm");
                    seed[room]->tableWiegt->setItem(stage,2*tempIndex-1,
                                                            new QTableWidgetItem(temp));

                    temp = QTime::fromMSecsSinceStartOfDay(data.set_sensitive[i].time_end *1000).toString("hh:mm");
                    seed[room]->tableWiegt->setItem(stage,2*tempIndex,
                                                            new QTableWidgetItem(temp));
                }

                //消毒
                temp = QTime::fromMSecsSinceStartOfDay(data.set_sterilize[i].time_sta *1000).toString("hh:mm");
                seed[room]->tableWiegt->setItem(stage,2*tempIndex+5,
                                                                        new QTableWidgetItem(temp));
                temp = QString::number(data.set_sterilize[i].min_len) + "分钟";
                seed[room]->tableWiegt->setItem(stage,2*tempIndex+6,
                                                                        new QTableWidgetItem(temp));

                //光照
                if( i < 3 ){
                    temp =QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_sta *1000).toString("hh:mm");
                    seed[room]->tableWiegt->setItem(stage,2*tempIndex+13,
                                                            new QTableWidgetItem(temp));

                    temp = QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_end *1000).toString("hh:mm");
                    seed[room]->tableWiegt->setItem(stage,2*tempIndex+14,
                                                            new QTableWidgetItem(temp));
                }

            }
            seed[room]->tableWiegt->item(stage,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            seed[room]->tableWiegt->item(stage,3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            seed[room]->tableWiegt->item(stage,4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            seed[room]->DataTo_txt(stage);


        //传感器的校准值

             Sensor_diff_Refresh(data);
            sensor->Sensor_Save(room);


            system_Setting->Diff_Save(room);

            uint8_t rowCount = seed[room]->tableWiegt->rowCount();
            uint8_t colCount = seed[room]->tableWiegt->columnCount();

            for( uint8_t i = 0 ; i < rowCount ; i++ ){
                for( uint8_t j = 0; j < colCount ; j++){
                    seed[room]->tableWiegt->item(i,j)->setTextColor(Qt::black);
                    seed[room]->tableWiegt->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }
}

void home::Cobreeding_renewal(uint8_t room,bool assigemnt)
{
    uint8_t i;
    //qDebug()<<"共育"<<room+1<<"房间更新";
    QDate staDate,endDate;
    QDate curDate = QDate::fromString(QDate::currentDate().toString("yyyy-MM-dd"),"yyyy-MM-dd");

    QString year = QDate::currentDate().toString("yyyy/");
    uint8_t row = co_Parenting[room]->tableWiegt ->rowCount();
    //UPDATE_ALL_TABLE_TYPEDEF &data = global_data::update_allTable[room];
    for(  i = 0 ; i < row ; i++ ){
        staDate = QDate::fromString(year + co_Parenting[room]->tableWiegt->item(i,0)->text(),"yyyy/MM/dd");
        endDate = QDate::fromString(year + co_Parenting[room]->tableWiegt->item(i,1)->text(),"yyyy/MM/dd");

        if( curDate.daysTo(endDate) >=0 && staDate.daysTo(curDate) >= 0){
            global_data::execute_date[room].sta_date = staDate.toString("MM/dd");
            global_data::execute_date[room].end_date = endDate.toString("MM/dd");
            global_data::execute_date[room].run_stage = i;
            break;
        }
    }

    //没有找到条件符合的
    if( i == row){
        global_data::execute_date[room].run_stage = -1;
        return ;
    }


    //参数赋值开始时
    if( global_data::execute_date[room].run_stage != -1 ){
        if( assigemnt ){
            global_data::Send_onine_flag[room] = false;
        }
        QString temp;
        uint8_t stage = global_data::execute_date[room].run_stage;
        for( uint8_t i = 0 ,tempIndex = 3; i < 8 ; i++ ,tempIndex++){
            temp = co_Parenting[room]->tableWiegt->item(stage,2*tempIndex-1)
                    ->text();
            global_data::update_allTable[room].set_breath[i].time_sta
                    = (QTime::fromString(temp,"hh:mm")).msecsSinceStartOfDay()/1000;

            temp = co_Parenting[room]->tableWiegt->item(stage,2*tempIndex)
                    ->text().split("分")[0];
            global_data::update_allTable[room].set_breath[i].min_len
                    =temp.toInt();
        }

        for( uint8_t i = 0 ,tempIndex = 11; i < 4 ; i++ ,tempIndex++){
            if( i < 3 ){
                temp = co_Parenting[room]->tableWiegt->item(stage,2*tempIndex-1)->text();
                global_data::update_allTable[room].set_sensitive[i].time_sta
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
                temp = co_Parenting[room]->tableWiegt->item(stage,2*tempIndex)->text();

                global_data::update_allTable[room].set_sensitive[i].time_end
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
            }

                temp = co_Parenting[room]->tableWiegt->item(stage,2*tempIndex+5)->text();
                global_data::update_allTable[room].set_sterilize[i].time_sta
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

                temp = co_Parenting[room]->tableWiegt->item(stage,2*tempIndex+6)->text().split("分")[0];
                global_data::update_allTable[room].set_sterilize[i].min_len
                        =temp.toInt();

                if( i < 3){
                    temp = co_Parenting[room]->tableWiegt->item(stage,2*tempIndex+13)->text();
                    global_data::update_allTable[room].set_light[i].time_sta
                            =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

                    temp = co_Parenting[room]->tableWiegt->item(stage,2*tempIndex+14)->text();
                    global_data::update_allTable[room].set_light[i].time_end
                            =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
                }
        }

        global_data::update_allTable[room].set_sensor[0].temp_center =
                uint16_t(co_Parenting[room]->tableWiegt->item(stage,3)->text().toDouble()*10+0.001);

        global_data::update_allTable[room].set_sensor[0].humi_center =
                uint16_t(co_Parenting[room]->tableWiegt->item(stage,4)->text().toDouble()*10+0.001);
        //满足条件，设置更新标志位
        if( assigemnt ){
           Send_update_Message(room);
           //global_data::Send_onine_flag[room] = true;
        }

    }


}

void home::Cobreeding_UpdateTable(uint8_t room, DataStatus status)
{
    int stage = global_data::execute_date[room].run_stage;

    //将数据填入表中
    UPDATE_ALL_TABLE_TYPEDEF data = global_data::update_allTable[room];
    System_parameter_change(data);

    if( stage < 0 || stage > 3)
        return;
        QString temp;
        //设置相应的更新标志位
        global_data::update_flag = true;
        if( status == __485_Serial ){
            if( global_data::on_line ){
                DB.AllTableToDB(global_data::update_allTable[room],global_data::execute_date[room]);
            }
        }
        else if( status == DataBase ){
            //global_data::room_flag[room] = false;
            if( global_data::Hear_flag ){
                update_All_table(global_data::update_allTable[room]);
            }

        }


//        uint8_t stage = global_data::stage[room];

        //设置参数表的值


            uint8_t column = co_Parenting[room]->tableWiegt->columnCount();

            for( uint8_t i = 0 ; i < column ; i++ ){
                QTableWidgetItem *item = co_Parenting[room]->tableWiegt->item(stage,i);
                if( item )
                    delete item;
            }

            QString year = QDate::currentDate().toString("yyyy/");
            QDate sta_date,end_date;
            sta_date = QDate::fromString(year+global_data::execute_date[room].sta_date,"yyyy/MM/dd");
            end_date = QDate::fromString(year+global_data::execute_date[room].end_date,"yyyy/MM/dd");

            co_Parenting[room]->tableWiegt->
                    setItem(stage,0,new
                            QTableWidgetItem(global_data::execute_date[room].sta_date));
            co_Parenting[room]->tableWiegt->
                    setItem(stage,1,new
                            QTableWidgetItem(global_data::execute_date[room].end_date));
            co_Parenting[room]->tableWiegt->
                    setItem(stage,2,new
                            QTableWidgetItem(QString::number(sta_date.daysTo(end_date)+1)));

            temp = QString::number((double)data.set_sensor[0].temp_center/10,'f',1);
            co_Parenting[room]->tableWiegt->
                    setItem(stage,3,new
                            QTableWidgetItem(temp));

            temp = QString::number((double)data.set_sensor[0].humi_center/10,'f',1);
            co_Parenting[room]->tableWiegt->
                    setItem(stage,4,new
                            QTableWidgetItem(temp));

            co_Parenting[room]->tableWiegt->item(stage,3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            co_Parenting[room]->tableWiegt->item(stage,4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

            for( uint8_t i = 0 ,tempIndex = 3; i < 8 ; i++ ,tempIndex++){
                temp = QTime::fromMSecsSinceStartOfDay(data.set_breath[i].time_sta*1000).toString("hh:mm");
                co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex-1,
                                                        new QTableWidgetItem(temp));

                temp = QString::number(data.set_breath[i].min_len) + "分钟";
                co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex,
                                                        new QTableWidgetItem(temp));
            }

            for( uint8_t i = 0 ,tempIndex = 11; i < 4 ; i++ ,tempIndex++){

                //感光
                if( i < 3 ){
                    temp =QTime::fromMSecsSinceStartOfDay(data.set_sensitive[i].time_sta *1000).toString("hh:mm");
                    co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex-1,
                                                            new QTableWidgetItem(temp));

                    temp = QTime::fromMSecsSinceStartOfDay(data.set_sensitive[i].time_end *1000).toString("hh:mm");
                    co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex,
                                                            new QTableWidgetItem(temp));
                }

                //消毒
                temp = QTime::fromMSecsSinceStartOfDay(data.set_sterilize[i].time_sta *1000).toString("hh:mm");
                co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex+5,
                                                                        new QTableWidgetItem(temp));
                temp = QString::number(data.set_sterilize[i].min_len) + "分钟";
                co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex+6,
                                                                        new QTableWidgetItem(temp));

                //光照
                if( i < 3 ){
                    temp =QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_sta *1000).toString("hh:mm");
                    co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex+13,
                                                            new QTableWidgetItem(temp));

                    temp = QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_end *1000).toString("hh:mm");
                    co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex+14,
                                                            new QTableWidgetItem(temp));
                }

            }
            co_Parenting[room]->tableWiegt->item(stage,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            co_Parenting[room]->tableWiegt->item(stage,3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            co_Parenting[room]->tableWiegt->item(stage,4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            co_Parenting[room]->DataTo_txt(stage);

        //传感器的校准值


             Sensor_diff_Refresh(data);
            sensor->Sensor_Save(room);


            system_Setting->Diff_Save(room);

            uint8_t rowCount = co_Parenting[room]->tableWiegt->rowCount();
            uint8_t colCount = co_Parenting[room]->tableWiegt->columnCount();

            for( uint8_t i = 0 ; i < rowCount ; i++ ){
                for( uint8_t j = 0; j < colCount ; j++){
                    co_Parenting[room]->tableWiegt->item(i,j)->setTextColor(Qt::black);
                    co_Parenting[room]->tableWiegt->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

}

void home::ModeChangeDeal(uint8_t id,bool status)
{

    switch (global_data::control_Mode[id] / 2) {
    case baozhong:
       Conservation_Renewal(id,status);
        break;
    case gongyu:
        Cobreeding_renewal(id,status);
        break;
    case cuiqing:
        Cui_Rejuvenate(id,status);
        break;
    default:
         global_data::control_Mode[id] = BAOZHONG_END;
         Conservation_Renewal(id,status);
         break;
    }

    if( global_data::execute_date[id].run_stage >= 0 ){
        uint8_t column = 0;
        switch ( system_Setting->pre_workStatus[id]/2 ) {
        case baozhong:
             column = seed[id]->tableWiegt->columnCount();
             for( uint8_t i = 0 ; i < column ; i++){
                 seed[id]->tableWiegt->item(global_data::execute_date[id].run_stage,i)->setBackgroundColor(QColor(227,237,249));
             }
            break;
        case gongyu:
            column = co_Parenting[id]->tableWiegt->columnCount();
            for( uint8_t i = 0 ; i < column ; i++){
                co_Parenting[id]->tableWiegt->item(global_data::execute_date[id].run_stage,i)->setBackgroundColor(QColor(227,237,249));
            }
            break;
        case cuiqing:
            column = Set_parment[id]->tableWidget->columnCount();
            for( uint8_t i = 0 ; i < column ; i++){
                Set_parment[id]->tableWidget->item(global_data::execute_date[id].run_stage,i)->setBackgroundColor(QColor(227,237,249));
            }
            break;
        default:
            break;
        }
        //system_Setting->pre_status = false;
        //global_data::execute_date[id].run_stage = -1;
    }

    Mode_Save(id);
}

void home::room_show(FROM_DB_Typedef data, uint8_t room )
{
    qDebug()<<room;

    if( room_Change != Write_Unlock )
        return ;
    if( data.status == ONLINE){
          Equipment[room]->setText(Set_font_Style("18pt"," ","00ff00","设备在线"));
          //心跳包计数
            global_data::heart_beat_count[room] = 0;
            co_Parenting[room]->setEnabled(true);
            Set_parment[room]->setEnabled(true);
            seed[room]->setEnabled(true);
            Sensor_show(room);
    }else{
          //qDebug()<<"删除传感器的ID"<<QString(global_data::update_allTable[room].id)
           //      <<"room房间号"<<room;
          Equipment[room]->setText(Set_font_Style("18pt"," ","ff0000","设备离线"));
          Del_Sensor(QString(global_data::id[room]));

          co_Parenting[room]->setEnabled(false);
          Set_parment[room]->setEnabled(false);
          seed[room]->setEnabled(false );
          Sensor_status[0]->setText(R"(<html><head/><body><p><span style=" font-size:16pt; font-weight:600; color:#ff0000;">传感器异常    </span></p></body></html>)");
    }

        QString str;
    switch (global_data::control_Mode[room] / 2) {
        case baozhong:
            str = "保种";
            break;
        case gongyu:
           str = "共育";
            break;

        case cuiqing:
            str = "催青";
            break;
        default:
            break;
        }
    //uint8_t temp = global_data::control_Mode[room];
    if( (global_data::control_Mode[room] %2) == 0 ){
        str += "运行";
        str = Set_font_Style("18pt","","00ff00",str.toUtf8().data());
    }
    else{
        str += "停止";
        str = Set_font_Style("18pt","","ff0000",str.toUtf8().data());
    }
    Mode[room]->setText(str);


    Heating[room]->setText(Set_font_Style("16pt"," ","ffffff",data.temp_center.toUtf8().data()));
    fall[room]->setText(Set_font_Style("16pt"," ","ffffff",data.humi_center.toUtf8().data()));
    show_relay(Heat_status[room],data.relay_status.relay.heat);
    show_relay(Moiste_status[room],data.relay_status.relay.humi);
    show_relay(Dehumi_status[room],data.relay_status.relay.dry);
    show_relay(Breathe_status[room],data.relay_status.relay.breath);
    show_relay(Light_status[room],data.relay_status.relay.light);
    show_relay(Wind_status[room],data.relay_status.relay.wind);
    show_relay(Disinfect_status[room],data.relay_status.relay.sterilize);
    show_relay(Sensitive_status[room],data.relay_status.relay.sensitive);
    show_air_relay(Air_status[room],data.air_status);

    Temperature[room]->setText(data.temp);
    Temperature[room]->setStyleSheet("font-size:50pt; font-weight:600; color:#ffbeaa;");

    Humidity[room]->setText(data.humi);
    Humidity[room]->setStyleSheet("font-size:50pt; font-weight:600; color:#ffbeaa;");
}

void home::Delete_Sensor_Line(uint8_t row)
{
    uint8_t column = sensor->sensor_table->columnCount();
    for( uint8_t i = 0 ; i < column ; i++ ){
        QTableWidgetItem  *item = sensor->sensor_table->item(row,i);
        if( item )
            delete item;
    }
}

void home::Ctronl_Drawer(bool isFlag)
{
    ui->widget_main->setVisible(isFlag);
    ui->widget_settting->setVisible(isFlag);
    ui->widget_chart->setVisible(isFlag);
    ui->widget_dataP->setVisible(isFlag);
    ui->widget_sensor->setVisible(isFlag);
    ui->widget_comminicat->setVisible(isFlag);
    ui->widget_manage->setVisible(isFlag);
    ui->widget_help->setVisible(isFlag);
    ui->widget_quit->setVisible(isFlag);
}

void home::closeEvent(QCloseEvent *event)
{


    QMessageBox message(QMessageBox::Warning,"退出!",
                                                     "确定要退出吗",QMessageBox::Yes|QMessageBox::No,NULL);
    if(message.exec() == QMessageBox::Yes){
        //this->close();
        event->accept();
        qDebug()<<"退出窗口";
    }
    else{
        event->ignore();
    }
}

void home::activeTray(QSystemTrayIcon::ActivationReason reason)
{
        if( reason == QSystemTrayIcon::DoubleClick){
            this->show();
        }
        else if( reason == QSystemTrayIcon::Context){
            m_menu->show();
        }

}

//bool home::nativeEvent(const QByteArray &eventType, void *message, long *result)
//{
//    qDebug()<<eventType.data()<<result;
//    MSG* msg = reinterpret_cast<MSG*>(message);
//        int msgType = msg->message;
//        if(msgType == WM_DEVICECHANGE)
//        {
//            PDEV_BROADCAST_HDR lpdb = (PDEV_BROADCAST_HDR)msg->lParam;
//            switch(msg->wParam)
//            {
//            case DBT_DEVICETYPESPECIFIC:
//            {
//                break;
//            }
//            case DBT_DEVICEARRIVAL://设备到来
//                if(lpdb -> dbch_devicetype == DBT_DEVTYP_PORT){

////                    QMessageBox box(QMessageBox::Information,"提示","设备已连接");
////                    box.exec();
//                    //serial->open(QIODevice::ReadWrite);
//                    //想要执行的逻辑
//                    system_Setting->ui->combox_port->clear();
//                    system_Setting->searchPort();
//                    system_Setting->ui->combox_port->addItems(system_Setting->portlist);
//                    system_Setting->on_btn_connect_clicked();
//                    communi->setText("串口" + serial->portName() + "连接");
//                    communi->setStyleSheet(" color:#ffffff;font: bold 16px");
//                    ui->statusBar->addWidget(communi);
//                }

//                break;
//            case DBT_DEVICEREMOVECOMPLETE://设备移除
//                if (lpdb -> dbch_devicetype == DBT_DEVTYP_PORT)
//                {
//                    QMessageBox box(QMessageBox::Warning,"提示","设备断开连接");
//                    box.exec();

//                    communi->setText("串口未连接");
//                    communi->setStyleSheet(" color:#ffffff;font: bold 16px");
//                    global_data::Hear_flag = false;

//                    system_Setting->Serial_flag = false;
//                    ui->statusBar->addWidget(communi);
//                    system_Setting->ui->btn_connect->setText("连接");
//                    system_Setting->ui->btn_connect->setStyleSheet("background-color: rgb(255, 85, 0);font-family:'楷体';font:bold 16pt;");
//                    serial->close();
//                    //逻辑部分

//                }
//                qDebug() << "DBT_DEVICEREMOVECOMPLETE" ;
//                break;
//            }
//        }
//        return false;
//}

//void home::timerEvent(QTimerEvent *event)
//{
//    qDebug()<< event->Drop;
//    static uint8_t count = 0;
//    static uint8_t time_count = 0;
//    if( !global_data::Hear_flag )
//        return ;


//        for( uint8_t i = 0 ; i < DEV ; i++ ){
//            count++;
//            if( count > DEV )
//                count = 0;

//                memcpy(Send_485_cmd.id,global_data::id[count],sizeof(Send_485_cmd.id));
//                Send_485_cmd.cmd = DEV_ALIVE_PACK;
//                Send_485_cmd.crc = CRC16_2_modbus((uint8_t *)&Send_485_cmd,sizeof(__485_CMD_Type)-2);
//                serial->write((char*)&Send_485_cmd,sizeof(__485_CMD_Type));
//                serial->waitForBytesWritten(1000);
//                break;
//            }

//        serial_oneFlag = 0;

//    //发送当前时间戳
//    time_count++;
//    if( time_count >= 5 ){
//        send_time.time_tamp = QDateTime::currentDateTime().toTime_t() + 8 * 3600;
//        send_time.crc = CRC16_2_modbus(( uint8_t *)&send_time,sizeof(send_time)-2);
//        sleep(50);
//        serial->write( ( char *)&send_time, sizeof(send_time));
//        serial->waitForBytesWritten(1000);
//        time_count = 0;
//    }
//}

void home::on_setting1_clicked()
{
    uint8_t id = 0;
    static int pre_stage = -1;
    if(  global_data::control_Mode[id] < 2 ){

        if( global_data::execute_date[id].run_stage >= 0 && global_data::execute_date[id].run_stage < 30){
             seed[id]->tableWiegt->setCurrentCell(global_data::execute_date[id].run_stage,QItemSelectionModel::Select);
             Seed_Table_color_change(id,pre_stage);
             pre_stage = global_data::execute_date[id].run_stage;
        }
        else{
            pre_stage = -1;
        }
        seed[id]->TITLE->setText(QString(global_data::id[id]) + + "保种参数设置");
        seed[id]->setWindowModality(Qt::ApplicationModal);
        seed[id]->showMaximized();

    }
    else if( global_data::control_Mode[id] >=2 &&
             global_data::control_Mode[id] < 4 ){
        if( global_data::execute_date[id].run_stage >= 0 && global_data::execute_date[id].run_stage < 4 ){
            co_Parenting[id]->tableWiegt->setCurrentCell(global_data::execute_date[id].run_stage,QItemSelectionModel::Select);
            Conservat_Table_color_change(id,pre_stage);
            pre_stage = global_data::execute_date[id].run_stage;
        }
        else{
            pre_stage = -1;
        }
        co_Parenting[id]->TITLE->setText(QString(global_data::id[id]) + + "共育参数设置");
        co_Parenting[id]->setWindowModality(Qt::ApplicationModal);
        co_Parenting[id]->showMaximized();

    }
    else if( global_data::control_Mode[id] >=4 &&
             global_data::control_Mode[id] < 6 ){

        if( global_data::execute_date[id].run_stage >= 0 && global_data::execute_date[id].run_stage < 12){
                  Set_parment[id]->tableWidget->setCurrentCell(global_data::execute_date[id].run_stage,QItemSelectionModel::Select);
                  Cui_Table_color_change(id,pre_stage);
                  pre_stage = global_data::execute_date[id].run_stage;
        }
        else{
            pre_stage = -1;
        }

        Set_parment[id]->TITLE->setText(QString(global_data::id[id]) + + "催青参数设置");
        Set_parment[id]->setWindowModality(Qt::ApplicationModal);

        //原本为最大显示
        Set_parment[id]->showMaximized();
    }

    table_LOCK[id] = Write_lock;


}

void home::timeUpdate(const QVariant info)
{
    FROM_DB_Typedef data;
    data = info.value<FROM_DB_Typedef>();
    int id = -1;
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( data.id.contains(global_data::id[i])){
            id = i+1;
            break;
        }
    }

    if( id == -1 )
        return ;
    //qDebug()<<"接收的id"<<data.id<<id;
    show_data[id-1].humi = data.humi;
    show_data[id - 1].temp = data.temp;

    for( uint8_t i = 0 ; i < 6 ; i++ ){
        show_data[id-1].signle_senser[i] = data.signle_senser[i];
    }


    if( data.status == ONLINE ){
         Interface_display(id,data,DataBase);
         show_data[id-1].status = ONLINE;
    }
    else{
        //qDebug()<<"data.status"<<data.status;
        Device_disengaged(show_data[id-1]);
    }


}


void home::update_table_485()
{
    static int updae_counts = 0;


    hear_beat++;
    ///离线设备
    QStringList offlineShow;
    for( uint8_t i = 0 ; i < ui->Abnormal_device->count() ; i++ ){
        offlineShow.append(ui->Abnormal_device->item(i)->text());
    }

    ///判断心跳包
    QStringList onlineshow;
    QList<int> record_num;
    for( uint8_t i = 0 ; i < onlineDev.size() ; i++ ){
        onlineDev[i].hear_count++;
        if( onlineDev[i].hear_count > 30 ){
            //onlineDev.removeAt(i);
            record_num.append(i);
            onlineDev[i].hear_count = 30;
            qDebug()<<onlineDev[i].devId<<"心跳包超时";
            continue;
        }
        onlineshow.append(onlineDev[i].devId + "  在线");
    }

//    for( uint8_t i = 0; i < record_num.size() ; i++ ){
//        onlineDev.removeOne(record_num.at(i));
//    }
    ui->Online_device->clear();
    qSort(onlineshow.begin(),onlineshow.end());
    ui->Online_device->addItems(onlineshow);





    QDate dTime = QDate::currentDate();
    ui->right_title->setText(dTime.toString("yyyy-MM-dd"));
    if( hear_beat > 9 )
    {
        global_data::heart_beat_count[0]++;
        hear_beat = 0;
    }

    if( global_data::heart_beat_count[0] > 6 )
    {
        Device_disengaged(show_data[0]);
        global_data::heart_beat_count[0] = 6;
    }
    static bool dev_cStatus = false;
    create_connect();
    if( global_data::mqtt_status )
    {
        if( (!changeRoom || dev_cStatus == false) &&
                DeviceChangeFlag == Write_Unlock)
        {
                if( pre_name != global_data::id[0] && dev_cStatus)
                {
                    mG_client->unsubscribe(Recive_Topic+pre_name);
                    qDebug()<<"unsubscribe"<<pre_name;
                    pre_name = QString(global_data::id[0]);

                }
                if( mqtt_subscribe(0))
                {
                    dev_cStatus = true;
                    changeRoom = true;
                }



        }
    }
    else
    {
        dev_cStatus = false;
    }

    updae_counts++;
    if( updae_counts >= 60){
        if( global_data::update_flag ){
                    //数控表发送
                     //Online_send();
        }
        updae_counts = 0;
        WriteTo_txt();



        if( global_data::on_line ){
            QFuture<void> f1;
            if( !DB.toDB()){
                f1 = QtConcurrent::run( [](){
                    DB.open("test1");
                });
                sleep(3);
                f1.cancel();
            }
            else{
                DeviceChangeFlag = Write_lock;
                QString area = Silkworm_Area->currentText();
                QString device = Silkworm_device->currentText();
                ui->Abnormal_device->clear();
                Abnormal_Widegt->clear();
                QStringList list =  DB.GetArea();
                if( !list.isEmpty()){
                    Silkworm_Area->clear();
                    Silkworm_Area->addItems(list);
                    Silkworm_Area->setCurrentText(area);
                    list.clear();
                    Silkworm_device->clear();
                    Silkworm_device->addItems(DB.GetDevice(Silkworm_Area->currentText()));
                    Silkworm_device->setCurrentText(device);
                }
                ui->Abnormal_device->clear();
                list = DB.Get_AbNormal_Device();
                if( !list.isEmpty() ){
                     Abnormal_Widegt->addItems(list);
                }
                DeviceChangeFlag = Write_Unlock;
            }

        }
    }

    //qDebug()<<"1号房间标志位"<<global_data::stage[0];


//    qDebug()<<mG_client->state();
    //网络锁，防止重复触发

//    QApplication::beep();
}

void home::Send_Heart()
{
    //qDebug()<<"我在发心跳包";
    if( !global_data::Hear_flag )
        return ;
    static uint8_t count = 0;
    static uint8_t time_count = 0;
    //qDebug()<<"阶段"<<global_data::stage[0];
        for( uint8_t i = 0 ; i < DEV ; i++ ){
            count++;
            if( count > DEV )
                count = 0;
//            if( global_data::stage[i] >= 0){
                memcpy(Send_485_cmd.id,global_data::id[count],sizeof(Send_485_cmd.id));
                Send_485_cmd.cmd = DEV_ALIVE_PACK;
                Send_485_cmd.crc = CRC16_2_modbus((uint8_t *)&Send_485_cmd,sizeof(__485_CMD_Type)-2);
                serial->write((char*)&Send_485_cmd,sizeof(__485_CMD_Type));
                //qDebug()<<"心跳包发送"<<QString(global_data::id[count])<<global_data::id[count]<<"DEV"<<count;
                break;
            }

        serial_oneFlag = 0;



    //发送当前时间戳
    time_count++;
    if( time_count >= 5 ){
        send_time.time_tamp = QDateTime::currentDateTime().toTime_t() + 8 * 3600;
        send_time.crc = CRC16_2_modbus(( uint8_t *)&send_time,sizeof(send_time)-2);
        sleep(10);
        serial->write( ( char *)&send_time, sizeof(send_time));
        time_count = 0;
    }

}

void home::update_SensorName(uint8_t room)
{
    int coulmn = sensor->sensor_table->rowCount();
    for( uint8_t i = 0 ; i < coulmn ; i++ ){
        if( room == sensor->sensor_table->item(i,4)->text().mid(3).toInt()){
            qDebug()<<"room"<<room;
            data_report->sensor_name->addItem(sensor->sensor_table->item(i,1)->text());
        }
    }
}

void home::RoomCtrol_Change(uint8_t room)
{
    if( room < DEV ){
        switch (global_data::control_Mode[room]) {
        case 0:
            qDebug()<<"催青";
            Cui_Rejuvenate(room,1);
            break;
        case 1:
            qDebug()<<"保种";
            Conservation_Renewal(room,1);
            break;
        case 2:
            qDebug()<<"共育";
            Cobreeding_renewal(room,1);
            break;
        default:
            break;
        }
    }

}

void home::Table_Change()
{
    uint8_t room = myT->DBT->room;

    qDebug()<<"网络房间参数表发生改变。。。。。。。。。。。"<<room;
//    if( global_data::execute_date[room%4].run_stage < 0)
//        return ;

    if( !global_data::Default_flag ){
        Default_Paremeter_Chagne();
    }

    switch (global_data::control_Mode[room%4]/2) {
    case cuiqing:
        //数据表的更新
        qDebug()<<"催青表格更新";
        if( room < 4){
            Cui_UpdateTable(room,Invalid);
        }
        else{
             Cui_UpdateTable(room%4,DataBase);
        }

        break;
    case baozhong:
        qDebug()<<"保种表格更新";
        if( room < 4 ){
            Conservation_UpdateTable(room,Invalid);
        }
        else{
            Conservation_UpdateTable(room%4,DataBase);
        }
        break;
    case gongyu:
        qDebug()<<"共育表格更新";
        if( room < 4 ){
            Cobreeding_UpdateTable(room,Invalid);
        }
        else{
            Cobreeding_UpdateTable(room%4,DataBase);
        }
    default:
        break;
    }
}

void home::table_unlock()
{
    qDebug()<<"table_inlock";
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        table_LOCK[i] = Write_Unlock;
    }
}

void home::on_pushButton_main_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

void home::on_pushButton_settting_clicked()
{
    //系统设置界面
    QInputDialog* inputDialog=new QInputDialog(this);
    inputDialog->setWindowTitle("提示");
    inputDialog->setLabelText("参数修改");
    inputDialog->setOkButtonText("确定");
    inputDialog->setToolTip("请输入密码");
    inputDialog->setCancelButtonText("取消");
    inputDialog->setTextEchoMode(QLineEdit::Password);
    bool ok;
    if(inputDialog->exec()==QDialog::Accepted){
        ok=true;
    }else{
        ok=false;
    }
    QString text=inputDialog->textValue();

    if( ok ){
        if(text == "888888"){
            //更新
            ui->stackedWidget->setCurrentIndex(2);
            system_Setting->ui->combox_port->clear();
            system_Setting->searchPort();
            system_Setting->ui->combox_port->addItems(system_Setting->portlist);

            QString port = serial->portName();
            if( !port.isEmpty() ){
                system_Setting->ui->combox_port->setCurrentText(port);
            }
            sensor_LOCK = Write_Unlock;
            system_LOCK  = Write_lock;
        }
        else{
            QMessageBox::warning(NULL, "警告", "密码输入错误", "确定");
        }
    }


    delete inputDialog;
}

void home::on_pushButton_chart_clicked()
{
    //历史曲线界面
    ui->stackedWidget->setCurrentIndex(3);
    charview->date_sta->setDate(QDate::currentDate());
    charview->date_end->setDate(QDate::currentDate().addDays(1));
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

void home::on_pushButton_dataP_clicked()
{
    //数据报表界面
    ui->stackedWidget->setCurrentIndex(4);
    QDate curDate = QDate::currentDate(),tempDate = global_data::sensor_Date;
    
    //控件内容清空
    data_report->sensor_date->clear();
    data_report->room_date->clear();
    data_report->sensor_name->clear();
    //data_report->room_name->clear();
    
    QString name,id;
    QStringList list;
    bool SensorStatus =true; //fasle
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        name =  QString(global_data::update_allTable[i].id);
        for( uint8_t j = 0 ; j < 6 ; j++ ){
            id = name +"-" + QString::number(j+1);

            if( show_data[i].signle_senser[j].senser_status == SENSER_OK ||
                    show_data[i].signle_senser[j].senser_status == SENSER_FAIL){
                    list.append(id);
                    SensorStatus = true;
            }
           
        }
    }

    data_report->sensor_name->addItems(list);
    list.clear();
    while(1){
        qDebug()<<"tempDate.daysTo(curDate)"<<tempDate.daysTo(curDate);
        if( tempDate.daysTo(curDate) >=0 ){
            list.append(tempDate.toString("yyyy年M月d日"));
        }
        else{
            break;
        }
        tempDate = tempDate.addDays(1);
    }

    if( SensorStatus ){
        data_report->sensor_date->addItems(list);
    }

    data_report->room_date->addItems(list);
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

void home::on_pushButton_sensor_clicked()
{
    //传感器界面
    QInputDialog* inputDialog=new QInputDialog(this);
    inputDialog->setWindowTitle("系统设置");
    inputDialog->setLabelText("参数修改");
    inputDialog->setToolTip("请输入密码");
    inputDialog->setOkButtonText("确定");
    inputDialog->setCancelButtonText("取消");
    inputDialog->setTextEchoMode(QLineEdit::Password);
    bool ok;
    if(inputDialog->exec()==QDialog::Accepted){
        ok=true;
    }else{
        ok=false;
    }
    QString text=inputDialog->textValue();

    if( ok ){
        if( text == "666666" ){
            ui->stackedWidget->setCurrentIndex(5);
            sensor_LOCK = Write_lock;
            system_LOCK  = Write_Unlock;
        }
        else{
            QMessageBox::warning(NULL, "警告", "密码输入错误", "确定");
        }
    }
}

void home::on_pushButton_comminicat_clicked()
{
    //通讯界面
    ui->stackedWidget->setCurrentIndex(6);
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

void home::on_pushButton_manage_clicked()
{
    //用户管理界面
    ui->stackedWidget->setCurrentIndex(7);
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

void home::on_pushButton_6_clicked()
{
    //帮助界面
    ui->stackedWidget->setCurrentIndex(8);
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

void home::on_pushButton_2_clicked()
{
//    if( global_data::on_line ){
//        if( !DB.toDB())
//            {
//                qDebug()<<"重新连接数据库";
//                DB.open("test1");
//            }
//    }

//        QMessageBox message(QMessageBox::Warning,"退出!",
//                                                         "确定要退出吗",QMessageBox::Yes|QMessageBox::No,NULL);
//        if(message.exec() == QMessageBox::Yes){

//        }
        this->close();


}

void home::on_com_area_currentIndexChanged(int index)
{
    if( global_data::on_line ){
        ui->com_device->clear();
        ui->com_device->addItems(DB.GetDevice(ui->com_area->itemText(index)));
    }
}

void home::on_com_device_currentIndexChanged(int index)
{
    if(index == -1 || DeviceChangeFlag == Write_lock)
        return ;
    pre_name = QString(global_data::id[0]);
    strncpy(global_data::id[0],ui->com_device->itemText(index).toUtf8().data(),20);

    if( pre_name == QString(global_data::id[0]) )
        return ;

    strcpy(global_data::update_allTable[0].id,global_data::id[0]);

    strcpy(global_data::work_way[0].id,global_data::id[0]);

    changeRoom = false;
    room_Change = Write_lock;
    Del_Sensor(pre_name);
    data_report->room_name->clear();
    charview->Device->clear();
    system_Setting->ui->Room_Choose->clear();

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        DEVICE_name[i]->setText(QString().sprintf(R"(<html><head/><body><p><span style=" font-size:18pt; font-weight:600;">%s</span></p></body></html>)",global_data::id[i]));
        data_report->room_name->addItem(QString(global_data::id[i]));
        charview->Device->addItem(QString(global_data::id[i]));
        system_Setting->ui->Room_Choose->addItem(QString(global_data::id[i]));
    }

    system_Setting->ui->Room_Choose->setCurrentIndex(0);
    //心跳包赋值
    for( uint8_t i = 0; i < DEV ; i++ ){
         global_data::heart_beat_count[i] = 0;
         show_data[i].status = OFFLINE;
         global_data::room_flag[i] = true;

         //id赋值
         show_data[i].id = QString(global_data::id[i]);

    }

    //上电，传感器默认断开
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        for( uint8_t j = 0 ; j < 6 ; j++ ){
            show_data[i].signle_senser[j].senser_status = SENSER_DIS_CON;
        }
        qDebug()<<"阶段赋值"<<i;
    }
    room_Change = Write_Unlock;
    Device_disengaged(show_data[0]);
    Sensor_status[0]->setText(R"(<html><head/><body><p><span style=" font-size:16pt; font-weight:600; color:#ff0000;">传感器异常    </span></p></body></html>)");
}

void home::topicMessageReceived(const QByteArray &data, const QMqttTopicName &topic)
{
    Q_UNUSED(topic);
    uint16_t crc ;
    bool ok;

    const char *rcv = data.data();


    uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
    uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);
//    qDebug()<<"date"<<data.toHex()
//           <<"head"<<head<<"tail"<<tail;

    if( TO_APP_HEAD == head && TO_APP_TAIL == tail){

        FROM_MCU_Typedef from_mcu;



        memcpy((char *)&from_mcu,rcv,sizeof(FROM_MCU_Typedef));

        crc = CRC16_2_modbus((uint8_t*)&from_mcu,sizeof(FROM_MCU_Typedef)-2);

        if( from_mcu.crc == crc ) {
            qDebug()<<"接收的id"<<QString(from_mcu.id);
            bool flag = false;
            for( uint8_t i = 0 ; i < onlineDev.size() ; i++ ){
                if( onlineDev[i].devId.contains(QString(from_mcu.id))){
                    onlineDev[i].hear_count = 0;
                    flag = true;
                    break;
                }
            }

            if( !flag ){
                EQUIP_MONITOR_TYPE temp = {QString(from_mcu.id),0};
                onlineDev.append(temp);
            }

            if( QString(from_mcu.id) != QString(global_data::id[0]))
                return;
           int pos  = 0;//ID_lookup(QString(from_mcu.id));

            if( pos < 0 )
                return ;
            if( pos >= 0 && pos < 4){

                    //global_data::Mutual_exclusion[pos] = Invalid;
                    global_data::heart_beat_count[0]  = 0;
                    hear_beat = 0;
                    show_data[pos].status = ONLINE;

                    show_data[pos].temp = QString::number((double)from_mcu.temp/10,'f',1);
                    show_data[pos].humi = QString::number((double)from_mcu.humi/10,'f',1);

                    show_data[pos].temp_center = QString::number((double)from_mcu.now_sensor.temp_center/10,'f',1);
                    show_data[pos].humi_center = QString::number((double)from_mcu.now_sensor.humi_center/10,'f',1);

                    for( uint8_t i = 0 ; i < Sensor_Number ; i++ ){
                        show_data[pos].signle_senser[i] = from_mcu.signle_senser[i];
                    }

                    show_data[pos].air_status = from_mcu.air_status;

                    show_data[pos].relay_status = from_mcu.relay_status;

                }
                //在主界面显示
                Interface_display(pos + 1,show_data[pos],Invalid);
            }
        }
    else if( head == TABLE_HEAD && tail == TABLE_TAIL ){
        UPDATE_ALL_TABLE_TYPEDEF UpdateTable;

        memcpy((char *)&UpdateTable,rcv,sizeof(UPDATE_ALL_TABLE_TYPEDEF));
        crc = CRC16_2_modbus((uint8_t*)&UpdateTable,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);

        if( crc == UpdateTable.crc ){

            if( !global_data::Default_flag ){
                Default_Paremeter_Chagne();
            }
            if( QString(UpdateTable.id) != QString(global_data::id[0]))
                return;
            int pos = 1 ;//QString(UpdateTable.id).right(3).toInt();


            //pos = ID_lookup(QString(UpdateTable.id)) + 1;
            if( pos <= 0 || global_data::update_allTable[pos-1].crc == UpdateTable.crc)
                return ;


            if( pos >0 && pos <= DEV ){
                global_data::update_allTable[pos-1] = UpdateTable;

                //将这个参数更新到参数表上
                switch (global_data::control_Mode[pos-1]/2) {
                case cuiqing:
                    //数据表的更新
                    qDebug()<<"催青";
                    Cui_UpdateTable(pos-1,Invalid);
                    break;
                case baozhong:
                    qDebug()<<"保种";
                    Conservation_UpdateTable(pos-1,Invalid);
                    break;
                case gongyu:
                    qDebug()<<"共育";
                    Cobreeding_UpdateTable(pos-1,Invalid);
                default:
                    break;
                }
                //并且上发到数据库
            }
        }

    }
    else if( head == GET_DEV_STATUS_HEAD && tail == GET_DEV_STATUS_TAIL ){
        WORK_WAY_TYEP work_way;
        memcpy((char*)&work_way,rcv,sizeof(WORK_WAY_TYEP));
        crc = CRC16_2_modbus((uint8_t*)&work_way,sizeof(WORK_WAY_TYEP)-2);
        if( work_way.crc == crc ){
               global_data::mode_rcv_flag = true;
//               int id = -1;//QString(work_way.id).right(3).toInt()-1;
//               id = ID_lookup(QString(work_way.id));
//               if( id < 0 )
//                   return ;
               global_data::control_Mode[0] = work_way.work_status;
               global_data::work_way[0].reasure_count = work_way.reasure_count;
               global_data::Mode_Lock[0] = Write_lock;
               ModeChangeDeal(0,0);
        }

    }
}

void home::on_Online_device_itemDoubleClicked(QListWidgetItem *item)
{

    QString id = item->text().split(" ")[0].remove(QRegExp("\\s"));//获取点击的ID
    if( global_data::on_line ){
        QStringList listArea = DB.GetArea();
        if( listArea.contains(id.left(10))){
            QStringList listDevice = DB.GetDevice(id.left(10));
            if( listDevice.contains(id)){
                ui->com_area->setCurrentText(id.left(10));
                ui->com_device->setCurrentText(id);
            }else{
                QMessageBox::warning(NULL,"警告","数据库没有此设备");
            }
        }else{
            QMessageBox::warning(NULL,"警告","数据库没有此设备");
        }
    }else{
        QMessageBox::warning(NULL,"警告⚠","失去网络连接");
    }

}

void home::on_pushButton_main_title_clicked()
{
    if( isWidget.isMainWiedet == false )
    {
        isWidget.isMainWiedet = true;
        ui->widget_main->setVisible(true);
        ui->pushButton_main_title->setIcon(QIcon(MAIN_DOWN_ARROW));
    }
    else{
        isWidget.isMainWiedet = false;
        ui->widget_main->setVisible(false);
        ui->pushButton_main_title->setIcon(QIcon(MAIN_RIGHT_ARROW));
    }
}

void home::on_pushButton_setttingtitle_clicked()
{
    if( isWidget.isSetWiedet == false )
    {
        isWidget.isSetWiedet = true;
        ui->widget_settting->setVisible(true);
        ui->pushButton_setttingtitle->setIcon(QIcon(MAIN_DOWN_ARROW));
    }
    else{
        isWidget.isSetWiedet = false;
        ui->widget_settting->setVisible(false);
        ui->pushButton_setttingtitle->setIcon(QIcon(MAIN_RIGHT_ARROW));
    }
}

void home::on_pushButton_chart_title_clicked()
{
    if( isWidget.isChartWiedet == false )
    {
        isWidget.isChartWiedet = true;
        ui->widget_chart->setVisible(true);
        ui->pushButton_chart_title->setIcon(QIcon(MAIN_DOWN_ARROW));
    }
    else{
        isWidget.isChartWiedet = false;
        ui->widget_chart->setVisible(false);
        ui->pushButton_chart_title->setIcon(QIcon(MAIN_RIGHT_ARROW));
    }
}

void home::on_pushButton_dataP_title_clicked()
{
    if( isWidget.isDataPWiedet == false )
    {
        isWidget.isDataPWiedet = true;
        ui->widget_dataP->setVisible(true);
        ui->pushButton_dataP_title->setIcon(QIcon(MAIN_DOWN_ARROW));
    }
    else{
        isWidget.isDataPWiedet = false;
        ui->widget_dataP->setVisible(false);
        ui->pushButton_dataP_title->setIcon(QIcon(MAIN_RIGHT_ARROW));
    }
}

void home::on_pushButton_sensor_title_clicked()
{
    if( isWidget.isSensorPWiedet == false )
    {
        isWidget.isSensorPWiedet = true;
        ui->widget_sensor->setVisible(true);
        ui->pushButton_sensor_title->setIcon(QIcon(MAIN_DOWN_ARROW));
    }
    else{
        isWidget.isSensorPWiedet = false;
        ui->widget_sensor->setVisible(false);
        ui->pushButton_sensor_title->setIcon(QIcon(MAIN_RIGHT_ARROW));
    }
}

void home::on_pushButton_comminicat_title_clicked()
{
    if( isWidget.isCommunicationWiedet == false )
    {
        isWidget.isCommunicationWiedet = true;
        ui->widget_comminicat->setVisible(true);
        ui->pushButton_comminicat_title->setIcon(QIcon(MAIN_DOWN_ARROW));
    }
    else{
        isWidget.isCommunicationWiedet = false;
        ui->widget_comminicat->setVisible(false);
        ui->pushButton_comminicat_title->setIcon(QIcon(MAIN_RIGHT_ARROW));
    }
}

void home::on_pushButton_manage_title_clicked()
{
    if( isWidget.isUserWiedet == false )
    {
        isWidget.isUserWiedet = true;
        ui->widget_manage->setVisible(true);
        ui->pushButton_manage_title->setIcon(QIcon(MAIN_DOWN_ARROW));
    }
    else{
        isWidget.isUserWiedet = false;
        ui->widget_manage->setVisible(false);
        ui->pushButton_manage_title->setIcon(QIcon(MAIN_RIGHT_ARROW));
    }
}

void home::on_pushButton_help_title_clicked()
{
    if( isWidget.isHelpWiedet == false )
    {
        isWidget.isHelpWiedet = true;
        ui->widget_help->setVisible(true);
        ui->pushButton_help_title->setIcon(QIcon(MAIN_DOWN_ARROW));
    }
    else{
        isWidget.isHelpWiedet = false;
        ui->widget_help->setVisible(false);
        ui->pushButton_help_title->setIcon(QIcon(MAIN_RIGHT_ARROW));
    }
}

void home::on_pushButton_quit_title_clicked()
{
    if( isWidget.isQuitWiedet == false )
    {
        isWidget.isQuitWiedet = true;
        ui->widget_quit->setVisible(true);
        ui->pushButton_quit_title->setIcon(QIcon(MAIN_DOWN_ARROW));
    }
    else{
        isWidget.isQuitWiedet = false;
        ui->widget_quit->setVisible(false);
        ui->pushButton_quit_title->setIcon(QIcon(MAIN_RIGHT_ARROW));
    }
}
