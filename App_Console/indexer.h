#ifndef INDEXER_H
#define INDEXER_H

#include <QString>
#include <QDirIterator>
#include <QVector>

#include "database.h"

class Indexer
{
public:
    Indexer();
    void scanRepository(QString m_start_path);
    void sendDatabase();
private:
    QVector<QStringList> _vectorIndexes;
    Database _db;
};

#endif // INDEXER_H
