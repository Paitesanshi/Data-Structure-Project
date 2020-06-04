#ifndef CPROGRESSBAR_H
#define CPROGRESSBAR_H

#include <QWidget>
#include <QProgressBar>

class CProgressBar:public QProgressBar
{
    Q_OBJECT
public:
    CProgressBar(QWidget *parent);
    void paintEvent(QPaintEvent *event) override;
};

#endif // CPROGRESSBAR_H
