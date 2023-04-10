#include "room_style.h"
#include "ui_room_style.h"
#include <QDebug>
Room_style::Room_style(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room_style)
{
    ui->setupUi(this);
    Device_Name         = ui->Device_Name1;
    mode                = ui->mode1;
    Equipment           = ui->Equipment1;

    Temperature         = ui->Temperature1;
    Humidity            = ui->Humidity1;
    temp_center         = ui->temp_center;
    humi_center         = ui->humi_center;

    Air_status          = ui->Air_status1;
    Heat_status         = ui->Heat_status1;
    Moiste_status       = ui->Moiste_status1;
    Dehumi_status       = ui->Dehumi_status1;
    Breathe_status      = ui->Breathe_status1;
    Sensitive_status    = ui->Sensitive_status1;
    Wind_status         = ui->Wind_status1;
    Disinfect_status    = ui->Disinfect_status1;
    Light_status        = ui->Light_status1;
    Setting             = ui->setting1;
    Sensor_status       = ui->Sensor_Status;

    co                  = ui->label_co;
    co2                 = ui->label_co2;
    nh3                 = ui->label_nh3;
    cio2                = ui->label_cio2;
}

Room_style::~Room_style()
{
    delete ui;
}
