#ifndef CLEAR_CMD_H
#define CLEAR_CMD_H

#include "Enums.h"
#include "commandfactory.h"

class Clear_cmd : public CommandFactory
{
public:
    Clear_cmd();
    bool execute(Actions, Flags, Options);
};

#endif // CLEAR_CMD_H
