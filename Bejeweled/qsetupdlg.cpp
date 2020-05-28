#include "qsetupdlg.h"
#include "ui_qsetupdlg.h"

QSetupDlg::QSetupDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QSetupDlg)
{
    ui->setupUi(this);
}

QSetupDlg::~QSetupDlg()
{
    delete ui;
}

void QSetupDlg::on_pushButton_clicked()
{

}
