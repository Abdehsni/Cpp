#include"consoleController.h"

using controller::Controller;
using std::cout;
using std::cin;
using std::endl;

Controller::Controller(Game *game, ConsoleView *view):game(game),view(view)
{

}

bool Controller::verifySymbolEntry(string symbol){

    if(symbol=="10"||symbol=="9"||symbol=="8"||symbol=="7"||symbol=="6"||symbol=="5"||
            symbol=="4"||symbol=="3"||symbol=="2"||symbol=="1"||symbol=="D"||symbol=="B"){
        return true;
    }else{
        return false;
    }

}

Position Controller::askPosition(){
    string position;
    Position pos;
    cin>>position;
    try {
        if(game->getGamestate()==GameState::CONFIGPLAYER1||game->getGamestate()==GameState::CONFIGPLAYER2){
            while(!verifyPositionForPlayerDuringConfig(position)){
                cout<<"Cette case vous est innaccessible reessayez : ";
                position="";
                cin>>position;
            }
        }
        pos=convertStringToPosition(position);
    }  catch (std::exception &e) {
        view->displayError(e.what());
        cout<<"try again : "<<endl;

    }
    return pos;
}


string Controller::AskPieceToPlace(){
    string symbol;
    cout<<"Quel piece voulez-vous placer?(Entrez un symbole): ";
    cin>>symbol;
    while(!verifySymbolEntry(symbol)){
        symbol="";
        cout<<"Veuillez entrer un symbole valide (Faites attention aux majuscules et espaces) : ";
        cin>>symbol;
    }
    return symbol;
}


Position Controller::AskDestinationPiece(){
    if(game->getGamestate()==GameState::CONFIGPLAYER1||game->getGamestate()==GameState::CONFIGPLAYER2){
        cout<<"Entrez ou vous souhaitez placer votre piece : "<<endl;
    }else{
        cout<<"Entrez ou vous souhaitez deplacer votre piece : "<<endl;
    }
    return askPosition();
}



