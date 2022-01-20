#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

/* Define */
#define SUCCESS true
#define FAILURE false

/* System Imports */
#include <QString>
#include <QMap>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

/* Global Imports */
#include "Enums.h"

class CommandFactory
{
public:
    CommandFactory();
    virtual bool execute(QMap<Options, QString>) = 0;
    virtual Options getKey(const QMap<Options, QString> &map, const QString &value) = 0;
    virtual QString getValue(const QMap<Options, QString> &map, Options searchedOption) = 0;
    virtual bool isKeyPresent(const QMap<Options, QString> &map, Options searchedKey) = 0;
};

#endif // COMMANDFACTORY_H
