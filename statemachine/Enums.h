#ifndef ENUMS_H
#define ENUMS_H

enum Actions {
    ADD         = 0,
    PUSH        = 1,
    CLEAR       = 2,
    GET         = 3,
    SEARCH      = 4,
    INDEXER     = 5,
    NOTFOUND    = 6
};

enum Options {
    /* FLAGS */
    WHITELIST,
    BLACKLIST,
    FILTERS,
    SKIPPED_FILTERS,

    /*SEARCH OPTIONS*/
    LAST_MODIFIED,
    DATE_CREATED,
    SIZE,
    MAX_SIZE,
    MIN_SIZE ,
    EXTENSION,
    TYPE,
    AND,
    COMA,

    /* OVERALL */
    WORD,
    NUMBER,
    AWAITING,
    ENDING,
    UNDEFINED,

    /* ACTIONS */
    ADD_OPT,
    PUSH_OPT,
    CLEAR_OPT,
    GET_OPT,
    SEARCH_OPT,
    INDEXER_OPT,

    /* MODES */
    INITIAL,
    START,
    STOP,
    PAUSE,
    RESUME,
    STATE,
    STATUS
};

#endif // ENUMS_H
