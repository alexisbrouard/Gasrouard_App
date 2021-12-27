#include "add_cmd.h"

Add_cmd::Add_cmd() : CommandFactory()
{

}

bool Add_cmd::execute(QMap<Options, QString> args)
{
    return false;
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
