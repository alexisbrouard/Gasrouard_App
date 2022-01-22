#define INSERTS_COUNT 10000
#define DISPLAY_EVERY 1000
#define func_width    50

#include "database.h"

Database::Database()
{
    _pool.setMaxThreadCount(1);
    _Database = QSqlDatabase::addDatabase("QSQLITE");
    _Database.setDatabaseName("files.db");
    if(!_Database.open())
    {
        qDebug() << "Erreur : Connexion à la base de données perdue";
    }
    else
    {
        qDebug() << "Database : Connexion ok";
    }

    setupDB();
}

void Database::setupDB()
{
    QString tblIndexes = "CREATE TABLE IF NOT EXISTS files("
                         "id           INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "path         STRING,"
                         "name         STRING,"
                         "suffix       STRING,"
                         "size         STRING,"
                         "creation     DATE,"
                         "modified     DATE,"
                         "status       STRING,"
                         "UNIQUE(path)"
                         ")";
    QSqlQuery query;
    query.exec(tblIndexes);
    if (query.lastError().isValid()) {
        qWarning() << "Query invalide";
    }
    qDebug() << __FUNCTION__ << __LINE__ << "Database créée / connectée";
}

void Database::addDatabase(QVector<QStringList> _vectorIndexes)
{
    QFuture<void> future = QtConcurrent::run(&_pool, [this, _vectorIndexes]() {
        QSqlQuery query(_Database);

        qDebug() <<"Adding to DB";

        query.exec("pragma temp_store = memory");
        query.exec("PRAGMA synchronous = normal");
        query.exec("pragma mmap_size = 30000000000");
        query.exec("PRAGMA journal_mode = wal");
        query.prepare("INSERT OR IGNORE INTO files(path, name, suffix, size, creation, modified, status) VALUES(?, ?, ?, ?, ?, ?, ?)");

        for(int i = 0; i< _vectorIndexes.size(); i++)
        {
            for(int j = 0; j <= 6; j++)
            {
                query.bindValue(j,_vectorIndexes.at(i).at(j));
            }
            if(query.lastError().isValid())
            {
                qWarning() << query.lastError().text();
            }
            query.exec();
        }
    });
}
