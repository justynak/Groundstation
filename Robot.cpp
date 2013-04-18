#include "Robot.h"
#include "drawArrow.h"
#include "IDrivingSystem.h"
#include <cmath>
#include <QString>
#include "battery.h"

#define START '#'

//////////////////////////////////
//////     constructor    ////////
//////////////////////////////////

Robot::Robot(double x, double y, double a, QObject *parent){
            md_linearVelocity=md_angularVelocity=0;
            md_wheelTrack=1.0;
            for (int i=0; i<4; ++i)
                m_wheel[i] = Wheel(0,0.3);

            md_position = new double [3];
            md_position[0]=x;
            md_position[1]=y;
            md_position[2]=a;

            m_cylinder = Cylinder();
            m_arm = Arm();

            battery = new Battery();
            teleoperated=true;

            socket = new QTcpSocket(this);
            socket->connectToHost(QString("192.168.0.2"), 2000);
            connect(socket, SIGNAL(connected()), this, SLOT(connected()));

        }



/////////////////////////////////////
///////   Position - odometry  //////
/////////////////////////////////////
void Robot::SetPosition(double* p){
    md_position[0]=p[0];
    md_position[1]=p[1];
    md_position[2]=p[2];
    }

void Robot::SetPosition(double ds, double da){
    ///get the old position
    double* p_old= new double[3];

    for (int i=0; i<3; ++i)
        p_old[i] = Robot::GetPosition()[i];

    double a = p_old[2];
    double dx= ds * cos((a+da/2)*3.14/180);
    double dy= ds * sin((a+da/2)*3.14/180);

    ///add the dx, dy, da to the old position to get the new one
    double* p_new = new double [3];
        p_new[0]=dx+ p_old[0];
        p_new[1]=dy+ p_old[1];
        p_new[2]=da+ p_old[2];

        if (p_new[2]>=360) p_new[2]=(int)p_new[2]%360;
        if (p_new[2]<0) p_new[2]=360+p_new[2];

    Robot::SetPosition(p_new);

    std::cout<<"My new position is ["<<p_new[0]<<", "<<p_new[1]<<", "<<p_new[2]<<"]\n";
    delete [] p_old;
    delete [] p_new;
}





/////////////////////////////////////////////////////////////
////////////////////    SLOTS!!!!!    ///////////////////////
/////////////////////////////////////////////////////////////


///////////////////////
////////BASIC//////////
///////////////////////

//1 Update Values
void Robot::BasicChangeValues(){

    //BATTERY
    SendFrame(1,0, 1,0);
    char* bl = new char[4];
    bl = ReceiveFrame(1);
    this->battery->SetVoltage((double)(((int)bl[3])/256*20)); //setvoltage
    this->battery->SetCurrent((double)(((int)bl[2])/256*1));  //setcurrent
    socket->flush();

    //CYLINDER CURRENT
    SendFrame(1,0,2,0);
    bl = ReceiveFrame(1);
    this->m_cylinder.SetCurrent(((int)bl[2])/256*1);
    socket->flush();

    //TENSOMETERS-MASS
    SendFrame(1,0,3,0);
    bl= ReceiveFrame(1);
    this->m_cylinder.SetWeight((int)(bl[2])/256*10);
    socket->flush();

    //TENSOMETERS-VALUES
    SendFrame(1,0,4,0);
    bl= ReceiveFrame(1);
    this->SetTensometer((int)(bl[2])/256);
    socket->flush();

    //ARM POSITION
    SendFrame(1,0,5,0);
    bl = ReceiveFrame(1);
    this->SetArmPosition(static_cast<POSITION>((int)(bl[2])));
    socket->flush();

    //ENGINE nr+dir+val
    for(int i=0; i<4; ++i){
         SendFrame(1,0,6,i);
         bl = ReceiveFrame(1);
         this->m_wheel[(int)(bl[2])].SetAngularVelocity((double)(bl[3])/256); // ??kierunek + nr silnika ??
         socket->flush();
    }

    //CYLINDER dir+val
    SendFrame(1,0,7,0);
    bl = ReceiveFrame(1);
    this->m_cylinder.SetEngineSpeed((int)bl[3]/255);
    socket->flush();

    //ENGINE IMPULSES
    for(int i=0; i<4; ++i){
        SendFrame(1,0,8,i);
        bl = ReceiveFrame(1);
         ///impulsy??
        socket->flush();
    }

    //ELECTROMAGNET
    SendFrame(1,0,9,0);
    bl = ReceiveFrame(1);
    bool val = true;
    //jaki jest warunek na true/false?
    this->m_cylinder.SetElectromagnet((val));
    socket->flush();


    //CYLINDER OPENED
    SendFrame(1,0,10,0);
    bl = ReceiveFrame(1);
    int vl = true;
    //jaki warunek na true/false?
    this->m_cylinder.SetFlap(vl);
    socket->flush();

    delete bl;

    emit _BasicChangeValues();
}

