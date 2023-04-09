/**********File Information********
**  date        author      version
**2023/04/08    shuai.xu    1.1
**
*/

#ifndef PUB_H
#define PUB_H

#include <QDebug>
#include <QString>
#include <QTime>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimeEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QMetaType>
#include <QInputDialog>
#include "QtConcurrent"
#include <QtMqtt/QMqttClient>
#include <QtMqtt/qmqtttopicfilter.h>
#include <QColor>
#include <QTableWidget>

#include <QHeaderView>
#define OFFLINE  "0"
#define ONLINE  "1"

#define STD_OFF                 (0)
#define STD_ON                  (1)

/**************software parameter**********************/
#define Send_Topic "dev/server/"
#define DEV 4                               //设备个数
#define Parameters_Times ((30*1000)/DEV)    //设备参数，访问时间，单位为:ms
#define Parameters_Udate_Times 100           //设备参数，静态刷新，多少次刷新一次
#define Equipment_Times  ((20 *1000)/DEV)   //设备温湿度访问时间
#define Pattern_Times    ((4*1000)/DEV)     //设备模式访问时间
#define ID_LENGTH 20                        //id长度
#define Sensor_Number 6                     //传感器个数
#define Ui_Alignment 2                      //房间一行的排列个树
#define FILENAME "C:/Windows/LSCS418"      //系统配置参数文件路径
#define RecordFILE "C:/Windows/Historical_data_sheet"       //文件记录路径

/********************************/
#define MODEDIFY_ENABLE     STD_ON


/**** font argument ****/
#define STR_DEVICENAME      "18pt"
#define STR_EQUIPMENT       "18pt"
#define STR_SENSOR          "16pt"
#define STR_MODE            "18pt"
#define STR_CENTER_DATA     "16pt"
#define STR_REALY           "14pt"
#define STR_REAL_DATA       "50pt"

#pragma pack(push)
#pragma pack(1)

typedef enum {
 OPEN = 1,
 CLOSE = ~OPEN
}RELAY_STATUS_Typedef;

typedef enum{
    DataBase = 0,
    __485_Serial,
    Invalid
}DataStatus;

typedef enum{
    Write_lock = false,
    Write_Unlock = true
}WRITE_LOCK;

typedef enum{
    GREY,
    RED,
    GREEN,
    YELLOW,
    BLUE
}COLOR_MODE;

/****************************定义各数据包头和尾**************************/
typedef enum{
    TABLE_HEAD          =   0XA0,
    TABLE_TAIL          =   0XA1,
    TO_APP_HEAD         =   0xA2,
    TO_APP_TAIL         =   0xA3,
    _485_CMD_HEAD       =   0xA4,
    _485_CMD_TAIL       =   0xA5,
    WIFI_SSID_HEAD      =   0xA6,
    WIFI_SSID_TAIL      =   0xA7,
    TIME_TAMP_HEAD      =   0xA8,
    TIME_TAMP_TAIL      =   0xA9,
    //修改设备的ID
    CHANGE_ID_HEAD      =   0XAA,
    CHANGE_ID_TAIL      =   0XAB,

    //获取mqtt文件
    GET_FILE_HEAD       =   0XAC,
    GET_FILE_TAIL       =   0XAD,

    //设备的工作状态
    GET_DEV_STATUS_HEAD =   0XB1,
    GET_DEV_STATUS_TAIL =   0XB2,
}HEAD_TAIL_CMD;


/*****************************一 下发到单片机的表 ***************************/
/*(一).各参数表具体类型*/
/*1.换气参数表(大端数据格式)(8条)*/

typedef struct{
    time_t  time_sta;
    uint8_t min_len;
}SET_BREATH_TypeDef;

/*2.消毒参数表(大端数据格式)(4条)*/
typedef struct{
    time_t  time_sta;
    uint8_t min_len;
}SET_STERILIZE_TypeDef;
/*3.光照参数表(大端数据格式))(3条)*/
typedef struct{
    time_t  time_sta;
    time_t  time_end;
}SET_LIGHT_TypeDef;
/*4.温湿度设定表(大端数据格式)))(1条)//保留一位小数*/
typedef struct{
    uint16_t temp_center;
    uint16_t temp_diff;
    uint16_t humi_center;
    uint16_t humi_diff;
}SET_SENSOR_Type;
/*5.感光参数表(大端数据格式)(3条)*/
typedef struct{
    time_t  time_sta;
    time_t  time_end;
}SET_SENSITIVE_TypeDef;
/*6.传感器校准值(大端数据格式)(4条)//保留一位小数*/
typedef struct{
    int16_t temp_adjust;
    int16_t humi_adjust;
}SET_SENSOR_DIFF_TypeDef;
/******************************	(二).统一各参数表和设置 **************************/
 typedef struct{
    uint8_t head;
    char id[20];
    SET_BREATH_TypeDef set_breath[8];
    SET_STERILIZE_TypeDef set_sterilize[4];
    SET_LIGHT_TypeDef set_light[3];
    SET_SENSOR_Type  set_sensor[1];
    SET_SENSITIVE_TypeDef set_sensitive[3];
    SET_SENSOR_DIFF_TypeDef set_senser_diff[6];
    uint8_t set_wind_temp_diff;
    uint8_t tail;
    uint16_t crc;
 }UPDATE_ALL_TABLE_TYPEDEF;

 /***pc端和网络端和触摸屏任意更新一个都存到flah其他全部更新***/



