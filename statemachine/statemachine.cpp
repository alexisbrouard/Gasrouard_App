#include "statemachine.h"

Statemachine::Statemachine() {}

void Statemachine::manageUserInput(QString userInput)
{
    QStringList fullInput = userInput.split(" ");
    _currentAction = isAction(fullInput[0]);
    _currentFlag = isFlag(fullInput[1]);
    _currentOption = isOption(fullInput[2]);

    if (_currentAction != Actions::UNDEFINED && _currentFlag != Flags::UNDEFINED2) {
        switch(_currentAction) {
            case Actions::ADD :
                _factory = new Add_cmd();
                break;
            case Actions::CLEAR :
                _factory = new Clear_cmd();
                break;
            case Actions::GET :
                _factory = new Get_cmd();
                break;
            case Actions::INDEXER :
                _factory = new Index_cmd();
                break;
            case Actions::PUSH :
                _factory = new Push_cmd();
                break;
            case Actions::SEARCH :
                _factory = new Search_cmd();
                break;
            default :
                break;
        }
    }
    bool command_ret = _factory->execute(_currentFlag, _currentOption);
    command_ret ? qDebug() << "Command Success" : qDebug() << "Command Failure";
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

enum Options Statemachine::isOption(QString const &str)
{
    if (str.compare("LAST_MODIFIED"))
        return LAST_MODIFIED;
    if (str.compare("DATE_CREATED"))
        return DATE_CREATED;
    if (str.compare("MAX_SIZE"))
        return MAX_SIZE;
    if (str.compare("MIN_SIZE"))
        return MIN_SIZE;
    if (str.compare("EXTENSION"))
        return EXTENSION;
    if (str.compare("TYPE"))
        return TYPE;
    return UNDEFINED3;
}

Flags Statemachine::getFlag()
{
    return _currentFlag;
}

Actions Statemachine::getAction()
{
    return _currentAction;
}

Options Statemachine::getOption()
{
    return _currentOption;
}
