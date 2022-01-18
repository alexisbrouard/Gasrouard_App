#ifndef INDEXER_H
#define INDEXER_H

#include <QCoreApplication>
#include <QString>
#include <QDirIterator>
#include <QVector>
#include <QThread>
#include <QThreadPool>
#include <QObject>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>

#include "database.h"

class Indexer : QObject
{
    Q_OBJECT
public:
    Indexer();
    ~Indexer();
    void scanRepository(QString m_start_path);
    void sendDatabase();
private:
    QVector<QStringList> _vectorIndexes;
    Database _db;
    QThreadPool _pool;
};

#endif // INDEXER_H
