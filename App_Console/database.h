#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStringList>

class Database
{
public:
    Database();
    void setupDB();
    void addDatabase(QVector<QStringList> _VectorIndexes);
private:
    QSqlDatabase _Database;
};

#endif // DATABASE_H
