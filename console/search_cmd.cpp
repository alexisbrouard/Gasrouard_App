#include "search_cmd.h"

Search_cmd::Search_cmd() : CommandFactory()
{
}

bool Search_cmd::execute(QMap<Options, QString> args)
{
    bool res = FAILURE;

    QMapIterator<Options, QString> i(args);
    while (i.hasNext()) {
        i.next();
        qDebug() << "Key: " << i.key() << " value: " << i.value();
    }
    return res;
}

Options Search_cmd::getKey(const QMap<Options, QString> &map, const QString &value)
{
    QMapIterator<Options, QString> i(map);
    while (i.hasNext()) {
        i.next();
        if (i.value() == value)
        return i.key();
    }
    return (Options::UNDEFINED);
}

QString Search_cmd::getValue(const QMap<Options, QString> &map, Options searchedOption)
{
    auto it = map.find(searchedOption);
    return it.value();
}

bool Search_cmd::isKeyPresent(const QMap<Options, QString> &map, Options searchedKey)
{
    if (map.find(searchedKey) == map.end())
        return FAILURE;
    return SUCCESS;
}

bool Search_cmd::handleBlackList(const QMap<Options, QString> args)
{
    if (args.empty())
        return FAILURE;

    QSqlQuery query;
    query.prepare("");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}

bool Search_cmd::handleFilters(const QMap<Options, QString> args)
{   
    if (args.empty())
        return FAILURE;

    QSqlQuery query;
    query.prepare("");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}

bool Search_cmd::handleSkippedFilters(const QMap<Options, QString> args)
{   
    if (args.empty())
        return FAILURE;

    QSqlQuery query;
    query.prepare("");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}

bool Search_cmd::handleWhiteList(const QMap<Options, QString> args)
{
    if (args.empty())
        return FAILURE;

    QSqlQuery query;
    query.prepare("");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}
