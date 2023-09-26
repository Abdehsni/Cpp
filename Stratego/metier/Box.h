#ifndef BOX_H
#define BOX_H
#include<vector>
#include "Piece.h"
#include "Player.h"

using std::vector;
/**
 * this class is the bow from where the player take piece from en put it on board
 * @brief The Box class
 */
namespace model {

class Box{
private:
    vector<Piece> piecesP1;
    vector<Piece> piecesP2;

public:

    /**
     * @brief Box constructor
     */
    Box();

    /**
     * @brief take a piece in the box
     * @param piece
     * @return the wished piece
     */
    Piece put(Player player,string piece);
    /**
     * @brief Check if the pieces of a player are all put
     * @return true
     */
    bool pieceAllPut();
    /**
     * @brief  The getter of the private attribute piecesP1
     */
    const vector<Piece> &getPiecesP1() const;
    /**
     * @brief  The setter of the private attribute piecesP1
     * @param newPiecesP1
     */
    void setPiecesP1(const vector<Piece> &newPiecesP1);
    /**
     * @brief  The getter of the private attribute piecesP2
     */
    const vector<Piece> &getPiecesP2() const;
    /**
     * @brief  The setter of the private attribute piecesP2
     * @param newPiecesP2
     */
    void setPiecesP2(const vector<Piece> &newPiecesP2);
    /**
     * @brief Method only used for a test ,the method clean the 2 box
     */
    void clearAll();
    /**
       * @brief Check if the piece are all put for player 1
       * @return true
       */
    bool pieceAllPutP1();
    /**
       * @brief Check if the piece are all put for player 2
       * @return true
       */
    bool pieceAllPutP2();

};

inline const vector<Piece> &Box::getPiecesP1() const
{
    return piecesP1;
}

inline void Box::setPiecesP1(const vector<Piece> &newPiecesP1)
{
    piecesP1 = newPiecesP1;
}

inline const vector<Piece> &Box::getPiecesP2() const
{
    return piecesP2;
}

inline void Box::setPiecesP2(const vector<Piece> &newPiecesP2)
{
    piecesP2 = newPiecesP2;
}


}
#endif // BOX_H
