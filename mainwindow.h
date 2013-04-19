#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include "Robot.h"
#include "drawArrow.h"
//#include <joystick.h>

#ifdef R
#undef R
#endif

#ifdef L
#undef L
#endif

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<opencv/cv.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Robot* robot;
    void initialize();


public slots:
    void BasicChangeValues();                        //1
    void BasicEngineSteer(int i, double w);          //2
    void BasicEngineDrivingSteer(int i, double w);   //3
    void BasicCylinderSetToZero(double w);           //4
    void BasicArmPositionChange(POSITION pos);       //5
    void BasicElectromagnetSet();                //6
    void BasicDriveForward(double v, double t);      //7
    void BasicTurn(double a, double t);              //8
    void BasicTurnArc();//9    ARG?

    ///START SEQ.
    void StartAll();                                 //20

    ////MINING SEQ
    void MiningInitiate();                           //30
    void MiningCylinderState(bool opened);           //31     ARG?
    void MiningArmPosition4();                       //32
    void MiningCylinderStart();                      //33
    void MiningCalibration() ;                       //34
    void MiningCylinderToGround(double w);           //35
    void MiningPowerControl(double U, double I);     //36
    void MiningDriving();                            //37
    void MiningTensometerMass();                     //38
    void MiningArmPosition1();                       //39

    ///UNLOAD SEQ
    void UnloadInitiate();                           //40
    void UnloadArmPosition1();                       //41
    void UnloadCylinderToZero(double w);             //42
    void UnloadCylinderOpen();                       //43
    void UnloadCylinderState(bool opened);           //44
    void UnloadCylinderShake();                      //45
    void UnloadCylinderRotate(double angle, double w);//46
    void UnloadCylinderClose();                      //47
    void UnloadArmPositionCheck();                   //48    ARG?

    ///SECURITY SEQ
    void SecurityAllEnginesStop();                   //101
    void SecurityDrivingEnginesStop();               //102
    void SecurityArmEngineStop();                    //103
    void SecurityCylinderEngineStop();               //104
    void SecurityAutonomy();                         //105

    void updateCamImage();
    void updateTime();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
    QPixmap imgUp;
    QPixmap imgSide;
    QPixmap imgMap;
    QPixmap imgSmall;
    void paintEvent(QPaintEvent *);
    //bool x11Event(XEvent *e);
    //Joystick* joy;
    QTimer* t;
    QTimer* t_counter;
    cv::VideoCapture cam;


};


#endif // MAINWINDOW_H
