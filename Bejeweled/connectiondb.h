#ifndef CONNECTIONDB_H
#define CONNECTIONDB_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QDebug>
#include <QSqlError>
static bool createConnection( QSqlDatabase &db)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
  //  db.setPort(3306);
    db.setDatabaseName("bejeweled");       //这里输入你的数据库名
    db.setUserName("root");
    db.setPassword("zxc110");   //这里输入你的密码

    if (!db.open()) {
    QMessageBox::critical(0, QObject::tr("无法打开数据库"),
    "无法创建数据库连接！ ", QMessageBox::Cancel);
    return false;
    } //下面来创建表
    // 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
    QSqlQuery query(db);
    // 使数据库支持中文
    query.exec("SET NAMES 'Latin1'");
    QStringList tables=db.tables();
    if(!tables.contains("ranks"))
    {
        // 创建 course 表
        //query.exec("create table bejeweled.ranks(name varchar(50),password varchar(50),Time1 int,grade1 int,Time2 int,grade2 int,Time3 int,grade3 int,Time4 int,grade4 int,Time5 int,grade5 int,Time6 int,grade6 int,Time7 int,grade7 int,Time8 int,grade8 int,Time9 int,grade9 int)");
        query.exec("create table bejeweled.ranks(name varchar(50),password varchar(50),level int,finalGrade int,finalTime int,grade1 int,grade2 int,grade3 int,grade4 int,grade5 int,grade6 int,grade7 int,grade8 int,grade9 int)");
        qDebug()<<"kk"+query.lastError().databaseText();
    }
    return true;
}
#endif // CONNECTIONDB_H
