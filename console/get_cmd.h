#ifndef GET_CMD_H
#define GET_CMD_H

#include "commandfactory.h"

class Get_cmd : public CommandFactory
{
public:
    Get_cmd();
    bool execute(QMap<Options, QString>);
    Options getKey(const QMap<Options, QString> &map, const QString &value);
    QString getValue(const QMap<Options, QString> &map, Options searchedOption);
    bool isKeyPresent(const QMap<Options, QString> &map, Options searchedKey);

    bool handleBlackList(const QMap<Options, QString> args);
    bool handleFilters(const QMap<Options, QString> args);
    bool handleSkippedFilters(const QMap<Options, QString> args);
    bool handleWhiteList(const QMap<Options, QString> args);
};

#endif // GET_CMD_H
