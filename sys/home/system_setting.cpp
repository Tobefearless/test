#include "system_setting.h"
#include "ui_system_setting.h"
#include "QDesktopWidget"
#include <QProgressDialog>
System_Setting::System_Setting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::System_Setting)
{
    ui->setupUi(this);
    this->setWindowTitle("系统设置");                 //设置窗口标题
    this->setWindowIcon(QIcon(":/img/setting.png"));        //设置窗口图片
    //为结构体头和尾
    send_wifi_data.head = WIFI_SSID_HEAD;
    send_wifi_data.tail = WIFI_SSID_TAIL;

    Send_485_cmd.head = _485_CMD_HEAD ;
    Send_485_cmd.tail = _485_CMD_TAIL;

    //串口标志位赋值
    Serial_flag = false;
    sconFlagOk = false;
    //不可改变状态
    show_Disable();
    //默认房间参数设置
    Default_parameter();
    temp_flag=humi_flag=wind_flag=false;
    //判断参数是否改变


    connect(ui->Temp_Diff,&QLineEdit::textChanged,[=]{
        if( ui->Modify->text() == "确定" ){
            qDebug()<<"温差改变";
            temp_flag = true;
        }
    });

    connect(ui->Humi_Diff,&QLineEdit::textChanged,[=]{
        if( ui->Modify->text() == "确定"){
            qDebug()<<"湿度差改变";
            humi_flag = true;
        }

    });

    connect(ui->WindDiff,&QLineEdit::textChanged,[=]{
        if( ui->Modify->text() == "确定"){
            qDebug()<<"匀风扇参数改变";
            wind_flag = true;
        }

    });
    ui->btn_Wconnect->setWindowOpacity(0.7);
}

QStringList System_Setting::searchPort()
{
    //通过QSerialPortInfo查找可用串口
    portlist.clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        portlist.push_back(info.portName());
    }
    qDebug()<<portlist;
    return portlist;
}

void System_Setting::OpenSerial(QString portName, qint32 baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{
    serial->setPortName(portName);
    //设置波特率
    serial->setBaudRate(baudRate);
    //设置数据位数
    serial->setDataBits(dataBits);
     //设置奇偶校验
     serial->setParity(parity);
    //设置停止位
    serial->setStopBits(stopBits);
    //打开串口
   if( serial->open(QIODevice::ReadWrite) == false){
       sconFlagOk = false;
   }else{
       sconFlagOk = true;
   }
}

void System_Setting::show_Enable()
{
    ui->groupBox_5->setEnabled(true);
    ui->groupBox_3->setEnabled(true);
    ui->groupBox_4->setEnabled(true);
    ui->groupBox_2->setEnabled(true);

    if( Serial_flag){
        ui->Heat_Learn->setEnabled(true);
        ui->Cold_Learn->setEnabled(true);
        ui->Close_Learn->setEnabled(true);
        ui->btn_Wconnect->setEnabled(true);
    }
}

void System_Setting::show_Disable()
{
    ui->groupBox_5->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
    ui->groupBox_2->setEnabled(false);
}

void System_Setting::Serial_show_Enable()
{
    ui->btn_Wconnect->setEnabled(true);
    ui->Heat_Learn->setEnabled(true);
    ui->Cold_Learn->setEnabled(true);
    ui->Close_Learn->setEnabled(true);
}

void System_Setting::Serial_show_Disable()
{
    ui->btn_Wconnect->setEnabled(false);
    ui->Heat_Learn->setEnabled(false);
    ui->Cold_Learn->setEnabled(false);
    ui->Close_Learn->setEnabled(false);
}

void System_Setting::Default_parameter()
{
    for( uint8_t id = 0 ; id < 4 ; id++ ){

        room_setting[id].WIFI_4G.mode = 0;
        room_setting[id].WIFI_4G.txt = "连接";

        room_setting[id].Air.heat = "加热学习";
        room_setting[id].Air.cold = "制冷学习";
        room_setting[id].Air.clsoe = "关闭学习";
    }
    QRegExp rx(R"((\d\.\d)|\d)");
    QRegExpValidator *pReg = new QRegExpValidator(rx,this);
    ui->Temp_Diff->setValidator(pReg);
    ui->Humi_Diff->setValidator(pReg);
    ui->WindDiff->setValidator(pReg);

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        pre_workStatus[i] = 10;
    }
}

