#include "Game.h"

using model::Board;
using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Player;
using model::Cemetery;
using model::Flag;
using model::Game;
using model::Bomb;

Game::Game(){}

void Game::nextPlayer(){
    if(this->currentPlayer.getColorPiece()==ColorPiece::RED){
        this->currentPlayer=p2;
    }else{
        this->currentPlayer=p1;
    }
}


void Game::burriedPiece(Player p,Piece piece){
    cemetery.victime(p,piece);

}

bool Game::isSameSide(const Piece& piece1,const Piece& piece2){
    return piece1.getColor()==piece2.getColor()  ;

}

void Game::putPieceOnBoard(Piece piece,Position position){
    board.putPieceAt(piece,position);
}


bool Game::isFinish(){
    return cemetery.allDead(currentPlayer) || cemetery.flagFound(currentPlayer);
}

bool Game::correctPositionSelected(Position pos){
    return board.isInside(pos) && board.getSquareAt(pos).isAccessible();

}

void Game::set148(int nb){
    if(currentPlayer.getColorPiece()==ColorPiece::RED){
        cemetery.setNbDeadP1(nb);

    }else{
        cemetery.setNbDeadP2(nb);

    }

}




Piece Game::battle(Piece pieceAttk,Piece pieceDefense){
    setGamestate(GameState::INFIGHT);
    showOrHideOnePieceDuringAFight(destination,true);
    notifyAll();
    showOrHideOnePieceDuringAFight(destination,false);
    setGamestate(GameState::INPROCESS);
/*
    if(pieceDefense.getSymbol()=="B"){
    Bomb b(ColorPiece::BLUE) ;
    return b.battle(pieceAttk);

    }
    if(pieceDefense.getSymbol()=="D"){
    Flag f(ColorPiece::BLUE) ;
    return f.battle(pieceAttk);

    }
*/
   return pieceDefense.battle(pieceAttk);
}




/*Piece Game::battle(Piece pieceAttk,Piece pieceDefense){
    setGamestate(GameState::INFIGHT);
    Piece winner(pieceAttk);

    if(pieceAttk.getRank()!=3 && pieceDefense.getRank()==0){//ok
        winner=pieceDefense;
    }else if( (pieceAttk.getRank()==3 && pieceDefense.getRank()==0) ||//ok
              ( pieceAttk.getRank()==1 && pieceDefense.getRank()==10) ||
              (pieceDefense.getRank()==1000)){//ok
        winner=pieceAttk;

    }else{
        pieceAttk>pieceDefense?winner=pieceAttk:winner=pieceDefense;
    }
    showOrHideOnePieceDuringAFight(destination,true);
    notifyAll();
    showOrHideOnePieceDuringAFight(destination,false);
    setGamestate(GameState::INPROCESS);
    return winner;

}*/

bool Game::checkRepeatMove(Position wishPos, Piece piece){
    vector<Position> history=piece.getHistory();
    vector<Position> historyLast6;
    Position myPos = actualPos;

    for(auto i= history.rbegin() ;i!=history.rbegin()+6; i++){
        historyLast6.push_back(*i);

    }
    vector<Position>condition{myPos,wishPos,myPos,wishPos,myPos,wishPos};
    if(historyLast6==condition)return true;
    else return false;

}

void Game::newPosition(Position posInitial,Position posFinal){
    Piece pieceInit=board.getSquareAt(posInitial).getPiece();

    if(board.getSquareAt(posFinal).isEmpty()){
        board.removePiece(posInitial);
        pieceInit.addPosToHistory(posInitial);
        putPieceOnBoard(pieceInit,posFinal);

    }else{

        Piece pieceFin=board.getSquareAt(posFinal).getPiece();
        destination=posFinal;
        Piece pieceWinner=battle(pieceInit,pieceFin);


        if(pieceInit==pieceFin){
            burriedPiece(currentPlayer,pieceInit);
            burriedPiece(opposite(),pieceFin);
            board.removePiece(posFinal);
            board.removePiece(posInitial);
        }

        else if(pieceWinner==pieceInit){

            burriedPiece(currentPlayer,pieceFin);
            board.removePiece(posFinal);
            pieceInit.addPosToHistory(posInitial);
            board.removePiece(posInitial);
            putPieceOnBoard(pieceInit,posFinal);
        }else{
            burriedPiece(currentPlayer,pieceInit);
            board.removePiece(posInitial);
        }
    }

}

