#ifndef CRANKLOGIC_H
#define CRANKLOGIC_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include "connectiondb.h"
#include "crankdao.h"
#include "global.h"
class CRankLogic
{
public:
    static CRankLogic* getInstance()
    {
        if(single==NULL)
            single=new CRankLogic();
        return single;
    }
    void addUser(RANKINFOR x);
    set<RANKINFOR,comp> getRank();
    int loginCheck(QString name,QString password);
    bool userRegister(QString name,QString password);
private:
    CRankDao *dao;
    CRankLogic();
    QString playerName;
    QString playerPassword;
    static CRankLogic *single;
};

#endif // CRANKLOGIC_H
