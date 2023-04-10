#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include "QtNetwork/qnetworkinterface.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //系统初始化设置
    System_file_initialization();
    Sensor_date_Up();

    USER_UI = new home();                               //创建一个user界面的对象，方便调用
    this->setWindowTitle("催青管理系统");                 //设置窗口标题
    this->setWindowIcon(QIcon(":/img/登录主图.jpg"));        //设置窗口图片
    this->setFixedSize(this->size().width(),this->size().height()); //固定窗口大小
    QString filename(":/img/login.png"); //赋值文件路径
    QImage img;
    img.load(filename);                                 //加载图片
    img.scaled(ui->main_pic->size(),Qt::KeepAspectRatio);//设置图片大小
    ui->main_pic->setScaledContents(true);               //设置图片自适应label大小
    ui->main_pic->setPixmap(QPixmap::fromImage(img));    //将图片加载到lable上

    QWidget::setTabOrder(ui->accout, ui->password);         //设置焦点切换顺序
    QWidget::setTabOrder(ui->password, ui->login);
    QWidget::setTabOrder(ui->login, ui->pushButton_2);


    /*************QlineEdit设置图标*****************/
    QAction *searchAction = new QAction(ui->accout);
    searchAction->setIcon(QIcon(":/img/accout.png"));
    ui->accout->setPlaceholderText("账号");
    ui->accout->addAction(searchAction,QLineEdit::LeadingPosition);

    QAction *searchAction1 = new QAction(ui->password);
    searchAction1->setIcon(QIcon(":/img/2.png"));
    ui->password->setPlaceholderText("密码");
    ui->password->addAction(searchAction1,QLineEdit::LeadingPosition);
    connect(this,&MainWindow::destroyed,[=]{
        delete searchAction1;
        delete searchAction;
    });

}

bool MainWindow::log_in(QString account, QString passwd)
{
    QStringList list;
    QString filename = QString(FILENAME) + "/user.txt";
    QFile file(filename);
    if( !file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(NULL, "数据库", "用户文件损坏", "确定");
        return false;
    }
    QTextStream in(&file);
    QString line1;
    line1 = in.readLine();
    list = line1.split("-");
    while( !line1.isNull()){
         qDebug()<<"line1"<<line1;

        if( account == list[1] && passwd == list[2]){
            return true;
        }
        line1 = in.readLine();
        qDebug()<<"line1"<<line1;
        list = line1.split("-");
    }
    return false;
}

void MainWindow::Sensor_date_Up()
{
    bool flag;
    QSettings *settings = new QSettings(QString(FILENAME) + "/config.ini", QSettings::IniFormat);

    UPDATE_ALL_TABLE_TYPEDEF temp1 = {TABLE_HEAD,"",{0,0},{0,0},{0,0},{0,0,0,0},{0,0},{0,0},0,TABLE_TAIL,0};
    WORK_WAY_TYEP temp2 = {GET_DEV_STATUS_HEAD,"",0,0,GET_DEV_STATUS_TAIL,0};
    //系统配置参数
    for( uint8_t i = 0 ; i < DEV ; i++ ){
        global_data::update_allTable[i] =temp1;
        global_data::work_way[i] = temp2;


        strcpy(global_data::update_allTable[i].id,global_data::id[i]);
        strcpy(global_data::work_way[i].id,global_data::id[i]);

        //设备模式赋值
        global_data::control_Mode[i] = settings->value("Mode/Device" + QString::number(i+1)).toInt();
        //温度、湿度温差赋值
        global_data::update_allTable[i].set_sensor[0].temp_diff = settings->value(QString("TEMP_ADJUST/temp") + QString::number(i+1)).toInt();
        global_data::update_allTable[i].set_sensor[0].humi_diff = settings->value(QString("HUMI_ADJUST/humi") + QString::number(i+1)).toInt();
        global_data::update_allTable[i].set_wind_temp_diff = settings->value(QString("WIND_ADJUST/wind") + QString::number(i+1)).toInt();

        global_data::sensor_just_data[i].coJust = settings->value(QString("Other_Sensor") + QString::number(i+1) + "/co" ).toDouble();
        global_data::sensor_just_data[i].co2Just = settings->value(QString("Other_Sensor") + QString::number(i+1) + "/co2").toDouble();
        global_data::sensor_just_data[i].cio2Just = settings->value(QString("Other_Sensor") + QString::number(i+1) + "/cio2").toDouble();
        global_data::sensor_just_data[i].nh3Just = settings->value(QString("Other_Sensor") + QString::number(i+1) + "/nh3").toDouble();

    }

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        for( uint8_t j = 0 ; j < 6 ; j++ ){
            global_data::update_allTable[i].set_senser_diff[j].temp_adjust = settings->value("SENSOR_TEMP" + QString::number(i+1)+
                                                                                      "/sensor" +QString::number(j+1) ).toInt();
            global_data::update_allTable[i].set_senser_diff[j].humi_adjust = settings->value("SENSOR_HUMI" + QString::number(i+1)+
                                                                                      "/sensor" +QString::number(j+1) ).toInt();
        }
    }

    flag = settings->value("mdate/flag").toBool();
    global_data::Default_flag = settings->value("Default_parameter/flag").toBool();



    qDebug()<<"flag"<<flag;
    if(  !flag ){
        global_data::sensor_Date = QDate::currentDate();
        settings->beginGroup("mdate");
        settings->setValue("flag", true);
        settings->setValue("date", QDate::currentDate().toString("yyyy/MM/dd"));
        settings->endGroup();

    }
    else{
        global_data::sensor_Date = QDate::fromString(settings->value("mdate/date").toString(),"yyyy/MM/dd");
    }

}

