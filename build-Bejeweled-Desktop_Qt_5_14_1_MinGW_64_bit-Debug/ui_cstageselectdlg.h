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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CStageSelectDlg
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_9;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CStageSelectDlg)
    {
        if (CStageSelectDlg->objectName().isEmpty())
            CStageSelectDlg->setObjectName(QString::fromUtf8("CStageSelectDlg"));
        CStageSelectDlg->resize(502, 525);
        centralwidget = new QWidget(CStageSelectDlg);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 400, 161, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("AcadEref"));
        font.setPointSize(18);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 440, 61, 31));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(160, 50, 89, 16));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(160, 80, 89, 16));
        radioButton_3 = new QRadioButton(centralwidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(160, 110, 89, 16));
        radioButton_4 = new QRadioButton(centralwidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(160, 140, 89, 16));
        radioButton_5 = new QRadioButton(centralwidget);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(160, 170, 89, 16));
        radioButton_6 = new QRadioButton(centralwidget);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(160, 200, 89, 16));
        radioButton_7 = new QRadioButton(centralwidget);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));
        radioButton_7->setGeometry(QRect(160, 230, 89, 16));
        radioButton_8 = new QRadioButton(centralwidget);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));
        radioButton_8->setGeometry(QRect(160, 260, 89, 16));
        radioButton_9 = new QRadioButton(centralwidget);
        radioButton_9->setObjectName(QString::fromUtf8("radioButton_9"));
        radioButton_9->setGeometry(QRect(160, 290, 89, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 113, 20));
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        CStageSelectDlg->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CStageSelectDlg);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 502, 22));
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
        pushButton->setText(QCoreApplication::translate("CStageSelectDlg", "\350\277\233\345\205\245\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CStageSelectDlg", "\350\277\224\345\233\236", nullptr));
        radioButton->setText(QCoreApplication::translate("CStageSelectDlg", "\347\254\254\344\270\200\345\205\263", nullptr));
        radioButton_2->setText(QCoreApplication::translate("CStageSelectDlg", "\347\254\254\344\272\214\345\205\263", nullptr));
        radioButton_3->setText(QCoreApplication::translate("CStageSelectDlg", "\347\254\254\344\270\211\345\205\263", nullptr));
        radioButton_4->setText(QCoreApplication::translate("CStageSelectDlg", "\347\254\254\345\233\233\345\205\263", nullptr));
        radioButton_5->setText(QCoreApplication::translate("CStageSelectDlg", "\347\254\254\344\272\224\345\205\263", nullptr));
        radioButton_6->setText(QCoreApplication::translate("CStageSelectDlg", "\347\254\254\345\205\255\345\205\263", nullptr));
        radioButton_7->setText(QCoreApplication::translate("CStageSelectDlg", "\347\254\254\344\270\203\345\205\263", nullptr));
        radioButton_8->setText(QCoreApplication::translate("CStageSelectDlg", "\347\254\254\345\205\253\345\205\263", nullptr));
        radioButton_9->setText(QCoreApplication::translate("CStageSelectDlg", "\347\254\254\344\271\235\345\205\263", nullptr));
        lineEdit->setText(QCoreApplication::translate("CStageSelectDlg", "\345\205\263\345\215\241\351\200\211\346\213\251\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CStageSelectDlg: public Ui_CStageSelectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSTAGESELECTDLG_H
