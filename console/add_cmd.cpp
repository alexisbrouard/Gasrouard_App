#include "add_cmd.h"

Add_cmd::Add_cmd() : CommandFactory()
{
}

bool Add_cmd::execute(QMap<Options, QString> args)
{
    bool res = FAILURE;

    Options currentOption = getKey(args, "FLAG");
    //qDebug() << "FLAG: " << currentOption << "| CMD : ADD" ;

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

Options Add_cmd::getKey(const QMap<Options, QString> &map, const QString &value)
{
    QMapIterator<Options, QString> i(map);
    while (i.hasNext()) {
        i.next();
        if (i.value() == value)
        return i.key();
    }
    return (Options::UNDEFINED);
}

QString Add_cmd::getValue(const QMap<Options, QString> &map, Options searchedOption)
{
    auto it = map.find(searchedOption);
    return it.value();
}

bool Add_cmd::isKeyPresent(const QMap<Options, QString> &map, Options searchedKey)
{
    if (map.find(searchedKey) == map.end())
        return FAILURE;
    return SUCCESS;
}

bool Add_cmd::handleBlackList(const QMap<Options, QString> args)
{
    std::cout << "Adding Blacklisted status to file" << std::endl;

    QSqlQuery query;
    QString temp_filename = getValue(args, FOLDER_PATH);
    query.prepare("UPDATE files SET status = 'BLACKLIST' WHERE name = '" + temp_filename + "'"); // UNDEFINED
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}

bool Add_cmd::handleFilters(const QMap<Options, QString> args)
{
    std::cout << "Adding Filters" << std::endl;

    QSqlQuery query;
    QString temp_filename = getValue(args, FOLDER_PATH);
    query.prepare("UPDATE files SET status = 'FILTERS' WHERE name = '" + temp_filename + "'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}

bool Add_cmd::handleSkippedFilters(const QMap<Options, QString> args)
{
    std::cout << "Adding Skipped Filters" << std::endl;

    QSqlQuery query;
    QString temp_filename = getValue(args, FOLDER_PATH);
    query.prepare("UPDATE files SET status = 'SKIPPED_FILTERS' WHERE name = '" + temp_filename + "'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}

bool Add_cmd::handleWhiteList(const QMap<Options, QString> args)
{
    std::cout << "Adding WhiteListed Files" << std::endl;

    QSqlQuery query;
    QString temp_filename = getValue(args, FOLDER_PATH);
    query.prepare("UPDATE files SET status = 'WHITELIST' WHERE name = '" + temp_filename + "'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }
    return SUCCESS;
}
