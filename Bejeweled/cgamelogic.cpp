#include "cgamelogic.h"

CGameLogic::CGameLogic(int row, int col, int kinds, int difficulty)
{
    this->row = row;
    this->col = col;
    this->kinds = kinds;
    this->difficulty=difficulty;
    distribute = (int **) new int *[row];
    for (int i = 0; i < row; i++){
        distribute[i] = new int[col];
    }

    layout=(int **)new int *[3];
    for(int i=0;i<3;i++){
        layout[i]=new int[row*col];
    }

    for(int i=0;i<row*col;i++){
        for(int j=0;j<3;j++)
            layout[j][i]=1;
    }

    //闅惧害浜屽竷灞€锛?
    //001100   00011000   0000110000
    //011110   00111100   0001111000
    //111111   01111110   0011111100
    //111111   11111111   0111111110
    //011110   11111111   1111111111
    //001100   01111110   1111111111
    //         00111100   0111111110
    //         00011000   0011111100
    //                    0001111000
    //                    0000110000
    for(int i=0;i<row/2-1;i++){
        for(int j=0;j<col/2-1-i;j++){
            layout[1][i*row+j]=0;
            layout[1][i*row+col-j-1]=0;
            layout[1][(row-i-1)*row+j]=0;
            layout[1][(row-i-1)*row+col-j-1]=0;
        }
    }

    //闅惧害涓夊竷灞€锛?
    //001100   00011000   0000110000
    //011110   00111100   0001111000
    //111111   01111110   0011111100
    //111111   11111111   0111111110
    //110011   11111111   1111111111
    //100001   11100111   1111111111
    //         11000011   1111001111
    //         10000001   1110000111
    //                    1100000011
    //                    1000000001

    for(int i=0;i<row/2-1;i++){
        for(int j=0;j<col/2-1-i;j++){
            layout[2][i*row+j]=0;
            layout[2][i*row+col-j-1]=0;
            layout[2][(row-i-1)*row+col/2-1-j]=0;
            layout[2][(row-i-1)*row+col/2+j]=0;
        }
    }

}

void CGameLogic::output(){
    QString string[row];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            string[i].append(QString::number(distribute[i][j])+" ");
        }
        qDebug()<<string[i];
    }
}

CGameLogic::~CGameLogic(){
    for (int i = 0; i < row; i++)
        delete []distribute[i];
    delete []distribute;

    for (int i = 0; i < 3; i++)
        delete []layout[i];
    delete []layout;
}


set<PICELEM> CGameLogic::getLayout()
{
    set<PICELEM> s;
    PICELEM p;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            qDebug()<<layout[difficulty-1][i*row+j];
            if(layout[difficulty-1][i*row+j]==1){
                p.nRow=i;
                p.nCol=j;
                s.insert(p);
            }
        }
    }
    return s;
}

void CGameLogic::changeKinds(int kinds)
{
    this->kinds = kinds;
    solutions.clear();
}

int** CGameLogic::getRandomDistribution()
{
    set<PICELEM> s;
    PICELEM p;
    srand((int)time(0));  // 浜х敓闅忔満绉嶅瓙  鎶?鎹㈡垚NULL涔熻
    solutions.clear();

    do{
        do{
            for (int i = 0; i<row; i++){
                for (int j = 0; j<col; j++){
                    if(layout[difficulty-1][i*row+j]!=0)
                        distribute[i][j] = rand() % kinds + 1;
                    else
                        distribute[i][j]=0;
                }
            }
        } while (hasChanged());

    } while (getAllSolutions() == false);

    //for(int i=0;i<row;i++){
        //for(int j=0;j<col;j++){
            //if(distribute[i][j]>0){
                //p.nRow=i;
                //p.nCol=j;
                //p.nPicNum=distribute[i][j];
                //s.insert(p);
            //}
        //}
    //}
    return distribute;
}

bool CGameLogic::hasChanged(){
    for (int i = 0; i<row; i++){
        for (int j = 0; j<col; j++){
            if (j < col - 2){
                if (distribute[i][j] == distribute[i][j + 1] && distribute[i][j] == distribute[i][j + 2] && distribute[i][j]!=0){
                    return true;
                }
            }

            if (i < row - 2){
                if (distribute[i][j] == distribute[i + 1][j] && distribute[i][j] == distribute[i + 2][j] && distribute[i][j]!=0){
                    return true;
                }
            }
        }
    }
    return false;
}

