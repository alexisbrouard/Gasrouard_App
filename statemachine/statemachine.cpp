#include "statemachine.h"

Statemachine::Statemachine()
{
}

bool Statemachine::isNumber(QString const &str)
{
    QRegExp re("\\d*");
    return re.exactMatch(str);
}

bool Statemachine::isOperator(QString const &str)
{
    QString operators = "+-/*";
    return operators.contains(str);
}

bool Statemachine::isWord(QString const& str)
{
    QRegExp re("\\d*");
    return !re.exactMatch(str);
}

bool Statemachine::isPath(const QString &str)
{
    const QFileInfo outputDir(str);
    return outputDir.exists();
}

enum Actions Statemachine::isAction(QString const& str)
{
    if (str.compare("ADD"))
        return ADD;
    if (str.compare("PUSH"))
        return PUSH;
    if (str.compare("CLEAR"))
        return CLEAR;
    if (str.compare("GET"))
        return GET;
    if (str.compare("SEARCH"))
        return SEARCH;
    if (str.compare("INDEXER"))
        return INDEXER;
    return UNDEFINED;
}

enum Flags Statemachine::isFlag(QString const &str)
{
    if (str.compare("WHITELIST"))
        return WHITELIST;
    if (str.compare("BLACKLIST"))
        return BLACKLIST;
    if (str.compare("FILTERS"))
        return FILTERS;
    if (str.compare("SKIPPED_FILTERS"))
        return SKIPPED_FILTERS;
    return UNDEFINED2;
}
