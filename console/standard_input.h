#ifndef STANDARD_INPUT_H
#define STANDARD_INPUT_H

#include <QObject>
#include <QSocketNotifier>
#include <iostream>
#include <stdio.h>
#include <QDir>
#include <QWinEventNotifier>
#include <windows.h>

class Standard_Input : public QObject
{
    Q_OBJECT;

    public:
    Standard_Input();

    void run();

    signals:
    void quit();

    private:
    QWinEventNotifier  *m_notifier;

    private slots:
    void readCommand();
};

#endif // STANDARD_INPUT_H
