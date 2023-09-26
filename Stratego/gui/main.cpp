#include "mainwindow.h"
#include "guiController.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game{};
    GuiView w{&game};
    controller::ControllerGui controller{game,w};
    w.show();
    return a.exec();
}
