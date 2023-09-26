QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    guiview.cpp \
    inscriptionwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    guiview.h \
    inscriptionwindow.h \
    mainwindow.h

FORMS += \
    inscriptionwindow.ui \
    mainwindow.ui

include(../config.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


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

RESOURCES += \
    ressource.qrc

