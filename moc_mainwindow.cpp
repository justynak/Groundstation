/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Apr 20 00:13:54 2013
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
      36,   32,   11,   11, 0x0a,
      65,   32,   11,   11, 0x0a,
     103,  101,   11,   11, 0x0a,
     138,  134,   11,   11, 0x0a,
     171,   11,   11,   11, 0x0a,
     199,  195,   11,   11, 0x0a,
     236,  232,   11,   11, 0x0a,
     261,   11,   11,   11, 0x0a,
     276,   11,   11,   11, 0x0a,
     287,   11,   11,   11, 0x0a,
     311,  304,   11,   11, 0x0a,
     337,   11,   11,   11, 0x0a,
     358,   11,   11,   11, 0x0a,
     380,   11,   11,   11, 0x0a,
     400,  101,   11,   11, 0x0a,
     435,  431,   11,   11, 0x0a,
     469,   11,   11,   11, 0x0a,
     485,   11,   11,   11, 0x0a,
     508,   11,   11,   11, 0x0a,
     529,   11,   11,   11, 0x0a,
     546,   11,   11,   11, 0x0a,
     567,  101,   11,   11, 0x0a,
     596,   11,   11,   11, 0x0a,
     617,  304,   11,   11, 0x0a,
     643,   11,   11,   11, 0x0a,
     673,  665,   11,   11, 0x0a,
     709,   11,   11,   11, 0x0a,
     731,   11,   11,   11, 0x0a,
     756,   11,   11,   11, 0x0a,
     781,   11,   11,   11, 0x0a,
     810,   11,   11,   11, 0x0a,
     834,   11,   11,   11, 0x0a,
     863,   11,   11,   11, 0x0a,
     882,   11,   11,   11, 0x0a,
     899,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0BasicChangeValues()\0i,w\0"
    "BasicEngineSteer(int,double)\0"
    "BasicEngineDrivingSteer(int,double)\0"
    "w\0BasicCylinderSetToZero(double)\0pos\0"
    "BasicArmPositionChange(POSITION)\0"
    "BasicElectromagnetSet()\0v,t\0"
    "BasicDriveForward(double,double)\0a,t\0"
    "BasicTurn(double,double)\0BasicTurnArc()\0"
    "StartAll()\0MiningInitiate()\0opened\0"
    "MiningCylinderState(bool)\0"
    "MiningArmPosition4()\0MiningCylinderStart()\0"
    "MiningCalibration()\0MiningCylinderToGround(double)\0"
    "U,I\0MiningPowerControl(double,double)\0"
    "MiningDriving()\0MiningTensometerMass()\0"
    "MiningArmPosition1()\0UnloadInitiate()\0"
    "UnloadArmPosition1()\0UnloadCylinderToZero(double)\0"
    "UnloadCylinderOpen()\0UnloadCylinderState(bool)\0"
    "UnloadCylinderShake()\0angle,w\0"
    "UnloadCylinderRotate(double,double)\0"
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
        case 1: _t->BasicEngineSteer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->BasicEngineDrivingSteer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->BasicCylinderSetToZero((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->BasicArmPositionChange((*reinterpret_cast< POSITION(*)>(_a[1]))); break;
        case 5: _t->BasicElectromagnetSet(); break;
        case 6: _t->BasicDriveForward((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->BasicTurn((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->BasicTurnArc(); break;
        case 9: _t->StartAll(); break;
        case 10: _t->MiningInitiate(); break;
        case 11: _t->MiningCylinderState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->MiningArmPosition4(); break;
        case 13: _t->MiningCylinderStart(); break;
        case 14: _t->MiningCalibration(); break;
        case 15: _t->MiningCylinderToGround((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->MiningPowerControl((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 17: _t->MiningDriving(); break;
        case 18: _t->MiningTensometerMass(); break;
        case 19: _t->MiningArmPosition1(); break;
        case 20: _t->UnloadInitiate(); break;
        case 21: _t->UnloadArmPosition1(); break;
        case 22: _t->UnloadCylinderToZero((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->UnloadCylinderOpen(); break;
        case 24: _t->UnloadCylinderState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->UnloadCylinderShake(); break;
        case 26: _t->UnloadCylinderRotate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
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
