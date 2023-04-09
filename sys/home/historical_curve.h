#ifndef HISTORICAL_CURVE_H
#define HISTORICAL_CURVE_H

#include <QMainWindow>
#include <QString>
#include <QtCharts>
#include "QFile"
#include "QTextStream"
#include "QDateTime"
#include <QTcpSocket>
#include <QtMqtt/QMqttClient>
#include <QProgressDialog>
namespace Ui {
class Historical_curve;
}

class Historical_curve : public QMainWindow
{
    Q_OBJECT

public:
    explicit Historical_curve(QWidget *parent = 0);
    ~Historical_curve();

    //创建多级目录
    QString mkMutiDir(const QString path);

    void createChart();   //创建图表
    void read_dat_to_chart();//读取数据到图标上去
    void initial_chart();

    void mqtt_connect();
    bool mqtt_subscribe();
    void mqtt_publish(QString content);
protected:
     void closeEvent(QCloseEvent *event);
    /* socket出错 -> 出错处理 */
//    void show_error(QAbstractSocket::SocketError);
    bool isFileExist(QString fullFilePath);
    void File_receiving_update();
private slots:
    void on_pushButton_clicked();

//    void on_button_get_clicked();
    void topicMessageReceived(const QByteArray &message, const QMqttTopicName &topic);
    void updateLogStateChange();
    void time_Out();
//    void recevie_file();
private:
    Ui::Historical_curve *ui;
    QTimer *timer;
    QDateTimeAxis *m_AxisX_Time;//时间轴
    QValueAxis *m_AxisY; //y轴
    QChart *chart;//chart对象
    QDateTime current_date_time;
    QStringList list;
/*******mqtt接收文件***********/
    //文件名接收标志位
    bool file_flag;
    //总的行数
    qint64 fileLine;
    qint64 gotLine;
    //文件
    QFile *file;
    QString fileName;
    uint8_t file_count;
    QProgressDialog *progressDialog;
    //接收启动标志位

    //接收的开始时间
    uint Recive_StaTime;
    //TCP通信
//    QTcpSocket *receive;
//    QString fileName;
//    QFile *file;
//    /* 已接受数据，总数据，文件名长度 */
//    qint64 gotBytes, fileBytes, nameSize;

    QDateTime file_time;

    //发送命令
    GET_FILE_TYPE get_file;
public:
    QLineSeries   *m_tem_Series;//折线图数据集
    QLineSeries   *m_hum_Series;
    QDateEdit *date_sta,*date_end;
    QComboBox *Device;
    QMqttClient *m_client;
};

#endif // HISTORICAL_CURVE_H
