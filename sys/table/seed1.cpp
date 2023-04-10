#include "seed1.h"
#include "ui_seed1.h"
#include "pub/controldelegate.h"
#include <QProgressDialog>
Seed::Seed(uint8_t room, QWidget *parent) :
    QMainWindow(parent),Myroom(room),
    ui(new Ui::Seed)
{
    ui->setupUi(this);

    this->setWindowTitle("保种参数设置");
    tableWiegt = ui->tableWidget;
    ui->title->setText(QString(global_data::id[Myroom]) + + "保种参数设置");
    dayChangeFlag = false;
    Write_SeedTable();
    initHeadFrame(ui->tableWidget_head,"保种时间");
    Parameter_setting();
    dayChangeFlag = true;
    execut_stage = false;

    TITLE = ui->title;
}

void Seed::Parameter_setting()
{
    //自适应表格内容，会把表格地宽度统一，表格列地宽度由45改为了100
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
  qDebug()<<"数据写入";
  int nCount = ui->tableWidget->rowCount();
  uint8_t ColCount = ui->tableWidget->columnCount();
  ui->tableWidget->setFrameShape(QFrame::NoFrame);//去除边框 尴尬
  //ui->tableWidget->setFrameShape(QFrame::WinPanel);//设置边框

  //有些表格地宽不一样，所以需要单独写
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(28, QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(30, QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(32, QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(34, QHeaderView::ResizeToContents);

//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(28, QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(30, QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(32, QHeaderView::ResizeToContents);

  //    //设置数据输入格式
  ui->tableWidget->setItemDelegateForColumn(0,new DateDelegate);
  ui->tableWidget->setItemDelegateForColumn(1,new DateDelegate());

  ui->tableWidget->setItemDelegateForColumn(3,new LindeEditDelegate(R"(2\d(\.\d)?)"));
  ui->tableWidget->setItemDelegateForColumn(4,new LindeEditDelegate(R"([3-9]\d(\.\d)?)"));

   QStringList breathList;
   breathList<<"0"<<"1"<<"2"<<"3"<<"4"
            <<"5"<<"6"<<"7"<<"8"<<"9";
   for( uint8_t j = 0 ,tempIndex = 3 ; j < 8 ; j++, tempIndex++){
      ui->tableWidget->setItemDelegateForColumn(2*tempIndex-1,new TimeDelegate());
      ui->tableWidget->setItemDelegateForColumn(2*tempIndex,new ComboboxDelegate(breathList));
  }
  breathList.clear();
  breathList<<"0"<<"5"<<"10"<<"15"<<"20"
           <<"25"<<"30"<<"35";

  for( uint8_t j = 0,tempIndex = 11 ; j < 3 ; j++ ,tempIndex++){
       ui->tableWidget->setItemDelegateForColumn(2*tempIndex-1,new TimeDelegate());
       ui->tableWidget->setItemDelegateForColumn(2*tempIndex,new TimeDelegate());
  }
  for( uint8_t j = 0 ,tempIndex = 14 ; j < 4 ; j++,tempIndex++){
      ui->tableWidget->setItemDelegateForColumn(2*tempIndex-1,new TimeDelegate());
      ui->tableWidget->setItemDelegateForColumn(2*tempIndex,new ComboboxDelegate(breathList));

  }

  for( uint8_t j = 0 ,tempIndex = 18 ; j < 3 ; j++,tempIndex++){
      ui->tableWidget->setItemDelegateForColumn(2*tempIndex-1,new TimeDelegate());
      ui->tableWidget->setItemDelegateForColumn(2*tempIndex,new TimeDelegate());
  }
      //设置内容居中
//    for( uint8_t i = 0 ; i < nCount ; i++ ){
//            ui->tableWidget->item(i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

//    }
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);

  for( uint8_t i = 0 ; i < nCount ; i++ ){
      for( uint8_t j = 0 ; j < ColCount ; j++){
          ui->tableWidget->item(i,j)->setTextColor(Qt::black);
          ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
      }
  }
}

void Seed::Parameter_write_back()
{
    qDebug()<<"软件系统文件配置"<<Myroom<<"号保种室";
}

void Seed::DataTo_txt(uint8_t stage)
{
        qDebug()<<"写进文本";
        QString strAll;
        QStringList strList;

        QString filename = QString(FILENAME) + "/seed/seed-" + QString::number(Myroom+1) + ".txt";

        QString content = "****" + QString::number(stage+1)+"****";
        QFile readFile(filename);

        if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
        {
            QTextStream stream(&readFile);
            QTextCodec *codec=QTextCodec::codecForName("GBK");
            stream.setCodec(codec);
            qDebug()<<"读取全部文件信息";
            strAll=stream.readAll();
        }

        readFile.close();
        if( strAll.isEmpty() || strAll.isNull() )
            return ;
        QFile writeFile(filename);
        if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text))
        {
                QTextStream stream(&writeFile);
                strList=strAll.split("\n");
                for(int i=0;i<strList.count();i++)
                {
                    if(i==strList.count()-1)
                    {
                        //最后一行不需要换行
                        stream<<strList.at(i);
                    }
                    else
                    {
                        stream<<strList.at(i)<<'\n';
                    }

                    if(strList.at(i).contains(content))
                    {
                        //开始日期和结束日期
                        uint8_t j = 1;

                        QString tempStr=strList.at(i+j);
                        tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,0)->text() + " "
                                        +ui->tableWidget->item(stage,1)->text()+" "+ui->tableWidget->item(stage,2)->text());
                        stream<<tempStr<<'\n';
                        j++;

                        //温度湿度
                        tempStr=strList.at(i+j);
                        tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,3)->text() + "/"+ui->tableWidget->item(stage,4)->text());
                        stream<<tempStr<<'\n';
                        j++;

                        //换气
                        for( uint8_t m = 0 ,tempIndex = 3; m < 8 ; m++,j++ ,tempIndex++){
                            tempStr=strList.at(i+j);
                            tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,2*tempIndex-1)->text() + "/" +ui->tableWidget->item(stage,2*tempIndex)->text() );
                            stream<<tempStr<<'\n';
                        }



                        //感光
                        for( uint8_t m = 0 ,tempIndex = 11; m < 3 ; m++,j++ ,tempIndex++){
                            tempStr=strList.at(i+j);
                            tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,2*tempIndex-1)->text() + "/" + ui->tableWidget->item(stage,2*tempIndex)->text() );
                            stream<<tempStr<<'\n';
                        }

                        //消毒
                        for( uint8_t m = 0 ,tempIndex = 14; m < 4 ; m++,j++,tempIndex++){
                            tempStr=strList.at(i+j);
                            tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,2*tempIndex-1)->text()+ "/" +ui->tableWidget->item(stage,2*tempIndex)->text() );
                            stream<<tempStr<<'\n';
                        }


                        //光照
                        for( uint8_t m = 0 ,tempIndex = 18; m < 3 ; m++,j++,tempIndex++){
                            tempStr=strList.at(i+j);
                            tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,2*tempIndex-1)->text()+ "/" +ui->tableWidget->item(stage,2*tempIndex)->text() );
                            stream<<tempStr<<'\n';
                        }

                        i+=(j-1);
                    }
                }
        }
        writeFile.close();

}

