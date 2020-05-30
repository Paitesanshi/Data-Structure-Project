#ifndef CSETDLG_H
#define CSETDLG_H

#include <QWidget>

namespace Ui {
class CSetDlg;
}

class CSetDlg : public QWidget
{
    Q_OBJECT

public:
    explicit CSetDlg(QWidget *parent = nullptr);
    ~CSetDlg();


private slots:
    void on_pushButton_3_clicked();
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CSetDlg *ui;
};

#endif // CSETDLG_H

