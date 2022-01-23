#include "add_cmd.h"

Add_cmd::Add_cmd() : CommandFactory()
{
}

bool Add_cmd::execute(QMap<Options, QString> args)
{
    bool res = FAILURE;

    Options currentOption = getKey(args, "FLAG");

    switch (currentOption) {
        case BLACKLIST :
            res = handleBlackList(args);
            break;
        case WHITELIST :
            res = handleWhiteList(args);
            break;
        case FILTERS :
            res = handleFilters(args);
            break;
        case SKIPPED_FILTERS :
            res = handleSkippedFilters(args);
            break;
        default:
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
    QSqlQuery query;
    QString temp_filename = getValue(args, FOLDER_PATH);
    query.prepare("UPDATE files SET status = 'BLACKLIST' WHERE name = '" + temp_filename + "'");
    query.exec();

    query.first();
    query.next();
    const QString result = query.value(0).toString();
    qDebug() << "Updated " << result << " to blacklist status";

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }

    qDebug() << "Updated " << temp_filename << " to BlackList status";

    return SUCCESS;
}

bool Add_cmd::handleFilters(const QMap<Options, QString> args)
{
    QSqlQuery query;
    QString temp_suffix = getValue(args, FOLDER_PATH);
    temp_suffix.remove("*.");
    query.prepare("UPDATE files SET status = 'FILTERS' WHERE suffix = '" + temp_suffix + "'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }

    qDebug() << "Updated all files with " << temp_suffix << " extension to Filters status";

    return SUCCESS;
}

bool Add_cmd::handleSkippedFilters(const QMap<Options, QString> args)
{
    QSqlQuery query;
    QString temp_suffix = getValue(args, FOLDER_PATH);
    temp_suffix.remove("*.");
    query.prepare("UPDATE files SET status = 'FILTERS' WHERE suffix = '" + temp_suffix + "'");
    query.exec();

    //Handle Error
    if(query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
        return FAILURE;
    }

    qDebug() << "Updated " << temp_suffix << " to Skipped Filters status";

    return SUCCESS;
}

bool Add_cmd::handleWhiteList(const QMap<Options, QString> args)
{
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

    qDebug() << "Updated " << temp_filename << " to WhiteList status";

    return SUCCESS;
}
