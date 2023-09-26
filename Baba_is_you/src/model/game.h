#ifndef GAME_H
#define GAME_H
#include"board.h"
#include"fileloader.h"
#include "utility/Observable.h"

namespace model {

class Game:public Observable{
    int currentLevel;
    model::Board board;
    model::FileLoader fileloader;

public:
    Game();
    void startGame();
    void restartLevel();
    void nextLevel();
    void move(model::Direction direction);
    void loadGame(std::string path);
    void saveGame(std::string newPath);
    const model::Board &getBoard() const;
    int getCurrentLevel() const;
    bool levelWon();
    /// to check if the game is blocked
    /// \brief levelFailed
    bool levelFailed();
};

}





#endif // GAME_H
