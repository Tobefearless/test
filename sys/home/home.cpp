#include "home/home.h"
#include "ui_homer.h"
#include "QDesktopWidget"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#pragma GCC diagnostic ignored "-Wwrite-strings"

home::home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
        ui->setupUi(this);

        /*
            定时器创建:
            table_timer:更新参数表定时器
            Heart_timer:发送心跳包定时器
        */
        table_timer = new QTimer(this);
        Heart_timer = new QTimer(this);
        /*
            创建线程
        */
        myT = new Mythread();

        thread = new QThread(this);
        thread1 = new QThread(this);

        myT->moveToThread(thread);

        ModeT =new Mythread();
        modeThread = new QThread(this);
        ModeT->moveToThread(modeThread);
        serialT = new SerialThread(this);

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
        QString str = "                          四川省农业科学院蚕业研究所                                     地址：四川省南充市顺庆区合众街52号                              联系电话：19938536220 19938535370  ";
        Qlabel->setStyleSheet(" color:#ffffff;font: bold 16px");
        Qlabel->setText(str);
        ui->statusBar->setStyleSheet
                (QString("QStatusBar::item{border: "
                                "0px; color:(255,255,255)}")); // 设置不显示label的边框
        ui->statusBar->addPermanentWidget(Qlabel);
        ui->statusBar->setSizeGripEnabled(false); //不显示右边的大小控制点

        communi->setText("串口未连接");
        communi->setStyleSheet(" color:#ffffff;font: bold 16px");
        ui->statusBar->addWidget(communi);


        this->setWindowTitle("催青管理系统");                 //设置窗口标题
        this->setWindowIcon(QIcon(":/img/登录主图.jpg"));        //设置窗口图片


        /*
         * 设置图片全屏显示且自动适应屏幕大小

         */
        QRect screenSize;    //设备屏幕（设备分辨率）

        screenSize = QApplication::desktop()->screenGeometry();

        int dev_width = screenSize.width();    //屏幕宽
        int dev_height = screenSize.height();    //屏幕高
#if 1
         setAutoFillBackground(true);
         QPixmap back_icon(":/img/Dark_Blue.png");//加载窗口图片
         QPalette palette;
         palette.setBrush(this->backgroundRole(),
                          QBrush(back_icon.scaled(dev_width,dev_height).
                                 scaled(dev_width,dev_height,
                                        Qt::IgnoreAspectRatio,
                                        Qt::SmoothTransformation)));
         this->setPalette(palette);


         /*
            *信号与槽连接
        */
        connect(serialT,&SerialThread::Serial_data,
                this,&home::__485_rcv_data);     //串口接收

        connect(mG_client, &QMqttClient::messageReceived,
                this,&home::topicMessageReceived);//mqtt消息接收

        connect(myT->DBT,SIGNAL(send_ChangeTable()),
                this,SLOT(Table_Change()));//数据库更新表格参数


         connect(ModeT->DBT,&mysql::send_ModeChange,[=](){
             ModeChangeDeal(ModeT->DBT->room,0);
         });//房间模式发生改变


         connect(table_timer,SIGNAL(timeout()),
                 this,SLOT(update_table_485()));//把表更新到单片机的定时器

         connect(Heart_timer,SIGNAL(timeout()),
                 this,SLOT(Send_Heart()));      //发送心跳包的定时器


         for( uint8_t i = 0 ; i < DEV ; i++ ){
             connect(Set_parment[i],SIGNAL(Table_UnCLOCK()),this,SLOT(table_unlock()));
             connect(seed[i],SIGNAL(Table_UnCLOCK()),this,SLOT(table_unlock()));
             connect(co_Parenting[i],SIGNAL(Table_UnCLOCK()),this,SLOT(table_unlock()));
         }  //解开表格锁

         for( uint8_t i = 0 ; i < DEV ; i++ ){
             connect(Device[i]->Setting,&QPushButton::clicked,[=](){
                 Setting_onclick(i);
             });
         }//点击房间设置

         connect(system_Setting,&System_Setting::Contral_adjust,[&](uint8_t room){
             ModeChangeDeal(room,0);
         });


         connect(this,&home::startThread,myT,&Mythread::myTimeout);//启动线程
         connect(this,&home::startThread,ModeT,&Mythread::Pattern_query);

         connect(mG_client,&QMqttClient::stateChanged,[=](){

             qDebug()<<"MQtt状态已进改变"<<mG_client->state();
         });

          //stackWidget界面添加

          ui->stackedWidget->addWidget(system_Setting);
          ui->stackedWidget->addWidget(charview);
          ui->stackedWidget->addWidget(data_report);
          ui->stackedWidget->addWidget(sensor);
          ui->stackedWidget->addWidget(comms_indicate);
          ui->stackedWidget->addWidget(user_management);
          ui->stackedWidget->addWidget(&help);

          ui->toolBox->setCurrentIndex(8);//设置初始显示页面

          ui->right_title->setText(QDate::currentDate().
                                   toString("yyyy-MM-dd"));//时间
          qDebug()<<"asdasd"<<sizeof(WORK_WAY_TYEP);
          //System_tray();//系统托盘
#endif
}

home::~home()
{
    if( thread->isRunning() == true ){
        thread->requestInterruption();
        thread->quit();
        thread->wait();
    }

    if( thread1->isRunning() == true ){
        thread1->requestInterruption();
        thread1->quit();
        thread1->wait();
    }
    if( modeThread->isRunning() == true ){
        modeThread->requestInterruption();
        modeThread->quit();
        modeThread->wait();
    }

    delete sensor;
    delete serialT;

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
    delete mG_client;
    delete ui;
}

/**
   *@brief   创建一个mqtt连接
   *@note    登录后开始自动连接mqtt服务器，会在table_timer,定时
            去调用这个函数，让mqtt服务器一直保持连接
   *@retval  返回mqtt的状态，true:mqtt已连接,false:mqtt为连接
*/
bool home::create_connect()
{
    if(mG_client->state() == QMqttClient::Disconnected){
        //mG_client->setClientId("12345678");   //设置连接ID
        mG_client->setHostname("1.14.26.239");//设置服务器名字(地址)
        //m_client->setHostname("47.96.154.99");

        mG_client->setPort(1883);           //设置连接端口
        mG_client->setUsername("admin");    //设置用户名
        mG_client->setPassword("czy123456");//设置密码
        mG_client->setWillQoS(2);           //设置消息质量

        //重新收到离线期间错过的消息的设备
        mG_client->setCleanSession(false);  //设置接收离线消息
        mG_client->setKeepAlive(30);        //设置心跳包保持的间隔
        mG_client->setAutoKeepAlive(true);  //设置自动发送心跳包
        mG_client->autoKeepAliveChanged(true);

        mG_client->connectToHost();         //连接主机(服务器)
        global_data::mqtt_status = false;
        return false;
    }
    else{
        global_data::mqtt_status = true;
        return true;
    }
}


