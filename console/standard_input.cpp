#include "standard_input.h"
#include <iostream>

Standard_Input::Standard_Input()
{
    //m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    m_notifier = new QWinEventNotifier(GetStdHandle(STD_INPUT_HANDLE));
}

void Standard_Input::run()
{
    std::cout << "First message" << std::endl;
    std::cout << "> " << std::flush;
    //res = connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readCommand()));
    //bool res;

    //res = connect(m_notifier, &QWinEventNotifier::activated, this, &Standard_Input::readCommand);
    //std::cout << res << std::flush;
}

void Standard_Input::readCommand()
{
    std::cout << "before" << std::endl;
    std::string line;
    std::getline(std::cin, line);
    std::cout << "line caught:" << line << std::endl;
    if (std::cin.eof() || line == "quit") {
        std::cout << "Good bye!" << std::endl;
        emit quit();
    } else {
        std::cout << "Echo: " << line << std::endl;
        std::cout << "> " << std::flush;
    }
}