void System_Setting::Key_State(QPushButton *button, uint8_t state)
{
    switch (state) {
    //绿色
    case 0:
        button->setStyleSheet("QPushButton {\n"
                              "color: rgb(255, 255, 255);\n"
                              "border:5px outset rgb(152,228,76);\n"
                              "background-color: rgb(85,170,0);\n"
                              "border-radius:10px;\n"
                              "padding:2px 4px;\n"
                              "}\n"

                              "QPushButton:hover{\n"

                                  "color: rgb(0, 0, 0);\n"
                                  "border:5px outset gray;\n"
                                  "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
                                  "border-radius:10px;\n"
                                  "position:relative; top:1px; left:1px\n"
                              "}\n"

                              "QPushButton:pressed{\n"
                                  "border:3px inset gray;\n"
                                  "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
                                  "border-bottom: 1px;\n"
                                  "border-radius:10px;\n"
                              "}");
        break;
    //红色
    case 1:
        button->setStyleSheet("QPushButton {\n"
                              "color: rgb(255, 255, 255);\n"
                              "border:5px outset rgb(252,87,87);\n"
                              "background-color: rgb(255,0,0);\n"
                              "border-radius:10px;\n"
                              "padding:2px 4px;\n"
                              "}\n"

                              "QPushButton:hover{\n"

                                  "color: rgb(0, 0, 0);\n"
                                  "border:5px outset gray;\n"
                                  "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
                                  "border-radius:10px;\n"
                                  "position:relative; top:1px; left:1px\n"
                              "}\n"

                              "QPushButton:pressed{\n"
                                  "border:3px inset gray;\n"
                                  "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
                                  "border-bottom: 1px;\n"
                                  "border-radius:10px;\n"
                              "}");
        break;
    //原始颜色
    case 2:
        button->setStyleSheet("QPushButton {color: rgb(255, 255, 255);border:2px groove gray;padding:2px 4px;}"
                             " QPushButton:hover{color: rgb(0, 0, 0);border: 1px solid #3C80B1;background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(181, 225, 250, 255), stop:0.50001 rgba(222, 242, 251, 255));}"
                             " QPushButton:pressed{border: 1px solid #5F92B2;background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(134, 198, 233, 255), stop:0.50001 rgba(206, 234, 248, 255));}");
        break;
    case 3:
        button->setStyleSheet("QPushButton {color: rgb(255, 255, 255);border:2px groove gray;background-color:rgb(0,255,255);padding:2px 4px;}"
                              "QPushButton:hover{color: rgb(0, 0, 0);border: 1px solid #3C80B1;background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(181, 225, 250, 255), stop:0.50001 rgba(222, 242, 251, 255));}"
                              "QPushButton:pressed{border: 1px solid #5F92B2;background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(134, 198, 233, 255), stop:0.50001 rgba(206, 234, 248, 255));}");
        break;
    default:
        button->setStyleSheet("QPushButton {color: rgb(255, 255, 255);border:2px groove gray;padding:2px 4px;}"
                             " QPushButton:hover{color: rgb(0, 0, 0);border: 1px solid #3C80B1;background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(181, 225, 250, 255), stop:0.50001 rgba(222, 242, 251, 255));}"
                             " QPushButton:pressed{border: 1px solid #5F92B2;background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(134, 198, 233, 255), stop:0.50001 rgba(206, 234, 248, 255));}");
             break;
    }
}

void System_Setting::Simple_trans(__485_CMD_ cmd)
{
    int num  = ui->Room_Choose->currentIndex();
    memcpy(Send_485_cmd.id,global_data::id[num],sizeof(Send_485_cmd.id));
    Send_485_cmd.cmd = cmd;
    Send_485_cmd.crc = CRC16_2_modbus((uint8_t*)&Send_485_cmd,sizeof(__485_CMD_Type)-2);
    serial->write((char*)&Send_485_cmd,sizeof(__485_CMD_Type));
}

