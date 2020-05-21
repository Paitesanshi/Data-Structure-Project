#include "cmenudlg.h"

CMenuDlg::CMenuDlg(QMainWindow *parent)
{
    this->setFixedSize(300,580);//菜单窗口大小

    this->setWindowTitle("菜单");//设置菜单标题

    //菜单界面的五个按钮
    QPushButton * mainMenuBtn = new QPushButton(this);
    QPushButton * resumeBtn = new QPushButton(this);
    QPushButton * restartBtn = new QPushButton(this);
    QPushButton * settingBtn = new QPushButton(this);
    QPushButton * quitBtn = new QPushButton(this);

    mainMenuBtn->setText("主菜单");
    resumeBtn->setText("返回游戏");
    restartBtn->setText("重新开始");
    settingBtn->setText("设置游戏");
    quitBtn->setText("退出游戏");

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
        parent->close();
        this->close();
    });
}