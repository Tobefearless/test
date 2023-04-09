#include "historical_curve.h"
#include "ui_historical.h"
#include <iostream>
#include <QDataStream>
#include <QFile>
#include <QtMqtt/QMqttClient>
#include <QtMqtt/qmqtttopicfilter.h>

#pragma GCC diagnostic ignored "-Wwrite-strings"
const quint16 PORT = 8888;
const int DATA_STREAM_VERSION = QDataStream::Qt_4_8;

Historical_curve::Historical_curve(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Historical_curve)
{
    ui->setupUi(this);

    //mqtt初始化
    m_client = new QMqttClient();

    file_flag = false;
    fileLine = 0;
    gotLine = 0;
    file = Q_NULLPTR;
    file_count = 0;
    Recive_StaTime = 0;
    timer = new QTimer(this);

    this->setWindowTitle("历史曲线");                 //设置窗口标题
    this->setWindowIcon(QIcon(":/img/chart.png"));        //设置窗口图片
//    this->setFixedSize(this->width(),this->height());
    date_sta = ui->time_sta;
    date_end = ui->time_end;

    ui->time_sta->setCalendarPopup(true);
    ui->time_end->setCalendarPopup(true);

        //坐标轴极线条创建
    m_AxisX_Time = new QDateTimeAxis(this);//时间轴
    m_AxisY = new QValueAxis(this); //y轴
    chart = new QChart();//chart对象
    m_tem_Series = new QLineSeries  (this);//折线图数据集
    m_hum_Series = new QLineSeries  (this);

    //mqtt

    connect(m_client, &QMqttClient::messageReceived,this,&Historical_curve::topicMessageReceived);
    connect(m_client, &QMqttClient::stateChanged, this,&Historical_curve::updateLogStateChange);
    connect(timer,SIGNAL(timeout()),this,SLOT(time_Out()));
    connect(this,&Historical_curve::destroyed,[=]{
        qDebug()<<"窗口销毁了";
    });

    //赋值头、尾
    get_file.head = GET_FILE_HEAD;
    get_file.tail = GET_FILE_TAIL;

    progressDialog = nullptr;
    Device = ui->com_room;
    initial_chart();


}

Historical_curve::~Historical_curve()
{
    delete ui;
    list.clear();
    delete chart;
    delete m_client;
    qDebug()<<"窗口没有了";
}

/**
 * @brief Historical_curve::mkMutiDir
 *          creat the Dir
 * @param path  the file path
 * @return      file path
 */
QString Historical_curve::mkMutiDir(const QString path)
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
 * @brief Historical_curve::createChart
 *        creat Chart
 */
