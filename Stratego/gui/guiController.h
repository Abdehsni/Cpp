#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H
#include "Game.h"
#include "mainwindow.h"
#include <iostream>

using model::Game;
class GuiView;
namespace controller{

class ControllerGui {

private:
    Game *game;

    GuiView *view;

public:

    ControllerGui(Game &game,GuiView &view);

    void launchGame();

};

}

#endif // GUICONTROLLER_H
