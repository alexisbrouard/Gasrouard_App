#ifndef ADD_CMD_H
#define ADD_CMD_H

#include "commandfactory.h"

class Add_cmd : public CommandFactory
{
public:
    Add_cmd();
    bool execute(QMap<Options, QString>);

    Options getKey(const QMap<Options, QString> &map, const QString &value);
    QString getValue(const QMap<Options, QString> &map, Options searchedOption);
    bool isKeyPresent(const QMap<Options, QString> &map, Options searchedKey);
};

#endif // ADD_CMD_H
