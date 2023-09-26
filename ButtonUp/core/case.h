#ifndef CASE_H
#define CASE_H
#include <queue>
#include <iostream>
#include "token.h"

using std::queue;

namespace model{

class Case{

 queue<Token> tokens;

public:

 Case();
 queue<Token>& getTokens();
 Token& getFirstToken();
 Token getLastToken();
 void addOneToken(Token& token);
 void addTokens(Case& origin);
 void addToken(Case& origin);
 void removeOneToken();
 bool isEmpty();
 bool isWhiteTokenInTheQueue();
 unsigned sizeOfTokensQueue();
 void showQueueTokens();

};




}


#endif // CASE_H
