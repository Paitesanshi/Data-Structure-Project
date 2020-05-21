#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "cranklogic.h"
#include "cmenudlg.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //游戏菜单窗口
    CMenuDlg* CMenu = NULL;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
