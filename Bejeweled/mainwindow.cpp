#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "csetdlg.h"
#include "cbejeweleddlg.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    CBejeweledDlg* CDialog = new CBejeweledDlg(this);//实例化游戏菜单窗口
    CDialog->show();
    CRankLogic *c=new CRankLogic();
}

MainWindow::~MainWindow()
{
    delete ui;
}
