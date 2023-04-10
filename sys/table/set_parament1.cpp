#include "set_parament1.h"
#include "ui_set_parament1.h"
#include "pub/controldelegate.h"

#include <QProgressDialog>
set_parament1::set_parament1(uint8_t room, QWidget *parent) :
    QMainWindow(parent),Myroom(room),
    ui(new Ui::set_parament1)
{
    ui->setupUi(this);
    tableWidget = ui->tableWidget;
    WriteTo_Table();
    initCuiHeadFrame();
    Parameter_setting();
    Change_row.clear();
    ui->title->setText(QString(global_data::id[Myroom]) + "催青参数设置");
    execut_stage = false;
    firstCopyFlag = false;

    TITLE = ui->title;
}

void set_parament1::Parameter_setting()
{
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    qDebug()<<"数据写入";
    int nCount = ui->tableWidget->rowCount();
    uint8_t ColCount = ui->tableWidget->columnCount();
//    for( uint8_t i = 0 ; i < nCount ; i++ ){
//        ui->tableWidget->setColumnWidth(ColCount,400);
//    }
    ui->tableWidget->setFrameShape(QFrame::NoFrame);//去除边框 尴尬
    //ui->tableWidget->setFrameShape(QFrame::WinPanel);//设置边框

//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(27, QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(29, QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(31, QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(33, QHeaderView::ResizeToContents);

    //    //设置数据输入格式
        ui->tableWidget->setItemDelegateForColumn(0,new DateDelegate());
        ui->tableWidget->setItemDelegateForColumn(1,new DateDelegate());

        ui->tableWidget->setItemDelegateForColumn(2,new LindeEditDelegate(R"(2\d(\.\d)?)"));
        ui->tableWidget->setItemDelegateForColumn(3,new LindeEditDelegate(R"([3-9]\d(\.\d)?)"));

         QStringList breathList;
         breathList<<"0"<<"1"<<"2"<<"3"<<"4"
                 <<"5"<<"6"<<"7"<<"8"<<"9";
        for( uint8_t j = 0 ,tempIndex = 2 ; j < 8 ; j++, tempIndex++){
            ui->tableWidget->setItemDelegateForColumn(2*tempIndex,new TimeDelegate());
            ui->tableWidget->setItemDelegateForColumn(2*tempIndex + 1,new ComboboxDelegate(breathList));
        }
        breathList.clear();
        breathList<<"0"<<"5"<<"10"<<"15"<<"20"
                    <<"25"<<"30"<<"35";
        for( uint8_t j = 0 ,tempIndex = 10 ; j < 4 ; j++,tempIndex++){
            ui->tableWidget->setItemDelegateForColumn(2*tempIndex+6,new TimeDelegate());
            ui->tableWidget->setItemDelegateForColumn(2*tempIndex + 7,new ComboboxDelegate(breathList));

            if( j < 3 ){
                ui->tableWidget->setItemDelegateForColumn(2*tempIndex,new TimeDelegate());
                ui->tableWidget->setItemDelegateForColumn(2*tempIndex + 1,new TimeDelegate());
                ui->tableWidget->setItemDelegateForColumn(2*tempIndex + 14 ,new TimeDelegate());
                ui->tableWidget->setItemDelegateForColumn(2*tempIndex + 15,new TimeDelegate());

            }
        }



        //设置内容居中
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);

        for( uint8_t i = 0 ; i < nCount ; i++ ){
            for( uint8_t j = 0 ; j < ColCount ; j++){
                ui->tableWidget->item(i,j)->setTextColor(Qt::black);
                ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
            }
        }

}

set_parament1::~set_parament1()
{
    delete ui;
}

