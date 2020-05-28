#include "crankdlg.h"
#include "ui_crankdlg.h"

CRankDlg::CRankDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CRankDlg)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

CRankDlg::~CRankDlg()
{
    delete ui;
}
