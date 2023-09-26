#include "Square.h"
using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Flag;
using model::Square;
using model::SquareType;

Square::Square(const SquareType& squareType):squareType(squareType){}

Square::Square(){}


/**
 * @brief isEmpty
 * @return true if the square is empty
 */

bool Square::isEmpty(){
   return !piece.has_value();
}

bool Square::isAccessible(){
   if(this->squareType==SquareType::LAND){
       return true;
   }else{
       return false;
   }
}

void Square::remove(){
    this->piece.reset();
}

void Square::hidePiece(){
    piece->hidePiece();
}

void Square::showPiece(){
    piece->showPiece();
}
