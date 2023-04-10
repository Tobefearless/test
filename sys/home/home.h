#ifndef USER_H
#define USER_H
#include <QMainWindow>
#include <table/set_parament1.h>

#include <QDateTime>
#include <home/historical_curve.h>
#include <QLabel>
#include <QString>
#include <QFile>
#include "QCloseEvent"

/**********界面*************/
#include "home/system_setting.h"
#include "ui_system_setting.h"
#include "home/data_report.h"
#include "home/sensor.h"
#include "home/comms_indicate.h"
#include "home/user_management.h"

#include <table/seed1.h>
#include <table/co_parenting1.h>
#include <home/help.h>

#include <ui_set_parament1.h>
#include <ui_seed1.h>
#include <ui_co_parenting1.h>

#include "thread/serialthread.h"

#include <windows.h>
#include<dbt.h>
#include<winuser.h>
#include<QAbstractNativeEventFilter>
#include <QWidget>
#include <pub/room_style.h>

/*********线程**********/
#include "thread/mythread.h"

namespace Ui {
class home;
}

class home : public QMainWindow
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

public:
        void setBackgroundImage(QString path);//设置背景图片  path：图片路径
public:
    Ui::home *ui;
private:
    bool create_connect();
    bool mqtt_subscribe(uint8_t id);

    void show_relay(QLabel *label,bool status);
    void show_air_relay(QLabel *label,uint8_t status);
    void Online_send();

    void  State_assignment(void); //控件数组赋值


    void Interface_display(uint8_t room,FROM_DB_Typedef data,
                           DataStatus method); //主页面显示


     void __485_CMD_Del(__485_CMD_Type cmd,uint8_t id);//空调 Wi-Fi状态判断


     void Device_disengaged(FROM_DB_Typedef &data);//设备断开，显示界面参数

     void setLED(QLabel* label, int color,
                 int size);             /*设备状态灯
                                 该函数将label控件变成一个圆形指示灯，需要指定颜
                                 色color以及直径sizecolor 0:grey 1:red 2:
                                 green 3:yellow size  单位是像素*/

     void UpdateTo_table();//将参数表写入刷新表中
     

     /*
        **************催青更新*******************
        将单片机传来的数据与数据库来的数据赋值给催青表格
     */
     void Cui_Rejuvenate(uint8_t room,bool assigemnt);
     void Cui_UpdateTable(uint8_t room,DataStatus status);

     /***************保种更新************************/
     void Conservation_Renewal(uint8_t room,bool assigemnt);
     void Conservation_UpdateTable(uint8_t room,DataStatus status);
     /****************共育更新******************************/
     void Cobreeding_renewal(uint8_t room,bool assigemnt);
     void Cobreeding_UpdateTable(uint8_t room,DataStatus status);

     void ModeChangeDeal(uint8_t id,bool status);

     QString Set_font_Style(char *fontsize,char *weight,
                            char *color,char *data);//设置显示字体样式


     void Sensor_show(uint8_t room);//传感器值得填写


     void Sensor_Status_Setting(uint8_t room,double temp,double humi,
                                QString tempAdjust,QString humiAdjust,
                                bool status);//传感器状态改变

     void Del_Sensor(QString id);//传感器离线删除;

     void Set_stage(uint8_t room, int stage);//赋值


     bool Device_off(uint8_t room,WORK_WAY_STATUS way);//设备关闭
     void Send_update_Message(uint8_t room);
     void List_Sensor(uint8_t room,uint8_t i);

     void Sensor_diff_Refresh(UPDATE_ALL_TABLE_TYPEDEF data);//传感器校准值刷新


     void Seed_Table_color_change(uint8_t id,int pre_stage);//改变表格颜色
     void Conservat_Table_color_change(uint8_t id,int pre_stage);
     void Cui_Table_color_change(uint8_t id,int pre_stage);

     void Default_Paremeter_Chagne();//默认参数标志位改变

     void show_Sensor_Data(FROM_SENSOR_TYPE from_sensor);

