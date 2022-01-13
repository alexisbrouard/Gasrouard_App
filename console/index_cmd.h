#ifndef INDEX_CMD_H
#define INDEX_CMD_H

#include "commandfactory.h"

class Index_cmd : public CommandFactory
{
public:
    Index_cmd();
    bool execute(QMap<Options, QString>);

    Options getKey(const QMap<Options, QString> &map, const QString &value);
    QString getValue(const QMap<Options, QString> &map, Options searchedOption);
    bool isKeyPresent(const QMap<Options, QString> &map, Options searchedKey);

    bool handleResume(const QMap<Options, QString> args);
    bool handleStop(const QMap<Options, QString> args);
    bool handleStart(const QMap<Options, QString> args);
    bool handleStatus(const QMap<Options, QString> args);
    bool handlePause(const QMap<Options, QString> args);
};

#endif // INDEX_CMD_H
