#ifndef CONTROLLERGUI_H
#define CONTROLLERGUI_H

#include <iostream>
#include <memory>
#include "model/game.h"

class MainWindow;


class ControllerGui{

    std::unique_ptr<MainWindow>_mainwindow;
    model::Game _game;
    bool loadingGame;
    bool gameStarded;

public:
    ControllerGui(model::Game& game);
    void startGameWithoutFile();
    void setView(std::unique_ptr<MainWindow> mainwindow);
    void launchGame();
    void loadGame(std::string filename);
    void saveGame(std::string filename);
    void reloadLevelGame();
    void move(const model::Direction &direction);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    bool isLoadingGame() const;
    bool verifyFilename(std::string filename);

    bool isGameStarded() const;
};
#endif // CONTROLLERGUI_H

