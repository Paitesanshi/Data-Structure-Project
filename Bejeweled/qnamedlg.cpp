#include "qnamedlg.h"
#include "ui_qnamedlg.h"

QNameDlg::QNameDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QNameDlg)
{
    ui->setupUi(this);
}

QNameDlg::~QNameDlg()
{
    delete ui;
}
