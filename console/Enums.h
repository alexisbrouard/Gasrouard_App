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
    AND_ONE,
    AND_TWO,
    COMA,
    FIRST_NUM,
    SECOND_NUM,
    FIRST_DATE,
    SECOND_DATE,
    SIZE_NUM_ONE,
    SIZE_NUM_TWO,

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
