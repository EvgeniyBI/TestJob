#include <k1.h>

K1::K1()
{
connect (this ,&K1::getCharacters,this,&K1::onGetCharacters);
connect (this, &K1::finished, &MyThread, &QThread::quit);

this->moveToThread(&MyThread);
MyThread.start();
}

void K1::onGetCharacters(const QString &str)
{
     qDebug() <<QThread::currentThreadId();
     QFile file(str);
     int length;
     if(file.open(QIODevice::ReadOnly)) {
        length = file.size();
        file.close();
     } else {
        length = 0;
     }
     emit display(length);
     emit finished();
}