/*************************************** 二  控制器发送温湿度、控制状态等信息到pc端:****************************************/
/*(一)、控制器具体各参数*/
/* 1.开关状态结构体*/
typedef struct{
    uint8_t heat:1;
    uint8_t humi:1;
    uint8_t dry:1;
    uint8_t breath:1;
    uint8_t wind:1;
    uint8_t light:1;//光照状态
    uint8_t sterilize:1;//消毒状态
    uint8_t sensitive:1;//感光状态
}RELAY_Typedef;
/*2.空调状态枚举	*/
typedef enum {
    AIR_CLOSE = 0,
    AIR_HEAT = 1,
    AIR_COLD = 2,
}AIR_STATUS;

/*3.单个传感器数据*/
typedef enum{
    SENSER_OK = 0,
    SENSER_DIS_CON = 1,
    SENSER_FAIL = 2,
}SENSER_STATUS;

typedef struct{
    uint16_t signle_temp;
    uint16_t signle_humi;
    uint8_t senser_status;
}SINGLE_SENSER_Typedef;
 /*(二)、控制器最终发送各参数*/
typedef union {
    RELAY_Typedef relay;
    uint8_t relay_vale;
}RELAY;


typedef struct{
    uint8_t head; //1
    char id[20];    //20
    uint16_t temp;  //2
    uint16_t humi;  //2
    SET_SENSOR_Type now_sensor; //8
    SET_LIGHT_TypeDef next_light; //8
    SET_BREATH_TypeDef next_breath; // 5
    SET_STERILIZE_TypeDef next_sterilize;//5
    SET_SENSITIVE_TypeDef next_sensitive;//感光 8
    SINGLE_SENSER_Typedef signle_senser[6]; // 30
    uint8_t air_status; //1
    RELAY relay_status; //1
    uint8_t tail;  //1
    uint16_t crc; //2
}FROM_MCU_Typedef;

//接收16进制数，处理后的结果
typedef struct{
    QString id;
    QString temp;
    QString humi;
    QString status;
    QString temp_center;
    QString humi_center;
    QString next_light_sta;//光照
    QString next_light_end;
    QString next_breath_time;
    QString next_breath_len;
    QString next_sterilize_time;//消毒
    QString next_sterilize_len;
    QString next_sensitive_sta;//感光
    QString next_sensitive_end;
    SINGLE_SENSER_Typedef signle_senser[6];
    uint8_t air_status;
    RELAY relay_status;
}FROM_DB_Typedef;
Q_DECLARE_METATYPE(FROM_DB_Typedef)

/**************三485-控制器指令数据格式:*****************/
typedef enum{
GET_WIFI_SCAN = 0,          //发送wifi扫描指令
WIFI_CON_STA,               //连接wifi
WIFI_CON_STOP,              //断开wifi
WIFI_CON_OK,                //告诉pc端wifi连接成功
WIFI_CON_FAIL,              //连接失败
_4G_CON_STA,                //连接4G
_4G_CON_OK,                 //连接4G OK
_4G_CON_FAIL,               //连接4G 失败
AIR_HEAT_LEARN_STA,         //开始空调制热学习
AIR_HEAT_LEARN_END,         //结束空调制热学习
AIR_CLOD_LEARN_STA,         //开始空调制冷学习
AIR_CLOD_LEARN_END,         //结束空调制冷学习
AIR_CLOSE_LEARN_STA,        //开始空调关闭学习
AIR_CLOSE_LEARN_END,        //结束空调关闭学习
DEV_ALIVE_PACK,             //PC端发送心跳包
DEV_ALIVE_PACK_BACK,        //设备端回应心跳包
}__485_CMD_;


typedef struct{     //1.pc端与设备端的简易指令格式:
    uint8_t head;
    char id[20];
    uint8_t cmd;
    uint8_t tail;
    uint16_t crc;
}__485_CMD_Type;


