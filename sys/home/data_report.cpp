#include "data_report.h"
#include "ui_data_report.h"
#include<ActiveQt\qaxobject.h>
#include<ActiveQt/qaxwidget.h>
#include <QFileDialog>
#include <QDesktopServices>
#include <QProgressDialog>
Data_report::Data_report(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Data_report)
{
    ui->setupUi(this);
    this->setWindowTitle("数据报表");                 //设置窗口标题
    this->setWindowIcon(QIcon(":/img/Data report.png"));        //设置窗口图片

    sensor_date  = ui->comboBox;
    room_date = ui->comboBox_3;
    sensor_name = ui->com_sensor;
    room_name = ui->com_room;

}

uint8_t Data_report::Get_interal()
{
    if( ui->radioButton->isChecked() )
        return 3;
    else if( ui->radioButton_2->isChecked() )
        return 15;
    else
        return 30;
}

void Data_report::Report_Generation(QString filename,uint8_t Interval,QString some,QString head)
{
    int numK = 0;
    QString temp = some.right(1);
    QString dateId;
    uint8_t count = 0;
    QList<QVariant> allRowData;
    QFile f(filename);
     if ( !f.open(QIODevice::ReadOnly | QIODevice::Text)){
         QMessageBox::warning(NULL, "参数报表", "文件不存在", "确定");
         return ;
     }

    QTextStream txtInput(&f);
    allRowData.append(QVariant(head.split("/")));
/*	QString astr = "";
    QStringList alldata;*/

   QProgressDialog dialog(tr("报表生成中"), tr("取消"), 0, 0, this);
   dialog.setWindowTitle(tr("进度对话框"));     // 设置窗口标题
   dialog.setWindowModality(Qt::WindowModal);  // 将对话框设置为模态
   dialog.show();

   ui->btn_sure->setEnabled(false);

    while (!txtInput.atEnd())
    {
//读取每一行的数据

        QString lineStr;
        QStringList linedata;
        lineStr = txtInput.readLine();

        linedata = lineStr.split("/");
        dateId = linedata[0];

        if( dateId.endsWith(temp)){
            if( QString(linedata[1]).toDouble() > 0 && QString(linedata[2]).toDouble())
                    count++;
        }

        if( count == Interval ){
            numK++;

            allRowData.append(QVariant(linedata));
            count = 0;
        }
        sleep(10);
    }
    f.close();


    /*******************接着打开连接office excel*************************/
    //一定要是QAxWidget
    QAxWidget *excel = NULL;
   //本例中，excel设定为Excel文件的操作对象
    QAxObject *workbooks = NULL;
    QAxObject *workbook = NULL;  //Excel操作对象
    excel = new QAxWidget("Excel.Application");
    excel->dynamicCall("SetVisible(bool)", false); //true 表示操作文件时可见，false表示为不可见
    excel->setProperty("DisplayAlerts", false);//excel的对话弹窗关闭
    workbooks = excel->querySubObject("WorkBooks");

    /*********************创建excel或者打开excel'文件***********************/
     //QString fileName = QFileDialog::getSaveFileName(NULL,"Save File","./" + some,tr("2010Excel File (*.xls);;2016Excel File(*.xlsx)"));
    QString fileName = QFileDialog::getSaveFileName(NULL,"Save File","./" + some,tr("2010Excel File (*.xls);"));
     if( fileName.isEmpty() ){
         delete excel;
         excel = NULL;
         dialog.close();
         ui->btn_sure->setEnabled(true);
         return ;
     }

     dialog.close();
     fileName.replace("/", "\\");
     workbooks->dynamicCall("Add");
     workbook = excel->querySubObject("ActiveWorkBook");
     //如果有excel 就不用这一步创建了
     //51是xlsx，csv是6；56表示创建的文件格式为xls
     workbook->dynamicCall("SaveAs (const QString&,int,const QString&,const QString&,bool,bool)",
         fileName, 56, QString(""), QString(""), false, false);

     workbook = workbooks->querySubObject("Open(const QString &)", fileName);


     // 获取打开的excel文件中所有的工作sheet
     QAxObject * worksheets = workbook->querySubObject("WorkSheets");

     //—————————————————Excel文件中表的个数:——————————————————
     //int iWorkSheet = worksheets->property("Count").toInt();


     // ————————————————获取第n个工作表 querySubObject("Item(int)", n);——————————
     QAxObject * worksheet = worksheets->querySubObject("Item(int)", 1);//本例获取第一个，最后参数填1

     /******************保存**********************/
     QAxObject* range;
     QString asd = "A1:D" + QString::number(numK+1);
     //获取范围
     range = worksheet->querySubObject("Range(const QString)", asd);
     //批量写入
     range->dynamicCall("SetValue(const QVariant&", QVariant(allRowData));
     //设置字体大小
     //range->querySubObject("Font")->setProperty("Size", 30);
     //range->setProperty("Value", allRowData);

     //

     QAxObject * cells = range->querySubObject("Columns");
     cells->dynamicCall("AutoFit");

     //range->setProperty("HorizontalAlignment",-4108);

     delete range;


     /******************保存*********************/
     workbook->dynamicCall("Save()");
     workbook->dynamicCall("Close()");
     excel->dynamicCall("Quit()");
     if (excel)
     {
         delete excel;
         excel = NULL;

     }

     allRowData.clear();

     QFile file(fileName);
        if (file.exists()) {
            QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
        }
     ui->btn_sure->setEnabled(true);

}




Data_report::~Data_report()
{
    delete ui;
}

void Data_report::on_btn_sure_clicked()
{
    uint8_t choose = ui->tabWidget->currentIndex();
    QDate tempDate;
    QString filename = QDir::currentPath();
    if( choose == 0 ){
        qDebug()<<"这是传感器的报表";
        tempDate = QDate::fromString(sensor_date->currentText(),"yyyy年M月d日");
        uint8_t pos = ui->com_sensor->currentText().indexOf("-");
        filename += "/sensor/" + ui->com_sensor->currentText().mid(0,pos) + " " + tempDate.toString("yyyy-MM-dd") + ".txt";
        qDebug()<<filename;    
        Report_Generation(filename, Get_interal(),ui->com_sensor->currentText(),"传感器名字/传感器温度/传感器湿度/时间");

    }
    else{
        qDebug()<<"这是房间界面的报表";
        QString name = room_name->currentText();
        tempDate = QDate::fromString(room_date->currentText(),"yyyy年M月d日");
        filename +="/room/" +name + "/" +tempDate.toString("yyyy-MM-dd") + ".txt";

        qDebug()<<"ui->com_room->currentText().right(1)"<<ui->com_room->currentText().right(1)
               <<"filename"<<filename;

            Report_Generation(filename,Get_interal(),name,"设备名/平均温度/平均湿度/时间");

    }
}

void Data_report::on_com_room_currentIndexChanged(int index)
{
    qDebug()<<"index"<<index;
}

void Data_report::on_tabWidget_currentChanged(int index)
{
    qDebug()<<"index"<<index;
}

void Data_report::on_com_sensor_currentIndexChanged(int index)
{
    qDebug()<<"index"<<index;
}
