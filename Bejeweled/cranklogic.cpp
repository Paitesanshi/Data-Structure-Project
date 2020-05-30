#include "cranklogic.h"
CRankLogic* CRankLogic::single=NULL;
CRankLogic::CRankLogic()
{
    dao=new CRankDao();
    playerName="";
    playerPassword="";
}

QString CRankLogic::getPlayerPassword() const
{
    return playerPassword;
}

QString CRankLogic::getPlayerName() const
{
    return playerName;
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
    int result=dao->loginCheck(name,password);
    if(result==1)
    {
         playerName=name;
         playerPassword=password;
    }
    return result;
}

bool CRankLogic::userRegister(QString name, QString password)
{
    return dao->userRegister(name,password);
}
