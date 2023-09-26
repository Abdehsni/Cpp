include(../defaults.pri)

TEMPLATE = lib
TARGET = libmetier
DESTDIR = ../lib

HEADERS += \
    Board.h \
    Box.h \
    Cemetery.h \
    ColorPiece.h \
    Game.h \
    Observable.h \
    Observer.h \
    Piece.h \
    Player.h \
    Position.h \
    Square.h \
    Squaretype.h \
    gameState.h


SOURCES += \
    Board.cpp \
    Box.cpp \
    Cemetery.cpp \
    Game.cpp \
    Observable.cpp \
    Piece.cpp \
    Player.cpp \
    Position.cpp \
    Square.cpp

DISTFILES += \
    config_player1.txt \
    config_player2.txt
