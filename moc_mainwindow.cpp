/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Apr 11 14:32:41 2013
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
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      27,   11,   11,   11, 0x0a,
      41,   11,   11,   11, 0x0a,
      54,   11,   11,   11, 0x0a,
      71,   11,   11,   11, 0x0a,
      88,   11,   11,   11, 0x0a,
     107,   11,   11,   11, 0x0a,
     125,   11,   11,   11, 0x0a,
     135,   11,   11,   11, 0x0a,
     146,   11,   11,   11, 0x0a,
     160,   11,   11,   11, 0x0a,
     175,   11,   11,   11, 0x0a,
     187,   11,   11,   11, 0x0a,
     206,   11,   11,   11, 0x0a,
     229,   11,   11,   11, 0x0a,
     242,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0updateValues()\0EngineSteer()\0"
    "EngineStop()\0CylinderToZero()\0"
    "SetArmPosition()\0SetElectromagnet()\0"
    "TeleoperationOn()\0StopAll()\0StartAll()\0"
    "StopDriving()\0CylinderMove()\0Calibrate()\0"
    "CylinderToGround()\0SetMaxCurrentVoltage()\0"
    "MassChange()\0initialize()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->updateValues(); break;
        case 1: _t->EngineSteer(); break;
        case 2: _t->EngineStop(); break;
        case 3: _t->CylinderToZero(); break;
        case 4: _t->SetArmPosition(); break;
        case 5: _t->SetElectromagnet(); break;
        case 6: _t->TeleoperationOn(); break;
        case 7: _t->StopAll(); break;
        case 8: _t->StartAll(); break;
        case 9: _t->StopDriving(); break;
        case 10: _t->CylinderMove(); break;
        case 11: _t->Calibrate(); break;
        case 12: _t->CylinderToGround(); break;
        case 13: _t->SetMaxCurrentVoltage(); break;
        case 14: _t->MassChange(); break;
        case 15: _t->initialize(); break;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
