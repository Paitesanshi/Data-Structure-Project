/********************************************************************************
** Form generated from reading UI file 'cbejeweleddlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBEJEWELEDDLG_H
#define UI_CBEJEWELEDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CBejeweledDlg)
    {
        if (CBejeweledDlg->objectName().isEmpty())
            CBejeweledDlg->setObjectName(QStringLiteral("CBejeweledDlg"));
        CBejeweledDlg->resize(800, 600);
        centralwidget = new QWidget(CBejeweledDlg);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 160, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 370, 93, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 230, 93, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(340, 300, 93, 28));
        CBejeweledDlg->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CBejeweledDlg);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        CBejeweledDlg->setMenuBar(menubar);
        statusbar = new QStatusBar(CBejeweledDlg);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CBejeweledDlg->setStatusBar(statusbar);

        retranslateUi(CBejeweledDlg);

        QMetaObject::connectSlotsByName(CBejeweledDlg);
    } // setupUi

    void retranslateUi(QMainWindow *CBejeweledDlg)
    {
        CBejeweledDlg->setWindowTitle(QApplication::translate("CBejeweledDlg", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CBejeweledDlg", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CBejeweledDlg", "\345\270\256\345\212\251", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("CBejeweledDlg", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("CBejeweledDlg", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CBejeweledDlg: public Ui_CBejeweledDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBEJEWELEDDLG_H