public:          //设置变量声明
     /*
        锁标志位:
        sensor_LOCK:传感器界面锁
        table_LOCK:房间表格锁
        system_LOCK:系统设置界面锁
    */

     bool sensor_LOCK;
     bool table_LOCK[DEV];
     bool system_LOCK;

    /*
        房间变量
    */
    set_parament1 *Set_parment[DEV];
    Seed *seed[DEV];
    Co_parenting * co_Parenting[DEV];

    QLabel  *communi;//通讯状态显示

    /*
     * 其他显示界面
    */
    Historical_curve *charview;
    System_Setting *system_Setting;
    Data_report *data_report;
    Sensor *sensor;
    COMMS_indicate *comms_indicate;
    User_Management *user_management;
    Help help;

    //控件数组
//    QLabel *Equipment_status[DEV],*Equipment[DEV],
//    *Temperature[DEV],*Humidity[DEV],*Heating[DEV],
//    *fall[DEV],*Air_status[DEV],*Heat_status[DEV]
//    ,*Moiste_status[DEV],*Dehumi_status[DEV],
//    *Breathe_status[DEV],*Sensitive_status[DEV],
//    *Wind_status[DEV],*Disinfect_status[DEV],
//    *Light_status[DEV],*DEVICE_name[DEV];
//    QLabel *Mode[DEV];
     Room_style *Device[DEV];
     QGridLayout *glayout;


    QLabel  *currentTimeLabel;
    /***************串口接收处理********************/

    QTimer *data_timer;//将数据写入txt文本中

    QTimer *table_timer;//更新表格的定时器

    QTimer *Heart_timer;//发送心跳包的定时器


    FROM_DB_Typedef show_data[DEV];//显示数据


    __485_CMD_Type Recive_485_cmd;//WIFI和空调结果

    __485_CMD_Type Send_485_cmd;//发送心跳包

    bool serial_oneFlag;//串口的接收第一个数据的标志位

    SEND_TIME_TAMP_Type send_time;//发送当前时间戳


    SET_SENSOR_Type set_sensor;//显示温湿度上下限的值

    QDate update_time;//更新参数表的时间变量()

    //线程
/*********处理表的数据***********/
    Mythread *myT;
    QThread *thread;

/***********处理温湿度数据*********/
    Mythread *DaT;
    QThread *thread1;

/**********处理模式变换**********/
    Mythread *ModeT;
    QThread *modeThread;

    SerialThread *serialT;

    QLabel *labelDay[DEV];


    UPDATE_ALL_TABLE_TYPEDEF temporary_send[DEV];//下发参数暂存

    int send_Failure_Status[DEV] = {0};//前一个执行阶段

    uint8_t heart_counts = 0;//心跳计时
    uint8_t sensor_heart_counts[DEV] = {0};//心跳计时
private:
        void  room_show(FROM_DB_Typedef data,uint8_t room);
        void  Delete_Sensor_Line(uint8_t row);

protected:

    void closeEvent(QCloseEvent *event);//窗口关闭事件
public slots:
        void Setting_onclick(uint8_t id);

        void timeUpdate(const QVariant info);          //更新
        void WriteTo_txt();


        void WriteTO_Sensor();//将单个传感器的数据记录在文本中


        QString mkMutiDir(const QString path);//创建多级目录

        void __485_rcv_data(QByteArray data);//接收来自485的数据

        void update_table_485();//更新表格到单片机

        void Send_Heart();//发送心跳包

        void update_SensorName(uint8_t room);//更新数据报表传感器名字


        void RoomCtrol_Change(uint8_t room);//房间模式发生改变


        void Table_Change();//数据库表发生改变

        void table_unlock();//表格锁解开

private slots:

        void on_pushButton_main_clicked();

        void on_pushButton_settting_clicked();

        void on_pushButton_chart_clicked();

        void on_pushButton_dataP_clicked();

        void on_pushButton_sensor_clicked();

        void on_pushButton_comminicat_clicked();

        void on_pushButton_manage_clicked();

        void on_pushButton_6_clicked();

        void on_pushButton_2_clicked();


        void topicMessageReceived(const QByteArray &data,
                                  const QMqttTopicName &topic);//mqtt接收消息
signals:
        void startThread();
};

#endif // USER_H
