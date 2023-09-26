#include"ConsoleView.h"
#include<unistd.h>

using std::cout;
using std::cin;
using std::endl;
using View::ConsoleView;


ConsoleView::ConsoleView(Game *game):game{game}{
    this->game->addObserver(this);
}


ConsoleView::~ConsoleView(){
    this->game->removeObserver(this);
}


void ConsoleView::update(const observer::Observable *observable){
    if(observable==game){
        if(game->getGamestate()==GameState::INSCRIPTIONPLAYER1){
           cout<<"Joueur 1, inscrivez vous \n";

        }else if(game->getGamestate()==GameState::INSCRIPTIONPLAYER2){
             cout<<"Au joueur 2 de s'inscrire \n";
        }else if(game->getGamestate()==GameState::CONFIGPLAYER1){
           cout<<"-----------Place à la configuration du jeu------- \n"<<endl;
           configMessage();
        }else if(game->getGamestate()==GameState::CONFIGPLAYER2){
           configMessage();
        }else if (game->getGamestate()==GameState::INPROCESS){
            sleep(1);
            cout<<game->getCurrentPlayer().getName()<<", a toi de jouer"<<endl;
            sleep(1);
            cout<<".";
            sleep(1);
            cout<<".";
            sleep(1);
            cout<<"."<<endl;
            this->displayBoard(game->getBoard());
        }else if(game->getGamestate()==GameState::INFIGHT){
            sleep(2);
            cout<<"Bataille !"<<endl;
            this->displayBoard(game->getBoard());
        }else if(game->getGamestate()==GameState::END){
            prepareTheFinalBoardDisplay();
            displayTheWinnerAndShowStat();
            this->displayBoard(game->getBoard());
        }

    }
}


void ConsoleView::intro(){
    cout<<"-----------------Bienvenu au Jeu Stratego-----------------"<<endl;
}

void ConsoleView::displayNumber(int number){
    if(number<10){
        cout<<number<<"  ";
    }else{
        cout<<number<<" ";
    }
}


void ConsoleView::displayBoard(Board board){
    displayLetter();
    horizontalLine();
    for(int n=0;n<10;n++){
        int pos_nb = n+1;
        displayNumber(pos_nb);
        pieceLine(board,n);
        horizontalLine();
    }
    displayLetter();
}




void ConsoleView::displayLetter(){
    cout<<"     A   B   C   D   E   F   G   H   I   J  "<<endl;
}


void ConsoleView::horizontalLine(){
    cout<<"   -----------------------------------------"<<endl;
}

string ConsoleView::pieceSymbol(Piece piece){
    if(piece.getIsHidden()){
        if(piece.getColor()==ColorPiece::BLUE){
            return "Z";
        }
        else{

            return "R";
        }
    }else{
        return piece.getSymbol();
    }
}



void ConsoleView::pieceLine(Board board, int row){

    for(int column=0;column<10;column++){

        if(board.getSquareAt(row,column).getSquareType()==SquareType::WATER){
            if(column==9){
                cout<<"|XXX|";
            }else{
                cout<<"|XXX";
            }
        }else if(board.getSquareAt(row,column).isEmpty()){
            if(column==9){
                cout<<"|   |";
            }else{
                cout<<"|   ";
            }
        }else{
            const Piece& p = board.getPieceAt(row,column);
            if(column==9){
                if(pieceSymbol(p)=="10")cout<<"| "<<pieceSymbol(p)<<"|";
                else cout<<"| "<<pieceSymbol(p)<<" |";
            }else{
                if(pieceSymbol(p)=="10")cout<<"| "<<pieceSymbol(p)<<"";
                else cout<<"| "<<pieceSymbol(p)<<" ";
            }
        }
    }
    cout<<endl;

}


