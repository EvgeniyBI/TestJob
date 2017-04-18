#include <SizeFile.h>

SizeFile::SizeFile()
{
connect (this ,&SizeFile::getCharacters,this,&SizeFile::onGetCharacters);
connect (this, &SizeFile::finished, &MyThread, &QThread::quit);

this->moveToThread(&MyThread);
MyThread.start();
}

void SizeFile::onGetCharacters(const QString &str)
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
