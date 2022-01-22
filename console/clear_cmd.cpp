#include "clear_cmd.h"

Clear_cmd::Clear_cmd() : CommandFactory()
{
}

bool Clear_cmd::execute(QMap<Options, QString> args)
{
    bool res = FAILURE;

    Options currentOption = getKey(args, "FLAG");
    //qDebug() << "FLAG: " << currentOption << "| CMD : CLEAR" ;

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

Options Clear_cmd::getKey(const QMap<Options, QString> &map, const QString &value)
{
    QMapIterator<Options, QString> i(map);
    while (i.hasNext()) {
        i.next();
        if (i.value() == value)
        return i.key();
    }
    return (Options::UNDEFINED);
}

QString Clear_cmd::getValue(const QMap<Options, QString> &map, Options searchedOption)
{
    auto it = map.find(searchedOption);
    return it.value();
}

bool Clear_cmd::isKeyPresent(const QMap<Options, QString> &map, Options searchedKey)
{
    if (map.find(searchedKey) == map.end())
        return FAILURE;
    return SUCCESS;
}

bool Clear_cmd::handleBlackList(const QMap<Options, QString> args)
{
    std::cout << "Clearing all BlackListed Files" << std::endl;

    if (args.empty())
        return FAILURE;

    QSqlQuery query;
    query.prepare("DELETE FROM files WHERE status = 'BLACKLIST'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}

bool Clear_cmd::handleFilters(const QMap<Options, QString> args)
{
    std::cout << "Clearing all Filters Files" << std::endl;

    if (args.empty())
        return FAILURE;

    QSqlQuery query;
    query.prepare("DELETE FROM files WHERE status = 'FILTERS'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}

bool Clear_cmd::handleSkippedFilters(const QMap<Options, QString> args)
{
    std::cout << "Clearing all Skipped Filters Files" << std::endl;

    if (args.empty())
        return FAILURE;

    QSqlQuery query;
    query.prepare("DELETE FROM files WHERE status = 'SKIPPED_FILTERS'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}

bool Clear_cmd::handleWhiteList(const QMap<Options, QString> args)
{
    std::cout << "Removing all WhiteListed Files" << std::endl;

    if (args.empty())
        return FAILURE;

    QSqlQuery query;
    query.prepare("DELETE FROM files WHERE status = 'WHITELIST'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}
