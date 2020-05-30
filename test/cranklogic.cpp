#include "cranklogic.h"
CRankLogic::CRankLogic()
{
    dao=new CRankDao();

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
    return dao->loginCheck(name,password);
}

bool CRankLogic::userRegister(QString name, QString password)
{
    return dao->userRegister(name,password);
}