void Seed::setDayFlag(bool flag)
{
    dayChangeFlag = flag;
}

void Seed::Write_SeedTable()
{

    uint8_t row = 0;
    QString head = "****",line1;
    QStringList list;

    QString filename = QString(FILENAME)  + "/seed/seed-" +QString::number(Myroom+1) + ".txt";
    QFile readfile(filename);
    if( readfile.open((QIODevice::ReadOnly | QIODevice::Text))){
        QTextStream stream(&readfile);
        line1 = stream.readLine();
        while ( !line1.isNull()) {
            if( line1.contains(head)){
                line1 = stream.readLine();

                list = line1.split(" ");
                //时间
                ui->tableWidget->setItem(row,0,new QTableWidgetItem(list[0]));
                ui->tableWidget->setItem(row,1,new QTableWidgetItem(list[1]));
                ui->tableWidget->setItem(row,2,new QTableWidgetItem(list[2]));

                ui->tableWidget->item(row,0)->setBackgroundColor(global_data::date_Color);
                ui->tableWidget->item(row,1)->setBackgroundColor(global_data::date_Color);
                ui->tableWidget->item(row,2)->setBackgroundColor(global_data::day_Color);

                line1 = stream.readLine();
                list = line1.split("/");
                ui->tableWidget->setItem(row,3,new QTableWidgetItem(list[0]));
                ui->tableWidget->setItem(row,4,new QTableWidgetItem(list[1]));

                ui->tableWidget->item(row,3)->setBackgroundColor(global_data::temp_Color);
                ui->tableWidget->item(row,4)->setBackgroundColor(global_data::humi_Color);


                for( uint8_t i = 0 ,tempIndex = 3; i < 8 ; i++,tempIndex++ ){
                    line1 = stream.readLine();
                    list = line1.split("/");
                    ui->tableWidget->setItem(row,tempIndex*2-1,new QTableWidgetItem(list[0]));
                    ui->tableWidget->setItem(row,tempIndex*2,new QTableWidgetItem(list[1]));

                    ui->tableWidget->item(row,tempIndex*2-1)->setBackgroundColor(global_data::breath_Color);
                    ui->tableWidget->item(row,tempIndex*2)->setBackgroundColor(global_data::breath_Color);
                }

                for( uint8_t i = 0 ,tempIndex = 11; i < 3 ; i++ ,tempIndex++){
                    line1 = stream.readLine();
                    list = line1.split("/");
                    ui->tableWidget->setItem(row,tempIndex*2-1,new QTableWidgetItem(list[0]));
                    ui->tableWidget->setItem(row,tempIndex*2,new QTableWidgetItem(list[1]));

                    ui->tableWidget->item(row,tempIndex*2-1)->setBackgroundColor(global_data::sensitive_Color);
                    ui->tableWidget->item(row,tempIndex*2)->setBackgroundColor(global_data::sensitive_Color);
                }

                for( uint8_t i = 0 ,tempIndex = 14; i < 4 ; i++ ,tempIndex++){
                    line1 = stream.readLine();
                    list = line1.split("/");
                    ui->tableWidget->setItem(row,tempIndex*2-1,new QTableWidgetItem(list[0]));
                    ui->tableWidget->setItem(row,tempIndex*2,new QTableWidgetItem(list[1]));

                    ui->tableWidget->item(row,tempIndex*2-1)->setBackgroundColor(global_data::disinfect_Color);
                    ui->tableWidget->item(row,tempIndex*2)->setBackgroundColor(global_data::disinfect_Color);
                }

                for( uint8_t i = 0 ,tempIndex = 18; i < 3 ; i++ ,tempIndex++){
                    line1 = stream.readLine();
                    list = line1.split("/");
                    ui->tableWidget->setItem(row,tempIndex*2-1,new QTableWidgetItem(list[0]));
                    ui->tableWidget->setItem(row,tempIndex*2,new QTableWidgetItem(list[1]));

                    ui->tableWidget->item(row,tempIndex*2-1)->setBackgroundColor(global_data::illumina_Color);
                    ui->tableWidget->item(row,tempIndex*2)->setBackgroundColor(global_data::illumina_Color);
                }
            }
            row++;
            line1 = stream.readLine();
            if( line1 == "/n"){
                break;
            }
        }
    }

    readfile.close();
}

