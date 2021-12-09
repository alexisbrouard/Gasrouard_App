#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "statemachine_global.h"

#include <QRegExp>
#include <QString>
#include <QStringList>
#include <QFileInfo>

#include "Enums.h"

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
    Flags isFlag(QString const& str);
    Actions isAction(QString const& str);

    /* Overall */
    void manageUserInput(QString userInput);
};

#endif // STATEMACHINE_H
