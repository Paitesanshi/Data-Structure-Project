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
}

CStageSelectDlg::~CStageSelectDlg()
{
    delete ui;
}

int CStageSelectDlg::getButtonIndex(){
    if(ui->radioButton->isChecked()){
        return 1;
    }
    if(ui->radioButton_2->isChecked()){
        return 2;
    }
    if(ui->radioButton_3->isChecked()){
        return 3;
    }
    if(ui->radioButton_4->isChecked()){
        return 4;
    }
    if(ui->radioButton_5->isChecked()){
        return 5;
    }
    if(ui->radioButton_6->isChecked()){
        return 6;
    }
    if(ui->radioButton_7->isChecked()){
        return 7;
    }
    if(ui->radioButton_8->isChecked()){
        return 8;
    }
    if(ui->radioButton_9->isChecked()){
        return 9;
    }
    else{
        return 1;
    }
}

void CStageSelectDlg::on_pushButton_clicked()//进入游戏按钮
{
    int stage = getButtonIndex();
    qDebug()<<logic->getPlayer().level<<endl;
    //logic->getPlayer().level=999;
    if(stage>logic->getPlayer().level/*条件判断：读取用户信息，仅开放已解锁关卡*/){
        QMessageBox::critical(this,"Failure","当前所选关卡尚未解锁！",QMessageBox::Cancel);
    }else{
        this->hide();
        //CGameDlg* gameDlg=new CGameDlg(1,6);
        int stage,cnt;
        stage=getButtonIndex();
        qDebug()<<stage;

         CGameDlg* gameDlg=new CGameDlg(stage%3+1,6+stage/3*2);
        gameDlg->show();
    }
//    this->hide();
//    CGameDlg* gameDlg=new CGameDlg(1,6);
//    gameDlg->show();
}

void CStageSelectDlg::on_pushButton_2_clicked()//取消按钮
{
    CBejeweledDlg* bejeweled=new CBejeweledDlg();
    bejeweled->show();
    this->close();
}

void CStageSelectDlg::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    pix.load(":/img/shiny rocks.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    QPixmap button;
    button.load(":/img/Button.png");

    painter.drawPixmap(ui->radioButton->pos().x()-10,ui->radioButton->pos().y(),ui->radioButton->width(),ui->radioButton->height(),button);
    painter.drawPixmap(ui->radioButton_2->pos().x()-10,ui->radioButton_2->pos().y(),ui->radioButton_2->width(),ui->radioButton_2->height(),button);
    painter.drawPixmap(ui->radioButton_3->pos().x()-10,ui->radioButton_3->pos().y(),ui->radioButton_3->width(),ui->radioButton_3->height(),button);
    painter.drawPixmap(ui->radioButton_4->pos().x()-10,ui->radioButton_4->pos().y(),ui->radioButton_4->width(),ui->radioButton_4->height(),button);
    painter.drawPixmap(ui->radioButton_5->pos().x()-10,ui->radioButton_5->pos().y(),ui->radioButton_5->width(),ui->radioButton_5->height(),button);
    painter.drawPixmap(ui->radioButton_6->pos().x()-10,ui->radioButton_6->pos().y(),ui->radioButton_6->width(),ui->radioButton_6->height(),button);
    painter.drawPixmap(ui->radioButton_7->pos().x()-10,ui->radioButton_7->pos().y(),ui->radioButton_7->width(),ui->radioButton_7->height(),button);
    painter.drawPixmap(ui->radioButton_8->pos().x()-10,ui->radioButton_8->pos().y(),ui->radioButton_8->width(),ui->radioButton_8->height(),button);
    painter.drawPixmap(ui->radioButton_9->pos().x()-10,ui->radioButton_9->pos().y(),ui->radioButton_9->width(),ui->radioButton_9->height(),button);

    drawIndex = getButtonIndex();
    QPixmap stageimg;
    if(drawIndex==1){
        stageimg.load(":/img/stage1.png");
        painter.drawPixmap(ui->radioButton_3->pos().x()+100,ui->radioButton_3->pos().y(),200,200,stageimg);
    }
    if(drawIndex==2){
        stageimg.load(":/img/stage2.png");
        painter.drawPixmap(ui->radioButton_3->pos().x()+100,ui->radioButton_3->pos().y(),200,200,stageimg);
    }
    if(drawIndex==3){
        stageimg.load(":/img/stage3.png");
        painter.drawPixmap(ui->radioButton_3->pos().x()+100,ui->radioButton_3->pos().y(),200,200,stageimg);
    }
    if(drawIndex==4){
        stageimg.load(":/img/stage4.png");
        painter.drawPixmap(ui->radioButton_3->pos().x()+100,ui->radioButton_3->pos().y(),200,200,stageimg);
    }
    if(drawIndex==5){
        stageimg.load(":/img/stage5.png");
        painter.drawPixmap(ui->radioButton_3->pos().x()+100,ui->radioButton_3->pos().y(),200,200,stageimg);
    }
    if(drawIndex==6){
        stageimg.load(":/img/stage6.png");
        painter.drawPixmap(ui->radioButton_3->pos().x()+100,ui->radioButton_3->pos().y(),200,200,stageimg);
    }
    if(drawIndex==7){
        stageimg.load(":/img/stage7.png");
        painter.drawPixmap(ui->radioButton_3->pos().x()+100,ui->radioButton_3->pos().y(),200,200,stageimg);
    }
    if(drawIndex==8){
        stageimg.load(":/img/stage8.png");
        painter.drawPixmap(ui->radioButton_3->pos().x()+100,ui->radioButton_3->pos().y(),200,200,stageimg);
    }
    if(drawIndex==9){
        stageimg.load(":/img/stage9.png");
        painter.drawPixmap(ui->radioButton_3->pos().x()+100,ui->radioButton_3->pos().y(),200,200,stageimg);
    }
}

void CStageSelectDlg::on_radioButton_clicked()
{
    update();
}

void CStageSelectDlg::on_radioButton_2_clicked()
{
    update();
}

void CStageSelectDlg::on_radioButton_3_clicked()
{
    update();
}

void CStageSelectDlg::on_radioButton_4_clicked()
{
    update();
}

void CStageSelectDlg::on_radioButton_5_clicked()
{
    update();
}

void CStageSelectDlg::on_radioButton_6_clicked()
{
    update();
}

void CStageSelectDlg::on_radioButton_7_clicked()
{
    update();
}

void CStageSelectDlg::on_radioButton_8_clicked()
{
    update();
}

void CStageSelectDlg::on_radioButton_9_clicked()
{
    update();
}
