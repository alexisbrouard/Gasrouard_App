#ifndef PUSH_CMD_H
#define PUSH_CMD_H

#include "Enums.h"
#include "commandfactory.h"

class Push_cmd : public CommandFactory
{
public:
    Push_cmd();
    bool execute(Flags, Options);
};

#endif // PUSH_CMD_H