Position Controller::convertStringToPosition(string str){
    Position pos;
    if(str=="A1"){
        return Position(0,0);
    }else if(str=="A2"){
        return Position(1,0);
    }else if(str=="A3"){
        return Position(2,0);
    }else if(str=="A4"){
        return Position(3,0);
    }else if(str=="A5"){
        return Position(4,0);
    }else if(str=="A6"){
        return Position(5,0);
    }else if(str=="A7"){
        return Position(6,0);
    }else if(str=="A8"){
        return Position(7,0);
    }else if(str=="A9"){
        return Position(8,0);
    }else if(str=="A10"){
        return Position(9,0);
    }else if(str=="B1"){
        return Position(0,1);
    }else if(str=="B2"){
        return Position(1,1);
    }else if(str=="B3"){
        return Position(2,1);
    }else if(str=="B4"){
        return Position(3,1);
    }else if(str=="B5"){
        return Position(4,1);
    }else if(str=="B6"){
        return Position(5,1);
    }else if(str=="B7"){
        return Position(6,1);
    }else if(str=="B8"){
        return Position(7,1);
    }else if(str=="B9"){
        return Position(8,1);
    }else if(str=="B10"){
        return Position(9,1);
    }else if(str=="C1"){
        return Position(0,2);
    }else if(str=="C2"){
        return Position(1,2);
    }else if(str=="C3"){
        return Position(2,2);
    }else if(str=="C4"){
        return Position(3,2);
    }else if(str=="C5"){
        return Position(4,2);
    }else if(str=="C6"){
        return Position(5,2);
    }else if(str=="C7"){
        return Position(6,2);
    }else if(str=="C8"){
        return Position(7,2);
    }else if(str=="C9"){
        return Position(8,2);
    }else if(str=="C10"){
        return Position(9,2);
    }else if(str=="D1"){
        return Position(0,3);
    }else if(str=="D2"){
        return Position(1,3);
    }else if(str=="D3"){
        return Position(2,3);
    }else if(str=="D4"){
        return Position(3,3);
    }else if(str=="D5"){
        return Position(4,3);
    }else if(str=="D6"){
        return Position(5,3);
    }else if(str=="D7"){
        return Position(6,3);
    }else if(str=="D8"){
        return Position(7,3);
    }else if(str=="D9"){
        return Position(8,3);
    }else if(str=="D10"){
        return Position(9,3);
    }else if(str=="E1"){
        return Position(0,4);
    }else if(str=="E2"){
        return Position(1,4);
    }else if(str=="E3"){
        return Position(2,4);
    }else if(str=="E4"){
        return Position(3,4);
    }else if(str=="E5"){
        return Position(4,4);
    }else if(str=="E6"){
        return Position(5,4);
    }else if(str=="E7"){
        return Position(6,4);
    }else if(str=="E8"){
        return Position(7,4);
    }else if(str=="E9"){
        return Position(8,4);
    }else if(str=="E10"){
        return Position(9,4);
    }else if(str=="F1"){
        return Position(0,5);
    }else if(str=="F2"){
        return Position(1,5);
    }else if(str=="F3"){
        return Position(2,5);
    }else if(str=="F4"){
        return Position(3,5);
    }else if(str=="F5"){
        return Position(4,5);
    }else if(str=="F6"){
        return Position(5,5);
    }else if(str=="F7"){
        return Position(6,5);
    }else if(str=="F8"){
        return Position(7,5);
    }else if(str=="F9"){
        return Position(8,5);
    }else if(str=="F10"){
        return Position(9,5);
    }else if(str=="G1"){
        return Position(0,6);
    }else if(str=="G2"){
        return Position(1,6);
    }else if(str=="G3"){
        return Position(2,6);
    }else if(str=="G4"){
        return Position(3,6);
    }else if(str=="G5"){
        return Position(4,6);
    }else if(str=="G6"){
        return Position(5,6);
    }else if(str=="G7"){
        return Position(6,6);
    }else if(str=="G8"){
        return Position(7,6);
    }else if(str=="G9"){
        return Position(8,6);
    }else if(str=="G10"){
        return Position(9,6);
    }else if(str=="H1"){
        return Position(0,7);
    }else if(str=="H2"){
        return Position(1,7);
    }else if(str=="H3"){
        return Position(2,7);
    }else if(str=="H4"){
        return Position(3,7);
    }else if(str=="H5"){
        return Position(4,7);
    }else if(str=="H6"){
        return Position(5,7);
    }else if(str=="H7"){
        return Position(6,7);
    }else if(str=="H8"){
        return Position(7,7);
    }else if(str=="H9"){
        return Position(8,7);
    }else if(str=="H10"){
        return Position(9,7);
    }else if(str=="I1"){
        return Position(0,8);
    }else if(str=="I2"){
        return Position(1,8);
    }else if(str=="I3"){
        return Position(2,8);
    }else if(str=="I4"){
        return Position(3,8);
    }else if(str=="I5"){
        return Position(4,8);
    }else if(str=="I6"){
        return Position(5,8);
    }else if(str=="I7"){
        return Position(6,8);
    }else if(str=="I8"){
        return Position(7,8);
    }else if(str=="I9"){
        return Position(8,8);
    }else if(str=="I10"){
        return Position(9,8);
    }else if(str=="J1"){
        return Position(0,9);
    }else if(str=="J2"){
        return Position(1,9);
    }else if(str=="J3"){
        return Position(2,9);
    }else if(str=="J4"){
        return Position(3,9);
    }else if(str=="J5"){
        return Position(4,9);
    }else if(str=="J6"){
        return Position(5,9);
    }else if(str=="J7"){
        return Position(6,9);
    }else if(str=="J8"){
        return Position(7,9);
    }else if(str=="J9"){
        return Position(8,9);
    }else if(str=="J10"){
        return Position(9,9);
    }else{
        throw std::invalid_argument("La position entree n'existe pas");
    }
    return pos;
}


Position Controller::AskPieceToMove(){
    cout<<"Entrez la position de la piece que vous souhaitez deplacer : "<<endl;
    return askPosition();
}



void Controller::putPieceFromBoxToBoard(){
    string piece;
    Position place;
    cout<<"Les pions restants de votre Box : "<<endl;
    if(game->getCurrentPlayer()==game->getP1()){
        view->displayBoxP1(game->getBox());
    }else{
        view->displayBoxP2(game->getBox());
    }
    piece= AskPieceToPlace();
    place= AskDestinationPiece();
    game->placePieceOnBoard(piece,place);
}


void Controller::config_manual(){
    while(!game->finishedToPutPiece()){
        while(!game->finishedToPutPieceForOnePlayer()){
            view->displayBoard(game->getBoard());
            view->displayBox(game->getBox(),game->getCurrentPlayer());
            game->placePieceOnBoard(AskPieceToPlace(),AskDestinationPiece());
        }
    }
}



