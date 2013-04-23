#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<QTimer>


int seconds = 0;
int mins = 10;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(close()));
    imgUp.load(":/images/dol.png");
    imgSide.load(":/images/bok.png");
    imgMap.load(":/images/map.png");
    imgSmall.load(":/images/small.png");

    signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(ui->button_Mining_SetCylinderTo0, 1);
    signalMapper->setMapping(ui->button_Mining_ArmPosition4, d);
    signalMapper->setMapping(ui->button_Mining_ArmPositionTo1, a);
    signalMapper->setMapping(ui->button_Unloading_SetArmPosition1, a);
    signalMapper->setMapping(ui->button_Unloading_SetCylinderTo0, 1);

    //joy = new Joystick();

   ////    IP CAM
    ////////  ZAMIAST 0 -> const std::string videoStreamAddress = "http://<username:password>@<ip_address>/video.cgi?.mjpg"; //czy w tym stylu
    cam.open(0);
    //////////////////////////////////

    t=new QTimer();
    t->start(50);
    t_counter=new QTimer();
    t_counter->start(1000);

    connect(t, SIGNAL(timeout()), this, SLOT(updateCamImage()));
    connect(t_counter, SIGNAL(timeout()), this, SLOT(updateTime()));

    //if(!(joy->init("/dev/input/js0"))){
    //    t = new QTimer(this);
    //    t->start();
    //    connect(t, SIGNAL(timeout()), this, SLOT(updateValues()));
    //}

    //disable checks
    ui->checkBox_ArchEngineLeft->setCheckable(false);
    ui->checkBox_ArchEngineRight->setCheckable(false);
    ui->checkBox_EngineSteerArm->setCheckable(false);
    ui->checkBox_EngineSteerCylinder->setCheckable(false);
    ui->checkBox_EngineSteerLeft->setCheckable(false);
    ui->checkBox_EngineSteerRight->setCheckable(false);

    ui->checkBox_Mining_ArmPosition4->setCheckable(false);
    ui->checkBox_Mining_CloseCylinder->setCheckable(false);
    ui->checkBox_Mining_MiningDriving->setCheckable(false);
    ui->checkBox_Mining_SetArmPosition1->setCheckable(false);
    ui->checkBox_Mining_SetCylinderTo0->setCheckable(false);
    ui->checkBox_Mining_StartCylinder->setCheckable(false);
    ui->checkBox_Mining_TensometerMass->setCheckable(false);

    ui->checkBox_Unloading_CheckArmPosition->setCheckable(false);
    ui->checkBox_Unloading_CloseCylinder->setCheckable(false);
    ui->checkBox_Unloading_OpenCylinder->setCheckable(false);
    ui->checkBox_Unloading_RotateCylinder->setCheckable(false);
    ui->checkBox_Unloading_SetArmPosition1->setCheckable(false);
    ui->checkBox_Unloading_SetCylinderTo0->setCheckable(false);
    ui->checkBox_Unloading_ShakeCylinder->setCheckable(false);

    //disable all buttons except start
    ui->button_Arch->setEnabled(false);
    ui->button_Calibration->setEnabled(false);
    ui->button_Electromagnets->setEnabled(false);
    ui->button_EngineSteer->setEnabled(false);
    ui->button_Mining_TensometerMass->setEnabled(false);
    ui->button_PowerControl->setEnabled(false);
    ui->button_StopAll->setEnabled(false);
    ui->button_StopArm->setEnabled(false);
    ui->button_StopCylinder->setEnabled(false);
    ui->button_StopDriving->setEnabled(false);
    ui->button_Teleoperation->setEnabled(false);

    ui->button_Mining_ArmPosition4->setEnabled(false);
    ui->button_Mining_CheckCylinderState->setEnabled(false);
    ui->button_Mining_Initiate->setEnabled(false);
    ui->button_Mining_MiningDriving->setEnabled(false);
    ui->button_Mining_SetCylinderTo0->setEnabled(false);
    ui->button_Mining_StartCylinder->setEnabled(false);
    ui->button_Mining_ArmPositionTo1->setEnabled(false);


    ui->button_Unloading_CheckArmPosition->setEnabled(false);
    ui->button_Unloading_CloseCylinder->setEnabled(false);
    ui->button_Unloading_Initiate->setEnabled(false);
    ui->button_Unloading_OpenCylinder->setEnabled(false);
    ui->button_Unloading_RotateCylinder->setEnabled(false);
    ui->button_Unloading_SetArmPosition1->setEnabled(false);
    ui->button_Unloading_SetCylinderTo0->setEnabled(false);
    ui->button_Unloading_ShakeCylinder->setEnabled(false);
    ui->button_UpdateValues->setEnabled(false);

}

