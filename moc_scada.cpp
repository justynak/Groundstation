/****************************************************************************
** Meta object code from reading C++ file 'scada.h'
**
** Created: Sat Apr 20 00:39:02 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scada.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scada.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SCADA[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      31,   27,    6,    6, 0x0a,
      60,   27,    6,    6, 0x0a,
      98,   96,    6,    6, 0x0a,
     133,  129,    6,    6, 0x0a,
     169,  166,    6,    6, 0x0a,
     201,  197,    6,    6, 0x0a,
     238,  234,    6,    6, 0x0a,
     279,  263,    6,    6, 0x0a,
     317,    6,    6,    6, 0x0a,
     328,    6,    6,    6, 0x0a,
     352,  345,    6,    6, 0x0a,
     378,    6,    6,    6, 0x0a,
     399,    6,    6,    6, 0x0a,
     421,    6,    6,    6, 0x0a,
     441,   96,    6,    6, 0x0a,
     476,  472,    6,    6, 0x0a,
     510,    6,    6,    6, 0x0a,
     526,    6,    6,    6, 0x0a,
     549,    6,    6,    6, 0x0a,
     570,    6,    6,    6, 0x0a,
     587,    6,    6,    6, 0x0a,
     608,   96,    6,    6, 0x0a,
     637,    6,    6,    6, 0x0a,
     658,  345,    6,    6, 0x0a,
     684,    6,    6,    6, 0x0a,
     714,  706,    6,    6, 0x0a,
     750,    6,    6,    6, 0x0a,
     772,    6,    6,    6, 0x0a,
     797,    6,    6,    6, 0x0a,
     822,    6,    6,    6, 0x0a,
     851,    6,    6,    6, 0x0a,
     875,    6,    6,    6, 0x0a,
     904,    6,    6,    6, 0x0a,
     923,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SCADA[] = {
    "SCADA\0\0BasicChangeValues()\0i,w\0"
    "BasicEngineSteer(int,double)\0"
    "BasicEngineDrivingSteer(int,double)\0"
    "w\0BasicCylinderSetToZero(double)\0pos\0"
    "BasicArmPositionChange(POSITION)\0on\0"
    "BasicElectromagnetSet(bool)\0v,t\0"
    "BasicDriveForward(double,double)\0a,t\0"
    "BasicTurn(double,double)\0dir1,dir3,w1,w2\0"
    "BasicTurnArc(bool,bool,double,double)\0"
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
    "SecurityAutonomy()\0updateImageCam()\0"
};

void SCADA::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SCADA *_t = static_cast<SCADA *>(_o);
        switch (_id) {
        case 0: _t->BasicChangeValues(); break;
        case 1: _t->BasicEngineSteer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->BasicEngineDrivingSteer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->BasicCylinderSetToZero((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->BasicArmPositionChange((*reinterpret_cast< POSITION(*)>(_a[1]))); break;
        case 5: _t->BasicElectromagnetSet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->BasicDriveForward((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->BasicTurn((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->BasicTurnArc((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
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
        case 34: _t->updateImageCam(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SCADA::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SCADA::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SCADA,
      qt_meta_data_SCADA, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SCADA::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SCADA::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SCADA::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SCADA))
        return static_cast<void*>(const_cast< SCADA*>(this));
    return QWidget::qt_metacast(_clname);
}

int SCADA::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
