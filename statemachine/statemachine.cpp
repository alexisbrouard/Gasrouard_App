#include "statemachine.h"

Statemachine::Statemachine() {}

void Statemachine::manageUserInput(QString userInput)
{
    /// Search
    QStringList fullInput = userInput.split(" ");
    _currentAction = isAction(fullInput[0]);
    //_currentFlag = isFlag(fullInput[1]);
    _currentOption = isOption(fullInput[2]);

    fillArgsMap(userInput);
    /*
        Build a qmap with all options
        is (verif) all user input
        State for parsing, if waiting for a number or a word
    */
    if (_currentAction != Actions::UNDEFINED) {
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
                 qDebug() << "Command Unknown";
                break;
        }
    }
    bool command_ret = _factory->execute(_currentFlag, _currentOption);
    command_ret ? qDebug() << "Command Success" : qDebug() << "Command Failure";
}

void Statemachine::fillArgsMap(QString userInput)
{
    QStringList filteredInput = userInput.split(" ");
    //_argsMap.append()

    for (int i = 1; i < filteredInput.size(); i++) {
        /* ADD */
        checkState(INITIAL, ADD_OPT, isParamsCompare(filteredInput[i], "ADD"));
        checkState(ADD_OPT, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"));
        checkState(ADD_OPT, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"));
        checkState(ADD_OPT, FILTERS, isExtension(filteredInput[i]));
        checkState(ADD_OPT, SKIPPED_FILTERS, isExtension(filteredInput[i]));

        /* INDEXER */
        checkState(INITIAL, INDEXER_OPT, isParamsCompare(filteredInput[i], "INDEXER"));
        checkState(INDEXER_OPT, RESUME, isParamsCompare(filteredInput[i], "RESUME" ));
        checkState(INDEXER_OPT, START, isParamsCompare(filteredInput[i], "START" ));
        checkState(INDEXER_OPT, STATUS, isParamsCompare(filteredInput[i], "STATUS" ));
        checkState(INDEXER_OPT, STOP, isParamsCompare(filteredInput[i], "STOP" ));
        checkState(INDEXER_OPT, PAUSE, isParamsCompare(filteredInput[i], "PAUSE" ));

        /* PUSH */
        checkState(INITIAL, PUSH_OPT, isParamsCompare(filteredInput[i], "PUSH"));
        checkState(PUSH_OPT, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"));
        checkState(PUSH_OPT, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"));
        checkState(PUSH_OPT, FILTERS, isExtension(filteredInput[i]));
        checkState(PUSH_OPT, SKIPPED_FILTERS, isExtension(filteredInput[i]));

        /* CLEAR */
        checkState(INITIAL, CLEAR_OPT, isParamsCompare(filteredInput[i], "CLEAR" ));
        checkState(CLEAR_OPT, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"));
        checkState(CLEAR_OPT, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"));
        checkState(CLEAR_OPT, SKIPPED_FILTERS, isExtension(filteredInput[i]));
        checkState(CLEAR_OPT, FILTERS, isExtension(filteredInput[i]));

        /* Search */
        checkState(INITIAL, SEARCH_OPT, isParamsCompare(filteredInput[i], "SEARCH"));
        checkState(SEARCH_OPT, WORD, isWord(filteredInput[i]));
        checkState(WORD, LAST_MODIFIED, isDate(filteredInput[i]));
        checkState(WORD, DATE_CREATED, isDate(filteredInput[i]));
        checkState(WORD, MAX_SIZE, isSize(filteredInput[i]));
        checkState(WORD, MIN_SIZE, isSize(filteredInput[i]));
        checkState(WORD, SIZE, isSize(filteredInput[i]));
        checkState(WORD, EXTENSION, isExtension(filteredInput[i]));
        checkState(WORD, TYPE, isType(filteredInput[i]));
    }
}

bool Statemachine::isParamsCompare(QString const &origin, QString const &in)
{
    return origin.compare(in);
}

void Statemachine::checkState(Options previous, Options next, bool condition)
{
    if (previous == _currentOption && condition) {
        _currentOption = next;

    }
}

bool Statemachine::isExtension(QString const &str)
{
    QStringList extList = {"json", "txt", "pdf", "jpg", "png", "targz"};
    QString temp;

    for (int i = 0; i < extList.size(); i++) {
        if (str.contains(temp))
            return true;
    }
    return false;
}

bool Statemachine::isDate(QString const &str)
{
    return true; // How dafuk are we suppossed to check this ?
}

bool Statemachine::isSize(QString const &str)
{
    if (str.contains('K') || str.contains('M') || str.contains('G'))
        return true;
    return false;
}

bool Statemachine::isType(QString const &str)
{
    QStringList extList = {"image", "text", "exe"};
    QString temp;

    for (int i = 0; i < extList.size(); i++) {
        if (str.contains(temp))
            return true;
    }
    return false;
}

bool Statemachine::isSeparator(QString const &str)
{
    QRegExp re("AND");
    return re.exactMatch(str);
}

bool Statemachine::isComa(QString const &str)
{
    QRegExp re(",");
    return re.exactMatch(str);
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

enum Options Statemachine::isFlag(QString const &str)
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
