#include "csetdlg.h"
#include "ui_csetdlg.h"
#include <QFileDialog>
#include <QLineEdit>
#include <cconfiglogic.h>
#include <QPainter>
#include <QPalette>

CSetDlg::CSetDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSetDlg)
{
    ui->setupUi(this);
    setFixedSize(580,480);
    //默认状态自定义音乐组件不可用
    ui->lineEdit->setDisabled(true);
    ui->pushButton_3->setDisabled(true);

    //绘图变量：是否绘出主题按钮
    paintButton=0;

    //主题选择
    //默认状态主题选择不可用
    ui->theme1SelectBtn->setDisabled(true);
    ui->theme2SelectBtn->setDisabled(true);
    ui->theme3SelectBtn->setDisabled(true);

    ui->tabWidget->setStyleSheet("QTabWidget:pane{border: 1px solid black; top: -1px;background: transparent;}QTabBar::tab{height:50px; margin-right: 2px; margin-bottom:-2px;}");
}

CSetDlg::~CSetDlg()
{
    delete ui;
}

void CSetDlg::on_pushButton_3_clicked()//浏览文件选择自定义音乐
{
    QString openFileName = QFileDialog::getOpenFileName(this,"Open File",".","music(*.mp3 *.wav *.flac *.m4a)");
    ui->lineEdit->setText(openFileName);
    settings.musicfilepath = openFileName;
}

void CSetDlg::on_radioButton_clicked()//默认音乐按钮
{
    ui->lineEdit->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
}

void CSetDlg::on_radioButton_2_clicked()//自定义音乐按钮
{
    ui->lineEdit->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
}

void CSetDlg::on_radioButton_3_clicked()//默认主题按钮
{
    ui->theme1SelectBtn->setDisabled(true);
    ui->theme2SelectBtn->setDisabled(true);
    ui->theme3SelectBtn->setDisabled(true);
}

void CSetDlg::on_radioButton_4_clicked()//自定义主题按钮
{
    ui->theme1SelectBtn->setEnabled(true);
    ui->theme2SelectBtn->setEnabled(true);
    ui->theme3SelectBtn->setEnabled(true);
}

void CSetDlg::on_pushButton_2_clicked()//“取消”按钮
{
    this->close();
}

int CSetDlg::getTheme()
{
    if(ui->theme1SelectBtn->isChecked()){
        return 1;
    }
    if(ui->theme2SelectBtn->isChecked()){
        return 2;
    }
    if(ui->theme3SelectBtn->isChecked()){
        return 3;
    }
    else{
        return 1;
    }
}

void CSetDlg::on_pushButton_clicked()//“确定”按钮
{
    CConfigLogic* config = new CConfigLogic();
    //更改主题
    settings.themeselect = getTheme();
    config->changeTheme(settings.themeselect-1);
    //背景音乐开关
    if(ui->checkBox->isChecked()){
        config->setBgMusicSwitch(1);
    }else{
        config->setBgMusicSwitch(0);
    }
    //音效开关
    if(ui->checkBox_2->isChecked()){
        config->setSoundSwitch(1);
    }else{
        config->setSoundSwitch(0);
    }
    //背景音乐自定义
    if(ui->radioButton->isChecked()){
        config->setBgMusicType(0);
    }else if(ui->radioButton_2->isChecked()){
        config->setBgMusicType(1);
        config->setUserDefinedBgMusic(settings.musicfilepath);
    }

    this->close();
}

void CSetDlg::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    pix.load(":/img/settingWindowBg(5).png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    QPixmap button;
    button.load(":/img/Button.png");

    if(paintButton==1){
        painter.drawPixmap(ui->theme1SelectBtn->pos().x()+30,ui->theme1SelectBtn->pos().y()+170,ui->theme1SelectBtn->width()+15,ui->theme1SelectBtn->height(),button);
        painter.drawPixmap(ui->theme2SelectBtn->pos().x()+30,ui->theme2SelectBtn->pos().y()+170,ui->theme2SelectBtn->width()+15,ui->theme2SelectBtn->height(),button);
        painter.drawPixmap(ui->theme3SelectBtn->pos().x()+30,ui->theme3SelectBtn->pos().y()+170,ui->theme3SelectBtn->width()+15,ui->theme3SelectBtn->height(),button);
    }
}


void CSetDlg::on_tabWidget_tabBarClicked(int index)
{
    if(index==1){
        paintButton=1;
    }else if(index==0){
        paintButton=0;
    }
}