void MainWindow::initialize(){
    //void BasicChangeValues();                        //1
    connect(ui->button_UpdateValues, SIGNAL(clicked()), this, SLOT(BasicChangeValues()));
    //void BasicEngineSteer(int i, double w); //2 + void BasicEngineDrivingSteer(int i, double w);   //3
    connect(ui->button_EngineSteer, SIGNAL(clicked()), this, SLOT(BasicEngineSteer()));
    //void BasicCylinderSetToZero(double w);           //4
    //?
    //void BasicArmPositionChange(POSITION pos);       //5
    //keyboard
    //void BasicElectromagnetSet(bool on);                //6
    connect(ui->button_Electromagnets, SIGNAL(clicked()), this, SLOT(BasicElectromagnetSet()));
    //void BasicDriveForward(double v, double t);      //7
    //keyboard
    //void BasicTurn(double a, double t);              //8
    //keyboard
    //void BasicTurnArc(bool dir1, bool dir3, double w1, double w2);//9
    connect(ui->button_Arch, SIGNAL(clicked()), this, SLOT(BasicTurnArc()));
    //void StartAll();                                 //20
    connect(ui->button_StartAll, SIGNAL(clicked()), this, SLOT(StartAll()));
    //void MiningInitiate();                           //30
    connect(ui->button_Mining_Initiate, SIGNAL(clicked()), this, SLOT(MiningInitiate()));
    //void MiningCylinderState(bool opened);           //31     ARG?
    connect(ui->button_Mining_CheckCylinderState, SIGNAL(clicked()), this, SLOT(MiningCylinderState()));
    //void MiningArmPosition4();                       //32
    connect(ui->button_Mining_ArmPosition4, SIGNAL(clicked()), this, SLOT(MiningArmPosition4()));
    //void MiningCylinderStart();                      //33
    connect(ui->button_Mining_StartCylinder, SIGNAL(clicked()), this, SLOT(MiningCylinderStart()));
    //void MiningCalibration() ;                       //34
    connect(ui->button_Calibration, SIGNAL(clicked()), this, SLOT(MiningCalibration()));
    //void MiningCylinderToGround(double w);           //35
    connect(ui->button_Mining_SetCylinderTo0, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(MiningCylinderToGround(int)));
    //void MiningPowerControl(double U, double I);     //36
    connect(ui->button_PowerControl, SIGNAL(clicked()), this, SLOT(MiningPowerControl()));
    //void MiningDriving();                            //37
    connect(ui->button_Mining_MiningDriving, SIGNAL(clicked()), this, SLOT(MiningDriving()));
    //void MiningTensometerMass();                     //38
    connect(ui->button_Mining_TensometerMass, SIGNAL(clicked()), this, SLOT(MiningTensometerMass()));
    //void MiningArmPosition1();                       //39
    connect(ui->button_Mining_ArmPositionTo1, SIGNAL(clicked()), this, SLOT(MiningArmPosition1()));
    //void UnloadInitiate();                           //40
    connect(ui->button_Unloading_Initiate, SIGNAL(clicked()), this, SLOT(UnloadInitiate()));
    //void UnloadArmPosition1();                       //41
    connect(ui->button_Unloading_SetArmPosition1, SIGNAL(clicked()), this, SLOT(UnloadArmPosition1()));
    //void UnloadCylinderToZero(double w);             //42
    connect(ui->button_Unloading_SetCylinderTo0, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(UnloadCylinderToZero(int)));
    //void UnloadCylinderOpen(); +    //void UnloadCylinderState(bool opened);           //44                      //43
    connect(ui->button_Unloading_OpenCylinder, SIGNAL(clicked()), this, SLOT(UnloadCylinderOpen()));
    //void UnloadCylinderShake();                      //45
    connect(ui->button_Unloading_ShakeCylinder, SIGNAL(clicked()), this, SLOT(UnloadCylinderShake()));
    //void UnloadCylinderRotate(double angle, double w);//46
    connect(ui->button_Unloading_RotateCylinder, SIGNAL(clicked()), this, SLOT(UnloadCylinderRotate()));
    //void UnloadCylinderClose();                      //47
    connect(ui->button_Unloading_CloseCylinder, SIGNAL(clicked()), SLOT(UnloadCylinderClose()));
    //void UnloadArmPositionCheck();                   //48    ARG?
    connect(ui->button_Unloading_CheckArmPosition, SIGNAL(clicked()), this, SLOT(UnloadArmPositionCheck()));
    //void SecurityAllEnginesStop();                   //101
    connect(ui->button_StopAll, SIGNAL(clicked()), this, SLOT(SecurityAllEnginesStop()));
    //void SecurityDrivingEnginesStop();               //102
    connect(ui->button_StopDriving, SIGNAL(clicked()), this, SLOT(SecurityDrivingEnginesStop()));
    //void SecurityArmEngineStop();                    //103
    connect(ui->button_StopArm, SIGNAL(clicked()), this, SLOT(SecurityArmEngineStop()));
    //void SecurityCylinderEngineStop();               //104
    connect(ui->button_StopCylinder, SIGNAL(clicked()), this, SLOT(SecurityCylinderEngineStop()));
    //void SecurityAutonomy();                         //105
    connect(ui->button_Teleoperation, SIGNAL(clicked()), this, SLOT(SecurityAutonomy()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete t;

}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_W){
        //ui->labelMap->setText(tr("aaa"));
        robot->Drive(0.5,0.25);
        double *p = new double[3];
        for(int i=0; i<3; ++i)
            p[i]=robot->GetPosition()[i];
        //ui->browser->append(tr("Robot is moving forward, speed %1, position: %2,%3,%4").arg(robot->GetLinearVelocity()).arg(p[0]).arg(p[1]).arg(p[2]));
        delete p;

    }
    if(event->key()==Qt::Key_D){
        robot->Turn(-15, 0.25);
        //ui->browser->append(tr("Robot turned to an angle %1").arg(robot->GetPosition()[2]));
    }
    if(event->key()==Qt::Key_A){
        robot->Turn(15, 0.25);
        //ui->browser->append(tr("Robot turned to an angle %1").arg(robot->GetPosition()[2]));
    }
    if(event->key()==Qt::Key_E){
        robot->Dig();
        //ui->browser->append(tr("Digging"));
    }
    if(event->key()==Qt::Key_Q){
        //ui->browser->append(tr("Dropping"));
        robot->Drop();
    }

    if(event->key()==Qt::Key_S){
        //ui->browser->append((tr("Going back")));
    }

    if(event->key()==Qt::Key_1){
        //robot->SetArmPosition(a);
        //ui->browser->append(tr("Setting arm position to 1"));
    }

    if(event->key()==Qt::Key_2){
        //robot->SetArmPosition(b);
        //ui->browser->append(tr("Setting arm position to 2"));
    }

    if(event->key()==Qt::Key_Escape){
        //robot->stopAll();
    }
}

