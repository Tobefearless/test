#ifndef SENSOR_H
#define SENSOR_H

#include <QMainWindow>
#include <QTableWidgetItem>
namespace Ui {
class Sensor;
}

class Sensor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sensor(QWidget *parent = 0);
    void Parameter_setting();
    void Sensor_Save(uint8_t room);
    ~Sensor();

    void other_Sensor_Save(void);
private slots:
    void on_btn_save_clicked();
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_btn_other_save_clicked();

public:
    Ui::Sensor *ui;
    //记录改变的有哪些行的参数
    QList<int> sensro_num;

    QTableWidget *sensor_table,*other_sensor_table;
};

#endif // SENSOR_H
