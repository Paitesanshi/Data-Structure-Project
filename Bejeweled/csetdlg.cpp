#include "csetdlg.h"
#include "ui_csetdlg.h"
#include <QFileDialog>
#include <QLineEdit>
#include <cconfiglogic.h>

CSetDlg::CSetDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSetDlg)
{
    ui->setupUi(this);
    setFixedSize(580,480);
    //默认状态自定义音乐组件不可用
    ui->lineEdit->setDisabled(true);
    ui->pushButton_3->setDisabled(true);

    //主题选择
    ui->comboBox->addItem("1");
    ui->comboBox->addItem("2");
    ui->comboBox->addItem("3");
    ui->comboBox->setDisabled(true);
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
    ui->comboBox->setDisabled(true);
}

void CSetDlg::on_radioButton_4_clicked()//自定义主题按钮
{
    ui->comboBox->setEnabled(true);
}

void CSetDlg::on_pushButton_2_clicked()//“取消”按钮
{
    this->close();
}

void CSetDlg::on_pushButton_clicked()//“确定”按钮
{
    CConfigLogic* config = new CConfigLogic();
    //更改主题
    bool ok;
    settings.themeselect = ui->comboBox->currentText().toInt(&ok,10);
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