void MainWindow::paintEvent(QPaintEvent *){
    QPixmap side(imgSide);
    QPainter painter(&side);
    paintArrowSpeed(QPoint(310,100), robot->GetLinearVelocity(), 20, painter);
    //ui->labelWebCam->setPixmap(side);
    painter.end();


    QPixmap map(imgMap);
    painter.begin(&map);
    painter.drawPixmap(QPoint(350,350), imgSmall);
    paintLocation(robot->GetPosition(), robot->GetLinearVelocity(), 7,robot->GetPosition()[2], imgSmall, painter);
    ui->labelMap->setPixmap(map);
    painter.end();

}

    //0 - forward, 1-turn
    //robot->Drive((joy->getAxis(1))*0.2/-32767);
    //robot->Drive((joy->getAxis(3))*0.2/-32767);
    //robot->Drive((joy->getAxis(5))*0.2/-32767);
    //ui->browser->append(tr("I drove forward"));

    //robot->Turn((double)(joy->getAxis(0))*15/-32767);
    //robot->Turn((double)(joy->getAxis(2))*15/-32767);
    //robot->Turn((double)(joy->getAxis(4))*15/-32767);
    //ui->browser->append(tr("I have turned"));

    //if(joy->getButton(0)) robot->Dig();
    //ui->browser->append(tr("Digging"));
    //if(joy->getButton(3)) robot->Drop();
    //ui->browser->append(tr("Dropping"));

                  //21
