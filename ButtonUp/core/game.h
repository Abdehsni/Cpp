#ifndef GAME_H
#define GAME_H
#include <vector>
#include "observable.h"
#include "gamestate.h"
#include "board.h"
#include "player.h"


using std::vector;

namespace model {

class Game: public observer::Observable{
    Board board;
    vector<Player>players;
    unsigned currentPlayer;
    bool replay{false};
    GameState gameState;
    unsigned tmpScoreP1;
    unsigned tmpScoreP2;
    bool player1HasChoiceToReplay{false};
    bool player2HasChoiceToReplay{false};
    string messageError;
    /* this function let the choice to the currentPlayer to
     * begin or not
     */
    void whoBeginTheRound(bool currentPlayer);
    void whoPlay();
    void inscription(const Player &buttonParte, const Player &buttonBourg);
    unsigned whoBeginTheGame(const Player& buttonParte,const Player& buttonBourg);
    void addScoreP1(unsigned score);
    void addScoreP2(unsigned score);
public:
    Game();  
    const Player& getCurrentPlayer();
    bool gameFinished();
    bool isOneRoundFinished();
    void move(unsigned indexCase);
    void newGame();
    void realInscription(string& namePlayer1,unsigned& agePlayer1,
                         string& namePlayer2,unsigned& agePlayer2);
    GameState& getGameState();
    void setGameInProcess();
    void setEndGame();
    void setErrorPlay();
    Case& getOneCaseOfboard(unsigned index);
    string getNamefirstPlayer();
    string getNameSecondPlayer();
    unsigned getScoreFirstPlayer();
    unsigned getScoreSecondPlayer();
    void setGameEndRound();
    void roundFinished();
    unsigned& getTmpScoreFirstPlayer();
    unsigned& getTmpScoreSecondPlayer();
    void notify();
    void moveGui(unsigned index);
    string& getMessageError();
    bool getP1HasChoiceToReplay();
    bool getP2HasChoiceToReplay();
    void setP1NoChoiceToReplay();
    void setP2NoChoiceToReplay();
    void nextPlayer();
};

}



#endif // GAME_H
