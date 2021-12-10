#ifndef INDEX_CMD_H
#define INDEX_CMD_H

#include "Enums.h"
#include "commandfactory.h"

class Index_cmd : public CommandFactory
{
public:
    Index_cmd();
    bool execute(Actions, Flags, Options);
};

#endif // INDEX_CMD_H
