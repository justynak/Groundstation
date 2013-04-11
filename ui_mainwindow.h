/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 11 14:32:36 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qled.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_10;
    QLCDNumber *lcdTimer;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLed *qLed_2;
    QLed *qLed_7;
    QLed *qLed_4;
    QLed *qLed_6;
    QLed *qLed_5;
    QLed *qLed_3;
    QLed *qLed;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_8;
    QPushButton *buttonTeleoperation;
    QPushButton *buttonStop;
    QLabel *labelWebCam;
    QLabel *labelMap;
    QPushButton *buttonQuit;
    QPushButton *buttonStart;
    QPushButton *buttonHalt;
    QPushButton *buttonCalibrate;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditKeepU;
    QLineEdit *lineEditSteerW;
    QLineEdit *lineEditKeepI;
    QLineEdit *lineEditSteerNr;
    QSlider *horizontalSliderArmPosition;
    QPushButton *buttonSteer;
    QPushButton *buttonKeep;
    QPushButton *buttonArmPosition;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(931, 679);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 150, 111, 17));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(580, 190, 101, 17));
        lcdTimer = new QLCDNumber(centralwidget);
        lcdTimer->setObjectName(QString::fromUtf8("lcdTimer"));
        lcdTimer->setGeometry(QRect(490, 20, 411, 91));
        lcdNumber_2 = new QLCDNumber(centralwidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(490, 140, 81, 31));
        lcdNumber_3 = new QLCDNumber(centralwidget);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(490, 180, 81, 31));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(730, 130, 51, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        qLed_2 = new QLed(verticalLayoutWidget);
        qLed_2->setObjectName(QString::fromUtf8("qLed_2"));
        qLed_2->setValue(false);
        qLed_2->setOnColor(QLed::Red);
        qLed_2->setOffColor(QLed::Grey);
        qLed_2->setShape(QLed::Circle);

        verticalLayout->addWidget(qLed_2);

        qLed_7 = new QLed(verticalLayoutWidget);
        qLed_7->setObjectName(QString::fromUtf8("qLed_7"));
        qLed_7->setValue(false);
        qLed_7->setOnColor(QLed::Red);
        qLed_7->setOffColor(QLed::Grey);
        qLed_7->setShape(QLed::Circle);

        verticalLayout->addWidget(qLed_7);

        qLed_4 = new QLed(verticalLayoutWidget);
        qLed_4->setObjectName(QString::fromUtf8("qLed_4"));
        qLed_4->setValue(false);
        qLed_4->setOnColor(QLed::Red);
        qLed_4->setOffColor(QLed::Grey);
        qLed_4->setShape(QLed::Circle);

        verticalLayout->addWidget(qLed_4);

        qLed_6 = new QLed(verticalLayoutWidget);
        qLed_6->setObjectName(QString::fromUtf8("qLed_6"));
        qLed_6->setValue(false);
        qLed_6->setOnColor(QLed::Red);
        qLed_6->setOffColor(QLed::Grey);
        qLed_6->setShape(QLed::Circle);

        verticalLayout->addWidget(qLed_6);

        qLed_5 = new QLed(verticalLayoutWidget);
        qLed_5->setObjectName(QString::fromUtf8("qLed_5"));
        qLed_5->setValue(false);
        qLed_5->setOnColor(QLed::Red);
        qLed_5->setOffColor(QLed::Grey);
        qLed_5->setShape(QLed::Circle);

        verticalLayout->addWidget(qLed_5);

        qLed_3 = new QLed(verticalLayoutWidget);
        qLed_3->setObjectName(QString::fromUtf8("qLed_3"));
        qLed_3->setValue(false);
        qLed_3->setOnColor(QLed::Red);
        qLed_3->setOffColor(QLed::Grey);
        qLed_3->setShape(QLed::Circle);

        verticalLayout->addWidget(qLed_3);

        qLed = new QLed(verticalLayoutWidget);
        qLed->setObjectName(QString::fromUtf8("qLed"));
        qLed->setValue(false);
        qLed->setOnColor(QLed::Red);
        qLed->setOffColor(QLed::Grey);
        qLed->setShape(QLed::Circle);

        verticalLayout->addWidget(qLed);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(790, 130, 111, 411));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        buttonTeleoperation = new QPushButton(centralwidget);
        buttonTeleoperation->setObjectName(QString::fromUtf8("buttonTeleoperation"));
        buttonTeleoperation->setGeometry(QRect(490, 240, 221, 51));
        buttonStop = new QPushButton(centralwidget);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        buttonStop->setGeometry(QRect(490, 360, 111, 51));
        labelWebCam = new QLabel(centralwidget);
        labelWebCam->setObjectName(QString::fromUtf8("labelWebCam"));
        labelWebCam->setGeometry(QRect(40, 40, 421, 241));
        labelMap = new QLabel(centralwidget);
        labelMap->setObjectName(QString::fromUtf8("labelMap"));
        labelMap->setGeometry(QRect(40, 310, 431, 261));
        buttonQuit = new QPushButton(centralwidget);
        buttonQuit->setObjectName(QString::fromUtf8("buttonQuit"));
        buttonQuit->setGeometry(QRect(730, 560, 171, 41));
        buttonStart = new QPushButton(centralwidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        buttonStart->setGeometry(QRect(490, 300, 221, 51));
        buttonHalt = new QPushButton(centralwidget);
        buttonHalt->setObjectName(QString::fromUtf8("buttonHalt"));
        buttonHalt->setGeometry(QRect(610, 360, 101, 51));
        buttonCalibrate = new QPushButton(centralwidget);
        buttonCalibrate->setObjectName(QString::fromUtf8("buttonCalibrate"));
        buttonCalibrate->setGeometry(QRect(480, 540, 98, 27));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(600, 420, 121, 97));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditKeepU = new QLineEdit(gridLayoutWidget);
        lineEditKeepU->setObjectName(QString::fromUtf8("lineEditKeepU"));

        gridLayout->addWidget(lineEditKeepU, 1, 0, 1, 1);

        lineEditSteerW = new QLineEdit(gridLayoutWidget);
        lineEditSteerW->setObjectName(QString::fromUtf8("lineEditSteerW"));

        gridLayout->addWidget(lineEditSteerW, 0, 1, 1, 1);

        lineEditKeepI = new QLineEdit(gridLayoutWidget);
        lineEditKeepI->setObjectName(QString::fromUtf8("lineEditKeepI"));

        gridLayout->addWidget(lineEditKeepI, 1, 1, 1, 1);

        lineEditSteerNr = new QLineEdit(gridLayoutWidget);
        lineEditSteerNr->setObjectName(QString::fromUtf8("lineEditSteerNr"));

        gridLayout->addWidget(lineEditSteerNr, 0, 0, 1, 1);

        horizontalSliderArmPosition = new QSlider(gridLayoutWidget);
        horizontalSliderArmPosition->setObjectName(QString::fromUtf8("horizontalSliderArmPosition"));
        horizontalSliderArmPosition->setMaximum(2);
        horizontalSliderArmPosition->setPageStep(1);
        horizontalSliderArmPosition->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderArmPosition, 2, 0, 1, 2);

        buttonSteer = new QPushButton(gridLayoutWidget);
        buttonSteer->setObjectName(QString::fromUtf8("buttonSteer"));

        gridLayout->addWidget(buttonSteer, 0, 2, 1, 1);

        buttonKeep = new QPushButton(gridLayoutWidget);
        buttonKeep->setObjectName(QString::fromUtf8("buttonKeep"));

        gridLayout->addWidget(buttonKeep, 1, 2, 1, 1);

        buttonArmPosition = new QPushButton(gridLayoutWidget);
        buttonArmPosition->setObjectName(QString::fromUtf8("buttonArmPosition"));

        gridLayout->addWidget(buttonArmPosition, 2, 2, 1, 1);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(480, 420, 111, 101));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_3->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 931, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "CURRENT MASS", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "TOTAL MASS", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        qLed_2->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_2->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed_7->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_7->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed_4->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_4->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed_6->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_6->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed_5->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_5->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed_3->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_3->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_7->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        buttonTeleoperation->setText(QApplication::translate("MainWindow", "TELEOPERATION", 0, QApplication::UnicodeUTF8));
        buttonStop->setText(QApplication::translate("MainWindow", "STOP", 0, QApplication::UnicodeUTF8));
        labelWebCam->setText(QApplication::translate("MainWindow", "CAMERA", 0, QApplication::UnicodeUTF8));
        labelMap->setText(QApplication::translate("MainWindow", "MAP", 0, QApplication::UnicodeUTF8));
        buttonQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        buttonStart->setText(QApplication::translate("MainWindow", "START", 0, QApplication::UnicodeUTF8));
        buttonHalt->setText(QApplication::translate("MainWindow", "HALT", 0, QApplication::UnicodeUTF8));
        buttonCalibrate->setText(QApplication::translate("MainWindow", "Calibrate", 0, QApplication::UnicodeUTF8));
        lineEditKeepU->setText(QString());
        lineEditSteerNr->setText(QString());
        buttonSteer->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        buttonKeep->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        buttonArmPosition->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Steer Engine i, w", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Keep max U, I", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Arm position", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