void set_parament1::Tbale_Send(uint8_t row)
{

    //正在执行的阶段判断
    qDebug()<<"进入表发送"<<"房间阶段"<<global_data::execute_date[Myroom].run_stage<<"时间更新标志"
           <<"阶段"<<row;

    if( execut_stage || global_data::execute_date[Myroom].run_stage == -1){

        uint8_t i;
        uint8_t table_row = ui->tableWidget->rowCount();
        QDate curDate = QDate::currentDate(),staDate,endDate;
        QString year = curDate.toString("yyyy/");

        for( i = 0 ; i < table_row ; i++ ){

            //uint8_t temp = i % table_row;
            staDate =QDate::fromString(year + ui->tableWidget->item(i,0)->text(),
                                        "yyyy/MM/dd");
            endDate =QDate::fromString(year + ui->tableWidget->item(i,1)->text(),
                                        "yyyy/MM/dd");

            if( curDate.daysTo(endDate) == 0 && staDate.daysTo(curDate)==0  )
            {
                global_data::execute_date[Myroom].sta_date = staDate.toString("MM/dd");
                global_data::execute_date[Myroom].end_date = endDate.toString("MM/dd");
                global_data::execute_date[Myroom].run_stage = i;
                break;
            }
        }
        execut_stage = false;
        if( i == table_row ){
            global_data::execute_date[Myroom].run_stage = -1;
            qDebug()<<"阶段数"<<global_data::execute_date[Myroom].run_stage;
            //return ;
        }

        if( global_data::execute_date[Myroom].run_stage != -1 ){
            staDate =QDate::fromString(year + ui->tableWidget->item(i,0)->text(),
                                        "yyyy/MM/dd").addDays(1);

            for(i = i+1; i < table_row ; i++ )
            {
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(staDate.toString("MM/dd")));
                ui->tableWidget->item(i,0)->setBackgroundColor(global_data::date_Color);
                ui->tableWidget->item(i,1)->setBackgroundColor(global_data::date_Color);
                staDate = staDate.addDays(1);
                DataTo_txt(i);
            }

            if( firstCopyFlag ){        /* 当目前的执行行数发生了变化时，开启对代码的复制操作*/
                 Copy_Parameter(global_data::execute_date[Myroom].run_stage); ///参数复制
                 firstCopyFlag = false;
            }
        }

    }


    if( global_data::execute_date[Myroom].run_stage != -1 ){
                Get_Row_Parameter(global_data::execute_date[Myroom].run_stage,
                                  global_data::update_allTable[Myroom]);
//        QString temp;
//        uint8_t stage = global_data::execute_date[Myroom].run_stage;

//        global_data::update_allTable[Myroom].set_sensor[0].temp_center=
//                (uint16_t)(ui->tableWidget->item(stage,2)->text().toDouble()*10+0.001);

//        global_data::update_allTable[Myroom].set_sensor[0].humi_center=
//                (uint16_t)(ui->tableWidget->item(stage,3)->text().toDouble()*10+0.001);

//        for( uint8_t i = 0 ,tempIndex = 2; i < 8 ; i++ ,tempIndex++){
//            temp = ui->tableWidget->item(stage,2*tempIndex)
//                    ->text();

//            global_data::update_allTable[Myroom].set_breath[i].time_sta
//                    = QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
//            qDebug()<<"发送的换气开始时间"<<global_data::update_allTable[Myroom].set_breath[i].time_sta;

//            temp = ui->tableWidget->item(stage,2*tempIndex+1)->text().split("分")[0];
//            global_data::update_allTable[Myroom].set_breath[i].min_len
//                    =temp.toInt();
//        }

//        for( uint8_t i = 0 ,tempIndex = 10; i < 4 ; i++ ,tempIndex++){
//            if( i < 3 ){
//                temp = ui->tableWidget->item(stage,2*tempIndex)->text();
//                global_data::update_allTable[Myroom].set_sensitive[i].time_sta
//                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
//                temp = ui->tableWidget->item(stage,2*tempIndex+1)->text();

//                global_data::update_allTable[Myroom].set_sensitive[i].time_end
//                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
//            }

//                temp = ui->tableWidget->item(stage,2*tempIndex+6)->text();
//                global_data::update_allTable[Myroom].set_sterilize[i].time_sta
//                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

//                temp = ui->tableWidget->item(stage,2*tempIndex+7)->text().split("分")[0];
//                global_data::update_allTable[Myroom].set_sterilize[i].min_len
//                        =temp.toInt();

//                if( i < 3){
//                    temp = ui->tableWidget->item(stage,2*tempIndex+14)->text();
//                    global_data::update_allTable[Myroom].set_light[i].time_sta
//                            =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

//                    temp = ui->tableWidget->item(stage,2*tempIndex+15)->text();
//                    global_data::update_allTable[Myroom].set_light[i].time_end
//                            =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
//                }
//        }
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

    if( global_data::execute_date[Myroom].run_stage != -1 ){
        if( !status ){

            QMessageBox::warning(NULL, "参数表", "数据发送失败", "确定");
        }
        else{
            Message_alert("参数表","数据发送成功",QMessageBox::Information);
        }

        DB.Change_Save(Myroom);
    }
}

