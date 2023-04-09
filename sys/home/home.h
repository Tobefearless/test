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

#include "system_setting.h"
#include "ui_system_setting.h"
#include "data_report.h"
#include "sensor.h"
#include "comms_indicate.h"
#include "user_management.h"
#include "thread/mythread.h"

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
        //设置背景图片  path：图片路径
        void setBackgroundImage(QString path);

        USARTx_RCV_Typedef recive_buff;

public:
    Ui::home *ui;
private:

     bool create_connect();
     bool mqtt_subscribe(uint8_t id);

     void show_relay(QLabel *label,bool status);
     void show_air_relay(QLabel *label,uint8_t status);

     //控件数组赋值
     void  State_assignment(void);

     //主页面显示
     void Interface_display(uint8_t room,FROM_DB_Typedef data,DataStatus method);

     //空调 Wi-Fi状态判断
     void __485_CMD_Del(__485_CMD_Type cmd,uint8_t id);

     //设备断开，显示界面参数
     void Device_disengaged(FROM_DB_Typedef &data);

     //将txt文本中的内容写入催青表格

     //设备状态灯
     // 该函数将label控件变成一个圆形指示灯，需要指定颜色color以及直径size
     // color 0:grey 1:red 2:green 3:yellow
     // size  单位是像素
     void setLED(QLabel* label, int color, int size);
     //将参数表写入刷新表中
     void UpdateTo_table();
     
     /**************催青更新*******************/
     void Cui_Rejuvenate(uint8_t room,bool assigemnt);

     //将单片机传来的数据与数据库来的数据赋值给催青表格
     void Cui_UpdateTable(uint8_t room,DataStatus status);

     /***************保种更新************************/
     void Conservation_Renewal(uint8_t room,bool assigemnt);
     void Conservation_UpdateTable(uint8_t room,DataStatus status);
     /****************共育更新******************************/
     void Cobreeding_renewal(uint8_t room,bool assigemnt);
     void Cobreeding_UpdateTable(uint8_t room,DataStatus status);

     void ModeChangeDeal(uint8_t id,bool status);
     //设置显示字体样式
     QString Set_font_Style(char *fontsize,char *weight,char *color,char *data);

     //传感器值得填写
     void Sensor_show(uint8_t room);

     //传感器状态改变
     void Sensor_Status_Setting(uint8_t room,double temp,double humi,
                                QString tempAdjust,QString humiAdjust,
                                bool status);
     //传感器离线删除;
     void Del_Sensor(QString id);
     //赋值
     void Set_stage(uint8_t room, int stage);

     //设备关闭
     bool Device_off(uint8_t room,WORK_WAY_STATUS way);
     void Send_update_Message(uint8_t room);
     void List_Sensor(uint8_t room,uint8_t i);
     //传感器校准值刷新
     void Sensor_diff_Refresh(UPDATE_ALL_TABLE_TYPEDEF data);

     //改变表格颜色
     void Seed_Table_color_change(uint8_t id,int pre_stage);
     void Conservat_Table_color_change(uint8_t id,int pre_stage);
     void Cui_Table_color_change(uint8_t id,int pre_stage);
     int ID_lookup(QString id);

     //默认参数标志位改变
     void Default_Paremeter_Chagne();

     //系统变量初始化
     void System_tray();

     //系统设置参数改变
     void System_parameter_change(UPDATE_ALL_TABLE_TYPEDEF data);
