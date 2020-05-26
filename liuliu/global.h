#ifndef GLOBAL_H
#define GLOBAL_H

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
    char strName[50];   // 玩家姓名
    int nTime;          // 剩余时间
    int nGrade;         // 玩家积分
    int nRank;          // 玩家排名
} RANKINFOR;

#endif // GLOBAL_H
