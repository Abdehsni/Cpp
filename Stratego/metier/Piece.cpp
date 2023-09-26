#include "Piece.h"

using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Flag;
using model::Bomb;
using model::Scout;
bool Piece::getIsHidden() const
{
    return isHidden;
}

Piece::Piece(int rank, const string &symbol, int moveMax, ColorPiece color) : rank(rank),
    symbol(symbol),
    moveMax(moveMax),
    color(color)
{}
Bomb::Bomb(ColorPiece color):Piece(0,"B", 0, color){}
Flag::Flag(ColorPiece color):Piece(1000,"D", 0, color){}
Scout::Scout(ColorPiece color):Piece(2,"2", 9, color){}

Piece Piece::battle(Piece pieceAttk){
    if(pieceAttk.getRank()==1 && this->getRank()==10){
        return pieceAttk;
    }else{
        return  pieceAttk.getRank()>this->getRank()? pieceAttk:*this;
    }

}


void Piece::addPosToHistory(Position pos){
    this->history.push_back(pos);
}


void Piece::showPiece(){
    isHidden=false;
}

void Piece::hidePiece(){
    isHidden=true;
}

