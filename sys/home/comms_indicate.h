#ifndef COMMS_INDICATE_H
#define COMMS_INDICATE_H

#include <QMainWindow>
#include <QListWidget>
namespace Ui {
class COMMS_indicate;
}

class COMMS_indicate : public QMainWindow
{
    Q_OBJECT

public:
    explicit COMMS_indicate(QWidget *parent = nullptr);
    QListWidget *list_show;
    ~COMMS_indicate();

private slots:

    void on_pushButton_clicked();

public:
    Ui::COMMS_indicate *ui;
    bool start_flag;   
};

#endif // COMMS_INDICATE_H