void MainWindow::Device_activation(uint8_t access)
{

    USER_UI->showMaximized();
     this->close();
    /**********线程开始*****************/
     emit USER_UI->startThread();

     USER_UI->thread->start();
    // USER_UI->thread1->start();
     USER_UI->modeThread->start();


     //USER_UI->serThread->start();
    //储存txt文本文件
     //USER_UI->data_timer->start(60 *1000);

    //将数据下发到单片机中
     USER_UI->table_timer->start(1000);//原本时间为1个小时
     USER_UI->Heart_timer->start(1000);
     global_data::update_flag = 1;

     //更新参数表的时间变量
      USER_UI->update_time = QDate::currentDate();

      //用户权限设定
      USER_UI->user_management->user_Access = access;
      //传感器日期获取
      Sensor_date_Up();

}

QString MainWindow::mkMutiDir(const QString path)
{
    QDir dir(path);
    if ( dir.exists(path)){
        return path;
    }
    QString parentDir = mkMutiDir(path.mid(0,path.lastIndexOf('/')));
    QString dirname = path.mid(path.lastIndexOf('/') + 1);
    QDir parentPath(parentDir);
    if ( !dirname.isEmpty() )
        parentPath.mkpath(dirname);
    return parentDir + "/" + dirname;
}

bool MainWindow::copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist)
{
    toDir.replace("\\","/");
        if (sourceDir == toDir){
            return true;
        }
        if (!QFile::exists(sourceDir)){
            return false;
            qDebug()<<"源文件不存在";
        }
        QDir *createfile     = new QDir;
        bool exist = createfile->exists(toDir);
        if (exist){
            if(coverFileIfExist){
                createfile->remove(toDir);
            }
        }//end if

        if(!QFile::copy(sourceDir, toDir))
        {
            return false;
             qDebug()<<"文件复制失败";
        }
        return true;

}

bool MainWindow::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
        QDir targetDir(toDir);
        if(!targetDir.exists()){    /**< 如果目标目录不存在，则进行创建 */
            if(!targetDir.mkdir(targetDir.absolutePath()))
                return false;
        }

        QFileInfoList fileInfoList = sourceDir.entryInfoList();

        foreach(QFileInfo fileInfo, fileInfoList){
            if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
                continue;

            if(fileInfo.isDir()){    /**< 当为目录时，递归的进行copy */
                if(!copyDirectoryFiles(fileInfo.filePath(),
                    targetDir.filePath(fileInfo.fileName()),
                    coverFileIfExist))
                    return false;
            }
            else{            /**< 当允许覆盖操作时，将旧文件进行删除操作 */
                if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                    targetDir.remove(fileInfo.fileName());
                }

                /// 进行文件copy
                if(!QFile::copy(fileInfo.filePath(),
                    targetDir.filePath(fileInfo.fileName()))){
                    qDebug()<<fileInfo.filePath()<<targetDir.filePath(fileInfo.fileName());
                        return false;
                }
            }
        }
        return true;

}

bool MainWindow::isDirExist(QString fullPath)
{
        QDir dir(fullPath);
        if(dir.exists())
        {
          return true;
        }
        return false;
}

bool MainWindow::isFileExist(QString fullFileName)
{
    QFile file(fullFileName);
    if(file.exists())
    {
        return true;
    }
    return false;
}

