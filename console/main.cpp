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
    indexer.scanRepository("C:/");
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
}
