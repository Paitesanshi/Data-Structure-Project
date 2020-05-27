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
class CRankLogic
{
public:
    CRankLogic();
    void addUser(RANKINFOR x);
private:
    CRankDao *dao;

};

#endif // CRANKLOGIC_H
