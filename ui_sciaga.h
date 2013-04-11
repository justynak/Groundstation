/********************************************************************************
** Form generated from reading UI file 'sciaga.ui'
**
** Created: Thu Apr 11 14:32:36 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCIAGA_H
#define UI_SCIAGA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sciaga
{
public:
    QTextBrowser *textBrowser;
    QLabel *label;

    void setupUi(QWidget *Sciaga)
    {
        if (Sciaga->objectName().isEmpty())
            Sciaga->setObjectName(QString::fromUtf8("Sciaga"));
        Sciaga->resize(422, 522);
        textBrowser = new QTextBrowser(Sciaga);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 70, 351, 371));
        label = new QLabel(Sciaga);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 20, 66, 17));

        retranslateUi(Sciaga);

        QMetaObject::connectSlotsByName(Sciaga);
    } // setupUi

    void retranslateUi(QWidget *Sciaga)
    {
        Sciaga->setWindowTitle(QApplication::translate("Sciaga", "Form", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("Sciaga", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Stop wszystko - ESC</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Start - 1</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Jed\305\272 prosto - W,S</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Skr\304\231\304\207 w miejscu - A,D</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -q"
                        "t-block-indent:0; text-indent:0px;\">Stop jazda - 2</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Kop - Q</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Rozruch b\304\231bna - 3</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Kalibracja - 4</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Opu\305\233\304\207 do gruntu - 5</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Pilnuj pr\304\205d/obci\304\205\305\274enie - to ju\305\274 zmienia\304\207 w kodzie</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Teleoperator - button</p>\n"
"<p"
                        " style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Sciaga", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sciaga: public Ui_Sciaga {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCIAGA_H
