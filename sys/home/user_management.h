#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include <QMainWindow>
#include <QTableWidget>
namespace Ui {
class User_Management;
}

class User_Management : public QMainWindow
{
    Q_OBJECT

public:
    explicit User_Management(QWidget *parent = 0);
    void table_setting();
    void update_user();
    //将txt文本的内容写入用户管理表格
    void Write_inUser();
    ~User_Management();

private slots:
    void on_btn_add_clicked();

    void on_btn_remove_clicked();

    void on_btn_cancel_clicked();

public:
    Ui::User_Management *ui;
    QTableWidget *user_table;

    uint8_t user_Access;
};

#endif // USER_MANAGEMENT_H
