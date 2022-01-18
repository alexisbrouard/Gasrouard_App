#include "push_cmd.h"

Push_cmd::Push_cmd() : CommandFactory()
{
}

bool Push_cmd::execute(QMap<Options, QString> args)
{
    bool res = FAILURE;

    Options currentOption = getKey(args, "FLAG");
    qDebug() << "FLAG: " << currentOption << "| CMD : PUSH" ;

    switch (currentOption) {
        case BLACKLIST :
            res = handleBlackList(args);
            break;
        case FILTERS :
            res = handleFilters(args);
            break;
        case SKIPPED_FILTERS :
            res = handleSkippedFilters(args);
            break;
        case WHITELIST :
            res = handleWhiteList(args);
            break;
        default:
            return FAILURE;
            break;
    }
    return res;
}

Options Push_cmd::getKey(const QMap<Options, QString> &map, const QString &value)
{
    QMapIterator<Options, QString> i(map);
    while (i.hasNext()) {
        i.next();
        if (i.value() == value)
        return i.key();
    }
    return (Options::UNDEFINED);
}

QString Push_cmd::getValue(const QMap<Options, QString> &map, Options searchedOption)
{
    auto it = map.find(searchedOption);
    return it.value();
}

bool Push_cmd::isKeyPresent(const QMap<Options, QString> &map, Options searchedKey)
{
    if (map.find(searchedKey) == map.end())
        return FAILURE;
    return SUCCESS;
}

bool Push_cmd::handleBlackList(const QMap<Options, QString> args)
{
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

bool Push_cmd::handleFilters(const QMap<Options, QString> args)
{
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

bool Push_cmd::handleSkippedFilters(const QMap<Options, QString> args)
{
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

bool Push_cmd::handleWhiteList(const QMap<Options, QString> args)
{
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
