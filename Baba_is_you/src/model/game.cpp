#include"game.h"

namespace model {



int Game::getCurrentLevel() const
{
    return currentLevel;
}

bool Game::levelWon()
{
    return board.isWin();
}

bool Game::levelFailed()
{
    return board.isBlocked();
}


const model::Board &Game::getBoard() const
{
    return board;
}

Game::Game():currentLevel(0){}


void Game::startGame(){
    currentLevel=0;
    board.initialiseBoard(fileloader.initLevel(currentLevel));
    notifyObservers();

}

void Game::restartLevel()
{
    board.initialiseBoard(fileloader.initLevel(currentLevel));
    notifyObservers();
}

void Game::nextLevel()
{
   currentLevel++;
   board.initialiseBoard(fileloader.initLevel(currentLevel));
   notifyObservers();
}

void Game::move(Direction direction)
{
    board.moveGameObjects(direction);
    notifyObservers();
}

void Game::loadGame(std::string path)
{
    board.initialiseBoard(std::get<0>(fileloader.loadALevel(path)));
    currentLevel=std::get<1>(fileloader.loadALevel(path));
    notifyObservers();
}

void Game::saveGame(std::string newPath)
{
    fileloader.saveLevel(newPath,board.convertBoardToData(),currentLevel);
}

}
