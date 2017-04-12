#pragma once
#include <QThread>

class ThreadK1:public QThread
{
    Q_OBJECT
public:
    ThreadK1()
    {

    }

    void run()
    {
        exec();
    }
};
