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
    void updateValues();
    void EngineSteer();                     //2
    //wysteruj silniki jezdne brak          //3
    void EngineStop();                      //4
    void CylinderToZero();                  //5
    void SetArmPosition();                  //6
    void SetElectromagnet() ;               //7
    void TeleoperationOn();                 //8
    void StopAll();                         //9
    void StartAll();                        //10
    //niestandardowej brak                  //13
    void StopDriving();                     //14
    //zadeklarowane już;                    //15
    void CylinderMove();                    //16
    void Calibrate();                       //17
    void CylinderToGround();                //18
    void SetMaxCurrentVoltage();            //19
    //pilnuj koniec brak                    //20
    void MassChange();                      //21

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
