#ifndef CJEWEL_H
#define CJEWEL_H
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QMainWindow>
#include <QMessageBox>
#include <qdebug.h>
//#include <cgamedlg.h>

class CJewel : public QLabel
{
    Q_OBJECT
public:
    QString* filename;
    QPixmap* pixmap;
    QTimer* timer;
    QImage* img;
    QMainWindow* ui;
    bool flag;
    int col;//行
    int row;//列
    int targetx;
    int targety;
    int number;//图片编号
    CJewel(QMainWindow* ui,QWidget* parent);
    void setPhoto();
protected:
    //void mousePressEvent(QMouseEvent *ev) override;
private slots:
    void timerTimeOutl();
    void timerTimeOutr();
    void timerTimeOutu();
    void timerTimeOutd();

};

#endif // CJEWEL_H