void set_parament1::WriteTo_Table()
{
    uint8_t row = 0;
    QString head = "****",line1;
    QStringList list;
//    QByteArray qa2((char *)global_data::id[Myroom],20);
//    QString name(qa2);

      QString filename = QString(FILENAME) + "/Cui/Cui-" +QString::number(Myroom+1) + ".txt";
//    QString filename = ":/img/Cui-" +QString::number(Myroom+1) + ".txt";

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
                ui->tableWidget->item(row,0)->setBackgroundColor(global_data::date_Color);
                ui->tableWidget->item(row,1)->setBackgroundColor(global_data::date_Color);

                line1 = stream.readLine();
                list = line1.split("/");
                ui->tableWidget->setItem(row,2,new QTableWidgetItem(list[0]));
                ui->tableWidget->setItem(row,3,new QTableWidgetItem(list[1]));
                ui->tableWidget->item(row,2)->setBackgroundColor(global_data::temp_Color);
                ui->tableWidget->item(row,3)->setBackgroundColor(global_data::humi_Color);

                for( uint8_t i = 0 ,tempIndex = 2; i < 8 ; i++,tempIndex++ ){
                    line1 = stream.readLine();
                    list = line1.split("/");
                    ui->tableWidget->setItem(row,tempIndex*2,new QTableWidgetItem(list[0]));
                    ui->tableWidget->setItem(row,tempIndex*2+1,new QTableWidgetItem(list[1]));
                    ui->tableWidget->item(row,tempIndex*2)->setBackgroundColor(global_data::breath_Color);
                    ui->tableWidget->item(row,tempIndex*2+1)->setBackgroundColor(global_data::breath_Color);
                }

                for( uint8_t i = 0 ,tempIndex = 10; i < 3 ; i++ ,tempIndex++){
                    line1 = stream.readLine();
                    list = line1.split("/");
                    ui->tableWidget->setItem(row,tempIndex*2,new QTableWidgetItem(list[0]));
                    ui->tableWidget->setItem(row,tempIndex*2+1,new QTableWidgetItem(list[1]));
                    ui->tableWidget->item(row,tempIndex*2)->setBackgroundColor(global_data::sensitive_Color);
                    ui->tableWidget->item(row,tempIndex*2+1)->setBackgroundColor(global_data::sensitive_Color);
                }

                for( uint8_t i = 0 ,tempIndex = 13; i < 4 ; i++ ,tempIndex++){
                    line1 = stream.readLine();
                    list = line1.split("/");
                    ui->tableWidget->setItem(row,tempIndex*2,new QTableWidgetItem(list[0]));
                    ui->tableWidget->setItem(row,tempIndex*2+1,new QTableWidgetItem(list[1]));
                    ui->tableWidget->item(row,tempIndex*2)->setBackgroundColor(global_data::disinfect_Color);
                    ui->tableWidget->item(row,tempIndex*2+1)->setBackgroundColor(global_data::disinfect_Color);
                }

                for( uint8_t i = 0 ,tempIndex = 17; i < 3 ; i++ ,tempIndex++){
                    line1 = stream.readLine();
                    list = line1.split("/");
                    ui->tableWidget->setItem(row,tempIndex*2,new QTableWidgetItem(list[0]));
                    ui->tableWidget->setItem(row,tempIndex*2+1,new QTableWidgetItem(list[1]));

                    ui->tableWidget->item(row,tempIndex*2)->setBackgroundColor(global_data::illumina_Color);
                    ui->tableWidget->item(row,tempIndex*2+1)->setBackgroundColor(global_data::illumina_Color);
                }
            }
            row++;
            line1 = stream.readLine();
            if( line1 == "/n"){
                break;
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, "错误","文件打开失败", "确定");
    }

    readfile.close();
}

bool set_parament1::Device_Change(uint8_t room, WORK_WAY_STATUS way)
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

void set_parament1::isExecuteTime()
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
        if( curDate.daysTo(endDate) == 0 && staDate.daysTo(curDate)==0  ){
            aproData.append(i);
        }
    }

    //判断表中是否有可执行阶段
    if( aproData.size() > 0 ){
        if( !aproData.contains(global_data::execute_date[Myroom].run_stage)){
               global_data::execute_date[Myroom].run_stage = -1;
        }
    }else{
        //没有则，将当前的可执行阶段设为-1
        global_data::execute_date[Myroom].run_stage = -1;
    }


}

void set_parament1::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    qDebug()<<"行"<<item->row()<<"列"<<item->column();
    Change_row.append(item->row());
    if( global_data::execute_date[Myroom].run_stage == item->row() && (item->column() == 1 ||
                                                      item->column() == 0)){
        execut_stage = true;
        firstCopyFlag = true;
    }
}