void System_Setting::Room_Ctrol_Change(uint8_t room)
{
        if( GetRadio_Status() != global_data::control_Mode[room] &&
               (GetRadio_Status()-1) != global_data::control_Mode[room] ){

            //global_data::control_Mode[room] = GetRadio_Status();
            qDebug()<<"按键状态"<<GetRadio_Status();
            //global_data::work_way[room].work_status = GetRadio_Status();
            bool status =  Device_Change(room, GetRadio_Status());
            if( status ){
                emit Contral_adjust(room);
                Message_alert("提示","模式修改成功",QMessageBox::Information);
            }
            else{
                QMessageBox::warning(NULL, "提示", "模式修改失败", "确定");
            }

        }
}

uint8_t System_Setting::GetRadio_Status()
{
    if( ui->Button_Cui->isChecked() )
        return CUIQING_END;
    else if( ui->Button_Bao->isChecked() )
        return BAOZHONG_END;
    else
        return GONGYU_END;
}

void System_Setting::Diff_Save(uint8_t room)
{
    QSettings *settings = new QSettings(QString(FILENAME) +"/config.ini", QSettings::IniFormat);
    settings->setValue("TEMP_ADJUST/temp" + QString::number(room + 1),global_data::update_allTable[room].set_sensor[0].temp_diff);
    settings->setValue("HUMI_ADJUST/humi" + QString::number(room + 1),global_data::update_allTable[room].set_sensor[0].humi_diff);
    settings->setValue("WIND_ADJUST/wind" + QString::number(room + 1),global_data::update_allTable[room].set_wind_temp_diff);
    delete settings;

}

bool System_Setting::Device_Change(uint8_t room, uint8_t way)
{
    room = 0;
    sleep(1000);
    QProgressDialog dialog(tr("模式修改中"), tr("取消"), 0, 0, this);
    dialog.setWindowTitle(tr("正在修改"));     // 设置窗口标题
    dialog.setWindowModality(Qt::WindowModal);  // 将对话框设置为模态
    dialog.show();

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
        if( !status ){
            f1 = QtConcurrent::run( [&temp,room](){
                    temp = DB.WORKwayToDB(global_data::work_way[room],"1");
                });
        }
        else{
            f1 = QtConcurrent::run( [&temp,room](){
                    temp = DB.WORKwayToDB(global_data::work_way[room],"0");
                });
        }

        sleep(1000);
        if( !temp ){
            DB.open("test1");
        }
        status |= temp;
    }
    f1.cancel();
    if( global_data::mqtt_status)
         Mqtt_publish(room,global_data::work_way[room]);
    if( !status )
        return false;
    uint8_t times = 0;
    while(global_data::Mode_Lock[room] == Write_Unlock)
    {
        if( times >= 8 ){
            global_data::work_way[room].work_status = global_data::control_Mode[room];
            if( global_data::on_line ){
                f1 = QtConcurrent::run([room](){
                    DB.WORKwayToDB(global_data::work_way[room],"0");
                });
                sleep(1000);
            }
            f1.cancel();
            dialog.close();
            return false;
        }
        times++;
        sleep(1000);
    }



    dialog.close();
    return true;
}

void System_Setting::Message_alert(QString title, QString text, QMessageBox::Icon hint)
{
    QMessageBox *box = new QMessageBox(hint,title,text);
    QTimer::singleShot(1500,box,SLOT(accept())); //也可将accept改为close
    box->exec();//box->show();都可以
    delete box;
    //box->deleteLater();
    box = nullptr;
    qApp->processEvents();
}

System_Setting::~System_Setting()
{
    delete ui;
}


