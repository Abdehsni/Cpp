#ifndef GAME_H
#define GAME_H

#include <iterator>
#include "Board.h"
#include "Box.h"
#include "Player.h"
#include "Cemetery.h"
#include "Position.h"
#include "gameState.h"
#include "Observable.h"
#include <fstream>
/**
 * @brief The Game class
 */

namespace model {

class Game:public observer::Observable{

    Board board;
    Box box;
    Player p1;
    Player p2;
    Player currentPlayer;
    Cemetery cemetery;
    Position actualPos;
    GameState gamestate{GameState::INSCRIPTIONPLAYER1};
    Position destination;

public:
     Game();
     /**
      * @brief The getter of the private attribute board
      *  @return the board
      */
     Board &getBoard() ;
     /**
      * @brief The getter of the private attribute box
      * @return the box
      */
    const Box &getBox() const;
    /**
     * @brief The setter of the private attribute box
     * @param newBox
     */
    void setBox(const Box &newBox);
    /**
     * @brief The getter of the private attribute p1
     */
    const Player &getP1() const;
    /**
     * @brief The setter of the private attribute p1
     * @param newP1
     */
    void setP1(const Player &newP1);
    /**
     * @brief The getter of the private attribute p2
     */
    const Player &getP2() const;
    /**
     * @brief The setter of the private attribute p2
     * @param newP2
     */
    void setP2(const Player &newP2);
    /**
     * @brief The getter of the private attribute currentPlayer
     */
    const Player &getCurrentPlayer() const;
    /**
     * @brief The setter of the private attribute currentPlayer
     * @param newCurrentPlayer
     */
    void setCurrentPlayer(const Player &newCurrentPlayer);
    /**
     * @brief The getter of the private attribute cemetery
     */
    const Cemetery &getCemetery() const;
    /**
     * @brief The setter of the private attribute cemetery
     * @param newCemetery
     */
    void setCemetery(const Cemetery &newCemetery);
    /**
     * @brief The getter of the private attribute actualPos
     */
    const Position &getActualPos() const;
    /**
     * @brief The setter of the private attribute actualPos
     * @param newActualPos
     */
    void setActualPos(const Position &newActualPos);
    /**
     * @brief initialise the game with file
     */
    void initWithFile(string path);
    /**
     * @brief Verify if the game is finished
     * @return true if the game is finished
     */
    bool isFinish();

    /**
     * @brief Verify if the given position is on board and on a case of type LAND
     * @param pos the given position
     * @return true if the position pos is selectable
     */
    bool correctPositionSelected(Position pos);

    /**
     * @brief move a piece from a posInitial to posFinal
     * @param posInitial the initial position
     * @param posFinal the final position
     */
    void move(Position posInitial,Position posFinal);
    /**
     * @brief battle between two pieces
     * @param pieceDefense the defense piece
     * @param pieceAttk the attack piece
     * @return the Piece that win the battle
     */
    Piece battle (Piece pieceDefense ,Piece pieceAttk);
    /**
     * @brief next Player turn
     */
    void nextPlayer();
    /**
     * @brief put a piece on a position
     * @param position the given position
     * @param piece the piece to put a this position
     */
     void putPieceOnBoard(Piece piece,Position position);
     /**
      * @brief send a piece to a cementery
      * @param p the current player
      * @param piece the given piece
      */
    void burriedPiece(Player p,Piece piece);
    /**
     * @brief check the rule of coming and going 3 times on the same squares
     * @param wishPos the position where the player want to go
     * @param piece the piece to place
     * @return true if it is already coming and going 3 times consecutively
     */
    bool checkRepeatMove(Position wishPos, Piece piece);
    /**
     * @brief check if the two are on the same camp
     * @param piece1 the first piece
     * @param piece2 the second piece
     * @return true if piece1 and piece2 are in the same side
     */
    bool  isSameSide(const Piece& piece1,const Piece& piece2);

    /**
     * Change the visibility of the piece
     * @brief changeVisibilityPiece
     * @param piece
     */
    void changeVisibilityPiece(Piece Piece);
    /**
     * @brief The getter of the private attribute gamestate
     */
    const GameState& getGamestate()const;
    /**
     * @brief Put the piece from the box on the board
     * @param piece the wished piece
     * @param pos the position to put the piece
     */
    void setGamestate(const GameState& newGamestate);

    /**
     * @brief Method for the test ,the method put the number of dead at 148
     * @param nb
     */
    void set148(int nb);
    /**
     * @brief Change the position of a piece
     * @param posInitial the position where the piece is
     * @param posFinal the position where the piece want to go
     */
    void newPosition(Position posInitial,Position posFinal);
    /**
     * @brief Verify the given positions
     * @param posInitial the position where the piece is
     * @param posFinal the position where the piece want to go
     */
    void moveCheck(Position posInitial,Position posFinal);
    /**
     * @brief Move the scout
     * @param posInitial the position where the piece is
     * @param posFinal the position where the piece want to go
     */
    void moveScout(Position posInitial,Position posFinal);
    /**
     * @brief  Change the player
     * @return the other player
     */
    Player opposite();
    /**
     * @brief Put the piece from the box on the board
     * @param piece the wished piece
     * @param pos the position to put the piece
     */
    void placePieceOnBoard(string piece, Position pos);
    /**
     * @brief  Check if the piece are all put
     * @return true
     */
    bool finishedToPutPiece();
    /**
       * @brief Check if the piece are all put for one player
       * @return true
       */
    bool finishedToPutPieceForOnePlayer();
    /**
       * @brief Show or hide the piece of the currentPlayer
       * @param show
       * @return true
       */
    void showOrHideAllPiecesOfTheCurrentPlayer(bool show);

    void showOrHideOnePieceDuringAFight(Position posPiece,bool show);

    void verifyIfPieceIsYours(Position pos);

    void firstCheckPieceToMove(Position pos);

    void firstCheckDestinationPiece(Position pos);

    void notifyView();

    bool wonByCapturingTheFlag();

    bool isPlayer1Turn();

};

inline  Board &Game::getBoard()
{
    return board;
}

inline const Box &Game::getBox() const
{
    return box;
}

inline void Game::setBox(const Box &newBox)
{
    box = newBox;
}

inline const Player &Game::getP1() const
{
    return p1;
}

inline void Game::setP1(const Player &newP1)
{
    p1 = newP1;
}

inline const Player &Game::getP2() const
{
    return p2;
}

inline void Game::setP2(const Player &newP2)
{
    p2 = newP2;
}

inline const Player &Game::getCurrentPlayer() const
{
    return currentPlayer;
}

inline void Game::setCurrentPlayer(const Player &newCurrentPlayer)
{
    currentPlayer = newCurrentPlayer;
}

inline const Cemetery &Game::getCemetery() const
{
    return cemetery;
}

inline void Game::setCemetery(const Cemetery &newCemetery)
{
    cemetery = newCemetery;
}

inline const Position &Game::getActualPos() const
{
    return actualPos;
}

inline void Game::setActualPos(const Position &newActualPos)
{
    actualPos = newActualPos;
}

inline const GameState &Game::getGamestate() const{
    return gamestate;
}

}
#endif // GAME_H




