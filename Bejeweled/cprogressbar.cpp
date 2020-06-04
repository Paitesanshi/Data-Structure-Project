#include "cprogressbar.h"
#include <QPainter>

CProgressBar::CProgressBar(QWidget *parent) : QProgressBar(parent)
{
    setMinimum(0);
    setMaximum(100);
    setValue(0);
}

void CProgressBar::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QRect rect = QRect(0, 0, width(), height()/2);
    QRect textRect = QRect(0, height()/2, width(), height()/2);

    const double k = (double)(value() - minimum()) / (maximum()-minimum());
    int x = (int)(rect.width() * k);
    QRect fillRect = rect.adjusted(0, 0, x-rect.width(), 0);

    QString valueStr = (QString::number(value())+"秒");
    QPixmap buttomMap = QPixmap("./img/4/1.png");
    QPixmap fillMap = QPixmap("./img/4/2.png");

    //画进度条
    p.drawPixmap(rect, buttomMap);
    p.drawPixmap(fillRect, fillMap);

    //画文字
    QFont f = QFont("Microsoft YaHei", 15, QFont::Bold);
    p.setFont(f);
    p.setPen(QColor("#555555"));
    p.drawText(textRect, Qt::AlignCenter, valueStr);
}
