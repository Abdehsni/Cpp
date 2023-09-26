 #include "Box.h"

using model::Piece;
using model::Position;
using model::Box;
using model::Player;
using model::Bomb;
using model::ColorPiece;

Box::Box(){
    piecesP1.push_back(Piece(10,"10", 1, ColorPiece::RED));

    piecesP1.push_back(Piece(9,"9", 1, ColorPiece::RED));

    piecesP1.push_back(Piece(8,"8", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(8,"8", 1, ColorPiece::RED));

    piecesP1.push_back(Piece(7,"7", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(7,"7", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(7,"7", 1, ColorPiece::RED));

    piecesP1.push_back(Piece(6,"6", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(6,"6", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(6,"6", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(6,"6", 1, ColorPiece::RED));

    piecesP1.push_back(Piece(5,"5", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(5,"5", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(5,"5", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(5,"5", 1, ColorPiece::RED));

    piecesP1.push_back(Piece(4,"4", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(4,"4", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(4,"4", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(4,"4", 1, ColorPiece::RED));

    piecesP1.push_back(Piece(3,"3", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(3,"3", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(3,"3", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(3,"3", 1, ColorPiece::RED));
    piecesP1.push_back(Piece(3,"3", 1, ColorPiece::RED));

    piecesP1.push_back(Scout(ColorPiece::RED));
    piecesP1.push_back(Scout(ColorPiece::RED));
    piecesP1.push_back(Scout(ColorPiece::RED));
    piecesP1.push_back(Scout(ColorPiece::RED));
    piecesP1.push_back(Scout(ColorPiece::RED));
    piecesP1.push_back(Scout(ColorPiece::RED));
    piecesP1.push_back(Scout(ColorPiece::RED));
    piecesP1.push_back(Scout(ColorPiece::RED));

    piecesP1.push_back(Piece(1,"1", 1, ColorPiece::RED));
    piecesP1.push_back(Flag(ColorPiece::RED));

    piecesP1.push_back(Bomb(ColorPiece::RED));
    piecesP1.push_back(Bomb(ColorPiece::RED));
    piecesP1.push_back(Bomb(ColorPiece::RED));
    piecesP1.push_back(Bomb(ColorPiece::RED));
    piecesP1.push_back(Bomb(ColorPiece::RED));
    piecesP1.push_back(Bomb(ColorPiece::RED));

    piecesP2=piecesP1;

    for (size_t i = 0 ; i< piecesP2.size();i++) {
        piecesP2.at(i).setColor(ColorPiece::BLUE);

    }

}


Piece Box::put(Player player,string piece){
    vector<Piece>&cp{player.getColorPiece()==ColorPiece::BLUE?piecesP2:piecesP1};
                     int size=player.getColorPiece()==ColorPiece::BLUE?piecesP2.size():piecesP1.size();
                                  for (int i =0;i<size ; i++) {
                                      if(cp.at(i).getSymbol()==piece){
                                          Piece tmp = cp.at(i);
                                          cp.erase(cp.begin()+i);
                                          return tmp ;
                                      }
                                  }


                                               throw "No more piece";
                    }

bool Box::pieceAllPutP1(){
    return piecesP1.empty()?true:false;
}

bool Box::pieceAllPutP2(){
    return piecesP2.empty()?true:false;
}

bool Box::pieceAllPut(){
   return pieceAllPutP1()&&pieceAllPutP2() ?true:false;
}


void Box::clearAll(){
    piecesP1.clear();
    piecesP2.clear();
}
