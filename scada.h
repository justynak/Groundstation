 #ifndef SCADA_H
#define SCADA_H

#include "ui_scada.h"
#include "drawArrow.h"
#include "Robot.h"
#include<QTimer>
#include <QMainWindow>
#include <QPixmap>
#include <QPaintEvent>
#include<QImage>





namespace Ui {
    class SCADA;
}

class SCADA : public QWidget
{
    Q_OBJECT
    
public:
    explicit SCADA(QWidget *parent = 0);
    //SCADA(QWidget *parent=)
    ~SCADA();
    void paintEvent(QPaintEvent *);
    Robot* robot;
    void initialize();

    
private:
    Ui::SCADA *ui;
    QPixmap qpixUp;
    QPixmap qpixSide;
    //cv::VideoCapture cam;
    QImage image;
    QTimer* tcam;
    QTimer* tup;

public slots:
    void UpdateValues();
    void EngineSteer(int i, double w);                     //2
    //wysteruj silniki jezdne brak               //3
    void EngineStop(int i);                      //4
    void CylinderToZero(double w);                       //5
    void ArmPosition(POSITION pos);           //6
    void SetElectromagnet(bool on) ;                    //7
    void TeleoperationOn();                      //8
    void StopAll();                              //9
    void StartAll();                            //10
    void Drive(double v, double t);       //11
    void Turn(double angle, double t);    //12
    //niestandardowej brak                      //13
    void StopDriving();                         //14
    void Dig();                                 //15
    void CylinderMove(double w);                        //16
    void Calibrate();                           //17
    void CylinderToGround(double w);                    //18
    void SetMaxCurrentVoltage(double U, double I);                //19
    //pilnuj koniec brak                        //20
    void MassChange(double m);                         //21

    void updateImageCam();



};

#endif // SCADA_H
