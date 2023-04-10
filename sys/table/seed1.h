#ifndef SEED_H
#define SEED_H

#include <QMainWindow>
#include <QTableWidget>
namespace Ui {
class Seed;
}

class Seed : public QMainWindow
{
    Q_OBJECT

public:
    explicit Seed(uint8_t room, QWidget *parent = 0);
    uint8_t Myroom;
    ~Seed();

private:
    void Parameter_setting();
    //参数回写
    void Parameter_write_back();

    //将txt文本写入保种表格
    void Write_SeedTable();
    //发送表格参数
    void Tbale_Send(uint8_t row);
    //设备状态改变
    bool Device_Change(uint8_t room,WORK_WAY_STATUS way);

    void Message_alert(QString title, QString text,QMessageBox::Icon hint);
    //超时判断
    void isExecuteTime();
public:
    //将参数写入txt文本中
    void DataTo_txt(uint8_t stage);
    void setDayFlag(bool flag);
private slots:
    void on_butto_back_clicked();

    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_button_save_clicked();

    void on_button_stop_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

public:
    Ui::Seed *ui;
    //表格引用别名
    QTableWidget *tableWiegt;
private:
    //参数设置的标题
    QString title;

    //哪一行改变
    QList<int> Change_row;
    //正在执行的那阶段
    bool execut_stage;
    //工作模式结构体
    WORK_WAY_TYEP workType;

    bool dayChangeFlag;
protected:
//    bool eventFilter(QObject *target, QEvent *event);
    void closeEvent(QCloseEvent *event);
signals:
        void Table_UnCLOCK();
};

#endif // SEED_H
