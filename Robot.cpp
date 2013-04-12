#include "Robot.h"
#include "drawArrow.h"
#include "IDrivingSystem.h"
#include <cmath>
#include <QString>
#include "battery.h"

#define START '#'

/////////constructor/////////////////
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

void Robot::SetPosition(double* p){
    md_position[0]=p[0];
    md_position[1]=p[1];
    md_position[2]=p[2];
    }

//////////Position - odometry
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


////////MAIN FEATURES//////////

///drive (v, t)
void Robot::Drive(double v, double t){
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

/////////////// <DO EDYCJI> ///////////////////////////
     QByteArray block;

     ///ramka komunikacyjna: id:11, arg1:cokolwiek, arg2:predkosc, arg3:czas
     block.append('#'); //
     block.append((QByteArray::number(11, 10)));   //ID
     block.append((QByteArray::number(0, 10)));   //arg1
     //1- prawo, 16-lewo //kierunek???
    // if(v>0) block.append(1);
    //    else block.append(16);


     int vel = static_cast<int>(v*256/5); //bo najfajniej się wtedy rusza
     int tm = static_cast<int>(t*256/5);

     block.append((QByteArray::number(vel, 10)));     //arg2
     block.append((QByteArray::number(tm, 10)));       //arg3

     //wyslij ramke
     socket->write(block);

     ///odpowiedz
     char* bl = new char[4];

     //wait to bytes to be written for 1s, else return
     if(!socket->waitForReadyRead(1000)) return;

     if(!socket->read(bl, 4)) return; //check if read
     if(bl[0]!='#') return;           //check start sign
     if(bl[1]!=(char)11)    return;          //check ID
     emit DrivenForward(v, t); ///nie ruszać tej linii!
     Robot::SetLinearVelocity(v);

     socket->flush(); //clean

     //wait to bytes to be written for 1s, else return
     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)11)    return;            //check ID

///////////////// </DO EDYCJI>  ///////////////////////////////////

     Robot::m_wheel[0].SetAngularVelocity(v/(2*PI*r0));
     Robot::m_wheel[1].SetAngularVelocity(v/(2*PI*r1));

     delete bl;

}


///Turn (angle, t)
void Robot::Turn(double angle, double t){
    //double v =  Robot::GetLinearVelocity();
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
    ///send a message
    std::cout<<"I have turned to an angle "<<angle<<std::endl;

    ///////////// <DO EDYCJI> //////////////////
     QByteArray block;

     //id:12, arg1-cokolwiek, arg2-predkosc, agr3-czas
     block.append('#'); //1
     block.append(QByteArray::number(12, 10));   //id //12 to int
     block.append(QByteArray::number(0,10)); //arg1

     //kierunek?
     //16- prawo, 1-lewo
     //if(a>0) block.append(16);
     //else block.append(1);

     int vel = (int)(10); //vel=10 fajnie dziala
     int tm = (int)(t*256/5);
     block.append(QByteArray::number(vel, 10));   //arg2
     block.append(QByteArray::number(tm, 10));     //arg3

     socket->write(block);
     socket->flush();

     char* bl = new char[4];
     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)12)    return;            //check ID

     emit Turned(a, t);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)12)    return;            //check ID

     //zwloka czasowa

      Robot::m_wheel[1].SetAngularVelocity(0);
      Robot::m_wheel[0].SetAngularVelocity(0);

    delete bl;
}


//void Robot::readResponse(){
//}


/////If connected to robot
void Robot::connected(){
    std::cout<<"connected\n";
}



