#include <SizeFile.h>

SizeFile::SizeFile()
{
connect (this ,&SizeFile::getCharacters,this,&SizeFile::onGetCharacters);
connect (this, &SizeFile::finished, &MyThread, &QThread::quit);

this->moveToThread(&MyThread);
MyThread.start();
}

int SizeFile::onGetCharacters(const QString &str)
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
     return length;
}


test_sizefile::test_sizefile(QObject *parent):
    QObject(parent)
{

}

void test_sizefile::onGetCharacters()
{
    SizeFile test_Object;
    QFile file("D:\\123.txt");
    for(int i = 0;i<3;i++) {
        if(file.open(QIODevice::WriteOnly)) {

            switch (i) {
            case 0:
                file.write("1");
                file.close();
                value = 1;
                break;
            case 1:
                file.write("12");
                file.close();
                value = 2;
                break;
            case 2:
                file.write("123");
                file.close();
                value = 3;
                break;
            }
        QString Directory = "D:\\123.txt";
        QCOMPARE(test_Object.onGetCharacters(Directory), value);
        }
    }
}
