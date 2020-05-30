#ifndef QNAMEDLG_H
#define QNAMEDLG_H

#include <QDialog>
#include <QMessageBox>
#include "cranklogic.h"
QT_BEGIN_NAMESPACE
namespace Ui { class QNameDlg; }
QT_END_NAMESPACE

class QNameDlg : public QDialog
{
    Q_OBJECT

public:
    QNameDlg(QWidget *parent = nullptr);
    ~QNameDlg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QNameDlg *ui;
    CRankLogic *logic;
};

#endif // QNAMEDLG_H
