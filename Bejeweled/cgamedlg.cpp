#include "cgamedlg.h"
#include "ui_cgamedlg.h"

CGameDlg::CGameDlg(int kinds,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CGameDlg)
{
    ui->setupUi(this);
    logic=new CGameLogic(8,8,kinds);
    //在这里调用Logic函数得到图片的二维数组
    photo=logic->getRandomDistribution();
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            jewel[i][j]=new CJewel(this,this);
    elimite=logic->canEliminate();
    while(elimite.size()>0||logic->hasEliminate()==false){
        photo=logic->getRandomDistribution();
        elimite=logic->canEliminate();
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            del[j][0]=8;
            del[j][1]=8;
            jewel[i][j]=new CJewel(this,this);
            jewel[i][j]->targety=0;
            jewel[i][j]->number=photo[i][j];
            jewel[i][j]->col=i;
            jewel[i][j]->row=j;
            jewel[i][j]->setPhoto();
            image[i][j]=new QImage;
            timer[i][j]=new QTimer;
            index[i][j].setX(i);
            index[i][j].setY(j);
            picture[i][j]=new Picture;
            picture[i][j]->nRow=i;
            picture[i][j]->nCol=j;
            picture[i][j]->nPicNum=photo[i][j];
        }
    }
    paintMap();
}

void CGameDlg::changeTheme(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int ncol=index[i][j].x();
            int nrow=index[i][j].y();
            jewel[ncol][nrow]->number=photo[i][j];
            jewel[ncol][nrow]->setPhoto();
        }
    }
}

void CGameDlg::paintMap(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            jewel[i][j]->setGeometry(205+j*50,105+i*50,40,40);
            jewel[i][j]->setParent(this);
            jewel[i][j]->show();
        }
    }
}

void CGameDlg::mousePressEvent(QMouseEvent *ev){
    QPoint pos=ev->pos();
    int y=(pos.x()-205)/50;
    int x=(pos.y()-105)/50;
    jewel[x][y]->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
    jewel[index[x][y].x()][index[x][y].y()]->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
    qDebug()<<x;
    qDebug()<<y;
    if(choose1.flag==false){
        choose1.x=x;
        choose1.y=y;
        choose1.flag=true;
    }
    else if(choose2.flag==false){
        choose2.x=x;
        choose2.y=y;
        choose2.flag=true;
    }
    else{

    }
    qDebug()<<choose1.flag;
    qDebug()<<choose2.flag;
    if(choose1.flag==true&&choose2.flag==true){
        p1.nCol=choose1.x;
        p1.nRow=choose1.y;
        p1.nPicNum=picture[choose1.x][choose1.y]->nPicNum;
        p2.nCol=choose2.x;
        p2.nRow=choose2.y;
        p1.nCol=choose1.y;
        p1.nRow=choose1.x;
        p1.nPicNum=picture[choose1.x][choose1.y]->nPicNum;
        p2.nCol=choose2.y;
        p2.nRow=choose2.x;
        p2.nPicNum=picture[choose2.x][choose2.y]->nPicNum;
        int flag=logic->isAdjacent(p1,p2);
        //调用logic的相邻判断函数
        //如果为true：交换 更新判断
        qDebug()<<44;
        if(flag){
            if(choose1.x==choose2.x){
                if(choose1.y<choose2.y){
                    qDebug()<<11;
                    moveChangeJewel(index[choose1.x][choose1.y].x(),index[choose1.x][choose1.y].y(),index[choose2.x][choose2.y].x(),index[choose2.x][choose2.y].y(),1);
                    moveChangeJewel(index[choose2.x][choose2.y].x(),index[choose2.x][choose2.y].y(),index[choose1.x][choose1.y].x(),index[choose1.x][choose1.y].y(),0);
                }
                else{
                    qDebug()<<22;
                    moveChangeJewel(index[choose1.x][choose1.y].x(),index[choose1.x][choose1.y].y(),index[choose2.x][choose2.y].x(),index[choose2.x][choose2.y].y(),0);
                    moveChangeJewel(index[choose2.x][choose2.y].x(),index[choose2.x][choose2.y].y(),index[choose1.x][choose1.y].x(),index[choose1.x][choose1.y].y(),1);
                }
            }
            if(choose1.y==choose2.y){
                if(choose1.x<choose2.x){
                    qDebug()<<33;
                    moveChangeJewel(index[choose1.x][choose1.y].x(),index[choose1.x][choose1.y].y(),index[choose2.x][choose2.y].x(),index[choose2.x][choose2.y].y(),3);
                    moveChangeJewel(index[choose2.x][choose2.y].x(),index[choose2.x][choose2.y].y(),index[choose1.x][choose1.y].x(),index[choose1.x][choose1.y].y(),2);
                }
                else{
                    qDebug()<<44;
                    moveChangeJewel(index[choose1.x][choose1.y].x(),index[choose1.x][choose1.y].y(),index[choose2.x][choose2.y].x(),index[choose2.x][choose2.y].y(),2);
                    moveChangeJewel(index[choose2.x][choose2.y].x(),index[choose2.x][choose2.y].y(),index[choose1.x][choose1.y].x(),index[choose1.x][choose1.y].y(),3);
                }
            }
            changeJewel();
            elimite=logic->canSwop();
            qDebug()<<"@@";
            qDebug()<<elimite.size();
            int iter=0;
            for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
                qDebug()<<"!!";
                delLength++;
                del[iter][0]=it->nCol;
                del[iter][1]=it->nRow;
                mark[it->nRow]++;
                number[it->nRow]++;
                if(it->nCol+1>min[it->nRow]){
                    min[it->nRow]=it->nCol+1;
                }
            }
            deleteJewel();
        }
    }
            QTime time;
            time.start();
            while(time.elapsed() < 600)             //等待时间流逝5秒钟
                QCoreApplication::processEvents();
            elimite=logic->canSwop();
            qDebug()<<"@@";
            qDebug()<<elimite.size();
            setDelete(elimite);
        }
    }
}