void set_parament1::on_button_save_clicked()
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
        if( text == "888888"){
            isExecuteTime();
            if( global_data::execute_date[Myroom].run_stage < 0 ){
                Change_row.append(0);
            }
            else{
                //Change_row.append(global_data::execute_date[Myroom].run_stage);
            }

            Change_row = Change_row.toSet().toList();
            for( uint8_t i = 0 ; i != Change_row.size() ; i++ ){
                qDebug()<<"改变行数"<<Change_row[i]<<"执行阶段数"<<global_data::execute_date[Myroom].run_stage;
                if( Change_row[i] == global_data::execute_date[Myroom].run_stage || global_data::execute_date[Myroom].run_stage == -1){
                    //函数：void Tbale_Send(uint_8 row);
                    Tbale_Send(Change_row[i]);
                }

                //将改变行的数据写入txt文本
                DataTo_txt(Change_row[i]);
            }

            //485发送指令

            if( global_data::execute_date[Myroom].run_stage >= 0){
                if( global_data::control_Mode[Myroom] != CUIQING_STA){
                    bool status = Device_Change(Myroom, CUIQING_STA);
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
                QMessageBox::warning(NULL, "警告", "没有合适的日期执行", "确定");
            }

        }
        else{
            QMessageBox::warning(NULL, "警告", "密码输入错误", "确定");
        }
    }

    Change_row.clear();
    delete inputDialog;

}

//将表格数据写入TXT文本中
void set_parament1::DataTo_txt(uint8_t stage)
{

        qDebug()<<Myroom+1<<"号房间，数据开始存入";
        QString strAll;
        QStringList strList;

//        QByteArray qa2((char *)global_data::id[Myroom],20);
//        QString qstr(qa2);
        QString filename = QString(FILENAME)  + "/Cui/Cui-" + QString::number(Myroom+1) + ".txt";

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
        else
        {
            QMessageBox::warning(NULL, "错误", "配置文件损坏", "确定");
            return ;
        }

        readFile.close();
        if( strAll.isEmpty() || strAll.isNull() )
            return ;

        QFile writeFile(filename);
        qDebug()<<"权限"<<(int)writeFile.permissions();
//        writeFile.setPermissions(QFile::ReadOther | QFile::WriteOther);
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
                                        +ui->tableWidget->item(stage,1)->text());
                        stream<<tempStr<<'\n';

                        j++;
                        //温度湿度
                        tempStr=strList.at(i+j);
                        tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,2)->text() + "/"+ui->tableWidget->item(stage,3)->text());
                        stream<<tempStr<<'\n';

                        j++;

                        //换气
                        for( uint8_t m = 0 ,tempIndex = 2; m < 8 ; m++,j++ ,tempIndex++){
                            tempStr=strList.at(i+j);
                            tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,2*tempIndex)->text() + "/" +ui->tableWidget->item(stage,2*tempIndex+1)->text() );
                            stream<<tempStr<<'\n';
                        }

                        //感光
                        for( uint8_t m = 0 ,tempIndex = 10; m < 3 ; m++,j++ ,tempIndex++){
                            tempStr=strList.at(i+j);
                            tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,2*tempIndex)->text() + "/" + ui->tableWidget->item(stage,2*tempIndex+1)->text() );
                            stream<<tempStr<<'\n';
                        }

                        //消毒
                        for( uint8_t m = 0 ,tempIndex = 13; m < 4 ; m++,j++,tempIndex++){
                            tempStr=strList.at(i+j);
                            tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,2*tempIndex)->text()+ "/" +ui->tableWidget->item(stage,2*tempIndex+1)->text() );
                            stream<<tempStr<<'\n';
                        }

                        for( uint8_t m = 0 ,tempIndex = 17; m < 3 ; m++,j++ ,tempIndex++){
                            tempStr=strList.at(i+j);
                            tempStr.replace(0,tempStr.length(),ui->tableWidget->item(stage,2*tempIndex)->text() + "/" + ui->tableWidget->item(stage,2*tempIndex+1)->text() );
                            stream<<tempStr<<'\n';
                        }
                        i+=(j-1);
                    }
                }
                writeFile.close();
        }
        else
        {
            QMessageBox::warning(NULL, "错误", "写文件失败", "确定");
            return ;
        }


}