void MainWindow::updateCamImage(){
    cv::Mat mat;
    cam>>mat;
    if(mat.empty()) return;
    cv::cvtColor(mat, mat, CV_BGR2RGB);
    cv::flip(mat,mat,1);

    QImage img((uchar*)mat.data, mat.cols, mat.rows, QImage::Format_RGB888);
    ui->labelWebCam->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::updateTime(){
    if(mins==10){
        ui->lcdNumber_RemainingTime->display(tr("%1:0%2").arg(mins).arg(seconds));
        seconds=59;
        --mins;
    }

    else if(mins>=0){

        if(seconds==0){
            ui->lcdNumber_RemainingTime->display(tr("0%1:0%2").arg(mins).arg(seconds));
            seconds=59;
            --mins;
        }
        else if(seconds < 10){
            ui->lcdNumber_RemainingTime->display(tr("0%1:0%2").arg(mins).arg(seconds));
            --seconds;
            }
        else{
            ui->lcdNumber_RemainingTime->display(tr("0%1:%2").arg(mins).arg(seconds));
            --seconds;

        }
    }
    else
        t_counter->stop();
}

void MainWindow::BasicChangeValues(){
    robot->BasicChangeValues();
}

void MainWindow::BasicEngineSteer(){
    if(ui->checkBox_EngineSteerRight->isChecked()){
         robot->BasicEngineSteer(4, ui->lineEdit_SteerEngineRight->text().toDouble());
        }
    if(ui->checkBox_EngineSteerLeft->isChecked()){
        robot->BasicEngineSteer(3, ui->lineEdit_EngineSteerLeft->text().toDouble());
    }
    if(ui->checkBox_EngineSteerArm->isChecked()){
            robot->BasicEngineSteer(2, ui->lineEdit_EngineSteerArm->text().toDouble());
        }
    if(ui->checkBox_EngineSteerCylinder->isChecked()){
        robot->BasicEngineSteer(1, ui->lineEdit_EngineSteerCylinder->text().toDouble());
    }
}
//2
void MainWindow::BasicEngineDrivingSteer(){
}   //3

void MainWindow::BasicCylinderSetToZero(double w){}

//4
void MainWindow::BasicArmPositionChange(POSITION pos){
    robot->BasicArmPositionChange(pos);
}       //5
void MainWindow::BasicElectromagnetSet(){
    if(ui->button_Electromagnets->text() == tr("ON")){
        robot->BasicElectromagnetSet(true);
        ui->button_Electromagnets->setText(tr("OFF"));
    }
    else{
        robot->BasicElectromagnetSet(false);
        ui->button_Electromagnets->setText(tr("ON")); //just to make sure
    }
}
//6
void MainWindow::BasicDriveForward(double v, double t){
    robot->BasicDriveForward(v,t);
}      //7
void MainWindow::BasicTurn(double a, double t){
    robot->BasicTurn(a,t);
}
//8
void MainWindow::BasicTurnArc(){
    bool dir1 = ui->checkBox_ArchEngineRight->isChecked();
    bool dir2= ui->checkBox_ArchEngineRight->isChecked();
    double w1 = ui->lineEdit_ArchEngineRight->text().toDouble();
    double w2=ui->lineEdit_ArchEngineLeft->text().toDouble();
    robot->BasicTurnArc(dir1, dir2, w1, w2);
}
//9    ARG?

///START SEQ.
void MainWindow::StartAll(){
    robot->StartAll();
    ui->button_StartAll->setDisabled(true);

    //enable all
    ui->button_Arch->setEnabled(true);
    ui->button_Calibration->setEnabled(true);
    ui->button_EngineSteer->setEnabled(true);
    ui->button_Mining_Initiate->setEnabled(true);
    ui->button_PowerControl->setEnabled(true);
    ui->button_StopAll->setEnabled(true);
    ui->button_StopArm->setEnabled(true);
    ui->button_StopCylinder->setEnabled(true);
    ui->button_StopDriving->setEnabled(true);
    ui->button_Teleoperation->setEnabled(true);
    ui->button_Unloading_Initiate->setEnabled(true);
    ui->button_UpdateValues->setEnabled(true);
    ui->button_Mining_ArmPositionTo1->setEnabled(true);
    ui->button_Electromagnets->setEnabled(true);

    ui->checkBox_ArchEngineLeft->setCheckable(true);
    ui->checkBox_ArchEngineRight->setCheckable(true);
    ui->checkBox_EngineSteerArm->setCheckable(true);
    ui->checkBox_EngineSteerCylinder->setCheckable(true);
    ui->checkBox_EngineSteerLeft->setCheckable(true);
    ui->checkBox_EngineSteerRight->setCheckable(true);


}                                 //20

////MINING SEQ
void MainWindow::MiningInitiate(){
    robot->MiningInitiate();
    //enable mining
    ui->checkBox_Mining_ArmPosition4->setCheckable(true);
    ui->checkBox_Mining_CloseCylinder->setCheckable(true);
    ui->checkBox_Mining_MiningDriving->setCheckable(true);
    ui->checkBox_Mining_SetArmPosition1->setCheckable(true);
    ui->checkBox_Mining_SetCylinderTo0->setCheckable(true);
    ui->checkBox_Mining_StartCylinder->setCheckable(true);
    ui->checkBox_Mining_TensometerMass->setCheckable(true);
    ui->button_Mining_ArmPosition4->setEnabled(true);
    ui->button_Mining_CheckCylinderState->setEnabled(true);
    ui->button_Mining_ArmPositionTo1->setEnabled(true);
    ui->button_Mining_MiningDriving->setEnabled(true);
    ui->button_Mining_SetCylinderTo0->setEnabled(true);
    ui->button_Mining_StartCylinder->setEnabled(true);
    ui->button_Mining_Initiate->setDisabled(true);
    ui->button_Mining_TensometerMass->setEnabled(true);

    //disable unloading
    ui->checkBox_Unloading_CheckArmPosition->setCheckable(false);
    ui->checkBox_Unloading_CloseCylinder->setCheckable(false);
    ui->checkBox_Unloading_OpenCylinder->setCheckable(false);
    ui->checkBox_Unloading_RotateCylinder->setCheckable(false);
    ui->checkBox_Unloading_SetArmPosition1->setCheckable(false);
    ui->checkBox_Unloading_SetCylinderTo0->setCheckable(false);
    ui->checkBox_Unloading_ShakeCylinder->setCheckable(false);
    ui->button_Unloading_CheckArmPosition->setEnabled(false);
    ui->button_Unloading_CloseCylinder->setEnabled(false);
    ui->button_Unloading_Initiate->setEnabled(false);
    ui->button_Unloading_OpenCylinder->setEnabled(false);
    ui->button_Unloading_RotateCylinder->setEnabled(false);
    ui->button_Unloading_SetArmPosition1->setEnabled(false);
    ui->button_Unloading_SetCylinderTo0->setEnabled(false);
    ui->button_Unloading_ShakeCylinder->setEnabled(false);


}                           //30
void MainWindow::MiningCylinderState(){
    robot->MiningCylinderState(true);
    ui->checkBox_Mining_CloseCylinder->setChecked(true);

}           //31     ARG?
void MainWindow::MiningArmPosition4(){
    robot->MiningArmPosition4();
    ui->checkBox_Mining_ArmPosition4->setChecked(true);
}
//32
void MainWindow::MiningCylinderStart(){
    robot->MiningCylinderStart();
    ui->checkBox_Mining_StartCylinder->setChecked(true);
}
//33
void MainWindow::MiningCalibration() {
    robot->MiningCalibration();
}

//34
void MainWindow::MiningCylinderToGround(int w){
    robot->MiningCylinderToGround(w);
    ui->checkBox_Mining_SetCylinderTo0->setChecked(true);
}
//35
void MainWindow::MiningPowerControl(){
    double U = ui->lineEdit_PowerControlVoltage->text().toDouble();
    double I = ui->lineEdit_PowerControlCurrent->text().toDouble();
    robot->MiningPowerControl(U,I);
}     //36
void MainWindow::MiningDriving(){
    robot->MiningDriving();
    ui->checkBox_Mining_MiningDriving->setChecked(true);
}                            //37
void MainWindow::MiningTensometerMass(){
    robot->MiningTensometerMass();
    ui->checkBox_Mining_TensometerMass->setChecked(true);
}                     //38
void MainWindow::MiningArmPosition1(){
    robot->MiningArmPosition1();
    ui->checkBox_Mining_SetArmPosition1->setChecked(true);
    ui->button_Unloading_Initiate->setEnabled(true);
}                       //39

///UNLOAD SEQ
void MainWindow::UnloadInitiate(){
    //disable mining
    //uncheck boxes
    ui->checkBox_Mining_ArmPosition4->setCheckable(false);
    ui->checkBox_Mining_CloseCylinder->setCheckable(false);
    ui->checkBox_Mining_MiningDriving->setCheckable(false);
    ui->checkBox_Mining_SetArmPosition1->setCheckable(false);
    ui->checkBox_Mining_SetCylinderTo0->setCheckable(false);
    ui->checkBox_Mining_StartCylinder->setCheckable(false);
    ui->checkBox_Mining_TensometerMass->setCheckable(false);

    //disable buttons&checkes
    ui->button_Mining_CheckCylinderState->setEnabled(false);
    ui->button_Mining_Initiate->setEnabled(false);
    ui->button_Mining_MiningDriving->setEnabled(false);
    ui->button_Mining_SetCylinderTo0->setEnabled(false);
    ui->button_Mining_StartCylinder->setEnabled(false);
    ui->button_Mining_ArmPositionTo1->setEnabled(false);
    ui->button_Mining_ArmPosition4->setEnabled(false);
    ui->button_Mining_TensometerMass->setEnabled(false);

    //enable unloading
    ui->button_Unloading_CheckArmPosition->setEnabled(true);
    ui->button_Unloading_CloseCylinder->setEnabled(true);
    ui->button_Unloading_Initiate->setEnabled(true);
    ui->button_Unloading_OpenCylinder->setEnabled(true);
    ui->button_Unloading_RotateCylinder->setEnabled(true);
    ui->button_Unloading_SetArmPosition1->setEnabled(true);
    ui->button_Unloading_SetCylinderTo0->setEnabled(true);
    ui->button_Unloading_ShakeCylinder->setEnabled(true);

    ui->checkBox_Unloading_CheckArmPosition->setCheckable(true);
    ui->checkBox_Unloading_CloseCylinder->setCheckable(true);
    ui->checkBox_Unloading_OpenCylinder->setCheckable(true);
    ui->checkBox_Unloading_RotateCylinder->setCheckable(true);
    ui->checkBox_Unloading_SetArmPosition1->setCheckable(true);
    ui->checkBox_Unloading_SetCylinderTo0->setCheckable(true);
    ui->checkBox_Unloading_ShakeCylinder->setCheckable(true);

    //disable button
    ui->button_Mining_Initiate->setDisabled(true);
    ui->button_Unloading_Initiate->setDisabled(true);

}                           //40
void MainWindow::UnloadArmPosition1(){
    robot->UnloadArmPosition1();
    ui->checkBox_Unloading_SetArmPosition1->setChecked(true);
}                       //41
void MainWindow::UnloadCylinderToZero(int w){
    robot->UnloadCylinderToZero(w);
    ui->checkBox_Unloading_SetCylinderTo0->setChecked(true);
}             //42
void MainWindow::UnloadCylinderOpen(){
    robot->UnloadCylinderOpen();
    ui->checkBox_Unloading_OpenCylinder->setChecked(true);
    UnloadCylinderState(true);
}                       //43
void MainWindow::UnloadCylinderState(bool opened){
    robot->UnloadCylinderState(true);
}           //44
void MainWindow::UnloadCylinderShake(){
    robot->UnloadCylinderShake();
    ui->checkBox_Unloading_ShakeCylinder->setChecked(true);
}                      //45
void MainWindow::UnloadCylinderRotate(){
    double angle = ui->lineEdit_Unloading_CylinderAngle->text().toDouble();
    double w = ui->lineEdit_Unloading_CylinderSpeed->text().toDouble();
    robot->UnloadCylinderRotate(angle, w);
    ui->checkBox_Unloading_RotateCylinder->setChecked(true);
}//46
void MainWindow::UnloadCylinderClose(){
    robot->UnloadCylinderClose();
    ui->checkBox_Unloading_CloseCylinder->setChecked(true);
}                      //47
void MainWindow::UnloadArmPositionCheck(){
    robot->UnloadArmPositionCheck();
    ui->checkBox_Unloading_CheckArmPosition->setChecked(true);

    //disable unloading
    ui->button_Unloading_CheckArmPosition->setEnabled(false);
    ui->button_Unloading_CloseCylinder->setEnabled(false);
    ui->button_Unloading_Initiate->setEnabled(false);
    ui->button_Unloading_OpenCylinder->setEnabled(false);
    ui->button_Unloading_RotateCylinder->setEnabled(false);
    ui->button_Unloading_SetArmPosition1->setEnabled(false);
    ui->button_Unloading_SetCylinderTo0->setEnabled(false);
    ui->button_Unloading_ShakeCylinder->setEnabled(false);

    ui->checkBox_Unloading_CheckArmPosition->setCheckable(false);
    ui->checkBox_Unloading_CloseCylinder->setCheckable(false);
    ui->checkBox_Unloading_OpenCylinder->setCheckable(false);
    ui->checkBox_Unloading_RotateCylinder->setCheckable(false);
    ui->checkBox_Unloading_SetArmPosition1->setCheckable(false);
    ui->checkBox_Unloading_SetCylinderTo0->setCheckable(false);
    ui->checkBox_Unloading_ShakeCylinder->setCheckable(false);

    //disable button
    ui->button_Mining_Initiate->setDisabled(false);

}                   //48    ARG?

///SECURITY SEQ
void MainWindow::SecurityAllEnginesStop(){
    robot->SecurityAllEnginesStop();
}                   //101
void MainWindow::SecurityDrivingEnginesStop(){
    robot->SecurityDrivingEnginesStop();
}               //102
void MainWindow::SecurityArmEngineStop(){
    robot->SecurityArmEngineStop();
}                    //103
void MainWindow::SecurityCylinderEngineStop(){
    robot->SecurityCylinderEngineStop();
}               //104
void MainWindow::SecurityAutonomy(){
    robot->SecurityAutonomy();
}                         //105