void System_Setting::on_Modify_clicked()
{
    int id = ui->Room_Choose->currentIndex();

    if( ui->Modify->text() == "修改"){
        ui->Modify->setText("确定");
        show_Enable();
    }
    else{
        ui->Modify->setText("修改");
        global_data::update_allTable[id].set_sensor[0].temp_diff = uint16_t((ui->Temp_Diff->text().toDouble()+0.00001) *10);
        global_data::update_allTable[id].set_sensor[0].humi_diff = uint16_t((ui->Humi_Diff->text().toDouble()+0.00001) *10);
        global_data::update_allTable[id].set_wind_temp_diff = uint8_t((ui->WindDiff->text().toDouble()+0.00001) *10);
        room_setting[id].Air.heat = ui->Heat_Learn->text();
        room_setting[id].Air.cold = ui->Cold_Learn->text();
        room_setting[id].Air.clsoe = ui->Close_Learn->text();

        room_setting[id].WIFI_4G.mode = ui->comboBox_wifi->currentIndex();
        room_setting[id].WIFI_4G.name = ui->lineEdit_name->text();
        room_setting[id].WIFI_4G.passwd = ui->lineEdit_passwd->text();
        room_setting[id].WIFI_4G.txt = ui->btn_Wconnect->text();


        Room_Ctrol_Change(id);
        show_Disable();

        if( (temp_flag || humi_flag || wind_flag) && global_data::execute_date[id].run_stage >= 0){
            //计算crc
            qDebug()<<"开始发送温度回差。。。。。。";
            global_data::update_allTable[id].crc = CRC16_2_modbus((uint8_t*)&global_data::update_allTable[id]
                                                                ,sizeof(UPDATE_ALL_TABLE_TYPEDEF) - 2);
            bool status = false;

            if( Serial_flag ){

                status = update_All_table(global_data::update_allTable[id]);
                if( !status ){
                    QMessageBox::warning(NULL, "参数表", "数据发送失败", "确定");
                }
            }

            if( global_data::mqtt_status ){
                bool data_status = Mqtt_publish(id,global_data::update_allTable[id]);
                QFuture<void> f1;
                //bool flag = false;
                if( status ){
                    f1 = QtConcurrent::run([&data_status,id](){
                        data_status = DB.AllTableToDB(global_data::update_allTable[id],global_data::execute_date[id]);
                    });
                }
                else{
                    f1 = QtConcurrent::run([&data_status,id](){
                        data_status = DB.AllTableToDB(global_data::update_allTable[id],global_data::execute_date[id],"1","1");
                    });
                }
                sleep(1000);
                f1.cancel();

                status |= data_status;
            }

            if( !status ){
                QMessageBox::warning(NULL, "参数表", "参数更改失败", "确定");
            }
            else{
                Message_alert("参数","参数修改成功",QMessageBox::Information);
                Diff_Save(id);
            }
            DB.Change_Save(id);
        }

        temp_flag = humi_flag = wind_flag =false;
    }
}

void System_Setting::on_btn_connect_clicked()
{
    static bool flag = false;
    serial->close();
    if(flag == false){
            serial->close();
            OpenSerial(ui->combox_port->currentText(), ui->comboBox_baud->currentText().toInt(), QSerialPort::Data8,QSerialPort::NoParity,QSerialPort::OneStop);
            //OpenSerial( ui->combox_port->itemText(ui->combox_port->currentIndex()),ui->comboBox_baud->currentText().toInt(), QSerialPort::Data8,QSerialPort::NoParity,QSerialPort::OneStop);

    } else{
           serial->close();
           sconFlagOk = false;
    }
    flag = !flag;

   if(sconFlagOk == false){
          if(flag == true)
            QMessageBox::warning(NULL, "警告", "串口打开失败", "确定");

           ui->btn_connect->setText("连接");
           ui->btn_connect->setStyleSheet("QPushButton {\n"
                                                     "color: rgb(255, 255, 255);\n"
                                                     "border:5px outset rgb(255,0,0);\n"
                                                     "background-color: rgb(249,121,121);\n"
                                                     "border-radius:10px;\n"
                                                     "padding:2px 4px;\n"
                                                     "}\n"

                                                     "QPushButton:hover{\n"

                                                         "color: rgb(0, 0, 0);\n"
                                                         "border:5px outset gray;\n"
                                                         "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
                                                         "border-radius:10px;\n"
                                                         "position:relative; top:1px; left:1px\n"
                                                     "}\n"

                                                     "QPushButton:pressed{\n"
                                                         "border:3px inset gray;\n"
                                                         "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
                                                         "border-bottom: 1px;\n"
                                                         "border-radius:10px;\n"
                                                     "}");
           Serial_flag = false;
           global_data::Hear_flag = 0;

           for( uint8_t i = 0 ; i < DEV ; i++ ){
               global_data::Mutual_exclusion[i] = DataBase;
           }
           serial->setPortName("");
           //设置控件无效
           Serial_show_Disable();
   }else{

          ui->btn_connect->setText("已连接");

          ui->btn_connect->setStyleSheet("QPushButton {\n"
                                                   "color: rgb(255, 255, 255);\n"
                                                   "border:5px outset rgb(85,170,0);\n"
                                                   "background-color: rgb(152,228,76);\n"
                                                   "border-radius:10px;\n"
                                                   "padding:2px 4px;\n"
                                                   "}\n"

                                                   "QPushButton:hover{\n"

                                                       "color: rgb(0, 0, 0);\n"
                                                       "border:5px outset gray;\n"
                                                       "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(188, 188, 188, 255), stop:0.50001 rgba(208, 208, 208, 255));\n"
                                                       "border-radius:10px;\n"
                                                       "position:relative; top:1px; left:1px\n"
                                                   "}\n"

                                                   "QPushButton:pressed{\n"
                                                       "border:3px inset gray;\n"
                                                       "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:180, stop:0.49999 rgba(208, 208, 208, 255), stop:0.50001 rgba(188, 188, 188, 255));\n"
                                                       "border-bottom: 1px;\n"
                                                       "border-radius:10px;\n"
                                                   "}");







          //串口连接有效标志位
           Serial_flag = true;
           //发送心跳包标志位
           global_data::Hear_flag = 1;
           Serial_show_Enable();

           for( uint8_t i = 0 ; i < DEV ; i++ ){
               global_data::Mutual_exclusion[i] = __485_Serial;
               global_data::heart_beat_count[i] = 0;
           }

   }
}

