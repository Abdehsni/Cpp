QT -= gui

TEMPLATE = lib
TARGET = ButtonUp
CONFIG += staticlib
DEFINES += CORE_LIBRARY


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    case.cpp \
    core.cpp \
    game.cpp \
    observable.cpp \
    player.cpp \
    token.cpp

HEADERS += \
    Color.h \
    board.h \
    case.h \
    core_global.h \
    core.h \
    game.h \
    gamestate.h \
    observable.h \
    observer.h \
    player.h \
    random.hpp \
    token.h

include(../config.pri)

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
