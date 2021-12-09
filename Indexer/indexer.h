#ifndef INDEXER_H
#define INDEXER_H

#include "Indexer_global.h"
#include "database.h"

#include <QDir>
#include <QDirIterator>

class INDEXER_EXPORT Indexer
{
public:
    Indexer();
    ~Indexer();
    void scanRepository(QString m_start_path);
};

#endif // INDEXER_H
