#ifndef ADD_CMD_H
#define ADD_CMD_H

#include "Enums.h"
#include "commandfactory.h"

class Add_cmd : public CommandFactory
{
public:
    Add_cmd();
    bool execute(Flags, Options);
};

#endif // ADD_CMD_H
