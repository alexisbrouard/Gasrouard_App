#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

/* System Imports */
#include <QString>
#include <QMap>
#include <QDebug>

/* Global Imports */
#include "Enums.h"

class CommandFactory
{
public:
    CommandFactory();
    virtual bool execute(QMap<Options, QString>);
    virtual Options getKey(const QMap<Options, QString> &map, const QString &value);
    virtual QString getValue(const QMap<Options, QString> &map, Options searchedOption);
    virtual bool isKeyPresent(const QMap<Options, QString> &map, Options searchedKey);
};

#endif // COMMANDFACTORY_H
