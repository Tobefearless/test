#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include "QtNetwork/qnetworkinterface.h"
#include<QSound>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //系统初始化设置
    System_file_initialization();
    Sensor_date_Up();
    USER_UI = new home();                               //创建一个user界面的对象，方便调用
//    this->setWindowTitle("催青管理系统");                 //设置窗口标题
//    this->setWindowIcon(QIcon(":/img/登录主图.jpg"));        //设置窗口图片
//    this->setFixedSize(this->size().width(),this->size().height()); //固定窗口大小
//    QString filename(":/img/login.png"); //赋值文件路径
//    QImage img;
//    img.load(filename);                                 //加载图片
//    img.scaled(ui->main_pic->size(),Qt::KeepAspectRatio);//设置图片大小
//    ui->main_pic->setScaledContents(true);               //设置图片自适应label大小
//    ui->main_pic->setPixmap(QPixmap::fromImage(img));    //将图片加载到lable上

//    QWidget::setTabOrder(ui->accout, ui->password);         //设置焦点切换顺序
//    QWidget::setTabOrder(ui->password, ui->login);
//    QWidget::setTabOrder(ui->login, ui->pushButton_2);


//    /*************QlineEdit设置图标*****************/
//    QAction *searchAction = new QAction(ui->accout);
//    searchAction->setIcon(QIcon(":/img/accout.png"));
//    ui->accout->setPlaceholderText("账号");
//    ui->accout->addAction(searchAction,QLineEdit::LeadingPosition);

//    QAction *searchAction1 = new QAction(ui->password);
//    searchAction1->setIcon(QIcon(":/img/2.png"));
//    ui->password->setPlaceholderText("密码");
//    ui->password->addAction(searchAction1,QLineEdit::LeadingPosition);
//    connect(this,&MainWindow::destroyed,[=]{
//        delete searchAction1;
//        delete searchAction;
//    });
    on_login_clicked();
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

