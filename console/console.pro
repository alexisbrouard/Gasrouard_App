QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        add_cmd.cpp \
        clear_cmd.cpp \
        commandfactory.cpp \
        get_cmd.cpp \
        index_cmd.cpp \
        main.cpp \
        push_cmd.cpp \
        search_cmd.cpp \
        statemachine.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Enums.h \
    add_cmd.h \
    clear_cmd.h \
    commandfactory.h \
    get_cmd.h \
    index_cmd.h \
    push_cmd.h \
    search_cmd.h \
    statemachine.h