void Historical_curve::createChart()
{
    //创建图表
    QString id = QString().sprintf(R"(<html><head/><body><p><span style=" font-family:'黑体'; font-size:16pt; font-weight:600; color:#ffffff;">%s</span></p></body></html>)",global_data::id[ui->com_room->currentIndex()]);
    int day = ui->time_sta->dateTime().daysTo(ui->time_end->dateTime());

    m_AxisX_Time->setRange(ui->time_sta->dateTime(),ui->time_end->dateTime());
    if( day <= 2 ){
         m_AxisX_Time->setFormat("HH:mm");

    }
    else
    m_AxisX_Time->setFormat("M-d");
    m_AxisX_Time->setLabelsAngle(0);
    m_AxisX_Time->setTickCount(24);
    m_AxisX_Time->setTitleText("时间");
    chart->setTitle(id);
    chart->setTitleBrush(QBrush(QColor(255,255,255)));//设置标题Brush
    m_tem_Series->clear();
    m_hum_Series->clear();

}

/**
 * @brief Historical_curve::read_dat_to_chart
 *          read txt to discrible chart
 */
void Historical_curve::read_dat_to_chart()
{
    timer->stop();
    progressDialog->setWindowTitle(tr("请等待"));
    //设置进度对话框的显示文字信息
    progressDialog->setLabelText(tr("曲线绘制中"));
    //设置进度对话框的“取消”按钮的显示文字
    progressDialog->setCancelButtonText(tr("确定"));
    QDir dir(QDir::currentPath() + "/room/" + QString(global_data::id[ui->com_room->currentIndex()]));
    if( !dir.exists()){
        QMessageBox::warning(NULL, "警告", "数据文件丢失", "确定");

            return ;
    }
    QString id = QString(global_data::id[ui->com_room->currentIndex()]);// QString::number(ui->com_room->currentIndex()+1);
    QString data_id,temp,humi;
    QDateTime datatime;
    int pos = ui->com_interval->currentText().indexOf("分钟");
    qDebug()<<"pos"<<pos;
    int time_resolution = ui->com_interval->currentText().mid(0,pos-1).toInt();
    if( time_resolution == 5 || time_resolution == 10)
        time_resolution *=2;

    qDebug()<<"time_resolution"<<time_resolution;
    int count;
    double temp_record,humi_record;
    //开始日期和结束日期
    QDateTime star_time = ui->time_sta->dateTime();
    QDateTime end_time = ui->time_end->dateTime();
    QString filename;

    while(1){

            if( star_time.toTime_t() >= end_time.toTime_t() ){
                     qDebug()<<"break 跳出循环";
                     break;
                }

            filename = QDir::currentPath() + "/room/" +QString(global_data::id[ui->com_room->currentIndex()]) + "/"
                    +star_time.toString("yyyy-MM-dd") + ".txt";
            star_time = star_time.addDays(1);
            qDebug()<<"文件名称"<<filename;
            QFile file (filename);

            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
                qDebug()<<"如果这个文件打不开，就证明这个文件不存在";
                continue;
            }



            QTextStream in(&file);
            QString line1= in.readLine(); //读取全部txt文档,并归为一个字符串
            list = line1.split("/");
            //datatime = QDateTime::fromString(list[3],"yyyy-MM-dd hh:mm:ss");
            count = 0;
            temp_record = 0;
            humi_record = 0;
            while(!line1.isNull()){
                    temp = list[1];
                    humi = list[2];
                    data_id = list[0];
                    qDebug()<<"id"<<data_id;
                    if( data_id.contains(id)){
                        if( temp.toDouble() > 0 && humi.toDouble() > 0 ){
                            temp_record += temp.toDouble();
                            humi_record += humi.toDouble();
                            qDebug()<<"有数据了"<<temp_record<<humi_record<<count;
                            count++;
                        }
                    }

                    if( time_resolution == count){
                        temp = QString::number(temp_record/count,'f',2);
                        humi = QString::number(humi_record/count,'f',2);
                        qDebug()<<"添加的温度"<<temp<<"添加的湿度"<<humi<<"添加时间";
                        datatime = QDateTime::fromString(list[3],"yyyy-MM-dd hh:mm:ss");
                        m_tem_Series->append(datatime.toMSecsSinceEpoch(),temp.toDouble());
                        m_hum_Series->append(datatime.toMSecsSinceEpoch(),humi.toDouble());

                        temp_record = 0;
                        humi_record = 0;
                        count = 0;
                        sleep(1);
                    }
                 line1= in.readLine();
                 list = line1.split("/");

            }
            file.close();

        }

    progressDialog->setLabelText(tr("曲线绘制完成"));
    progressDialog->setCancelButtonText(tr("确定"));
    progressDialog->close();
    ui->pushButton->setEnabled(true);
}

/**
 * @brief Historical_curve::initial_chart
 *          initial chart
 */
