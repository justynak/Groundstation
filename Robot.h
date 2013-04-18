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
       ////BASIC SEQ.
        void _BasicChangeValues();                       //1
        void _BasicEngineSteer(int i, double w);         //2
        void _BasicEngineDrivingSteer(int i, double w);  //3    ARG?
        void _BasicCylinderSetToZero(double w);          //4
        void _BasicArmPositionChange(POSITION pos);      //5
        void _BasicElectromagnetSet(bool on);            //6
        void _BasicDriveForward(double v, double t);     //7
        void _BasicTurn(double a, double t);             //8
        void _BasicTurnArc();                            //9    ARG?

        ///START SEQ.
        void StartedAll();                               //20


        ////MINING SEQ
        void _MiningInitiate();                          //30
        void _MiningCylinderState(bool opened);          //31        ARG?
        void _MiningArmPosition4();                      //32
        void _MiningCylinderStart();                     //33
        void _MiningCalibration() ;                      //34
        void _MiningCylinderToGround();                  //35
        void _MiningPowerControl();                      //36
        void _MiningDriving();                           //37
        void _MiningTensometerMass(double mass);         //38
        void _MiningArmPosition0();                      //39

        ///UNLOAD SEQ
        void _UnloadInitiate();                          //40
        void _UnloadArmPosition1();                      //41
        void _UnloadCylinderToZero();                    //42
        void _UnloadCylinderOpen();                      //43
        void _UnloadWheelState(bool opened);             //44
        void _UnloadCylinderShake();                     //45 HARLEM SHAKE LEL
        void _UnloadWheelRotate();                       //46
        void _UnloadCylinderClose();                     //47
        void _UnloadArmPositionCheck();                  //48    ARG?


        ///SECURITY SEQ
        void _SecurityAllEnginesStop();                  //101
        void _SecurityDrivingEnginesStop();              //102
        void _SecurityArmEngineStop();                   //103
        void _SecurityCylinderEngineStop();              //104
        void _SecurityAutonomy();                        //105






public slots:

        ////BASIC SEQ.
         void BasicChangValues();                         //1
         void BasicEngineSteer(int i, double w);          //2
         void BasicEngineDrivingSteer(int i, double w);   //3    ARG?
         void BasicCylinderSetToZero(double w);           //4
         void BasicArmPositionChange(POSITION pos);       //5
         void BasicElectromagnet(bool on);                //6
         void BasicDriveForward(double v, double t);      //7
         void BasicTurn(double a, double t);              //8
         void BasicTurnArc();                             //9    ARG?

         ///START SEQ.
         void StartAll();                                 //20


         ////MINING SEQ
         void MiningInitiate();                           //30
         void MiningCylinderState(bool opened);           //31        ARG?
         void MiningArmPosition4();                       //32
         void MiningCylinderStart();                      //33
         void MiningCalibration() ;                       //34
         void MiningCylinderToGround();                   //35
         void MiningPowerControl();                       //36
         void MiningDriving();                            //37
         void MiningTensometerMass(double mass);          //38
         void MiningArmPosition0();                       //39

         ///UNLOAD SEQ
         void UnloadInitiate();                           //40
         void UnloadArmPosition1();                       //41
         void UnloadCylinderToZero();                     //42
         void UnloadCylinderOpen();                       //43
         void UnloadWheelState(bool opened);              //44
         void UnloadCylinderShake();                      //45 HARLEM SHAKE LEL
         void UnloadWheelRotate();                        //46
         void UnloadCylinderClose();                      //47
         void UnloadArmPositionCheck();                   //48    ARG?


         ///SECURITY SEQ
         void SecurityAllEnginesStop();                   //101
         void SecurityDrivingEnginesStop();               //102
         void SecurityArmEngineStop();                    //103
         void SecurityCylinderEngineStop();               //104
         void SecurityAutonomy();                         //105


};

#endif // ROBOT_H
