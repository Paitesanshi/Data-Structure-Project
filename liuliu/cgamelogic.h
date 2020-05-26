#ifndef CGAMELOGIC_H
#define CGAMELOGIC_H
#include "global.h"
#include <set>
#include <ctime>
#include <cstdlib>
#include <iterator>
using namespace std;

typedef struct FEASIBLESOLUTION{
    PICELEM picture1;  //需要交换的第一个图片
    PICELEM picture2;  //需要交换的第二个图片
    set<PICELEM> feasible;  //交换后能消除的图片位置集合
    bool operator<(const FEASIBLESOLUTION &s) const
    {
        if (picture1.nCol < s.picture1.nCol)
            return true;
        else
            return false;
        /*bool flag1, flag2;

        if (picture1.nRow<s.picture1.nRow)
            flag1=true;
        else if (picture1.nRow == s.picture1.nRow){
            if (picture1.nCol<s.picture1.nCol)
                flag1 = true;
            else
                flag1 = false;
        }
        else
            flag1=false;

        if (picture2.nRow<s.picture2.nRow)
            flag2 = true;
        else if (picture2.nRow == s.picture2.nRow){
            if (picture2.nCol<s.picture2.nCol)
                flag2 = true;
            else
                flag2 = false;
        }
        else
            flag2 = false;

        if (flag1)
            return true;
        else if (flag2)
            return true;
        else
            return false;*/
    }
    bool operator==(const FEASIBLESOLUTION &s) const{
        if (picture1 == s.picture1 && picture2 == s.picture2)
            return true;
        else
            return false;
    }
}SOLUTION;

class CGameLogic
{
    int **distribute;  //二维数组存储目前宝石分布
    int kinds;  //宝石种类
    set<SOLUTION> solutions;  //存储目前可交换的所有选择和交换后消除的所有位置
    int row; //地图行数
    int col;  //地图列数
    PICELEM p1;  //选中的第一张图片
    PICELEM p2;  //选中的第二张图片
    set<PICELEM> eliminateSet;  //交换后需要消除的图片集合
    bool getAllSolutions();  //更新可交换的所有宝石
    bool changeIsFeasible(int **state,PICELEM p1,PICELEM p2);  //交换后是否可消除
    bool hasChanged(); //随机生成整体布局后判断是否有能消除的
public:
    CGameLogic(int row,int col,int kinds);
    ~CGameLogic();
    void changeDemension(int row,int col);  //改变地图行数和列数
    void changeKinds(int kinds);  //改变宝石种类
    int **getRandomDistribution();  //获取随机生成的地图
    bool isAdjacent(PICELEM p1,PICELEM p2);  //两个图片是否相邻
    set<PICELEM> canSwop();  //两个图片交换后是否能够消除
    set<PICELEM> fall();  //获取消除后落下新宝石的集合
    bool hasEliminate();  //是否存在能够交换消除的宝石
    SOLUTION getHint();  //获得提示
    set<PICELEM> canEliminate(); //当前布局有没有可消除的宝石
};

#endif // CGAMELOGIC_H
