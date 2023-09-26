cmake_minimum_required(VERSION 3.5)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


add_executable(BabaIsYou
    model/gameobject.h
    model/gameobject.cpp
    model/type.h
    model/board.h
    model/board.cpp
    model/coordinate.h
    model/coordinate.cpp
    model/direction.h
    model/elements.h
    model/fileloader.h
    model/fileloader.cpp
    model/game.h
    model/game.cpp
    ui/controller.h
    ui/controller.cpp
    ui/controllergui.h
    ui/controllergui.cpp
    ui/view.h
    ui/view.cpp
    ui/mainwindow.h
    ui/mainwindow.cpp
    ui/mainwindow.ui
    ui/main.cpp
    utility/Observable.h
    utility/Observable.cpp
    utility/Observer.h
    utility/Observer.cpp
)


target_include_directories(BabaIsYou PRIVATE
./
./model
./ui
./utility
)


find_package (QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package ( Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
target_link_libraries(BabaIsYou PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)



install(TARGETS BabaIsYou
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
