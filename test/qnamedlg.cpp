#include "qnamedlg.h"
#include "ui_qnamedlg.h"

QNameDlg::QNameDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QNameDlg)
{
    ui->setupUi(this);
    logic=CRankLogic::getInstance();
}

QNameDlg::~QNameDlg()
{
    delete ui;
}

void QNameDlg::on_pushButton_clicked()
{
    //int result=logic->loginCheck(this->ui->lineEdit->text(),this->ui->lineEdit_2->text());
    int result=logic->loginCheck(this->ui->lineEdit->text(),this->ui->lineEdit_2->text());
    switch (result) {
    case -1:
        QMessageBox::information(this,tr("用户名不存在"),tr("用户名不存在!"));
        break;
    case 0:
        QMessageBox::information(this,tr("密码错误"),tr("密码错误!"));
        break;
    case 1:
        QString s="欢迎！"+this->ui->lineEdit->text();
        QMessageBox::information(this,tr("登录成功"),tr(s.toStdString().c_str()));
        this->hide();
        break;

    }
}
