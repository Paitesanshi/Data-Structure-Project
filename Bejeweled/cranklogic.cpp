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