void Historical_curve::initial_chart()
{

    ui->chartView->setChart(chart);

    ui->chartView->setRenderHint(QPainter::Antialiasing);

    ui->chartView->setCursor(Qt::CrossCursor); //设置鼠标指针为十字星
    chart->setBackgroundVisible(false);

    m_tem_Series->setName(R"(<html><head/><body><p><span style=" font-family:'黑体'; font-size:16pt; font-weight:600; color:#ffffff;">温度/℃</span></p></body></html>)");
    m_hum_Series->setName(R"(<html><head/><body><p><span style=" font-family:'黑体'; font-size:16pt; font-weight:600; color:#ffffff;">湿度/%</span></p></body></html>)");

    QPen    pen;
    QFont font;
    font.setPointSize(16);
    font.setFamily("SimHei");

    pen.setStyle(Qt::SolidLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
    pen.setWidth(2);
    pen.setColor(Qt::red);
    m_tem_Series->setPen(pen);
    pen.setStyle(Qt::SolidLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
    pen.setColor(Qt::blue);
    m_hum_Series->setPen(pen);


    m_AxisY->setRange(0,100);
    m_AxisY->setTickCount(20);
    //m_AxisY->setMinorTickCount(5);

    m_AxisY->setTitleText(R"(<html><head/><body><p><span style=" font-family:'黑体'; font-size:16pt; font-weight:600; color:#ffffff;">值</span></p></body></html>)");

    m_AxisY->setLabelsColor(QColor(255,255,255));
    m_AxisY->setTitleBrush(QBrush(QColor(255,255,255)));
    m_AxisY->setLabelFormat("%0.2f");

    m_AxisY->setLabelsFont(font);

    font.setPointSize(12);
    m_AxisX_Time->setRange(ui->time_sta->dateTime(),ui->time_end->dateTime());
    m_AxisX_Time->setFormat("H:m");


    //设置角度
    m_AxisX_Time->setLabelsAngle(0);

    m_AxisX_Time->setLabelsFont(font);
    m_AxisX_Time->setTickCount(24);
    m_AxisX_Time->setTitleText(R"(<html><head/><body><p><span style=" font-family:'黑体'; font-size:16pt; font-weight:600; color:#ffffff;">时间</span></p></body></html>)");
    m_AxisX_Time->setTitleBrush(QBrush(QColor(255,255,255)));
    m_AxisX_Time->setLabelsColor(QColor(255,255,255));
//    //添加曲线到chart中

    //设置数据点可见
//    m_tem_Series->setPointsVisible();
//    m_hum_Series->setPointsVisible();

    chart->addSeries(m_tem_Series);
    chart->addSeries(m_hum_Series);
//    //chart->setTheme(QtCharts::QChart::ChartThemeBrownSand);

//   // chart->legend()->hide();
    chart->legend()->setFont(font);
    chart->legend()->setAlignment(Qt::AlignRight);

    chart->addAxis(m_AxisY, Qt::AlignLeft);
    chart->addAxis(m_AxisX_Time,Qt::AlignBottom);

    m_tem_Series->attachAxis(m_AxisY);
    m_tem_Series->attachAxis(m_AxisX_Time);

    m_hum_Series->attachAxis(m_AxisY);
    m_hum_Series->attachAxis(m_AxisX_Time);
    chart->legend()->setLabelColor(QColor(255,255,255));//设置标签颜

}

/**
 * @brief Historical_curve::mqtt_connect
 *          进行mqqt链接
 */
void Historical_curve::mqtt_connect()
{
//    QDir dir(QDir::currentPath() + "/room");
//    if( !dir.exists()){
//        bool ok = dir.mkpath(QDir::currentPath() + "/room");
//        if( !ok)
//            QMessageBox::warning(NULL, "警告", "文件夹创建失败", "确定");
//            return ;
//    }


    if( !global_data::on_line ){
         QMessageBox::warning(NULL, "警告", "没有网络", "确定");
         ui->pushButton->setEnabled(true);
         return ;
    }

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        mkMutiDir(QDir::currentPath() + "/room/" + QString(global_data::id[i]));
    }

      qDebug()<<"连接";
      if(m_client->state() == QMqttClient::Disconnected){
          m_client->setClientId("123456");
          m_client->setHostname("1.14.26.239");
          //m_client->setHostname("47.96.154.99");

          m_client->setPort(1883);
          m_client->setUsername("admin");
          m_client->setPassword("czy123456");
          m_client->setWillQoS(1);

          m_client->connectToHost();

      }
      else{
          m_client->disconnectFromHost();
      }

    memset(get_file.devid,0,20);
    memcpy(get_file.devid,global_data::id[ui->com_room->currentIndex()],sizeof(get_file.devid));
}

/**
 * @brief Historical_curve::mqtt_subscribe
 *          进行mqtt订阅
 * @return  是否订阅成功
 */
bool Historical_curve::mqtt_subscribe()
{
    uint8_t id = ui->com_room->currentIndex();
    qDebug()<<"房间ID"<<id;
    qDebug()<<m_client->state();
    QString topic = "file/read_from_server/" + QString(global_data::id[id]);

    if(m_client->state() == QMqttClient::Connected){
        qDebug()<<"连接asdasdasdasdasdasdasd";

        //程序
        QMqttSubscription *subscription = m_client->subscribe(topic);
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
 * @brief Historical_curve::mqtt_publish
 *          mqtt消息发布
 * @param content   发布的地址
 */
void Historical_curve::mqtt_publish(QString content)
{
    //content = R"({'cmd':"get_file",'file_name':")" + content + ".txt\"}";
    uint8_t id = ui->com_room->currentIndex();
//    content = QString().sprintf(R"({'cmd':"get_file",'devid':"%s",'file_name':"%s"})",QString(global_data::id[id]).toUtf8().data(),
//                                QString(content + ".txt").toUtf8().data());


    content = content + ".txt";
    memset(get_file.file_name,0,sizeof(get_file.file_name));
    strcpy(get_file.file_name,content.toLatin1());
    get_file.crc = CRC16_2_modbus((uint8_t*)&get_file,sizeof(GET_FILE_TYPE)-2);


    qDebug()<<"content"<<content;
    QString topicPub = "file/write_to_server/" + QString(global_data::id[id]);


    if( m_client->state() == QMqttClient::Connected ){
        QByteArray byteArray;
        qDebug()<<topicPub;
        byteArray.append(( char *)&get_file,sizeof(GET_FILE_TYPE));
        m_client->publish(topicPub,byteArray);

        //serial->write(byteArray);
        Recive_StaTime = QDateTime::currentDateTime().toTime_t();
        qDebug()<<"开始时间"<<QDateTime::currentDateTime();
        return ;
    }
}

/**
 * @brief Historical_curve::closeEvent
 *      窗口关闭事件
 * @param event     关闭的类型
 *
 */
void Historical_curve::closeEvent(QCloseEvent *event)
{
    qDebug()<<"窗口关闭了";
    if(m_client->state() == QMqttClient::Connected){
        m_client->disconnectFromHost();
    }
    delete progressDialog;
    progressDialog   = nullptr;
    event->accept();
}

/**
 * @brief Historical_curve::isFileExist
 *          判断文件是否存在
 * @param fullFilePath  文件路径
 * @return
 */
bool Historical_curve::isFileExist(QString fullFilePath)
{
    QFile file(fullFilePath);
    if( file.exists()){
        return true;
    }
    return false;
}

/**
 * @brief Historical_curve::File_receiving_update
 *          对接收的文件进行，处理并更新文件
 */
void Historical_curve::File_receiving_update()
{
    QString filename;

    if( file!= Q_NULLPTR){
        file->close(); // 关文件
        delete file;
        file = Q_NULLPTR;
    }

    fileLine = 0;
    gotLine = 0;
    file_flag = false;
    fileName = "";

    QDateTime dTtime = QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd"),"yyyy-MM-dd");

    while( 1){
        if( file_time.toTime_t() < ui->time_end->dateTime().addDays(-1).toTime_t()){
            filename = QDir::currentPath() +"/room/" + file_time.toString("yyyy-MM-dd") + ".txt";
            if( !isFileExist(filename) || dTtime.toTime_t() == file_time.toTime_t()){
                mqtt_publish(file_time.toString("yyyy-MM-dd"));
                file_time = file_time.addDays(1);
                timer->start(10 * 1000);
                break;
            }
        }
        else{
           qDebug()<<"文件时间"<<file_time.date().toString("dd")<<"结束时间"<<ui->time_end->date().addDays(1).toString("dd");
           if( file_time.date().toString("dd") == ui->time_end->date().addDays(-1).toString("dd")){
               qDebug()<<"曲线开始显示";
               read_dat_to_chart();
               m_client->disconnectFromHost();
           }
           break;
        }
         file_time = file_time.addDays(1);
    }

    qDebug()<<"结束时间"<<QDateTime::currentDateTime();
}

/**
 * @brief Historical_curve::on_pushButton_clicked
 *          按键的回调函数，用于画图
 */
void Historical_curve::on_pushButton_clicked()
{
    //连接mqtt
    //订阅主题
    //发布
    qDebug()<<"创建表格";


    ui->pushButton->setEnabled(false);
    createChart();

    uint8_t i = 0;
    QString filename;
    //和mqtt建立连接
    mqtt_connect();
    //订阅
        while( !mqtt_subscribe()){
            sleep(100);
            i++;
            if( i >=4 ){
                break;
            }
        }


        if( !progressDialog ){
                    qDebug()<<"新建了一个进度条变量";
                    progressDialog = new QProgressDialog(this);
                    if( progressDialog == nullptr ){
                        QMessageBox::warning(NULL, "警告", "进度条申请失败", "确定");
                    }
                }

                else
                    progressDialog->show();

                qDebug()<<"天数"<<file_count;
                QFont font("ZYSong18030",12);
                progressDialog->setFont(font);
                //设置进度对话框采用模态方式进行，即显示进度的同时，其他窗口将不响应输入信号
                progressDialog->setWindowModality(Qt::WindowModal);
                //设置进度对话框出现需等待的时间，默认为4s
                progressDialog->setMinimumDuration(5);
                //设置进度对话框的窗体标题
                progressDialog->setWindowTitle(tr("请等待"));
                //设置进度对话框的显示文字信息
                progressDialog->setLabelText(tr("数据获取中..."));
                //设置进度对话框的“取消”按钮的显示文字
                progressDialog->setCancelButtonText(tr("Cancel"));
                progressDialog->setRange(0,0); //设置进度对话框的步进范围
        //sleep(500);
        if( i >= 4 ){
             QMessageBox::warning(NULL, "提示", "远端服务器连接失败", "确定");
             read_dat_to_chart();
             m_client->disconnectFromHost();
             return ;
            //return ;
        }
        uint8_t pos = ui->com_room->currentIndex();
        QDateTime dTtime = QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd"),"yyyy-MM-dd");
        file_time = ui->time_sta->dateTime();
        file_count = (ui->time_end->dateTime().toTime_t()- ui->time_sta->dateTime().toTime_t())/(3600*24);
        for( i = 0 ; i < file_count ;i++){
            filename = QDir::currentPath() +"/room/" + QString(global_data::id[pos])+"/"
                    + file_time.toString("yyyy-MM-dd") + ".txt";
            qDebug()<<"filename"<<filename;
            if( !isFileExist(filename) || dTtime.toTime_t() == file_time.toTime_t()){
                mqtt_publish(file_time.toString("yyyy-MM-dd"));
                if( !timer->isActive() )
                    timer->start(10 * 1000);
                return ;
            }
            file_time = file_time.addDays(1);
        }

        if( i == file_count ){
            read_dat_to_chart();
            m_client->disconnectFromHost();
        }
        ui->pushButton->setEnabled(true);

}

/**
 * @brief Historical_curve::topicMessageReceived
 *          用于接收mqtt的消息
 * @param message   接收的数据信息
 * @param topic     接收到的主题
 */
void Historical_curve::topicMessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    if( !file_flag ){
        qDebug()<<topic.name();
        qDebug()<<QString(message)<<"转换为16进制"<<message.toHex();
        QString string(message);
        string.prepend(message);// QByteArray转QString方法2
        qDebug()<<"字符串后一两位"<<string.right(1);
        if(   string.contains("no file",Qt::CaseSensitive) ){
            File_receiving_update();
        }
        if( string.mid(string.size()-1) == "\n" || string.mid(string.size()-1) == "")
            return;


        QStringList file_name = string.split("/");

        QDir dir(QDir::currentPath() + "/room/" + file_name[0]);
        if( !dir.exists()){
                QMessageBox::warning(NULL, "警告", "文件夹创建失败", "确定");
                return ;
        }

        qDebug()<<"创建文件";

        fileLine = string.mid(string.lastIndexOf('/')+1).toInt();
        qDebug()<<"file_name"<<file_name[1]<<"文件行数"<<string.mid(string.lastIndexOf('/')+1);
        gotLine = 0;
        file_flag = true;
        fileName = QDir::currentPath() +"/room/" + file_name[0] + "/" + file_name[1];
        qDebug()<<"文件开始接收时间"<<QDateTime::currentDateTime();

        timer->start(1000);
    }

    if(QString(message).right(1) != "\n")
        return ;

    if(!fileName.isEmpty() && file == Q_NULLPTR)
    {
        //创建文件
        file = new QFile(fileName);
        //以写的方式打开
        if(!file->open(QFile::WriteOnly)) // 打开失败
        {
            std::cerr << "*** File Open Failed ***" << std::endl;
            delete file;
            file = Q_NULLPTR;
            return;
        }
        return ;
    }
    if(file == Q_NULLPTR || QString(message).isEmpty()) // 文件未打开，不能进行后续操作
        return;


    if(gotLine < fileLine) // 文件未接收完
    {
        qDebug()<<QString(message);
        gotLine += 1;
        file->write(message);
        Recive_StaTime = QDateTime::currentDateTime().toTime_t();
    }

    if(gotLine == fileLine) // 文件接收完
    {
        qDebug()<<"文件结束";
        File_receiving_update();

    }
}

/**
 * @brief Historical_curve::updateLogStateChange
 *          mqtt链接状态改变的槽
 */
void Historical_curve::updateLogStateChange()
{
    qDebug()<<"m_client->state"<<m_client->state();

}

/**
 * @brief Historical_curve::time_Out
 *          对获取数据 超时进行的处理
 */
void Historical_curve::time_Out()
{

    if( global_data::on_line ){
            //超时判断

            if( (QDateTime::currentDateTime().toTime_t() - Recive_StaTime) > 1 ){
                 qDebug()<<"timeout";
                 File_receiving_update();
            }
    }
    else{
        progressDialog->setWindowTitle(tr("提示"));
        //设置进度对话框的显示文字信息
        progressDialog->setLabelText(tr("数据获取失败，本地读取中"));
        //设置进度对话框的“取消”按钮的显示文字
        progressDialog->setCancelButtonText(tr("确定"));
        read_dat_to_chart();
    }
}
