#pragma once
#include <QObject>
#include <QFile>

class K1: public QObject
{
    Q_OBJECT
public:
    K1();
    void getCharacters(const std::string * str);
signals:
    void display(int);
    void finished();
};
