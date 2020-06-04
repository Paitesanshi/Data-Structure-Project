#include "cbejeweleddlg.h"
#include "ui_cbejeweleddlg.h"

CBejeweledDlg::CBejeweledDlg(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CBejeweledDlg)
{
    ui->setupUi(this);
    logic = CRankLogic::getInstance();
}

CBejeweledDlg::~CBejeweledDlg()
{
    delete ui;
}

void CBejeweledDlg::on_pushButton_3_clicked()//登录
{
    name=new QNameDlg();
    name->show();
}

void CBejeweledDlg::on_pushButton_4_clicked()//注册
{

    setup=new QSetupDlg();
    setup->show();
}

void CBejeweledDlg::on_pushButton_clicked()//开始游戏
{
    if(logic->getPlayer().strName==""){
        QMessageBox::warning(this,"Failure","请先登录！",QMessageBox::Ok);
    }else{
        this->hide();
        CStageSelectDlg* stageSelect = new CStageSelectDlg();
        stageSelect->show();
    }
}

void CBejeweledDlg::on_pushButton_5_clicked()//退出游戏
{
    exit(0);
}

void CBejeweledDlg::on_pushButton_2_clicked()//帮助
{
    cHelp = new CHelpDlg(nullptr);
    cHelp->show();
}

void CBejeweledDlg::on_pushButton_6_clicked()//排行榜
{
    cRank = new CRankDlg(nullptr);
    cRank->show();
}

void CBejeweledDlg::on_pushButton_7_clicked()//菜单
{
    cMenu = new CMenuDlg(1,6);
    cMenu->show();
}

void CBejeweledDlg::on_pushButton_8_clicked()//设置
{
    cSet = new CSetDlg(nullptr);
    cSet->show();
}
