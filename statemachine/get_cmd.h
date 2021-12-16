#ifndef GET_CMD_H
#define GET_CMD_H

#include "Enums.h"
#include "commandfactory.h"

class Get_cmd : public CommandFactory
{
public:
    Get_cmd();
    bool execute(Flags, Options);

    bool handleBlackList(Options currentOption);
    bool handleFilters(Options currentOption);
    bool handleSkippedFilters(Options currentOption);
    bool handleWhiteList(Options currentOption);
};

#endif // GET_CMD_H
