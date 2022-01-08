#include <QCoreApplication>
#include "statemachine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Statemachine obj;
    //obj.manageUserInput("GET WHITELIST toto"); // works

    obj.manageUserInput("PUSH WHITELIST toto tata titi DONE"); // does not work, add being detected cuz wtf

    //obj.manageUserInput("INDEXER RESUME"); //
    return a.exec();
}
