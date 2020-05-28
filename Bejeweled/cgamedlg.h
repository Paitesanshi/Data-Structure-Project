#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QMainWindow>
#include <cjewel.h>
#include <QMouseEvent>
#include <QLabel>
#include <QTimer>
//#include <QImage>
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
//#include "structure.h"
#include "Global.h"
#include "picture.h"
#include "choose.h"
//#include "structure.h"
#include "cgamelogic.h"
#include <set>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class CGameDlg; }
QT_END_NAMESPACE

class CGameDlg : public QMainWindow
{
    Q_OBJECT

public:
    set<PICELEM> elimite;
    CGameLogic* logic;
    PICELEM p1;
    PICELEM p2;
    Choose choose1;
    Choose choose2;
    int col;
    int row;
    int kinds;
    QTimer* timer[8][8];
    QImage* image[8][8];
    int delLength=0;
    int del[8][2];
    int mark[8]={0};
    int number[8]={0};
    int min[8]={-1};
    Picture* picture[8][8];
    QPixmap* pixmap[8][8];
    CJewel* jewel[8][8];
    QPoint index[8][8];
    int** photo;
    void setPhoto();
    void paintMap();
    void changeJewel();
    void deleteJewel();
    void changeTheme();
    void setDelete(set<PICELEM> elimite);
    void moveChangeJewel(int labelx,int labely,int targetx,int targety,int pos);
    void moveDeleteJewel(int labelx,int labely);
    CGameDlg(int c,QWidget *parent = nullptr);
    ~CGameDlg();
private:
    Ui::CGameDlg *ui;
protected:
    void mousePressEvent(QMouseEvent *ev) override;
};
#endif // CGAMEDLG_H
