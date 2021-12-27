#include "statemachine.h"

Statemachine::Statemachine() {}

void Statemachine::manageUserInput(QString userInput)
{
    QStringList fullInput = userInput.split(" ");
    _currentAction = isAction(fullInput[0]);
    fillArgsMap(userInput);

    if (_currentAction != Actions::NOTFOUND) {
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
    bool command_ret = _factory->execute(_argsMap);
    command_ret ? qDebug() << "Command Success" : qDebug() << "Command Failure";
}

void Statemachine::fillArgsMap(QString userInput)
{
    QStringList filteredInput = userInput.split(" ");

    for (int i = 1; i < filteredInput.size(); i++) {
        /* ADD */
        checkState(INITIAL, ADD_OPT, isParamsCompare(filteredInput[i], "ADD"), "ADD");
        checkState(ADD_OPT, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"), "FLAG");
        checkState(ADD_OPT, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"), "FLAG");
        checkState(ADD_OPT, FILTERS, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(ADD_OPT, SKIPPED_FILTERS, isExtension(filteredInput[i]), filteredInput[i]);

        /* INDEXER */
        checkState(INITIAL, INDEXER_OPT, isParamsCompare(filteredInput[i], "INDEXER"), "INDEXER");
        checkState(INDEXER_OPT, RESUME, isParamsCompare(filteredInput[i], "RESUME" ), "RESUME");
        checkState(INDEXER_OPT, START, isParamsCompare(filteredInput[i], "START" ), "START");
        checkState(INDEXER_OPT, STATUS, isParamsCompare(filteredInput[i], "STATUS" ), "STATUS");
        checkState(INDEXER_OPT, STOP, isParamsCompare(filteredInput[i], "STOP" ), "STOP");
        checkState(INDEXER_OPT, PAUSE, isParamsCompare(filteredInput[i], "PAUSE" ), "PAUSE");

        /* PUSH */
        checkState(INITIAL, PUSH_OPT, isParamsCompare(filteredInput[i], "PUSH"), "PUSH");
        checkState(PUSH_OPT, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"), "FLAG");
        checkState(PUSH_OPT, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"), "FLAG");
        checkState(PUSH_OPT, FILTERS, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(PUSH_OPT, SKIPPED_FILTERS, isExtension(filteredInput[i]), filteredInput[i]);

        /* CLEAR */
        checkState(INITIAL, CLEAR_OPT, isParamsCompare(filteredInput[i], "CLEAR" ), "CLEAR");
        checkState(CLEAR_OPT, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"), "FLAG");
        checkState(CLEAR_OPT, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"), "FLAG");
        checkState(CLEAR_OPT, SKIPPED_FILTERS, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(CLEAR_OPT, FILTERS, isExtension(filteredInput[i]), filteredInput[i]);

        /* Search */
        checkState(INITIAL, SEARCH_OPT, isParamsCompare(filteredInput[i], "SEARCH"), "SEARCH");
        checkState(SEARCH_OPT, WORD, isWord(filteredInput[i]), filteredInput[i]);
        checkState(WORD, LAST_MODIFIED, isDate(filteredInput[i]), filteredInput[i]);
        checkState(WORD, DATE_CREATED, isDate(filteredInput[i]), filteredInput[i]);
        checkState(WORD, MAX_SIZE, isSize(filteredInput[i]), filteredInput[i]);
        checkState(WORD, MIN_SIZE, isSize(filteredInput[i]), filteredInput[i]);
        checkState(WORD, SIZE, isSize(filteredInput[i]), filteredInput[i]);
        checkState(WORD, EXTENSION, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(WORD, TYPE, isType(filteredInput[i]), filteredInput[i]);
    }
}

bool Statemachine::isParamsCompare(QString const &origin, QString const &in)
{
    return origin.compare(in);
}

void Statemachine::checkState(Options previous, Options next, bool condition, QString const &str)
{
    if (previous == _currentOption && condition) {
        _currentOption = next;
        _argsMap.insert(previous, str);
    }
}

bool Statemachine::isExtension(QString const &str)
{
    return str.contains('.');
}

bool Statemachine::isDate(QString const &str)
{
    //return QDate::fromString(str,"dd/MM/yyyy"); how dafuk am i supposed to check this
    return str.contains('/');
}

bool Statemachine::isSize(QString const &str)
{
    //MAX_SIZE:10M
    //MIN_SIZE:1M
    return (str.contains('K') || str.contains('M') || str.contains('G'));
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
    return NOTFOUND;
}

enum Options Statemachine::isOption(QString const &str)
{
    if (str.compare("LAST_MODIFIED"))
        return LAST_MODIFIED;
    else if (str.compare("DATE_CREATED"))
        return DATE_CREATED;
    else if (str.compare("MAX_SIZE"))
        return MAX_SIZE;
    else if (str.compare("MIN_SIZE"))
        return MIN_SIZE;
    else if (str.compare("EXTENSION"))
        return EXTENSION;
    else if (str.compare("TYPE"))
        return TYPE;
    else if (str.compare("WHITELIST"))
        return WHITELIST;
    else if (str.compare("BLACKLIST"))
        return BLACKLIST;
    else if (str.compare("FILTERS"))
        return FILTERS;
    else if (str.compare("SKIPPED_FILTERS"))
        return SKIPPED_FILTERS;
    else if (str.compare("SIZE"))
        return SKIPPED_FILTERS;
    return UNDEFINED;
    /*
    TYPE,
    AND,
    COMA,

    WORD,
    NUMBER,
    AWAITING,
    ENDING,
    UNDEFINED,

    ADD_OPT,
    PUSH_OPT,
    CLEAR_OPT,
    GET_OPT,
    SEARCH_OPT,
    INDEXER_OPT,

    INITIAL,
    START,
    STOP,
    PAUSE,
    RESUME,
    STATE,
    STATUS*/
}

Actions Statemachine::getAction()
{
    return _currentAction;
}

Options Statemachine::getOption()
{
    return _currentOption;
}
