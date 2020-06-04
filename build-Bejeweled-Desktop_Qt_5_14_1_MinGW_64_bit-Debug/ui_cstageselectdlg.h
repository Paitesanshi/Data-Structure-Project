/********************************************************************************
** Form generated from reading UI file 'cstageselectdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSTAGESELECTDLG_H
#define UI_CSTAGESELECTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CStageSelectDlg
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CStageSelectDlg)
    {
        if (CStageSelectDlg->objectName().isEmpty())
            CStageSelectDlg->setObjectName(QString::fromUtf8("CStageSelectDlg"));
        CStageSelectDlg->resize(462, 292);
        centralwidget = new QWidget(CStageSelectDlg);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(218, 60, 161, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 60, 81, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(154, 132, 161, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("AcadEref"));
        font.setPointSize(18);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 170, 61, 31));
        CStageSelectDlg->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CStageSelectDlg);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 462, 22));
        CStageSelectDlg->setMenuBar(menubar);
        statusbar = new QStatusBar(CStageSelectDlg);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CStageSelectDlg->setStatusBar(statusbar);

        retranslateUi(CStageSelectDlg);

        QMetaObject::connectSlotsByName(CStageSelectDlg);
    } // setupUi

    void retranslateUi(QMainWindow *CStageSelectDlg)
    {
        CStageSelectDlg->setWindowTitle(QCoreApplication::translate("CStageSelectDlg", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("CStageSelectDlg", "\345\205\263\345\215\241\351\200\211\346\213\251\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("CStageSelectDlg", "\350\277\233\345\205\245\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CStageSelectDlg", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CStageSelectDlg: public Ui_CStageSelectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSTAGESELECTDLG_H
