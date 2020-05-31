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
    void addUser(RANKINFOR x);//用户游戏结束计算分数过后执行此方法，根据下面方法获得当前登录玩家信息，再传入RANKINFOR，排行榜set和数据库会更新玩家信息。此时应重新调用getRAnk更新排行榜set
    set<RANKINFOR,comp> getRank();//返回set按积分大小降序排列玩家排名信息，注意接收返回值的应该也是set<RANKINFOR,comp>
    int loginCheck(QString name,QString password);//用户登录检验，用户名不存在返回-1，用户密码错误返回0，用户登陆成功返回1
    bool userRegister(QString name,QString password);
    RANKINFOR getPlayer() const;//获取已登录玩家信息

private:
    CRankDao *dao;
    CRankLogic();
    RANKINFOR player;//已登录玩家信息
    static CRankLogic *single;//单例模式指针
};

#endif // CRANKLOGIC_H
