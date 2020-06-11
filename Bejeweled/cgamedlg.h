#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QWidget>
#include <QPixmap>
#include <cgamelogic.h>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QDir>
#include <QList>
#include <set>
#include <math.h>
#include <QThread>
#include <QTimer>
#include <cmenudlg.h>
#include <cprogressbar.h>
#include <cmusicplayer.h>
#include <cconfig.h>
#include <cconfiglogic.h>
#include <QLabel>
#include <cranklogic.h>
#include "cstop.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CGameDlg; }
QT_END_NAMESPACE

class CGameDlg : public QWidget
{
    Q_OBJECT

public:
    //QPixmap* pixmap[8][8];
    int score;
    int target;
    int time;
    int difficulty;
    int tool1;
    int tool2;
    int tool3;
    PICELEM p1;
    PICELEM p2;
    bool flag1;
    bool flag2;
    int** picture;
    int **photo;
    int** index;
    int dimension;
    int startX;
    int startY;
    int** showPic;
    int** lay;
    int bgplay;
    int soundplay;
    int del[10][2];
    int number[10]={0};
    int max[10]={0};
    int* first;
    bool flag3;
    bool flag4;
    bool flag5;
    bool flag6;
    bool flag7;
    bool flag8;
    bool flag9;
    PICELEM pic1;
    PICELEM pic2;
    SOLUTION solution;
    QLabel* label1;
    QLabel* label;
    CMusicPlayer* musicplayer;
    BgStyle theme;
    QString music;
    CConfig* config;
    CConfigLogic* configLogic;
    QTimer* timer;
    CProgressBar* bar;
    QString stringP[10];
    set<PICELEM> layout;
    set<PICELEM> setPic;
    set<PICELEM> elimite;
    QList<QPixmap*> frame;
    QList<QPixmap*> list;
    QList<PICELEM> pic;
    CGameLogic* logic;
    //CStop *nextStage;
    CRankLogic *rank;
    void changeTheme();
    void changeMusic();
    void setDelete(set<PICELEM> set);
    void msleep(unsigned long msecs);
    CGameDlg(int difficulty,int dimension,QWidget *parent = nullptr);
    ~CGameDlg();

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void paintEvent(QPaintEvent* event) override;

public slots:
    void timeOut();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::CGameDlg *ui;
};
#endif // CGAMEDLG_H