void set_parament1::Message_alert(QString title, QString text, QMessageBox::Icon hint)
{
    QMessageBox *box = new QMessageBox(hint,title,text);
    QTimer::singleShot(1500,box,SLOT(accept())); //也可将accept改为close
    box->exec();//box->show();都可以
    delete box;
    //box->deleteLater();
    box = nullptr;
    qApp->processEvents();
}

void set_parament1::initCuiHeadFrame()
{
    ui->tableWidget_head->setEnabled(false);
    ui->tableWidget_head->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度

    //ui->tableWidget->setStyleSheet("QTableWidget::item{border:1px solid ;}");
   // ui->tableWidget->horizontalHeader()->setVisible(false);//表头不可见
    //ui->tableWidget->verticalHeader()->setVisible(false);//表头不可见
    //ui->tableWidget->setShowGrid(false);//网格线不可见
    ui->tableWidget_head->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置单元格不可编辑
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);//最后一个单元格扩展
    ui->tableWidget_head->setFocusPolicy(Qt::NoFocus);//解决选中虚框问题
    ui->tableWidget_head->setFrameShape(QFrame::NoFrame);//去除边框 尴尬
    ui->tableWidget_head->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏滚动条
    ui->tableWidget_head->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//

    ui->tableWidget_head->setColumnCount(40);//header10列
    ui->tableWidget_head->setRowCount(3);//header2行

    ui->tableWidget_head->setRowHeight(0, 20);//第一行设置高度20px
    ui->tableWidget_head->setRowHeight(1, 20);//第二行设置高度20px
    ui->tableWidget_head->setRowHeight(2, 75);//第二行设置高度75px

    ui->tableWidget_head->setSpan(0, 0, 2, 2);//催青时间
    ui->tableWidget_head->setSpan(0, 2, 3, 1);//温度设置
    ui->tableWidget_head->setSpan(0, 3, 3, 1);//湿度设置

    ui->tableWidget_head->setSpan(0, 4, 1, 16);//换气

    ui->tableWidget_head->setSpan(0, 20, 1, 6);//感光

    ui->tableWidget_head->setSpan(0, 26, 1, 8);//消毒

    ui->tableWidget_head->setSpan(0, 34, 1, 6);//光照

    /******************第二行**************************/
