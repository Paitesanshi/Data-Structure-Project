/********************************************************************************
** Form generated from reading UI file 'qnamedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNAMEDLG_H
#define UI_QNAMEDLG_H

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

class Ui_QNameDlg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *QNameDlg)
    {
        if (QNameDlg->objectName().isEmpty())
            QNameDlg->setObjectName(QStringLiteral("QNameDlg"));
        QNameDlg->resize(400, 300);
        label = new QLabel(QNameDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 68, 15));
        label_2 = new QLabel(QNameDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 110, 68, 15));
        lineEdit = new QLineEdit(QNameDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 70, 171, 21));
        lineEdit_2 = new QLineEdit(QNameDlg);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 110, 171, 21));
        pushButton = new QPushButton(QNameDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 210, 93, 28));

        retranslateUi(QNameDlg);

        QMetaObject::connectSlotsByName(QNameDlg);
    } // setupUi

    void retranslateUi(QDialog *QNameDlg)
    {
        QNameDlg->setWindowTitle(QApplication::translate("QNameDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("QNameDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("QNameDlg", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QNameDlg", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QNameDlg: public Ui_QNameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNAMEDLG_H
