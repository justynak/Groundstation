#include <QApplication>
#include "mainwindow.h"
#include "scada.h"
#include "Robot.h"
#include"sciaga.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Robot* robot = new Robot(0,0,0);
    MainWindow w;
    w.robot = robot;
    w.initialize();
    w.show();

    SCADA s;
    s.robot = robot;
    s.initialize();
    s.show();

    Sciaga sciaga;
    sciaga.show();

    return a.exec();
}
