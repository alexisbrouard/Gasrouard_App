#include <QCoreApplication>
#include <QString>

#include "indexer.h"

int main(int argc, char *argv[])
{
    // This is dev branch, test
    QCoreApplication a(argc, argv);

    Indexer indexer;
    QTimer timer;
    indexer.scanRepository("F:/");

    return a.exec();
}

