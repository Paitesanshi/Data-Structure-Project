#include "cgamedlg.h"
#include "ui_cgamedlg.h"

CGameDlg::CGameDlg(int difficulty,int dimension,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CGameDlg)
{
    ui->setupUi(this);
    nextStage=new CStop(1,dimension,difficulty);
    this->rank=CRankLogic::getInstance();
    flag1=false;
    flag2=false;
    startX=400-dimension/2.0*70;
    startY=startX;
    //qDebug()<<startX;
    this->difficulty=difficulty;
    this->dimension=dimension;
    for(int i=0;i<dimension*dimension;i++){
        QPixmap* pixmap=new QPixmap();
        list.append(pixmap);
    }
    for(int i=0;i<dimension*dimension;i++){
        QPixmap* pixmap=new QPixmap();
        frame.append(pixmap);
    }
    first=new int[dimension];
    photo = (int **) new int *[dimension];
    for (int i = 0; i < dimension; i++){
        first[i]=0;
        photo[i] = new int[dimension];
    }
    showPic = (int **) new int *[dimension];
    for (int i = 0; i < dimension; i++){
        showPic[i] = new int[dimension];
    }
    lay = (int **) new int *[dimension];
    for (int i = 0; i < dimension; i++){
        lay[i] = new int[dimension];
    }
    //qDebug()<<44;
    //bgpaint=new QPixmap();
    flag3=true;
    configLogic=new CConfigLogic();
    //qDebug()<<33;
    config=configLogic->getConfig();
    //qDebug()<<11;
    theme=config->Get_Picture_Style();
    //qDebug()<<22;
    bgplay=config->Get_Switch_BgMusic();
    ui->label->setStyleSheet("background-color:white");
    //QString background=theme.picture_BgPic;
    //qDebug()<<background;
    if(bgplay==1){
        musicplayer=new CMusicPlayer(config->Get_Music_BgMusicPath());
        musicplayer->PlayBgMusic();
    }
    soundplay=config->Get_Switch_Sound();
    if(soundplay==1){
        musicplayer->PlaySound(1);
    }
    bar=new CProgressBar(this);
    bar->setGeometry(300,800,600,40);
    /*bar->setStyleSheet("\
                          QProgressBar::chunk {\
                              background-color: #CD96CD;\
                              width: 10px;\
                              margin: 0.5px;\
                          }");*/
    //bar->setRange(0,100);
    score=0;//初始分数为0
    target=(dimension-6)/2*500+difficulty*200;
    qDebug()<<target;
    this->ui->label_2->setText("目标："+QString::number(target));
    this->ui->label_2->setStyleSheet("background-color:white");
    time=100;//可改，通过更改time来改变,单位是秒
    bar->setValue(time);
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timeOut()));
    int kinds=0;
    if(dimension==6){
        kinds=4;
    }
    else if(dimension==8){
        kinds=5;
    }
    else{
        kinds=6;
    }
    logic=new CGameLogic(dimension,dimension,kinds,difficulty);
    picture=logic->getRandomDistribution();
    //qDebug()<<22;
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            photo[i][j]=picture[i][j];
            //qDebug()<<photo[i][j];
            showPic[i][j]=0;
        }
    }
    /*
    for(set<PICELEM>::iterator it=setPic.begin();it!=setPic.end();it++){
        int x=(*it).nRow;
        //qDebug()<<x;
        int y=(*it).nCol;
        //qDebug()<<x<<y;
        photo[x][y]=it->nPicNum;
        //qDebug()<<x<<y<<photo[x][y];
    }
    */
    //qDebug()<<11;
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            lay[i][j]=0;
        }
    }
    layout=logic->getLayout();
    for(set<PICELEM>::iterator it=layout.begin();it!=layout.end();it++){
        int x=(*it).nRow;
        int y=(*it).nCol;
        lay[x][y]=1;
    }
    //for(int i=0;i<dimension;i++){
        //stringP[i].clear();
        //for(int j=0;j<dimension;j++){
            //stringP[i].append(QString::number(lay[i][j])+" ");
        //}
        //qDebug()<<stringP[i];
    //}
    elimite=logic->canEliminate();
    while(elimite.size()>0||logic->hasEliminate()==false){
        picture=logic->getRandomDistribution();
        for(int i=0;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                photo[i][j]=picture[i][j];
            }
        }
        for(set<PICELEM>::iterator it=setPic.begin();it!=setPic.end();it++){
            int x=(*it).nRow;
            int y=(*it).nCol;
            photo[x][y]=it->nPicNum;
        }
        elimite=logic->canEliminate();
    }
    timer->start(1000);
}

void CGameDlg::timeOut(){
    time--;
    bar->setValue(time);
    bar->repaint();
    if(time==0){
        timer->stop();
        CStop* stop=new CStop(0,dimension,difficulty);
        stop->show();
        bool up=false;
        int stage=(dimension-6)/2*3+difficulty;
        if(stage==this->rank->getPlayer().level)
        {
            if(score>this->rank->getPlayer().finalGrade)
            {
                this->rank->getPlayer().finalGrade=score;
                this->rank->getPlayer().nTime=time;
                up=true;
            }

        }
        if(score>this->rank->getPlayer().nGrade[stage])
        {
            this->rank->getPlayer().nGrade[stage]=score;
            up=true;
        }
        if(up)rank->addUser(this->rank->getPlayer());
        this->close();
    }
}

