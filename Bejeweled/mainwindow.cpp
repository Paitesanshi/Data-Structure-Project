#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "csetdlg.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CRankLogic *c=new CRankLogic();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//测试菜单窗口
{
    CMenu = new CMenuDlg(this);//实例化游戏菜单窗口
    CMenu->show();
}