void System_Setting::on_btn_Wconnect_clicked()
{
    int num = ui->Room_Choose->currentIndex();
    int choose = ui->comboBox_wifi->currentIndex();
    if( ui->btn_Wconnect->text() == "连接"){
        if( choose == 1){
            Simple_trans(_4G_CON_STA);
        }
        else{
            if( !ui->lineEdit_passwd->text().isEmpty()){


                strcpy(send_wifi_data.pass,ui->lineEdit_passwd->text().toLocal8Bit().data());
                strcpy(send_wifi_data.name,ui->lineEdit_name->text().toLocal8Bit().data());
                qDebug()<<"wifi名字"<<send_wifi_data.name;

                memcpy(send_wifi_data.id,global_data::id[num],sizeof(send_wifi_data.id));

                qDebug()<<"wifi_name"<<send_wifi_data.name<<"wifi_data"<<send_wifi_data.pass;
                send_wifi_data.crc = CRC16_2_modbus((uint8_t*)&send_wifi_data,sizeof(SEND_WIFI_DATA_Type)-2);
                qDebug()<<"WIFI参数"<<(char *)&send_wifi_data;
                serial->write((char *)&send_wifi_data,sizeof(SEND_WIFI_DATA_Type));
                ui->btn_Wconnect->setText("连接中");
                Key_State(ui->btn_Wconnect,3);
                //设置样式表
            }
            else{
                QMessageBox::warning(NULL, "密码", "WiFi密码不能为空", "确定");
                ui->btn_Wconnect->setText("连接");
                Key_State(ui->btn_Wconnect,1);
            }

        }

    }
    else{
        Simple_trans(WIFI_CON_STOP);
        ui->btn_Wconnect->setText("连接");
        ui->btn_Wconnect->setStyleSheet("background-color: rgb(255, 23,23);font-family:'楷体';font:bold 16pt;");
    }
}

void System_Setting::on_Heat_Learn_clicked()
{
    if( ui->Heat_Learn->text() == "加热学习"){
        ui->Heat_Learn->setText("学习中");

       Simple_trans(AIR_HEAT_LEARN_STA);
        Key_State(ui->Heat_Learn,3 );
    }
    else{
        ui->Heat_Learn ->setText("加热学习");
        Simple_trans(AIR_HEAT_LEARN_END);
        Key_State(ui->Heat_Learn,1 );
    }
}

