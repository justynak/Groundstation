#include "drawArrow.h"
#include <cstdlib>


void paintArrowWheel( QPoint pt, double v, double sze, QPainter& painter){
    QPoint pd, pa, pb;
    double tangent;
    v=v*100;

    QPoint ppt(pt.rx()+v, pt.ry());
    tangent = 0*3.14/180;
    pa.setX(sze * cos (tangent + M_PI / 7) + pt.rx());
    pa.setY(sze * sin (tangent + M_PI / 7) + pt.ry());
    pb.setX( sze * cos (tangent - M_PI / 7) + pt.rx());
    pb.setY( sze * sin (tangent - M_PI / 7) + pt.ry());

    painter.setPen(QPen(Qt::green, 2));
    painter.drawLine(pa, pt);
    painter.drawLine(pb,pt);
    painter.drawLine(pt,ppt);
}

void paintArrowSpeed(QPoint pt, double v, double sze, QPainter& painter){

    QPoint pd, pa, pb;
    double tangent;
    v*=100;

    QPoint ppt(pt.rx()+v, pt.ry());
    QPoint t(pt.rx()+10, pt.ry()-10);

    tangent =0*3.14/180;
    pa.setX(sze * cos (tangent + M_PI / 7) + pt.rx());
    pa.setY(sze * sin (tangent + M_PI / 7) + pt.ry());
    pb.setX( sze * cos (tangent - M_PI / 7) + pt.rx()); //pt.rx()
    pb.setY( sze * sin (tangent - M_PI / 7) + pt.ry()); //pt.ry()

    painter.setPen(QPen(Qt::red, 3));
    painter.drawLine(pa, pt);
    painter.drawLine(pb,pt);
    painter.drawLine(pt,ppt);

    v=v/100;
    painter.drawText(t, QString("v= %1 [m/s]").arg(v));
}

void paintLocation(double* point, double v, double sze, double a, QPixmap& pic, QPainter& painter){
    //QPainter painter(edit);
    QPoint p(490-point[1]*20, 332-point[0]*20);
    QPoint r(p.rx()+30, p.ry()+30);
    painter.translate(QPoint(-94,-64));
    painter.translate(r);
    if(a!=0) painter.rotate(-a);
    painter.drawPixmap(QPoint(-30,-30), pic);
    painter.rotate(a);
    painter.translate(-r);

    double tangent = point[2]*3.14/180;
    ///cos ze strzalka!!!!
    QPoint ppt(p.rx()+v*20*sin(tangent), p.ry()+v*20*cos(tangent));
    QPoint pa, pb;

    pa.setX(-sze * cos (tangent - M_PI / 7) + ppt.rx());
    pa.setY(-sze * sin (tangent - M_PI / 7) + ppt.ry());
    pb.setX( -sze * cos (tangent + M_PI / 7) + ppt.rx());
    pb.setY( -sze * sin (tangent + M_PI / 7) + ppt.ry());

    painter.setPen(QPen(Qt::blue, 1));
    painter.drawLine(pa, p);

    painter.drawLine(pb,p);
    painter.drawLine(p,ppt);

    painter.drawText(ppt, QString("[%1; %2; %3]").arg(point[0]).arg(point[1]).arg(point[2]));
}

void paintCylinderWeight(QPoint p, double w, QPainter& painter){

    painter.setPen(QPen(Qt::darkMagenta, 1));
    painter.drawText(p,QString("Mass: %1 kg").arg(w));
}

void paintArmPosition(QPoint p, double pos, QPainter& painter){
    painter.setPen(QPen(Qt::darkMagenta, 1));
    painter.drawText(p, QString("Position %1").arg(pos));

}