/**
   *@brief   订阅主题
   *@note    订阅mqtt主题，让其接收由主题发送来的消息
   *@param   id  想要订阅的id(设备号)
   *@retval  返回mqtt的状态，true:mqtt已连接,false:mqtt为连接
*/
bool home::mqtt_subscribe(uint8_t id)
{
    QString topic = "dev/recive/" + QString(global_data::id[id]);

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


/**
   *@brief   将数据写入本地的TXT文本中
   *@note    这里主要写入的数据为平均的温湿度数据
*/

void home::WriteTo_txt()
{
    qDebug()<<"正在写数据";
#if 1
    for( uint8_t i = 0 ; i < DEV ; i++ ){
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

/**
   *@brief   将数据写入本地的TXT文本中
   *@note    这里主要写入的数据为传感器数据
*/
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


/**
   *@brief   创建文件夹
   *@note    这是一个递归创建
   *@param   path    需要创建文件夹的路径
   *@retval  返回创建成功的路径
*/
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

/**
   *@brief   继电器状态控件的显示
   *@note    对单片机的继电器状态的显示
   *@param   label   需要显示的控件
   *@param   status  设置需要显示的状态
*/

void home::show_relay(QLabel *label, bool status)
{
       if(status){
           label->setText(R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_REALY) + R"(; color:#00ff00;">开启</span></p></body></html>)");
       }else{
           label->setText(R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_REALY) + R"(; color:#ff0000;">关闭</span></p></body></html>)");
       }
}

/**
   *@brief   空调状态控件的显示
   *@note    对空调状态的显示
   *@param   label   需要显示的控件
   *@param   status  设置需要显示的状态
*/
void home::show_air_relay(QLabel *label, uint8_t status)
{
    switch (status) {
    case AIR_CLOSE:
        label->setText(R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_REALY) + R"(; color:#ff0000;">关闭</span></p></body></html>)");
        break;
    case AIR_HEAT:
        label->setText(R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_REALY) + R"(; color:#00ff00;">制热</span></p></body></html>)");
        break;
    case AIR_COLD:
        label->setText(R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_REALY) + R"(; color:#00ff00;">制冷</span></p></body></html>)");
        break;
    default:
        label->setText(R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_REALY) + R"(; color:#ff0000;">关闭</span></p></body></html>)");
        break;
    }
}

/**
   *@brief   在线发送参数表
   *@note    用与连接网络或是连接串口的参数表更新
*/
void home::Online_send()
{
    qDebug()<<"房间更新";
    uint8_t __485_count = 0,__date_count = 0;
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        qDebug()<<"show_data[i].status"<<

                  show_data[i].status<<"i"<<i<<"global_data::execute_date[i].run_stage"
               <<global_data::execute_date[i].run_stage;
        if( show_data[i].status == ONLINE && (global_data::execute_date[i].run_stage >= 0)){
            bool status = false;
            if(false == global_data::room_flag[i] && global_data::Hear_flag ){
                qDebug()<<"串口发送";
                status = update_All_table(temporary_send[i]);
                if( status )
                    global_data::room_flag[i] = true;
            }


            qDebug()<<"发送前global_data::Send_onine_flag[i]"<<global_data::Send_onine_flag[i]<<i;
           if( !global_data::Send_onine_flag[i]){

               temporary_send[i].crc = CRC16_2_modbus((uint8_t*)&temporary_send[i]
                                                                  ,sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);

               //有网发送
               if( global_data::on_line){
                   bool temp;
                   if( status )
                        temp = DB.AllTableToDB(temporary_send[i],global_data::execute_date[i]);
                   else
                        temp = DB.AllTableToDB(temporary_send[i],global_data::execute_date[i],"1","1");

                   if( !temp ){
                       DB.open("test1");
                   }
                   else{
                          global_data::Send_onine_flag[i] = true;
                   }

               }



           }
        }
    }

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( global_data::room_flag[i]){
            __485_count++;
        }

        if( global_data::Send_onine_flag[i] ){
            __date_count++;
        }
    }

    if( __485_count >= DEV && __date_count >=  DEV){
        global_data::update_flag = 0;
    }

}


/**
 * @brief home::State_assignment
 * @note  用于初始状态的一些赋值
 */
void home::State_assignment()
{

    //创建显示窗口
    QWidget *pwidegt = new QWidget(this);
    glayout = new QGridLayout();
    QLabel *label[DEV / Ui_Alignment ];
    for( uint8_t i = 0 ; i < DEV / Ui_Alignment ; i++ )
    {
        label[i] = new QLabel(this);
        label[i]->setMinimumHeight(75);
    }
    int k = 0,j = 0,m = 0;
    for( uint8_t i = 0 ; i < DEV ; i++ )
    {
        Device[i] = new Room_style(this);
        Device[i]->setFixedSize(641,721);

        //几个为一行
        if( (i) % Ui_Alignment == 0 && i != 0){
            k++;
            j = 0;
            if( i != 0 ){
                glayout->addWidget(label[m++],k,1);
                k++;
            }
            glayout->addWidget(Device[i],k,2*j+1);
        }
        else
        {
            glayout->addWidget(Device[i],k,2*j+1);
        }
        j++;
    }
    ++k;

    glayout->setVerticalSpacing(10);
    glayout->setHorizontalSpacing(10);
    pwidegt->setLayout(glayout);
    ui->scrollArea->setWidget(pwidegt);

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        Device[i]->Device_Name->setText(
                    R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_DEVICENAME) +
                    QString().sprintf(R"(; font-weight:600;">%s</span></p></body></html>)",global_data::id[i]));
        data_report->room_name->addItem(QString(global_data::id[i]));
        charview->Device->addItem(QString(global_data::id[i]));
        system_Setting->ui->Room_Choose->addItem(QString(global_data::id[i]));
    }

    system_Setting->ui->Room_Choose->setCurrentIndex(0);

    for( uint8_t i = 0; i < DEV ; i++ ){
         global_data::heart_beat_count[i] = 0;  //心跳包赋值
         show_data[i].status = OFFLINE;
         global_data::room_flag[i] = true;

         show_data[i].id = QString(global_data::id[i]);//id赋值
         system_Setting->ui->Room_Choose->setCurrentIndex((DEV-1)-i);

         co_Parenting[i]->setEnabled(false);
         Set_parment[i]->setEnabled(false);
         seed[i]->setEnabled(false );
    }


        global_data::update_flag = 0;//参数更新标志

        /*
         * 时间戳头尾赋值
        */
        send_time.head = TIME_TAMP_HEAD ;
        send_time.tail = TIME_TAMP_TAIL;

        Send_485_cmd.head = _485_CMD_HEAD ;
        Send_485_cmd.tail = _485_CMD_TAIL ;


        for( uint8_t i = 0 ; i < DEV ; i++ ){
            for( uint8_t j = 0 ; j < 6 ; j++ ){
                show_data[i].signle_senser[j].senser_status = SENSER_DIS_CON;  //上电，传感器默认断开
            }
        }

        for( uint8_t i = 0 ; i < DEV ; i++ ){

            table_LOCK[i] = Write_Unlock;//加锁

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

        sensor_LOCK = Write_Unlock;
        system_LOCK = Write_Unlock;

}

/**
 * @brief home::Interface_display
 * @note  用于主界面的房间参数及状态显示
 * @param room  需要显示的房间(第几个房间)
 * @param data  需要显示的数据
 * @param method 数据来源:
 *                      DataBase    0, 数据库
                        __485_Seria 1, 串口
                        Invalid     2  mqtt
 */
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
/**
 * @brief home::__485_CMD_Del
 * @note:命令处理
 * @param cmd   需要处理的命令
 * @param id    房间号
 */