void Seed::Tbale_Send(uint8_t row)
{


    //正在执行的阶段判断
    qDebug()<<"进入表发送"<<"房间阶段"<<global_data::execute_date[Myroom].run_stage<<"时间更新标志"
           <<"阶段"<<row;
    if( execut_stage || global_data::execute_date[Myroom].run_stage == -1){
        qDebug()<<"阶段判断";

        uint8_t i ;
        uint8_t table_row = ui->tableWidget->rowCount();
        QDate curDate = QDate::currentDate(),staDate,endDate;
        QString year = curDate.toString("yyyy/");
        for( i = 0 ; i < table_row ; i++ ){
            //uint8_t temp = i % table_row;
            staDate =QDate::fromString(year + ui->tableWidget->item(i,0)->text(),
                                        "yyyy/MM/dd");
            endDate =QDate::fromString(year + ui->tableWidget->item(i,1)->text(),
                                        "yyyy/MM/dd");
            qDebug()<<"开始时间"<<staDate<<"结束时间"<<endDate;
            if( curDate.daysTo(endDate) >= 0 && staDate.daysTo(curDate)>=0 ){
                global_data::execute_date[Myroom].sta_date = staDate.toString("MM/dd");
                global_data::execute_date[Myroom].end_date = endDate.toString("MM/dd");
                global_data::execute_date[Myroom].run_stage = i;
                break;
            }
        }

        //如果超出这个范围，还没有找到的话。那么就赋值为-1
        if( i == table_row ){
            global_data::execute_date[Myroom].run_stage = -1;
        }

        execut_stage = false;
    }

    //条件不满足，退出
    if( global_data::execute_date[Myroom].run_stage < 0 ){
        return ;
    }


    QString temp;
    uint8_t stage = global_data::execute_date[Myroom].run_stage;


    global_data::update_allTable[Myroom].set_sensor[0].temp_center=
            (uint16_t)(ui->tableWidget->item(stage,3)->text().toDouble()*10+0.001);

    global_data::update_allTable[Myroom].set_sensor[0].humi_center=
            (uint16_t)(ui->tableWidget->item(stage,4)->text().toDouble()*10+0.001);


    for( uint8_t i = 0 ,tempIndex = 3; i < 8 ; i++ ,tempIndex++){
        temp = ui->tableWidget->item(stage,2*tempIndex-1)
                ->text();
        global_data::update_allTable[Myroom].set_breath[i].time_sta
                = QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
        qDebug()<<"发送的换气开始时间"<<global_data::update_allTable[Myroom].set_breath[i].time_sta;

        temp = ui->tableWidget->item(stage,2*tempIndex)->text().split("分")[0];
        global_data::update_allTable[Myroom].set_breath[i].min_len
                =temp.toInt();
    }

    for( uint8_t i = 0 ,tempIndex = 11; i < 4 ; i++ ,tempIndex++){
        if( i < 3 ){
            temp = ui->tableWidget->item(stage,2*tempIndex-1)->text();
            global_data::update_allTable[Myroom].set_sensitive[i].time_sta
                    =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
            temp = ui->tableWidget->item(stage,2*tempIndex)->text();

            global_data::update_allTable[Myroom].set_sensitive[i].time_end
                    =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
        }

            temp = ui->tableWidget->item(stage,2*tempIndex+5)->text();
            global_data::update_allTable[Myroom].set_sterilize[i].time_sta
                    =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

            temp = ui->tableWidget->item(stage,2*tempIndex+6)->text().split("分")[0];
            global_data::update_allTable[Myroom].set_sterilize[i].min_len
                    =temp.toInt();

            if( i < 3){
                temp = ui->tableWidget->item(stage,2*tempIndex+13)->text();
                global_data::update_allTable[Myroom].set_light[i].time_sta
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

                temp = ui->tableWidget->item(stage,2*tempIndex+14)->text();
                global_data::update_allTable[Myroom].set_light[i].time_end
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
            }
    }

    global_data::update_allTable[Myroom].crc =
            CRC16_2_modbus((uint8_t*)&global_data::update_allTable[Myroom],sizeof(UPDATE_ALL_TABLE_TYPEDEF)-2);

    bool status = false;
    if( global_data::Hear_flag ){
        status = update_All_table(global_data::update_allTable[Myroom]);

       }

    //将数据发送数据库
    uint8_t room = Myroom;

    if(global_data::mqtt_status)
        status |= Mqtt_publish(room,global_data::update_allTable[room]);

    if( global_data::on_line ){


        qDebug()<<"有网络，将数据发送到数据库";
        bool data_status  =false;


        QFuture<void> f1;

        if( status ){
            f1 = QtConcurrent::run([&data_status,room](){
                data_status = DB.AllTableToDB(QString(global_data::id[room]),global_data::execute_date[room]);
            });
        }
        else{
            f1 = QtConcurrent::run([&data_status,room](){
                data_status = DB.AllTableToDB(global_data::update_allTable[room],global_data::execute_date[room],"1","1");
            });
        }


        sleep(1000);
        f1.cancel();
        status |= data_status;
    }

    if( !status ){
        QMessageBox::warning(NULL, "参数表", "数据发送失败", "确定");
    }
    else{
        Message_alert("参数表","数据发送成功",QMessageBox::Information);
        //QMessageBox::information(NULL, "参数表", "数据发送成功1111", "确定");
    }
        DB.Change_Save(Myroom);
}

