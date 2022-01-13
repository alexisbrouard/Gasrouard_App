#ifndef ENUMS_H
#define ENUMS_H

enum Options {
    /* MODES */
    INITIAL,
    START,
    STOP,
    PAUSE,
    RESUME,
    STATUS,

    /* FLAGS */
    WHITELIST,
    BLACKLIST,
    FILTERS,
    SKIPPED_FILTERS,
    FOLDER_PATH,

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
    DONE,

    /* ACTIONS */
    ADD,
    PUSH,
    CLEAR,
    GET,
    SEARCH,
    INDEXER
};

#endif // ENUMS_H
