#include "Robot.h"
#include "drawArrow.h"
#include "IDrivingSystem.h"
#include <cmath>
#include <QString>
#include "battery.h"
#include <QMessageBox>

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
            state=BASIC;

            socket = new QTcpSocket(this);
            socket->connectToHost(QString("192.168.0.1"), 2000);
            connect(socket, SIGNAL(connected()), this, SLOT(connected()));
            connect(socket, SIGNAL(hostFound()), this, SLOT(connected()));
            connect(socket, SIGNAL(disconnected()), this, SLOT(not_connected()));
            bl=new char[4];
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

    bl = ReceiveFrame(1);
    if(bl==NULL) return;
    this->battery->SetVoltage((double)bl[3]); //setvoltage
    this->battery->SetCurrent((double)bl[2]);  //setcurrent
    std::cout<<"I answered!\n";
    socket->flush();

    //CYLINDER CURRENT
    SendFrame(1,0,2,0);
    bl = ReceiveFrame(1);
    if(bl==NULL) return;
    this->m_cylinder.SetCurrent((int)bl[2]);
    socket->flush();

    //TENSOMETERS-MASS //wartosc x1, wartosc x2???
    SendFrame(1,0,3,0);
    bl= ReceiveFrame(1);
    if(bl==NULL) return;
    this->m_cylinder.SetWeight((int)(bl[2]));
    socket->flush();

    //TENSOMETERS-VALUES
    SendFrame(1,0,4,0);
    bl= ReceiveFrame(1);
    if(bl==NULL) return;
    this->SetTensometer((int)bl[2]);
    socket->flush();

    //ARM POSITION
    SendFrame(1,0,5,0);
    //
    bl = ReceiveFrame(1);
    if(bl==NULL) return;
    this->m_arm.SetPosition(static_cast<POSITION>(bl[1]));
    socket->flush();


    //ENGINE nr+dir+val
    for(int i=0; i<2; ++i){
        ///1 4 bity - silnik
         SendFrame(1,0,6,i);
         bl = ReceiveFrame(1);
         if(bl[0]==0) {std::cout<<":("; return;}
         int dir=bl[1];
         //1-cylinder, 2-arm, 3,4-wheels
         switch(dir){
            case 20:{
             this->m_cylinder.SetEngineSpeed((double)bl[2]);
             this->m_cylinder.SetEngineDirection(1);
             break;}

            case 24:{
             this->m_cylinder.SetEngineSpeed((double)bl[2]);
             this->m_cylinder.SetEngineDirection(0);
             break;}

            case 36:{
             this->m_arm.SetEngineSpeed((double)bl[2]);
             this->m_arm.SetEngineDirection(0);

             break;}

            case 40:{
             this->m_arm.SetEngineSpeed((double)bl[2]);
             this->m_arm.SetEngineDirection(1);

             break;}

            case 52:{
             this->m_wheel[0].SetEngineSpeed((double)bl[2]);
             this->m_wheel[0].SetEngineDirection(0);

             break;}

            case 56:{
             this->m_wheel[0].SetEngineSpeed((double)bl[2]);
             this->m_wheel[0].SetEngineDirection(1);

             break;}

            case 68:{
             this->m_wheel[1].SetEngineSpeed((double)bl[2]);
             this->m_wheel[1].SetEngineDirection(0);

             break;}

            case 72:{
             this->m_wheel[1].SetEngineSpeed((double)bl[2]);
             this->m_wheel[1].SetEngineDirection(1);

             break;}

         }


    }
        // Wysterowany 1bit- lewy silnik w lewo, 3bit- lewy w prawo, 5bit- prawy w lewo, 7bit- prawy w lewo
         socket->flush();
         //std::cout<<"Agreed\n";


    //CYLINDER dir+val
    //1 -active, 2-closed
    SendFrame(1,0,7,0);
    bl = ReceiveFrame(1);
    if(bl==NULL) return;
    this->m_cylinder.SetEngineSpeed((int)bl[3]);
    socket->flush();

    //ENGINE IMPULSES
    for(int i=0; i<4; ++i){
        SendFrame(1,0,8,i);
        bl = ReceiveFrame(1);
        if(bl==NULL) return;
         ///impulsy??
        socket->flush();
    }

    //ELECTROMAGNET
    SendFrame(1,0,9,0);
    bl = ReceiveFrame(1);
    bool val = true;
    if(val==1)
        this->m_cylinder.SetElectromagnet(false);
    else if (val==2)
        this->m_cylinder.SetElectromagnet(true);
    else return;
    socket->flush();

    //CYLINDER OPENED
    SendFrame(1,0,10,0);
    bl = ReceiveFrame(1);
    int vl = bl[1];
    if(vl==1) this->m_cylinder.Open(false);
    if (vl==2) this->m_cylinder.Open(true);
    //else return;
    socket->flush();

    emit _BasicChangeValues();
}

