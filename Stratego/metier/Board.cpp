#include "Board.h"

using model::Board;
using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Square;



Board::Board(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(indexPosWater(i,j)){
                squares[i][j]=Square(SquareType::WATER);
            }
            else{
                squares[i][j]=Square(SquareType::LAND);
            }
        }
    }
}

bool Board::indexPosWater(int i,int j){
    if((i==4||i==5)&&(j==2||j==3||j==6||j==7))return true;
    else return false;
}


Square& Board::getSquareAt(int row, int column){
    return squares[row][column];
}

Square& Board::getSquareAt(Position position){
    return getSquareAt(position.row,position.column);
}

void Board::putPieceAt(Piece pion, Position pos){
    if(!getSquareAt(pos).isEmpty()){
        throw std::invalid_argument("There is already a piece ");
    }
    squares[pos.row][pos.column].setPiece(pion);
}

bool Board::isInside(Position pos){
    return(pos.row>=0&&pos.row<10&&pos.column>=0&&pos.column<10)? true: false;
}

void Board::removePiece(Position position){
    getSquareAt(position).remove();
}

const Piece& Board::getPieceAt(int row,int column){
    return getSquareAt(row,column).getPiece();
}

const Piece& Board::getPieceAt(Position position){
    return getSquareAt(position).getPiece();
}

bool Board::pieceIsHidden(int row,int column){
    return getPieceAt(row,column).getIsHidden();
}

void Board::hidePieceAt(int row,int column){
    squares[row][column].hidePiece();
}

void Board::showPieceAt(int row, int column){
    squares[row][column].showPiece();
}


