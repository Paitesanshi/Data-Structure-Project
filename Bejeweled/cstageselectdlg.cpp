#include "cstageselectdlg.h"
#include "ui_cstageselectdlg.h"
#include <QDebug>
#include <QMessageBox>

CStageSelectDlg::CStageSelectDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CStageSelectDlg)
{
    ui->setupUi(this);

    logic = CRankLogic::getInstance();
    QStringList items;
    items << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9";
    ui->comboBox->addItems(items);
}

CStageSelectDlg::~CStageSelectDlg()
{
    delete ui;
}

void CStageSelectDlg::on_pushButton_clicked()//进入游戏按钮
{
    bool ok;
    int stage = (ui->comboBox->currentText()).toInt(&ok,10);
    if(stage>logic->getPlayer().level/*条件判断：读取用户信息，仅开放已解锁关卡*/){
        QMessageBox::critical(this,"Failure","当前所选关卡尚未解锁！",QMessageBox::Cancel);
    }else{
        this->hide();
        CGameDlg* gameDlg=new CGameDlg(6);
        gameDlg->show();
    }
}

void CStageSelectDlg::on_pushButton_2_clicked()//取消按钮
{
    this->close();
}
