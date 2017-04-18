#include<QApplication>
#include <QDebug>
#include <iterator>
#include <QLCDNumber>
#include <QThread>
#include "K1.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLCDNumber  lsd;
    K1 loadFile;
    QObject::connect(&loadFile, SIGNAL(display(int)), &lsd, SLOT(display(int)));
    lsd.setSegmentStyle(QLCDNumber::Filled);
    lsd.display(10);
    lsd.resize(220,90);
    lsd.show();

    qDebug() <<QThread::currentThreadId();
    QString Directory = "D:\\123.txt";
    loadFile.getCharacters(Directory);
    return a.exec();
}
