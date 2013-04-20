/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Apr 20 02:24:26 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      32,   11,   11,   11, 0x0a,
      51,   11,   11,   11, 0x0a,
      79,   77,   11,   11, 0x0a,
     114,  110,   11,   11, 0x0a,
     147,   11,   11,   11, 0x0a,
     175,  171,   11,   11, 0x0a,
     212,  208,   11,   11, 0x0a,
     237,   11,   11,   11, 0x0a,
     252,   11,   11,   11, 0x0a,
     263,   11,   11,   11, 0x0a,
     280,   11,   11,   11, 0x0a,
     302,   11,   11,   11, 0x0a,
     323,   11,   11,   11, 0x0a,
     345,   11,   11,   11, 0x0a,
     365,   77,   11,   11, 0x0a,
     393,   11,   11,   11, 0x0a,
     414,   11,   11,   11, 0x0a,
     430,   11,   11,   11, 0x0a,
     453,   11,   11,   11, 0x0a,
     474,   11,   11,   11, 0x0a,
     491,   11,   11,   11, 0x0a,
     512,   77,   11,   11, 0x0a,
     538,   11,   11,   11, 0x0a,
     566,  559,   11,   11, 0x0a,
     592,   11,   11,   11, 0x0a,
     614,   11,   11,   11, 0x0a,
     637,   11,   11,   11, 0x0a,
     659,   11,   11,   11, 0x0a,
     684,   11,   11,   11, 0x0a,
     709,   11,   11,   11, 0x0a,
     738,   11,   11,   11, 0x0a,
     762,   11,   11,   11, 0x0a,
     791,   11,   11,   11, 0x0a,
     810,   11,   11,   11, 0x0a,
     827,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0BasicChangeValues()\0"
    "BasicEngineSteer()\0BasicEngineDrivingSteer()\0"
    "w\0BasicCylinderSetToZero(double)\0pos\0"
    "BasicArmPositionChange(POSITION)\0"
    "BasicElectromagnetSet()\0v,t\0"
    "BasicDriveForward(double,double)\0a,t\0"
    "BasicTurn(double,double)\0BasicTurnArc()\0"
    "StartAll()\0MiningInitiate()\0"
    "MiningCylinderState()\0MiningArmPosition4()\0"
    "MiningCylinderStart()\0MiningCalibration()\0"
    "MiningCylinderToGround(int)\0"
    "MiningPowerControl()\0MiningDriving()\0"
    "MiningTensometerMass()\0MiningArmPosition1()\0"
    "UnloadInitiate()\0UnloadArmPosition1()\0"
    "UnloadCylinderToZero(int)\0"
    "UnloadCylinderOpen()\0opened\0"
    "UnloadCylinderState(bool)\0"
    "UnloadCylinderShake()\0UnloadCylinderRotate()\0"
    "UnloadCylinderClose()\0UnloadArmPositionCheck()\0"
    "SecurityAllEnginesStop()\0"
    "SecurityDrivingEnginesStop()\0"
    "SecurityArmEngineStop()\0"
    "SecurityCylinderEngineStop()\0"
    "SecurityAutonomy()\0updateCamImage()\0"
    "updateTime()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->BasicChangeValues(); break;
        case 1: _t->BasicEngineSteer(); break;
        case 2: _t->BasicEngineDrivingSteer(); break;
        case 3: _t->BasicCylinderSetToZero((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->BasicArmPositionChange((*reinterpret_cast< POSITION(*)>(_a[1]))); break;
        case 5: _t->BasicElectromagnetSet(); break;
        case 6: _t->BasicDriveForward((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->BasicTurn((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->BasicTurnArc(); break;
        case 9: _t->StartAll(); break;
        case 10: _t->MiningInitiate(); break;
        case 11: _t->MiningCylinderState(); break;
        case 12: _t->MiningArmPosition4(); break;
        case 13: _t->MiningCylinderStart(); break;
        case 14: _t->MiningCalibration(); break;
        case 15: _t->MiningCylinderToGround((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->MiningPowerControl(); break;
        case 17: _t->MiningDriving(); break;
        case 18: _t->MiningTensometerMass(); break;
        case 19: _t->MiningArmPosition1(); break;
        case 20: _t->UnloadInitiate(); break;
        case 21: _t->UnloadArmPosition1(); break;
        case 22: _t->UnloadCylinderToZero((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->UnloadCylinderOpen(); break;
        case 24: _t->UnloadCylinderState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->UnloadCylinderShake(); break;
        case 26: _t->UnloadCylinderRotate(); break;
        case 27: _t->UnloadCylinderClose(); break;
        case 28: _t->UnloadArmPositionCheck(); break;
        case 29: _t->SecurityAllEnginesStop(); break;
        case 30: _t->SecurityDrivingEnginesStop(); break;
        case 31: _t->SecurityArmEngineStop(); break;
        case 32: _t->SecurityCylinderEngineStop(); break;
        case 33: _t->SecurityAutonomy(); break;
        case 34: _t->updateCamImage(); break;
        case 35: _t->updateTime(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
