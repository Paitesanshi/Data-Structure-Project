/********************************************************************************
** Form generated from reading UI file 'csetdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSETDLG_H
#define UI_CSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *CSetDlg)
    {
        if (CSetDlg->objectName().isEmpty())
            CSetDlg->setObjectName(QStringLiteral("CSetDlg"));
        CSetDlg->resize(590, 428);
        tabWidget = new QTabWidget(CSetDlg);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 541, 351));
        sound = new QWidget();
        sound->setObjectName(QStringLiteral("sound"));
        groupBox = new QGroupBox(sound);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 501, 81));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(90, 30, 101, 21));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(11);
        checkBox->setFont(font);
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(320, 30, 91, 21));
        checkBox_2->setFont(font);
        groupBox_2 = new QGroupBox(sound);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 120, 501, 191));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(90, 40, 89, 16));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(320, 40, 89, 16));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(80, 110, 241, 20));
        lineEdit->setReadOnly(true);
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        pushButton_3->setGeometry(QRect(340, 110, 75, 23));
        tabWidget->addTab(sound, QString());
        theme = new QWidget();
        theme->setObjectName(QStringLiteral("theme"));
        radioButton_3 = new QRadioButton(theme);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(90, 70, 81, 16));
        radioButton_3->setFont(font);
        radioButton_3->setChecked(true);
        radioButton_4 = new QRadioButton(theme);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(320, 70, 89, 16));
        radioButton_4->setFont(font);
        comboBox = new QComboBox(theme);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(220, 190, 191, 21));
        label = new QLabel(theme);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 190, 81, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("AcadEref"));
        font1.setPointSize(12);
        label->setFont(font1);
        tabWidget->addTab(theme, QString());
        pushButton = new QPushButton(CSetDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 370, 131, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("AcadEref"));
        font2.setPointSize(14);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(CSetDlg);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 370, 131, 41));
        pushButton_2->setFont(font2);

        retranslateUi(CSetDlg);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CSetDlg);
    } // setupUi

    void retranslateUi(QWidget *CSetDlg)
    {
        CSetDlg->setWindowTitle(QApplication::translate("CSetDlg", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CSetDlg", "\351\237\263\346\225\210\350\256\276\347\275\256", Q_NULLPTR));
        checkBox->setText(QApplication::translate("CSetDlg", "\350\203\214\346\231\257\351\237\263\344\271\220", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("CSetDlg", "\351\237\263\346\225\210", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("CSetDlg", "\350\203\214\346\231\257\351\237\263\344\271\220\350\256\276\347\275\256", Q_NULLPTR));
        radioButton->setText(QApplication::translate("CSetDlg", "\351\273\230\350\256\244", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("CSetDlg", "\350\207\252\345\256\232\344\271\211", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("CSetDlg", "\346\265\217\350\247\210", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(sound), QApplication::translate("CSetDlg", "\351\237\263\346\225\210\350\256\276\347\275\256", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("CSetDlg", "\351\273\230\350\256\244", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("CSetDlg", "\350\207\252\345\256\232\344\271\211", Q_NULLPTR));
        label->setText(QApplication::translate("CSetDlg", "\344\270\273\351\242\230\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(theme), QApplication::translate("CSetDlg", "\344\270\273\351\242\230\350\256\276\347\275\256", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CSetDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CSetDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSetDlg: public Ui_CSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSETDLG_H
