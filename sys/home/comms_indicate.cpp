#include "comms_indicate.h"
#include "ui_comms_indicate.h"

COMMS_indicate::COMMS_indicate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::COMMS_indicate)
{
    ui->setupUi(this);
    this->setWindowTitle("通讯显示");                 //设置窗口标题
    this->setWindowIcon(QIcon(":/img/communication.png"));        //设置窗口图片
    start_flag = true;
    list_show = ui->listWidget;
    ui->listWidget->setWindowOpacity(0.7);
}

COMMS_indicate::~COMMS_indicate()
{
    delete ui;
}

void COMMS_indicate::on_pushButton_clicked()
{
    if( ui->pushButton->text() == "暂停"){
        start_flag = false;
        ui->pushButton->setText("显示");
//        qDebug()<<start_flag;
    }
    else{
        start_flag = true;
        ui->pushButton->setText("暂停");
//        qDebug()<<start_flag;
    }
}
