#include "push_cmd.h"

Push_cmd::Push_cmd() : CommandFactory()
{

}

bool Push_cmd::execute(QMap<Options, QString> args)
{
    return false;
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
