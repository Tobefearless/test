#ifndef SET_PARAMENT1_H
#define SET_PARAMENT1_H

#include <QMainWindow>
#include <QTableWidget>
namespace Ui {
class set_parament1;
}

class set_parament1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit set_parament1(uint8_t room,QWidget *parent = 0);
    uint8_t Myroom;
    ~set_parament1();


private:
    //参数表的发送
    void Tbale_Send(uint8_t row);
    //将txt文本的数据写入表格
    void WriteTo_Table();
    //将表格数据写入TXT文本中

    //设备状态改变
    bool Device_Change(uint8_t room,WORK_WAY_STATUS way);
    //超时判断
    void isExecuteTime();
public:
    void DataTo_txt(uint8_t stage);
public:
    Ui::set_parament1 *ui;
    QTableWidget *tableWidget;
private:
    //哪一行改变
    QList<int> Change_row;
    //正在执行的那阶段
    bool execut_stage;


    bool firstCopyFlag; //第一行复制标志位
    void Message_alert(QString title, QString text,QMessageBox::Icon hint);

    //初始化表参
    void initCuiHeadFrame();

    /**
     * @brief Get_Row_Parameter 获取某一行的参数
     * @param stage             行数
     * @param data              存储数据的结构体
     */
    void Get_Row_Parameter(uint8_t stage,UPDATE_ALL_TABLE_TYPEDEF &data);

    /**
     * @brief Copy_Parameter
     *        参数复制
     */
    void Copy_Parameter(uint8_t row);
protected:
    void closeEvent(QCloseEvent *event);
private slots:

    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_button_save_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void on_butto_back_clicked();

    void on_button_stop_clicked();

private:
        void Parameter_setting();
signals:
        void Table_UnCLOCK();
};

#endif // SET_PARAMENT1_H
