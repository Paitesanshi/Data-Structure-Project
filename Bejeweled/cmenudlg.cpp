#include "cmenudlg.h"
#include "csetdlg.h"
#include <cbejeweleddlg.h>
#include <cgamedlg.h>

CMenuDlg::CMenuDlg(int difficulty,int dimension,QMainWindow *parent)
{
    this->setFixedSize(300,580);//菜单窗口大小

    this->setWindowTitle("菜单");//设置菜单标题

    //菜单界面的五个按钮
    QPushButton * mainMenuBtn = new QPushButton(this);
    QPushButton * resumeBtn = new QPushButton(this);
    QPushButton * restartBtn = new QPushButton(this);
    QPushButton * settingBtn = new QPushButton(this);
    QPushButton * quitBtn = new QPushButton(this);

    //按钮文字
    mainMenuBtn->setText("主菜单");
    resumeBtn->setText("返回游戏");
    restartBtn->setText("重新开始");
    settingBtn->setText("设置游戏");
    quitBtn->setText("退出游戏");

    //按钮位置
    mainMenuBtn->resize(100,70);
    mainMenuBtn->move(100,50);

    resumeBtn->resize(100,70);
    resumeBtn->move(100,150);

    restartBtn->resize(100,70);
    restartBtn->move(100,250);

    settingBtn->resize(100,70);
    settingBtn->move(100,350);

    quitBtn->resize(100,70);
    quitBtn->move(100,450);

    connect(quitBtn,&QPushButton::clicked,[=](){
        exit(0);
    });//退出按钮：退出整个程序

    connect(settingBtn,&QPushButton::clicked,[=](){
        CSetDlg* CSet = new CSetDlg(nullptr);
        CSet->show();
    });//设置按钮：打开设置窗口

    connect(mainMenuBtn,&QPushButton::clicked,[=](){
        CBejeweledDlg* CMainmenu = new CBejeweledDlg(nullptr);
        CMainmenu->show();
        this->close();
        parent->close();
    });//主菜单按钮，关闭该菜单并返回主菜单

    connect(resumeBtn,&QPushButton::clicked,[=](){
        this->close();
    });//返回游戏按钮，关闭该菜单

    connect(restartBtn,&QPushButton::clicked,[=](){
        CGameDlg* gameDlg=new CGameDlg(difficulty,dimension);
        gameDlg->show();
        this->close();
        parent->close();
    });//重新开始游戏按钮，创建一个新的CGameDlg，并关闭原来的CGameDlg
}
