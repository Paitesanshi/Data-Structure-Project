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
