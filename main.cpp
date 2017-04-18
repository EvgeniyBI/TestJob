//#include <QCoreApplication>
#include<QApplication>
#include <QDebug>
#include <iterator>
#include <QLCDNumber>
#include <QThread>
//#include "buf.h"
#include "K1.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // VectorMt<double>  p;
    /*for(int i = 0; i <6; i++) {
        double   n = i*5.3;
        p.push_back(n);
    }
    p.deleteElement(3);

    qDebug() <<p[3];

    list<double> v(p.begin(),p.end());

    for(list<double>::iterator it = v.begin(); it != v.end(); ++it) {
        qDebug() <<*it;
    }
    qDebug() <<"++++++++++++++++++++++";
   for(int i = 0;i<15;i++) {
        qDebug() <<++p;
    }*/
    QLCDNumber  lsd;
    K1 p;
    QObject::connect(&p, SIGNAL(display(int)), &lsd, SLOT(display(int)));
    lsd.setSegmentStyle(QLCDNumber::Filled);
    lsd.display(10);
    lsd.resize(220,90);
    lsd.show();

    qDebug() <<QThread::currentThreadId();
    QString Directory = "D:\\123.txt";
    emit p.getCharacters(Directory);
    return a.exec();
}
