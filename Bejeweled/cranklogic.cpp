#include "cranklogic.h"
CRankLogic::CRankLogic()
{
    qDebug()<<"start";
   if(createConnection(db))
   {
        QSqlQuery query(db);
        //query.exec("insert into bejeweled.rank values(1,'PTSS',0,0)");
        query.exec("select * from bejeweled.rank");
        while (query.next()) {
            qDebug()<<query.value(0)<<" "<<query.value(1)<<" "<<query.value(2)<<query.value(3);
//            QByteArray ba = query.value(1).toString().toUtf8();
//            strName=ba.data();
//            nRank=query.value(0).toInt();
//            nTime=query.value(2).toInt();
//            nRank=query.value(3).toInt();
        }
        //qDebug()<<"gg"+query.lastError().databaseText();
   }
}
