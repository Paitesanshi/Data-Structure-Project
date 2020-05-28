#include "cbejeweleddlg.h"
#include "ui_cbejeweleddlg.h"

CBejeweledDlg::CBejeweledDlg(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CBejeweledDlg)
{
    ui->setupUi(this);
}

CBejeweledDlg::~CBejeweledDlg()
{
    delete ui;
}

void CBejeweledDlg::on_pushButton_3_clicked()
{
    name=new QNameDlg();
    name->show();
}

void CBejeweledDlg::on_pushButton_4_clicked()
{

    setup=new QSetupDlg();
    setup->show();
}

void CBejeweledDlg::on_pushButton_clicked()
{
    this->hide();
    CGameDlg* gameDlg=new CGameDlg(6);
    gameDlg->show();
}

void CBejeweledDlg::on_pushButton_5_clicked()
{
    exit(0);
}

void CBejeweledDlg::on_pushButton_2_clicked()
{
    cHelp = new CHelpDlg(nullptr);
    cHelp->show();
}

void CBejeweledDlg::on_pushButton_6_clicked()
{
    cRank = new CRankDlg(nullptr);
    cRank->show();
}

void CBejeweledDlg::on_pushButton_7_clicked()
{
    cMenu = new CMenuDlg(this);
    cMenu->show();
}

void CBejeweledDlg::on_pushButton_8_clicked()
{
    cSet = new CSetDlg(nullptr);
    cSet->show();
}
