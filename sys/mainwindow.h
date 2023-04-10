#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QTimer>
#include <home/home.h>
//#include <ui_user.h>
#include <home/user_management.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    bool log_in(QString account,QString passwd);
    void Sensor_date_Up();

    //设备启动
    void Device_activation(uint8_t access);

    //创建多级目录
    QString mkMutiDir(const QString path);

    //拷贝文件

    bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist);

    //拷贝文件夹：
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);

    //判断文件夹是否存在
    bool isDirExist(QString fullPath);

    //判断文件是否存在
    bool isFileExist(QString fullFileName);

    //系统文件初始化
    bool System_file_initialization();
    uint getfiles(const QString &dir_path,uint &max_time);

    void guidFormString(const char *pszGuid, GUID &guid);

    //获取MAC地址
    QString getMacAddress();
    ~MainWindow();

public slots:
    void on_pushButton_2_clicked();

    void on_login_clicked();
public:
    Ui::MainWindow *ui;
    home *USER_UI;
private slots:
    void keyPressEvent(QKeyEvent * event);
};

#endif // MAINWINDOW_H
