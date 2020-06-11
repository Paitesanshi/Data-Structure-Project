#include "cstop.h"
#include "ui_cstop.h"

CStop::CStop(int success,int dimension,int difficulty,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CStop)
{
    ui->setupUi(this);
    //qDebug()<<1;
    //this->stop=widget;
    this->dimension=dimension;
    this->difficulty=difficulty;
    //qDebug()<<2;
    if(success==1){
        //qDebug()<<3;
        ui->label->setText("恭喜你闯关成功！");
        //qDebug()<<6;
    }
    else{
        //qDebug()<<4;
        ui->label->setText("很遗憾，闯关失败");
        ui->pushButton->setEnabled(false);
        qDebug()<<"zzz";
    }
    //qDebug()<<5;
}

void CStop::on_pushButton_clicked()
{
    if(difficulty<=2){
        //qDebug()<<1;
        CGameDlg* game=new CGameDlg(difficulty+1,dimension);
        game->show();
    }
    else{
        //qDebug()<<2;
        if(dimension<=8){
            CGameDlg* game=new CGameDlg(1,dimension+2);
            game->show();
        }
        else{
            QMessageBox::critical(this,"SUCCESS","您已闯关成功！恭喜！",QMessageBox::Cancel);
        }
    }
    //stop->close();
    this->close();
}

void CStop::on_pushButton_2_clicked()
{
    CGameDlg* game=new CGameDlg(difficulty,dimension);
    //stop->close();
    game->show();
    this->close();
}

void CStop::on_pushButton_3_clicked()
{
    CBejeweledDlg* bejeweled=new CBejeweledDlg();
    bejeweled->show();
    //stop->close();
    this->close();
}
