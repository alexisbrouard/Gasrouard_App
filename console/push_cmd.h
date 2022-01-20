#ifndef PUSH_CMD_H
#define PUSH_CMD_H

#include "commandfactory.h"

class Push_cmd : public CommandFactory
{
public:
    Push_cmd();
    bool execute(QMap<Options, QString>);

    Options getKey(const QMap<Options, QString> &map, const QString &value);
    QString getValue(const QMap<Options, QString> &map, Options searchedOption);
    bool isKeyPresent(const QMap<Options, QString> &map, Options searchedKey);

    bool handleBlackList(const QMap<Options, QString> args);
    bool handleFilters(const QMap<Options, QString> args);
    bool handleSkippedFilters(const QMap<Options, QString> args);
    bool handleWhiteList(const QMap<Options, QString> args);
};

#endif // PUSH_CMD_H
