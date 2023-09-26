#include"controllergui.h"
#include"mainwindow.h"
#define MinSizePathName 4

ControllerGui::ControllerGui(model::Game &game):_game(game),loadingGame(true),gameStarded(false){
}


void ControllerGui::setView(std::unique_ptr<MainWindow> mainwindow){
    _mainwindow = std::move(mainwindow);
    _game.registerObserver(_mainwindow.get());
}

void ControllerGui::launchGame()
{
    _mainwindow->beginning();
}

void ControllerGui::loadGame(std::string filename)
{
    _game.loadGame(filename);
    loadingGame=false;
    gameStarded=true;

}

void ControllerGui::saveGame(std::string filename)
{
    _game.saveGame(filename);
}

void ControllerGui::reloadLevelGame()
{
    _game.restartLevel();
}


void ControllerGui::startGameWithoutFile(){
    loadingGame=false;
    _game.startGame();
    gameStarded=true;
}

bool ControllerGui::isLoadingGame() const
{
    return loadingGame;
}

bool ControllerGui::isGameStarded() const
{
    return gameStarded;
}


bool ControllerGui::verifyFilename(std::string filename)
{
    bool valideinput{false};
    if (filename.size() > MinSizePathName && filename.substr(filename.size()-4) == ".txt")valideinput=true;
    return valideinput;
}


void ControllerGui::move(const model::Direction &direction)
{
    _game.move(direction);
    if(_game.levelWon()){
        _game.nextLevel();
    }
}