void CGameDlg::setDelete(set<PICELEM> elimite){
    int iter=0;
    int minite[8]={0};
    for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
        qDebug()<<"!!";
        delLength++;
        del[iter][0]=it->nRow;
        del[iter][1]=it->nCol;
        iter++;
        mark[it->nCol]++;
        number[it->nCol]++;
        if(it->nRow+1>minite[it->nCol]){
            minite[it->nCol]=it->nRow+1;
        }
    }
    qDebug()<<22333444;
    for(int i=0;i<8;i++){
        min[i]=minite[i];
        qDebug()<<min[i];
    }
    deleteJewel();
    delLength=0;
    for(int i=0;i<8;i++){
        number[i]=0;
        mark[i]=0;
        min[i]=-1;
    }
}

void CGameDlg::deleteJewel(){
    //实现消子效果
    for(int i=0;i<delLength;i++){
        int col=del[i][0];
        int row=del[i][1];
        qDebug()<<6<<" "<<col<<" "<<row;
        jewel[index[col][row].x()][index[col][row].y()]->setVisible(false);
    for(int i=0;i<8;i++){
        int col=del[i][0];
        int row=del[i][1];
        qDebug()<<6<<" "<<col<<" "<<row;
        //jewel[index[col][row].x()][index[col][row].y()]->setVisible(false);
    }
    //宝石都应该在的位置，等待降落
    for(int i=0;i<8;i++){//第i列是否有需要消的子
        if(mark[i]!=0){//mark[i]记录着第i列有多少要消的子
            for(int j=0;j<8;j++){//第j行是否是第i列要消的子
                bool flag=false;
                for(int k=0;k<8;k++){
                    if(del[k][0]==j&&del[k][1]==i){
                        flag=true;
                    }
                }
                if(flag){
                    qDebug()<<j<<"true";
                    qDebug()<<mark[i];
                    jewel[index[j][i].x()][index[j][i].y()]->move(i*50+205,105-mark[i]*50);
                    jewel[index[j][i].x()][index[j][i].y()]->setVisible(true);
                    jewel[index[j][i].x()][index[j][i].y()]->targetx=i*50+205;
                    jewel[index[j][i].x()][index[j][i].y()]->targety=105+((j+number[i])%min[i])*50;
                    mark[i]--;
                }
                else{
                    qDebug()<<j<<"false"<<i;
                    jewel[index[j][i].x()][index[j][i].y()]->targetx=i*50+205;
                    jewel[index[j][i].x()][index[j][i].y()]->targety=105+(j+mark[i])*50;
                    qDebug()<<j<<i<<"true";
                    qDebug()<<mark[i];
                    jewel[index[j][i].x()][index[j][i].y()]->move(i*50+205,105-mark[i]*50);
                    QTime time;
                    time.start();
                    while(time.elapsed() < 100)             //等待时间流逝5秒钟
                        QCoreApplication::processEvents();
                    jewel[index[j][i].x()][index[j][i].y()]->setVisible(true);
                    jewel[index[j][i].x()][index[j][i].y()]->targetx=i*50+205;
                    jewel[index[j][i].x()][index[j][i].y()]->targety=105+((j+number[i])%min[i])*50;
                    qDebug()<<(jewel[index[j][i].x()][index[j][i].y()]->targety-105)/50;
                    mark[i]--;
                }
                else{
                    qDebug()<<j<<i<<"false";
                    jewel[index[j][i].x()][index[j][i].y()]->targetx=i*50+205;
                    jewel[index[j][i].x()][index[j][i].y()]->targety=105+(j+mark[i])*50;
                    qDebug()<<(jewel[index[j][i].x()][index[j][i].y()]->targety-105)/50;
                }
            }
        }
    }
    for(int i=0;i<8;i++){
        if(min[i]!=-1){
        if(min[i]!=0){
            qDebug()<<min[i];
            for(int j=0;j<min[i];j++){
                moveDeleteJewel(index[j][i].x(),index[j][i].y());
            }
        }
    }
    for(int i=0;i<8;i++){
        if(min[i]!=0){
            for(int j=0;j<min[i];j++){
                qDebug()<<(j+number[i]-1)%min[i];
                jewel[index[j][i].x()][index[j][i].y()]->col=(j+number[i])%min[i];
                index[j][i].setX(index[j+min[i]-number[i]%min[i]]->x());
                picture[j][i]->nPicNum=picture[(j+number[i])%min[i]][i]->nPicNum;
                qDebug()<<(j+min[i]-number[i])%min[i];
                jewel[index[j][i].x()][index[j][i].y()]->col=(j+number[i])%min[i];
                jewel[index[j][i].x()][index[j][i].y()]->row=i;
                index[j][i].setX(index[(j+min[i]-number[i])%min[i]][i].x());
                index[j][i].setY(index[(j+min[i]-number[i])%min[i]][i].y());
            }
        }
    }
}

void CGameDlg::moveDeleteJewel(int labelx,int labely){
    connect(jewel[labelx][labely]->timer,SIGNAL(timeout()),jewel[labelx][labely],SLOT(timerTimeOutd()));
    qDebug()<<jewel[labelx][labely]->col<<"@"<<jewel[labelx][labely]->row;
    jewel[labelx][labely]->timer->setSingleShot(false);
    jewel[labelx][labely]->timer->start(100);
}

void CGameDlg::changeJewel(){
    //交换PIC的num
    int i=picture[choose1.x][choose1.y]->nPicNum;
    picture[choose1.x][choose1.y]->nPicNum=picture[choose2.x][choose2.y]->nPicNum;
    picture[choose2.x][choose2.y]->nPicNum=i;
    //交换不同行列对应的QLabel
    int temx=index[choose1.x][choose1.y].x();
    int temy=index[choose1.x][choose1.y].y();
    index[choose1.x][choose1.y].setX(index[choose2.x][choose2.y].x());
    index[choose1.x][choose1.y].setY(index[choose2.x][choose2.y].y());
    index[choose2.x][choose2.y].setX(temx);
    index[choose2.x][choose2.y].setY(temy);
    //交换不同QLabel对应的行列
    int indx=jewel[index[choose1.x][choose1.y].x()][index[choose1.x][choose1.y].y()]->row;
    int indy=jewel[index[choose1.x][choose1.y].x()][index[choose1.x][choose1.y].y()]->col;
    jewel[index[choose1.x][choose1.y].x()][index[choose1.x][choose1.y].y()]->row=jewel[index[choose2.x][choose2.y].x()][index[choose2.x][choose2.y].y()]->row;
    jewel[index[choose1.x][choose1.y].x()][index[choose1.x][choose1.y].y()]->col=jewel[index[choose2.x][choose2.y].x()][index[choose2.x][choose2.y].y()]->col;
    jewel[index[choose2.x][choose2.y].x()][index[choose2.x][choose2.y].y()]->row=indx;
    jewel[index[choose2.x][choose2.y].x()][index[choose2.x][choose2.y].y()]->col=indy;
    //重置choose1\choose2的flag
    choose1.flag=false;
    choose2.flag=false;
    //去掉QLabel的边框
    jewel[index[choose1.x][choose1.y].x()][index[choose1.x][choose1.y].y()]->setStyleSheet("QLabel{border:0px solid rgb(0, 255, 0);}");
    jewel[index[choose2.x][choose2.y].x()][index[choose2.x][choose2.y].y()]->setStyleSheet("QLabel{border:0px solid rgb(0, 255, 0);}");
}


void CGameDlg::moveChangeJewel(int labelx,int labely,int targetx,int targety,int pos){
    qDebug()<<11;
    jewel[labelx][labely]->targetx=jewel[targetx][targety]->row*50+205;
    jewel[labelx][labely]->targety=jewel[targetx][targety]->col*50+105;
    if(pos==0){
        connect(jewel[labelx][labely]->timer,SIGNAL(timeout()),jewel[labelx][labely],SLOT(timerTimeOutl()));
    }
    else if(pos==1){
        connect(jewel[labelx][labely]->timer,SIGNAL(timeout()),jewel[labelx][labely],SLOT(timerTimeOutr()));
    }
    else if(pos==2){
        connect(jewel[labelx][labely]->timer,SIGNAL(timeout()),jewel[labelx][labely],SLOT(timerTimeOutu()));
    }
    else{
        connect(jewel[labelx][labely]->timer,SIGNAL(timeout()),jewel[labelx][labely],SLOT(timerTimeOutd()));
    }
    jewel[labelx][labely]->timer->setSingleShot(false);
    jewel[labelx][labely]->timer->start(100);
}


CGameDlg::~CGameDlg()
{
    delete ui;
}


void CGameDlg::on_pushButton_2_clicked()//打开菜单
{
    cMenu = new CMenuDlg(this);
    cMenu->show();
}

