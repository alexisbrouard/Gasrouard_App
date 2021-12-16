#include "get_cmd.h"

Get_cmd::Get_cmd() : CommandFactory()
{

}

bool Get_cmd::execute(Flags currentFlag, Options currentOption)
{
    bool res = false;

    switch (currentFlag) {
        case Flags::BLACKLIST :
            res = handleBlackList(currentOption);
            break;
        case Flags::FILTERS :
            res = handleFilters(currentOption);
            break;
        case Flags::SKIPPED_FILTERS :
            res = handleSkippedFilters(currentOption);
            break;
        case Flags::WHITELIST :
            res = handleWhiteList(currentOption);
            break;
        default:
            res = false;
            break;
    }
    return res;
}

bool Get_cmd::handleBlackList(Options currentOption)
{}

bool Get_cmd::handleFilters(Options currentOption)
{}

bool Get_cmd::handleSkippedFilters(Options currentOption)
{}

bool Get_cmd::handleWhiteList(Options currentOption)
{}
