#ifndef SQUARE_H
#define SQUARE_H
#include "Piece.h"
#include<optional>
#include"Squaretype.h"
using std::optional;
/**
 * @brief The Square class
 */
namespace model {

class Square{
    SquareType squareType=SquareType::LAND;
    optional<Piece> piece;

public:
    Square();
    /**
     * @brief constructor of an empty Square
     * @param piece
     */
    Square(const SquareType& squareType);
    /**
     * @brief isEmpty
     * @return true if the square is empty
     */
    bool isEmpty();
    /**
     * @brief isAccessible
     * @param square
     * @return true if the squareType is land
     */
    bool isAccessible();
    /**
     * @brief getSquareType
     */
    SquareType getSquareType() const;
    /**
     * @brief setSquareType
     * @param newSquareType
     */
    void setSquareType(SquareType newSquareType);
    /**
     * @brief getPiece
     */
    const Piece &getPiece() const;
    /**
     * @brief setPiece
     * @param newPiece
     */
    void setPiece(const Piece &newPiece);

    void remove();

    void hidePiece();

    void showPiece();
};

inline SquareType Square::getSquareType() const
{
    return squareType;
}

inline void Square::setSquareType(SquareType newSquareType)
{
    squareType = newSquareType;
}

inline const Piece &Square::getPiece() const
{
    return piece.value();
}

inline void Square::setPiece(const Piece &newPiece)
{
    piece = newPiece;
}

}

#endif // SQUARE_H


