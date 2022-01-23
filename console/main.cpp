#include <QCoreApplication>
#include "statemachine.h"
#include "indexer.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    /* Inits */
    Statemachine obj;
    Indexer indexer;
    std::string line;
    indexer.scanRepository("C:/Users/Cameron/OneDrive/Documents/Battlefield 4");
    std::cout << "Welcome dear user, Please wait a minute for indexation completion" << std::endl;

    while (1) {
        std::cout << "> " << std::flush;
        std::getline(std::cin, line);
        if (std::cin.eof() || line == "quit") {
            std::cout << "Ending the Session!" << std::endl;
            break;
        } else {
           QString qstr = QString::fromStdString(line);
           obj.manageUserInput(qstr);
        }
        line.clear();
    }
    return app.exec();

    //obj.manageUserInput("INDEXER RESUME"); // works

    //obj.manageUserInput("GET WHITELIST"); // works

    //obj.manageUserInput("ADD FILTERS .txt"); // works

    //obj.manageUserInput("PUSH WHITELIST toto.txt DONE"); // works, but only for one file

    //obj.manageUserInput("CLEAR WHITELIST"); // works

    //obj.manageUserInput("SEARCH toto LAST_MODIFIED:2days CREATED:31/12/2020 MAX_SIZE:1M EXT:txt,doc,xlsx TYPE:image"); // not tested
    //obj.manageUserInput("SEARCH toto LAST_MODIFIED:BETWEEN 2 days and 3 days CREATED:31/12/2020 MAX_SIZE:10M MIN_SIZE:1M SIZE:BETWEEN 10M AND 20M EXT:txt,doc,xlsx "
                        //"TYPE:image OR text");
}
