#ifndef BOARD_H
#define BOARD_H
#include "Square.h"
#include "Piece.h"
#include "Position.h"

/**
 * @brief The Board class
 */
namespace model{

class Board{

    Square squares[10][10];


public:

    Board();
    /**
     * @brief Give the square at the given position
     * @param position
     * @return the square
     */
    Square& getSquareAt(Position position);

    /**
     * @brief Give the piece at the given position
     * @param row
     * @param column
     * @return the piece
     */
    const Piece& getPieceAt(Position position);

    /**
     * Put a pion at position pos
     * @brief putPieceAt
     * @param pion
     * @param pos
     */
    void putPieceAt(Piece pion,Position pos);
    /**
     * @brief isInside
     * @param pos
     * @return true if pos is inside board
     */
    bool isInside(Position pos);

    /**
     * remove a piece from a square
     * @brief removePiece
     * @param square
     */
    void removePiece(Position position);
    /**
     * @brief Give the square at the given row and column
     * @param row
     * @param column
     * @return the square
     */
    Square& getSquareAt(int row, int column);

    /**
     * @brief Give the piece at the given row and column
     * @param row
     * @param column
     * @return the piece
     */
    const Piece& getPieceAt(int row,int column);

    /**
     * @brief Check if the piece is hidden or not
     * @param row
     * @param column
     * @return true if hidden
     */
    bool pieceIsHidden(int row,int column);

    /**
     * @brief Hide the piece at the given row and column
     * @param row
     * @param column
     */
    void hidePieceAt(int row,int column);
    /**
     * @brief Show the piece at the given row and column
     * @param row
     * @param column
     */
    void showPieceAt(int row, int column);

    bool indexPosWater(int i,int j);


};
}
#endif // BOARD_H
