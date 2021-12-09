#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "commandfactory.h"
#include "Enums.h"

class CommandFactory
{
public:
    CommandFactory();
    virtual void execute(Actions, Flags, Options);
};

#endif // COMMANDFACTORY_H
