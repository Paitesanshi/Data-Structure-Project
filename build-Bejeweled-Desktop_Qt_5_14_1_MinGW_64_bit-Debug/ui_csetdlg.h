/********************************************************************************
** Form generated from reading UI file 'csetdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSETDLG_H
#define UI_CSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSetDlg
{
public:
    QTabWidget *tabWidget;
    QWidget *sound;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QWidget *theme;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QRadioButton *theme1SelectBtn;
    QRadioButton *theme2SelectBtn;
    QRadioButton *theme3SelectBtn;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *CSetDlg)
    {
        if (CSetDlg->objectName().isEmpty())
            CSetDlg->setObjectName(QString::fromUtf8("CSetDlg"));
        CSetDlg->resize(590, 428);
        tabWidget = new QTabWidget(CSetDlg);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 541, 351));
        sound = new QWidget();
        sound->setObjectName(QString::fromUtf8("sound"));
        groupBox = new QGroupBox(sound);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 501, 81));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(90, 30, 101, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("AcadEref"));
        font.setPointSize(11);
        checkBox->setFont(font);
        checkBox->setChecked(true);
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(320, 30, 91, 21));
        checkBox_2->setFont(font);
        checkBox_2->setChecked(true);
        groupBox_2 = new QGroupBox(sound);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 120, 501, 191));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(90, 40, 89, 16));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(320, 40, 89, 16));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(80, 110, 241, 20));
        lineEdit->setReadOnly(true);
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(true);
        pushButton_3->setGeometry(QRect(340, 110, 75, 23));
        tabWidget->addTab(sound, QString());
        theme = new QWidget();
        theme->setObjectName(QString::fromUtf8("theme"));
        radioButton_3 = new QRadioButton(theme);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(90, 70, 81, 16));
        radioButton_3->setFont(font);
        radioButton_3->setChecked(true);
        radioButton_4 = new QRadioButton(theme);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(320, 70, 89, 16));
        radioButton_4->setFont(font);
        groupBox_3 = new QGroupBox(theme);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 110, 501, 191));
        theme1SelectBtn = new QRadioButton(groupBox_3);
        theme1SelectBtn->setObjectName(QString::fromUtf8("theme1SelectBtn"));
        theme1SelectBtn->setGeometry(QRect(30, 30, 101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AcadEref"));
        font1.setPointSize(14);
        theme1SelectBtn->setFont(font1);
        theme2SelectBtn = new QRadioButton(groupBox_3);
        theme2SelectBtn->setObjectName(QString::fromUtf8("theme2SelectBtn"));
        theme2SelectBtn->setGeometry(QRect(190, 30, 101, 41));
        theme2SelectBtn->setFont(font1);
        theme3SelectBtn = new QRadioButton(groupBox_3);
        theme3SelectBtn->setObjectName(QString::fromUtf8("theme3SelectBtn"));
        theme3SelectBtn->setGeometry(QRect(360, 30, 101, 41));
        theme3SelectBtn->setFont(font1);
        tabWidget->addTab(theme, QString());
        pushButton = new QPushButton(CSetDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 370, 131, 41));
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(CSetDlg);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 370, 131, 41));
        pushButton_2->setFont(font1);

        retranslateUi(CSetDlg);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CSetDlg);
    } // setupUi

    void retranslateUi(QWidget *CSetDlg)
    {
        CSetDlg->setWindowTitle(QCoreApplication::translate("CSetDlg", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CSetDlg", "\351\237\263\346\225\210\350\256\276\347\275\256", nullptr));
        checkBox->setText(QCoreApplication::translate("CSetDlg", "\350\203\214\346\231\257\351\237\263\344\271\220", nullptr));
        checkBox_2->setText(QCoreApplication::translate("CSetDlg", "\351\237\263\346\225\210", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CSetDlg", "\350\203\214\346\231\257\351\237\263\344\271\220\350\256\276\347\275\256", nullptr));
        radioButton->setText(QCoreApplication::translate("CSetDlg", "\351\273\230\350\256\244", nullptr));
        radioButton_2->setText(QCoreApplication::translate("CSetDlg", "\350\207\252\345\256\232\344\271\211", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CSetDlg", "\346\265\217\350\247\210", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sound), QCoreApplication::translate("CSetDlg", "\351\237\263\346\225\210\350\256\276\347\275\256", nullptr));
        radioButton_3->setText(QCoreApplication::translate("CSetDlg", "\351\273\230\350\256\244", nullptr));
        radioButton_4->setText(QCoreApplication::translate("CSetDlg", "\350\207\252\345\256\232\344\271\211", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("CSetDlg", "\344\270\273\351\242\230\351\200\211\346\213\251", nullptr));
        theme1SelectBtn->setText(QCoreApplication::translate("CSetDlg", "\345\256\235\347\237\263\350\277\267\351\230\265", nullptr));
        theme2SelectBtn->setText(QCoreApplication::translate("CSetDlg", "\345\212\250\347\211\251\344\270\226\347\225\214", nullptr));
        theme3SelectBtn->setText(QCoreApplication::translate("CSetDlg", "\346\260\264\346\236\234\344\271\220\345\233\255", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(theme), QCoreApplication::translate("CSetDlg", "\344\270\273\351\242\230\350\256\276\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("CSetDlg", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CSetDlg", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSetDlg: public Ui_CSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSETDLG_H
