#ifndef CMENUDLG_H
#define CMENUDLG_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>

class CMenuDlg : public QWidget
{
public:
    CMenuDlg(int difficulty,int dimension,QMainWindow *parent = 0);
};

#endif // CMENUDLG_H