//2 Steer Engine Arm/Cylinder //howto differ?
void Robot::BasicEngineSteer(int i, double w){

    int val = (int)(w*256/5);
    //emit EngineSteered(i, w);

    SendFrame(2, i, val,0);
    char* bl = new char[4];
    bl = ReceiveFrame(2);

    emit _BasicEngineSteer(i,w);
    this->m_wheel[i].SetEngineSpeed(w);

    delete bl;
 }

//3 Driving Steer Engine
void Robot::BasicEngineDrivingSteer(int i, double w){
    int val = (int)(w*256/5);
    //emit EngineSteered(i, w);
    SendFrame(3, i, val,0);
    char* bl = new char[4];
    bl = ReceiveFrame(2);

    emit _BasicEngineSteer(i,w);
    this->m_wheel[i].SetEngineSpeed(w);

    delete bl;

}

//4 0 Cylinder Position ARGS????
void Robot::BasicCylinderSetToZero(double w){
    int val = (int)(w*256/5);
    SendFrame(4,0,w,0);
    char* bl = new char[4];
    bl=ReceiveFrame(4);
    emit _BasicCylinderSetToZero(w);
    delete bl;
}

//5 Arm Position
void Robot::BasicArmPositionChange(POSITION pos)
 {
     m_arm.SetPosition(pos);

     SendFrame(6,0, (int)pos, 0 );
     emit ArmPositionChanged(pos);

     char* bl = new char[4];
     bl=ReceiveFrame(6);

     emit ArmPositionChanged(pos);
     this->m_arm.SetPosition(pos);
     bl=ReceiveFrame(6);

     delete bl;
 }

//6 Electromagnets
void Robot::BasicElectromagnet(bool on) {
    //emit Electromagnet(On);
    SendFrame(6, 0, (int)on, 0);

    char* bl = new char[4];
    bl= ReceiveFrame(6);

    this->m_cylinder.SetElectromagnet(On);
    emit Electromagnet(On);
    delete bl;
 }

//7 Go Forward  DIRECTION
void Robot::BasicDriveForward(double v, double t){
    ///values needed to calculate teh new angular velocities of the wheels
    double r0 = Robot::m_wheel[0].GetRadius();
    double r1 = Robot::m_wheel[1].GetRadius();
    double wl = Robot::m_wheel[0].GetAngularVelocity();
    double wr = Robot::m_wheel[1].GetAngularVelocity();
    double v_old = Robot::GetLinearVelocity();
    std::cout<<"I have driven with the velocity "<<v<<" for time "<<t<<std::endl;

    double ds = v*t;
    double da=0.0;
    Robot::SetPosition(ds,da);

     int vel = static_cast<int>(v*256/5); //bo najfajniej się wtedy rusza
     int tm = static_cast<int>(t*256/5);
     SendFrame(7, 0, vel, tm);
     char* bl = new char[4];
     bl = ReceiveFrame(7);

     emit _BasicDriveForward(vel,tm);
     Robot::SetLinearVelocity(v);
     socket->flush();
     bl = ReceiveFrame(11);

     Robot::m_wheel[0].SetAngularVelocity(v/(2*PI*r0));
     Robot::m_wheel[1].SetAngularVelocity(v/(2*PI*r1));
     delete bl;

}

//8 Turn DIRECTION
void Robot::BasicTurn(double angle, double t){
    double w = Robot::GetAngularVelocity();
    double rl = Robot::m_wheel[0].GetRadius();
    double rr = Robot::m_wheel[1].GetRadius();
    double d = Robot::GetWheelTrack();
    double wl = Robot::m_wheel[0].GetAngularVelocity();
    double wr = Robot::m_wheel[1].GetAngularVelocity();

    ///check the angle and then decide which angular velocity changes
   if (angle>0) {
       ///calculate the value
       //Robot::m_wheel[0].SetAngularVelocity(w*d/rr+wr+a/t);
       Robot::m_wheel[0].SetAngularVelocity(angle/t/100);
   }
   else {
       ///calculate the value
       //Robot::m_wheel[1].SetAngularVelocity(-wl+w*d/rl+a/t);
       Robot::m_wheel[1].SetAngularVelocity(-angle/t/100);
   }

    ///temporary velocity while turning  - (v_left + v_right)/2
    double ds = (wl * rl + wr * rr)/2*t;
    double da=angle;

    ///change position
    Robot::SetPosition(ds,da);
    std::cout<<"I have turned to an angle "<<angle<<std::endl;

     int vel = (int)(10); //vel=10 fajnie dziala
     int tm = (int)(t*256/5);
     SendFrame(8,0, vel, tm);

     socket->flush();
     char* bl = new char[4];
     bl = ReceiveFrame(12);
     emit _BasicTurn(vel, tm);

     bl=ReceiveFrame(12);
     Robot::m_wheel[1].SetAngularVelocity(0);
     Robot::m_wheel[0].SetAngularVelocity(0);

     socket->flush();
     delete bl;
}

