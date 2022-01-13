#include "index_cmd.h"

Index_cmd::Index_cmd() : CommandFactory() {}

bool Index_cmd::execute(QMap<Options, QString> args)
{
    bool res = false;

     Options currentOption = getKey(args, "FLAG");
     qDebug() << "FLAG: " << currentOption << "| CMD : INDEX" ;
     switch (currentOption) {
         case START:
             res = handleStart(args);
             break;
         case RESUME :
             res = handleResume(args);
             break;
         case STOP :
             res = handleStop(args);
             break;
         case PAUSE :
             res = handlePause(args);
             break;
        case STATUS :
            res = handleStatus(args);
         break;
         default:
             res = false;
             break;
     }
     return res;
}


Options Index_cmd::getKey(const QMap<Options, QString> &map, const QString &value)
{
    QMapIterator<Options, QString> i(map);
    while (i.hasNext()) {
        i.next();
        if (i.value() == value)
        return i.key();
    }
    return (Options::UNDEFINED);
}

QString Index_cmd::getValue(const QMap<Options, QString> &map, Options searchedOption)
{
    auto it = map.find(searchedOption);
    return it.value();
}

bool Index_cmd::isKeyPresent(const QMap<Options, QString> &map, Options searchedKey)
{
    if (map.find(searchedKey) == map.end())
        return false;
    return true;
}

bool Index_cmd::handleResume(const QMap<Options, QString> args)
{
    if (args.empty()) // useless but usefull to wipe out the fucking warning
        return false;
    return false;
}

bool Index_cmd::handleStop(const QMap<Options, QString> args)
{
    if (args.empty()) // useless but usefull to wipe out the fucking warning
        return false;
    return false;
}

bool Index_cmd::handleStart(const QMap<Options, QString> args)
{
    if (args.empty()) // useless but usefull to wipe out the fucking warning
        return false;
    return false;
}

bool Index_cmd::handleStatus(const QMap<Options, QString> args)
{
    if (args.empty()) // useless but usefull to wipe out the fucking warning
        return false;
    return false;
}

bool Index_cmd::handlePause(const QMap<Options, QString> args)
{
    if (args.empty()) // useless but usefull to wipe out the fucking warning
        return false;
    return false;
}
