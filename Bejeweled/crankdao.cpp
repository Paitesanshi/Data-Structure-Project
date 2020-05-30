#include "crankdao.h"

CRankDao::CRankDao()
{

   if(createConnection(db))
   {
    qDebug()<<"ss"<<endl;
       users.clear();
        QSqlQuery query(db);
        //query.exec("insert into bejeweled.ranks values('PTSS',0,0)");
        query.exec("select * from bejeweled.ranks ORDER BY grade DESC");
        while (query.next()&&users.size()<10) {
            qDebug()<<query.value(0)<<" "<<query.value(1)<<" "<<query.value(2)<<query.value(3);
            QByteArray ba = query.value(0).toString().toUtf8();
            RANKINFOR tem;
            tem.strName=ba.data();
            ba = query.value(1).toString().toUtf8();
            tem.strPass=ba.data();
            //strcpy(tem.strName,ba.data());
            tem.nRank=users.size()+1;
            tem.nTime=query.value(2).toInt();
            tem.nGrade=query.value(3).toInt();
            users.insert(tem);
        }

   }
}

set<RANKINFOR,comp> CRankDao::getUsers()
{
    return users;
}

void CRankDao::addRank(RANKINFOR x)
{
    for(auto &item: users)
    {
        if(item.strName==x.strName)
        {
               if(x>item)
               {
                   users.erase(item);
                   users.insert(x);

               }
               return;
        }
    }
    users.insert(x);
//    qDebug()<<users.size()<<endl;
//    for(auto item: users)
//    {
//        qDebug()<<item.strName<<item.nGrade;
//    }
    return;
}

void CRankDao::addRanktoDB(RANKINFOR x)
{
    QSqlQuery query(db);
    QString str=QString("select * from bejeweled.ranks where name='%1'").arg(x.strName);
    query.exec(str);
    if(query.next())
    {
        QByteArray ba = query.value(0).toString().toUtf8();
        RANKINFOR tem;
        tem.strName=ba.data();
        tem.nRank=users.size()+1;
        tem.nTime=query.value(1).toInt();
        tem.nGrade=query.value(2).toInt();
        if(x>tem)
        {
            str=QString("update bejeweled.ranks set remainingTime=%1,grade=%2 where name='%3'").arg(x.nTime).arg(x.nGrade).arg(x.strName);
            query.exec(str);
        }
    }
//    else
//    {
//        str=QString("insert into bejeweled.ranks values('%1',%2,%3)").arg(QString(QLatin1String(x.strName))).arg(x.nTime).arg(x.nGrade);
//        query.exec(str);
//       //qDebug()<<"kk"<<query.lastError().databaseText();
//    }

}

int CRankDao::loginCheck(QString name, QString password)
{
    QSqlQuery query(db);
    QString str=QString("select * from bejeweled.ranks where name='%1'").arg(name);
    query.exec(str);
    if(query.next())
    {
        if(password==query.value(1))
        {
            return 1;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

bool CRankDao::userRegister(QString name, QString password)
{qDebug()<<name<<password;
    QSqlQuery query(db);

    QString str=QString("select * from bejeweled.ranks where name='%1'").arg(name.toStdString().c_str());
    query.exec(str);
    if(query.next())
    {
        return false;
    }
    qDebug()<<name<<password;
    str=QString("insert into bejeweled.ranks values('%1','%2',0,0)").arg(name.toStdString().c_str()).arg(password.toStdString().c_str());
    query.exec(str);
    return true;

}
