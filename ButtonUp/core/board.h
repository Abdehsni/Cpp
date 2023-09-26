#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <array>
#include "random.hpp"
#include "case.h"
#include "token.h"

using std::vector;
using std::array;

namespace model {

class Board{

 vector<Token>tokenBox{Token(Color::BLACK),Token(Color::RED),Token(Color::WHITE),
                        Token(Color::BLACK),Token(Color::RED),Token(Color::WHITE),
                         Token(Color::BLACK),Token(Color::RED),Token(Color::WHITE)};
 array<Case,9>cases;
 bool ruleReplay;

 void placeTokenInBoardRandom();

public:
 Board();
 void addTokenToCase(int indexOfCase,Token& token);
 Case& getCaseAtIndex(int index);
 bool tokenBoxEmpty();
 bool allTokenInOneCase();
 bool getRuleReplay();
 void moveTokens(unsigned index);
 void showCasesOfTheBoard();  //methode qui sert juste à tester les mouvements a supprimer
 unsigned indexCaseFull();
 void resetRulePlay();
};

}
























#endif // BOARD_H
