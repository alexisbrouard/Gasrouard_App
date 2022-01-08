#include "search_cmd.h"

Search_cmd::Search_cmd() : CommandFactory() {}

bool Search_cmd::execute(QMap<Options, QString> args)
{}

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
        return false;
    return true;
}
