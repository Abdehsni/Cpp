TEMPLATE = app

CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board.cpp \
        case.cpp \
        excpt.cpp \
        game.cpp \
        main.cpp \
        scenario.cpp \
        simple.cpp \
        token.cpp

HEADERS += \
    array.hpp \
    catch.hpp

include(../config.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -lButtonUp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -lButtonUp
else:unix: LIBS += -L$$OUT_PWD/../core/ -lButtonUp

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/libButtonUp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/libButtonUp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/ButtonUp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/ButtonUp.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../core/libButtonUp.a
