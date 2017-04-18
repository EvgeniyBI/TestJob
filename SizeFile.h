#pragma once
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QFile>

class SizeFile: public QObject
{
    Q_OBJECT
public:
    SizeFile();
protected:
    QThread MyThread;

signals:
    void getCharacters(const QString &str);
    void display(int);
    void finished();
protected slots:
    void onGetCharacters(const QString &str);
};
