#include "database.h"

Database::Database()
{
    _Database = QSqlDatabase::addDatabase("QSQLITE");
    _Database.setDatabaseName("");
    if(!_Database.open())
    {
        qDebug() << "Erreur : Connexion à la base de données perdue";
    }
    else
    {
        qDebug() << "Database : Connexion ok";
    }
}

void Database::setupDB()
{
    QString tblIndexes = "CREATE TABLE IF NOT EXISTS files("
                         "id           INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "pat          STRING,"
                         "name         STRING,"
                         "suffix       STRING,"
                         "size         STRING,"
                         "status       STRING"
                         ")";
    QSqlQuery query;
    query.exec(tblIndexes);
    if (query.lastError().isValid()) {
        qWarning() << "Query invalide";
    }
    qDebug() << __FUNCTION__ << __LINE__ << "Database crée / connectée";
}

void Database::addDatabase(QVector<QStringList> _vectorIndexes)
{
    QSqlQuery query;

    query.prepare("INSERT INTO values(file_path, file_name, file_extension, file_size) VALUES(?, ?, ?, ?)");

    for(int i = 0, k = 0; i< _vectorIndexes.size(); i++)
    {
        for(int j = 0; j < 3; j++)
        {
            query.bindValue(k,_vectorIndexes.at(i).at(j));
            k++;
        }
    }


}