typedef struct{         //    2.pc端向设备发送wifi的账号和密码:
    uint8_t head;
    char id[20];
    char name[30];
    char pass[30];
    uint8_t tail;
    uint16_t crc;
}SEND_WIFI_DATA_Type;



typedef struct{         //3.pc端向设备发送时间戳:
    uint8_t head;
    uint32_t time_tamp;
    uint8_t tail;
    uint16_t crc;
}SEND_TIME_TAMP_Type;

typedef struct{         //4.pc端获取mqtt文本
    uint8_t head;
    char devid[20];
    char file_name[20];
    uint8_t tail;
    uint16_t crc;
}GET_FILE_TYPE;

/********************获取保种、共育、催青状态结构体*************************/
typedef enum{
    BAOZHONG_STA = 0X00,
    BAOZHONG_END = 0X01,

    GONGYU_STA = 0X02,
    GONGYU_END = 0X03,

    CUIQING_STA = 0X04,
    CUIQING_END = 0X05,
}WORK_WAY_STATUS;

typedef struct{
    uint8_t head; //1
    char id[20];  //20
    uint8_t work_status; //1
    uint16_t reasure_count;//2
    uint8_t tail; //1
    uint16_t crc; //2
}WORK_WAY_TYEP;

#pragma pack(pop)




/************************系统设置界面，参数设置保存*******************************/
typedef struct
{
    uint8_t mode;
    QString txt;
    QString name;
    QString passwd;
}WIFI_4G_Type;

typedef struct {
    QString heat;
    QString cold;
    QString clsoe;
}Air_Learn_Type;

typedef struct {
    WIFI_4G_Type WIFI_4G;
    Air_Learn_Type Air;
}Room_setting;

#define USARTx_RCV_MAX_LEN 512
typedef struct{
char arry[USARTx_RCV_MAX_LEN];
uint16_t count;
uint16_t resid;
}USARTx_RCV_Typedef;

typedef struct{
    QString sta_date;
    QString end_date;
    int run_stage;
}EXECUTE_DATE_Typedef;

/********************全局变量参数*************************/
class global_data{
public:
    static char id[DEV][20];                //房间的ID号
    static bool update_flag;                //日期更新了的标志位
    static bool rcv_ok;                     //房间参数表是否更新完毕
    static bool Hear_flag;                  //心跳包发送标志位
    static bool room_flag[DEV];             //房间发送成功
    static bool Send_onine_flag[DEV];
    static bool on_line;                    //设备联网与未联网
    static bool update_RoomFlag[DEV];       //参数表更新到TXT文本标志位
    static uint8_t heart_beat_count[DEV];   //心跳包计数
    static uint8_t control_Mode[DEV];       //模式选择
    static UPDATE_ALL_TABLE_TYPEDEF update_allTable[DEV];   //更新的参数表
    static QDate sensor_Date;               //软件启动的天数
    static uint8_t Mutual_exclusion[DEV];   //数据库 串口互斥
    static bool Mode_Lock[DEV];             //模式锁
    static WORK_WAY_TYEP work_way[DEV];     //更新的模式
    static bool mode_rcv_flag;              //开始状态接收标志位
    static EXECUTE_DATE_Typedef execute_date[DEV];  //执行的状态
    static bool Default_flag;               //默认参数标志位
    static bool mqtt_status;                //mqtt状态
    static bool temp_flag;                  //设备状态接收完成
    static QColor date_Color;
    static QColor day_Color;
    static QColor temp_Color;
    static QColor humi_Color;
    static QColor breath_Color;
    static QColor sensitive_Color;
    static QColor disinfect_Color;
    static QColor illumina_Color;
};

enum work_Mode{baozhong,gongyu,cuiqing};
extern QSerialPort *serial;
extern  QMqttClient *mG_client;

/*****************参数界面颜色**********************/



#define  DEF_TEMP_HIG   28.0
#define  DEF_TEMP_LOW   23.0
#define  DEF_HUM_HIG    93.0
#define  DEF_HUM_LOW    56.0


uint16_t CRC16_2_modbus(unsigned char *buf, int len);

//延时
void sleep(unsigned int msec);
void Delay_MSec_Suspend(unsigned int msec);


/*******更新参数表且返回是否更新成功*******************/
bool update_All_table(UPDATE_ALL_TABLE_TYPEDEF data);
bool Write_Work_Way(WORK_WAY_TYEP data);
void Mode_Save(uint8_t id);
int ID_lookup(QString id);

int Mqtt_publish(int id,UPDATE_ALL_TABLE_TYPEDEF content);
int Mqtt_publish(int id,WORK_WAY_TYEP content);
int Mqtt_publish(int id);

//初始化表参
void initHeadFrame(QTableWidget *tableWiegt,QString tableName);
#endif // PUB_H
