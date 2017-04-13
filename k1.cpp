#include <k1.h>

K1::K1()
{
connect(this ,&K1::getCharacters,this,&K1::onGetCharacters);
}

void K1::onGetCharacters(const std::string *str)
{
     QString dir = QString::fromUtf8(str->c_str());
     QFile file(dir);
     int length;
     if(file.open(QIODevice::ReadOnly)) {
        length = file.size();
     } else {
        length = 0;
     }
     emit display(length);
     emit finished();
}
