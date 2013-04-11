/****************************************************************************
** Meta object code from reading C++ file 'scada.h'
**
** Created: Thu Apr 11 14:32:43 2013
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
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      26,   22,    6,    6, 0x0a,
      52,   50,    6,    6, 0x0a,
      70,   68,    6,    6, 0x0a,
      97,   93,    6,    6, 0x0a,
     122,  119,    6,    6, 0x0a,
     145,    6,    6,    6, 0x0a,
     163,    6,    6,    6, 0x0a,
     173,    6,    6,    6, 0x0a,
     188,  184,    6,    6, 0x0a,
     217,  209,    6,    6, 0x0a,
     237,    6,    6,    6, 0x0a,
     251,    6,    6,    6, 0x0a,
     257,   68,    6,    6, 0x0a,
     278,    6,    6,    6, 0x0a,
     290,   68,    6,    6, 0x0a,
     319,  315,    6,    6, 0x0a,
     357,  355,    6,    6, 0x0a,
     376,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SCADA[] = {
    "SCADA\0\0UpdateValues()\0i,w\0"
    "EngineSteer(int,double)\0i\0EngineStop(int)\0"
    "w\0CylinderToZero(double)\0pos\0"
    "ArmPosition(POSITION)\0on\0"
    "SetElectromagnet(bool)\0TeleoperationOn()\0"
    "StopAll()\0StartAll()\0v,t\0Drive(double,double)\0"
    "angle,t\0Turn(double,double)\0StopDriving()\0"
    "Dig()\0CylinderMove(double)\0Calibrate()\0"
    "CylinderToGround(double)\0U,I\0"
    "SetMaxCurrentVoltage(double,double)\0"
    "m\0MassChange(double)\0updateImageCam()\0"
};

void SCADA::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SCADA *_t = static_cast<SCADA *>(_o);
        switch (_id) {
        case 0: _t->UpdateValues(); break;
        case 1: _t->EngineSteer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->EngineStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->CylinderToZero((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->ArmPosition((*reinterpret_cast< POSITION(*)>(_a[1]))); break;
        case 5: _t->SetElectromagnet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->TeleoperationOn(); break;
        case 7: _t->StopAll(); break;
        case 8: _t->StartAll(); break;
        case 9: _t->Drive((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 10: _t->Turn((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 11: _t->StopDriving(); break;
        case 12: _t->Dig(); break;
        case 13: _t->CylinderMove((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->Calibrate(); break;
        case 15: _t->CylinderToGround((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->SetMaxCurrentVoltage((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 17: _t->MassChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->updateImageCam(); break;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