void System_Setting::on_Cold_Learn_clicked()
{
        if( ui->Cold_Learn->text() == "制冷学习"){
            ui->Cold_Learn->setText("学习中");
            Simple_trans(AIR_CLOD_LEARN_STA);
            Key_State(ui->Cold_Learn,3 );
        }
        else{
            ui->Cold_Learn->setText("制冷学习");
            Simple_trans(AIR_CLOD_LEARN_END);
            Key_State(ui->Cold_Learn,1 );
        }

}

void System_Setting::on_Close_Learn_clicked()
{
        if( ui->Close_Learn->text() == "关闭学习"){
            ui->Close_Learn->setText("学习中");
            Simple_trans(AIR_CLOSE_LEARN_STA);
            Key_State(ui->Close_Learn,3 );
        }
        else{
            ui->Close_Learn->setText("关闭学习");
            Simple_trans(AIR_CLOSE_LEARN_END);
            Key_State(ui->Close_Learn,1 );
        }
}

//void System_Setting::on_Room_Choose_currentIndexChanged(int index)
//{
//    return ;
//    ui->Modify->setText("修改");
//    show_Disable();
//    if( Serial_flag || global_data::on_line){
//        ui->groupBox_6->setEnabled(true);
//    }
//    else{
//        ui->groupBox_6->setEnabled(false);
//    }
//    //房间参数赋值
//    ui->comboBox_wifi->setCurrentIndex(room_setting[index].WIFI_4G.mode);
//    ui->btn_Wconnect->setText(room_setting[index].WIFI_4G.txt);

//    if( room_setting[index].WIFI_4G.txt == "已连接"){
//        Key_State(ui->btn_Wconnect,0);
//    }
//    else{
//        Key_State(ui->btn_Wconnect,1);
//    }
//    ui->lineEdit_passwd->setText(room_setting[index].WIFI_4G.passwd);
//    ui->lineEdit_name->setText(room_setting[index].WIFI_4G.name);


//    ui->Heat_Learn->setText(room_setting[index].Air.heat);
//    ui->Cold_Learn->setText(room_setting[index].Air.cold);
//    ui->Close_Learn->setText(room_setting[index].Air.clsoe);

//    if( "学习完成" == room_setting[index].Air.heat)
//            Key_State(ui->Heat_Learn,0);
//    else
//        Key_State(ui->Heat_Learn,1);

//    if( "学习完成" == room_setting[index].Air.cold)
//        Key_State(ui->Cold_Learn,0);
//    else
//        Key_State(ui->Cold_Learn,1);

//    if( "学习完成" == room_setting[index].Air.clsoe)
//        Key_State(ui->Close_Learn,0);
//    else
//        Key_State(ui->Close_Learn,1);

//    ui->Temp_Diff->setText(QString::number((double)global_data::update_allTable[index].set_sensor[0].temp_diff/10,'f',1));
//    ui->Humi_Diff->setText(QString::number((double)global_data::update_allTable[index].set_sensor[0].humi_diff/10,'f',1));
//    ui->WindDiff->setText(QString::number((double)global_data::update_allTable[index].set_wind_temp_diff/10,'f',1));

//    switch (global_data::control_Mode[index] / 2) {
//    case 0:
//        ui->Button_Bao->setChecked(true);
//        break;
//    case 1:
//        ui->Button_Gong->setChecked(true);
//        break;
//    case 2:
//        ui->Button_Cui->setChecked(true);
//        break;
//    default:
//        ui->Button_Bao->setChecked(true);
//        break;
//    }
//}

void System_Setting::on_comboBox_wifi_currentIndexChanged(int index)
{
    if( index == 0 ){
        qDebug()<<ui->comboBox_wifi->currentText();
        if( sconFlagOk ){
            ui->btn_Wconnect->setEnabled(true);
        }
        ui->lineEdit_passwd->setEnabled(true);
        ui->lineEdit_name->setEnabled(true);

    }
    else{
        qDebug()<<ui->comboBox_wifi->currentText();
        if( sconFlagOk ){
            ui->btn_Wconnect->setEnabled(true);
        }
        ui->lineEdit_passwd->setEnabled(false);
        ui->lineEdit_name->setEnabled(false);
    }
}


void System_Setting::on_btn_scan_clicked()
{
    ui->combox_port->clear();
    searchPort();
    ui->combox_port->addItems(portlist);

}
