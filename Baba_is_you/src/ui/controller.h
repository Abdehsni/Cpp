#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <memory>
#include "model/game.h"

namespace view{class View;}

class Controller{

    std::unique_ptr<view::View> _view;
    model::Game _game;

    bool inputYesOrNo();
    bool checkInput(const std::string& input);
    std::string askForAction();
    std::string askForPathForSavingOrLoadingGame(bool saving);
public:
    Controller(std::unique_ptr<view::View>view);
    void playGame();
    const model::Game &game() const;
};







#endif // CONTROLLER_H
