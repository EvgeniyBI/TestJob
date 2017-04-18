#pragma once
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QFile>

class K1: public QObject
{
    Q_OBJECT
public:
    K1();
protected:
    QThread MyThread;

signals:
    void getCharacters(const QString &str);
    void display(int);
    void finished();
protected slots:
    void onGetCharacters(const QString &str);
};
