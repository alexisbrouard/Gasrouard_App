#include "get_cmd.h"

Get_cmd::Get_cmd() : CommandFactory() {}

bool Get_cmd::execute(QMap<Options, QString> args)
{
    bool res = FAILURE;

    Options currentOption = getKey(args, "FLAG");

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

Options Get_cmd::getKey(const QMap<Options, QString> &map, const QString &value)
{
    QMapIterator<Options, QString> i(map);
    while (i.hasNext()) {
        i.next();
        if (i.value() == value)
        return i.key();
    }
    return (Options::UNDEFINED);
}

QString Get_cmd::getValue(const QMap<Options, QString> &map, Options searchedOption)
{
    auto it = map.find(searchedOption);
    return it.value();
}

bool Get_cmd::isKeyPresent(const QMap<Options, QString> &map, Options searchedKey)
{
    if (map.find(searchedKey) == map.end())
        return FAILURE;
    return SUCCESS;
}

bool Get_cmd::handleBlackList(const QMap<Options, QString> args)
{
    if (args.empty())
        return FAILURE;

    std::cout << "Getting All files BlackListed" << std::endl;

    QSqlQuery query("SELECT * FROM files WHERE status = 'BLACKLIST'");
    while (query.next()) {
           qDebug() << "File BlackListed: " << query.value(2).toString();
    }

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }

    QSqlQuery retCount("SELECT COUNT(*) FROM files WHERE status = 'BLACKLIST'");

    if(retCount.lastError().isValid())
    {
        qWarning() << retCount.lastError().text();
        return FAILURE;
    }

    retCount.first();
    qDebug() << "There are " << retCount.value(0).toInt() << " files with status BLACKLIST";
    return SUCCESS;
}

bool Get_cmd::handleFilters(const QMap<Options, QString> args)
{
    std::cout << "Getting Filters Files" << std::endl;

    if (args.empty())
        return FAILURE;

    QSqlQuery retRes("SELECT * FROM files WHERE status = 'FILTERS'");
    while (retRes.next()) {
           qDebug() << "File FILTERS: " << retRes.value(2).toString();
    }

    if(retRes.lastError().isValid())
    {
        qWarning() << retRes.lastError().text();
        return FAILURE;
    }

    QSqlQuery retCount("SELECT COUNT(*) FROM files WHERE status = 'FILTERS'");

    if(retCount.lastError().isValid())
    {
        qWarning() << retCount.lastError().text();
        return FAILURE;
    }

    retCount.first();
    qDebug() << "There are " << retCount.value(0).toInt() << " files with status Filters";
    return SUCCESS;
}

bool Get_cmd::handleSkippedFilters(const QMap<Options, QString> args)
{
    std::cout << "Getting All Skipped Filters Files" << std::endl;

    if (args.empty())
        return FAILURE;

    QSqlQuery query;
    query.prepare("SELECT * FROM files WHERE status = 'SKIPPED_FILTERS'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }

    QSqlQuery retRes("SELECT * FROM files WHERE status = 'SKIPPED_FILTERS'");
    while (retRes.next()) {
           qDebug() << "File SKIPPED_FILTERS: " << retRes.value(2).toString();
    }

    QSqlQuery retCount("SELECT COUNT(*) FROM files WHERE status = 'SKIPPED_FILTERS'");

    if(retCount.lastError().isValid())
    {
        qWarning() << retCount.lastError().text();
        return FAILURE;
    }

    retCount.first();
    qDebug() << "There are " << retCount.value(0).toInt() << " files with status SKIPPED_FILTERS";
    return SUCCESS;
}

bool Get_cmd::handleWhiteList(const QMap<Options, QString> args)
{
    std::cout << "Getting All files WhiteListed" << std::endl;

    if (args.empty())
        return FAILURE;

    QSqlQuery query("SELECT * FROM files WHERE status = 'WHITELIST'");
    while (query.next()) {
           qDebug() << "File WhiteListed: " << query.value(2).toString();
    }

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }

    QSqlQuery retCount("SELECT COUNT(*) FROM files WHERE status = 'WHITELIST'");

    if(retCount.lastError().isValid())
    {
        qWarning() << retCount.lastError().text();
        return FAILURE;
    }

    retCount.first();
    qDebug() << "There are " << retCount.value(0).toInt() << " file(s) with status WHITELIST";

    return SUCCESS;
}
