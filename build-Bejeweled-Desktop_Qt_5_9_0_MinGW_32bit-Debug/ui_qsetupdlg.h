/********************************************************************************
** Form generated from reading UI file 'qsetupdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSETUPDLG_H
#define UI_QSETUPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QSetupDlg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;

    void setupUi(QDialog *QSetupDlg)
    {
        if (QSetupDlg->objectName().isEmpty())
            QSetupDlg->setObjectName(QStringLiteral("QSetupDlg"));
        QSetupDlg->resize(400, 300);
        label = new QLabel(QSetupDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(95, 80, 51, 16));
        label_2 = new QLabel(QSetupDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 110, 41, 16));
        label_3 = new QLabel(QSetupDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 150, 68, 15));
        lineEdit = new QLineEdit(QSetupDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 70, 161, 21));
        lineEdit_2 = new QLineEdit(QSetupDlg);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 110, 161, 21));
        lineEdit_3 = new QLineEdit(QSetupDlg);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 150, 161, 21));
        pushButton = new QPushButton(QSetupDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 220, 93, 28));

        retranslateUi(QSetupDlg);

        QMetaObject::connectSlotsByName(QSetupDlg);
    } // setupUi

    void retranslateUi(QDialog *QSetupDlg)
    {
        QSetupDlg->setWindowTitle(QApplication::translate("QSetupDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("QSetupDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("QSetupDlg", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("QSetupDlg", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QSetupDlg", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QSetupDlg: public Ui_QSetupDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSETUPDLG_H
