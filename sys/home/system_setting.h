#ifndef SYSTEM_SETTING_H
#define SYSTEM_SETTING_H

#include <QMainWindow>

namespace Ui {
class System_Setting;
}

class System_Setting : public QMainWindow
{
    Q_OBJECT

public:
    explicit System_Setting(QWidget *parent = 0);

    QStringList searchPort();
    void OpenSerial(QString portName,qint32 baudRate,QSerialPort::DataBits dataBits,
                    QSerialPort::Parity parity,QSerialPort::StopBits stopBits);

    //界面控件显示设置
    void show_Enable();
    void show_Disable();

    //串口相关控件使能
    void Serial_show_Enable();
    void Serial_show_Disable();
    //默认房间参数设置
    void Default_parameter();
    //按键状态改变
    void Key_State(QPushButton *button,uint8_t state);
    //红外发送集成
    void Simple_trans(__485_CMD_ cmd);

    //房间模式发生改变
    void Room_Ctrol_Change(uint8_t room);
    //获取RadioButton的状态
    uint8_t GetRadio_Status();
    //回差参数记录
    void Diff_Save(uint8_t room);
    bool Device_Change(uint8_t room,uint8_t way);

    void Message_alert(QString title, QString text,QMessageBox::Icon hint);
    ~System_Setting();
public slots:
    void on_btn_connect_clicked();
private slots:

    void on_Modify_clicked();

    void on_btn_Wconnect_clicked();

    void on_Heat_Learn_clicked();

    void on_Cold_Learn_clicked();

    void on_Close_Learn_clicked();

    void on_Room_Choose_currentIndexChanged(int index);

    void on_comboBox_wifi_currentIndexChanged(int index);

    void on_btn_scan_clicked();

public:
    Ui::System_Setting *ui;
    QList<QString>portlist;
    bool sconFlagOk;

    //WIFI账号与密码发送
    SEND_WIFI_DATA_Type send_wifi_data;
    //红外传感器命令发送
    __485_CMD_Type Send_485_cmd;
    //串口标志位
    bool Serial_flag;

    //保存参数
    Room_setting room_setting[DEV + 1];

    //参数改变标志
    bool temp_flag,humi_flag,wind_flag;

    //前一个状态
    uint8_t pre_workStatus[DEV];
signals:
    void Contral_adjust(uint8_t id);
};

#endif // SYSTEM_SETTING_H
