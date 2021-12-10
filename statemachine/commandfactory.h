#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "commandfactory.h"
#include "Enums.h"

class CommandFactory
{
public:
    CommandFactory();
    virtual bool execute(Actions, Flags, Options);
};

#endif // COMMANDFACTORY_H
