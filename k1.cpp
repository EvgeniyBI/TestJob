#include <k1.h>

K1::K1()
{

}

void K1::getCharacters(const std::string *str)
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
