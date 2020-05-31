#ifndef CBEJEWELEDDLG_H
#define CBEJEWELEDDLG_H

#include <QMainWindow>
#include <qsetupdlg.h>
#include <qnamedlg.h>
#include <cgamedlg.h>

#include <chelpdlg.h>
#include <crankdlg.h>
#include <cmenudlg.h>
#include <csetdlg.h>
#include <cstageselectdlg.h>


QT_BEGIN_NAMESPACE
namespace Ui { class CBejeweledDlg; }
QT_END_NAMESPACE

class CBejeweledDlg : public QMainWindow
{
    Q_OBJECT

public:
    //保存用户信息 应该是注册时将用户信息写到文件中去，登陆时从文件中匹配信息
    QString userName;
    QString password;
    //
    QSetupDlg* setup;
    QNameDlg* name;
    CHelpDlg* cHelp;
    CRankDlg* cRank;
    CMenuDlg* cMenu;
    CSetDlg* cSet;
    CBejeweledDlg(QWidget *parent = nullptr);
    ~CBejeweledDlg();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();


private:
    Ui::CBejeweledDlg *ui;
    CRankLogic *logic;
};

#endif // CBEJEWELEDDLG_H
