/********************************************************************************
** Form generated from reading UI file 'cstop.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSTOP_H
#define UI_CSTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CStop
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *CStop)
    {
        if (CStop->objectName().isEmpty())
            CStop->setObjectName(QString::fromUtf8("CStop"));
        CStop->resize(400, 300);
        label = new QLabel(CStop);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 50, 231, 16));
        pushButton = new QPushButton(CStop);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 120, 93, 28));
        pushButton_2 = new QPushButton(CStop);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 180, 93, 28));
        pushButton_3 = new QPushButton(CStop);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 240, 93, 28));

        retranslateUi(CStop);

        QMetaObject::connectSlotsByName(CStop);
    } // setupUi

    void retranslateUi(QWidget *CStop)
    {
        CStop->setWindowTitle(QCoreApplication::translate("CStop", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("CStop", "\344\270\213\344\270\200\345\205\263", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CStop", "\351\207\215\347\216\251\346\234\254\345\205\263", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CStop", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CStop: public Ui_CStop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSTOP_H
