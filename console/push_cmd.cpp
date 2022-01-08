#include "push_cmd.h"

Push_cmd::Push_cmd() : CommandFactory()
{

}

bool Push_cmd::execute(QMap<Options, QString> args)
{
    bool res = false;

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
            res = false;
            break;
    }
    return res;
    return false;
}


bool Push_cmd::handleBlackList(const QMap<Options, QString> args)
{
    if (args.empty()) // useless but usefull to wipe out the fucking warning
        return false;
    return true;
}

bool Push_cmd::handleFilters(const QMap<Options, QString> args)
{
    if (args.empty())
        return false;
    return true;
}

bool Push_cmd::handleSkippedFilters(const QMap<Options, QString> args)
{
    if (args.empty())
        return false;
    return true;
}

bool Push_cmd::handleWhiteList(const QMap<Options, QString> args)
{
    if (args.empty())
        return false;
      qDebug() << "WHITELIST Handled";
      qDebug() << getValue(args, FOLDER_PATH);
      return true;
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
        return false;
    return true;
}