//2 Steer Engine Arm/Cylinder //1-cylinder, 2-arm, 3,4-wheels
void Robot::BasicEngineSteer(int i, double w){
    //lewy w lewo przod 3*16+4 = 52
    //lewy w prawo 3*16+8=56
    //prawy w lewo 68
    //prawy w prawo 72
    int dir;

    switch(i){
    case 1: {
        if(w>0) dir=20;
        else dir = 24;
        break;}
    case 2: {
        if(w>0) dir=36;
        else dir=40;
        break;}
    case 3: {
        if(w>0) dir=52;
        else dir=56;
        break;}
    case 4: {
        if(w>0) dir = 68;
        else dir=72;
        break;}
    }

    int val = (int)(w);
    if(val<0) val=val*(-1);
    SendFrame(2, dir, val,0);

    bl = ReceiveFrame(2);
    if(bl!=NULL) std::cout<<"OK";

    switch(bl[2]){
        case 20: {m_cylinder.SetEngineSpeed((double)bl[3]); m_cylinder.SetEngineDirection(0); break;}
        case 24: {m_cylinder.SetEngineSpeed((double)bl[3]); m_cylinder.SetEngineDirection(1); break;}
        case 36: {m_arm.SetEngineSpeed((double)bl[3]); m_arm.SetEngineDirection(0); break;}
        case 40:  {m_arm.SetEngineSpeed((double)bl[3]); m_arm.SetEngineDirection(1); break;}
        case 52: {m_wheel[0].SetEngineSpeed((double)bl[3]); m_wheel[0].SetEngineDirection(0); break;}
        case 56: {m_wheel[0].SetEngineSpeed((double)bl[3]); m_wheel[0].SetEngineDirection(1); break;}
        case 68: {m_wheel[1].SetEngineSpeed((double)bl[3]); m_wheel[0].SetEngineDirection(0); break;}
        case 72: {m_wheel[1].SetEngineSpeed((double)bl[3]); m_wheel[0].SetEngineDirection(1); break;}
    }

    emit _BasicEngineSteer(i,w);


 }

//3 Driving Steer Engine
void Robot::BasicEngineDrivingSteer(int i, double w){
    int val = (int)(w);
    int dir;
    switch(i){
        case 1: {
        if(w>0)
            dir=52;
        else
            dir=56;
        break;}
        case 2: {
            if(w>0)
                dir=68;
            else
                dir=72;
        break;
        }
    }

    if(w<0) val=val*(-1);
    SendFrame(3, dir, val,0);

    bl = ReceiveFrame(2);
    switch(bl[2]){
    case 52: {m_wheel[0].SetEngineSpeed((double)bl[3]); m_wheel[0].SetEngineDirection(0); break;}
    case 56: {m_wheel[0].SetEngineSpeed((double)bl[3]); m_wheel[0].SetEngineDirection(1); break;}
    case 68: {m_wheel[1].SetEngineSpeed((double)bl[3]); m_wheel[0].SetEngineDirection(0); break;}
    case 72: {m_wheel[1].SetEngineSpeed((double)bl[3]); m_wheel[0].SetEngineDirection(1); break;}
    }

    this->m_wheel[i].SetEngineSpeed((double)bl[3]);
    emit _BasicEngineDrivingSteer(i, double(bl[3]));

}

