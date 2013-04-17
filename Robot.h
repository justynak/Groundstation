/// |------------------------------------------------------------------------------------------------|
/// |                                                                                                |
/// |               Class Robot - describes the whole Lunabot, It contains:                          |
/// |           *Position [x, y, alpha]                                                              |
/// |           *Descend the methods from IDiggingSystem and IDriving system                         |                                                        |
/// -------------------------------------------------------------------------------------------------|
/// |               The DiggingSystem can                                                            |
/// |           *Do what both system are written for                                                 |
/// |           *Go to lunabin and to the mining spot                                                |
/// |           *Avoid obstacles on the way to and from lunabins and mining spot                     |
/// |           *Give its posiiton                                                                   |
/// |           *Go to a position                                                                    |
/// |------------------------------------------------------------------------------------------------|

#ifndef ROBOT_H
#define ROBOT_H

#include "IDiggingSystem.h"
#include "IDrivingSystem.h"
#include "battery.h"
#include <cstdlib>
#include <QPixmap>
#include <QObject>
#include <QTcpSocket>


class Robot : public IDiggingSystem, public IDrivingSystem
{

    Q_OBJECT
    public:
        ///Constructor: Robot ready to go in a position of (x,y,a)
        explicit Robot(double x=0, double y=0, double a=0, QObject *parent=0);

        void SetPosition(double da, double ds); //
        void SetPosition(double* p);

        double GetWheelVelocity(int i){return m_wheel[i].GetAngularVelocity();}
        POSITION GetArmPosition(){return(m_arm.GetPosition()) ;}
        double GetCylinderWeight(){return(m_cylinder.GetWeight()) ;}

        double GetBatteryCurrent(){return battery->GetCurrent();}
        double GetBatteryVoltage(){return battery->GetVoltage();}

        double GetEngineCurrent(int i){return m_wheel[i].GetEngineCurrent();}
        double GetEngineSpeed(int i){return m_wheel[i].GetEngineSpeed();}

        double GetCylinderSpeed(){return m_cylinder.GetEngineSpeed();}
        double GetElectromagnet(){return m_cylinder.IsElectroMagnetOn();}

        double GetTensometer(){return tensometer[1];}
        void SetTensometer(double t){tensometer[1]=t;}

        double GetMass(){return m_cylinder.GetWeight();}

        bool IsTeleoperated(){return teleoperated;}

        virtual ~Robot(){}

        char* ReceiveFrame(int id);
        void SendFrame(int id, int arg1, int arg2, int arg3);



private:
        QTcpSocket* socket;
        double tensometer[2];
        Battery* battery;
        bool teleoperated;



signals:
        void changedValues();
        void EngineSteered(int i, double w);  //2 mainwindow
     //wysteruj silniki jezdne brak //3
        void EngineStopped(int i);  //4  //
        void CylinderSetToZero(double w);   //5
        void ArmPositionChanged(POSITION pos);  //6 //mainwindow
        void Electromagnet(bool on);     //7
        void Teleoperation();       //8 //mainwindow
        void StoppedAll();          //9 //mainwindow
        void StartedAll();          //10 //mainwindow
        void DrivenForward(double v, double t);       //11 //mainwindow-key
        void Turned(double a, double t);              //12 //mainwindow-key
        //niestandardowej brak      //13
        void StoppedDriving();      //14   //mainwindow
        void Mined();               //15
        void CylinderMoved(double w);       //16
        void Calibrated();          //17   //mainwindow
        void CylinderSetToGround(double w); //18
        void CurrentVoltageSet(double U, double I);   //19 //mainwindow
        //pilnuj koniec brak        //20
        void MassChanged(double m);         //21




public slots:
        //void readResponse();
        void connected();
        void updateValues();
        void EngineSteer(int i, double w);           //2
        //wysteruj silniki jezdne brak               //3
        void EngineStop(int i);                      //4
        void CylinderToZero(int w);                  //5
        void SetArmPosition(POSITION pos);           //6
        void SetElectromagnet(bool On) ;             //7
        void TeleoperationOn();                      //8
        void StopAll();                              //9
        void StartAll();                             //10
        void Drive(double v=0.5, double t=0.2);           //11
        void Turn(double angle=30, double t=0.2);           //12
        //niestandardowej brak                       //13
        void StopDriving();                          //14
        //zadeklarowane już;                                  //15
        void CylinderMove(double w);                 //16
        void Calibrate();                            //17
        void CylinderToGround(double w);             //18
        void SetMaxCurrentVoltage(double U, double I);//19
        //pilnuj koniec brak                         //20
        void MassChange(double m);                   //21



};

#endif // ROBOT_H
