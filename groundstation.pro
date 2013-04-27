#-------------------------------------------------
#
# Project created by QtCreator 2013-02-10T12:24:58
#
#-------------------------------------------------

QT       += core gui \
            network \
            svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = groundstation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        Robot.cpp\
        Arm.cpp\
        Cylinder.cpp\
        Engine.cpp\
        IDiggingSystem.cpp\
        IDrivingSystem.cpp\
        drawArrow.cpp \
         scada.cpp \
         battery.cpp \
         sciaga.cpp


HEADERS  += mainwindow.h \
            Robot.h\
            Arm.h\
            Cylinder.h\
            Engine.h\
            IDiggingSystem.h\
            IDrivingSystem.h\
            Wheel.h \
            drawArrow.h \
            scada.h \
            battery.h \
            sciaga.h

FORMS    += mainwindow.ui \
            scada.ui \
            sciaga.ui

RESOURCES += src.qrc

LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/qt4/plugins/designer/ -lqledplugin
INCLUDEPATH += $$PWD/../../../../usr/lib/qt4/examples/designer/qledplugin
DEPENDPATH += $$PWD/../../../../usr/lib/qt4/examples/designer/qledplugin
LIBS += -L$$PWD/../../../../opt/ros/fuerte/lib/ -lopencv_core -lopencv_calib3d -lopencv_highgui -lopencv_imgproc
INCLUDEPATH += $$PWD/../../../../opt/ros/fuerte/include/opencv2
DEPENDPATH += $$PWD/../../../../opt/ros/fuerte/include/opencv2
INCLUDEPATH += $$PWD/../../../../opt/ros/fuerte/include/opencv
DEPENDPATH += $$PWD/../../../../opt/ros/fuerte/include/opencv
