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
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width() / 5);
    ui->tableWidget->setColumnWidth(1, ui->tableWidget->width() / 5);
    ui->tableWidget->setColumnWidth(2, (ui->tableWidget->width() / 5)-10);
    ui->tableWidget->setColumnWidth(3, (ui->tableWidget->width() / 5)-10);
    ui->tableWidget->setColumnWidth(4, (ui->tableWidget->width() / 5)+15);

    //设置排行榜表格正文
    set<RANKINFOR,comp> ranks = logic->getRank();//获得排名信息

    /*如果排名信息非空，则填入表中*/
    qDebug()<<"-------------"<<ranks.size();
    for(auto &item: ranks)
    {
        qDebug()<<item.strName;
    }
    if(!ranks.empty()){
        set<RANKINFOR,comp>::iterator it=ranks.begin();
        if(ranks.size()>10){
            for(int i = 0 ; i < 10 ; i++){
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(it->strName));
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(it->finalGrade)));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(it->level)));
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(it->nTime)));
                it++;
            }
        }
        else{
            for(int i = 0 ; i < (int)ranks.size() ; i++){

                ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString(it->strName)));
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(it->finalGrade)));
               // qDebug()<<it->finalGrade<<it->nTime;
//                ui->tableWidget->setItem(i,2,new QTableWidgetItem(it->nGrade));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(it->level)));
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(it->nTime)));
                it++;
            }
        }
    }

}

CRankDlg::~CRankDlg()
{
    delete ui;
}
