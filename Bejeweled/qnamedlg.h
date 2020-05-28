#ifndef QNAMEDLG_H
#define QNAMEDLG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QNameDlg; }
QT_END_NAMESPACE

class QNameDlg : public QDialog
{
    Q_OBJECT

public:
    QNameDlg(QWidget *parent = nullptr);
    ~QNameDlg();

private:
    Ui::QNameDlg *ui;
};

#endif // QNAMEDLG_H
