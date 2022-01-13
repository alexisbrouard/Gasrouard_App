#include <QCoreApplication>
#include "statemachine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Statemachine obj;

    //obj.manageUserInput("INDEXER RESUME"); // works

    obj.manageUserInput("GET WHITELIST"); // works

    //obj.manageUserInput("ADD WHITELIST TOTO"); // works

    //obj.manageUserInput("PUSH WHITELIST toto.txt DONE"); // works, but only for one file

    //obj.manageUserInput("CLEAR WHITELIST"); // works

    //obj.manageUserInput("SEARCH toto LAST_MODIFIED:2days CREATED:31/12/2020 MAX_SIZE:1M EXT:txt,doc,xlsx TYPE:image"); // not tested
    return a.exec();
}
