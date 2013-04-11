#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<QTimer>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(close()));
    imgUp.load(":/images/dol.png");
    imgSide.load(":/images/bok.png");
    imgMap.load(":/images/map.png");
    imgSmall.load(":/images/small.png");

    ui->labelMap->setPixmap(imgMap);
    //ui->labelWebCam->setPixmap(imgWebCam);

    //joy = new Joystick();


    ////    IP CAM
    ////////  ZAMIAST 0 -> const std::string videoStreamAddress = "http://<username:password>@<ip_address>/video.cgi?.mjpg"; //czy w tym stylu

    cam.open(0);

    t=new QTimer();
    t->start(50);

    connect(t, SIGNAL(timeout()), this, SLOT(updateCamImage()));

    //if(!(joy->init("/dev/input/js0"))){
    //    t = new QTimer(this);
    //    t->start();
    //    connect(t, SIGNAL(timeout()), this, SLOT(updateValues()));
    //}


}

void MainWindow::initialize(){
   connect(ui->buttonCalibrate, SIGNAL(clicked()), this->robot, SLOT(Calibrate()));
   connect(ui->buttonHalt, SIGNAL(clicked()), this->robot, SLOT(StopAll()));
   connect(ui->buttonStop, SIGNAL(clicked()), this->robot, SLOT(StopDriving()));
   connect(ui->buttonTeleoperation, SIGNAL(clicked()), this, SLOT(TeleoperationOn()));
   connect(ui->buttonSteer, SIGNAL(clicked()), this, SLOT(EngineSteer()));
   connect(ui->buttonArmPosition, SIGNAL(clicked()), this, SLOT(SetArmPosition()));
   connect(ui->buttonKeep, SIGNAL(clicked()), this, SLOT(SetMaxCurrentVoltage()));
   connect(ui->buttonStart, SIGNAL(clicked()), this->robot, SLOT(StartAll()));

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
        robot->SetArmPosition(a);
        //ui->browser->append(tr("Setting arm position to 1"));
    }

    if(event->key()==Qt::Key_2){
        robot->SetArmPosition(b);
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


void MainWindow::updateValues(){
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

}

void MainWindow::EngineSteer(){
   int i = ui->lineEditSteerNr->text().toInt();
   int w = ui->lineEditSteerW->text().toDouble();
   if(w==0) robot->EngineStop(i);
   else robot->EngineSteer(i,w);


    //robot->EngineSteer(i, w);
}         //2
//wysteruj silniki jezdne brak               //3
void MainWindow::EngineStop(){
   //////////
}                      //4

void MainWindow::CylinderToZero(){
    robot->CylinderToZero(0.5);
}
//5
void MainWindow::SetArmPosition(){
    int pos =  ui->horizontalSliderArmPosition->value();
    if(pos==0)  robot->SetArmPosition(a);
    if(pos==1)  robot->SetArmPosition(b);
    if(pos==2) robot->SetArmPosition(c);

}
//6
void MainWindow::SetElectromagnet() {
    bool on=true;
    robot->SetElectromagnet(on);
}             //7

void MainWindow::TeleoperationOn(){
    robot->TeleoperationOn();
}                      //8

void MainWindow::StopAll(){
    robot->StopAll();
}                              //9
void MainWindow::StartAll(){
    robot->StartAll();
}                             //10
//void MainWindow::Drive(){}           //11
//void MainWindow::Turn(){}           //12
//niestandardowej brak                       //13
void MainWindow::StopDriving(){
    robot->StopDriving();
}                          //14
//zadeklarowane już{}                                  //15
void MainWindow::CylinderMove(){

}                 //16
void MainWindow::Calibrate(){

}                            //17
void MainWindow::CylinderToGround(){

}             //18
void MainWindow::SetMaxCurrentVoltage(){
    double U = ui->lineEditKeepU->text().toDouble();
    double I=ui->lineEditKeepI->text().toDouble();
    robot->SetMaxCurrentVoltage(U,I);
}//19
//pilnuj koniec brak                         //20
void MainWindow::MassChange(){
    ////////////
}                   //21

void MainWindow::updateCamImage(){
    cv::Mat mat;
    cam>>mat;
    if(mat.empty()) return;
    cv::cvtColor(mat, mat, CV_BGR2RGB);
    cv::flip(mat,mat,1);

    QImage img((uchar*)mat.data, mat.cols, mat.rows, QImage::Format_RGB888);
    ui->labelWebCam->setPixmap(QPixmap::fromImage(img));

}
