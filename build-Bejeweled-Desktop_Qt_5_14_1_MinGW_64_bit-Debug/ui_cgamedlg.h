/********************************************************************************
** Form generated from reading UI file 'cgamedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGAMEDLG_H
#define UI_CGAMEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGameDlg
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QWidget *CGameDlg)
    {
        if (CGameDlg->objectName().isEmpty())
            CGameDlg->setObjectName(QString::fromUtf8("CGameDlg"));
        CGameDlg->resize(1200, 900);
        label = new QLabel(CGameDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(930, 40, 201, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        pushButton = new QPushButton(CGameDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1060, 610, 93, 28));
        pushButton_3 = new QPushButton(CGameDlg);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1060, 520, 93, 28));

        retranslateUi(CGameDlg);

        QMetaObject::connectSlotsByName(CGameDlg);
    } // setupUi

    void retranslateUi(QWidget *CGameDlg)
    {
        CGameDlg->setWindowTitle(QCoreApplication::translate("CGameDlg", "Form", nullptr));
        label->setText(QCoreApplication::translate("CGameDlg", "\345\210\206\346\225\260\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("CGameDlg", "STOP", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CGameDlg", "HINT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGameDlg: public Ui_CGameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGAMEDLG_H
