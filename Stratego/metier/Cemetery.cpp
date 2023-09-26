#include "Cemetery.h"

using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Player;
using model::Cemetery;
using model::Flag;

void Cemetery::victime(Player& p,Piece& piece){

    if(p.getColorPiece()==ColorPiece::RED ){
        nbDeadP1+=piece.getRank();
    }else{
        nbDeadP2+=piece.getRank();

    }
}

bool Cemetery::flagFound(Player &currentPlayer){
    if(currentPlayer.getColorPiece()==ColorPiece::RED){
        return nbDeadP1>=1000;
    }else{
        return nbDeadP2>=1000;
    }
}

bool Cemetery::allDead(Player& p){
    if(p.getColorPiece()==ColorPiece::BLUE){
        return nbDeadP2==148 ;
    }else{
        return nbDeadP1==148 ;
    }
    return false ;
}

































