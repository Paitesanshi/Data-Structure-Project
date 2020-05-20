#ifndef CRANKLOGIC_H
#define CRANKLOGIC_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include "connectiondb.h"
class CRankLogic
{
public:
    CRankLogic();
private:
    QSqlDatabase db;

};

#endif // CRANKLOGIC_H
