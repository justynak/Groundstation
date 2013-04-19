/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Apr 20 01:06:46 2013
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
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "qled.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelWebCam;
    QLabel *labelMap;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *checkBox_EngineSteerRight;
    QCheckBox *checkBox_EngineSteerLeft;
    QCheckBox *checkBox_EngineSteerArm;
    QCheckBox *checkBox_EngineSteerCylinder;
    QLineEdit *lineEdit_SteerEngineRight;
    QLineEdit *lineEdit_EngineSteerLeft;
    QLineEdit *lineEdit_EngineSteerCylinder;
    QLineEdit *lineEdit_EngineSteerArm;
    QPushButton *button_EngineSteer;
    QLed *qLed_EngineSteerRight;
    QLed *qLed_EngineSteerLeft;
    QLed *qLed_EngineSteerArm;
    QLed *qLed_EngineSteerCylinder;
    QLabel *label_3;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *button_Electromagnets;
    QFrame *line_4;
    QLabel *label_4;
    QCheckBox *checkBox_ArchEngineRight;
    QCheckBox *checkBox_ArchEngineLeft;
    QLineEdit *lineEdit_ArchEngineRight;
    QLineEdit *lineEdit_ArchEngineLeft;
    QPushButton *button_Arch;
    QFrame *line_5;
    QLabel *label_5;
    QPushButton *button_StopAll;
    QPushButton *button_StopDriving;
    QPushButton *button_StopArm;
    QPushButton *button_StopCylinder;
    QPushButton *button_Calibration;
    QPushButton *button_UpdateValues;
    QLineEdit *lineEdit_PowerControlCurrent;
    QLineEdit *lineEdit_PowerControlVoltage;
    QPushButton *button_PowerControl;
    QLabel *label_6;
    QLabel *label_7;
    QLCDNumber *lcdNumber_RemainingTime;
    QLCDNumber *lcdNumber_CurrentMass;
    QLCDNumber *lcdNumber_TotalMass;
    QFrame *line_7;
    QFrame *line_8;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *button_Mining_Initiate;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QFrame *line_9;
    QPushButton *button_Unloading_Initiate;
    QCheckBox *checkBox_Mining_CloseCylinder;
    QCheckBox *checkBox_Mining_ArmPosition4;
    QCheckBox *checkBox_Mining_StartCylinder;
    QCheckBox *checkBox_Mining_SetCylinderTo0;
    QCheckBox *checkBox_Mining_MiningDriving;
    QCheckBox *checkBox_Mining_SetArmPosition1;
    QCheckBox *checkBox_Mining_TensometerMass;
    QPushButton *button_Mining_CheckCylinderState;
    QPushButton *button_Mining_ArmPosition4;
    QPushButton *button_Mining_StartCylinder;
    QPushButton *button_Mining_SetCylinderTo0;
    QPushButton *button_Mining_MiningDriving;
    QPushButton *button_Mining_TensometerMass;
    QPushButton *button_Mining_ArmPositionTo1;
    QCheckBox *checkBox_Unloading_CheckArmPosition;
    QCheckBox *checkBox_Unloading_RotateCylinder;
    QPushButton *button_Unloading_CloseCylinder;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QCheckBox *checkBox_Unloading_OpenCylinder;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *button_Unloading_OpenCylinder;
    QCheckBox *checkBox_Unloading_SetArmPosition1;
    QPushButton *button_Unloading_ShakeCylinder;
    QCheckBox *checkBox_Unloading_SetCylinderTo0;
    QCheckBox *checkBox_Unloading_ShakeCylinder;
    QLabel *label_20;
    QCheckBox *checkBox_Unloading_CloseCylinder;
    QPushButton *button_Unloading_RotateCylinder;
    QPushButton *button_Unloading_SetArmPosition1;
    QLabel *label_21;
    QPushButton *button_Unloading_CheckArmPosition;
    QPushButton *button_Unloading_SetCylinderTo0;
    QFrame *line_10;
    QLed *qLed_ArchEngineLeft;
    QLed *qLed_ArchEngineLeft_2;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_25;
    QLabel *label_26;
    QFrame *line_11;
    QFrame *line_6;
    QLabel *label_24;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QFrame *line;
    QPushButton *button_StartAll;
    QPushButton *button_Teleoperation;
    QLineEdit *lineEdit_CylinderSpeed;
    QLabel *label_31;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1165, 767);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelWebCam = new QLabel(centralwidget);
        labelWebCam->setObjectName(QString::fromUtf8("labelWebCam"));
        labelWebCam->setGeometry(QRect(20, 20, 431, 321));
        labelMap = new QLabel(centralwidget);
        labelMap->setObjectName(QString::fromUtf8("labelMap"));
        labelMap->setGeometry(QRect(20, 390, 451, 291));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(550, 10, 191, 20));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(530, 70, 66, 17));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        checkBox_EngineSteerRight = new QCheckBox(centralwidget);
        checkBox_EngineSteerRight->setObjectName(QString::fromUtf8("checkBox_EngineSteerRight"));
        checkBox_EngineSteerRight->setGeometry(QRect(570, 100, 97, 22));
        checkBox_EngineSteerLeft = new QCheckBox(centralwidget);
        checkBox_EngineSteerLeft->setObjectName(QString::fromUtf8("checkBox_EngineSteerLeft"));
        checkBox_EngineSteerLeft->setGeometry(QRect(570, 120, 97, 22));
        checkBox_EngineSteerArm = new QCheckBox(centralwidget);
        checkBox_EngineSteerArm->setObjectName(QString::fromUtf8("checkBox_EngineSteerArm"));
        checkBox_EngineSteerArm->setGeometry(QRect(570, 140, 97, 22));
        checkBox_EngineSteerCylinder = new QCheckBox(centralwidget);
        checkBox_EngineSteerCylinder->setObjectName(QString::fromUtf8("checkBox_EngineSteerCylinder"));
        checkBox_EngineSteerCylinder->setGeometry(QRect(570, 160, 97, 22));
        lineEdit_SteerEngineRight = new QLineEdit(centralwidget);
        lineEdit_SteerEngineRight->setObjectName(QString::fromUtf8("lineEdit_SteerEngineRight"));
        lineEdit_SteerEngineRight->setGeometry(QRect(680, 100, 31, 21));
        lineEdit_EngineSteerLeft = new QLineEdit(centralwidget);
        lineEdit_EngineSteerLeft->setObjectName(QString::fromUtf8("lineEdit_EngineSteerLeft"));
        lineEdit_EngineSteerLeft->setGeometry(QRect(680, 120, 31, 20));
        lineEdit_EngineSteerCylinder = new QLineEdit(centralwidget);
        lineEdit_EngineSteerCylinder->setObjectName(QString::fromUtf8("lineEdit_EngineSteerCylinder"));
        lineEdit_EngineSteerCylinder->setGeometry(QRect(680, 160, 31, 21));
        lineEdit_EngineSteerArm = new QLineEdit(centralwidget);
        lineEdit_EngineSteerArm->setObjectName(QString::fromUtf8("lineEdit_EngineSteerArm"));
        lineEdit_EngineSteerArm->setGeometry(QRect(680, 140, 31, 21));
        button_EngineSteer = new QPushButton(centralwidget);
        button_EngineSteer->setObjectName(QString::fromUtf8("button_EngineSteer"));
        button_EngineSteer->setGeometry(QRect(740, 100, 31, 81));
        qLed_EngineSteerRight = new QLed(centralwidget);
        qLed_EngineSteerRight->setObjectName(QString::fromUtf8("qLed_EngineSteerRight"));
        qLed_EngineSteerRight->setGeometry(QRect(530, 100, 21, 21));
        qLed_EngineSteerRight->setValue(false);
        qLed_EngineSteerRight->setOnColor(QLed::Red);
        qLed_EngineSteerRight->setOffColor(QLed::Grey);
        qLed_EngineSteerRight->setShape(QLed::Circle);
        qLed_EngineSteerLeft = new QLed(centralwidget);
        qLed_EngineSteerLeft->setObjectName(QString::fromUtf8("qLed_EngineSteerLeft"));
        qLed_EngineSteerLeft->setGeometry(QRect(530, 120, 21, 21));
        qLed_EngineSteerLeft->setValue(false);
        qLed_EngineSteerLeft->setOnColor(QLed::Red);
        qLed_EngineSteerLeft->setOffColor(QLed::Grey);
        qLed_EngineSteerLeft->setShape(QLed::Circle);
        qLed_EngineSteerArm = new QLed(centralwidget);
        qLed_EngineSteerArm->setObjectName(QString::fromUtf8("qLed_EngineSteerArm"));
        qLed_EngineSteerArm->setGeometry(QRect(530, 140, 21, 21));
        qLed_EngineSteerArm->setValue(false);
        qLed_EngineSteerArm->setOnColor(QLed::Red);
        qLed_EngineSteerArm->setOffColor(QLed::Grey);
        qLed_EngineSteerArm->setShape(QLed::Circle);
        qLed_EngineSteerCylinder = new QLed(centralwidget);
        qLed_EngineSteerCylinder->setObjectName(QString::fromUtf8("qLed_EngineSteerCylinder"));
        qLed_EngineSteerCylinder->setGeometry(QRect(530, 160, 21, 21));
        qLed_EngineSteerCylinder->setValue(false);
        qLed_EngineSteerCylinder->setOnColor(QLed::Red);
        qLed_EngineSteerCylinder->setOffColor(QLed::Grey);
        qLed_EngineSteerCylinder->setShape(QLed::Circle);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 210, 131, 20));
        label_3->setFont(font1);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(490, -10, 20, 741));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(510, 50, 271, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        button_Electromagnets = new QPushButton(centralwidget);
        button_Electromagnets->setObjectName(QString::fromUtf8("button_Electromagnets"));
        button_Electromagnets->setGeometry(QRect(740, 210, 31, 27));
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(510, 240, 271, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(530, 260, 66, 17));
        label_4->setFont(font1);
        checkBox_ArchEngineRight = new QCheckBox(centralwidget);
        checkBox_ArchEngineRight->setObjectName(QString::fromUtf8("checkBox_ArchEngineRight"));
        checkBox_ArchEngineRight->setGeometry(QRect(570, 290, 97, 22));
        checkBox_ArchEngineLeft = new QCheckBox(centralwidget);
        checkBox_ArchEngineLeft->setObjectName(QString::fromUtf8("checkBox_ArchEngineLeft"));
        checkBox_ArchEngineLeft->setGeometry(QRect(570, 310, 81, 22));
        lineEdit_ArchEngineRight = new QLineEdit(centralwidget);
        lineEdit_ArchEngineRight->setObjectName(QString::fromUtf8("lineEdit_ArchEngineRight"));
        lineEdit_ArchEngineRight->setGeometry(QRect(680, 290, 31, 21));
        lineEdit_ArchEngineLeft = new QLineEdit(centralwidget);
        lineEdit_ArchEngineLeft->setObjectName(QString::fromUtf8("lineEdit_ArchEngineLeft"));
        lineEdit_ArchEngineLeft->setGeometry(QRect(680, 310, 31, 21));
        button_Arch = new QPushButton(centralwidget);
        button_Arch->setObjectName(QString::fromUtf8("button_Arch"));
        button_Arch->setGeometry(QRect(740, 290, 31, 41));
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(510, 460, 271, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(540, 490, 221, 17));
        label_5->setFont(font);
        button_StopAll = new QPushButton(centralwidget);
        button_StopAll->setObjectName(QString::fromUtf8("button_StopAll"));
        button_StopAll->setGeometry(QRect(530, 530, 111, 27));
        button_StopDriving = new QPushButton(centralwidget);
        button_StopDriving->setObjectName(QString::fromUtf8("button_StopDriving"));
        button_StopDriving->setGeometry(QRect(530, 570, 111, 27));
        button_StopArm = new QPushButton(centralwidget);
        button_StopArm->setObjectName(QString::fromUtf8("button_StopArm"));
        button_StopArm->setGeometry(QRect(530, 610, 111, 27));
        button_StopCylinder = new QPushButton(centralwidget);
        button_StopCylinder->setObjectName(QString::fromUtf8("button_StopCylinder"));
        button_StopCylinder->setGeometry(QRect(530, 650, 111, 27));
        button_Calibration = new QPushButton(centralwidget);
        button_Calibration->setObjectName(QString::fromUtf8("button_Calibration"));
        button_Calibration->setGeometry(QRect(550, 410, 61, 41));
        button_UpdateValues = new QPushButton(centralwidget);
        button_UpdateValues->setObjectName(QString::fromUtf8("button_UpdateValues"));
        button_UpdateValues->setGeometry(QRect(705, 410, 61, 41));
        lineEdit_PowerControlCurrent = new QLineEdit(centralwidget);
        lineEdit_PowerControlCurrent->setObjectName(QString::fromUtf8("lineEdit_PowerControlCurrent"));
        lineEdit_PowerControlCurrent->setGeometry(QRect(750, 580, 31, 21));
        lineEdit_PowerControlVoltage = new QLineEdit(centralwidget);
        lineEdit_PowerControlVoltage->setObjectName(QString::fromUtf8("lineEdit_PowerControlVoltage"));
        lineEdit_PowerControlVoltage->setGeometry(QRect(750, 560, 31, 21));
        button_PowerControl = new QPushButton(centralwidget);
        button_PowerControl->setObjectName(QString::fromUtf8("button_PowerControl"));
        button_PowerControl->setGeometry(QRect(670, 610, 101, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(950, 120, 121, 17));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_6->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(940, 430, 171, 17));
        label_7->setFont(font);
        lcdNumber_RemainingTime = new QLCDNumber(centralwidget);
        lcdNumber_RemainingTime->setObjectName(QString::fromUtf8("lcdNumber_RemainingTime"));
        lcdNumber_RemainingTime->setGeometry(QRect(810, 10, 181, 71));
        lcdNumber_CurrentMass = new QLCDNumber(centralwidget);
        lcdNumber_CurrentMass->setObjectName(QString::fromUtf8("lcdNumber_CurrentMass"));
        lcdNumber_CurrentMass->setGeometry(QRect(1080, 30, 71, 31));
        lcdNumber_TotalMass = new QLCDNumber(centralwidget);
        lcdNumber_TotalMass->setObjectName(QString::fromUtf8("lcdNumber_TotalMass"));
        lcdNumber_TotalMass->setGeometry(QRect(1080, 70, 71, 31));
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(790, -10, 20, 751));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(800, 100, 361, 16));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(830, 190, 131, 17));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(830, 220, 191, 17));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(830, 250, 161, 17));
        button_Mining_Initiate = new QPushButton(centralwidget);
        button_Mining_Initiate->setObjectName(QString::fromUtf8("button_Mining_Initiate"));
        button_Mining_Initiate->setGeometry(QRect(830, 150, 321, 27));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(830, 280, 141, 17));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(830, 310, 131, 17));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(830, 340, 151, 17));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(830, 370, 181, 17));
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(810, 400, 361, 16));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        button_Unloading_Initiate = new QPushButton(centralwidget);
        button_Unloading_Initiate->setObjectName(QString::fromUtf8("button_Unloading_Initiate"));
        button_Unloading_Initiate->setGeometry(QRect(830, 460, 321, 27));
        checkBox_Mining_CloseCylinder = new QCheckBox(centralwidget);
        checkBox_Mining_CloseCylinder->setObjectName(QString::fromUtf8("checkBox_Mining_CloseCylinder"));
        checkBox_Mining_CloseCylinder->setGeometry(QRect(1100, 190, 61, 22));
        checkBox_Mining_ArmPosition4 = new QCheckBox(centralwidget);
        checkBox_Mining_ArmPosition4->setObjectName(QString::fromUtf8("checkBox_Mining_ArmPosition4"));
        checkBox_Mining_ArmPosition4->setGeometry(QRect(1100, 220, 61, 22));
        checkBox_Mining_StartCylinder = new QCheckBox(centralwidget);
        checkBox_Mining_StartCylinder->setObjectName(QString::fromUtf8("checkBox_Mining_StartCylinder"));
        checkBox_Mining_StartCylinder->setGeometry(QRect(1100, 250, 61, 22));
        checkBox_Mining_SetCylinderTo0 = new QCheckBox(centralwidget);
        checkBox_Mining_SetCylinderTo0->setObjectName(QString::fromUtf8("checkBox_Mining_SetCylinderTo0"));
        checkBox_Mining_SetCylinderTo0->setGeometry(QRect(1100, 280, 61, 22));
        checkBox_Mining_MiningDriving = new QCheckBox(centralwidget);
        checkBox_Mining_MiningDriving->setObjectName(QString::fromUtf8("checkBox_Mining_MiningDriving"));
        checkBox_Mining_MiningDriving->setGeometry(QRect(1100, 310, 61, 22));
        checkBox_Mining_SetArmPosition1 = new QCheckBox(centralwidget);
        checkBox_Mining_SetArmPosition1->setObjectName(QString::fromUtf8("checkBox_Mining_SetArmPosition1"));
        checkBox_Mining_SetArmPosition1->setGeometry(QRect(1100, 370, 61, 22));
        checkBox_Mining_TensometerMass = new QCheckBox(centralwidget);
        checkBox_Mining_TensometerMass->setObjectName(QString::fromUtf8("checkBox_Mining_TensometerMass"));
        checkBox_Mining_TensometerMass->setGeometry(QRect(1100, 340, 61, 22));
        button_Mining_CheckCylinderState = new QPushButton(centralwidget);
        button_Mining_CheckCylinderState->setObjectName(QString::fromUtf8("button_Mining_CheckCylinderState"));
        button_Mining_CheckCylinderState->setGeometry(QRect(1050, 190, 31, 21));
        button_Mining_ArmPosition4 = new QPushButton(centralwidget);
        button_Mining_ArmPosition4->setObjectName(QString::fromUtf8("button_Mining_ArmPosition4"));
        button_Mining_ArmPosition4->setGeometry(QRect(1050, 220, 31, 21));
        button_Mining_StartCylinder = new QPushButton(centralwidget);
        button_Mining_StartCylinder->setObjectName(QString::fromUtf8("button_Mining_StartCylinder"));
        button_Mining_StartCylinder->setGeometry(QRect(1050, 250, 31, 21));
        button_Mining_SetCylinderTo0 = new QPushButton(centralwidget);
        button_Mining_SetCylinderTo0->setObjectName(QString::fromUtf8("button_Mining_SetCylinderTo0"));
        button_Mining_SetCylinderTo0->setGeometry(QRect(1050, 280, 31, 21));
        button_Mining_MiningDriving = new QPushButton(centralwidget);
        button_Mining_MiningDriving->setObjectName(QString::fromUtf8("button_Mining_MiningDriving"));
        button_Mining_MiningDriving->setGeometry(QRect(1050, 310, 31, 21));
        button_Mining_TensometerMass = new QPushButton(centralwidget);
        button_Mining_TensometerMass->setObjectName(QString::fromUtf8("button_Mining_TensometerMass"));
        button_Mining_TensometerMass->setGeometry(QRect(1050, 340, 31, 21));
        button_Mining_ArmPositionTo1 = new QPushButton(centralwidget);
        button_Mining_ArmPositionTo1->setObjectName(QString::fromUtf8("button_Mining_ArmPositionTo1"));
        button_Mining_ArmPositionTo1->setGeometry(QRect(1050, 370, 31, 21));
        checkBox_Unloading_CheckArmPosition = new QCheckBox(centralwidget);
        checkBox_Unloading_CheckArmPosition->setObjectName(QString::fromUtf8("checkBox_Unloading_CheckArmPosition"));
        checkBox_Unloading_CheckArmPosition->setGeometry(QRect(1100, 680, 61, 22));
        checkBox_Unloading_RotateCylinder = new QCheckBox(centralwidget);
        checkBox_Unloading_RotateCylinder->setObjectName(QString::fromUtf8("checkBox_Unloading_RotateCylinder"));
        checkBox_Unloading_RotateCylinder->setGeometry(QRect(1100, 620, 61, 22));
        button_Unloading_CloseCylinder = new QPushButton(centralwidget);
        button_Unloading_CloseCylinder->setObjectName(QString::fromUtf8("button_Unloading_CloseCylinder"));
        button_Unloading_CloseCylinder->setGeometry(QRect(1050, 650, 31, 21));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(830, 560, 161, 17));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(830, 530, 191, 17));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(830, 620, 131, 17));
        checkBox_Unloading_OpenCylinder = new QCheckBox(centralwidget);
        checkBox_Unloading_OpenCylinder->setObjectName(QString::fromUtf8("checkBox_Unloading_OpenCylinder"));
        checkBox_Unloading_OpenCylinder->setGeometry(QRect(1100, 560, 61, 22));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(830, 500, 171, 17));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(830, 590, 141, 17));
        button_Unloading_OpenCylinder = new QPushButton(centralwidget);
        button_Unloading_OpenCylinder->setObjectName(QString::fromUtf8("button_Unloading_OpenCylinder"));
        button_Unloading_OpenCylinder->setGeometry(QRect(1050, 560, 31, 21));
        checkBox_Unloading_SetArmPosition1 = new QCheckBox(centralwidget);
        checkBox_Unloading_SetArmPosition1->setObjectName(QString::fromUtf8("checkBox_Unloading_SetArmPosition1"));
        checkBox_Unloading_SetArmPosition1->setGeometry(QRect(1100, 500, 61, 22));
        button_Unloading_ShakeCylinder = new QPushButton(centralwidget);
        button_Unloading_ShakeCylinder->setObjectName(QString::fromUtf8("button_Unloading_ShakeCylinder"));
        button_Unloading_ShakeCylinder->setGeometry(QRect(1050, 590, 31, 21));
        checkBox_Unloading_SetCylinderTo0 = new QCheckBox(centralwidget);
        checkBox_Unloading_SetCylinderTo0->setObjectName(QString::fromUtf8("checkBox_Unloading_SetCylinderTo0"));
        checkBox_Unloading_SetCylinderTo0->setGeometry(QRect(1100, 530, 61, 22));
        checkBox_Unloading_ShakeCylinder = new QCheckBox(centralwidget);
        checkBox_Unloading_ShakeCylinder->setObjectName(QString::fromUtf8("checkBox_Unloading_ShakeCylinder"));
        checkBox_Unloading_ShakeCylinder->setGeometry(QRect(1100, 590, 61, 22));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(830, 650, 151, 17));
        checkBox_Unloading_CloseCylinder = new QCheckBox(centralwidget);
        checkBox_Unloading_CloseCylinder->setObjectName(QString::fromUtf8("checkBox_Unloading_CloseCylinder"));
        checkBox_Unloading_CloseCylinder->setGeometry(QRect(1100, 650, 61, 22));
        button_Unloading_RotateCylinder = new QPushButton(centralwidget);
        button_Unloading_RotateCylinder->setObjectName(QString::fromUtf8("button_Unloading_RotateCylinder"));
        button_Unloading_RotateCylinder->setGeometry(QRect(1050, 620, 31, 21));
        button_Unloading_SetArmPosition1 = new QPushButton(centralwidget);
        button_Unloading_SetArmPosition1->setObjectName(QString::fromUtf8("button_Unloading_SetArmPosition1"));
        button_Unloading_SetArmPosition1->setGeometry(QRect(1050, 500, 31, 21));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(830, 680, 181, 17));
        button_Unloading_CheckArmPosition = new QPushButton(centralwidget);
        button_Unloading_CheckArmPosition->setObjectName(QString::fromUtf8("button_Unloading_CheckArmPosition"));
        button_Unloading_CheckArmPosition->setGeometry(QRect(1050, 680, 31, 21));
        button_Unloading_SetCylinderTo0 = new QPushButton(centralwidget);
        button_Unloading_SetCylinderTo0->setObjectName(QString::fromUtf8("button_Unloading_SetCylinderTo0"));
        button_Unloading_SetCylinderTo0->setGeometry(QRect(1050, 530, 31, 21));
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(510, 190, 271, 20));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        qLed_ArchEngineLeft = new QLed(centralwidget);
        qLed_ArchEngineLeft->setObjectName(QString::fromUtf8("qLed_ArchEngineLeft"));
        qLed_ArchEngineLeft->setGeometry(QRect(530, 290, 21, 21));
        qLed_ArchEngineLeft->setValue(false);
        qLed_ArchEngineLeft->setOnColor(QLed::Red);
        qLed_ArchEngineLeft->setOffColor(QLed::Grey);
        qLed_ArchEngineLeft->setShape(QLed::Circle);
        qLed_ArchEngineLeft_2 = new QLed(centralwidget);
        qLed_ArchEngineLeft_2->setObjectName(QString::fromUtf8("qLed_ArchEngineLeft_2"));
        qLed_ArchEngineLeft_2->setGeometry(QRect(530, 310, 21, 21));
        qLed_ArchEngineLeft_2->setValue(false);
        qLed_ArchEngineLeft_2->setOnColor(QLed::Red);
        qLed_ArchEngineLeft_2->setOffColor(QLed::Grey);
        qLed_ArchEngineLeft_2->setShape(QLed::Circle);
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(580, 360, 191, 20));
        label_22->setFont(font);
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(670, 520, 111, 21));
        label_23->setFont(font1);
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(660, 560, 81, 20));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(660, 580, 81, 21));
        line_11 = new QFrame(centralwidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(510, 690, 261, 20));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(510, 330, 271, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(530, 390, 101, 20));
        label_24->setFont(font1);
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(680, 390, 111, 20));
        label_27->setFont(font1);
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(1020, 80, 66, 17));
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(1020, 40, 66, 17));
        label_30 = new QLabel(centralwidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(1060, 0, 66, 17));
        label_30->setFont(font1);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 360, 461, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        button_StartAll = new QPushButton(centralwidget);
        button_StartAll->setObjectName(QString::fromUtf8("button_StartAll"));
        button_StartAll->setGeometry(QRect(740, 10, 51, 41));
        button_Teleoperation = new QPushButton(centralwidget);
        button_Teleoperation->setObjectName(QString::fromUtf8("button_Teleoperation"));
        button_Teleoperation->setGeometry(QRect(660, 640, 121, 41));
        lineEdit_CylinderSpeed = new QLineEdit(centralwidget);
        lineEdit_CylinderSpeed->setObjectName(QString::fromUtf8("lineEdit_CylinderSpeed"));
        lineEdit_CylinderSpeed->setGeometry(QRect(750, 70, 41, 21));
        label_31 = new QLabel(centralwidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(680, 70, 66, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1165, 25));
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
        labelWebCam->setText(QApplication::translate("MainWindow", "CAMERA", 0, QApplication::UnicodeUTF8));
        labelMap->setText(QApplication::translate("MainWindow", "MAP", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "BASIC FUNCTIONS", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Engines", 0, QApplication::UnicodeUTF8));
        checkBox_EngineSteerRight->setText(QApplication::translate("MainWindow", "RIGHT", 0, QApplication::UnicodeUTF8));
        checkBox_EngineSteerLeft->setText(QApplication::translate("MainWindow", "LEFT", 0, QApplication::UnicodeUTF8));
        checkBox_EngineSteerArm->setText(QApplication::translate("MainWindow", "ARM", 0, QApplication::UnicodeUTF8));
        checkBox_EngineSteerCylinder->setText(QApplication::translate("MainWindow", "CYLINDER", 0, QApplication::UnicodeUTF8));
        lineEdit_SteerEngineRight->setText(QString());
        button_EngineSteer->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        qLed_EngineSteerRight->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_EngineSteerRight->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed_EngineSteerLeft->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_EngineSteerLeft->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed_EngineSteerArm->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_EngineSteerArm->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed_EngineSteerCylinder->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_EngineSteerCylinder->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("MainWindow", "Electromagnets", 0, QApplication::UnicodeUTF8));
        button_Electromagnets->setText(QApplication::translate("MainWindow", "ON", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Arch", 0, QApplication::UnicodeUTF8));
        checkBox_ArchEngineRight->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        checkBox_ArchEngineLeft->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        lineEdit_ArchEngineRight->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_ArchEngineLeft->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        button_Arch->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "SECURITY FUNCTIONS", 0, QApplication::UnicodeUTF8));
        button_StopAll->setText(QApplication::translate("MainWindow", "HALT", 0, QApplication::UnicodeUTF8));
        button_StopDriving->setText(QApplication::translate("MainWindow", "STOP DRIVING", 0, QApplication::UnicodeUTF8));
        button_StopArm->setText(QApplication::translate("MainWindow", "STOP ARM", 0, QApplication::UnicodeUTF8));
        button_StopCylinder->setText(QApplication::translate("MainWindow", "STOP CYLINDER", 0, QApplication::UnicodeUTF8));
        button_Calibration->setText(QApplication::translate("MainWindow", "Calib!", 0, QApplication::UnicodeUTF8));
        button_UpdateValues->setText(QApplication::translate("MainWindow", "Update!", 0, QApplication::UnicodeUTF8));
        button_PowerControl->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "MINING", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "UNLOADING", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "1) Close Cylinder", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "2) Set Arm position to 4", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "3) Start Cylinder", 0, QApplication::UnicodeUTF8));
        button_Mining_Initiate->setText(QApplication::translate("MainWindow", "INITIATE", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "4) Set Cylinder to 0", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "5) Mine & Drive", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "6) Mass mesurement", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "7) Set Arm position to 1", 0, QApplication::UnicodeUTF8));
        button_Unloading_Initiate->setText(QApplication::translate("MainWindow", "INITIATE", 0, QApplication::UnicodeUTF8));
        checkBox_Mining_CloseCylinder->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        checkBox_Mining_ArmPosition4->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        checkBox_Mining_StartCylinder->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        checkBox_Mining_SetCylinderTo0->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        checkBox_Mining_MiningDriving->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        checkBox_Mining_SetArmPosition1->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        checkBox_Mining_TensometerMass->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        button_Mining_CheckCylinderState->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        button_Mining_ArmPosition4->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        button_Mining_StartCylinder->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        button_Mining_SetCylinderTo0->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        button_Mining_MiningDriving->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        button_Mining_TensometerMass->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        button_Mining_ArmPositionTo1->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        checkBox_Unloading_CheckArmPosition->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        checkBox_Unloading_RotateCylinder->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        button_Unloading_CloseCylinder->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "3) Open Cylinder", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "2) Set Cylinder to 0", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "5) Rotate cylinder", 0, QApplication::UnicodeUTF8));
        checkBox_Unloading_OpenCylinder->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "1) Set Arm position to 1", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "4) Shake Cylinder", 0, QApplication::UnicodeUTF8));
        button_Unloading_OpenCylinder->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        checkBox_Unloading_SetArmPosition1->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        button_Unloading_ShakeCylinder->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        checkBox_Unloading_SetCylinderTo0->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        checkBox_Unloading_ShakeCylinder->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "6) Close Cylinder", 0, QApplication::UnicodeUTF8));
        checkBox_Unloading_CloseCylinder->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        button_Unloading_RotateCylinder->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        button_Unloading_SetArmPosition1->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "7) Check arm position", 0, QApplication::UnicodeUTF8));
        button_Unloading_CheckArmPosition->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        button_Unloading_SetCylinderTo0->setText(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        qLed_ArchEngineLeft->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_ArchEngineLeft->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        qLed_ArchEngineLeft_2->setToolTip(QApplication::translate("MainWindow", "Binary Led", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        qLed_ArchEngineLeft_2->setWhatsThis(QApplication::translate("MainWindow", "Led widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_22->setText(QApplication::translate("MainWindow", "MEASUREMENT", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "Power Control", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "Voltage [V]", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "Current [A] ", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "CALIBRATION", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "UPDATE STATE", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "TOTAL", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "NOW", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "MASS", 0, QApplication::UnicodeUTF8));
        button_StartAll->setText(QApplication::translate("MainWindow", "START", 0, QApplication::UnicodeUTF8));
        button_Teleoperation->setText(QApplication::translate("MainWindow", "TELEOPERATION", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "Cyl speed", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
