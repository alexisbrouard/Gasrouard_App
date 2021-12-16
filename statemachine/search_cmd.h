#ifndef SEARCH_CMD_H
#define SEARCH_CMD_H

#include "Enums.h"
#include "commandfactory.h"

class Search_cmd : public CommandFactory
{
public:
    Search_cmd();
    bool execute(Flags, Options);
};

#endif // SEARCH_CMD_H
