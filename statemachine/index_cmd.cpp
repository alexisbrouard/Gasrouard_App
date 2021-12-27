#include "index_cmd.h"

Index_cmd::Index_cmd() : CommandFactory() {}


bool Index_cmd::execute(QMap<Options, QString> args)
{
    return false;
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
