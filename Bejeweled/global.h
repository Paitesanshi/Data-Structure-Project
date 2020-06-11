#ifndef GLOBAL_H
#define GLOBAL_H
#include <QDebug>
typedef struct PICTUREELEMENT  // 图片元素信息
{
    int nRow;       // 行号
    int nCol;       // 列号
    int nPicNum;    // 图片编号

    bool operator==(const PICTUREELEMENT &p) const{
        if (nRow == p.nRow && nCol == p.nCol)
            return true;
        else
            return false;
    }

    bool operator<(const PICTUREELEMENT &p) const{
        if (nRow<p.nRow)
            return true;
        else if (nRow == p.nRow){
            if (nCol<p.nCol)
                return true;
            else
                return false;
        }
        else
            return false;
    }
} PICELEM;

typedef struct RANKINFORMATION  // 玩家积分信息
{
    QString strName;   // 玩家姓名
    QString strPass;//玩家密码
    int level;//玩家最高关卡
    int finalGrade;//最高关分数
    int nTime;          // 剩余时间
    int nGrade[12];         // 玩家积分
    int nRank;          // 玩家排名
    bool operator>(const RANKINFORMATION& a)const
    {
        if(level==a.level)
            return finalGrade>a.finalGrade;
        return level>a.level;
    }

} RANKINFOR;
class comp{
public:
    bool operator()(const RANKINFOR &s1,const RANKINFOR &s2){
        if(s1.level==s2.level)
        {
            if(s1.finalGrade==s2.finalGrade)
            {
                return s1.strName<s2.strName;
            }
            return s1.finalGrade>s2.finalGrade;
        }
        return s1.level>s2.level;
    }
};
#endif // GLOBAL_H
