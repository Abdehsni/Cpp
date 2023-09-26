include(../defaults.pri)

#you MUST include headers to subprojects, for instance like this
#"core" is not added here because it's already in defaults.pri

#INCLUDEPATH += $$PWD/../controllers

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibmetier \

SOURCES += ConsoleView.cpp \
    consoleController.cpp \
    main.cpp

HEADERS += \
    ConsoleView.h \
    consoleController.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../metier/release/ -llibmetier
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../metier/debug/ -llibmetier
else:unix: LIBS += -L$$OUT_PWD/../metier/ -llibmetier

INCLUDEPATH += $$PWD/../metier
DEPENDPATH += $$PWD/../metier