bool CGameLogic::isAdjacent(PICELEM p1, PICELEM p2)
{
    //qDebug()<<11;
    if(distribute[p1.nRow][p1.nCol]==0 || distribute[p2.nRow][p2.nCol]==0)
        return false;

    if (p1<p2){
        this->p1 = p1;
        this->p2 = p2;
    }
    else{
        this->p1 = p2;
        this->p2 = p1;
    }


    //qDebug()<<22;

    if (p1.nRow == p2.nRow && (p1.nCol - p2.nCol == 1 || p1.nCol - p2.nCol == -1))
        return true;
    else if (p1.nCol == p2.nCol && (p1.nRow - p2.nRow == 1 || p1.nRow - p2.nRow == -1))
        return true;
    else
        return false;
}

set<PICELEM> CGameLogic::canSwop()
{
    //qDebug()<<solutions.size();
    for (set<SOLUTION>::iterator it = solutions.begin(); it != solutions.end(); it++){
        //qDebug()<<"ccc";
        if (((*it).picture1 == p1 && (*it).picture2 == p2) || ((*it).picture1 == p2 && (*it).picture2 == p1)){
            //qDebug()<<"bbb";
            int x = distribute[(*it).picture1.nRow][(*it).picture1.nCol];
            distribute[(*it).picture1.nRow][(*it).picture1.nCol] = distribute[(*it).picture2.nRow][(*it).picture2.nCol];
            distribute[(*it).picture2.nRow][(*it).picture2.nCol] = x;
            eliminateSet = (*it).feasible;
            return (*it).feasible;
        }
    }
    set<PICELEM> s;
    return s;
}

set<PICELEM> CGameLogic::fall()
{
    set<PICELEM> ss;
    PICELEM p;
    for (set<PICELEM>::iterator it = eliminateSet.begin(); it != eliminateSet.end(); it++){
        distribute[(*it).nRow][(*it).nCol] = -1;
    }
    int k;
    srand((int)time(0));

    for (int i = 0; i<col; i++){
        k = row - 1;
        while(distribute[k][i]==0)
            k--;
        for (int j = row - 1; j >= 0; j--){
            if (distribute[j][i]>0){
                distribute[k][i] = distribute[j][i];
                k--;
                if (k >= 0){
                    while (distribute[k][i] == 0){
                        k--;
                        if (k < 0)
                            break;
                    }
                }
            }
        }

        for (; k >= 0; k--){
            if(distribute[k][i]!=0){
                distribute[k][i] = rand() % kinds + 1;
                p.nRow=k;
                p.nCol=i;
                p.nPicNum=distribute[k][i];
                ss.insert(p);
            }

        }
    }

    solutions.clear();
    eliminateSet.clear();
    getAllSolutions();
    return ss;
}

set<PICELEM> CGameLogic::canEliminate(){
    PICELEM p;
    for (int i = 0; i<row; i++){
        for (int j = 0; j<col; j++){
            if (j < col - 2){
                if (distribute[i][j] == distribute[i][j + 1] && distribute[i][j] == distribute[i][j + 2] && distribute[i][j]!=0){
                    for (int k = 0; k<3; k++){
                        p.nRow = i;
                        p.nCol = j + k;
                        p.nPicNum = distribute[i][j + k];
                        eliminateSet.insert(p);
                    }
                }
            }

            if (i < row - 2){
                if (distribute[i][j] == distribute[i + 1][j] && distribute[i][j] == distribute[i + 2][j] && distribute[i][j]!=0){
                    for (int k = 0; k<3; k++){
                        p.nRow = i + k;
                        p.nCol = j;
                        p.nPicNum = distribute[i + k][j];
                        eliminateSet.insert(p);
                    }
                }
            }
        }
    }
    return eliminateSet;
}

PICELEM CGameLogic::eliminateOne(PICELEM p)
{
    int i=p.nRow;
    while(i>0){
        if(distribute[i-1][p.nCol]!=0){
            distribute[i][p.nCol]=distribute[i-1][p.nCol];
            i--;
        }
        else
            break;
    }

    srand((int)time(0));
    distribute[i][p.nCol]=rand() % kinds + 1;
    PICELEM p1;
    p1.nRow=i;
    p1.nCol=p.nCol;
    p1.nPicNum=distribute[i][p.nCol];

    solutions.clear();
    eliminateSet.clear();
    getAllSolutions();
    return p1;
}

