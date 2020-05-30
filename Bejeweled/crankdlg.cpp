#include "crankdlg.h"
#include "ui_crankdlg.h"
#include <QHeaderView>

CRankDlg::CRankDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CRankDlg)
{
    ui->setupUi(this);
    logic=CRankLogic::getInstance();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width() / 4);
    ui->tableWidget->setColumnWidth(1, ui->tableWidget->width() / 2);
    ui->tableWidget->setColumnWidth(2, (ui->tableWidget->width() / 4)-10);

    //设置排行榜表格正文
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("Paul Pheonix"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("Deathfist"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("Marshall Law"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("DB4"));


}

CRankDlg::~CRankDlg()
{
    delete ui;
}
