#include "sensor.h"
#include "ui_sensor.h"
#include "pub/controldelegate.h"
Sensor::Sensor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sensor)
{
    ui->setupUi(this);
    this->setWindowTitle("传感器");
    this->setWindowIcon(QIcon(":/img/sensor.png"));        //设置窗口图片
    //表格设定
    Parameter_setting();
    //参数头尾赋值

    sensor_table = ui->tableWidget;
    ui->tableWidget->setWindowOpacity(0.7);
}

void Sensor::Parameter_setting()
{
    qDebug()<<"表格设置";

       ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度*/
       ui->tableWidget->setItemDelegateForColumn(4,new LindeEditDelegate(R"(-?((\d\.\d)|(\d)))"));
       ui->tableWidget->setItemDelegateForColumn(5,new LindeEditDelegate(R"(-?((\d\.\d)|(\d)))"));

      int rowCount = ui->tableWidget->rowCount();
      for( uint8_t i = 0 ; i < rowCount ; i++ ){
          ui->tableWidget->removeRow(0);

      }
}

void Sensor::Sensor_Save(uint8_t room)
{
     QSettings *settings = new QSettings(QString(FILENAME) +"/config.ini", QSettings::IniFormat);
    for( uint8_t i = 0 ; i < 6 ; i++ ){
        settings->setValue("SENSOR_TEMP" + QString::number(room + 1) + "/sensor" + QString::number(i + 1),QString::number(global_data::update_allTable[room].set_senser_diff[i].temp_adjust));
        settings->setValue("SENSOR_HUMI" + QString::number(room + 1) + "/sensor" + QString::number(i + 1),QString::number( global_data::update_allTable[room].set_senser_diff[i].humi_adjust));
    }


    delete settings;
}

Sensor::~Sensor()
{
    delete ui;
}

void Sensor::on_btn_save_clicked()
{
    qDebug()<<"传感器表参数温湿度校对值开始存储";
    QInputDialog* inputDialog=new QInputDialog(this);
    inputDialog->setWindowTitle("参数修改");
    inputDialog->setLabelText("输入密码");
    inputDialog->setOkButtonText("确定");
    inputDialog->setCancelButtonText("取消");
    inputDialog->setTextEchoMode(QLineEdit::Password);
    bool ok;
    if(inputDialog->exec()==QDialog::Accepted){
        ok=true;
    }else{
        ok=false;
    }
    QString text=inputDialog->textValue();

    if( ok ){
        if( text == "888888"){
            QStringList list;
            int name,id;
            bool room_status[4] = {false};
            sensro_num = sensro_num.toSet().toList();
            for( uint8_t i = 0 ; i != sensro_num.size() ; i++ ){
                list = ui->tableWidget->item(sensro_num[i],1)->text().split("-");
                name =-1;
                //name = QString(list[0]).right(1).toInt();
                for( uint8_t j = 0 ; j < DEV ; j++ ){
                    if( QString(list[0]).contains(global_data::id[j])){
                        name = j +1;
                        break;
                    }
                }
                id = QString(list[1]).toInt();
                if( name <= 0 || id <= 0 )
                    continue;



                room_status[name-1] = true;

                double num = ui->tableWidget->item(sensro_num[i],4)->text().toDouble() * 10;
                if( num < 0 )
                    global_data::update_allTable[name-1].set_senser_diff[id-1].temp_adjust
                        = int16_t( num  - 0.001);
                else
                    global_data::update_allTable[name-1].set_senser_diff[id-1].temp_adjust
                        = int16_t( num  + 0.001);

                double num1 = ui->tableWidget->item(sensro_num[i],5)->text().toDouble() * 10;
                if( num1 < 0 )
                    global_data::update_allTable[name-1].set_senser_diff[id-1].humi_adjust
                        = int16_t( num1  - 0.001);
                else
                    global_data::update_allTable[name-1].set_senser_diff[id-1].humi_adjust
                        = int16_t( num1  + 0.001);

                qDebug()<<"房间号"<<name<<"设备ID"<<id;
            }

            for( uint8_t i = 0  ; i < 4 ; i++ ){
                if( room_status[i] ){

                    bool status  = false ;
                    if( global_data::Hear_flag ){
                        //串口数据发送
                       status =  update_All_table(global_data::update_allTable[i]);
                    }

                    if( global_data::mqtt_status ){
                        //数据库数据发送
                        bool data_status = Mqtt_publish(i,global_data::update_allTable[i]);
                        QFuture<void> f1;
                        if( status ){
                            f1 = QtConcurrent::run([&data_status,i]{
                                data_status = DB.AllTableToDB(global_data::update_allTable[i],global_data::execute_date[i]);
                            }) ;
                        }

                        else{
                            f1 = QtConcurrent::run([&data_status,i]{
                               data_status = DB.AllTableToDB(global_data::update_allTable[i],global_data::execute_date[i],"1","1");
                            });
                        }
                        sleep(1000);
                        f1.cancel();
                        if( !data_status ){
                            DB.open("test1");
                        }
                        status |= data_status;

                    }
                    if( !status ){
                        QMessageBox::warning(NULL, "参数表", "数据更新失败", "确定");
                    }
                    else{
                            Sensor_Save(i);

                            QMessageBox *box = new QMessageBox(QMessageBox::Information,"提示",QString(global_data::id[i]) + "参数发送成功");
                            QTimer::singleShot(1500,box,SLOT(accept())); //也可将accept改为close
                            box->exec();//box->show();都可以
                            delete box;
                            //box->deleteLater();
                            box = nullptr;
                            //qApp->processEvents();
                    }
                }
            }
        }
        else{
              QMessageBox::warning(NULL, "警告", "密码输入错误", "确定");
        }
    }

    sensro_num.clear();
    delete inputDialog;
}

void Sensor::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    if( item->column() == 4 || item->column() == 5 ){
        qDebug()<<"传感器校准值行改变"<<item->row();
        sensro_num.append(item->row());
    }
}
