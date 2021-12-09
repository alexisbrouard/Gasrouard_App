#include "statemachine.h"

Statemachine::Statemachine()
{
}

/*
*methods to get and check enums is fucked up, must redo and clean
*/
void Statemachine::manageUserInput(QString userInput)
{
    QStringList fullInput = userInput.split(" ");
    if (isAction(fullInput[0]) && isFlag(fullInput[1])) {
        //_factory =;
        /*switch(_currentAction) {
            case Actions::ADD :
                _factory = new Add_cmd;
                break;
            case Actions::CLEAR :
                break;
            case Actions::GET :
                break;
            case Actions::INDEXER :
                break;
            case Actions::PUSH :
                break;
            case Actions::SEARCH :
                break;
            default :
                break;
        }*/

        setAction( isAction(fullInput[0]) );
        setFlag( isFlag(fullInput[1]) );
        //_factory = new CommandFactory();
    }
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

void Statemachine::setFlag(Flags nFlag)
{
    _currentFlag = nFlag;
}

Flags Statemachine::getFlag()
{
    return _currentFlag;
}

void Statemachine::setAction(Actions nAction)
{
    _currentAction = nAction;
}

Actions Statemachine::getAction()
{
    return _currentAction;
}