//9 Arch DOALL
void Robot::BasicTurnArc(){
    SendFrame(9, 0,0,0);
    char* bl = new char[4];
    bl = ReceiveFrame(9);
    delete bl;
}

///////////////////////////////
/////////----START-----////////
///////////////////////////////

//20 Start
 void Robot::StartAll(){

     SendFrame(20,0,0,0);
     char* bl = new char[4];
     bl=ReceiveFrame(20);
     emit _StartAll();
     delete bl;
 }


/////////////////////////////////
///////------/MINING----/////////
/////////////////////////////////

//30 Initiate   DOALL
 void Robot::MiningInitiate(){
    SendFrame(30,0,0,0);
    bl = new char[4];
    bl = ReceiveFrame(30);
    emit _MiningInitiate();
    delete bl;
 }

//31 Cylinder check
 void Robot::MiningCylinderState(bool opened){
     SendFrame(31,0,0,0);
     bl = new char[4];
     bl = ReceiveFrame(30);
     //opened
     emit _MiningCylinderState(opened);
     delete bl;
 }

//32 Arm Position 4
void Robot::MiningArmPosition4(){
    SendFrame(32,0,0,0);
    bl = new char[4];
    bl = ReceiveFrame(32);
    m_arm.SetPosition(d);
    emit _MiningArmPosition4();
    delete bl;
}

//33 Cylinder start
void Robot::MiningCylinderStart(){
    SendFrame(33,0,0,0);
    bl = new char[4];
    bl = ReceiveFrame(33);
    //started
    emit _MiningCylinderStart();
    delete bl;
}

//34 Calibration ///howto??
void Robot::MiningCalibration(){
    SendFrame(34,0,0,0);
    bl = new char[4];
    bl = ReceiveFrame(34);
    //started
    emit _MiningCalibration();
    delete bl;
}

//35 Lower to ground //wot??
void Robot::MiningCylinderToGround(double w){
    int val = (int)(w*256/5);
    SendFrame(35,0,val,0);
    bl = new char[4];
    bl = ReceiveFrame(35);
    //started
    emit _MiningCylinderToGround(w);
    delete bl;
}

//36 Power Control
void Robot::MiningPowerControl(double U, double I){
    SendFrame(34,0,0,0);
    bl = new char[4];
    bl = ReceiveFrame(34);
    //started
    emit _MiningCalibration();
    delete bl;

}

//37 Mining&Driving
void Robot::MiningDriving(){
}

//38 Mass measurement
void Robot::MiningTensometerMass(){
}

//39 Arm to go
void Robot::MiningArmPosition0(){
}

/////////////////////////////////////
//////--------UNLOADING--------//////
/////////////////////////////////////

//40 Init
void Robot::UnloadInitiate(){
}

//41 Arm pos 1
void Robot::UnloadArmPosition1(){
}

//42 Cylinder pos 0
void Robot::UnloadCylinderToZero(){
}

//43 Cylinder opening
void Robot::UnloadCylinderOpen(){
}

//44 Cylinder check
void Robot::UnloadCylinderState(){
}

//45 Cylinder shake
void Robot::UnloadCylinderShake(){
}

//46 Cylinder rotate
void Robot::UnloadCylinderRotate(double w){
}

//47 Cylider close
void Robot::UnloadCylinderClose(){
}

//48 Arm pos check
void Robot::UnloadArmPositionCheck(){
}

///////////////////////////////
///////----SECURITY------//////
///////////////////////////////

//101 Stop all engines
void Robot::SecurityAllEnginesStop(){
}

//102 Stahp all driving eng.
void Robot::SecurityDrivingEnginesStop(){
}

//103 Stop arm eng
void Robot::SecurityArmEngineStop(){
}

//104 Stop cylinder eng
void Robot::SecurityCylinderEngineStop(){
}

//105 Autonomy
void Robot::SecurityAutonomy(){
}


 void Robot::SendFrame(int id, int arg1, int arg2, int arg3){
     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(id, 10)));
     block.append((QByteArray::number(arg1, 10)));
     block.append((QByteArray::number(arg2, 10)));
     block.append((QByteArray::number(arg3, 10)));

     socket->write(block);
 }

 char* Robot::ReceiveFrame(int id){
     char* bl = new char[4];
     if(!socket->waitForReadyRead(1000)) {delete bl; return 0;}
     if(!socket->read(bl, 4)) {delete bl; return 0;}   //check if read
     if(bl[0]!='#') {delete bl; return 0;}             //check start sign
     if(bl[1]!=(char)id)    {delete bl; return 0 ;}
     return bl;

 }

 /////If connected to robot
 void Robot::connected(){
     std::cout<<"connected\n";
 }