//     ui->tableWidget->setSpan(1,0 , 2, 1);//开始
//     ui->tableWidget->setSpan(1,1 , 2, 1);//结束

     uint8_t i = 0;
     QStringList list ;
     list<<"第一次"<<"第二次"<<"第三次"<<"第四次"<<"第五次"<<
           "第六次"<<"第七次"<<"第八次";
     for( i  = 4 ; i < 2*8+4 ; i+=2 ){
         ///换气
         ui->tableWidget_head->setSpan(1,i,1,2);
         ui->tableWidget_head->setItem(1, i, new QTableWidgetItem(list.at((i-5)/2)));
         ui->tableWidget_head->item(1,i)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(1, i)->setBackground(global_data::breath_Color);
         ui->tableWidget_head->item(1, i)->setTextColor(Qt::black);

         ///换气开始与结束
         ui->tableWidget_head->setItem(2, i, new QTableWidgetItem("开始时间"));
         ui->tableWidget_head->item(2,i)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(2, i)->setBackground(global_data::breath_Color);

         ui->tableWidget_head->setItem(2, i+1, new QTableWidgetItem("运行时间(分)"));
         ui->tableWidget_head->item(2,i+1)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(2, i+1)->setBackground(global_data::breath_Color);

         ui->tableWidget_head->item(2, i)->setTextColor(Qt::black);
         ui->tableWidget_head->item(2, i+1)->setTextColor(Qt::black);
     }

     //感光
     uint8_t j = i;
     for( ; i < 2*3+j ; i+=2 ){
         ///感光
         ui->tableWidget_head->setSpan(1,i,1,2);
         ui->tableWidget_head->setItem(1, i, new QTableWidgetItem(list.at((i-j)/2)));
         ui->tableWidget_head->item(1,i)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(1, i)->setBackground(global_data::sensitive_Color);
         ui->tableWidget_head->item(1, i)->setTextColor(Qt::black);


         ///感光开始与结束
         ui->tableWidget_head->setItem(2, i, new QTableWidgetItem("开始时间"));
         ui->tableWidget_head->item(2,i)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(2, i)->setBackground(global_data::sensitive_Color);

         ui->tableWidget_head->setItem(2, i+1, new QTableWidgetItem("结束时间"));
         ui->tableWidget_head->item(2,i+1)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(2, i+1)->setBackground(global_data::sensitive_Color);

         ui->tableWidget_head->item(2, i)->setTextColor(Qt::black);
         ui->tableWidget_head->item(2, i+1)->setTextColor(Qt::black);


     }

     //消毒
     j = i;
     for( ; i < 2*4+j ; i+=2 ){
         //消毒
         ui->tableWidget_head->setSpan(1,i,1,2);
         ui->tableWidget_head->setItem(1, i, new QTableWidgetItem(list.at((i-j)/2)));
         ui->tableWidget_head->item(1,i)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(1, i)->setBackground(global_data::disinfect_Color);
         ui->tableWidget_head->item(1, i)->setTextColor(Qt::black);


         //消毒开始与结束
         ui->tableWidget_head->setItem(2, i, new QTableWidgetItem("开始时间"));
         ui->tableWidget_head->item(2,i)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(2, i)->setBackground(global_data::disinfect_Color);

         ui->tableWidget_head->setItem(2, i+1, new QTableWidgetItem("运行时间(分)"));
         ui->tableWidget_head->item(2,i+1)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(2, i+1)->setBackground(global_data::disinfect_Color);

         ui->tableWidget_head->item(2, i)->setTextColor(Qt::black);
         ui->tableWidget_head->item(2, i+1)->setTextColor(Qt::black);
     }

     //光照
     j = i;
     for( ; i < 2*3+j ; i+=2 ){
         ///光照
         ui->tableWidget_head->setSpan(1,i,1,2);
         ui->tableWidget_head->setItem(1, i, new QTableWidgetItem(list.at((i-j)/2)));
         ui->tableWidget_head->item(1,i)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(1, i)->setBackground(global_data::illumina_Color);
         ui->tableWidget_head->item(1, i)->setTextColor(Qt::black);

         ///光照开始与结束
         ui->tableWidget_head->setItem(2, i, new QTableWidgetItem("开始时间"));
         ui->tableWidget_head->item(2,i)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(2, i)->setBackground(global_data::illumina_Color);

         ui->tableWidget_head->setItem(2, i+1, new QTableWidgetItem("结束时间"));
         ui->tableWidget_head->item(2,i+1)->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget_head->item(2, i+1)->setBackground(global_data::illumina_Color);

         ui->tableWidget_head->item(2, i)->setTextColor(Qt::black);
         ui->tableWidget_head->item(2, i+1)->setTextColor(Qt::black);
     }

    //ui->tableWidget->setEnabled(false);

    ui->tableWidget_head->setItem(0, 0, new QTableWidgetItem("催青时间"));
    ui->tableWidget_head->item(0, 0)->setBackground(global_data::date_Color);
    ui->tableWidget_head->item(0,0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_head->item(0, 0)->setTextColor(Qt::black);

    i = 2;
    ui->tableWidget_head->setItem(0, i, new QTableWidgetItem("温度设置(℃)"));
    ui->tableWidget_head->item(0, i)->setBackground(global_data::temp_Color);
    ui->tableWidget_head->item(0, i)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_head->item(0, i)->setTextColor(Qt::black);
//    ui->tableWidget->setColumnWidth(3,40);
//    ui->tableWidget->setColumnWidth(4,40);
    i++;


    ui->tableWidget_head->setItem(0, i, new QTableWidgetItem("湿度设置(%)"));
    ui->tableWidget_head->item(0, i)->setBackground(global_data::humi_Color);
    ui->tableWidget_head->item(0, i)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_head->item(0, i)->setTextColor(Qt::black);
    i++;
    ui->tableWidget_head->setItem(0, i, new QTableWidgetItem("换气"));
    ui->tableWidget_head->item(0, i)->setBackground(global_data::breath_Color);
    ui->tableWidget_head->item(0, i)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_head->item(0, i)->setTextColor(Qt::black);


    ui->tableWidget_head->setItem(0, 20, new QTableWidgetItem("感光"));
    ui->tableWidget_head->item(0, 20)->setBackground(global_data::sensitive_Color);
    ui->tableWidget_head->item(0, 20)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_head->item(0, 20)->setTextColor(Qt::black);

    ui->tableWidget_head->setItem(0, 26, new QTableWidgetItem("消毒"));
    ui->tableWidget_head->item(0, 26)->setBackground(global_data::disinfect_Color);
    ui->tableWidget_head->item(0, 26)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_head->item(0, 26)->setTextColor(Qt::black);

    ui->tableWidget_head->setItem(0, 34, new QTableWidgetItem("光照"));
    ui->tableWidget_head->item(0, 34)->setBackground(global_data::illumina_Color);
    ui->tableWidget_head->item(0, 34)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_head->item(0, 34)->setTextColor(Qt::black);

    ui->tableWidget_head->setItem(2, 0, new QTableWidgetItem("开始"));
    ui->tableWidget_head->item(2,0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_head->item(2, 0)->setBackground(global_data::date_Color);
    ui->tableWidget_head->item(2, 0)->setTextColor(Qt::black);

    ui->tableWidget_head->setItem(2, 1, new QTableWidgetItem("结束"));
    ui->tableWidget_head->item(2,1)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_head->item(2, 1)->setBackground(global_data::date_Color);
    ui->tableWidget_head->item(2, 1)->setTextColor(Qt::black);
}

void set_parament1::Get_Row_Parameter(uint8_t stage,UPDATE_ALL_TABLE_TYPEDEF &data)
{
    if( stage >= ui->tableWidget->rowCount()
            && ui->tableWidget->rowCount() < 0 )
        return ;
    QString temp;

    data.set_sensor[0].temp_center=
            (uint16_t)(ui->tableWidget->item(stage,2)->text().toDouble()*10+0.001);

    data.set_sensor[0].humi_center=
            (uint16_t)(ui->tableWidget->item(stage,3)->text().toDouble()*10+0.001);

    for( uint8_t i = 0 ,tempIndex = 2; i < 8 ; i++ ,tempIndex++){
        temp = ui->tableWidget->item(stage,2*tempIndex)
                ->text();

        data.set_breath[i].time_sta
                = QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

        temp = ui->tableWidget->item(stage,2*tempIndex+1)->text().split("分")[0];
        data.set_breath[i].min_len
                =temp.toInt();
    }

    for( uint8_t i = 0 ,tempIndex = 10; i < 4 ; i++ ,tempIndex++){
        if( i < 3 ){
            temp = ui->tableWidget->item(stage,2*tempIndex)->text();
            data.set_sensitive[i].time_sta
                    =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
            temp = ui->tableWidget->item(stage,2*tempIndex+1)->text();

            data.set_sensitive[i].time_end
                    =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
        }

            temp = ui->tableWidget->item(stage,2*tempIndex+6)->text();
            data.set_sterilize[i].time_sta
                    =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

            temp = ui->tableWidget->item(stage,2*tempIndex+7)->text().split("分")[0];
            data.set_sterilize[i].min_len
                    =temp.toInt();

            if( i < 3){
                temp = ui->tableWidget->item(stage,2*tempIndex+14)->text();
                data.set_light[i].time_sta
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;

                temp = ui->tableWidget->item(stage,2*tempIndex+15)->text();
                data.set_light[i].time_end
                        =QTime::fromString(temp,"h:m").msecsSinceStartOfDay()/1000;
            }
    }

}

void set_parament1::Copy_Parameter(uint8_t row)
{
    UPDATE_ALL_TABLE_TYPEDEF data;
    Get_Row_Parameter(row,data);
    uint8_t rowCount = ui->tableWidget->rowCount();

    QString temp;
    for( uint8_t stage = row + 1 ; stage < rowCount ;stage++){
        //设置参数表的值
        temp = QString::number((double)data.set_sensor[0].temp_center/10,'f',1);
        ui->tableWidget->
                setItem(stage,2,new
                        QTableWidgetItem(temp));


        temp = QString::number((double)data.set_sensor[0].humi_center/10,'f',1);
        ui->tableWidget->
                setItem(stage,3,new
                        QTableWidgetItem(temp));

        ui->tableWidget->item(stage,2)->setBackgroundColor(global_data::temp_Color);
        ui->tableWidget->item(stage,3)->setBackgroundColor(global_data::humi_Color);


        for( uint8_t i = 0 ,tempIndex = 2; i < 8 ; i++ ,tempIndex++){
            temp = QTime::fromMSecsSinceStartOfDay(data.set_breath[i].time_sta*1000).toString("hh:mm");
            qDebug()<<temp;
            ui->tableWidget->setItem(stage,2*tempIndex,
                                                    new QTableWidgetItem(temp));

            temp = QString::number(data.set_breath[i].min_len);
            qDebug()<<"分钟数"<<temp;

            ui->tableWidget->setItem(stage,2*tempIndex+1,
                                                    new QTableWidgetItem(temp));

            ui->tableWidget->item(stage,2*tempIndex)->setBackgroundColor(global_data::breath_Color);
            ui->tableWidget->item(stage,2*tempIndex+1)->setBackgroundColor(global_data::breath_Color);
        }

        for( uint8_t i = 0 ,tempIndex = 10; i < 4 ; i++ ,tempIndex++){

            //感光
            if( i < 3 ){
                temp =QTime::fromMSecsSinceStartOfDay(data.set_sensitive[i].time_sta *1000).toString("hh:mm");
                ui->tableWidget->setItem(stage,2*tempIndex,
                                                        new QTableWidgetItem(temp));

                temp = QTime::fromMSecsSinceStartOfDay(data.set_sensitive[i].time_end *1000).toString("hh:mm");
                ui->tableWidget->setItem(stage,2*tempIndex+1,
                                                        new QTableWidgetItem(temp));

                ui->tableWidget->item(stage,2*tempIndex)->setBackgroundColor(global_data::sensitive_Color);
                ui->tableWidget->item(stage,2*tempIndex+1)->setBackgroundColor(global_data::sensitive_Color);
            }

            //消毒
            temp = QTime::fromMSecsSinceStartOfDay(data.set_sterilize[i].time_sta *1000).toString("hh:mm");
            ui->tableWidget->setItem(stage,2*tempIndex+6,
                                                                    new QTableWidgetItem(temp));
            temp = QString::number(data.set_sterilize[i].min_len) ;
            ui->tableWidget->setItem(stage,2*tempIndex+7,
                                                                  new QTableWidgetItem(temp));

            ui->tableWidget->item(stage,2*tempIndex+6)->setBackgroundColor(global_data::disinfect_Color);
            ui->tableWidget->item(stage,2*tempIndex+7)->setBackgroundColor(global_data::disinfect_Color);

            //光照
            if( i < 3 ){
                temp =QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_sta *1000).toString("hh:mm");
                ui->tableWidget->setItem(stage,2*tempIndex+14,
                                                        new QTableWidgetItem(temp));

                temp = QTime::fromMSecsSinceStartOfDay(data.set_light[i].time_end *1000).toString("hh:mm");
                ui->tableWidget->setItem(stage,2*tempIndex+15,
                                                        new QTableWidgetItem(temp));

                ui->tableWidget->item(stage,2*tempIndex+14)->setBackgroundColor(global_data::illumina_Color);
                ui->tableWidget->item(stage,2*tempIndex+15)->setBackgroundColor(global_data::illumina_Color);

            }

        }

        ui->tableWidget->item(stage,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->item(stage,3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        DataTo_txt(stage);//将数据写入txt文本
    }

    uint8_t colCount = ui->tableWidget->columnCount();

    for( uint8_t i = 0 ; i < rowCount ; i++ ){
        for( uint8_t j = 0; j < colCount ; j++){
            ui->tableWidget->item(i,j)->setTextColor(Qt::black);
            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void set_parament1::closeEvent(QCloseEvent *event)
{
    qDebug()<<"催青窗口关闭了"<<Myroom<<event->ActionChanged;
    Change_row.clear();
    execut_stage = false;
    firstCopyFlag = false;
    emit Table_UnCLOCK();
}

void set_parament1::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if( item == nullptr )
        return ;
    QString text = item->text();

//    if( item->row() == 0 ){
//        firstCopyFlag = true;
//    }

    if( item->column() == 0 ){
        //item为为空则不执行
        if( ui->tableWidget->item(item->row(),1) ){
            if( text != ui->tableWidget->item(item->row(),1)->text())
                ui->tableWidget->setItem(item->row(),1,new QTableWidgetItem(text));
        }
    }
    else if( item->column() == 1){

        if( ui->tableWidget->item(item->row(),0) ){
            if( text != ui->tableWidget->item(item->row(),0)->text())
                ui->tableWidget->setItem(item->row(),0,new QTableWidgetItem(text));
        }

    }
}

void set_parament1::on_butto_back_clicked()
{
    Change_row.clear();
    execut_stage = false;
    emit Table_UnCLOCK();
    this->close();
}

void set_parament1::on_button_stop_clicked()
{
    qDebug()<<Myroom<<"房间"<<"停止催青";
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
            if( global_data::control_Mode[Myroom] != CUIQING_END){
                ok = Device_Change(Myroom, CUIQING_END);
                global_data::Mode_Lock[Myroom] = Write_lock;
                if( ok )
                    Message_alert("提示","模式修改成功",QMessageBox::Information);
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
