#ifndef CO_PARENTING_H
#define CO_PARENTING_H

#include <QMainWindow>
#include <QTableWidget>
namespace Ui {
class Co_parenting;
}

class Co_parenting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Co_parenting(uint8_t room, QWidget *parent = 0);
    uint8_t Myroom;
    ~Co_parenting();
private:
    void Parameter_setting();//tableWidget初始化
    void WriteTo_Table();//将txt文本中的内容写入共育表格
    void Tbale_Send(uint8_t row);//发送表格参数
    bool Device_Change(uint8_t room,WORK_WAY_STATUS way);//设备状态改变
    void Message_alert(QString title, QString text,QMessageBox::Icon hint);//消息提示
    //超时判断
    void isExecuteTime();


public:
    void DataTo_txt(uint8_t stage);//将数据存储到文本中
    void setDayFlag(bool flag);
protected:
    void closeEvent(QCloseEvent *event);//窗口关闭事件
private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);//表格点击事件
    void on_button_save_clicked();//保存(开始)按钮点击事件
    void on_butto_back_clicked();//返回按钮点击事件
    void on_button_stop_clicked();//停止按钮点击事件

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

public:
    Ui::Co_parenting *ui;
    QTableWidget *tableWiegt;//表格引用别名
private:
    QString title;//标题
    QList<int> Change_row;//哪一行改变
    bool execut_stage;//正在执行的那阶段
    WORK_WAY_TYEP workType;//工作模式结构体

    bool dayChangeFlag;
signals:
        void Table_UnCLOCK();
};

#endif // CO_PARENTING_H
