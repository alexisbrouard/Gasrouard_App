#ifndef ENUMS_H
#define ENUMS_H

enum Actions {
    ADD         = 0,
    PUSH        = 1,
    CLEAR       = 2,
    GET         = 3,
    SEARCH      = 4,
    INDEXER     = 5,
    UNDEFINED   = 6
};

enum Flags {
};

enum Options {
    WHITELIST,
    BLACKLIST,
    FILTERS,
    SKIPPED_FILTERS,
    UNDEFINED2,
    LAST_MODIFIED,
    DATE_CREATED,
    SIZE,
    MAX_SIZE,
    MIN_SIZE ,
    EXTENSION,
    TYPE,
    WORD,
    NUMBER,
    AND,
    AWAITING,
    ENDING,
    COMA,
    UNDEFINED3,
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
    STATUS
};

#endif // ENUMS_H
