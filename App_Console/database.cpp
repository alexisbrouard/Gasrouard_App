#include "database.h"

Database::Database()
{
    _pool.setMaxThreadCount(1);
    _Database = QSqlDatabase::addDatabase("QSQLITE, QODBC, QPSQL");
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
                         "modified     DATE,"
                         "status       STRING"
                         ")";
    QSqlQuery query;
    query.exec(tblIndexes);
    if (query.lastError().isValid()) {
        qWarning() << "Query invalide";
    }
    qDebug() << __FUNCTION__ << __LINE__ << "Database créée / connectée";
}

bool Database::addDatabase(QVector<QStringList> _vectorIndexes)
{
    QFuture<void> future =  QtConcurrent::run(&_pool, [this, _vectorIndexes]() {
        QSqlQuery query;

        query.prepare("INSERT INTO files(path, name, suffix, size, modified, status) VALUES(?, ?, ?, ?, ?, ?)");

        for(int i = 0; i< _vectorIndexes.size(); i++)
        {
            for(int j = 0; j <= 5; j++)
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
    return false;
}
