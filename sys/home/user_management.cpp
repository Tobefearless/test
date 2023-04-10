#include "user_management.h"
#include "ui_user_management.h"
#include <QSqlQuery>
User_Management::User_Management(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::User_Management)
{
    ui->setupUi(this);
    this->setWindowTitle("用户管理");                 //设置窗口标题
    this->setWindowIcon(QIcon(":/img/User Management.png"));        //设置窗口图片

    //表格设置
    //table_setting();

    user_table = ui->tableWidget;
   // Write_inUser();
    //ui->tableWidget->setWindowOpacity(1);
    //0为最高级权限
    user_Access = 0;
}

void User_Management::table_setting()
{
  qDebug()<<"表格修改";
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//  ui->tableWidget->setRowCount(9); //设置行数为9
//  ui->tableWidget->setColumnCount(3); //设置列数为3
  int nRow = ui->tableWidget->rowCount();
//  QStringList header;
//  header<<"编号"<<"姓名"<<"密码";
//  ui->tableWidget->setHorizontalHeaderLabels(header);

  for( uint8_t i = 0 ; i < nRow ; i++ ){
      ui->tableWidget->setRowHeight(i, 25);
  }
  ui->tableWidget->setColumnWidth(0,50);
  ui->tableWidget->setColumnWidth(1,150);
  ui->tableWidget->setColumnWidth(2, 150);
  ui->tableWidget->verticalHeader()->hide();//取消行号
//  ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{border:2px groove gray;padding:2px 4px;background-color: rgb(221, 221, 221);;font: 9pt 'Microsoft YaHei UI'}");
}

void User_Management::update_user()
{
    QString filename = QString(FILENAME) + "/user.txt";
    uint8_t row_count = ui->tableWidget->rowCount();
    QFile file(filename);
    while( !file.open(QIODevice::WriteOnly));
    QTextStream txtOutput(&file);
    for( uint8_t i = 0 ; i < row_count ; i++ ){
        txtOutput<<ui->tableWidget->item(i,0)->text()<<"-"
                <<ui->tableWidget->item(i,1)->text()<<"-"
               <<ui->tableWidget->item(i,2)->text()<<"\n";
    }
    file.close();
}

void User_Management::Write_inUser()
{
    QStringList list;
    QString filename = QString(FILENAME) + "/user.txt";
    QFile file(filename);
    if( !file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return ;
    }

    QTextStream in(&file);
    QString line1;
    line1 = in.readLine();
    list = line1.split("-");

    while( !line1.isNull()){
        uint8_t count = user_table->rowCount();
        user_table->insertRow(count);
        user_table->setItem(count,0,new QTableWidgetItem(list[0]));
        user_table->setItem(count,1,new QTableWidgetItem(list[1]));
        user_table->setItem(count,2,new QTableWidgetItem(list[2]));
        qDebug()<<list[0]<<list[1]<<list[2];
        line1 = in.readLine();
        list = line1.split("-");
    }
    file.close();
}

User_Management::~User_Management()
{
    delete ui;
}

void User_Management::on_btn_add_clicked()
{

    if( user_Access == 1 ){
        QMessageBox::warning(NULL, "用户管理", "没有权限", "确定");
        return ;
    }

    if( ui->lineEdit_account->text().isEmpty() || ui->lineEdit_passwd->text().isEmpty()){
        QMessageBox::warning(NULL, "参数错误", "密码不能为空", "确定");
    }
    else{
        uint8_t j = 0;
        QString account = ui->lineEdit_account->text();
        uint8_t count = ui->tableWidget->rowCount();
        if( account == "admin" ){
            QMessageBox::warning(NULL, "参数错误", "用户名不能重复", "确定");

            return ;
        }

        for( uint8_t i = 0 ; i < count ; i++ ){
            if( ui->tableWidget->item(i,1)->text() == account || account == "admin"){
                QMessageBox::warning(NULL, "参数错误", "用户名不能重复", "确定");

                return ;
            }
        }
        ui->tableWidget->insertRow(count);
        ui->tableWidget->setItem(count,j++,new QTableWidgetItem(QString::number(count+1)));
        ui->tableWidget->setItem(count,j++,new QTableWidgetItem(account));
        ui->tableWidget->setItem(count,j,new QTableWidgetItem(ui->lineEdit_passwd->text()));
        update_user();
        //DB.addUser(ui->lineEdit_account->text(),ui->lineEdit_passwd->text());
    }
}

void User_Management::on_btn_remove_clicked()
{
    uint8_t row_count = ui->tableWidget->rowCount();
    uint8_t curRow = ui->tableWidget->currentRow();

    if( user_Access == 1 ){
        QMessageBox::warning(NULL, "用户管理", "没有权限", "确定");
        return ;
    }
//    if( row_count == 1){
//        QMessageBox::information(NULL, "用户管理", "主用户不能删除",
//                                 QMessageBox::Yes, QMessageBox::Yes);
//        return ;
//    }

    if( curRow < 255 ){
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
       //qDebug()<<"DB.del_user"<<DB.del_user(ui->tableWidget->item(ui->tableWidget->currentRow(),1)->text());
        for( uint8_t i = 0 ; i < row_count ; i++ ){
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
        }
    }

    update_user();

}

void User_Management::on_btn_cancel_clicked()
{
    this->close();
}
