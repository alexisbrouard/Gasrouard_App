#include "get_cmd.h"

Get_cmd::Get_cmd() : CommandFactory()
{
}

bool Get_cmd::execute(QMap<Options, QString> args)
{
    bool res = false;

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
            res = false;
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
        return false;
    return true;
}

bool Get_cmd::handleBlackList(const QMap<Options, QString> args)
{}

bool Get_cmd::handleFilters(const QMap<Options, QString> args)
{}

bool Get_cmd::handleSkippedFilters(const QMap<Options, QString> args)
{}

bool Get_cmd::handleWhiteList(const QMap<Options, QString> args)
{}
