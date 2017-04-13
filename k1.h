#pragma once
#include <QObject>
#include <QFile>

class K1: public QObject
{
    Q_OBJECT
public:
    K1();

signals:
    void getCharacters(const std::string * str);
    void display(int);
    void finished();
protected slots:
    void onGetCharacters(const std::string * str);
};
