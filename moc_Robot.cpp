/****************************************************************************
** Meta object code from reading C++ file 'Robot.h'
**
** Created: Thu Apr 11 14:32:42 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Robot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Robot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Robot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      27,   23,    6,    6, 0x05,
      55,   53,    6,    6, 0x05,
      76,   74,    6,    6, 0x05,
     106,  102,    6,    6, 0x05,
     138,  135,    6,    6, 0x05,
     158,    6,    6,    6, 0x05,
     174,    6,    6,    6, 0x05,
     187,    6,    6,    6, 0x05,
     204,  200,    6,    6, 0x05,
     237,  233,    6,    6, 0x05,
     259,    6,    6,    6, 0x05,
     276,    6,    6,    6, 0x05,
     284,   74,    6,    6, 0x05,
     306,    6,    6,    6, 0x05,
     319,   74,    6,    6, 0x05,
     351,  347,    6,    6, 0x05,
     386,  384,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     406,    6,    6,    6, 0x0a,
     421,    6,    6,    6, 0x0a,
     433,    6,    6,    6, 0x0a,
     448,   23,    6,    6, 0x0a,
     472,   53,    6,    6, 0x0a,
     488,   74,    6,    6, 0x0a,
     508,  102,    6,    6, 0x0a,
     536,  533,    6,    6, 0x0a,
     559,    6,    6,    6, 0x0a,
     577,    6,    6,    6, 0x0a,
     587,    6,    6,    6, 0x0a,
     598,  200,    6,    6, 0x0a,
     621,  619,    6,    6, 0x2a,
     635,    6,    6,    6, 0x2a,
     651,  643,    6,    6, 0x0a,
     677,  671,    6,    6, 0x2a,
     690,    6,    6,    6, 0x2a,
     697,    6,    6,    6, 0x0a,
     711,   74,    6,    6, 0x0a,
     732,    6,    6,    6, 0x0a,
     744,   74,    6,    6, 0x0a,
     769,  347,    6,    6, 0x0a,
     805,  384,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Robot[] = {
    "Robot\0\0changedValues()\0i,w\0"
    "EngineSteered(int,double)\0i\0"
    "EngineStopped(int)\0w\0CylinderSetToZero(double)\0"
    "pos\0ArmPositionChanged(POSITION)\0on\0"
    "Electromagnet(bool)\0Teleoperation()\0"
    "StoppedAll()\0StartedAll()\0v,t\0"
    "DrivenForward(double,double)\0a,t\0"
    "Turned(double,double)\0StoppedDriving()\0"
    "Mined()\0CylinderMoved(double)\0"
    "Calibrated()\0CylinderSetToGround(double)\0"
    "U,I\0CurrentVoltageSet(double,double)\0"
    "m\0MassChanged(double)\0readResponse()\0"
    "connected()\0updateValues()\0"
    "EngineSteer(int,double)\0EngineStop(int)\0"
    "CylinderToZero(int)\0SetArmPosition(POSITION)\0"
    "On\0SetElectromagnet(bool)\0TeleoperationOn()\0"
    "StopAll()\0StartAll()\0Drive(double,double)\0"
    "v\0Drive(double)\0Drive()\0angle,t\0"
    "Turn(double,double)\0angle\0Turn(double)\0"
    "Turn()\0StopDriving()\0CylinderMove(double)\0"
    "Calibrate()\0CylinderToGround(double)\0"
    "SetMaxCurrentVoltage(double,double)\0"
    "MassChange(double)\0"
};

void Robot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Robot *_t = static_cast<Robot *>(_o);
        switch (_id) {
        case 0: _t->changedValues(); break;
        case 1: _t->EngineSteered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->EngineStopped((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->CylinderSetToZero((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->ArmPositionChanged((*reinterpret_cast< POSITION(*)>(_a[1]))); break;
        case 5: _t->Electromagnet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->Teleoperation(); break;
        case 7: _t->StoppedAll(); break;
        case 8: _t->StartedAll(); break;
        case 9: _t->DrivenForward((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 10: _t->Turned((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 11: _t->StoppedDriving(); break;
        case 12: _t->Mined(); break;
        case 13: _t->CylinderMoved((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->Calibrated(); break;
        case 15: _t->CylinderSetToGround((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->CurrentVoltageSet((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 17: _t->MassChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->readResponse(); break;
        case 19: _t->connected(); break;
        case 20: _t->updateValues(); break;
        case 21: _t->EngineSteer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 22: _t->EngineStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->CylinderToZero((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->SetArmPosition((*reinterpret_cast< POSITION(*)>(_a[1]))); break;
        case 25: _t->SetElectromagnet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->TeleoperationOn(); break;
        case 27: _t->StopAll(); break;
        case 28: _t->StartAll(); break;
        case 29: _t->Drive((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 30: _t->Drive((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->Drive(); break;
        case 32: _t->Turn((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 33: _t->Turn((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 34: _t->Turn(); break;
        case 35: _t->StopDriving(); break;
        case 36: _t->CylinderMove((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: _t->Calibrate(); break;
        case 38: _t->CylinderToGround((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 39: _t->SetMaxCurrentVoltage((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 40: _t->MassChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Robot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Robot::staticMetaObject = {
    { &IDiggingSystem::staticMetaObject, qt_meta_stringdata_Robot,
      qt_meta_data_Robot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Robot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Robot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Robot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Robot))
        return static_cast<void*>(const_cast< Robot*>(this));
    if (!strcmp(_clname, "IDrivingSystem"))
        return static_cast< IDrivingSystem*>(const_cast< Robot*>(this));
    return IDiggingSystem::qt_metacast(_clname);
}

int Robot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IDiggingSystem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}

// SIGNAL 0
void Robot::changedValues()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Robot::EngineSteered(int _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Robot::EngineStopped(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Robot::CylinderSetToZero(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Robot::ArmPositionChanged(POSITION _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Robot::Electromagnet(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Robot::Teleoperation()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Robot::StoppedAll()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Robot::StartedAll()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Robot::DrivenForward(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Robot::Turned(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Robot::StoppedDriving()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void Robot::Mined()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void Robot::CylinderMoved(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Robot::Calibrated()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void Robot::CylinderSetToGround(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Robot::CurrentVoltageSet(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Robot::MassChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}
QT_END_MOC_NAMESPACE
