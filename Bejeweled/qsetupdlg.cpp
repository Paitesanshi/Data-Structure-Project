#include "qsetupdlg.h"
#include "ui_qsetupdlg.h"

QSetupDlg::QSetupDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QSetupDlg)
{
    ui->setupUi(this);
    logic=new CRankLogic();
}

QSetupDlg::~QSetupDlg()
{
    delete ui;
}

void QSetupDlg::on_pushButton_clicked()
{
    if(this->ui->lineEdit_2->text()!=this->ui->lineEdit_3->text())
    {
        QMessageBox::information(this,tr("两次输入密码不一致"),tr("两次输入密码不一致!"));
        return;
    }
    if(logic->userRegister(this->ui->lineEdit->text(),this->ui->lineEdit_2->text()))
    {
        QMessageBox::information(this,tr("注册成功！"),tr("注册成功!"));
        this->hide();
    }
    else
    {
        QMessageBox::information(this,tr("用户名已存在！"),tr("用户名已存在!"));
    }
    return;
}