Player Game::opposite(){
    return currentPlayer==p1 ?p2:p1;
}

void Game::moveCheck(Position posInitial,Position posFinal){
    int totalMoves(abs((posFinal.row-posInitial.row)+(posFinal.column-posInitial.column)));

    if(!board.getSquareAt(posFinal).isEmpty()){
        if(isSameSide(board.getSquareAt(posInitial).getPiece(),board.getSquareAt(posFinal).getPiece())){
            throw std::invalid_argument("You cannot attack on a piece from the same camp as you");
        }
    }
    if(board.getPieceAt(posInitial).getMoveMax()==0||totalMoves>board.getPieceAt(posInitial).getMoveMax()){
        throw std::invalid_argument("You're not allowed to make this move");
    }


}

void Game::firstCheckPieceToMove(Position pos){
    if(board.getSquareAt(pos).isEmpty())throw std::invalid_argument("Select a position that contains a piece");
    verifyIfPieceIsYours(pos);
    if(!correctPositionSelected(pos))throw std::invalid_argument("Select a final position that is on earth in the board");
}

void Game::firstCheckDestinationPiece(Position pos){
    if(!correctPositionSelected(pos))throw std::invalid_argument("Select a final position that is on earth in the board");
}


void Game::moveScout(Position posInitial,Position posFinal){
    Position tmp1{0,0};
    if(posInitial.row==posFinal.row && posInitial.column!=posFinal.column){
        if(posInitial.column<posFinal.column){
            tmp1=Position{posInitial.row,posInitial.column+1};
            while(tmp1.column<posFinal.column){
                if(!board.getSquareAt(tmp1).isAccessible())
                    throw std::invalid_argument("You cannot pass through water ");

                if(!board.getSquareAt(tmp1).isEmpty() ){
                    throw std::invalid_argument("You cannot pass through a piece ") ;
                }
                tmp1=Position{tmp1.row,tmp1.column+1};
            }
        }
        if(posInitial.column>posFinal.column){

            tmp1=Position{posInitial.row,posInitial.column-1};
            while(tmp1.column>posFinal.column){
                if(!board.getSquareAt(tmp1).isAccessible())
                    throw std::invalid_argument("You cannot pass through water ");
                if(!board.getSquareAt(tmp1).isEmpty() ){
                    throw std::invalid_argument("You cannot pass through a piece ");
                }
                tmp1=Position{tmp1.row,tmp1.column-1};
            }
        }
    }else if(posInitial.row!=posFinal.row && posInitial.column==posFinal.column){
        if(posInitial.row<posFinal.row){

            tmp1=Position{posInitial.row+1,posInitial.column};
            while(tmp1.row<posFinal.row){
                if(!board.getSquareAt(tmp1).isAccessible())
                    throw std::invalid_argument("You cannot pass through water ");
                if(!board.getSquareAt(tmp1).isEmpty() ){
                    throw std::invalid_argument("You cannot pass through a piece ");
                }
                tmp1=Position{tmp1.row+1,tmp1.column};
            }
        }
        if(posInitial.row>posFinal.row){
            tmp1=Position{posInitial.row-1,posInitial.column};
            while(tmp1.row>posFinal.row){
                if(!board.getSquareAt(tmp1).isAccessible())
                    throw std::invalid_argument("You cannot pass through water ");

                if(!board.getSquareAt(tmp1).isEmpty() ){
                    throw std::invalid_argument("You cannot pass through a piece ");
                }
                tmp1=Position{tmp1.row-1,tmp1.column};
            }
        }
    }
    newPosition(posInitial,posFinal);
}