void CGameDlg::paintEvent(QPaintEvent *event){
    //qDebug()<<11;
    QPainter painter(this);
    //qDebug()<<"aaaaa";
    //qDebug()<<"bbbb";
    painter.drawPixmap(0,0,1200,900,theme.picture_BgPic);
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            //if(photo[i][j]==0){
                //continue;
            //}
            if(lay[i][j]==1){
                //qDebug()<<theme.picture_Element[photo[i][j]-1]<<photo[i][j];
                if(showPic[i][j]==1){
                    frame.at(i*dimension+j)->load("./images/10.png");
                    painter.drawPixmap(startX+j*70,startY+i*70,70,70,*frame.at(i*dimension+j));
                }
                list.at(i*dimension+j)->load(theme.picture_Element[photo[i][j]-1]);
                painter.drawPixmap(startX+j*70,startY+i*70,70,70,*list.at(i*dimension+j));
            }
            else{
                list.at(i*dimension+j)->load(theme.picture_Element[photo[i][j]-1]);
            }
        }
    }
}

void CGameDlg::msleep(unsigned long msecs){
    QThread::msleep(msecs);
}

void CGameDlg::mousePressEvent(QMouseEvent *ev){
    QPoint pos=ev->pos();
    int x,y;
    x=(pos.y()-startY)/70;
    y=(pos.x()-startX)/70;
    qDebug()<<x<<" "<<y;
    if(!((pic1.nRow==x&&pic1.nCol==y)||(pic2.nRow==x&&pic2.nCol==y))){
        for(int i=0;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                showPic[i][j]=0;
            }
        }
    }
    repaint();
    if(soundplay==1){
        musicplayer->PlaySound(2);
    }
    if(flag1==false){
        p1.nRow=x;
        p1.nCol=y;
        p1.nPicNum=photo[x][y];
        flag1=true;
        showPic[x][y]=1;
        repaint();
    }
    else if(flag2==false){
        p2.nRow=x;
        p2.nCol=y;
        p2.nPicNum=photo[x][y];
        flag2=true;
        showPic[x][y]=1;
        repaint();
    }
    else{

    }
    if(flag1==true&&flag2==true){
        flag3=true;
        //qDebug()<<"p1:x"<<p1.nRow<<"p1:y"<<p1.nCol<<"p1:pic"<<p1.nPicNum;
        //qDebug()<<"p2:x"<<p2.nRow<<"p2:y"<<p2.nCol<<"p2:pic"<<p2.nPicNum;
        qDebug()<<"aaa";
        bool flag=logic->isAdjacent(p1,p2);
        qDebug()<<flag;
        if(flag){
            elimite=logic->canSwop();
            qDebug()<<elimite.size();
            //qDebug()<<elimite.size();
            photo[p1.nRow][p1.nCol]=p2.nPicNum;
            photo[p2.nRow][p2.nCol]=p1.nPicNum;
            showPic[p1.nRow][p1.nCol]=0;
            showPic[p2.nRow][p2.nCol]=0;
            repaint();
            msleep(300);                              //休眠
            if(elimite.size()==0){
                //qDebug()<<33;
                int indx=photo[p1.nRow][p1.nCol];
                photo[p1.nRow][p1.nCol]=photo[p2.nRow][p2.nCol];
                photo[p2.nRow][p2.nCol]=indx;
                repaint();
            }
            else{
                setDelete(elimite);
//                score=score+elimite.size()*10;
//                ui->label->setText("分数："+QString::number(score));
                if(score>=target){
                    msleep(100);
                    score=score+time*5;
                    if(soundplay==1){
                        musicplayer->StopBgMusic();
                    }
                    //qDebug()<<11;
                    qDebug()<<"difficulty"+QString::number(difficulty)+"dimension"+QString::number(dimension);


                    //qDebug()<<22;

                    if(!this->nextStage->isVisible())
                    {

                        nextStage->show();
                        bool up=false;
                        int stage=(dimension-6)/2*3+difficulty;
                        if(stage==this->rank->getPlayer().level)
                        {
                            this->rank->getPlayer().level++;
                            this->rank->getPlayer().finalGrade=0;
                            this->rank->getPlayer().nTime=0;
                            up=true;
                        }
                        if(score>this->rank->getPlayer().nGrade[stage])
                        {
                            this->rank->getPlayer().nGrade[stage]=score;
                            up=true;
                        }
                        if(up)rank->addUser(this->rank->getPlayer());
                        //qDebug()<<"---"<<this->nextStage->isVisible();
                    }

                    //qDebug()<<33;
                    this->close();
                    //qDebug()<<44;
                }
            }
        }
        flag1=false;
        flag2=false;
        //qDebug()<<" ";
    }
}

