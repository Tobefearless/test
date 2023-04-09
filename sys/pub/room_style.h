#ifndef ROOM_STYLE_H
#define ROOM_STYLE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
namespace Ui {
class Room_style;
}

class Room_style : public QWidget
{
    Q_OBJECT

public:
    explicit Room_style(QWidget *parent = 0);
    ~Room_style();

private:
    Ui::Room_style *ui;
public:
    QLabel *Device_Name,        //设备名字
           *mode,               //工作模式
           *Equipment,          //设备状态
           *Temperature,        //温度
           *Humidity,           //湿度
           *temp_center,        //中心温度
           *humi_center,        //中心湿度
           *Air_status,         //空调状态
           *Heat_status,        //加热状态
           *Moiste_status,      //加湿状态
           *Dehumi_status,      //除湿状态
           *Breathe_status,     //换气状态
           *Sensitive_status,   //感光状态
           *Wind_status,        //匀风状态
           *Disinfect_status,   //消毒状态
           *Light_status,       //光照状态
           *Sensor_status;
    QPushButton *Setting;
};

#endif // ROOM_STYLE_H
