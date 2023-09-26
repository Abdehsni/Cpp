#include "guiview.h"


namespace view {

guiView::guiView(model::Game *game, QWidget *parent) : QWidget(parent),
    i(new InscriptionWindow(game)),
    w(new MainWindow(game)),
    game(game)
{
    game->addObserver(this);
    i->show();
}

guiView::~guiView()
{
    delete i;
    delete w;
    game->removeObserver(this);
}


void guiView::update(const observer::Observable *obs)
{ if(obs==game){

        updateView(game);
    }
}


void guiView::updateView(model::Game *game)
{
    if(game->getGameState()== GameState::INSCRIPTION){
        game->setGameInProcess();
        game->realInscription(i->getNamePlayer1(),i->getAgePlayer1(),
                              i->getNamePlayer2(),i->getAgePlayer2());
        i->close();
        w->show();
        w->displayTabScore();       
    }else if(game->getGameState()==GameState::IN_PROCESS){
        w->displayMessageInProcess();
        w->displayTokens();
        w->displayScore();
        w->setSignals();
        if(game->isOneRoundFinished()){
            game->setGameEndRound();
        }
    }else if(game->getGameState()==GameState::ERROR_PLAY){
        w->displayErrorMessage();
        w->nextAfterError();
    }else if(game->getGameState()==GameState::END_ROUND){
        w->displayTokens();
        game->roundFinished();
        w->displayMessageEndRound();
        w->toContinue();
        game->setGameInProcess();
        w->nextRound();
    }else if(game->getGameState()==GameState::IS_OVER){

    }

}

}