void CGameDlg::setDelete(set<PICELEM> elimite){
    score=score+elimite.size()*10;
    ui->label->setText("分数："+QString::number(score));
    int column;
    for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
        if(soundplay==1){
            musicplayer->PlaySound(3);
        }
        int x=(*it).nRow;
        int y=(*it).nCol;
        photo[x][y]=7;
        column=it->nCol;
    }
    repaint();
    msleep(60);
    for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
        int x=(*it).nRow;
        int y=(*it).nCol;
        photo[x][y]=8;
    }
    repaint();
    msleep(60);
    for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
        int x=(*it).nRow;
        int y=(*it).nCol;
        photo[x][y]=9;
    }
    repaint();
    msleep(60);
    qDebug()<<"aaa";
    int iter=0;
    for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
         //delLength++;
        del[iter][0]=it->nRow;
        del[iter][1]=it->nCol;
        iter++;
        number[it->nCol]++;
        if(it->nRow+1>max[it->nCol]){
            max[it->nCol]=it->nRow+1;
        }
    }
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            if(lay[j][i]==0){
                continue;
            }else{
                first[i]=j;
                qDebug()<<first[i];
                break;
            }
        }
    }
    elimite=logic->fall();
    for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
        pic.append(*it);
    }
    for(int i=0;i<dimension;i++){
        if(number[i]!=0){
            for(int k=0,l=number[i]-1;k<number[i];k++,l--){
                for(int j=max[i]-1;j>=first[i]+1;j--){
                    photo[j][i]=photo[j-1][i];
                }
                for(int h=0;h<pic.size();h++){
                    if(pic.at(h).nRow==l&&pic.at(h).nCol==i){
                        photo[first[i]][i]=pic.at(h).nPicNum;
                    }
                }
                repaint();
                msleep(150);
            }
        }
    }
    //qDebug()<<"fall";
    //for(int i=0;i<dimension;i++){
        //stringP[i].clear();
        //for(int j=0;j<dimension;j++){
            //stringP[i].append(QString::number(photo[i][j])+" ");
        //}
        //qDebug()<<stringP[i];
    //}
    //qDebug()<<"logic fall";
    logic->output();
    for(int i=0;i<dimension;i++){
        number[i]=0;
        del[i][0]=0;
        del[i][1]=0;
        max[i]=0;
        first[i]=0;
    }
    pic.clear();
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            if(picture[i][j]!=photo[i][j]){
                photo[i][j]=picture[i][j];
                repaint();
            }
        }
    }
    elimite=logic->canEliminate();
    while(elimite.size()>0){
        //qDebug()<<"delete";
        if(soundplay==1&&flag3){
            musicplayer->PlaySound(4);
            flag3=false;
        }
        setDelete(elimite);
        score=score+elimite.size()*10;
        ui->label->setText("分数："+QString::number(score));
//        if(score>=target){
//            msleep(100);
//            if(soundplay==1){
//                musicplayer->StopBgMusic();
//            }
//            //qDebug()<<"aa";
//            qDebug()<<"difficulty"+QString::number(difficulty)+"dimension"+QString::number(dimension);
//            CStop* stop=new CStop(1,dimension,difficulty);
//            //qDebug()<<"bb";
//            stop->show();
//            //qDebug()<<"cc";
//            this->close();
//            //qDebug()<<"dd";
//        }
        elimite=logic->canEliminate();
    }
    bool flag1=logic->hasEliminate();
    if(!flag1){
        //qDebug()<<"nothing";
        picture=logic->getRandomDistribution();
        for(int i=0;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                photo[i][j]=picture[i][j];
            }
        }
        for(set<PICELEM>::iterator it=setPic.begin();it!=setPic.end();it++){
            int x=(*it).nRow;
            int y=(*it).nCol;
            photo[x][y]=it->nPicNum;
        }
        elimite=logic->canEliminate();
        while(elimite.size()>0||logic->hasEliminate()==false){
            picture=logic->getRandomDistribution();
            for(int i=0;i<dimension;i++){
                for(int j=0;j<dimension;j++){
                    photo[i][j]=picture[i][j];
                }
            }
            for(set<PICELEM>::iterator it=setPic.begin();it!=setPic.end();it++){
                int x=(*it).nRow;
                int y=(*it).nCol;
                photo[x][y]=it->nPicNum;
            }
            elimite=logic->canEliminate();
        }
    }
}

CGameDlg::~CGameDlg()
{
    delete ui;
}


void CGameDlg::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="STOP"){
        timer->stop();
        label=new QLabel();
        label->setGeometry(0,0,750,750);
        label->setParent(this);
        QString string="border-image:url(";
        QString string1=theme.picture_Element[10];
        string.append(string1+")");
        label->setStyleSheet(string);
        label->show();
        ui->pushButton->setText("START");
    }else{
        timer->start(1000);
        label->hide();
        ui->pushButton->setText("STOP");
    }
}

void CGameDlg::on_pushButton_3_clicked()
{
    score=score-50;
    solution=logic->getHint();
    pic1=solution.picture1;
    pic2=solution.picture2;
    showPic[pic1.nRow][pic1.nCol]=1;
    showPic[pic2.nRow][pic2.nCol]=1;
    repaint();
}
