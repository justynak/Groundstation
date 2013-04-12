#include "scada.h"
#include "ui_scada.h"


SCADA::SCADA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SCADA)
{
    ui->setupUi(this);
    qpixUp.load(":/images/dol.png");
    qpixSide.load(":/images/bok.png");

    ui->labelUp->setPixmap(qpixUp);
    ui->labelSide->setPixmap(qpixSide);

    tcam = new QTimer(this);
    connect(tcam, SIGNAL(timeout()), this, SLOT(updateImageCam()));

    tcam->start(50);


}

void SCADA::initialize(){
    connect(robot, SIGNAL(changedValues()), this, SLOT(UpdateValues()));
    connect(robot, SIGNAL(ArmPositionChanged(POSITION)), this, SLOT(ArmPosition(POSITION)));
    connect(robot, SIGNAL(Calibrated()), this, SLOT(Calibrate()));
    connect(robot, SIGNAL(CurrentVoltageSet(double, double)), this, SLOT(SetMaxCurrentVoltage(double, double)));
    connect(robot, SIGNAL(CylinderMoved(double)), this, SLOT(CylinderMove(double)));
    connect(robot, SIGNAL(CylinderSetToGround(double)), this, SLOT(CylinderToGround(double)));
    connect(robot, SIGNAL(CylinderSetToZero(double)), this, SLOT(CylinderToZero(double)));
    connect(robot, SIGNAL(DrivenForward(double, double)), this, SLOT(Drive(double,double)));
    connect(robot, SIGNAL(Electromagnet(bool)), this, SLOT(SetElectromagnet(bool)));
    connect(robot, SIGNAL(EngineSteered(int, double)), this, SLOT(EngineSteer(int, double)));
    connect(robot, SIGNAL(EngineStopped(int)), this, SLOT(EngineStop(int)));
    connect(robot, SIGNAL(Mined()), this, SLOT(Dig()));
    connect(robot, SIGNAL(StartedAll()), this, SLOT(StartAll()));
    connect(robot, SIGNAL(StoppedAll()), this, SLOT(StopAll()));
    connect(robot, SIGNAL(StoppedDriving()), this, SLOT(StopDriving()));
    connect(robot, SIGNAL(Teleoperation()), this, SLOT(TeleoperationOn()));
    connect(robot, SIGNAL(Turned(double, double)), this, SLOT(Turn(double,double)));
    connect(robot, SIGNAL(MassChanged(double)), this, SLOT(MassChange(double)));
}

SCADA::~SCADA()
{
    delete ui;
    delete tcam;
    delete tup;
}

void SCADA::paintEvent(QPaintEvent *){
    QPixmap side(qpixSide);
    QPainter painter(&side);
    paintArrowSpeed(QPoint(310,100), robot->GetLinearVelocity(), 20, painter);

   POSITION pos = robot->GetArmPosition();

   paintArmPosition(QPoint(100,100),(int)pos, painter);
    paintCylinderWeight(QPoint(150,150),robot->GetCylinderWeight(), painter);
    ui->labelSide->setPixmap(side);
    QPixmap up(qpixUp);
    QPainter painter2(&up);

    paintArrowWheel(QPoint(82,70), robot->GetWheelVelocity(0), 10, painter2);
    paintArrowWheel(QPoint(82,304), robot->GetWheelVelocity(1), 10, painter2);
    paintArrowWheel(QPoint(390,70), robot->GetWheelVelocity(2), 10, painter2);
    paintArrowWheel(QPoint(390,304), robot->GetWheelVelocity(3), 10, painter2);
    ui->labelUp->setPixmap(up);
}

void SCADA::UpdateValues(){
    ui->sliderBatteryI->setValue(robot->GetBatteryCurrent());
    ui->sliderBatteryU->setValue(robot->GetBatteryVoltage());
    ui->sliderCylinderI->setValue ( robot->GetCylinderWeight());
    ui->sliderCylinderw->setValue( robot->GetCylinderWeight());
    ui->sliderElectromagnet->setValue (robot->GetElectromagnet() );

    ui->sliderEngine0I->setValue ( robot->GetEngineCurrent(0));
    ui->sliderEngine1I->setValue(robot->GetEngineCurrent(1));
    ui->sliderEngine2I->setValue(robot->GetEngineCurrent(2));
    ui->sliderEngine3I->setValue(robot->GetEngineCurrent(3));

    ui->sliderEngine0w->setValue ( robot->GetEngineSpeed(0));
    ui->sliderEngine1w->setValue ( robot->GetEngineSpeed(1));
    ui->sliderEngine2w->setValue ( robot->GetEngineSpeed(2));
    ui->sliderEngine3w->setValue ( robot->GetEngineSpeed(3));

    ui->sliderMass->setValue ( robot->GetCylinderWeight()) ;
    ui->sliderTensometer0->setValue ( robot->GetMass());
    ui->sliderTensometer1->setValue( robot->GetTensometer());


}

void SCADA::EngineSteer(int i, double w){
    ui->textBrowser->append(tr("Engine %1 steered to %2 speed").arg(i).arg(w));
}                     //2
//wysteruj silniki jezdne brak               //3
void SCADA::EngineStop(int i){
    ui->textBrowser->append(tr("Engine %1 stopped").arg(i));
}                      //4
void SCADA::CylinderToZero(double w){
   ui->textBrowser->append(tr("Cylinder set to zero"));
}                       //5
void SCADA::ArmPosition(POSITION pos){
    ui->textBrowser->append(tr("Arm set to position %1").arg(pos));
}
//6
void SCADA::SetElectromagnet(bool on) {
    ui->textBrowser->append(tr("Electromagnet is %1").arg(on));
}                    //7
void SCADA::TeleoperationOn(){
    ui->textBrowser->append(tr("TELEOPERATION MODE"));
}                      //8
void SCADA::StopAll(){
    ui->textBrowser->append(tr("ALL STOPPED"));
}                              //9
void SCADA::StartAll(){
    ui->textBrowser->append(tr("ROBOT STARTED"));
}                            //10
void SCADA::Drive(double v, double t){
    ui->textBrowser->append(tr("Robot drove for t= %1, v=").arg(v).arg(t));
}       //11
void SCADA::Turn(double angle, double t){
    ui->textBrowser->append(tr("Robot turned for t= %1, a=").arg(t).arg(angle));
}    //12
//niestandardowej brak                      //13
void SCADA::StopDriving(){
    ui->textBrowser->append(tr("Stopped driving"));
}                         //14
void SCADA::Dig(){
    ui->textBrowser->append(tr("Digging"));
}                                 //15
void SCADA::CylinderMove(double w){
    ui->textBrowser->append(tr("Cylinder moved with speed").arg(w));
}                        //16
void SCADA::Calibrate(){
    ui->textBrowser->append(tr("Tensors calibrated"));
}                           //17
void SCADA::CylinderToGround(double w){
    ui->textBrowser->append(tr("Cylinder set to the grounf with speed %1").arg(w));
}                    //18
void SCADA::SetMaxCurrentVoltage(double U, double I){
    ui->textBrowser->append(tr("Umax = %1, Imax= %2").arg(U).arg(I));
}                //19
//pilnuj koniec brak                        //20
void SCADA::MassChange(double m){
    ui->textBrowser->append(tr("Current mass %1").arg(m));
}                         //21

void SCADA::updateImageCam(){

}
