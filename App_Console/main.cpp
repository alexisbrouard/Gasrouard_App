#include <QCoreApplication>
#include <QString>

#include "indexer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Indexer indexer;
    QTimer timer;
    indexer.scanRepository("C:/Users");

    return a.exec();
}
