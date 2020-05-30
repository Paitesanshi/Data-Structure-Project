#include "cgamelogic.h"

CGameLogic::CGameLogic(int row, int col, int kinds)
{
    this->row = row;
    this->col = col;
    this->kinds = kinds;
    distribute = (int **) new int *[row];
    for (int i = 0; i < row; i++){
        distribute[i] = new int[col];
    }
}
CGameLogic::~CGameLogic(){
    for (int i = 0; i < row; i++)
        delete []distribute[i];
    delete[]distribute;
}

void CGameLogic::changeDemension(int row, int col)
{
    this->row = row;
    this->col = col;
    for (int i = 0; i < row; i++)
        delete[]distribute[i];
    delete[]distribute;

    distribute = (int **) new int *[row];
    for (int i = 0; i < row; i++){
        distribute[i] = new int[col];
    }
    solutions.clear();
}

void CGameLogic::changeKinds(int kinds)
{
    this->kinds = kinds;
    solutions.clear();
}

int **CGameLogic::getRandomDistribution()
{
    srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    solutions.clear();

    do{
        do{
            for (int i = 0; i<row; i++)
            for (int j = 0; j<col; j++)
                distribute[i][j] = rand() % kinds + 1;
        } while (hasChanged());



    } while (getAllSolutions() == false);

    return distribute;
}

bool CGameLogic::hasChanged(){
    for (int i = 0; i<row; i++){
        for (int j = 0; j<col; j++){
            if (j < col - 2){
                if (distribute[i][j] == distribute[i][j + 1] && distribute[i][j] == distribute[i][j + 2]){
                    return true;
                }
            }

            if (i < row - 2){
                if (distribute[i][j] == distribute[i + 1][j] && distribute[i][j] == distribute[i + 2][j]){
                    return true;
                }
            }
        }
    }
    return false;
}

bool CGameLogic::isAdjacent(PICELEM p1, PICELEM p2)
{
    if (p1<p2){
        this->p1 = p1;
        this->p2 = p2;
    }
    else{
        this->p1 = p2;
        this->p2 = p1;
    }

    if (p1.nRow == p2.nRow && (p1.nCol - p2.nCol == 1 || p1.nCol - p2.nCol == -1))
        return true;
    else if (p1.nCol == p2.nCol && (p1.nRow - p2.nRow == 1 || p1.nRow - p2.nRow == -1))
        return true;
    else
        return false;
}

set<PICELEM> CGameLogic::canSwop()
{
    for (set<SOLUTION>::iterator it = solutions.begin(); it != solutions.end(); it++){
        if ((*it).picture1 == p1 && (*it).picture2 == p2 || (*it).picture1 == p2 && (*it).picture2 == p1){
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
        distribute[(*it).nRow][(*it).nCol] = 0;
    }
    int k;
    srand((int)time(0));
    for (int i = 0; i<col; i++){
        k = row - 1;
        for (int j = row - 1; j >= 0; j--){
            if (distribute[j][i]>0){
                distribute[k][i] = distribute[j][i];
                k--;
            }
        }

        for (; k >= 0; k--){
            distribute[k][i] = rand() % kinds + 1;
            p.nRow=k;
            p.nCol=i;
            p.nPicNum=distribute[k][i];
            ss.insert(p);
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
                if (distribute[i][j] == distribute[i][j + 1] && distribute[i][j] == distribute[i][j + 2]){
                    for (int k = 0; k<3; k++){
                        p.nRow = i;
                        p.nCol = j + k;
                        p.nPicNum = distribute[i][j + k];
                        eliminateSet.insert(p);
                    }
                }
            }

            if (i < row - 2){
                if (distribute[i][j] == distribute[i + 1][j] && distribute[i][j] == distribute[i + 2][j]){
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
            if (j < col - 1 && distribute[i][j]!=distribute[i][j+1]){
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

            if (i < row - 1 && distribute[i][j]!=distribute[i + 1][j]){
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
                if (state[i][j] == state[i][j + 1] && state[i][j] == state[i][j + 2]){
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
                if (state[i][j] == state[i + 1][j] && state[i][j] == state[i + 2][j]){
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
