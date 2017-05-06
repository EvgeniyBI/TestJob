#include<QApplication>
#include <QDebug>
#include <QTest>
#include <iterator>
#include <QLCDNumber>
#include <QThread>
#include "SizeFile.h"
//#include "test_sizefile.h"


int main(int argc, char *argv[])
{
    freopen("testing.log", "w", stdout);
    QApplication a(argc, argv);
    QTest::qExec(new test_sizefile, argc, argv);

    return 0;
}