public:          //设置变量声明
    //锁标志位
     bool sensor_LOCK;
     bool table_LOCK[4];
     bool system_LOCK;
     bool room_Change;
     //房间变量
    set_parament1 *Set_parment[DEV];
    Seed *seed[DEV];
    Co_parenting * co_Parenting[DEV];
    //set_parament4 *Set_parment4;

    //系统托盘变量
    QSystemTrayIcon *m_systemTray;
    QMenu *m_menu;
    QAction *m_action1;
    QAction *m_action2;

    //通讯状态显示
    QLabel  *communi;
    //其他显示界面
    Historical_curve *charview;
    System_Setting *system_Setting;
    Data_report *data_report;
    Sensor *sensor;
    COMMS_indicate *comms_indicate;
    User_Management *user_management;
    Help help;

    //控件数组
    QLabel *Equipment_status[DEV],*Equipment[DEV],
    *Temperature[DEV],*Humidity[DEV],*Heating[DEV],
    *fall[DEV],*Air_status[DEV],*Heat_status[DEV]
    ,*Moiste_status[DEV],*Dehumi_status[DEV],
    *Breathe_status[DEV],*Sensitive_status[DEV],
    *Wind_status[DEV],*Disinfect_status[DEV],
    *Light_status[DEV],*DEVICE_name[DEV];
    QLabel *Mode[DEV],*Sensor_status[DEV];

    QComboBox *Silkworm_Area,*Silkworm_device;
    QLabel  *currentTimeLabel;
    /***************串口接收处理********************/
    //将数据写入txt文本中
    QTimer *data_timer;
    //更新表格的定时器
    QTimer *table_timer;
    //发送心跳包的定时器
    QTimer *Heart_timer;
    //QBasicTimer h_timer;

    //显示数据
    FROM_DB_Typedef show_data[DEV];

    //WIFI和空调结果
    __485_CMD_Type Recive_485_cmd;
    //发送心跳包
    __485_CMD_Type Send_485_cmd;
    //串口的接收第一个数据的标志位
    bool serial_oneFlag;
    //发送当前时间戳
    SEND_TIME_TAMP_Type send_time;

    //显示温湿度上下限的值
    SET_SENSOR_Type set_sensor;
    //更新参数表的时间变量()
    QDate update_time;

    //线程
    Mythread *myT;
    QThread *thread;

    Mythread *ModeT;
    QThread *modeThread;

    QLabel *labelDay[DEV];

    QListWidget *Abnormal_Widegt;

    bool changeRoom;
    bool DeviceChangeFlag;
    QString pre_name;
    //心跳计时
    int hear_beat = 0;

    //在线列表
    QList<EQUIP_MONITOR_TYPE> onlineDev;
private:
        void  room_show(FROM_DB_Typedef data,uint8_t room);
        void  Delete_Sensor_Line(uint8_t row);
        void  Ctronl_Drawer(bool isFlag);

       // void Status_off(FROM_DB_Typedef *data);          //全部状态关闭
        IS_WIDGET_TYPE isWidget = {false,false,false,
                                  false,false,false,
                                  false,false,false};


protected:
    //窗口关闭事件
    void closeEvent(QCloseEvent *event);
    //串口热插拔
    //bool nativeEvent(const QByteArray &eventType, void *message, long *result);

    //void timerEvent(QTimerEvent *event);

    //系统托盘函数
    void activeTray(QSystemTrayIcon::ActivationReason reason);

public slots:
        void on_setting1_clicked();

        void timeUpdate(const QVariant info);          //更新
        void WriteTo_txt();

        //将单个传感器的数据记录在文本中
        void WriteTO_Sensor();

        //创建多级目录
        QString mkMutiDir(const QString path);
        //更新表格到单片机
        void update_table_485();
        //发送心跳包
        void Send_Heart();
        //更新数据报表传感器名字
        void update_SensorName(uint8_t room);

        //房间模式发生改变
        void RoomCtrol_Change(uint8_t room);

        //数据库表发生改变
        void Table_Change();

        //表格锁解开
        void table_unlock();

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

        void on_com_area_currentIndexChanged(int index);

        void on_com_device_currentIndexChanged(int index);

        void topicMessageReceived(const QByteArray &data, const QMqttTopicName &topic);

        void on_Online_device_itemDoubleClicked(QListWidgetItem *item);

        void on_pushButton_main_title_clicked();

        void on_pushButton_setttingtitle_clicked();

        void on_pushButton_chart_title_clicked();

        void on_pushButton_dataP_title_clicked();

        void on_pushButton_sensor_title_clicked();

        void on_pushButton_comminicat_title_clicked();

        void on_pushButton_manage_title_clicked();

        void on_pushButton_help_title_clicked();

        void on_pushButton_quit_title_clicked();

signals:
        void startThread();
};

#endif // USER_H
