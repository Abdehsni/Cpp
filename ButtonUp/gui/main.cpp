#include <QApplication>
#include "guiview.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    model::Game game;
    view::guiView view(&game);
    return a.exec();
}