set<PICELEM> CGameLogic::eliminateRow(int r)
{
    set<PICELEM> s;
    PICELEM p;
    srand((int)time(0));
    for(int i=0;i<col;i++){
        int j=r;
        if(distribute[j][i]==0)
            continue;

        while(j>0){
            if(distribute[j-1][i]!=0){
                distribute[j][i]=distribute[j-1][i];
                j--;
            }
            else
                break;
        }

        distribute[j][i]=rand() % kinds + 1;
        p.nRow=j;
        p.nCol=i;
        p.nPicNum=distribute[j][i];
        s.insert(p);
    }

    solutions.clear();
    eliminateSet.clear();
    getAllSolutions();
    return s;

}

set<PICELEM> CGameLogic::eliminateCol(int c)
{
    set<PICELEM> s;
    PICELEM p;
    srand((int)time(0));
    int i=0;
    while(distribute[i][c]==0)
        i++;

    while(i<row){
        if(distribute[i][c]!=0){
            distribute[i][c]=rand() % kinds + 1;
            p.nRow=i;
            p.nCol=c;
            p.nPicNum=distribute[i][c];
            s.insert(p);
            i++;
        }else
            break;

    }

    solutions.clear();
    eliminateSet.clear();
    getAllSolutions();
    return s;
}

bool CGameLogic::hasEliminate()
{
    if (solutions.size()>0)
        return true;
    else
        return false;
}

SOLUTION CGameLogic::getHint()
{
    set<SOLUTION>::iterator it = solutions.begin();
    return *it;
}


bool CGameLogic::getAllSolutions()
{
    bool flag = false;

    int x;
    PICELEM p1, p2;

    for (int i = 0; i<row; i++){
        for (int j = 0; j<col; j++){
            if(distribute[i][j]!=0){
                if (j < col - 1 && distribute[i][j]!=distribute[i][j+1] && distribute[i][j+1]!=0){
                    p1.nRow = i;
                    p1.nCol = j;
                    p1.nPicNum = distribute[i][j];
                    p2.nRow = i;
                    p2.nCol = j+1;
                    p2.nPicNum = distribute[i][j+1];

                    x = distribute[i][j];
                    distribute[i][j] = distribute[i][j+1];
                    distribute[i][j+1] = x;

                    if (changeIsFeasible(distribute, p1, p2))
                        flag = true;

                    x = distribute[i][j];
                    distribute[i][j] = distribute[i][j + 1];
                    distribute[i][j + 1] = x;
                }

                if (i < row - 1 && distribute[i][j]!=distribute[i + 1][j] && distribute[i + 1][j]!=0){
                    p1.nRow = i;
                    p1.nCol = j;
                    p1.nPicNum = distribute[i][j];
                    p2.nRow = i + 1;
                    p2.nCol = j;
                    p2.nPicNum = distribute[i + 1][j];

                    x = distribute[i][j];
                    distribute[i][j] = distribute[i + 1][j];
                    distribute[i + 1][j] = x;

                    if (changeIsFeasible(distribute, p1, p2))
                        flag = true;

                    x = distribute[i][j];
                    distribute[i][j] = distribute[i + 1][j];
                    distribute[i + 1][j] = x;
                }
            }
        }
    }

    return flag;
}

bool CGameLogic::changeIsFeasible(int **state, PICELEM p1, PICELEM p2){
    SOLUTION solution;
    solution.picture1 = p1;
    solution.picture2 = p2;
    PICELEM p;
    bool flag = false;
    for (int i = 0; i<row; i++){
        for (int j = 0; j<col; j++){
            if (j < col - 2){
                if (state[i][j] == state[i][j + 1] && state[i][j] == state[i][j + 2] && state[i][j]!=0){
                    flag = true;
                    for (int k = 0; k<3; k++){
                        p.nRow = i;
                        p.nCol = j + k;
                        p.nPicNum = state[i][j + k];
                        solution.feasible.insert(p);
                    }
                }
            }

            if (i < row - 2){
                if (state[i][j] == state[i + 1][j] && state[i][j] == state[i + 2][j] && state[i][j]!=0){
                    flag = true;
                    for (int k = 0; k<3; k++){
                        p.nRow = i + k;
                        p.nCol = j;
                        p.nPicNum = state[i+k][j];
                        solution.feasible.insert(p);
                    }
                }
            }
        }
    }
    if (flag){
        solutions.insert(solution);
        return true;
    }
    else
        return false;
}
