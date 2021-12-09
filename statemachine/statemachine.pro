QT -= gui

TEMPLATE = lib
DEFINES += STATEMACHINE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_cmd.cpp \
    clear_cmd.cpp \
    commandfactory.cpp \
    get_cmd.cpp \
    push_cmd.cpp \
    search_cmd.cpp \
    statemachine.cpp

HEADERS += \
    Enums.h \
    add_cmd.h \
    clear_cmd.h \
    commandfactory.h \
    get_cmd.h \
    push_cmd.h \
    search_cmd.h \
    statemachine_global.h \
    statemachine.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
