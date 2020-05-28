/********************************************************************************
** Form generated from reading UI file 'cgamedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGAMEDLG_H
#define UI_CGAMEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGameDlg
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CGameDlg)
    {
        if (CGameDlg->objectName().isEmpty())
            CGameDlg->setObjectName(QStringLiteral("CGameDlg"));
        CGameDlg->resize(800, 600);
        centralwidget = new QWidget(CGameDlg);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        CGameDlg->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CGameDlg);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        CGameDlg->setMenuBar(menubar);
        statusbar = new QStatusBar(CGameDlg);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CGameDlg->setStatusBar(statusbar);

        retranslateUi(CGameDlg);

        QMetaObject::connectSlotsByName(CGameDlg);
    } // setupUi

    void retranslateUi(QMainWindow *CGameDlg)
    {
        CGameDlg->setWindowTitle(QApplication::translate("CGameDlg", "CGameDlg", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CGameDlg: public Ui_CGameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGAMEDLG_H
