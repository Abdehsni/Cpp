#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H
#include"ConsoleView.h"
#include"Game.h"

using View::ConsoleView;

namespace controller {

class Controller{
    /*!
     * \brief game_ the game object
     */
    Game *game;
    /*!
     * \brief view_ the view objetc
     */
    ConsoleView *view;

public:
    /*!
     * \brief Controller simple constructor of the class
     * \param game the game object
     * \param view the view object
     */
    Controller(Game *game,ConsoleView *view);
    /*!
     * \brief launchGame method launching and continuing the game.
     */
    void startGame();
    /**
     * ask for the name of the player
     * @brief inscriptionPlayer
     * @return name of player
     */
    //void inscriptionPlayer();
    /**
     *
     * @brief Here
     */
    //bool AskFileDisposition();
    /**
     *
     * @brief Here
     */
    string AskPieceToPlace();
    /**
     *
     * @brief Here
     */
    bool verifySymbolEntry(string symbol);
    /**
     *
     * @brief Here
     */
    void putPieceFromBoxToBoard();
    /**
     *
     * @brief Here
     */
    Position AskDestinationPiece();
    /**
     *
     * @brief Here
     */
    Position convertStringToPosition(string str);
    /**
     *
     * @brief Here
     */
    Position AskPieceToMove();
    /**
     *
     * @brief Here
     */
    Position askPosition();
    /**
     *
     * @brief Here
     */
    void configurePiecePlacement();
    /**
     *
     * @brief Here
     */
    void config_manual();
    /**
     *
     * @brief Here
     */
    bool verifyPositionForPlayerDuringConfig(string pos);

    void prepareTheBoardDisplay();

};


}
#endif // CONSOLECONTROLLER_H
