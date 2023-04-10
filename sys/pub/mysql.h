#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include <QtSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlerror.h>
#include <QString>
#include <QDebug>
#include "pub.h"
#include <QTableWidget>
#include <QMutex>
class mysql : public QObject
{
    Q_OBJECT
public:
    explicit mysql(QObject *parent = nullptr);

    bool login(QString userName,QString password);
    QString select(QString userName,QString type);
    //从数据库获取Toapp数据
    bool fromDB(FROM_DB_Typedef* data);
    //从数据库获取显示数据和表格数据
    bool fromDBAll(FROM_DB_Typedef* data);

    bool toDB();
    bool open(const QString connnectname);
    bool close();

    //将表的上上传到数据库
    bool AllTableToDB(UPDATE_ALL_TABLE_TYPEDEF data,EXECUTE_DATE_Typedef excute,QString app_status,QString change_status);
    bool AllTableToDB(UPDATE_ALL_TABLE_TYPEDEF data,EXECUTE_DATE_Typedef excute);

    bool AllTableToDB(QString id,EXECUTE_DATE_Typedef excute);
    //模式改变送入参数表
    bool WORKwayToDB(WORK_WAY_TYEP data,QString status);
   //从数据库荡数据下来
    bool GetTable();
    //从数据库上获取模式下来
    bool GetMode();
    bool GetMode(QString device);

    bool GetTable(QString id);

    //全部更新
    bool Updata_All();
    //屏幕更新时间
    bool Screen_update(QString name);
    //设备更新标志位清零
    bool Dev_Clear(QString name);
    //模式标志位清除
    bool Mode_Clear(QString name);
  //添加用户名和密码
    bool addUser(QString name,QString passwd);
  //将数据库的用户和密码添加到表格
    bool  User_data_lookup(QTableWidget *table);
  //删除用户
    bool del_user(QString name);

    //获取数据库最新更新时间
    uint Get_Update_Time();

    //十六进制的字符串转QByteArray
    QByteArray HexStringToByteArray(QString hex, bool *ok);
    //QByteArray的转16进制
    QString ByteArrayToHexString(QString data);

    //将结构体转换为16进制数
    QByteArray Convert_struct(const char *data, qint64 len);

    //参数改变记录
    void Change_Save(uint8_t id);

    //获取本机电脑的MAC地址
    QString getMacAddress();
private:
  QSqlDatabase db;
  bool isopen;
  static QMutex mutex;
  WORK_WAY_TYEP work_way;
public:
  int  room;
signals:
    void send_ChangeTable();
    void send_ModeChange();

    void finsh_table();
public slots:
};

#endif // MYSQL_H
