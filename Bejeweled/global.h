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
    char *strName;   // 玩家姓名
    int nTime;          // 剩余时间
    int nGrade;         // 玩家积分
    int nRank;          // 玩家排名
    bool operator>(const RANKINFORMATION& a)const
    {
        if(nGrade==a.nGrade)
            return nTime>a.nTime;
        return nGrade>a.nGrade;
    }

} RANKINFOR;
class comp{
public:
    bool operator()(const RANKINFOR &s1,const RANKINFOR &s2){
        if(s1.nGrade==s2.nGrade) return s1.nTime>s2.nTime;
        return s1.nGrade>s2.nGrade;
    }
};
#endif // GLOBAL_H
