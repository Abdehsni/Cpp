#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "Game.h"
#include"Position.h"
#include"Box.h"
#include"Board.h"
#include"Player.h"
#include"Observer.h"

using std::string;
using model::Board;
using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Player;
using model::Cemetery;
using model::Flag;
using model::Game;
using model::Bomb;
using model::Box;
using model::GameState;
using model::SquareType;
/**
 * @brief The View struct
 */

namespace View{

class game;


class ConsoleView : public observer::Observer{

    Game *game;




public:
    /**
     *
     * @brief Here
     */
    explicit ConsoleView(Game *game);
    /**
     *
     * @brief Here
     */
    ~ConsoleView();
    /**
     *
     * @brief Here
     */
    void update(const observer::Observable * observable)override;
    /**
     *
     * @brief Here
     */
    void intro();   

    /**
     * show the board
     * @brief displayBoard
     * @param board
     */
    void displayBoard(Board board);
    /**
     *
     * @brief Here
     */
    void displayLetter();
    /**
     *
     * @brief Here
     */
    void horizontalLine();
    /**
     *
     * @brief Here
     */
    void pieceLine(Board board, int n);
    /**
     *
     * @brief Here
     */
    string pieceSymbol(Piece piece);
    /**
     *
     * @brief Here
     */
    void displayNumber(int number);


    /**
     * show the box
     * @brief displayBox
     * @param box
     */
     void displayBox(const Box& box, const Player &p);
     /**
      *
      * @brief Here
      */
     void displayBoxP1(const Box& box);
     /**
      *
      * @brief Here
      */
     void displayBoxP2(const Box& box);

     /**
      * show the a display with name and symbol
      * @brief displayNameSymbol
      */
     void displayNameSymbol();

     /**
      * display an error message
      * @brief displayError
      * @param message
      */
     void displayError(string message);

     void prepareTheBoardDisplay();

    void prepareTheFinalBoardDisplay();

    void displayTheWinnerAndShowStat();

    string inscriptionPlayer(int n);

    bool AskFileDisposition();

    string askPathForFileDisposition();

    void configMessage();
    void initWithFileSuccesMessage();
};
}
#endif // CONSOLEVIEW_H
