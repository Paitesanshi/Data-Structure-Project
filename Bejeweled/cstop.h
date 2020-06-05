#ifndef CSTOP_H
#define CSTOP_H

#include <QWidget>
#include <cgamedlg.h>
#include <qdialog.h>
#include <qmessagebox.h>
#include <cbejeweleddlg.h>

namespace Ui {
class CStop;
}

class CStop:public QWidget
{
    Q_OBJECT
public:
    int dimension;
    int difficulty;
    CStop(int success,int dimension,int difficulty,QWidget *parent = nullptr);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CStop *ui;
};

#endif // CSTOP_H
