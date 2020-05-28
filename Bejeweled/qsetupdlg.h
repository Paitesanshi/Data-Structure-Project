#ifndef QSETUPDLG_H
#define QSETUPDLG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QSetupDlg; }
QT_END_NAMESPACE

class QSetupDlg : public QDialog
{
    Q_OBJECT

public:
    QSetupDlg(QWidget *parent = nullptr);
    ~QSetupDlg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QSetupDlg *ui;
};
#endif // QSETUPDLG_H
