#pragma once
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QFile>
#include <QTest>

class test_sizefile: public QObject
{
    Q_OBJECT

public:
    explicit  test_sizefile(QObject *parent = 0);

protected:
    int value = 0;

private slots:
    void onGetCharacters();
};

class SizeFile: public QObject
{
    Q_OBJECT
    friend class test_sizefile;
public:
    SizeFile();
protected:
    QThread MyThread;

signals:
    void getCharacters(const QString &str);
    void display(int);
    void finished();
protected slots:
    int onGetCharacters(const QString &str);
};
