/********************************************************************************
** Form generated from reading UI file 'cbejeweleddlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBEJEWELEDDLG_H
#define UI_CBEJEWELEDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CBejeweledDlg
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CBejeweledDlg)
    {
        if (CBejeweledDlg->objectName().isEmpty())
            CBejeweledDlg->setObjectName(QString::fromUtf8("CBejeweledDlg"));
        CBejeweledDlg->resize(800, 600);
        centralwidget = new QWidget(CBejeweledDlg);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 160, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 300, 93, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 210, 93, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(470, 210, 93, 28));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(340, 450, 91, 31));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(470, 300, 91, 31));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(470, 390, 91, 31));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(220, 390, 91, 31));
        CBejeweledDlg->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CBejeweledDlg);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        CBejeweledDlg->setMenuBar(menubar);
        statusbar = new QStatusBar(CBejeweledDlg);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CBejeweledDlg->setStatusBar(statusbar);

        retranslateUi(CBejeweledDlg);

        QMetaObject::connectSlotsByName(CBejeweledDlg);
    } // setupUi

    void retranslateUi(QMainWindow *CBejeweledDlg)
    {
        CBejeweledDlg->setWindowTitle(QCoreApplication::translate("CBejeweledDlg", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("CBejeweledDlg", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CBejeweledDlg", "\345\270\256\345\212\251", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CBejeweledDlg", "\347\231\273\345\275\225", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CBejeweledDlg", "\346\263\250\345\206\214", nullptr));
        pushButton_5->setText(QCoreApplication::translate("CBejeweledDlg", "\351\200\200\345\207\272", nullptr));
        pushButton_6->setText(QCoreApplication::translate("CBejeweledDlg", "\346\216\222\350\241\214\346\246\234", nullptr));
        pushButton_7->setText(QCoreApplication::translate("CBejeweledDlg", "\350\217\234\345\215\225", nullptr));
        pushButton_8->setText(QCoreApplication::translate("CBejeweledDlg", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CBejeweledDlg: public Ui_CBejeweledDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBEJEWELEDDLG_H