bool Seed::Device_Change(uint8_t room, WORK_WAY_STATUS way)
{
    sleep(1000);
    QProgressDialog dialog(tr("模式修改中"), tr("取消"), 0, 0, this);
    dialog.setWindowTitle(tr("正在修改"));     // 设置窗口标题
    dialog.setWindowModality(Qt::WindowModal);  // 将对话框设置为模态
    dialog.show();

    qDebug()<<"设备进行关闭 "<<room+1<<"号房间";
    bool status = false;
    //485发送指令
    global_data::Mode_Lock[room] = Write_Unlock;
    global_data::work_way[room].work_status = way;

    if( global_data::Hear_flag ){
        status = Write_Work_Way(global_data::work_way[room]);
    }

    QFuture<void> f1;
    if( global_data::on_line ){
        bool temp;
        if( !status ){
            f1 = QtConcurrent::run( [&temp,room](){
                    temp = DB.WORKwayToDB(global_data::work_way[room],"1");
                });
        }
        else{
            f1 = QtConcurrent::run( [&temp,room](){
                    temp = DB.WORKwayToDB(global_data::work_way[room],"0");
                });
        }

        sleep(1000);
        if( !temp ){
            DB.open("test1");
        }
        status |= temp;
    }
    f1.cancel();
    if( global_data::mqtt_status)
         Mqtt_publish(room,global_data::work_way[room]);
    if( !status )
        return false;
    uint8_t times = 0;
    while(global_data::Mode_Lock[room] == Write_Unlock)
    {
        if( times >= 8 ){
            global_data::work_way[room].work_status = global_data::control_Mode[room];
            if( global_data::on_line ){
                f1 = QtConcurrent::run([room](){
                    DB.WORKwayToDB(global_data::work_way[room],"0");
                });
                sleep(1000);
            }
            f1.cancel();
            dialog.close();
            return false;
        }
        times++;
        sleep(1000);
    }



    dialog.close();
    return true;
}

