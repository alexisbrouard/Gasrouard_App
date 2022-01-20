#ifndef CLEAR_CMD_H
#define CLEAR_CMD_H

#include "commandfactory.h"

class Clear_cmd : public CommandFactory
{
public:
    Clear_cmd();
    bool execute(QMap<Options, QString>);

    Options getKey(const QMap<Options, QString> &map, const QString &value);
    QString getValue(const QMap<Options, QString> &map, Options searchedOption);
    bool isKeyPresent(const QMap<Options, QString> &map, Options searchedKey);

    bool handleBlackList(const QMap<Options, QString> args);
    bool handleFilters(const QMap<Options, QString> args);
    bool handleSkippedFilters(const QMap<Options, QString> args);
    bool handleWhiteList(const QMap<Options, QString> args);
};

#endif // CLEAR_CMD_H
