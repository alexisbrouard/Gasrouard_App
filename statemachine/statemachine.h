#ifndef STATEMACHINE_H
#define STATEMACHINE_H

/* Global Imports */
#include "statemachine_global.h"
#include "Enums.h"

/* System Imports */
#include <QRegExp>
#include <QString>
#include <QStringList>
#include <QFileInfo>

/* Commands Imports */
#include "commandfactory.h"
#include "add_cmd.h"
#include "clear_cmd.h"
#include "get_cmd.h"
#include "push_cmd.h"
#include "search_cmd.h"
#include "index_cmd.h"

class STATEMACHINE_EXPORT Statemachine
{
public:
    Statemachine();

    /* Verif */
    bool isNumber(QString const &str);
    bool isOperator(QString const &str);
    bool isWord(QString const& str);
    bool isPath(QString const& str);

    /* States */
    Flags   isFlag(QString const& str);
    Actions isAction(QString const& str);
    Options isOption(QString const& str);

    /* Overall */
    void    manageUserInput(QString userInput);
    Flags   getFlag();
    Options getOption();
    Actions getAction();

private:
    CommandFactory *_factory;
    Flags _currentFlag;
    Actions _currentAction;
    Options _currentOption;
};

#endif // STATEMACHINE_H
