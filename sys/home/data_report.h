#ifndef DATA_REPORT_H
#define DATA_REPORT_H

#include <QMainWindow>
namespace Ui {
class Data_report;
}

class Data_report : public QMainWindow
{
    Q_OBJECT

public:
    explicit Data_report(QWidget *parent = nullptr);
    uint8_t Get_interal();

    //报表生成
    void Report_Generation(QString filename,uint8_t Interval,QString some,QString head);
    ~Data_report();

public:
    Ui::Data_report *ui;
    uint8_t sensor_table[4][4];
    uint8_t room_table[4];

    QComboBox *sensor_date,*room_date,*sensor_name,*room_name;

private slots:

    void on_btn_sure_clicked();

    void on_com_room_currentIndexChanged(int index);

    void on_tabWidget_currentChanged(int index);

    void on_com_sensor_currentIndexChanged(int index);

signals:
    void room_Change(uint8_t );
};

#endif // DATA_REPORT_H
