#include "crankdao.h"

CRankDao::CRankDao()
{

   if(createConnection(db))
   {
    //qDebug()<<"ss"<<endl;
       users.clear();
        QSqlQuery query(db);
        //query.exec("insert into bejeweled.ranks values('PTSS',0,0)");
        query.exec("select * from bejeweled.ranks ORDER BY level desc,finalGrade DESC");
        while (query.next()&&users.size()<10) {
            qDebug()<<query.value(0)<<" "<<query.value(1)<<" "<<query.value(2)<<query.value(3);
          //  QByteArray ba = query.value(0).toString().toUtf8();
            RANKINFOR tem;
            //tem.strName=ba.data();
            tem.strName=query.value(0).toString();
            qDebug()<<"1111  "<<tem.strName<<endl;
         //   ba = query.value(1).toString().toUtf8();
          //  tem.strPass=ba.data();
            tem.strPass=query.value(1).toString();
            tem.level=query.value(2).toInt();
            //strcpy(tem.strName,ba.data());
            tem.finalGrade=query.value(3).toInt();
            tem.nTime=query.value(4).toInt();
            tem.nRank=users.size()+1;
            for(int i=1;i<=9;++i)
                tem.nGrade[i]=query.value(4+i).toInt();
            users.insert(tem);
        }


   }
}

set<RANKINFOR,comp> CRankDao::getUsers()
{
    for(auto &item: users)
    {
        qDebug()<<"gggg "<<item.strName;
    }
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

        str=QString("update bejeweled.ranks set level=%1,finalGrade=%2,finalTime=%3,grade1=%4,grade2=%5,grade3=%6,grade4=%7,grade5=%8,grade6=%9,grade7=%10,grade8=%11,grade9=%12 where name='%13'").arg(x.level).arg(x.finalGrade).arg(x.nTime).arg(x.nGrade[1]).arg(x.nGrade[2]).arg(x.nGrade[3]).arg(x.nGrade[4]).arg(x.nGrade[5]).arg(x.nGrade[6]).arg(x.nGrade[7]).arg(x.nGrade[8]).arg(x.nGrade[9]).arg(x.strName);
        query.exec(str);
    }
//    else
//    {
//        str=QString("insert into bejeweled.ranks values('%1',%2,%3)").arg(QString(QLatin1String(x.strName))).arg(x.nTime).arg(x.nGrade);
//        query.exec(str);
//       //qDebug()<<"kk"<<query.lastError().databaseText();
//    }

}

int CRankDao::loginCheck(QString name, QString password,RANKINFOR &tem)
{
    QSqlQuery query(db);
    QString str=QString("select * from bejeweled.ranks where name='%1'").arg(name);
    query.exec(str);
    if(query.next())
    {
        if(password==query.value(1))
        {
            QByteArray ba = query.value(0).toString().toUtf8();
            tem.strName=ba.data();
            ba = query.value(1).toString().toUtf8();
            tem.strPass=ba.data();
            tem.level=query.value(2).toInt();
           // qDebug()<<tem.strName<<" "<<tem.level;
            //strcpy(tem.strName,ba.data());
            tem.finalGrade=query.value(3).toInt();
            tem.nTime=query.value(4).toInt();
            for(int i=1;i<=9;++i)
                tem.nGrade[i]=query.value(4+i).toInt();
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
    QString str=QString("select * from bejeweled.ranks where name='%1'").arg(name);
    query.exec(str);
    if(query.next())
    {
        return false;
    }
    qDebug()<<name<<password;
    str=QString("insert into bejeweled.ranks values('%1','%2',1,0,0,0,0,0,0,0,0,0,0,0)").arg(name).arg(password);
    query.exec(str);
    return true;

}
