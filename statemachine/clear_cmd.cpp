#include "clear_cmd.h"

Clear_cmd::Clear_cmd() : CommandFactory()
{

}

bool Clear_cmd::execute(QMap<Options, QString> args)
{
    return false;
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
