#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"xx";
    CRankLogic *c=new CRankLogic();

    CMenu = new CMenuDlg(this);//实例化游戏菜单窗口
    CMenu->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
