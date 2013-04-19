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


void SCADA::BasicChangeValues(){
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

void SCADA::BasicEngineSteer(int i, double w){
    ui->textBrowser->append(tr("Basic: Engine %1 steered to %2").arg(i).arg(w));
}

void SCADA::BasicEngineDrivingSteer(int i, double w){
    ui->textBrowser->append(tr("Basic: Engine (wheel) %1 steered to %2").arg(i).arg(w));
}

void SCADA::BasicCylinderSetToZero(double w){
     ui->textBrowser->append(tr("Basic: Cylinder set to 0 position"));
}

void SCADA::BasicArmPositionChange(POSITION pos){
     ui->textBrowser->append(tr("Basic: Arm changet to position").arg(pos));
}

void SCADA::BasicElectromagnetSet(bool on){
     ui->textBrowser->append(tr("Basic: Electromagnet: %1").arg(on));
}

void SCADA::BasicDriveForward(double v, double t){
     ui->textBrowser->append(tr("Basic: Went forward: v= %1, t= %2").arg(v).arg(t));
}

void SCADA::BasicTurn(double a, double t){
    ui->textBrowser->append(tr("Basic: Turned: a= %1, t= %2").arg(a).arg(t));
}

void SCADA::BasicTurnArc(bool dir1, bool dir2, double w1, double w2){
    ui->textBrowser->append(tr("Basic: Turned: arc: dir1=%1, dir2 =%2, w1=%3, w2=%4").arg(dir1).arg(dir2).arg(w1).arg(w2));
}

///START SEQ.
void SCADA::StartAll(){
    ui->textBrowser->append(tr("Start sequence"));
}

////MINING SEQ
void SCADA::MiningInitiate(){
    ui->textBrowser->append(tr("Mining: initiated"));
}

void SCADA::MiningCylinderState(bool opened){
    ui->textBrowser->append(tr("Mining:Cylinder is opened:").arg(opened));
}

void SCADA::MiningArmPosition4(){
    ui->textBrowser->append(tr("Mining: Arm position: 4,"));
}

void SCADA::MiningCylinderStart(){
    ui->textBrowser->append(tr("Mining: Cylinder started"));
}

void SCADA::MiningCalibration() {
    ui->textBrowser->append(tr("Mining: Calibration"));
}

void SCADA::MiningCylinderToGround(double w){
    ui->textBrowser->append(tr("Mining: Cylinder set to ground: %1").arg(w));
}

void SCADA::MiningPowerControl(double U, double I){
    ui->textBrowser->append(tr("Mining: Power control: U=%1, I=%2").arg(U).arg(I));
}

void SCADA::MiningDriving(){
    ui->textBrowser->append(tr("Mining: Driving"));
}

//check args
void SCADA::MiningTensometerMass(){
    ui->textBrowser->append(tr("Mining: loaded mass: "));
}

void SCADA::MiningArmPosition1(){
    ui->textBrowser->append(tr("Mining: Arm position: 0"));
}


///UNLOAD SEQ
void SCADA::UnloadInitiate(){
    ui->textBrowser->append(tr("Unload: Initiated"));
}

void SCADA::UnloadArmPosition1(){
    ui->textBrowser->append(tr("Unload: Arm position: 1"));
}

void SCADA::UnloadCylinderToZero(double w){
    ui->textBrowser->append(tr("Unload: Cylinder to zero, w=%1").arg(w));
}

void SCADA::UnloadCylinderOpen(){
    ui->textBrowser->append(tr("Unload: Cylinder Opened"));
}

void SCADA::UnloadCylinderState(bool opened){
    ui->textBrowser->append(tr("Unload: Cylinder opened: %1").arg(opened));
}

void SCADA::UnloadCylinderShake(){
    ui->textBrowser->append(tr("Unload: Cylinder shaking"));
}

void SCADA::UnloadCylinderRotate(double angle, double w){
    ui->textBrowser->append(tr("Unload: Cylinder rotated to: a=%1, w=%2").arg(angle).arg(w));
}

void SCADA::UnloadCylinderClose(){
    ui->textBrowser->append(tr("Unload: Cylinder closed"));
}

void SCADA::UnloadArmPositionCheck(){
    ui->textBrowser->append(tr("Unload: Arm positioned"));
}


///SECURITY SEQ
void SCADA::SecurityAllEnginesStop(){
    ui->textBrowser->append(tr("Security: All engines stopped"));
}

void SCADA::SecurityDrivingEnginesStop(){
    ui->textBrowser->append(tr("Security: Driving engines stopped"));
}

void SCADA::SecurityArmEngineStop(){
    ui->textBrowser->append(tr("Security: Arm engine stopped"));
}

void SCADA::SecurityCylinderEngineStop(){
    ui->textBrowser->append(tr("Security: Cylinder engine stopped"));
}

void SCADA::SecurityAutonomy(){
    ui->textBrowser->append(tr("Security: Autonomy mode"));
}

void SCADA::updateImageCam(){
////////cam
}