void Seed::Message_alert(QString title, QString text, QMessageBox::Icon hint)
{
    QMessageBox *box = new QMessageBox(hint,title,text);
    QTimer::singleShot(1500,box,SLOT(accept())); //也可将accept改为close

    box->exec();//box->show();都可以
    delete box;

    box = nullptr;
    qApp->processEvents();
}

void Seed::isExecuteTime()
{
    uint8_t table_row = ui->tableWidget->rowCount();
    QDate curDate = QDate::currentDate(),staDate,endDate;
    QString year = curDate.toString("yyyy/");
    QList<int> aproData;
    for( uint8_t i = 0 ; i < table_row ; i++ ){
        staDate =QDate::fromString(year + ui->tableWidget->item(i,0)->text(),
                                    "yyyy/MM/dd");
        endDate =QDate::fromString(year + ui->tableWidget->item(i,1)->text(),
                                    "yyyy/MM/dd");
        if( curDate.daysTo(endDate) >= 0 && staDate.daysTo(curDate)>=0  ){
            aproData.append(i);
        }
    }


    if( aproData.size() > 0 ){
        if( !aproData.contains(global_data::execute_date[Myroom].run_stage)){
               global_data::execute_date[Myroom].run_stage = -1;
        }
    }else{
        global_data::execute_date[Myroom].run_stage = -1;
    }

}

Seed::~Seed()
{
    delete ui;
}


void Seed::on_butto_back_clicked()
{
    Change_row.clear();
    execut_stage = false;
    emit Table_UnCLOCK();
    this->close();
}


void Seed::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    qDebug()<<"你点击了行"<<item->row()<<"列"<<item->column();
    Change_row.append(item->row());
    if( (item->column() == 1 ||item->column() == 0 ) && item->row() == global_data::execute_date[Myroom].run_stage ){
        execut_stage = true;
    }
}