void ConsoleView::displayNameSymbol(){
    cout<<"_______________________"<<endl;
    cout<<"| Piece       |Symbole|"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"| Marechal    |   10  |"<<endl;
    cout<<"| General     |    9  |"<<endl;
    cout<<"| Colonel     |    8  |"<<endl;
    cout<<"| Major       |    7  |"<<endl;
    cout<<"| Commandant  |    6  |"<<endl;
    cout<<"| Lieutenant  |    5  |"<<endl;
    cout<<"| Sergent     |    4  |"<<endl;
    cout<<"| Demineur    |    3  |"<<endl;
    cout<<"| Eclaireur   |    2  |"<<endl;
    cout<<"| Espionne    |    1  |"<<endl;
    cout<<"| Drapeau     |    D  |"<<endl;
    cout<<"| Bombe       |    B  |"<<endl;
    cout<<"-----------------------"<<endl;

}


void ConsoleView::displayBoxP1(const Box& box){
    int size= box.getPiecesP1().size();
    auto piecesBoxP1=box.getPiecesP1();

    for(int i=0;i<size;i++){
        int k= i+1;
        if(k%9==0){
            cout<<"| "<<piecesBoxP1.at(i).getSymbol()<<" |"<<endl;
        }else{

            cout<<"| "<<piecesBoxP1.at(i).getSymbol()<<" ";
        }

    }
    cout<<endl;
}

void ConsoleView::displayBoxP2(const Box& box){
    int size= box.getPiecesP2().size();
    auto piecesBoxP2=box.getPiecesP2();

    for(int i=0;i<size;i++){
        int k= i+1;
        if(k%9==0){
            cout<<"| "<<piecesBoxP2.at(i).getSymbol()<<" |"<<endl;
        }else{
            cout<<"| "<<piecesBoxP2.at(i).getSymbol()<<" ";
        }

    }
    cout<<endl;
}


void ConsoleView::displayBox(const Box& box,const Player& p){
    if(p.getColorPiece()==ColorPiece::RED){
        displayNameSymbol();
        cout<<p.getName()<<" ,vos pions a placer :"<<endl;
        displayBoxP1(box);
    }else{
        displayNameSymbol();
        cout<<p.getName()<<" ,vos pions a placer :"<<endl;
        displayBoxP2(box);
    }

}


void ConsoleView::displayError(string message){
    cout<<message<<endl;
}


void ConsoleView::prepareTheBoardDisplay(){
    game->showOrHideAllPiecesOfTheCurrentPlayer(true);
    game->nextPlayer();
    game->showOrHideAllPiecesOfTheCurrentPlayer(false);
    game->nextPlayer();
}



void ConsoleView::prepareTheFinalBoardDisplay(){
    game->showOrHideAllPiecesOfTheCurrentPlayer(true);
    game->nextPlayer();
    game->showOrHideAllPiecesOfTheCurrentPlayer(true);
    game->nextPlayer();

}



void ConsoleView::displayTheWinnerAndShowStat(){
    cout<<"---------------------------------------"<<endl;
    cout<<"Le gagnant est "<<game->getCurrentPlayer().getName()<<" en ";
    if(game->wonByCapturingTheFlag()){
        cout<<"capturant le drapeau"<<endl;
    }else{
        cout<<"massacrant tous les pions adverses"<<endl;
    }
}




string ConsoleView::inscriptionPlayer(int n){
    string nom;
    cout<<"Joueur "<<n<<",entrez votre nom (Vos pions sont rouges) : ";
    cin>>nom;
    return nom;
}


bool ConsoleView::AskFileDisposition(){
    string answer;
    while(answer!="Y"&&answer!="N"){
        answer="";
        cout<<"Voulez-vous charger un fichier de configuration de vos pieces sur le plateau?(Y/N): ";
        cin>>answer;
    }
    if(answer=="Y")return true;
    else return false;

}


string ConsoleView::askPathForFileDisposition(){
    string path;
    cout<<"Entrez le chemin absolu menant au fichier de configuration de vos pions : "<<endl;
    cin>>path;
    return path;
}


void ConsoleView::configMessage(){
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<"."<<endl;
    cout<<game->getCurrentPlayer().getName()<<", a toi d'etablir ta configuration :"<<endl;
    sleep(2);
}

void ConsoleView::initWithFileSuccesMessage(){
    cout<<"Initialisation de votre jeu via fichier reussi!!!\n";
}