void home::__485_CMD_Del(__485_CMD_Type cmd,uint8_t id)
{

    switch (cmd.cmd) {  
    case WIFI_CON_OK://wifi连接成功
        system_Setting->ui->btn_Wconnect->setText("已连接");
        system_Setting->ui->btn_Wconnect->
                setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        //设置样式表
    case WIFI_CON_FAIL://连接失败
        system_Setting->ui->btn_Wconnect->setText("连接");
        system_Setting->ui->btn_Wconnect->setStyleSheet("background-color: rgb(255, 85, 0);font-family:'楷体';font:bold 16pt;");
        QMessageBox::warning(NULL, "WIFI连接", "WIFI连接失败", "确定");
        break;

    case _4G_CON_OK://4G连接成功
        system_Setting->ui->btn_Wconnect->setText("已连接");
        system_Setting->ui->btn_Wconnect->setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        break;

    case _4G_CON_FAIL://4G连接失败
        system_Setting->ui->btn_Wconnect->setText("连接");
        system_Setting->ui->btn_Wconnect->setStyleSheet("background-color: rgb(255, 85, 0);font-family:'楷体';font:bold 16pt;");
        QMessageBox::warning(NULL, "4G连接", "连接失败", "确定");
        break;

    case AIR_HEAT_LEARN_END://加热学习完成
        system_Setting->room_setting[id].Air.heat = "学习完成";
        system_Setting->ui->Heat_Learn->setText("学习完成");
        system_Setting->ui->Heat_Learn->setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        break;

    case AIR_CLOD_LEARN_END://制冷学习完成
        system_Setting->room_setting[id].Air.cold = "学习完成";
        system_Setting->ui->Cold_Learn->setText("学习完成");
        system_Setting->ui->Cold_Learn->setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        break;

    case AIR_CLOSE_LEARN_END://关闭学习完成
        qDebug()<<"关闭学习完成";
        system_Setting->room_setting[id].Air.clsoe = "学习完成";
        system_Setting->ui->Close_Learn->setText("学习完成");
        system_Setting->ui->Close_Learn->setStyleSheet("background-color: rgb(85, 170, 0);font-family:'楷体';font:bold 16pt;");
        break;

    case DEV_ALIVE_PACK_BACK://设备端回应心跳包
        global_data::rcv_ok = true;
        break;

    default:
        break;
    }
}

/**
 * @brief home::Device_disengaged
 * @note  房间离线，参数赋值
 * @param data     需要赋值的数据结构体
 */
void home::Device_disengaged(FROM_DB_Typedef &data)
{
   int room = - 1;
   for( uint8_t i = 0 ; i < DEV ; i++ ){
       if( !QString::compare(data.id,global_data::id[i])){
           room = i+1;
           break;
       }
   }

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

/**
 * @brief home::setLED
 * @note  设置label变成圆形的led灯的形式
 * @param label 需要设置的label控件的地址
 * @param color 需要设置的颜色
 * @param size  显示圆形的大小
 */
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


/**
 * @brief home::Set_font_Style
 * @note  设置文字样式
 * @param fontsize  文字的大小
 * @param weight    权重
 * @param color     颜色
 * @param data      数据
 * @return          返回生成的html的字符串
 */
QString home::Set_font_Style(char *fontsize,char *weight,char *color,char *data)
{
    QString result =
            QString().sprintf(R"(<html><head/><body><p><span style=" font-size:%s; %s color:#%s;">%s</span></p></body></html>)",fontsize,weight,color,data);
    return result;
}

/**
 * @brief home::Sensor_show
 * @note  传感器数据显示
 * @param room  需要显示的房间
 */
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
                QTableWidgetItem *item = sensor->sensor_table->item(j,6);
                    if( item )
                        delete item;

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
        Device[room]->Sensor_status->setText(R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_SENSOR) + R"(; font-weight:600; color:#00ff00;">传感器正常 </span></p></body></html>)");
    }
    else
    {
        Device[room]->Sensor_status->setText(R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_SENSOR) + R"(; font-weight:600; color:#ff0000;">传感器异常 </span></p></body></html>)");
    }

    for( uint8_t i = 0 ; i < rowCount ; i++ ){
//        QTableWidgetItem *item = sensor->sensor_table->item(i,0);
//        if( item )
//            delete item;
        sensor->sensor_table->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
    }
}


/**
 * @brief home::Sensor_Status_Setting
 * @note  传感器状态赋值
 * @param room  那个房间
 * @param temp  传感器温度
 * @param humi  传感器湿度
 * @param tempAdjust    温度校准值
 * @param humiAdjust    湿度校准值
 * @param rowStatus     温湿度的校准值是否改变的标志位
 *                      true:改变
 *                      false:未改变
 */
