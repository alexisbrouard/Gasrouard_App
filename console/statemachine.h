#ifndef STATEMACHINE_H
#define STATEMACHINE_H

/* Global Imports */
#include "Enums.h"

/* System Imports */
#include <QRegExp>
#include <QString>
#include <QStringList>
#include <QFileInfo>
#include <QDebug>
#include <QMap>
#include <QDate>
#include <QDir>

/* Commands Imports */
#include "commandfactory.h"
#include "add_cmd.h"
#include "clear_cmd.h"
#include "get_cmd.h"
#include "push_cmd.h"
#include "search_cmd.h"
#include "index_cmd.h"

class Statemachine
{
public:
    Statemachine();

    /* Verif */
    bool isNumber(QString const &str);
    bool isOperator(QString const &str);
    bool isWord(QString const& str);
    bool isPath(QString const& str);
    bool isComa(QString const& str);
    bool isSeparator(QString const& str);
    bool isExtension(QString const& str);
    bool isDate(QString const& str);
    bool isSize(QString const& str);
    bool isType(QString const& str);
    bool isParamsCompare(QString const &origin, QString const &in);
    bool isValidPath(QString const &str);

    /* States */
    Options isOption(QString const& str);
    Options getOption();
    Options getKey(const QMap<Options, QString> &map, const QString &value);

    /* Overall */
    void    manageUserInput(QString userInput);
    void    fillArgsMap(QString userInput);
    void    checkState(Options previous, Options next, bool condition, QString const &in);

private:
    CommandFactory *_factory;
    Options _currentOption;
    QMap<Options, QString> _argsMap;
};

#endif // STATEMACHINE_H
