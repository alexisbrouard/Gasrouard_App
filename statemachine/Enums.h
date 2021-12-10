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
    WHITELIST        = 0,
    BLACKLIST        = 1,
    FILTERS          = 2,
    SKIPPED_FILTERS  = 3,
    UNDEFINED2       = 4
};

enum Options {
    LAST_MODIFIED   = 0,
    DATE_CREATED    = 1,
    MAX_SIZE        = 2,
    MIN_SIZE        = 3,
    EXTENSION       = 4,
    TYPE            = 5,
    UNDEFINED3      = 6
};

enum Status {
    START           = 0,
    STOP            = 1,
    PAUSE           = 2,
    RESUME          = 3,
    STATE           = 4,
};

#endif // ENUMS_H