void home::Sensor_Status_Setting(uint8_t room,double temp,double humi,
                                 QString tempAdjust,QString humiAdjust,bool rowStatus)
{
//       uint8_t array[3] = {2,3,6};
//       for( uint8_t m = 0 ; m < 3 ; m++ ){
//               QTableWidgetItem  *item = sensor->sensor_table->item(room,array[m]);
//               if( item )
//                    delete item;
//       }

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

/**
 * @brief home::Del_Sensor
 * @note  删除已经离线的传感器
 * @param id    需要删除的Id
 */
void home::Del_Sensor(QString id)
{
    uint8_t rowCount;

    bool status = false;
    for( uint8_t i = 0 ; i < Sensor_Number ; i++ ){
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

/**
 * @brief home::Set_stage
 * @note  设置日期的执行阶段
 * @param room  房间号
 * @param stage 阶段
 */
void home::Set_stage(uint8_t room, int stage)
{
    global_data::execute_date[room].run_stage = stage;
}


/**
 * @brief home::Device_off
 * @note  设备工作模式改变
 * @param room  房间号
 * @param way   改变的模式
 * @return      true:模式改变成功
 *              false:模式改变失败
 */
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

/**
 * @brief home::Send_update_Message
 * @note  发送每日更新的参数表的信息
 * @param room  房间号
 */
void home::Send_update_Message(uint8_t room)
{
    bool status = false;
    if( global_data::Hear_flag ){
       update_All_table(global_data::update_allTable[room]);
       status = update_All_table(global_data::update_allTable[room]);
    }

    QFuture<void> f1;
    if( global_data::on_line ){
        bool flag = false;
        if( global_data::mqtt_status )
             status |= Mqtt_publish(room,global_data::update_allTable[room]);

        f1 = QtConcurrent::run([&flag,room]{
            flag = DB.AllTableToDB(QString(global_data::id[room]),global_data::execute_date[room]);
        });

        sleep(3 * 1000);
        f1.cancel();
        if( !flag ){
            DB.open("test1");
        }
    }
    if( status )
    {
        global_data::Send_onine_flag[room] = true;
        send_Failure_Status[room] = 0;
    }
    else
    {
        send_Failure_Status[room]++;
    }


}

/**
 * @brief home::List_Sensor
 * @note  获取传感器的校准值
 * @param room  房间号
 * @param i     没有用
 */
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
        for( uint8_t m = 0 ; m < Sensor_Number ; m++ ){
            id = name + "-" + QString::number(m+1);
            for( n  = i ;  n < i + Sensor_Number &&  n < rowCount; n++ ){
                if( sensor->sensor_table->item(n,1)->text().contains(id)){
                    global_data::update_allTable[room].set_senser_diff[m]
                            .humi_adjust = (uint16_t)(sensor->sensor_table->item(n,4)->text().toDouble()*10+0.001);
                    global_data::update_allTable[room].set_senser_diff[m]
                            .temp_adjust = (uint16_t)(sensor->sensor_table->item(n,5)->text().toDouble()*10+0.001);
                    break;
                }
            }
        }
    }
}

/**
 * @brief home::Sensor_diff_Refresh
 * @note  更新传感器的温湿度校准值
 * @param data 更新的数据
 */
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
        for( uint8_t i = 0 ; i < Sensor_Number ; i++ ){
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

/**
 * @brief home::Seed_Table_color_change
 * @note  保种执行阶段高亮
 * @param id    房间号
 * @param pre_stage 前一个执行阶段
 */
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

/**
 * @brief home::Conservat_Table_color_change
 * @note  共育执行阶段高亮
 * @param id 房间号
 * @param pre_stage 前一个执行阶段
 */
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

/**
 * @brief home::Cui_Table_color_change
 * @note  催青执行阶段高亮
 * @param id 房间号
 * @param pre_stage 前一个执行阶段
 */
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

/**
 * @brief home::Default_Paremeter_Chagne
 * @note  软件第一次的表已被改变
 */
void home::Default_Paremeter_Chagne()
{
    QSettings *settings = new QSettings(QString(FILENAME )+"/config.ini", QSettings::IniFormat);
    settings->setValue("Default_parameter/flag",true);
    delete settings;
}

/**
 * @brief home::Cui_Rejuvenate
 * @note  催青参数获取
 * @param room  房间号
 * @param assigemnt 是否发送更新倒单片机或是数据库
 */
void home::Cui_Rejuvenate(uint8_t room,bool assigemnt)
{
    qDebug()<<"催青"<<room+1<<"房间得时间更新";
    uint8_t i;
    QDate staDate,endDate;

    QDate curDate = QDate::currentDate();

    QString year = QDate::currentDate().toString("yyyy/");

    uint8_t row = Set_parment[room]->tableWidget->rowCount();

    qDebug()<<"崩了"<<"表格的行数"<<row<<"时间的年数"<<year;
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
        bool status = false;
        QFuture<void> f1;
        if( global_data::on_line ){
            f1 = QtConcurrent::run([&status,room](){
                    status = DB.AllTableToDB(QString(global_data::id[room]),global_data::execute_date[room]);
            });
            sleep(1000);

            if( !status ){
                QMessageBox::warning(NULL,"参数表","参数表更新失败，请手动更新");
            }
        }


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

/**
 * @brief home::Cui_UpdateTable
 * @note  将催青参数更新到表格中
 * @param room  房间号
 * @param status 数据来源
 */
void home::Cui_UpdateTable(uint8_t room,DataStatus status)
{
    qDebug()<<"room"<<room<<global_data::execute_date[room].run_stage;

    int stage = global_data::execute_date[room].run_stage;
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
        
        //将数据填入表中
        UPDATE_ALL_TABLE_TYPEDEF data = global_data::update_allTable[room];
        //uint8_t stage = global_data::stage[room];

        if( stage < 0 )
            return ;
        /*******************表格***********************/

            Set_parment[room]->tableWidget->
                    setItem(stage,0,new
                            QTableWidgetItem(global_data::execute_date[room].end_date));

            Set_parment[room]->tableWidget->
                    setItem(stage,1,new
                            QTableWidgetItem(global_data::execute_date[room].end_date));

            Set_parment[room]->tableWidget->item(stage,0)->setBackgroundColor(global_data::date_Color);
            Set_parment[room]->tableWidget->item(stage,1)->setBackgroundColor(global_data::date_Color);

            //设置参数表的值   
            temp = QString::number((double)data.set_sensor[0].temp_center/10,'f',1);
            Set_parment[room]->tableWidget->
                    setItem(stage,2,new
                            QTableWidgetItem(temp));


            temp = QString::number((double)data.set_sensor[0].humi_center/10,'f',1);
            Set_parment[room]->tableWidget->
                    setItem(stage,3,new
                            QTableWidgetItem(temp));

            Set_parment[room]->tableWidget->item(stage,2)->setBackgroundColor(global_data::temp_Color);
            Set_parment[room]->tableWidget->item(stage,3)->setBackgroundColor(global_data::humi_Color);


            for( uint8_t i = 0 ,tempIndex = 2; i < 8 ; i++ ,tempIndex++){
                temp = QTime::fromMSecsSinceStartOfDay(data.set_breath[i].time_sta*1000).toString("hh:mm");
                qDebug()<<temp;
                Set_parment[room]->tableWidget->setItem(stage,2*tempIndex,
                                                        new QTableWidgetItem(temp));

                temp = QString::number(data.set_breath[i].min_len);
                qDebug()<<"分钟数"<<temp;

                Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+1,
                                                        new QTableWidgetItem(temp));

                Set_parment[room]->tableWidget->item(stage,2*tempIndex)->setBackgroundColor(global_data::breath_Color);
                Set_parment[room]->tableWidget->item(stage,2*tempIndex+1)->setBackgroundColor(global_data::breath_Color);
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

                    Set_parment[room]->tableWidget->item(stage,2*tempIndex)->setBackgroundColor(global_data::sensitive_Color);
                    Set_parment[room]->tableWidget->item(stage,2*tempIndex+1)->setBackgroundColor(global_data::sensitive_Color);
                }

                //消毒
                temp = QTime::fromMSecsSinceStartOfDay(data.set_sterilize[i].time_sta *1000).toString("hh:mm");
                Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+6,
                                                                        new QTableWidgetItem(temp));
                temp = QString::number(data.set_sterilize[i].min_len) ;
                Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+7,
                                                                      new QTableWidgetItem(temp));

                Set_parment[room]->tableWidget->item(stage,2*tempIndex+6)->setBackgroundColor(global_data::disinfect_Color);
                Set_parment[room]->tableWidget->item(stage,2*tempIndex+7)->setBackgroundColor(global_data::disinfect_Color);

                //光照
                if( i < 3 ){
                    temp =QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_sta *1000).toString("hh:mm");
                    Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+14,
                                                            new QTableWidgetItem(temp));

                    temp = QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_end *1000).toString("hh:mm");
                    Set_parment[room]->tableWidget->setItem(stage,2*tempIndex+15,
                                                            new QTableWidgetItem(temp));

                    Set_parment[room]->tableWidget->item(stage,2*tempIndex+14)->setBackgroundColor(global_data::illumina_Color);
                    Set_parment[room]->tableWidget->item(stage,2*tempIndex+15)->setBackgroundColor(global_data::illumina_Color);

                }

            }

            Set_parment[room]->tableWidget->item(stage,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Set_parment[room]->tableWidget->item(stage,3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

            Set_parment[room]->DataTo_txt(stage);//将数据写入txt文本

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

/**
 * @brief home::Conservation_Renewal
 * @note  保钟参数更新
 * @param room  房间号
 * @param assigemnt 是否更新到单片机(数据库)
 */
void home::Conservation_Renewal(uint8_t room,bool assigemnt)
{

    qDebug()<<"保种"<<room+1<<"房间更新";
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
        bool status = false;
        QFuture<void> f1;
        if( global_data::on_line ){
            f1 = QtConcurrent::run([&status,room](){
                    status = DB.AllTableToDB(QString(global_data::id[room]),global_data::execute_date[room]);
            });
            sleep(1000);
            if( !status ){
                QMessageBox::warning(NULL,"参数表","参数表更新失败，请手动更新");
            }
        }

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

/**
 * @brief home::Conservation_UpdateTable
 * @note  将保种参数更新到表格中
 * @param room  房间号
 * @param status 数据来源
 */
void home::Conservation_UpdateTable(uint8_t room, DataStatus status)
{
        int stage = global_data::execute_date[room].run_stage;
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

        //将数据填入表中
        UPDATE_ALL_TABLE_TYPEDEF data = global_data::update_allTable[room];
//        uint8_t stage = global_data::stage[room];


        //设置参数表的值

        QString year = QDate::currentDate().toString("yyyy/");
        QDate sta_date,end_date;
        sta_date = QDate::fromString(year+global_data::execute_date[room].sta_date,"yyyy/MM/dd");
        end_date = QDate::fromString(year+global_data::execute_date[room].end_date,"yyyy/MM/dd");

        seed[room]->setDayFlag(false);
        seed[room]->tableWiegt->
                setItem(stage,0,new
                        QTableWidgetItem(global_data::execute_date[room].sta_date));
        seed[room]->tableWiegt->
                setItem(stage,1,new
                        QTableWidgetItem(global_data::execute_date[room].end_date));
        seed[room]->tableWiegt->
                setItem(stage,2,new
                        QTableWidgetItem(QString::number(sta_date.daysTo(end_date) + 1)));

        seed[room]->tableWiegt->item(stage,0)->setBackgroundColor(global_data::date_Color);
        seed[room]->tableWiegt->item(stage,1)->setBackgroundColor(global_data::date_Color);
        seed[room]->tableWiegt->item(stage,2)->setBackgroundColor(global_data::day_Color);

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
        seed[room]->tableWiegt->item(stage,3)->setBackgroundColor(global_data::temp_Color);
        seed[room]->tableWiegt->item(stage,4)->setBackgroundColor(global_data::humi_Color);

        for( uint8_t i = 0 ,tempIndex = 3; i < 8 ; i++ ,tempIndex++){
            temp = QTime::fromMSecsSinceStartOfDay(data.set_breath[i].time_sta*1000).toString("hh:mm");
            seed[room]->tableWiegt->setItem(stage,2*tempIndex-1,
                                                    new QTableWidgetItem(temp));

            temp = QString::number(data.set_breath[i].min_len);
            seed[room]->tableWiegt->setItem(stage,2*tempIndex,
                                                    new QTableWidgetItem(temp));

            seed[room]->tableWiegt->item(stage,2*tempIndex-1)->setBackgroundColor(global_data::breath_Color);
            seed[room]->tableWiegt->item(stage,2*tempIndex)->setBackgroundColor(global_data::breath_Color);
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

                seed[room]->tableWiegt->item(stage,2*tempIndex-1)->setBackgroundColor(global_data::sensitive_Color);
                seed[room]->tableWiegt->item(stage,2*tempIndex)->setBackgroundColor(global_data::sensitive_Color);
            }

            //消毒
            temp = QTime::fromMSecsSinceStartOfDay(data.set_sterilize[i].time_sta *1000).toString("hh:mm");
            seed[room]->tableWiegt->setItem(stage,2*tempIndex+5,
                                                                    new QTableWidgetItem(temp));
            temp = QString::number(data.set_sterilize[i].min_len) ;
            seed[room]->tableWiegt->setItem(stage,2*tempIndex+6,
                                                                    new QTableWidgetItem(temp));

            seed[room]->tableWiegt->item(stage,2*tempIndex+5)->setBackgroundColor(global_data::disinfect_Color);
            seed[room]->tableWiegt->item(stage,2*tempIndex+6)->setBackgroundColor(global_data::disinfect_Color);


            //光照
            if( i < 3 ){
                temp =QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_sta *1000).toString("hh:mm");
                seed[room]->tableWiegt->setItem(stage,2*tempIndex+13,
                                                        new QTableWidgetItem(temp));

                temp = QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_end *1000).toString("hh:mm");
                seed[room]->tableWiegt->setItem(stage,2*tempIndex+14,
                                                        new QTableWidgetItem(temp));

                seed[room]->tableWiegt->item(stage,2*tempIndex+13)->setBackgroundColor(global_data::illumina_Color);
                seed[room]->tableWiegt->item(stage,2*tempIndex+14)->setBackgroundColor(global_data::illumina_Color);
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

        seed[room]->setDayFlag(true);
}

/**
 * @brief home::Cobreeding_renewal
 * @note  共育参数更新
 * @param room 房间号
 * @param assigemnt 是否需要发送到单片机(数据库)
 */
void home::Cobreeding_renewal(uint8_t room,bool assigemnt)
{
    uint8_t i;
    qDebug()<<"共育"<<room+1<<"房间更新";
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
        bool status = false;
        global_data::execute_date[room].run_stage = -1;
        QFuture<void> f1;
        if( global_data::on_line ){
            f1 = QtConcurrent::run([&status,room](){
                    status = DB.AllTableToDB(QString(global_data::id[room]),global_data::execute_date[room]);
            });
            sleep(1000);

            if( !status ){
                QMessageBox::warning(NULL,"参数表","参数表更新失败，请手动更新");
            }
        }


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

/**
 * @brief home::Cobreeding_UpdateTable
 * @note  共育参数更新
 * @param room  房间号
 * @param status 数据来源
 */
void home::Cobreeding_UpdateTable(uint8_t room, DataStatus status)
{
    int stage = global_data::execute_date[room].run_stage;
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

        //将数据填入表中
        UPDATE_ALL_TABLE_TYPEDEF data = global_data::update_allTable[room];

        //设置参数表的值

        QString year = QDate::currentDate().toString("yyyy/");
        QDate sta_date,end_date;
        sta_date = QDate::fromString(year+global_data::execute_date[room].sta_date,"yyyy/MM/dd");
        end_date = QDate::fromString(year+global_data::execute_date[room].end_date,"yyyy/MM/dd");
        co_Parenting[room]->setDayFlag(false);

        co_Parenting[room]->tableWiegt->
                setItem(stage,0,new
                        QTableWidgetItem(global_data::execute_date[room].sta_date));
        co_Parenting[room]->tableWiegt->
                setItem(stage,1,new
                        QTableWidgetItem(global_data::execute_date[room].end_date));
        co_Parenting[room]->tableWiegt->
                setItem(stage,2,new
                        QTableWidgetItem(QString::number(sta_date.daysTo(end_date)+1)));

        co_Parenting[room]->tableWiegt->item(stage,0)->setBackgroundColor(global_data::date_Color);
        co_Parenting[room]->tableWiegt->item(stage,1)->setBackgroundColor(global_data::date_Color);
        co_Parenting[room]->tableWiegt->item(stage,2)->setBackgroundColor(global_data::date_Color);

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
        co_Parenting[room]->tableWiegt->item(stage,3)->setBackgroundColor(global_data::temp_Color);
        co_Parenting[room]->tableWiegt->item(stage,4)->setBackgroundColor(global_data::humi_Color);


        for( uint8_t i = 0 ,tempIndex = 3; i < 8 ; i++ ,tempIndex++){
            temp = QTime::fromMSecsSinceStartOfDay(data.set_breath[i].time_sta*1000).toString("hh:mm");
            co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex-1,
                                                    new QTableWidgetItem(temp));

            temp = QString::number(data.set_breath[i].min_len) ;
            co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex,
                                                    new QTableWidgetItem(temp));

            co_Parenting[room]->tableWiegt->item(stage,2*tempIndex-1)->setBackgroundColor(global_data::breath_Color);
            co_Parenting[room]->tableWiegt->item(stage,2*tempIndex)->setBackgroundColor(global_data::breath_Color);
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

                co_Parenting[room]->tableWiegt->item(stage,2*tempIndex-1)->setBackgroundColor(global_data::illumina_Color);
                co_Parenting[room]->tableWiegt->item(stage,2*tempIndex)->setBackgroundColor(global_data::illumina_Color);
            }

            //消毒
            temp = QTime::fromMSecsSinceStartOfDay(data.set_sterilize[i].time_sta *1000).toString("hh:mm");
            co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex+5,
                                                                    new QTableWidgetItem(temp));
            temp = QString::number(data.set_sterilize[i].min_len) ;
            co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex+6,
                                                                     new QTableWidgetItem(temp));

            co_Parenting[room]->tableWiegt->item(stage,2*tempIndex+5)->setBackgroundColor(global_data::disinfect_Color);
            co_Parenting[room]->tableWiegt->item(stage,2*tempIndex+6)->setBackgroundColor(global_data::disinfect_Color);

            //光照
            if( i < 3 ){
                temp =QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_sta *1000).toString("hh:mm");
                co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex+13,
                                                        new QTableWidgetItem(temp));

                temp = QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_end *1000).toString("hh:mm");
                co_Parenting[room]->tableWiegt->setItem(stage,2*tempIndex+14,
                                                        new QTableWidgetItem(temp));
                co_Parenting[room]->tableWiegt->item(stage,2*tempIndex+13)->setBackgroundColor(global_data::illumina_Color);
                co_Parenting[room]->tableWiegt->item(stage,2*tempIndex+14)->setBackgroundColor(global_data::illumina_Color);
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
        co_Parenting[room]->setDayFlag(true);

}

