#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<QTimer>


int seconds = 600;

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

    //ui->labelMap->setPixmap(imgMap);

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

}

void MainWindow::initialize(){
    //void BasicChangeValues();                        //1
    connect(ui->button_UpdateValues, SIGNAL(clicked()), this, SLOT(BasicChangeValues()));
    //void BasicEngineSteer(int i, double w); //2 + void BasicEngineDrivingSteer(int i, double w);   //3
    connect(ui->button_EngineSteer, SIGNAL(clicked()), this, SLOT(BasicEngineSteer(int,double)));
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



    ////MINING SEQ
    //void MiningInitiate();                           //30
    //void MiningCylinderState(bool opened);           //31     ARG?
    //void MiningArmPosition4();                       //32
    //void MiningCylinderStart();                      //33
    //void MiningCalibration() ;                       //34
    //void MiningCylinderToGround(double w);           //35
    //void MiningPowerControl(double U, double I);     //36
    //void MiningDriving();                            //37
    //void MiningTensometerMass();                     //38
    //void MiningArmPosition1();                       //39

    ///UNLOAD SEQ
    //void UnloadInitiate();                           //40
    //void UnloadArmPosition1();                       //41
    //void UnloadCylinderToZero(double w);             //42
    //void UnloadCylinderOpen();                       //43
    //void UnloadCylinderState(bool opened);           //44
    //void UnloadCylinderShake();                      //45
    //void UnloadCylinderRotate(double angle, double w);//46
    //void UnloadCylinderClose();                      //47
    //void UnloadArmPositionCheck();                   //48    ARG?

    ///SECURITY SEQ
    //void SecurityAllEnginesStop();                   //101
    //void SecurityDrivingEnginesStop();               //102
    //void SecurityArmEngineStop();                    //103
    //void SecurityCylinderEngineStop();               //104
    //void SecurityAutonomy();                         //105
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
    if(seconds>=0){
        //ui->lcdTimer->display(seconds);
        --seconds;}
    else
        t_counter->stop();
}

void MainWindow::BasicChangeValues(){}                        //1
void MainWindow::BasicEngineSteer(int i, double w){}          //2
void MainWindow::BasicEngineDrivingSteer(int i, double w){}   //3
void MainWindow::BasicCylinderSetToZero(double w){}           //4
void MainWindow::BasicArmPositionChange(POSITION pos){}       //5
void MainWindow::BasicElectromagnetSet(){}                //6
void MainWindow::BasicDriveForward(double v, double t){}      //7
void MainWindow::BasicTurn(double a, double t){}              //8
void MainWindow::BasicTurnArc(){}//9    ARG?

///START SEQ.
void MainWindow::StartAll(){}                                 //20

////MINING SEQ
void MainWindow::MiningInitiate(){}                           //30
void MainWindow::MiningCylinderState(bool opened){}           //31     ARG?
void MainWindow::MiningArmPosition4(){}                       //32
void MainWindow::MiningCylinderStart(){}                      //33
void MainWindow::MiningCalibration() {}                       //34
void MainWindow::MiningCylinderToGround(double w){}           //35
void MainWindow::MiningPowerControl(double U, double I){}     //36
void MainWindow::MiningDriving(){}                            //37
void MainWindow::MiningTensometerMass(){}                     //38
void MainWindow::MiningArmPosition1(){}                       //39

///UNLOAD SEQ
void MainWindow::UnloadInitiate(){}                           //40
void MainWindow::UnloadArmPosition1(){}                       //41
void MainWindow::UnloadCylinderToZero(double w){}             //42
void MainWindow::UnloadCylinderOpen(){}                       //43
void MainWindow::UnloadCylinderState(bool opened){}           //44
void MainWindow::UnloadCylinderShake(){}                      //45
void MainWindow::UnloadCylinderRotate(double angle, double w){}//46
void MainWindow::UnloadCylinderClose(){}                      //47
void MainWindow::UnloadArmPositionCheck(){}                   //48    ARG?

///SECURITY SEQ
void MainWindow::SecurityAllEnginesStop(){}                   //101
void MainWindow::SecurityDrivingEnginesStop(){}               //102
void MainWindow::SecurityArmEngineStop(){}                    //103
void MainWindow::SecurityCylinderEngineStop(){}               //104
void MainWindow::SecurityAutonomy(){}                         //105
