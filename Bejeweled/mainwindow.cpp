#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"xx";
    CRankLogic *c=new CRankLogic();
}

MainWindow::~MainWindow()
{
    delete ui;
}
