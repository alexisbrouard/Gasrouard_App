#include "statemachine.h"

Statemachine::Statemachine()
{
    _currentOption = Options::INITIAL;
}

void Statemachine::manageUserInput(QString userInput)
{
    qDebug() << "Enterin into Management";
    qDebug() << "user input: " << userInput;

    fillArgsMap(userInput);

    /*Temp Print*/
    QMap<Options, QString>::iterator i = _argsMap.begin();
    while (i != _argsMap.end()) {
        qDebug() << i.key() << ": " << i.value();
        ++i;
    }
    qDebug() << "Map printed";
    if (_argsMap.isEmpty())
        qDebug() << "Map empty";
    /*End of temp Action */

    Options currentAction = getKey(_argsMap, "ACTION");

    qDebug() << "current action :" << currentAction;
    if (currentAction != Options::UNDEFINED) {
        switch(currentAction) {
            case Options::ADD :
                _factory = new Add_cmd();
                break;
            case Options::CLEAR :
                _factory = new Clear_cmd();
                break;
            case Options::GET :
                _factory = new Get_cmd();
                break;
            case Options::INDEXER :
                _factory = new Index_cmd();
                break;
            case Options::PUSH :
                _factory = new Push_cmd();
                break;
            case Options::SEARCH :
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

/*
 * Add must be done the folders already on the DB, must retrieve them if check is here (currently no, must check in cmd)
*/
/*
 * TO make the push work must create multiple options to hold all folders (Folder_path1, folder_path2, ect..)
*/

void Statemachine::fillArgsMap(QString userInput)
{
    QStringList filteredInput = userInput.split(" ");
    bool endOPT = false;

    for (int i = 0, lastOPT = filteredInput.size() - 1; i < filteredInput.size(); i++) {
        /* Check for last OPT */
        if (i == lastOPT)
            endOPT = true;
                                 /* ADD */
        checkState(INITIAL, ADD, isParamsCompare(filteredInput[i], "ADD"), "ACTION");
        checkState(ADD, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"), "FLAG");
        checkState(ADD, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"), "FLAG");
        checkState(ADD, FILTERS, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(ADD, SKIPPED_FILTERS, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(WHITELIST, FOLDER_PATH, endOPT, filteredInput[i]);
        checkState(BLACKLIST, FOLDER_PATH, endOPT, filteredInput[i]);
        checkState(FILTERS, FOLDER_PATH, endOPT, filteredInput[i]);
        checkState(SKIPPED_FILTERS, FOLDER_PATH, endOPT, filteredInput[i]);

                                /* GET */
        checkState(INITIAL, GET, isParamsCompare(filteredInput[i], "GET"), "ACTION");
        checkState(GET, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"), "FLAG");
        checkState(GET, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"), "FLAG");
        checkState(GET, FILTERS, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(GET, SKIPPED_FILTERS, isExtension(filteredInput[i]), filteredInput[i]);

                                /* INDEXER */
        checkState(INITIAL, INDEXER, isParamsCompare(filteredInput[i], "INDEXER"), "ACTION");
        checkState(INDEXER, RESUME, isParamsCompare(filteredInput[i], "RESUME" ), "RESUME");
        checkState(INDEXER, START, isParamsCompare(filteredInput[i], "START" ), "START");
        checkState(INDEXER, STATUS, isParamsCompare(filteredInput[i], "STATUS" ), "STATUS");
        checkState(INDEXER, STOP, isParamsCompare(filteredInput[i], "STOP" ), "STOP");
        checkState(INDEXER, PAUSE, isParamsCompare(filteredInput[i], "PAUSE" ), "PAUSE");

                                /* PUSH */
        checkState(INITIAL, PUSH, isParamsCompare(filteredInput[i], "PUSH"), "ACTION");
        checkState(PUSH, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"), "FLAG");
        checkState(PUSH, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"), "FLAG");
        checkState(PUSH, FILTERS, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(PUSH, SKIPPED_FILTERS, isExtension(filteredInput[i]), filteredInput[i]);
        //Getting the folders
        checkState(WHITELIST, FOLDER_PATH, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(BLACKLIST, FOLDER_PATH, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(FILTERS, FOLDER_PATH, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(SKIPPED_FILTERS, FOLDER_PATH, isExtension(filteredInput[i]), filteredInput[i]);
        // Multiple folders, not gonna work prob cuz map is being used
        checkState(FOLDER_PATH, FOLDER_PATH, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(FOLDER_PATH, FOLDER_PATH, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(FOLDER_PATH, FOLDER_PATH, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(FOLDER_PATH, FOLDER_PATH, isExtension(filteredInput[i]), filteredInput[i]);
        // Getting the end
        checkState(FOLDER_PATH, DONE, isParamsCompare(filteredInput[i], "DONE"), "DONE");
        checkState(FOLDER_PATH, DONE, isParamsCompare(filteredInput[i], "DONE"), "DONE");
        checkState(FOLDER_PATH, DONE, isParamsCompare(filteredInput[i], "DONE"), "DONE");
        checkState(FOLDER_PATH, DONE, isParamsCompare(filteredInput[i], "DONE"), "DONE");

                                /* CLEAR */
        checkState(INITIAL, CLEAR, isParamsCompare(filteredInput[i], "CLEAR" ), "ACTION");
        checkState(CLEAR, WHITELIST, isParamsCompare(filteredInput[i], "WHITELIST"), "FLAG");
        checkState(CLEAR, BLACKLIST, isParamsCompare(filteredInput[i], "BLACKLIST"), "FLAG");
        checkState(CLEAR, SKIPPED_FILTERS, isExtension(filteredInput[i]), filteredInput[i]);
        checkState(CLEAR, FILTERS, isExtension(filteredInput[i]), filteredInput[i]);

                            /* Search */
        checkState(INITIAL, SEARCH, isParamsCompare(filteredInput[i], "SEARCH"), "ACTION");
        checkState(SEARCH, WORD, isWord(filteredInput[i]), filteredInput[i]);
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
    qDebug() << origin << " : " << in;
    int res = QString::compare(origin, in, Qt::CaseInsensitive);
    if (res == 0) {
        return true;
       qDebug() << origin << " : " << in;
    }
    return false;
}

void Statemachine::checkState(Options previous, Options next, bool condition, QString const &str)
{
    //qDebug() << "previous: " << previous << "  | currentOption: " << _currentOption << " | condition: " << condition;
    if (previous == _currentOption && condition == true) {
        _currentOption = next;
        qDebug() << "Map gonna be filled with: " << next;
        _argsMap.insert(next, str);
    }
}

bool Statemachine::isExtension(QString const &str)
{
    return str.contains('.');
}

bool Statemachine::isValidPath(QString const &str)
{
    QDir pathDir(str);
    return pathDir.exists();
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
    else if (str.compare("ADD"))
        return ADD;
    else if (str.compare("PUSH"))
        return PUSH;
    else if (str.compare("CLEAR"))
        return CLEAR;
    else if (str.compare("GET"))
        return GET;
    else if (str.compare("SEARCH"))
        return SEARCH;
    else if (str.compare("INDEXER"))
        return INDEXER;
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

    INITIAL,
    START,
    STOP,
    PAUSE,
    RESUME,
    STATE,
    STATUS*/
}

Options Statemachine::getOption()
{
    return _currentOption;
}

Options Statemachine::getKey(const QMap<Options, QString> &map, const QString &value)
{
    QMapIterator<Options, QString> i(map);
    while (i.hasNext()) {
        i.next();
        if (i.value() == value)
        return i.key();
    }
    return (Options::UNDEFINED);
}