void Game::move(Position posInitial,Position posFinal){
    Piece piece = board.getSquareAt(posInitial).getPiece();
    switch (piece.getMoveMax()){
    case 0:
        throw std::invalid_argument("You cannot move this piece, it's a "+piece.getSymbol());
        break;

    case 1:
        newPosition(posInitial,posFinal);
        break;

    case 9 :
        int distance=posFinal-posInitial;
        if(distance>9)
            throw std::invalid_argument("you have far exceded the number of movement you can move");

        moveScout(posInitial,posFinal);
        break;
    }
}




void Game::placePieceOnBoard(string piece,Position pos){
    Piece copyPiece= box.put(currentPlayer,piece);
    putPieceOnBoard(copyPiece,pos);
}

bool Game::finishedToPutPiece(){
    return box.pieceAllPut();
}

bool Game::finishedToPutPieceForOnePlayer(){
    if(currentPlayer==p1){
        return box.pieceAllPutP1();
    }else{
        return box.pieceAllPutP2();
    }
}



void Game::showOrHideAllPiecesOfTheCurrentPlayer(bool show){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(!board.getSquareAt(i,j).isEmpty()&&board.getSquareAt(i,j).getPiece().getColor()==currentPlayer.getColorPiece()){
                if(show)board.showPieceAt(i,j);
                else board.hidePieceAt(i,j);
            }
        }
    }

}


void Game::showOrHideOnePieceDuringAFight(Position posPiece,bool show){
    if(show)board.showPieceAt(posPiece.row,posPiece.column);
    else board.hidePieceAt(posPiece.row,posPiece.column);

}


void Game::initWithFile(string path){
    string symbol;
    std::ifstream input_file(path,std::ifstream::in);

    if(!input_file.is_open()){
        throw std::invalid_argument("Cannot open the config files");
    }
    else{

        int i(0),j(0);
        if(gamestate==GameState::CONFIGPLAYER1){
            while(input_file>>symbol&&i<4){
                if(i==0){
                    placePieceOnBoard(symbol,Position(i,j));
                    j++;
                    if(j==10){
                        j=0;
                        i++;
                    }
                }else if(i==1){
                    placePieceOnBoard(symbol,Position(i,j));
                    j++;
                    if(j==10){
                        j=0;
                        i++;
                    }

                }else if(i==2){
                    placePieceOnBoard(symbol,Position(i,j));
                    j++;
                    if(j==10){
                        j=0;
                        i++;
                    }
                }else if(i==3){
                    placePieceOnBoard(symbol,Position(i,j));
                    j++;
                    if(j==10){
                        j=0;
                        i++;
                    }
                }
            }
        }
        else if(gamestate==GameState::CONFIGPLAYER2){
            i=9;
            while(input_file>>symbol&&i>5){
                if(i==9){
                    placePieceOnBoard(symbol,Position(i,j));
                    j++;
                    if(j==10){
                        j=0;
                        i--;
                    }
                }else if(i==8){
                    placePieceOnBoard(symbol,Position(i,j));
                    j++;
                    if(j==10){
                        j=0;
                        i--;
                    }

                }else if(i==7){
                    placePieceOnBoard(symbol,Position(i,j));
                    j++;
                    if(j==10){
                        j=0;
                        i--;
                    }
                }else if(i==6){
                    placePieceOnBoard(symbol,Position(i,j));
                    j++;
                    if(j==10){
                        j=0;
                        i--;
                    }
                }
            }
        }
        input_file.close();
    }
}


void Game::setGamestate(const GameState& newGamestate){
    gamestate=newGamestate;
}


void Game::verifyIfPieceIsYours(Position pos){
    if(board.getSquareAt(pos).getPiece().getColor()!=currentPlayer.getColorPiece()){
        throw std::invalid_argument("This Piece is not yours, try again: ");
    }
}

void Game::notifyView(){
    notifyAll();
}

bool Game::wonByCapturingTheFlag(){
    if(gamestate!=GameState::END){
        throw std::invalid_argument("You cannot use this function when the game is still running");
    }else{
        if(cemetery.flagFound(currentPlayer)){
            return true;
        }else{
            return false;
        }
    }
}


bool Game::isPlayer1Turn(){
    return currentPlayer.getColorPiece()==ColorPiece::RED?true:false;
}
