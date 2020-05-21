#include "csetdlg.h"
#include "ui_csetdlg.h"
#include <QFileDialog>
#include <QLineEdit>

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
    QString openFileName = QFileDialog::getOpenFileName(this,"Open File");
    ui->lineEdit->setText(openFileName);
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
