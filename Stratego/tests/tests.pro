include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibmetier

SOURCES += main.cpp \
    BoardTest.cpp \
    BoxTest.cpp \
    CemeteryTest.cpp \
    GameTest.cpp \
    PieceTest.cpp \
    PlayerTest.cpp \
    PositionTest.cpp \
    SquareTest.cpp

HEADERS += \
    catch.hpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../metier/release/ -llibmetier
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../metier/debug/ -llibmetier
else:unix: LIBS += -L$$OUT_PWD/../metier/ -llibmetier

INCLUDEPATH += $$PWD/../metier
DEPENDPATH += $$PWD/../metier