//4 0 Cylinder
void Robot::BasicCylinderSetToZero(double w){
    int val = (int)(w*255/5);
    SendFrame(4,0,w,0);

    bl=ReceiveFrame(4);
    emit _BasicCylinderSetToZero(w);

}

//5 Arm Position
void Robot::BasicArmPositionChange(POSITION pos)
 {

     SendFrame(6,0, (int)pos, 0 );
     emit _BasicArmPositionChange(pos);

     bl=ReceiveFrame(6);
     this->m_arm.SetPosition(static_cast<POSITION>(bl[2]));
     bl=ReceiveFrame(6);


 }

//6 Electromagnets
void Robot::BasicElectromagnetSet(bool on) {
    //emit Electromagnet(On);
    SendFrame(6, 0, (int)on, 0);

    bl= ReceiveFrame(6);
    this->m_cylinder.SetElectromagnet((bool)bl[2]);
    emit _BasicElectromagnetSet((bool)bl[2]);

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

     int vel = static_cast<int>(250*v); //bo najfajniej się wtedy rusza
     int tm = static_cast<int>(80*t);
     //if(vel)
     //10 - lewo, 01 - prawo
     //16 - przod, 1 - tyl
     int dir;
     if(vel>0) dir=16;
     else {dir=1;  vel=vel*(-1);}
     SendFrame(7, dir, vel, tm);

     bl = ReceiveFrame(7);

     emit _BasicDriveForward((double)bl[2],(double)bl[3]);

     this->SetLinearVelocity(v);
     socket->flush();
     bl = ReceiveFrame(11);

     Robot::m_wheel[0].SetAngularVelocity(v/(2*PI*r0));
     Robot::m_wheel[1].SetAngularVelocity(v/(2*PI*r1));


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

    //0-100
     int vel = (int)(angle*8);
     int tm = (int)(t*80);
     int dir;
     if(vel>0){ dir=16;}
     else {dir=1;  vel=vel*(-1);}

     SendFrame(8,dir, vel, tm);

     socket->flush();

     bl = ReceiveFrame(12);
     emit _BasicTurn((double)bl[2], (double)bl[3]);

     bl=ReceiveFrame(12);
     Robot::m_wheel[1].SetAngularVelocity(0);
     Robot::m_wheel[0].SetAngularVelocity(0);

     socket->flush();

}

//lewy, prawy
void Robot::BasicTurnArc(bool dir1, bool dir2, double w1, double w2){
    //w2- czas
    //if(dir1)
    //SendFrame(9, dir,(int)(w1*255/5),(int)(w2*255/5));

    bl = ReceiveFrame(9);

}

/////////////////////////////////
/////////----START-----//////////
/////////////////////////////////

//20 Start
 void Robot::StartAll(){

     SendFrame(20,0,0,0);
     //
     //bl=ReceiveFrame(20);
     emit _StartAll();
     //
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
    this->SetState(MINING);

 }

//31 Cylinder check
 void Robot::MiningCylinderState(bool opened){

     SendFrame(31,0,0,0);
     bl = ReceiveFrame(30);
     //opened
     emit _MiningCylinderState(opened);

 }

//32 Arm Position 4
void Robot::MiningArmPosition4(){
    SendFrame(32,0,0,0);

    bl = ReceiveFrame(32);
    m_arm.SetPosition(d);
    emit _MiningArmPosition4();

}

//33 Cylinder start
void Robot::MiningCylinderStart(){
    SendFrame(33,0,0,0);

    bl = ReceiveFrame(33);
    //started
    emit _MiningCylinderStart();

}

//34 Calibration
void Robot::MiningCalibration(){
    SendFrame(34,0,0,0);

    bl = ReceiveFrame(34);
    //started
    emit _MiningCalibration();

}