void Controller::configurePiecePlacement(){
    if(view->AskFileDisposition()){
        try{
            string path(view->askPathForFileDisposition());
            game->initWithFile(path);
            view->initWithFileSuccesMessage();
        }catch(std::exception &e){
            view->displayError(e.what());
            cout<<"A defaut de fichier de configuration correct, vous allez passer à la configuration manuelle"<<endl;
            config_manual();
        }
    }else{
        config_manual();
    }
}


bool Controller::verifyPositionForPlayerDuringConfig(string pos){
    if(game->getCurrentPlayer()==game->getP1()){
        if(pos=="A1"||pos=="A2"||pos=="A3"||pos=="A4"||pos=="B1"||pos=="B2"||pos=="B3"||pos=="B4"||pos=="C1"||pos=="C2"||pos=="C3"||pos=="C4"||
                pos=="D1"||pos=="D2"||pos=="D3"||pos=="D4"||pos=="E1"||pos=="E2"||pos=="E3"||pos=="E4"||pos=="F1"||pos=="F2"||pos=="F3"||pos=="F4"||
                pos=="G1"||pos=="G2"||pos=="G3"||pos=="G4"||pos=="H1"||pos=="H2"||pos=="H3"||pos=="H4"||pos=="I1"||pos=="I2"||pos=="I3"||pos=="I4"||
                pos=="J1"||pos=="J2"||pos=="J3"||pos=="J4")return true;
        else return false;
    }else if(game->getCurrentPlayer()== game->getP2()){
        if(pos=="A7"||pos=="A8"||pos=="A9"||pos=="A10"||pos=="B7"||pos=="B8"||pos=="B9"||pos=="B10"|| pos=="C7"||pos=="C8"||pos=="C9"||pos=="C10"||
                pos=="D7"||pos=="D8"||pos=="D9"||pos=="D10"|| pos=="E7"||pos=="E8"||pos=="E9"||pos=="E10"|| pos=="F7"||pos=="F8"||pos=="F9"||pos=="F10"||
                pos=="G7"||pos=="G8"||pos=="G9"||pos=="G10"|| pos=="H7"||pos=="H8"||pos=="H9"||pos=="H10"|| pos=="I7"||pos=="I8"||pos=="I9"||pos=="I10"||
                pos=="J7"||pos=="J8"||pos=="J9"||pos=="J10")return true;
        else return false;
    }else return false;
}



void Controller::startGame(){
    view->intro();
    string name;
    bool stillGame(true);
    while(stillGame){
        int n= game->getGamestate();     
        switch(n){
        case 0:
            game->notifyView();
            name=view->inscriptionPlayer(1);
            game->setP1(Player(name,ColorPiece::RED));
            game->setCurrentPlayer(game->getP1());
            game->setGamestate(GameState::INSCRIPTIONPLAYER2);
            break;
        case 1:
            game->notifyView();
            name=view->inscriptionPlayer(2);
            game->setP2(Player(name,ColorPiece::BLUE));
            game->setGamestate(GameState::CONFIGPLAYER1);
            break;
        case 2:
            game->notifyView();
            configurePiecePlacement();
            game->showOrHideAllPiecesOfTheCurrentPlayer(false);
            game->nextPlayer();
            game->setGamestate(GameState::CONFIGPLAYER2);
            break;
        case 3:
            game->notifyView();
            configurePiecePlacement();
            game->showOrHideAllPiecesOfTheCurrentPlayer(false);
            game->nextPlayer();
            game->setGamestate(GameState::INPROCESS);
            game->showOrHideAllPiecesOfTheCurrentPlayer(true);
            game->notifyView();
            break;
        case 4:
            while(game->getGamestate()!=GameState::END){
                bool good(false);
                while(!good){
                    try{
                        Position pieceToMove(AskPieceToMove());
                        game->firstCheckPieceToMove(pieceToMove);
                        Position destinationPiece(AskDestinationPiece());
                        game->firstCheckDestinationPiece(destinationPiece);
                        game->moveCheck(pieceToMove,destinationPiece);
                        game->move(pieceToMove,destinationPiece);
                        good=true;
                    }catch(std::exception &e){
                        view->displayError(e.what());
                    }
                }
                if(game->isFinish()){
                game->setGamestate(GameState::END);
                }else{
                game->showOrHideAllPiecesOfTheCurrentPlayer(false);
                game->nextPlayer();
                game->showOrHideAllPiecesOfTheCurrentPlayer(true);
                }
                game->notifyView();
            }
            break;
        case 6:
            game->nextPlayer();
            stillGame=false;
            break;
        }
    }
}

