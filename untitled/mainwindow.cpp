#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mTimer = new QTimer(this);
    mTimer->start(1000);

    mG_client =new QMqttClient(this);

    hear_count  = 0;
    mqtt_connect_status = false;
    cancel_sub = true;

    record_data.id = nullptr;
    connect(mTimer,&QTimer::timeout,this,&MainWindow::timeOut);

    connect(mG_client, &QMqttClient::messageReceived,
            this,&MainWindow::topicMessageReceived);//mqtt消息接收
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::create_connect()
{
    if(mG_client->state() == QMqttClient::Disconnected){

        mG_client->setHostname("1.14.26.239");//设置服务器名字(地址)


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
        return false;
    }
    else{
        return true;
    }
}

bool MainWindow::mqtt_subscribe(QString id)
{
    QString topic = "dev/recive/" +id;

    qDebug()<<"订阅"<<topic<<"mqtt连接状态"<<mG_client->state();
    if(mG_client->state() == QMqttClient::Connected){

        //程序
        QMqttSubscription *subscription = mG_client->subscribe(topic,2);

        if (!subscription) {
            QMessageBox::warning(NULL, "警告", "不能订阅，这是一个有效连接嘛？", "确定");
            return false;
        }
        qDebug()<<"订阅成功";
        return true;
    }
    return false;
}

void MainWindow::Device_disengaged(FROM_DB_Typedef &data)
{
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
}

void MainWindow::monitor_file_generate(FROM_DB_Typedef &data)
{
    mkMutiDir(QDir::currentPath()+ "/single_monitor/" + ui->lineEdit_Id->text());
    QDateTime current_date_time = QDateTime::currentDateTime();
//    current_date_time = current_date_time.addSecs(60);
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");;
    QString filename = current_date_time.toString("yyyy-MM-dd");
    filename = filename + ".txt";

    QFile file(QDir::currentPath()+ "/single_monitor/" + ui->lineEdit_Id->text()+"/"+filename);//此路径下没有就会自己创建一个
    qDebug()<<"文件路径为"<<QDir::currentPath()+ "/single_monitor/" + ui->lineEdit_Id->text()+"/"+filename;
    while(!file.open(QIODevice::ReadWrite | QIODevice::Append));//以读写切追加写入的方式操作文本
    QTextStream txtOutput(&file);

    txtOutput << data.id << "\t" <<data.temp << "\t"
              <<data.humi<<"\t"<< data.status << "\t"
             <<current_date<<"\n";

    file.close();

}

QString MainWindow::mkMutiDir(const QString path)
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

void MainWindow::timeOut()
{
    static uint8_t timeOut = 0;
    mqtt_connect_status = create_connect();
    if( cancel_sub == false ){
        hear_count++;
        if( hear_count > 20 ){
            hear_count = 0;
            Device_disengaged(record_data);
        }
    }

    timeOut++;
    if( timeOut > 60 ){
        timeOut = 0;
        monitor_file_generate(record_data);
    }
}

void MainWindow::on_pushButton_subscription_clicked()
{
    if( mqtt_connect_status == true ){

        if( !record_data.id.isNull() ){
            mG_client->unsubscribe(record_data.id);
        }

        if( mqtt_subscribe(ui->lineEdit_Id->text()) == true ){
            ui->pushButton_subscription->setText("已订阅");
            qDebug()<<"订阅成功";
            record_data.id = ui->lineEdit_Id->text();
        }
        cancel_sub = false;
    }
    else{
        QMessageBox::information(NULL,"信息","MQTT连接失败 不能进行信息订阅");
        ui->pushButton_subscription->setText("订阅");
    }
}

void MainWindow::on_pushButton_unsubscribe_clicked()
{
    QString topic = "dev/recive/" +ui->lineEdit_Id->text() + "/";

    qDebug()<<"订阅"<<topic<<"asdasdmqtt连接状111态"<<mG_client->state();
    if(mG_client->state() == QMqttClient::Connected){

        //程序
        mG_client->unsubscribe(topic);
        cancel_sub = true;
        ui->pushButton_subscription->setText("订阅");
    }
    else{
         QMessageBox::information(NULL,"信息","MQTT连接失败 取消订阅失败");
    }

}

void MainWindow::topicMessageReceived(const QByteArray &data, const QMqttTopicName &topic)
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

            qDebug()<<"名字"<< QString(from_mcu.id);

                    hear_count = 0;
                    record_data.status = ONLINE;

                    record_data.temp = QString::number((double)from_mcu.temp/10,'f',1);
                    record_data.humi = QString::number((double)from_mcu.humi/10,'f',1);

                    record_data.temp_center = QString::number((double)from_mcu.now_sensor.temp_center/10,'f',1);
                    record_data.humi_center = QString::number((double)from_mcu.now_sensor.humi_center/10,'f',1);

                    for( uint8_t i = 0 ; i < Sensor_Number ; i++ ){
                        record_data.signle_senser[i] = from_mcu.signle_senser[i];
                    }

                    record_data.air_status = from_mcu.air_status;

                    record_data.relay_status = from_mcu.relay_status;

            }
        }
}
