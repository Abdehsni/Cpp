#include "game.h"

namespace model {

Game::Game(){
    tmpScoreP1=0;
    tmpScoreP2=0;
    gameState=GameState::INSCRIPTION;
}

void Game::inscription(const Player& buttonParte,const Player& buttonBourg){
    this->players.push_back(buttonParte);
    this->players.push_back(buttonBourg);
    this->currentPlayer = whoBeginTheGame(buttonParte,buttonBourg);
    notifyAll();
}

const Player &Game::getCurrentPlayer()
{
    return players.at(currentPlayer);
}

bool Game::gameFinished()
{
    return (players[0].getScore()>=15||players[1].getScore()>=15);
}

bool Game::isOneRoundFinished()
{
    return board.allTokenInOneCase();
}

unsigned Game::whoBeginTheGame(const Player& buttonParte,const Player& buttonBourg)
{
    if(buttonParte.getAge() > buttonBourg.getAge()){
        return 0;
    }else{
        return 1;
    }
}

void Game::whoBeginTheRound(bool currentPlayer)
{
    if(!currentPlayer){
        nextPlayer();
    }
}



void Game::whoPlay()
{
    if(this->replay){
        board.resetRulePlay();
        board.getRuleReplay();
    }else{
        nextPlayer();

    }
    
}


void Game::nextPlayer()
{
    if(currentPlayer==0)currentPlayer=1;
    else currentPlayer=0;
}


void Game::move(unsigned indexCase)
{
    if(indexCase>8){
        throw std::out_of_range("invalid index");
    }
    if(board.getCaseAtIndex(indexCase).isEmpty()){
       throw std::invalid_argument("case selected id Empty");
    }
    if(!(board.getCaseAtIndex(indexCase).isWhiteTokenInTheQueue())){
        throw std::invalid_argument("no white token in the case,you cannot play it");
    }else{
        board.moveTokens(indexCase);
        this->replay=board.getRuleReplay();
        if(isOneRoundFinished()){
            setGameEndRound();
        }else{
            whoPlay();

        }

    }    
}


void Game::newGame()
{
    for(Player player:players){
        player.resetScore();
    }
}

void Game::realInscription(std::string &namePlayer1, unsigned &agePlayer1, std::string &namePlayer2, unsigned &agePlayer2)
{
    inscription(Player(namePlayer1,agePlayer1,Color::RED),Player(namePlayer2,agePlayer2,Color::BLACK));
}

GameState &Game::getGameState()
{
    return gameState;
}

void Game::setGameInProcess()
{
    this->gameState=GameState::IN_PROCESS;
}

void Game::setEndGame()
{
    this->gameState=GameState::IS_OVER;

}

void Game::setErrorPlay()
{
    this->gameState=GameState::ERROR_PLAY;
}


Case &Game::getOneCaseOfboard(unsigned index)
{
    return board.getCaseAtIndex(index);
}

std::string Game::getNamefirstPlayer()
{
 return players.at(0).getName();
}

std::string Game::getNameSecondPlayer()
{
    return players.at(1).getName();
}

unsigned Game::getScoreFirstPlayer()
{
   return players.at(0).getScore();
}

unsigned Game::getScoreSecondPlayer()
{
    return players.at(1).getScore();
}

void Game::setGameEndRound()
{
    this->gameState=GameState::END_ROUND;
}


void Game::roundFinished()
{
   unsigned caseToCount =board.indexCaseFull();
   unsigned point=1;
   Case& caseFull= board.getCaseAtIndex(caseToCount);

   while(!caseFull.isEmpty())
   {
       if(caseFull.getFirstToken().isRed()){
            this->tmpScoreP1+=point;
            std::cout<<this->tmpScoreP1<<std::endl;
       }else if(caseFull.getFirstToken().isBlack()){
           this->tmpScoreP2+=point;
       }
       point++;
       caseFull.removeOneToken();
   }

   if(tmpScoreP1>tmpScoreP2){
       addScoreP1((tmpScoreP1-tmpScoreP2));
       player1HasChoiceToReplay=true;
   }else if(tmpScoreP1<tmpScoreP2){
       addScoreP2(((tmpScoreP2-tmpScoreP1)));
       player2HasChoiceToReplay=true;
   }
}

unsigned &Game::getTmpScoreFirstPlayer()
{
    return tmpScoreP1;
}

unsigned &Game::getTmpScoreSecondPlayer()
{
    return tmpScoreP2;
}

void Game::notify()
{
    notifyAll();
}

void Game::moveGui(unsigned index){

    try{
        this->move(index);
    }catch(std::invalid_argument &e){
        setErrorPlay();
        messageError=e.what();
    }
    notifyAll();
}

std::string &Game::getMessageError()
{
    return messageError;
}

bool Game::getP1HasChoiceToReplay()
{
    return player1HasChoiceToReplay;
}

bool Game::getP2HasChoiceToReplay()
{
    return player2HasChoiceToReplay;
}

void Game::setP1NoChoiceToReplay()
{
    player1HasChoiceToReplay=false;
}

void Game::setP2NoChoiceToReplay()
{
    player2HasChoiceToReplay=false;
}

void Game::addScoreP1(unsigned score)
{
    players.at(0).addScore(score);
}

void Game::addScoreP2(unsigned score)
{
    players.at(1).addScore(score);
}

}
