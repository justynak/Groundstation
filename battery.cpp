#include "battery.h"

Battery::Battery(QObject *parent) :
    QObject(parent)
{
    current = voltage = 0;
}
