/********************************************************************************
** Form generated from reading UI file 'cgamedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGameDlg
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CGameDlg)
    {
        if (CGameDlg->objectName().isEmpty())
            CGameDlg->setObjectName(QStringLiteral("CGameDlg"));
        CGameDlg->resize(800, 600);
        centralwidget = new QWidget(CGameDlg);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(650, 430, 75, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 320, 111, 111));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(20);
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 430, 75, 51));
        CGameDlg->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CGameDlg);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        pushButton->setText(QApplication::translate("CGameDlg", "\346\217\220\347\244\272", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CGameDlg", "\350\217\234\345\215\225", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("CGameDlg", "\346\232\202\345\201\234", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CGameDlg: public Ui_CGameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGAMEDLG_H