/**
 * @brief home::ModeChangeDeal
 * @note  设备工作模式改变
 * @param id 设备号
 * @param status 是否发送参数到单片机或是数据库 true为真
 */
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
    }

    Mode_Save(id);
}

/**
 * @brief home::room_show
 * @note  设备参数显示
 * @param data  显示的数据
 * @param room  要显示的房间号
 */
void home::room_show(FROM_DB_Typedef data, uint8_t room )
{
    qDebug()<<room;

    if( data.status == ONLINE){
          Device[room]->Equipment->setText(Set_font_Style(STR_EQUIPMENT," ","00ff00","设备在线"));
          //心跳包计数
            global_data::heart_beat_count[room] = 0;
            co_Parenting[room]->setEnabled(true);
            Set_parment[room]->setEnabled(true);
            seed[room]->setEnabled(true);
          Sensor_show(room);
    }else{
          Device[room]->Equipment->setText(Set_font_Style(STR_EQUIPMENT," ","ff0000","设备离线"));
          Del_Sensor(QString(global_data::id[room]));

          co_Parenting[room]->setEnabled(false);
          Set_parment[room]->setEnabled(false);
          seed[room]->setEnabled(false );
          Device[room]->Sensor_status->setText(R"(<html><head/><body><p><span style=" font-size:)" + QString(STR_SENSOR) + R"(; font-weight:600; color:#ff0000;">传感器异常 </span></p></body></html>)");
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

    if( (global_data::control_Mode[room] %2) == 0 ){
        str += "运行";
        str = Set_font_Style(STR_MODE,"","00ff00",str.toUtf8().data());
    }
    else{
        str += "停止";
        str = Set_font_Style(STR_MODE,"","ff0000",str.toUtf8().data());
    }
    Device[room]->mode->setText(str);


    Device[room]->temp_center->setText(Set_font_Style(STR_CENTER_DATA," ","ffffff",data.temp_center.toUtf8().data()));
    Device[room]->humi_center->setText(Set_font_Style(STR_CENTER_DATA," ","ffffff",data.humi_center.toUtf8().data()));
    show_relay(Device[room]->Heat_status,data.relay_status.relay.heat);

    show_relay(Device[room]->Moiste_status,data.relay_status.relay.humi);

    show_relay(Device[room]->Dehumi_status,data.relay_status.relay.dry);

    show_relay(Device[room]->Breathe_status,data.relay_status.relay.breath);

    show_relay(Device[room]->Light_status,data.relay_status.relay.light);

    show_relay(Device[room]->Wind_status,data.relay_status.relay.wind);

    show_relay(Device[room]->Disinfect_status,data.relay_status.relay.sterilize);

    show_relay(Device[room]->Sensitive_status,data.relay_status.relay.sensitive);

    show_air_relay(Device[room]->Air_status,data.air_status);

    Device[room]->Temperature->setText(data.temp);
    Device[room]->Temperature->setStyleSheet("font-size:" + QString(STR_REAL_DATA) + "; font-weight:600; color:#ffbeaa;");

    Device[room]->Humidity->setText(data.humi);
    Device[room]->Humidity->setStyleSheet("font-size:" + QString(STR_REAL_DATA) + "; font-weight:600; color:#ffbeaa;");
}

/**
 * @brief home::Delete_Sensor_Line
 * @note  删除传感器在表中的那一行
 * @param row 要删除的行
 */
void home::Delete_Sensor_Line(uint8_t row)
{
    uint8_t column = sensor->sensor_table->columnCount();
    for( uint8_t i = 0 ; i < column ; i++ ){
        QTableWidgetItem  *item = sensor->sensor_table->item(row,i);
        if( item )
            delete item;
    }
}

void home::closeEvent(QCloseEvent *event)
{


    QMessageBox message(QMessageBox::Warning,"退出!",
                                                     "确定要退出吗",QMessageBox::Yes|QMessageBox::No,NULL);
    if(message.exec() == QMessageBox::Yes){
        //this->close();
        event->accept();
    }
    else{
        event->ignore();
    }
}

/**
 * @brief home::Setting_onclick
 * @note  房间的设置按钮被点击时，触发的函数
 * @param id 房间号
 */
void home::Setting_onclick(uint8_t id)
{
    static int pre_stage[DEV] = {-1,-1};
    if(  global_data::control_Mode[id] < 2 ){

        if( global_data::execute_date[id].run_stage >= 0 && global_data::execute_date[id].run_stage < 30){
             seed[id]->tableWiegt->setCurrentCell(global_data::execute_date[id].run_stage,QItemSelectionModel::Select);
             Seed_Table_color_change(id,pre_stage[id]);
             pre_stage[id] = global_data::execute_date[id].run_stage;
        }
        else{
            pre_stage[id] = -1;
        }
        seed[id]->setWindowModality(Qt::ApplicationModal);
        seed[id]->showMaximized();

    }
    else if( global_data::control_Mode[id] >=2 &&
             global_data::control_Mode[id] < 4 ){
        if( global_data::execute_date[id].run_stage >= 0 && global_data::execute_date[id].run_stage < 4 ){
            co_Parenting[id]->tableWiegt->setCurrentCell(global_data::execute_date[id].run_stage,QItemSelectionModel::Select);
            Conservat_Table_color_change(id,pre_stage[id]);
            pre_stage[id] = global_data::execute_date[id].run_stage;
        }
        else{
            pre_stage[id] = -1;
        }

        co_Parenting[id]->setWindowModality(Qt::ApplicationModal);
        co_Parenting[id]->showMaximized();

    }
    else if( global_data::control_Mode[id] >=4 &&
             global_data::control_Mode[id] < 6 ){

        if( global_data::execute_date[id].run_stage >= 0 && global_data::execute_date[id].run_stage < 12){
                  //int temp = global_data::execute_date[id].run_stage;
                  Set_parment[id]->tableWidget->setCurrentCell(global_data::execute_date[id].run_stage,QItemSelectionModel::Select);
                  Cui_Table_color_change(id,pre_stage[id]);
                  pre_stage[id] = global_data::execute_date[id].run_stage;
        }
        else{
            pre_stage[id] = -1;
        }

        Set_parment[id]->setWindowModality(Qt::ApplicationModal);

        //原本为最大显示
        Set_parment[id]->showMaximized();
    }

    table_LOCK[id] = Write_lock;
}

/**
 * @brief home::timeUpdate
 * @note  接收来自数据的数据
 * @param info 显示数据的结构体
 */
void home::timeUpdate(const QVariant info)
{
    FROM_DB_Typedef data;
    data = info.value<FROM_DB_Typedef>();
    int id = -1;
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( !QString::compare(data.id,global_data::id[i]) ){
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

/**
 * @brief home::__485_rcv_data
 * @note  串口接收数据处理
 * @param data 从串口接收到的数据
 */
void home::__485_rcv_data(QByteArray data)
{
     uint16_t crc ;
     bool ok;

     char *rcv = data.data();


     uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
     uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);
     qDebug()<<"date"<<data.toHex()
            <<"head"<<head<<"tail"<<tail;
     if( TO_APP_HEAD == head && TO_APP_TAIL == tail){

         FROM_MCU_Typedef from_mcu;//显示数据
         memcpy((char *)&from_mcu,rcv,sizeof(FROM_MCU_Typedef));

         crc = CRC16_2_modbus((uint8_t*)&from_mcu,sizeof(FROM_MCU_Typedef)-2);

         if( from_mcu.crc == crc ) {

            int pos  = ID_lookup(QString(from_mcu.id));

             if( pos < 0 )
                 return ;

             if( pos >= 0 && pos < 4){
                     show_data[pos].status = ONLINE;

                     global_data::Mutual_exclusion[pos] = __485_Serial;
                     global_data::heart_beat_count[pos]  = 0; //心跳包清零

                     show_data[pos].temp = QString::number((double)from_mcu.temp/10,'f',1);
                     show_data[pos].humi = QString::number((double)from_mcu.humi/10,'f',1);

                     show_data[pos].temp_center = QString::number((double)from_mcu.now_sensor.temp_center/10,'f',1);
                     show_data[pos].humi_center = QString::number((double)from_mcu.now_sensor.humi_center/10,'f',1);

                     for( uint8_t i = 0 ; i < Sensor_Number ; i++ ){
                         show_data[pos].signle_senser[i] = from_mcu.signle_senser[i];
                     }

                     show_data[pos].air_status = from_mcu.air_status;
                     show_data[pos].relay_status.relay_vale = from_mcu.relay_status.relay_vale;
                 }

                 Interface_display(pos + 1,show_data[pos],__485_Serial);//在主界面显示
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

             int pos = -1 ;//QString(UpdateTable.id).right(3).toInt();


             pos = ID_lookup(QString(UpdateTable.id)) + 1;
             if( pos <= 0 )
                 return ;


             if( pos >0 && pos <= DEV ){
                 global_data::update_allTable[pos-1] = UpdateTable;

                 //将这个参数更新到参数表上
                 switch (global_data::control_Mode[pos-1]/2) {
                 case cuiqing:
                     //数据表的更新
                     qDebug()<<"催青";
                     Cui_UpdateTable(pos-1,__485_Serial);
                     break;
                 case baozhong:
                     qDebug()<<"保种";
                     Conservation_UpdateTable(pos-1,__485_Serial);
                     break;
                 case gongyu:
                     qDebug()<<"共育";
                     Cobreeding_UpdateTable(pos-1,__485_Serial);
                 default:
                     break;
                 }
                 //并且上发到数据库
             }
         }

     }
     else if( head == _485_CMD_HEAD && tail == _485_CMD_TAIL){
         qDebug()<<"接收到的数据的第一位数据为"<<data.toHex();
         qDebug()<<data.left(1).toHex()<<data.right(3).left(1).toHex();
         qDebug()<<"头"<<head<<"尾"<<tail;
         memcpy((char *)&Recive_485_cmd,rcv,sizeof(__485_CMD_Type));
         crc = CRC16_2_modbus((uint8_t*)&Recive_485_cmd,sizeof(__485_CMD_Type)-2);

         if( Recive_485_cmd.crc == crc ){
             //进行命令判断 空调/WIFI
             qDebug()<<"信号来了啊啊啊啊啊啊啊啊"<<Recive_485_cmd.cmd;
             int id = -1;//QString(Recive_485_cmd.id).right(3).toInt()-1;
             id = ID_lookup(QString(Recive_485_cmd.id));
             if( id < 0 )
                 return ;
             __485_CMD_Del(Recive_485_cmd,id);
         }
     }
     else if( head == GET_DEV_STATUS_HEAD && tail == GET_DEV_STATUS_TAIL ){
         WORK_WAY_TYEP work_way;
         memcpy((char*)&work_way,rcv,sizeof(WORK_WAY_TYEP));
         crc = CRC16_2_modbus((uint8_t*)&work_way,sizeof(WORK_WAY_TYEP)-2);
         if( work_way.crc == crc ){
                global_data::mode_rcv_flag = true;
                int id = -1;//QString(work_way.id).right(3).toInt()-1;
                id = ID_lookup(QString(work_way.id));
                if( id < 0 )
                    return ;
                global_data::control_Mode[id] = work_way.work_status;
                global_data::work_way[id].reasure_count = work_way.reasure_count;
                global_data::Mode_Lock[id] = Write_lock;
                ModeChangeDeal(id,0);
         }
         
     }
     serial->flush();

}

/**
 * @brief home::update_table_485
 *        Timer callback to deal mode change,heart connect,mqtt connect
 */
void home::update_table_485()
{
    if( global_data::temp_flag == false)
    {
        for( uint8_t i = 0 ; i < DEV ; i++ ){
            //加锁
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
    }
     global_data::temp_flag = true;

    //UPDATE_ALL_TABLE_TYPEDEF data = global_data::update_allTable[1];

    static uint8_t updae_counts = 0;
    static QTime Utime[3] = {{0,1,0},{0,31,0},{1,1,0}};
    //static uint8_t table_counts = 0;

    QDate dTime = QDate::currentDate();

    if( update_time.daysTo(dTime) > 0){
        ui->right_title->setText(dTime.toString("yyyy-MM-dd"));
        update_time = update_time.addDays(1);
        qDebug()<<"天数更新"<<update_time;
        //赋值标志位更新
       global_data::update_flag = true;;

       for( uint8_t i = 0 ; i < DEV ; i++ ){
           switch (global_data::control_Mode[i]/2) {
           case cuiqing:
               //Set_stage(i,1);
               Cui_Rejuvenate(i,1);
               break;
           case baozhong:
               Conservation_Renewal(i,1);
               break;
           case gongyu:
               Cobreeding_renewal(i,1);
               break;
           default:
               break;
           }
       }  
    }

    /* 发送失败次数判断，条件为globle::send_flag == false*/
    QTime time = QTime::currentTime();
    if( (time >= Utime[0] && time < Utime[0].addSecs(8) )
            || (time >= Utime[1] && time < Utime[1].addSecs(8)) ||
            (time >= Utime[2] && time < Utime[2].addSecs(8)))
    {
        for(int i = 0 ; i < DEV ; i++ )
        {
            Send_update_Message(i);
            if(global_data::Send_onine_flag[i] == false)
            {
                Send_update_Message(i);
                if( (time >= Utime[2] && time < Utime[2].addSecs(8)))
                {
                    global_data::Send_onine_flag[i] = true;
                    send_Failure_Status[i] = 0;
                }

            }

        }
    }


    //心跳包检测显示
    heart_counts++;
    if( heart_counts > 20 ){
        for( uint8_t i = 0 ; i < DEV ; i++ ){
            global_data::heart_beat_count[i]++;
        }
        heart_counts = 0;
        /***************串口连接与否判断******************/
        if(serial->portName().isEmpty()){
            communi->setText("串口未连接");
        }
        else{
            communi->setText("串口"+serial->portName()+ "已连接");
        }
        communi->setStyleSheet(" color:#ffffff;font: bold 16px");
        ui->statusBar->addWidget(communi);
    }

    uint8_t serial_count = 0;
    for( uint8_t i = 0; i < DEV ; i++ ){
        //串口使用判断
        //有：打开定时器
        //无关闭定时器

        if( global_data::heart_beat_count[i] > 4 ){
            if( global_data::Mutual_exclusion[i] == __485_Serial ||
                    global_data::Mutual_exclusion[i] == Invalid){
                 //global_data::Mutual_exclusion[i] = DataBase;

                Device_disengaged(show_data[i]);
                global_data::heart_beat_count[i] = 4;

                serial_count++;
            }
        }


    }

//    if( serial_count  < 4 ){
//        if( !Heart_timer->isActive()){
//            Heart_timer->start(400);
//            qDebug()<<"心跳包定时器打开";
//        }

//    }
//    else{
//        if( Heart_timer->isActive()){
//             Heart_timer->stop();;
//            qDebug()<<"心跳包定时器关闭";
//        }

//    }

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
        }


    }

    //qDebug()<<"1号房间标志位"<<global_data::stage[0];
    create_connect();
    static bool dev_cStatus[DEV] = {false};
    if( global_data::mqtt_status)
    {
        for(int i = 0 ; i < DEV  ; i++ )
        {

//            if( show_data[i].status == OFFLINE)
//            {
//                dev_cStatus[i] = false;
//            }
            if( !dev_cStatus[i])
            {
                if(mqtt_subscribe(i))
                {
                    dev_cStatus[i] = true;
                }
            }
        }
    }
    else
    {
        qDebug()<<"Mqqtt断开连接";
        for(int i = 0 ; i < DEV ; i++ )
        {
            dev_cStatus[i] = false;
        }
    }



//    qDebug()<<"主界面"<<mG_client->state();
//    qDebug()<<"锁的状态:"<<global_data::Mode_Lock[0]<<"  "<<"1:"<<global_data::Mode_Lock[1]
//           <<"处于的模式"<<global_data::Mutual_exclusion[0]<<global_data::Mutual_exclusion[1];
    //网络锁，防止重复触发

}

/**
 * @brief home::Send_Heart
 * @note  心跳包发送
 */
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

/**
 * @brief home::update_SensorName
 * @note  将传感器名字在数据报表中显示出来
 * @param room
 */
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

/**
 * @brief home::RoomCtrol_Change
 * @note  房间控制模式改变
 * @param room
 */
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

/**
 * @brief home::Table_Change
 * @note  参数表发生变化
 */
void home::Table_Change()
{
    uint8_t room = myT->DBT->room;

    qDebug()<<"网络房间参数表发生改变。。。。。。。。。。。"<<room;
    if( global_data::execute_date[room%4].run_stage < 0)
        return ;

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

/**
 * @brief home::table_unlock
 * @note  表加锁
 */
void home::table_unlock()
{
    qDebug()<<"table_inlock";
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        table_LOCK[i] = Write_Unlock;
    }
}

/**
 * @brief home::on_pushButton_main_clicked
 * @note  主界面被点击
 */
void home::on_pushButton_main_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

/**
 * @brief home::on_pushButton_settting_clicked
 * @note  系统设置界面被点击
 */
void home::on_pushButton_settting_clicked()
{
    //系统设置界面
    QInputDialog* inputDialog=new QInputDialog(this);
    inputDialog->setWindowTitle("提示");
    inputDialog->setLabelText("参数修改");
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
        if(text == "888888"){
            //更新
            uint8_t room = system_Setting->ui->Room_Choose->currentIndex();
            system_Setting->ui->Room_Choose->setCurrentIndex((room+1)%DEV);
            system_Setting->ui->Room_Choose->setCurrentIndex(room);

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

/**
 * @brief home::on_pushButton_chart_clicked
 * @note  历史曲线被点击
 */
void home::on_pushButton_chart_clicked()
{
    //历史曲线界面
    ui->stackedWidget->setCurrentIndex(3);
    charview->date_sta->setDate(QDate::currentDate());
    charview->date_end->setDate(QDate::currentDate().addDays(1));
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

/**
 * @brief home::on_pushButton_dataP_clicked
 * @note  数据报表被点击
 */
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
        for( uint8_t j = 0 ; j < Sensor_Number ; j++ ){
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

/**
 * @brief home::on_pushButton_sensor_clicked
 * @note  传感器被点击
 */
void home::on_pushButton_sensor_clicked()
{
    //传感器界面
    QInputDialog* inputDialog=new QInputDialog(this);
    inputDialog->setWindowTitle("传感器");
    inputDialog->setLabelText("参数修改");
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

/**
 * @brief home::on_pushButton_comminicat_clicked
 * @note  设备通讯被点击
 */
void home::on_pushButton_comminicat_clicked()
{
    //通讯界面
    ui->stackedWidget->setCurrentIndex(6);
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

/**
 * @brief home::on_pushButton_manage_clicked
 * @note  用户管理被点击
 */
void home::on_pushButton_manage_clicked()
{
    //用户管理界面
    ui->stackedWidget->setCurrentIndex(7);
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

/**
 * @brief home::on_pushButton_6_clicked
 * @note  帮助界面被点击
 */
void home::on_pushButton_6_clicked()
{
    //帮助界面
    ui->stackedWidget->setCurrentIndex(8);
    sensor_LOCK = Write_Unlock;
    system_LOCK  = Write_Unlock;
}

/**
 * @brief home::on_pushButton_2_clicked
 * @note  退出系统被点击
 */
void home::on_pushButton_2_clicked()
{
    if( global_data::on_line ){
        if( !DB.toDB())
            {
                qDebug()<<"重新连接数据库";
                DB.open("test1");
            }
    }

//        QMessageBox message(QMessageBox::Warning,"退出!",
//                                                         "确定要退出吗",QMessageBox::Yes|QMessageBox::No,NULL);
//        if(message.exec() == QMessageBox::Yes){

//        }
        this->close();


}

/**
 * @brief home::topicMessageReceived
 * @note  mqtt消息接收，处理
 * @param data  接收来自mqtt的消息
 * @param topic 主题
 */
void home::topicMessageReceived(const QByteArray &data, const QMqttTopicName &topic)
{
    Q_UNUSED(topic);
    uint16_t crc ;
    bool ok;

    const char *rcv = data.data();

    uint8_t head = QString(data.left(1).toHex()).toInt(&ok,16);
    uint8_t tail = QString(data.right(3).left(1).toHex()).toInt(&ok,16);
    qDebug()<<"date"<<data.toHex()
           <<"head"<<head<<"tail"<<tail;

    if( TO_APP_HEAD == head && TO_APP_TAIL == tail){

        FROM_MCU_Typedef from_mcu;



        memcpy((char *)&from_mcu,rcv,sizeof(FROM_MCU_Typedef));

        crc = CRC16_2_modbus((uint8_t*)&from_mcu,sizeof(FROM_MCU_Typedef)-2);

        qDebug()<<"crc"<<crc<<from_mcu.crc;
        if( from_mcu.crc == crc ) {

           int pos  = ID_lookup(QString(from_mcu.id));

            if( pos < 0 )
                return ;
            qDebug()<<"名字"<< QString(from_mcu.id);
            if( pos >= 0 && pos < DEV){
                    global_data::Mutual_exclusion[pos] = Invalid;
                    global_data::heart_beat_count[pos]  = 0;

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

            int pos = -1 ;//QString(UpdateTable.id).right(3).toInt();


            pos = ID_lookup(QString(UpdateTable.id)) + 1;
            if( pos <= 0 )
                return ;


            if( pos >0 && pos <= DEV ){
                if( global_data::update_allTable[pos-1].crc == UpdateTable.crc)
                    return ;
                global_data::update_allTable[pos-1] = UpdateTable;

                //将这个参数更新到参数表上
                switch (global_data::control_Mode[pos-1]/2) {
                case cuiqing:
                    //数据表的更新
                    qDebug()<<"催青";
                    Cui_UpdateTable(pos-1,__485_Serial);
                    break;
                case baozhong:
                    qDebug()<<"保种";
                    Conservation_UpdateTable(pos-1,__485_Serial);
                    break;
                case gongyu:
                    qDebug()<<"共育";
                    Cobreeding_UpdateTable(pos-1,__485_Serial);
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
               int id = -1;//QString(work_way.id).right(3).toInt()-1;
               id = ID_lookup(QString(work_way.id));
               if( id < 0 )
                   return ;
               global_data::control_Mode[id] = work_way.work_status;
               global_data::work_way[id].reasure_count = work_way.reasure_count;
               global_data::Mode_Lock[id] = Write_lock;
               ModeChangeDeal(id,0);
        }

    }
}


