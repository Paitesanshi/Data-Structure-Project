#ifndef CBEJEWELEDDLG_H
#define CBEJEWELEDDLG_H

#include <QMainWindow>
#include <qsetupdlg.h>
#include <qnamedlg.h>
#include <cgamedlg.h>

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
    CBejeweledDlg(QWidget *parent = nullptr);
    ~CBejeweledDlg();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::CBejeweledDlg *ui;
};

#endif // CBEJEWELEDDLG_H