//35 Lower to ground
void Robot::MiningCylinderToGround(double w){
    int val = (int)(w*255/5);
    SendFrame(35,0,val,0);

    bl = ReceiveFrame(35);
    //started
    emit _MiningCylinderToGround(w);

}

//36 Power Control
void Robot::MiningPowerControl(double U, double I){
    int u = (int)(U*255/5);
    int i = (int)(I*255/5);

    SendFrame(36,0,i,u);

    bl = ReceiveFrame(36);

    SetMaxCurrentVoltage(U,I);
    emit _MiningPowerControl(U,I);


}

//37 Mining&Driving //args???
void Robot::MiningDriving(){
    SendFrame(37,0,0,0);

    bl = ReceiveFrame(37);
    //started
    emit _MiningDriving();
}

//38 Mass measurement
void Robot::MiningTensometerMass(){
    SendFrame(38,0,0,0);

    bl = ReceiveFrame(38);
    if(bl==NULL) return;
    double mass = bl[1];
    //m_cylinder.AddMass(w);
    m_cylinder.SetWeight(mass);
    emit _MiningTensometerMass();
}

//39 Arm to go
void Robot::MiningArmPosition1(){
    SendFrame(39,0,0,0);

    bl = ReceiveFrame(39);
    m_arm.SetPosition(a);
    emit _MiningArmPosition1();
    this->SetState(BASIC);

}

/////////////////////////////////////
//////--------UNLOADING--------//////
/////////////////////////////////////

//40 Init
void Robot::UnloadInitiate(){
    SendFrame(40,0,0,0);

    bl = ReceiveFrame(40);
    emit _UnloadInitiate();
    this->SetState(UNLOADING);

}

//41 Arm pos 1
void Robot::UnloadArmPosition1(){
    SendFrame(41,0,0,0);

    bl = ReceiveFrame(41);
    m_arm.SetPosition(b);
    emit _UnloadArmPosition1();

}

//42 Cylinder pos 0
void Robot::UnloadCylinderToZero(double w){
    int val = (int)(w*255/5);
    SendFrame(42,0,val,0);

    bl = ReceiveFrame(42);
    //started
    emit _UnloadCylinderToZero(w);

}

//43 Cylinder opening //args wat
void Robot::UnloadCylinderOpen(){
    SendFrame(43,0,0,0);

    bl = ReceiveFrame(43);
    //ch state
    emit _UnloadCylinderOpen();

}

//44 Cylinder check //wat
void Robot::UnloadCylinderState(bool opened){
    SendFrame(44,0,(int)opened,0);

    bl = ReceiveFrame(44);
    //opened
    emit _UnloadCylinderState(opened);

}

//45 Cylinder shake //shake
void Robot::UnloadCylinderShake(){
    SendFrame(45,0,0,0);

    bl = ReceiveFrame(44);
    emit _UnloadCylinderShake();
    //shake...

}

//46 Cylinder rotate //rotate
void Robot::UnloadCylinderRotate(double angle, double w){
    int val = (int)(angle*255/5);
    SendFrame(46,0,val,0);

    bl = ReceiveFrame(46);
    emit _UnloadCylinderRotate(angle, w);

}

//47 Cylider close
void Robot::UnloadCylinderClose(){
    SendFrame(47,0,0,0);

    bl = ReceiveFrame(47);
    //ch state
    emit _UnloadCylinderClose();

}

//48 Arm pos check //wat
void Robot::UnloadArmPositionCheck(){
    SendFrame(48,0,8,0);

    bl = ReceiveFrame(48);
    if (bl==NULL) return;
    if(bl[2]!= (char)1)
        BasicArmPositionChange(b);
    emit _UnloadArmPositionCheck();

    this->SetState(BASIC);
}

///////////////////////////////
///////----SECURITY------//////
///////////////////////////////

