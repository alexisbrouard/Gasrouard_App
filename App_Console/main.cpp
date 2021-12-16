#include <QCoreApplication>
#include "indexer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Indexer indexer;

    indexer.scanRepository("D:/JEUX");

    return a.exec();
}
