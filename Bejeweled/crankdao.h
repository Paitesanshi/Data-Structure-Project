#ifndef CRANKDAO_H
#define CRANKDAO_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include <cstring>
#include <set>
#include "connectiondb.h"
#include "global.h"
using namespace std;
class CRankDao
{

public:
    CRankDao();   
    set<RANKINFOR,comp> getUsers() ;
    void addRank(RANKINFOR x);
    void addRanktoDB(RANKINFOR x);
    int loginCheck(QString name,QString password);
    bool userRegister(QString name,QString password);
private:
    QSqlDatabase db;
    set<RANKINFOR,comp> users;
};

#endif // CRANKDAO_H