void Seed::on_button_save_clicked()
{
    qDebug()<<"数据开始解析";
    QInputDialog* inputDialog=new QInputDialog(this);
    inputDialog->setWindowTitle("提示");
    inputDialog->setLabelText("参数修改");
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
        if(text == "888888"){
            isExecuteTime();
            if( global_data::execute_date[Myroom].run_stage < 0 ){
                Change_row.append(0);
            }
            else{
                Change_row.append(global_data::execute_date[Myroom].run_stage);
            }
            QString year = QDate::currentDate().toString("yyyy/");
            Change_row = Change_row.toSet().toList();
            for( uint8_t i = 0 ; i != Change_row.size() ; i++ ){
                if( Change_row[i] == global_data::execute_date[Myroom].run_stage || global_data::execute_date[Myroom].run_stage == -1){
                    //函数：void Tbale_Send(uint_8 row);
                    Tbale_Send(Change_row[i]);
                }

                //天数的计算

                ui->tableWidget->item(Change_row[i],2)->setText(QString::number(1+
                                    QDate::fromString(year + ui->tableWidget->item(Change_row[i],0)->text(),"yyyy/MM/dd")
                                    .daysTo(QDate::fromString(year + ui->tableWidget->item(Change_row[i],1)->text(),"yyyy/MM/dd"))));
                //将改变行的数据写入txt文本
                qDebug()<<"stage"<<Change_row[i];
                DataTo_txt(Change_row[i]);
            }
            //485发送指令
            if( global_data::execute_date[Myroom].run_stage >= 0 ){
               if( global_data::control_Mode[Myroom] != BAOZHONG_STA){
                   bool status =  Device_Change(Myroom, BAOZHONG_STA);
                   global_data::Mode_Lock[Myroom] = Write_lock;
                   if( status ){
                       Message_alert("提示","模式修改成功",QMessageBox::Information);
                   }
                   else{
                       QMessageBox::warning(NULL, "提示", "模式修改失败", "确定");
                   }
               }
            }
            else{
                QMessageBox::warning(NULL, "警告", "没有合适的日期更新", "确定");
            }
        }
        else{
            QMessageBox::warning(NULL, "警告", "密码输入错误", "确定");
        }
    }
    delete inputDialog;
}

void Seed::closeEvent(QCloseEvent *event)
{
    qDebug()<<"保种窗口关闭了"<<Myroom<<event->ActionChanged;
    Change_row.clear();
    execut_stage = false;
    emit Table_UnCLOCK();
}

void Seed::on_button_stop_clicked()
{
    qDebug()<<Myroom<<"号设备停止保种";
    QInputDialog inputDialog;
    inputDialog.setWindowTitle("提示");
    inputDialog.setLabelText("参数修改");
    inputDialog.setOkButtonText("确定");
    inputDialog.setCancelButtonText("取消");
    inputDialog.setTextEchoMode(QLineEdit::Password);
    bool ok;
    if(inputDialog.exec()==QDialog::Accepted){
        ok=true;
    }else{
        ok=false;
    }
    QString text=inputDialog.textValue();

    if( ok ){
        if(text == "888888"){
            if( global_data::control_Mode[Myroom] != BAOZHONG_END){
                ok = Device_Change(Myroom, BAOZHONG_END);
                global_data::Mode_Lock[Myroom] = Write_lock;
                if( ok ){
                    Message_alert("提示","模式修改成功",QMessageBox::Information);
                }
                else{
                     QMessageBox::warning(NULL, "提示", "模式修改失败", "确定");
                }
            }
            else{
                Message_alert("提示","设备已停止",QMessageBox::Warning);
                //QMessageBox::information(NULL, "提示", "当前已经是停止","确定");
            }

        }
        else{
             QMessageBox::warning(NULL, "警告", "密码输入错误", "确定");
        }
    }

}

void Seed::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if( item == nullptr )
        return ;
    if( !dayChangeFlag )
        return ;
    qDebug()<<item->row()<<"行"<<item->column()<<"列"<<item->text()<<"发生改变";
    //static uint8_t pre_row = -1;
    QString year = QDate::currentDate().toString("yyyy/");

    if( item->row() < (ui->tableWidget->rowCount() - 1) &&         ///不是最后一行
            item->column() == 1 ){ ///判断改变的列是否为结束日期

        QDate curDate = QDate::fromString(year + item->text(),"yyyy/MM/dd");///获取结束行日期


        if( curDate.month() == 12
                && curDate.day() == 31 ) //判断当前行的日期是否为终止日期12月31
            return ;
        ui->tableWidget->
                item(item->row()+1,0)->
                setText(curDate.addDays(1).toString("MM/dd"));

        QDate endDate = QDate::fromString(year +  "12/31","yyyy/MM/dd");


        ui->tableWidget->
                item(item->row()+1,1)->
                setText("12/31");

        ui->tableWidget->item(item->row()+1,2)
                ->setText(QString::number(curDate.daysTo(endDate)));


        ui->tableWidget->item(item->row()+1,0)->
                setBackground(global_data::date_Color);
        ui->tableWidget->item(item->row()+1,1)->
                setBackground(global_data::date_Color);
        ui->tableWidget->item(item->row()+1,2)->
                setBackground(global_data::day_Color);

        Change_row.append(item->row()+1);
    }
}
