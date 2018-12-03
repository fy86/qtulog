#include <QCoreApplication>

#include "udplog.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    udplog ulog;

    ulog.init();

    return a.exec();
}

