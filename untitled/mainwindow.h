#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMqtt/QMqttClient>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include "pub.h"
#include <QTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMqttClient *mG_client;
    QTimer *mTimer;
    uint8_t hear_count;
    bool mqtt_connect_status;
    bool cancel_sub;

    FROM_DB_Typedef record_data;//显示数据

private:
    bool create_connect(void);
    bool mqtt_subscribe(QString id);
    void Device_disengaged(FROM_DB_Typedef &data);//设备断开，显示界面参数

    void monitor_file_generate(FROM_DB_Typedef &data);
    QString mkMutiDir(const QString path);

private slots:
    void timeOut(void);
    void on_pushButton_subscription_clicked();
    void on_pushButton_unsubscribe_clicked();

    void topicMessageReceived(const QByteArray &data,
                              const QMqttTopicName &topic);//mqtt接收消息
};

#endif // MAINWINDOW_H
