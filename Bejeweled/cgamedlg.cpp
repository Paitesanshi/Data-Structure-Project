#include "cgamedlg.h"
#include "ui_cgamedlg.h"

CGameDlg::CGameDlg(int difficulty,int dimension,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CGameDlg)
{
    //qDebug()<<"---------"<<QDir::currentPath()<<endl;
    ui->setupUi(this);
    //nextStage=new CStop(1,dimension,difficulty);
    this->rank=CRankLogic::getInstance();
    flag1=false;
    flag2=false;
    flag4=false;
    flag5=false;
    flag6=false;
    flag7=true;
    flag8=true;
    flag9=true;
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
    //qDebug()<<target;
    this->ui->label_2->setText("目标："+QString::number(target));
    this->ui->label_2->setStyleSheet("background-color:white");

    label1=new QLabel();

    ui->label_3->setParent(this);
    QString string="border-image:url(";
    QString string1=theme.picture_Element[11];
    string.append(string1+")");
    ui->label_3->setStyleSheet(string);
    ui->label_3->show();
    //ui->pushButton_2->setEnabled(false);
    tool1=1;
    ui->pushButton_2->setText("可使用数量："+QString::number(tool1));

    ui->label_5->setParent(this);
    QString string2="border-image:url(";
    QString string3=theme.picture_Element[12];
    string2.append(string3+")");
    ui->label_5->setStyleSheet(string2);
    ui->label_5->show();
    //ui->pushButton_4->setEnabled(false);
    tool2=1;
    ui->pushButton_4->setText("可使用数量："+QString::number(tool2));

    ui->label_7->setParent(this);
    QString string4="border-image:url(";
    QString string5=theme.picture_Element[13];
    string4.append(string5+")");
    ui->label_7->setStyleSheet(string4);
    ui->label_7->show();
    //ui->pushButton_5->setEnabled(false);
    tool3=1;
    ui->pushButton_5->setText("可使用数量："+QString::number(tool3));

    ui->label_4->setParent(this);
    QString string6="border-image:url(";
    QString string7=theme.picture_Element[14];
    string6.append(string7+")");
    ui->label_4->setStyleSheet(string6);
    ui->label_4->show();

    ui->label_6->setParent(this);
    QString string8="border-image:url(";
    QString string9=theme.picture_Element[16];
    string8.append(string9+")");
    ui->label_6->setStyleSheet(string8);
    ui->label_6->show();

    ui->label_8->setParent(this);
    QString string10="border-image:url(";
    QString string11=theme.picture_Element[18];
    string10.append(string11+")");
    ui->label_8->setStyleSheet(string10);
    ui->label_8->show();

    ui->label_9->setParent(this);
    QString string12="border-image:url(";
    QString string13=theme.picture_Element[20];
    string12.append(string13+")");
    ui->label_9->setStyleSheet(string12);
    ui->label_9->show();

    ui->label_10->setParent(this);
    QString string14="border-image:url(";
    QString string15=theme.picture_Element[21];
    string14.append(string15+")");
    ui->label_10->setStyleSheet(string14);
    ui->label_10->show();

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
    if(pos.x()>=1020&&pos.x()<=1060&&pos.y()>=840&&pos.y()<=880){
        if(flag7){
            musicplayer->StopBgMusic();
            config->Set_Switch_BgMusic(0);
            QString string6="border-image:url(";
            QString string7=theme.picture_Element[15];
            string6.append(string7+")");
            ui->label_4->setStyleSheet(string6);
            flag7=false;
        }
        else{
            musicplayer->PlayBgMusic();
            config->Set_Switch_BgMusic(1);
            QString string6="border-image:url(";
            QString string7=theme.picture_Element[14];
            string6.append(string7+")");
            ui->label_4->setStyleSheet(string6);
            flag7=true;
        }
    }
    else if(pos.x()>=1080&&pos.x()<=1120&&pos.y()>=840&&pos.y()<=880){
        if(flag8){
            soundplay=0;
            config->Set_Switch_Sound(0);
            QString string6="border-image:url(";
            QString string7=theme.picture_Element[17];
            string6.append(string7+")");
            ui->label_6->setStyleSheet(string6);
            flag8=false;
        }
        else{
            soundplay=1;
            config->Set_Switch_Sound(1);
            QString string6="border-image:url(";
            QString string7=theme.picture_Element[16];
            string6.append(string7+")");
            ui->label_6->setStyleSheet(string6);
            flag8=true;
        }

    }
    else if(pos.x()>=1030&&pos.x()<=1080&&pos.y()>=610&&pos.y()<=660){
        if(score>=50){
            score=score-50;
            solution=logic->getHint();
            pic1=solution.picture1;
            pic2=solution.picture2;
            showPic[pic1.nRow][pic1.nCol]=1;
            showPic[pic2.nRow][pic2.nCol]=1;
            repaint();
        }
    }
    else if(pos.x()>=1030&&pos.x()<=1080&&pos.y()>=680&&pos.y()<=730){
        if(flag9){
            timer->stop();
            label=new QLabel();
            label->setGeometry(0,0,750,750);
            label->setParent(this);
            QString string="border-image:url(";
            QString string1=theme.picture_Element[10];
            string.append(string1+")");
            label->setStyleSheet(string);
            label->show();
            QString string6="border-image:url(";
            QString string7=theme.picture_Element[19];
            string6.append(string7+")");
            ui->label_9->setStyleSheet(string6);
            flag9=false;
        }else{
            QString string6="border-image:url(";
            QString string7=theme.picture_Element[20];
            string6.append(string7+")");
            ui->label_9->setStyleSheet(string6);
            flag8=false;
            timer->start(1000);
            label->hide();
            flag9=true;
        }
    }
    else if(pos.x()>=1030&&pos.x()<=1080&&pos.y()>=750&&pos.y()<=800){
        CBejeweledDlg* bejeweled=new CBejeweledDlg();
        bejeweled->show();
        //stop->close();
        this->musicplayer->StopBgMusic();
        this->close();
    }
    else{
        //qDebug()<<x<<" "<<y;
        if(x>=0&&x<dimension&&y>=0&&y<dimension){
            if(flag4){
                this->setMouseTracking(false);
                label1->hide();
                PICELEM pic;
                pic.nRow=x;
                pic.nCol=y;
                pic.nPicNum=photo[x][y];
                set<PICELEM> elimite;
                elimite.insert(pic);
                setDelete(elimite);
            }
            else if(flag5){
                this->setMouseTracking(false);
                label1->hide();
                set<PICELEM> elimite;
                for(int i=0;i<dimension;i++){
                    PICELEM pic;
                    pic.nRow=x;
                    pic.nCol=i;
                    pic.nPicNum=photo[x][i];
                    elimite.insert(pic);
                }
                setDelete(elimite);
            }
            else if(flag6){
                this->setMouseTracking(false);
                label1->hide();
                set<PICELEM> elimite;
                for(int i=0;i<dimension;i++){
                    PICELEM pic;
                    pic.nRow=i;
                    pic.nCol=y;
                    pic.nPicNum=photo[i][y];
                    elimite.insert(pic);
                }
                setDelete(elimite);
            }
            else{
                //qDebug()<<"normal";
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
                    //qDebug()<<"aaa";
                    bool flag=logic->isAdjacent(p1,p2);
                    //qDebug()<<flag;
                    if(flag){
                        elimite=logic->canSwop();
                        //qDebug()<<elimite.size();
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
                                msleep(100);
                                score=score+time*5;
                                if(soundplay==1){
                                    musicplayer->StopBgMusic();
                                }
                                //qDebug()<<11;
                                qDebug()<<"difficulty"+QString::number(difficulty)+"dimension"+QString::number(dimension);
                                //qDebug()<<22;
                                CStop* nextStage=new CStop(1,dimension,difficulty);
                                if(!nextStage->isVisible())
                                {

                                    nextStage->show();
                                    //qDebug()<<"---"<<nextStage->isVisible();
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
                    //qDebug()<<22;


                    //qDebug()<<"---"<<this->nextStage->isVisible();

                    //qDebug()<<33;
                    //this->close();
                    //qDebug()<<44;
                }
            }
        }
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
    //qDebug()<<"aaa";
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
        //qDebug()<<number[i];
        for(int j=0;j<dimension;j++){
            if(lay[j][i]==0){
                continue;
            }else{
                first[i]=j;
                //qDebug()<<first[i];
                break;
            }
        }
    }
    if(flag4){
        PICELEM pi;
        for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
             pi=*it;
        }
        PICELEM p=logic->eliminateOne(pi);
        pic.append(p);
        flag4=false;
    }
    else if(flag5){
        int x=0;
        for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
             x=(*it).nRow;
             break;
        }
        elimite=logic->eliminateRow(x);
        for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
             pic.append(*it);
        }
        flag5=false;
    }
    else if(flag6){
        int y=0;
        for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
             y=(*it).nCol;
             break;
        }
        elimite=logic->eliminateCol(y);
        for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
             pic.append(*it);
        }
        flag6=false;
    }
    else{
        elimite=logic->fall();
        for(set<PICELEM>::iterator it=elimite.begin();it!=elimite.end();it++){
            pic.append(*it);
        }
    }
    for(int i=0;i<dimension;i++){
        if(number[i]!=0){
            for(int k=0,l=first[i]+number[i]-1;k<number[i];k++,l--){
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
            //qDebug()<<"gg";
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

void CGameDlg::mouseMoveEvent(QMouseEvent *ev){
    //QPoint p=ev->pos();
    //qDebug()<<"a"<<p;
    if(flag4){
        label1->setGeometry(ev->pos().x(),ev->pos().y(),50,50);
        label1->show();
    }
    if(flag5){
        label1->setGeometry(ev->pos().x(),ev->pos().y(),91,50);
        label1->show();
    }
    if(flag6){
        label1->setGeometry(ev->pos().x(),ev->pos().y(),50,91);
        label1->show();
    }
}

CGameDlg::~CGameDlg()
{
    delete ui;
}

void CGameDlg::on_pushButton_2_clicked()
{
    if(tool1>=1){
        ui->pushButton_2->setText("可使用数量："+QString::number(tool1));
        //label1->setGeometry(0,0,35,35);
        label1->setParent(this);
        QString string="border-image:url(";
        QString string1=theme.picture_Element[11];
        string.append(string1+")");
        label1->setStyleSheet(string);
        flag4=true;
        this->setMouseTracking(true);
    }
    tool1--;
    if(tool1==0){
        ui->pushButton_2->setEnabled(false);
    }
    ui->pushButton_2->setText("可使用数量："+QString::number(tool1));
}

void CGameDlg::on_pushButton_4_clicked()
{
    if(tool2>=1){
        ui->pushButton_4->setText("可使用数量："+QString::number(tool2));
        //label1->setGeometry(0,0,35,35);
        label1->setParent(this);
        QString string="border-image:url(";
        QString string1=theme.picture_Element[12];
        string.append(string1+")");
        label1->setStyleSheet(string);
        flag5=true;
        this->setMouseTracking(true);
    }
    tool2--;
    if(tool2==0){
        ui->pushButton_4->setEnabled(false);
    }
    ui->pushButton_4->setText("可使用数量："+QString::number(tool2));
}

void CGameDlg::on_pushButton_5_clicked()
{
    if(tool3>=1){
        ui->pushButton_5->setText("可使用数量："+QString::number(tool3));
        //label1->setGeometry(0,0,35,35);
        label1->setParent(this);
        QString string="border-image:url(";
        QString string1=theme.picture_Element[13];
        string.append(string1+")");
        label1->setStyleSheet(string);
        flag6=true;
        this->setMouseTracking(true);
    }
    tool3--;
    if(tool3==0){
        ui->pushButton_5->setEnabled(false);
    }
    ui->pushButton_5->setText("可使用数量："+QString::number(tool3));
}
