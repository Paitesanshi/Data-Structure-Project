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
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

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
        label_2 = new QLabel(CGameDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(930, 110, 201, 61));
        label_2->setFont(font);
        label_3 = new QLabel(CGameDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1030, 200, 50, 50));
        label_5 = new QLabel(CGameDlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1000, 320, 110, 60));
        label_7 = new QLabel(CGameDlg);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1020, 440, 70, 110));
        pushButton_2 = new QPushButton(CGameDlg);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1000, 270, 110, 28));
        pushButton_4 = new QPushButton(CGameDlg);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1000, 400, 110, 28));
        pushButton_5 = new QPushButton(CGameDlg);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(1000, 570, 110, 28));
        label_4 = new QLabel(CGameDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1020, 840, 40, 40));
        label_6 = new QLabel(CGameDlg);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1080, 840, 40, 40));
        label_8 = new QLabel(CGameDlg);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1030, 610, 50, 50));
        label_9 = new QLabel(CGameDlg);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1030, 680, 50, 50));
        label_10 = new QLabel(CGameDlg);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(1030, 750, 50, 50));

        retranslateUi(CGameDlg);

        QMetaObject::connectSlotsByName(CGameDlg);
    } // setupUi

    void retranslateUi(QWidget *CGameDlg)
    {
        CGameDlg->setWindowTitle(QCoreApplication::translate("CGameDlg", "Form", nullptr));
        label->setText(QCoreApplication::translate("CGameDlg", "\345\210\206\346\225\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("CGameDlg", "\347\233\256\346\240\207\357\274\232", nullptr));
        label_3->setText(QString());
        label_5->setText(QString());
        label_7->setText(QString());
        pushButton_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        label_4->setText(QString());
        label_6->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CGameDlg: public Ui_CGameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGAMEDLG_H