bool MainWindow::System_file_initialization()
{
    global_data_initial();
    mkMutiDir(QString(RecordFILE));
    mkMutiDir(QString(FILENAME));
    QFileInfo info(QString(FILENAME));

    if (info.exists())    {
        QString file_size = tr("%1").arg(info.size());
        QDateTime dt = info.created();
        QString create_time = tr("%1").arg(dt.toString("yyyy-MM-dd"));
        dt = info.lastModified();
        QString modify_time = tr("%1").arg(dt.toString("yyyy-MM-dd hh:mm:ss"));
        qDebug() << "文件名:" << info.fileName() << " 版本:"  << file_size << " 创建时间 : " << create_time << " 修改时间 : "<<modify_time ;

        QDate tDate = QDate::fromString(create_time,"yyyy-MM-dd");
        QDate cDate = QDate::fromString("2021-05-20","yyyy-MM-dd");
        if( cDate.daysTo(tDate) < 0 ){
            QFile::remove(QString(FILENAME)  + "/config.ini");
            //QDir(QString(FILENAME)  + "/").removeRecursively();
        }
    }
    uint max_time = 0;
//    getfiles(QString(FILENAME)  + "/Cui",max_time);
//    getfiles(QString(FILENAME)  + "/Seed",max_time);
//    getfiles(QString(FILENAME)  + "/coparaent",max_time);
    getfiles(QString(FILENAME),max_time);
    qDebug()<<"最新的时间"<<max_time;
    qDebug()<<"本机电脑的MAC地址"<<getMacAddress();
    mkMutiDir(QString(FILENAME) );
    sleep(1000);
    if( !isDirExist(QString(FILENAME)  + "/Cui") ){
        qDebug()<<"文件复制"<<copyDirectoryFiles(QDir::currentPath() + "/Cui", QString(FILENAME)  + "\\Cui", 1);
    }

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( !isFileExist(QString(FILENAME)  + "/Cui/Cui-" + QString::number(i+1) + ".txt")){
            qDebug()<<"文件复制"<<copyFileToPath( QDir::currentPath() + "/Cui/Cui-" + QString::number(i+1) + ".txt" , QString(FILENAME)  + "/Cui/Cui-" + QString::number(i+1) + ".txt", 1);
        }
    }

    if( !isDirExist(QString(FILENAME)  +"/Seed")){
        qDebug()<<"文件复制"<<copyDirectoryFiles(QDir::currentPath() + "/seed", QString(FILENAME)  + "/Seed", 1);
    }

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( !isFileExist(QString(FILENAME)  + "/Seed/seed-" + QString::number(i+1) + ".txt")){
            qDebug()<<"文件复制"<<copyFileToPath( QDir::currentPath() + "/Seed/seed-" + QString::number(i+1) + ".txt" , QString(FILENAME)  + "/Seed/seed-" + QString::number(i+1) + ".txt", 1);
        }
    }

    if( !isDirExist(QString(FILENAME)  + "/coparaent")){
        qDebug()<<"文件复制"<<copyDirectoryFiles(QDir::currentPath() + "/coparaent", QString(FILENAME)   + "/coparaent", 1);
    }

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        if( !isFileExist(QString(FILENAME)  + "/coparaent/coparaent-" + QString::number(i+1) + ".txt")){
            qDebug()<<"文件复制"<<copyFileToPath( QDir::currentPath() + "/coparaent/coparaent-" + QString::number(i+1) + ".txt" , QString(FILENAME)  + "/coparaent/coparaent-" + QString::number(i+1) + ".txt", 1);
        }
    }

    if( !isFileExist(QString(FILENAME) + "/user.txt")){
        qDebug()<<"文件复制"<<copyFileToPath( QDir::currentPath() + "/user.txt",QString(FILENAME)  + "/user.txt", 1);
        qDebug()<<"路径"<<QDir::currentPath() + "/user.txt";
    }

    if( !isFileExist(QString(FILENAME)  + "/config.ini")){
        qDebug()<<"文件复制"<<copyFileToPath( QDir::currentPath() + "/config.ini", QString(FILENAME)  + "/config.ini", 1);
    }



    return true;
}

uint MainWindow::getfiles(const QString &dir_path,uint &max_time)
{
    QDir dir(dir_path);
    if(!dir.exists())
    {
        qDebug() << "it is not true dir_path";
    }

    /*设置过滤参数，QDir::NoDotAndDotDot表示不会去遍历上层目录*/
    QDirIterator dir_iterator(dir_path,QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot,QDirIterator::Subdirectories);

    while(dir_iterator.hasNext())
    {
        dir_iterator.next();
        QFileInfo file_info = dir_iterator.fileInfo();
        QString files = file_info.absoluteFilePath();
        QDateTime dt = file_info.lastModified();
        QString modify_time = tr("%1").arg(dt.toString("yyyy-MM-dd hh:mm:ss"));
        if( max_time < dt.toTime_t()){
            max_time = dt.toTime_t();
        }
        if( !files.contains("user.txt") ){
            qDebug()<<files<<modify_time;
        }

    }

    return max_time;
}

QString MainWindow::getMacAddress()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    int nCnt = nets.count();
    QString strMacAddr = "";
    for(int i = 0; i < nCnt; i ++)
    {
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    return strMacAddr;
}

void MainWindow::global_data_initial()
{
    for( uint8_t i = 0 ; i < DEV ; i++ ){

        global_data::execute_date[i].sta_date = "";

        global_data::execute_date[i].end_date = "";

        global_data::execute_date[i].run_stage = -1;

        global_data::Mode_Lock[i] = Write_lock;

        global_data::room_flag[i] = true;

        global_data::Send_onine_flag[i] = true;

        global_data::Mutual_exclusion[i] =Invalid;
    }
}

MainWindow::~MainWindow()
{
    delete USER_UI;
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_login_clicked()
{
   bool openStatus = DB.open("test1");
   global_data::on_line = openStatus;
   ui->hint->setStyleSheet("font-size:16pt; font-weight:600; color:#ff5500");
   if(openStatus && DB.login(ui->accout->text(),ui->password->text())){
           Device_activation(0);
   }
   else if( log_in(ui->accout->text(),ui->password->text())){
            Device_activation(1);
   }
   else{
           ui->hint->setText(" 数据库连接失败!\n本地账号或密码错误");
   }

}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Return){
        on_login_clicked();
    }

}

