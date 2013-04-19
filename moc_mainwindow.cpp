/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Apr 20 00:39:01 2013
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
      77,   11,   11,   11, 0x0a,
     102,   11,   11,   11, 0x0a,
     127,   11,   11,   11, 0x0a,
     151,   11,   11,   11, 0x0a,
     171,   11,   11,   11, 0x0a,
     183,   11,   11,   11, 0x0a,
     198,   11,   11,   11, 0x0a,
     209,   11,   11,   11, 0x0a,
     226,   11,   11,   11, 0x0a,
     248,   11,   11,   11, 0x0a,
     269,   11,   11,   11, 0x0a,
     291,   11,   11,   11, 0x0a,
     311,   11,   11,   11, 0x0a,
     336,   11,   11,   11, 0x0a,
     357,   11,   11,   11, 0x0a,
     373,   11,   11,   11, 0x0a,
     396,   11,   11,   11, 0x0a,
     417,   11,   11,   11, 0x0a,
     434,   11,   11,   11, 0x0a,
     455,   11,   11,   11, 0x0a,
     478,   11,   11,   11, 0x0a,
     499,   11,   11,   11, 0x0a,
     521,   11,   11,   11, 0x0a,
     543,   11,   11,   11, 0x0a,
     566,   11,   11,   11, 0x0a,
     588,   11,   11,   11, 0x0a,
     613,   11,   11,   11, 0x0a,
     638,   11,   11,   11, 0x0a,
     667,   11,   11,   11, 0x0a,
     691,   11,   11,   11, 0x0a,
     720,   11,   11,   11, 0x0a,
     739,   11,   11,   11, 0x0a,
     756,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0BasicChangeValues()\0"
    "BasicEngineSteer()\0BasicEngineDrivingSteer()\0"
    "BasicCylinderSetToZero()\0"
    "BasicArmPositionChange()\0"
    "BasicElectromagnetSet()\0BasicDriveForward()\0"
    "BasicTurn()\0BasicTurnArc()\0StartAll()\0"
    "MiningInitiate()\0MiningCylinderState()\0"
    "MiningArmPosition4()\0MiningCylinderStart()\0"
    "MiningCalibration()\0MiningCylinderToGround()\0"
    "MiningPowerControl()\0MiningDriving()\0"
    "MiningTensometerMass()\0MiningArmPosition1()\0"
    "UnloadInitiate()\0UnloadArmPosition1()\0"
    "UnloadCylinderToZero()\0UnloadCylinderOpen()\0"
    "UnloadCylinderState()\0UnloadCylinderShake()\0"
    "UnloadCylinderRotate()\0UnloadCylinderClose()\0"
    "UnloadArmPositionCheck()\0"
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
        case 3: _t->BasicCylinderSetToZero(); break;
        case 4: _t->BasicArmPositionChange(); break;
        case 5: _t->BasicElectromagnetSet(); break;
        case 6: _t->BasicDriveForward(); break;
        case 7: _t->BasicTurn(); break;
        case 8: _t->BasicTurnArc(); break;
        case 9: _t->StartAll(); break;
        case 10: _t->MiningInitiate(); break;
        case 11: _t->MiningCylinderState(); break;
        case 12: _t->MiningArmPosition4(); break;
        case 13: _t->MiningCylinderStart(); break;
        case 14: _t->MiningCalibration(); break;
        case 15: _t->MiningCylinderToGround(); break;
        case 16: _t->MiningPowerControl(); break;
        case 17: _t->MiningDriving(); break;
        case 18: _t->MiningTensometerMass(); break;
        case 19: _t->MiningArmPosition1(); break;
        case 20: _t->UnloadInitiate(); break;
        case 21: _t->UnloadArmPosition1(); break;
        case 22: _t->UnloadCylinderToZero(); break;
        case 23: _t->UnloadCylinderOpen(); break;
        case 24: _t->UnloadCylinderState(); break;
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
    Q_UNUSED(_a);
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
