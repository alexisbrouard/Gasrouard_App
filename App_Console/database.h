#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStringList>
#include <QThread>
#include <QThreadPool>
#include <QObject>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>

class Database : QObject
{
    Q_OBJECT
public:
    Database();
    void setupDB();
    void addDatabase(QVector<QStringList> _VectorIndexes);
private:
    QSqlDatabase _Database;
    QThreadPool _pool;
};

#endif // DATABASE_H
