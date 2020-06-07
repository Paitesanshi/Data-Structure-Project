#include "cranklogic.h"
CRankLogic* CRankLogic::single=NULL;
CRankLogic::CRankLogic()
{
    dao=new CRankDao();
    player.strName="";
    player.strPass="";
}

RANKINFOR& CRankLogic::getPlayer()
{
    return player;
}
void CRankLogic::addUser(RANKINFOR x)
{
    dao->addRank(x);
    dao->addRanktoDB(x);
}

set<RANKINFOR,comp> CRankLogic::getRank()
{
    return dao->getUsers();
}

int CRankLogic::loginCheck(QString name, QString password)
{
    int result=dao->loginCheck(name,password,player);
    //qDebug()<<result<<"-----"<<player.strName<<"-----"<<player.level;
    return result;
}

bool CRankLogic::userRegister(QString name, QString password)
{
    return dao->userRegister(name,password);
}