//101 Stop all engines
void Robot::SecurityAllEnginesStop(){
    SendFrame(101,0,0,0);

    bl = ReceiveFrame(101);
    for(int i=0; i<2; ++i){
        m_wheel[i].Stop();
    }
    m_arm.Stop();
    m_cylinder.Stop();

    emit _SecurityAllEnginesStop();

}

//102 Stahp all driving eng.
void Robot::SecurityDrivingEnginesStop(){
    SendFrame(102,0,0,0);

    bl = ReceiveFrame(102);
    for(int i=0; i<2; ++i){
        m_wheel[i].Stop();
    }
    emit _SecurityDrivingEnginesStop();

}

//103 Stop arm eng
void Robot::SecurityArmEngineStop(){
    SendFrame(103,0,0,0);

    bl = ReceiveFrame(103);
    m_arm.Stop();
    emit _SecurityArmEngineStop();

}

//104 Stop cylinder eng
void Robot::SecurityCylinderEngineStop(){
    SendFrame(104,0,0,0);

    bl = ReceiveFrame(104);
    m_cylinder.Stop();
    emit _SecurityCylinderEngineStop();

}

//105 `Autonomy //wat
void Robot::SecurityAutonomy(){
    SendFrame(105,0,0,0);

    bl = ReceiveFrame(105);
    if(bl==NULL) return;
    if(bl[2]!=(char)1)
        emit _SecurityAutonomy();

    this->SetState(AUTONOMY);

}


 void Robot::SendFrame(int id, int arg1, int arg2, int arg3){
     QByteArray block;
     block.append('#');
     block.append((char)id);
     block.append((char)arg1);
     block.append((char)arg2);
     block.append((char)arg3);
     socket->write(block);
 }

 char* Robot::ReceiveFrame(int id){

     //if(!socket->waitForReadyRead(1000)) {    return 0;}
     //if(!socket->read(bl, 4)) {    return 0;}   //check if read
     socket->read(bl,4);
     //if(a[0]!='#') {    return 0;}             //check start sign

     for(int i=0; i<4; ++i)
         std::cout<<(int)(bl[i])<<"\t";
     std::cout<<"\n";
     //if(bl[1]!=(char)id)    {    return 0 ;}
     return bl;

 }

 void Robot::connected(){
     std::cout<<"Connected\n";
     QMessageBox msgBox;
     msgBox.setText("Connected");
     msgBox.exec();
     socket->flush();
 }

 void Robot::SetMaxCurrentVoltage(double U, double I){
     for(int i=0; i<2; ++i){
         m_wheel[i].SetEngineMaxCurrent(I);
         m_wheel[i].SetEngineMaxVoltage(U);
     }
     m_arm.SetEngineMaxCurrent(I);
     m_arm.SetEngineMaxVoltage(U);
     m_cylinder.SetMaxCurrent(I);
     m_cylinder.SetMaxVoltage(U);
 }

 void Robot::MiningLaunchAll(){
    //emisja sygnałów przy otrzymanych ramkach
   /*
     emit _MiningInitiate();
     emit _MiningCylinderState(on);
     emit _MiningArmPosition4();
     emit _MiningCylinderStart();
     emit _MiningCalibration();
     emit _MiningCylinderToGround(w);
     emit _MiningPowerControl(U,I);
     emit _MiningDriving();
     emit _MiningTensometerMass();
     emit _MiningArmPosition1();
     */

 }

 void Robot::UnloadLaunchAll(){
     //emisja sygnałów przy otrzymanych ramkach
     /*
     emit _UnloadInitiate();
     emit _UnloadArmPosition1();
     emit _UnloadCylinderToZero(w);
     emit _UnloadCylinderOpen();
     emit _UnloadCylinderState(on);
     emit _UnloadCylinderShake();
     emit _UnloadCylinderRotate(alfa,w);
     emit _UnloadCylinderClose();
     emit _UnloadArmPositionCheck();
     */

 }

 void Robot::not_connected(){
     std::cout<<"Not Connected\n";
     QMessageBox msgBox;
     msgBox.setText("Not Connected");
     msgBox.exec();
 }
