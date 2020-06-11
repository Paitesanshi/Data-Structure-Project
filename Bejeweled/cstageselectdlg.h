#ifndef CSTAGESELECTDLG_H
#define CSTAGESELECTDLG_H

#include <QMainWindow>
#include <cgamedlg.h>
#include <cranklogic.h>
#include <cbejeweleddlg.h>

namespace Ui {
class CStageSelectDlg;
}

class CStageSelectDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CStageSelectDlg(QWidget *parent = nullptr);
    ~CStageSelectDlg();
    int getButtonIndex();
    void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_9_clicked();

private:
    Ui::CStageSelectDlg *ui;
    CRankLogic *logic;
    int drawIndex = 1;
};

#endif // CSTAGESELECTDLG_H
