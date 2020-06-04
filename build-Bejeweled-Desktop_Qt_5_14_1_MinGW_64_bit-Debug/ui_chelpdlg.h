/********************************************************************************
** Form generated from reading UI file 'chelpdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHELPDLG_H
#define UI_CHELPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CHelpDlg
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *CHelpDlg)
    {
        if (CHelpDlg->objectName().isEmpty())
            CHelpDlg->setObjectName(QString::fromUtf8("CHelpDlg"));
        CHelpDlg->resize(409, 399);
        label = new QLabel(CHelpDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 81, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("AcadEref"));
        font.setPointSize(16);
        label->setFont(font);
        textBrowser = new QTextBrowser(CHelpDlg);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 50, 371, 311));

        retranslateUi(CHelpDlg);

        QMetaObject::connectSlotsByName(CHelpDlg);
    } // setupUi

    void retranslateUi(QWidget *CHelpDlg)
    {
        CHelpDlg->setWindowTitle(QCoreApplication::translate("CHelpDlg", "Help", nullptr));
        label->setText(QCoreApplication::translate("CHelpDlg", "\345\270\256\345\212\251\357\274\232", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("CHelpDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt;\">\346\270\270\346\210\217\350\247\204\345\210\231\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt;\">1.\344\272\222\346\215\242</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt;\">\347\216\251\345\256\266\351\200\211\344\270\255"
                        "\344\275\215\347\275\256\347\233\270\351\202\273\357\274\210\346\250\252\343\200\201\347\253\226\357\274\211\347\232\204\344\270\244\344\270\252\345\256\235\347\237\263\344\275\215\347\275\256\345\217\221\347\224\237\344\272\222\346\215\242\357\274\214\345\246\202\346\236\234\344\272\222\346\215\242\346\210\220\345\212\237\345\210\231\346\266\210\345\216\273\345\256\235\347\237\263\357\274\214\345\220\246\345\210\231\345\217\226\346\266\210\344\275\215\347\275\256\344\272\222\346\215\242\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt;\">2.\346\266\210\345\216\273</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt;\">\347\216\251\345\256\266\351\200\211\346\213\251\344\270\244\344\270\252\345\256\235\347\237\263\350\277\233\350"
                        "\241\214\344\275\215\347\275\256\344\272\222\346\215\242\357\274\214\344\272\222\346\215\242\345\220\216\345\246\202\346\236\234\346\250\252\346\216\222\346\210\226\347\253\226\346\216\222\347\232\204\346\234\2113\344\270\252\346\210\2263\344\270\252\344\273\245\344\270\212\347\232\204\347\233\270\345\220\214\345\256\235\347\237\263\357\274\214\345\210\231\346\266\210\345\216\273\350\277\231\345\207\240\344\270\252\347\233\270\345\220\214\345\256\235\347\237\263\357\274\214\345\246\202\346\236\234\344\272\222\346\215\242\345\220\216\346\262\241\346\234\211\345\217\257\344\273\245\346\266\210\345\216\273\347\232\204\345\256\235\347\237\263\357\274\214\345\210\231\351\200\211\344\270\255\347\232\204\344\270\244\344\270\252\345\256\235\347\237\263\346\215\242\345\233\236\345\216\237\346\235\245\347\232\204\344\275\215\347\275\256\357\274\214\346\266\210\345\216\273\345\220\216\347\232\204\347\251\272\346\240\274\347\224\261\344\270\212\351\235\242\347\232\204\345\256\235\347\237\263\346\216\211\344\270\213\346\235"
                        "\245\350\241\245\351\275\220\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt;\">3.\350\277\236\351\224\201</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt;\">\347\216\251\345\256\266\346\266\210\345\216\273\345\256\235\347\237\263\345\220\216\357\274\214\344\270\212\351\235\242\347\232\204\345\256\235\347\237\263\346\216\211\344\270\213\346\235\245\350\241\245\345\205\205\347\251\272\346\240\274\357\274\214\345\246\202\346\236\234\350\277\231\346\227\266\346\270\270\346\210\217\346\261\240\344\270\255\346\234\211\350\277\236\347\273\255\346\221\206\346\224\276\357\274\210\346\250\252\343\200\201\347\253\226\357\274\211\347\232\2043\344\270\252\346\210\2263\344\270\252\344\273\245\344\270\212\347\233\270\345\220\214\347\232\204"
                        "\345\256\235\347\237\263\357\274\214\345\210\231\345\217\257\344\273\245\346\266\210\345\216\273\350\277\231\344\272\233\345\256\235\347\237\263\357\274\214\350\277\231\345\260\261\346\230\257\344\270\200\346\254\241\350\277\236\351\224\201\343\200\202\347\251\272\346\240\274\350\242\253\346\226\260\347\232\204\345\256\235\347\237\263\345\241\253\345\205\205\357\274\214\345\217\210\345\217\257\344\273\245\350\277\233\350\241\214\344\270\213\344\270\200\346\254\241\350\277\236\351\224\201\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:11pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CHelpDlg: public Ui_CHelpDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHELPDLG_H
