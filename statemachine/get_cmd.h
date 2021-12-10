#ifndef GET_CMD_H
#define GET_CMD_H

#include "Enums.h"
#include "commandfactory.h"

class Get_cmd : public CommandFactory
{
public:
    Get_cmd();
    bool execute(Actions, Flags, Options);
};

#endif // GET_CMD_H