/////Arm position
void Robot::SetArmPosition(POSITION pos) //6
 {
     m_arm.SetPosition(pos);

     //id 6, arg1-cokolwiek, arg2-pozycja, arg3 - cokolwiek
     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(6, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(pos, 10)));
     block.append((QByteArray::number(0, 10)));

       emit ArmPositionChanged(pos);

     char* bl = new char[4];
     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)6)    return;      //check ID

     emit ArmPositionChanged(pos);

     this->m_arm.SetPosition(pos);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)6)    return;       //check ID

     delete bl;
 }



 ///////Update values
 void Robot::updateValues(){
    //wszystkie zapytania
     QByteArray block;

     //BATTERY
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(1, 10))); ///akumulator
     block.append((QByteArray::number(0, 10)));
     socket->write(block);

     char* bl = new char[4];
     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     this->battery->SetVoltage((double)(((int)bl[3])/256*20)); //setvoltage
     this->battery->SetCurrent((double)(((int)bl[2])/256*1));  //setcurrent
     socket->flush();

     //CYLINDER CURRENT
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(2, 10))); ///akumulator
     block.append((QByteArray::number(0, 10)));
     socket->write(block);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     this->m_cylinder.SetCurrent(((int)bl[2])/256*1);
     socket->flush();

     //TENSOMETERS-MASS
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(3, 10))); ///akumulator
     block.append((QByteArray::number(0, 10)));
     socket->write(block);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     this->m_cylinder.SetWeight((int)(bl[2])/256*10);

     socket->flush();

     //TENSOMETERS-VALUES
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(4, 10))); ///akumulator
     block.append((QByteArray::number(0, 10)));

     socket->write(block);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     this->SetTensometer((int)(bl[2])/256);
     socket->flush();

     //ARM POSITION
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(5, 10)));
     block.append((QByteArray::number(0, 10)));

     socket->write(block);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     this->SetArmPosition(static_cast<POSITION>((int)(bl[2])));
     socket->flush();

     //ENGINE nr+dir+val
     for(int i=0; i<4; ++i){
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(6, 10)));
     block.append((QByteArray::number(i, 10)));

     socket->write(block);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     this->m_wheel[(int)(bl[2])].SetAngularVelocity((double)(bl[3])/256); // ??kierunek + nr silnika ??

     socket->flush();
     }

     //CYLINDER dir+val
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(7, 10))); ///akumulator
     block.append((QByteArray::number(0, 10)));

     socket->write(block);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     this->m_cylinder.SetEngineSpeed((int)bl[3]/255);
     socket->flush();

     //ENGINE IMPULSES
     for(int i=0; i<4; ++i){
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(8, 10)));
     block.append((QByteArray::number(i, 10))); ///akumulator

     socket->write(block);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     ///impulsy??
     socket->flush();
     }

     //ELECTROMAGNET
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(9, 10))); ///akumulator
     block.append((QByteArray::number(0, 10)));
     socket->write(block);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     bool val = true;
     //jaki jest warunek na true/false?
     this->m_cylinder.SetElectromagnet((val));
     socket->flush();


     //CYLINDER OPENED
     block.append('#');
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10))); ///akumulator
     block.append((QByteArray::number(10, 10)));
     block.append((QByteArray::number(0, 10)));
     socket->write(block);

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)1)    return;      //check ID

     int vl = true;
     //jaki warunek na true/false?
     this->m_cylinder.SetFlap(vl);
     socket->flush();

     delete bl;


     //////////////////////
     emit changedValues();
 }


///////Launch robot
 void Robot::StartAll(){

     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(10, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));

     emit StartedAll();

              char* bl = new char[4];
     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)10)    return;            //check ID

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)10)    return;            //check ID

    delete bl;
 }


 //////Engine steer     //2
void Robot::EngineSteer(int i, double w){

    int val = (int)(w*256/5);
    emit EngineSteered(i, w);
     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(2, 10)));
     block.append((QByteArray::number(i, 10)));
     block.append((QByteArray::number(val, 10)));
     block.append((QByteArray::number(0, 10)));

      char* bl = new char[4];


     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)2)    return;            //check ID


     emit EngineSteered(i, w);
     this->m_wheel[i].SetEngineSpeed(w);

     delete bl;
 }


 //wysteruj silniki jezdne brak

 //////Engine stop //3
void Robot::EngineStop(int i){
     emit EngineStopped(i);
     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(4, 10)));
     block.append((QByteArray::number(i, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));

                   char* bl = new char[4];
     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=((char)4))    return;            //check ID
     socket->flush();

     this->m_wheel[i].SetEngineSpeed(0);
     emit EngineStopped(i);
 }


 //////// Set cylinder to position 0 //4

void Robot::CylinderToZero(int w){
    emit CylinderSetToZero(w);
     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(5, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(w, 10)));
     block.append((QByteArray::number(0, 10)));
     emit CylinderSetToZero(w);

     char* bl = new char[4];

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)5)    return;            //check ID

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)5)    return;            //check ID

     delete bl;

     this->m_arm.SetPosition(a);
     emit CylinderSetToZero(w);
 }
 //5


void Robot::SetElectromagnet(bool On) {
    emit Electromagnet(On);
     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(7, 10)));
     block.append((QByteArray::number(On, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));

     char* bl = new char[4];
     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)7)    return;            //check ID

    this->m_cylinder.SetElectromagnet(On);
     emit Electromagnet(On);
     delete bl;
 }
 //7


