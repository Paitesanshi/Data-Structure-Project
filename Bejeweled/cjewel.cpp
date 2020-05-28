#include "cjewel.h"

#include <QCoreApplication>
#include <QFile>

CJewel::CJewel(QMainWindow* ui,QWidget* parent):QLabel(parent)
{
    this->ui=ui;
    timer=new QTimer();
    img=new QImage;
    flag=false;
}

void CJewel::setPhoto(){
    filename=new QString("D:\\Qt\\"+QString::number(number)+".png");
    pixmap=new QPixmap("D:\\Qt\\"+QString::number(number)+".png");
//    filename=new QString("img\\Jewel"+QString::number(number)+".png");
      filename=new QString("img\\Jewel\\"+QString::number(number)+".png");
    pixmap=new QPixmap("img\\Jewel\\"+QString::number(number)+".png");
    qDebug()<<QCoreApplication::applicationDirPath()<<*filename<<endl;
    //QFile file("")
    if(! ( img->load(*filename) ) ) //加载图像
        {
            QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
            delete img;
            return;
        }
    setPixmap(QPixmap::fromImage(*img));
    setScaledContents(false);//图片随着标签大小的改变而改变
}

void CJewel::timerTimeOutl(){
    int x=this->x();
    int y=this->y();
    if(x>targetx){
        this->move(x-10,y);
    }
    else{
        this->timer->disconnect();
        this->timer->stop();
    }
}

void CJewel::timerTimeOutr(){
    int x=this->x();
    int y=this->y();
    if(x<targetx){
        this->move(x+10,y);
    }
    else{
        this->timer->disconnect();
        this->timer->stop();
    }
}

void CJewel::timerTimeOutu(){
    int x=this->x();
    int y=this->y();
    if(y>=55){
        this->setVisible(true);
    }
    else{
        this->setVisible(false);
    }
    if(y>targety){
        this->move(x,y-10);
    }
    else{
        this->timer->disconnect();
        this->timer->stop();
    }
}

void CJewel::timerTimeOutd(){
    int x=this->x();
    int y=this->y();
    if(y<targety){
        this->move(x,y+10);
    }
    else{
        this->timer->disconnect();
        this->timer->stop();
    }
}