#if 0
    QSettings *settings = new QSettings(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    qDebug()<<"文件存储地址"<<QDir::currentPath() + "/config.ini";
    settings->beginGroup("Mode");
    settings->setValue("SQLS210300001", 0);
    settings->setValue("SQLS210300002", 0);
    settings->setValue("SQLS210300003", 0);
    settings->setValue("SQLS210300004", 0);
    settings->endGroup();

    settings->beginGroup("date");
    settings->setValue("flag", false);
    settings->setValue("date", QDate::currentDate().toString("yyyy/MM/dd"));
    settings->endGroup();
    delete settings;
#else
    bool flag;
    QSettings *settings = new QSettings(QString(FILENAME) + "/config.ini", QSettings::IniFormat);

//    strcpy(global_data::id[0],settings->value("DeviceName/name1").toByteArray().data());
//    strcpy(global_data::id[1],settings->value("DeviceName/name2").toByteArray().data());
//    strcpy(global_data::id[2],settings->value("DeviceName/name3").toByteArray().data());
//    strcpy(global_data::id[3],settings->value("DeviceName/name4").toByteArray().data());

    global_data::coJust = settings->value("Other_Sensor/co").toDouble();
    global_data::co2Just = settings->value("Other_Sensor/co2").toDouble();
    global_data::so2Just = settings->value("Other_Sensor/so2").toDouble();
    global_data::nh3Just = settings->value("Other_Sensor/nh3").toDouble();

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        strcpy(global_data::update_allTable[i].id,global_data::id[i]);
        strcpy(global_data::work_way[i].id,global_data::id[i]);
        strcpy(global_data::id[i],global_data::id[i]);
        qDebug()<<"global_data::update_allTable[i].id"
               <<global_data::update_allTable[i].id;
    }

    global_data::control_Mode[0] = settings->value("Mode/Device1").toInt();   // returns 58


    for( uint8_t i = 0 ; i < DEV ; i++ ){
        global_data::update_allTable[i].set_sensor[0].temp_diff = settings->value(QString("TEMP_ADJUST/temp") + QString::number(i+1)).toInt();
        global_data::update_allTable[i].set_sensor[0].humi_diff = settings->value(QString("HUMI_ADJUST/humi") + QString::number(i+1)).toInt();
        global_data::update_allTable[i].set_wind_temp_diff = settings->value(QString("WIND_ADJUST/wind") + QString::number(i+1)).toInt();

//        qDebug()<<"温差"<<settings->value(QString("TEMP_ADJUST/temp") + QString::number(i+1)).toInt()
//        <<"湿度差"<<settings->value(QString("HUMI_ADJUST/humi") + QString::number(i+1)).toInt()
//        <<"匀风差"<<settings->value(QString("WIND_ADJUST/wind") + QString::number(i+1)).toInt();
    }

    for( uint8_t i = 0 ; i < DEV ; i++ ){
        for( uint8_t j = 0 ; j < 6 ; j++ ){
            global_data::update_allTable[i].set_senser_diff[j].temp_adjust = settings->value("SENSOR_TEMP" + QString::number(i+1)+
                                                                                      "/sensor" +QString::number(j+1) ).toInt();
            global_data::update_allTable[i].set_senser_diff[j].humi_adjust = settings->value("SENSOR_HUMI" + QString::number(i+1)+
                                                                                      "/sensor" +QString::number(j+1) ).toInt();


//            qDebug()<<QString(global_data::id[i])<<"传感器温差"<<"sensor"+QString::number(j+1)<<
//                   settings->value("SENSOR_TEMP" + QString::number(i+1)+
//                                   "/sensor" +QString::number(j+1) ).toInt();
//            qDebug()<<QString(global_data::id[i])<<"传感器湿度差"<<"sensor"+QString::number(j+1)<<
//                   settings->value("SENSOR_HUMI" + QString::number(i+1)+
//                                   "/sensor" +QString::number(j+1) ).toInt();
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


#endif
    qDebug()<<global_data::sensor_Date.toString("yyyy/MM/dd");
    delete settings;
}

void MainWindow::Device_activation(uint8_t access)
{

    USER_UI->showMaximized();
     this->close();
    /**********线程开始*****************/
     emit USER_UI->startThread();

     USER_UI->thread->start();
     //USER_UI->thread1->start();
     USER_UI->modeThread->start();

//     USER_UI->serThread->start();
    //储存txt文本文件
     //USER_UI->data_timer->start(60 *1000);

//    将数据下发到单片机中
     USER_UI->table_timer->start(1000);//原本时间为1个小时
     USER_UI->Heart_timer->start(1000);
     //global_data::update_flag = 1;

     //更新参数表的时间变量
      USER_UI->update_time = QDate::currentDate();

      //用户权限设定
      USER_UI->user_management->user_Access = access;
      //传感器日期获取 
      //Sensor_date_Up();

      QSettings *settings1 = new QSettings(QString(FILENAME) + "/user.ini", QSettings::IniFormat);
      settings1->setValue("USERCONFIG/UserName",ui->accout->text());
      settings1->setValue("USERCONFIG/PassWord",ui->password->text());
      delete settings1;

//      QMediaPlayer *startSound  = new QMediaPlayer(this);  //创建一个音乐播放器
//      //connect(startSound,SIGNAL(positionChanged(qint64)),this,SLOT(postitionChanged(qint64)));
//      startSound->setMedia(QUrl::fromLocalFile(R"(F:\Catalytic host\SYS_Serial-noScan_TableTHreadPoolALL\sys\sys2\sys\Sirenen.mp3)"));
//      startSound->setVolume(80);  //音量
//      startSound->play();
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

    if( !isFileExist(QString(FILENAME)  + "/config.ini")){
        qDebug()<<"文件复制"<<copyFileToPath( QDir::currentPath() + "/config.ini", QString(FILENAME)  + "/config.ini", 1);
    }

//    if( !isFileExist(QString(FILENAME)  + "/user.ini")){
//        qDebug()<<"文件复制"<<copyFileToPath( QDir::currentPath() + "/user.ini", QString(FILENAME)  + "/user.ini", 1);
//    }


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
       if( !openStatus ){
           DB.open("test1");
           return ;
       }
       Device_activation(0);
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Return){
        on_login_clicked();
    }

}

