#include "clear_cmd.h"

Clear_cmd::Clear_cmd() : CommandFactory()
{

}

bool Clear_cmd::execute(Actions _currentAction, Flags _currentFlag, Options _currentOption)
{
    return false;
}
