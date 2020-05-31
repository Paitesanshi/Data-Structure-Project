#ifndef CSTAGESELECTDLG_H
#define CSTAGESELECTDLG_H

#include <QMainWindow>
#include <cgamedlg.h>

namespace Ui {
class CStageSelectDlg;
}

class CStageSelectDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CStageSelectDlg(QWidget *parent = nullptr);
    ~CStageSelectDlg();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CStageSelectDlg *ui;
};

#endif // CSTAGESELECTDLG_H