void Robot::TeleoperationOn(){

     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(8, 10)));
     block.append((QByteArray::number(1, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));

     emit Teleoperation();
     //this->teleoperated=true;

     char* bl = new char[4];


     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)8)    return;            //check ID

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)8)    return;            //check ID

     this->teleoperated=true;
     emit TeleoperationOn();

     delete bl;
 }
 //8


void Robot::StopAll(){

     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(9, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));


     ///////////set all values to 0

     emit StoppedAll();
 }


void Robot::StopDriving(){

    QByteArray block;
     block.append('#');
     block.append((QByteArray::number(14, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));

     emit StoppedDriving();


     char* bl = new char[4];

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)14)    return;            //check ID


     ///stop wheels
     for (int i=0; i<4; ++i)
        this->m_wheel[i].SetEngineSpeed(0);
     emit StoppedDriving();

     delete bl;
 }

 //14
 //zadeklarowane już{}
 //15

 void Robot::CylinderMove(double w){

     QByteArray block;
     block.append('#');
     block.append(QByteArray::number(16, 10));
     block.append(QByteArray::number(0, 10));
     int val = (int)(256/5*w);
     block.append(QByteArray::number(val, 10));
     block.append(QByteArray::number(0, 10));

     char* bl = new char[4];
     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=16)    return;            //check ID


    this->m_cylinder.SetEngineSpeed(w);
     emit CylinderMoved(w);
     delete bl;
 }
 //16

 void Robot::Calibrate(){

     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(17, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));
     block.append((QByteArray::number(0, 10)));

     char* bl = new char[4];

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)17)    return;            //check ID

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)17)    return;            //check ID

     this->tensometer[0]=(double)bl[2]; //masa
     this->tensometer[1]=(double)bl[3]; //prad
     emit Calibrated();

     delete bl;
 }
 //17

 void Robot::CylinderToGround(double w){

     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(18, 10)));
     block.append((QByteArray::number(0, 10)));
     int val = (int)(w*256/5);
     block.append((QByteArray::number(val, 10)));
     block.append((QByteArray::number(0, 10)));

     char* bl = new char[4];

     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)2)    return;            //check ID

    this->SetArmPosition(b);
     emit CylinderSetToGround(w);

    delete bl;
 }
 //18

 void Robot::SetMaxCurrentVoltage(double U, double I){

     QByteArray block;
     block.append('#');
     block.append((QByteArray::number(19, 10)));
     block.append((QByteArray::number(0, 10)));
     int Uv = (int)(256*U/20);
     int Iv = (int)(256*I/20);

     block.append((QByteArray::number(Uv, 10)));
     block.append((QByteArray::number(Iv, 10)));

      char* bl = new char[4];
     if(!socket->waitForReadyRead(1000)) return;
     if(!socket->read(bl, 4)) return;   //check if read
     if(bl[0]!='#') return;             //check start sign
     if(bl[1]!=(char)19)    return;     //check ID


     ////cylinder
     this->m_cylinder.SetMaxCurrent(I);
     this->m_cylinder.SetMaxVoltage(U);

     /////wheels
     for(int i=0; i<4; ++i){
        this->m_wheel[i].SetEngineMaxCurrent(I);
        this->m_wheel[i].SetEngineVoltage(U);
     }

     //////arm
     this->m_arm.SetEngineMaxCurrent(I);
     this->m_arm.SetEngineMaxVoltage(U);

     emit CurrentVoltageSet(U, I);
     delete bl;

 }//19

 //pilnuj koniec brak
 //20
 void Robot::MassChange(double m){

    QByteArray block;
    block.append('#');
    block.append((QByteArray::number(21, 10)));
    block.append((QByteArray::number(0, 10)));
    int val = (int)(m*245/5);
    block.append((QByteArray::number(0, 10)));
    block.append((QByteArray::number(0, 10)));

     char* bl = new char[4];

    if(!socket->waitForReadyRead(1000)) return;
    if(!socket->read(bl, 4)) return;   //check if read
    if(bl[0]!='#') return;             //check start sign
    if(bl[1]!=(char)21)    return;            //check ID

    emit MassChanged(m);

    if(!socket->waitForReadyRead(1000)) return;
    if(!socket->read(bl, 4)) return;   //check if read
    if(bl[0]!='#') return;             //check start sign
    if(bl[1]!=(char)21)    return;            //check ID

    delete bl;
 }                   //21
