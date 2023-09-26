#include "case.h"



namespace model {


Case::Case()
{
    this->tokens= queue<Token>();
}

queue<Token>& Case::getTokens()
{
    return this->tokens;
}

Token& Case::getFirstToken()
{
    return getTokens().front();
}

Token Case::getLastToken()
{
    queue<Token>tmp=this->tokens;
    while(tmp.size()>1){
        tmp.pop();
    }
    return tmp.front();
}

void Case::addOneToken(Token& token)
{
    this->tokens.push(token);
}


void Case::addToken(Case& origin)
{
    this->tokens.push(origin.getFirstToken());
    origin.removeOneToken();
}

void Case::removeOneToken()
{
    this->tokens.pop();
}


void Case::addTokens(Case& origin){
   while(!origin.isEmpty()){
       this->addToken(origin);
   }
}

bool Case::isEmpty(){
    return this->tokens.empty();
}

bool Case::isWhiteTokenInTheQueue()
{
    bool yes{false};
    queue<Token>copy=tokens;
    int i=copy.size();
    while(i>0){
        if(copy.front().getColor()==Color::WHITE){
            yes=true;
            break;
        }else{
            copy.pop();
            i--;
        }
    }
    return yes;
}

unsigned Case::sizeOfTokensQueue()
{
    return tokens.size();
}


void Case::showQueueTokens()
{
    queue<Token>toDisplay=getTokens();
    std::cout<<"la pile vaut: "<<std::endl;
    while(!toDisplay.empty()){
        std::cout<<toDisplay.front().getColor();
        toDisplay.pop();
    }
   std::cout<<std::endl;
}



}
