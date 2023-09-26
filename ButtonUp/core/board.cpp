#include "board.h"

using nvs::random_value;

namespace model {

Board::Board(){   
    placeTokenInBoardRandom();
    ruleReplay=false;
}


void Board::placeTokenInBoardRandom()
{
    int indexTabCase=0;
    int max=8;
    while(indexTabCase<9){
        int index = random_value(max,0);
        addTokenToCase(indexTabCase,this->tokenBox[index]);
        this->tokenBox.erase(this->tokenBox.begin()+index);
        max--;
        indexTabCase++;
    }

}


void Board::addTokenToCase(int indexOfCase,Token& token)
{
    this->cases[indexOfCase].addOneToken(token);
}

Case &Board::getCaseAtIndex(int index)
{
    return this->cases[index];
}


bool Board::tokenBoxEmpty()
{
    return this->tokenBox.empty();
}

bool Board::allTokenInOneCase()
{
    bool yes{false};
    for(Case casee:cases){
        if(casee.sizeOfTokensQueue()==9){
            yes=true;
        }
    }
    return yes;
}

bool Board::getRuleReplay()
{
    return ruleReplay;
}


void Board::moveTokens(unsigned index)
{
    unsigned nextQueue=index+1;
    unsigned lastI=0;
    Case& c= getCaseAtIndex(index);
    while(!c.isEmpty()){
        if(nextQueue==9){
            nextQueue=0;
        }
       while(getCaseAtIndex(nextQueue).isEmpty()){
           nextQueue++;
           if(nextQueue==9){
               nextQueue=0;
           }
           if(nextQueue==index){
               break;
           }
       }
       if(c.sizeOfTokensQueue()==1){
           if((nextQueue!=index)&&getCaseAtIndex(nextQueue).getLastToken()==c.getFirstToken()){
               ruleReplay=true;
           }
       }
       if(nextQueue!=index){
           lastI=nextQueue;
           getCaseAtIndex(nextQueue).addToken(c);

           nextQueue++;
       }else if(nextQueue==index){
           getCaseAtIndex(lastI).addTokens(c);
       }
    }

}

void Board::showCasesOfTheBoard()
{
    unsigned i=0;
    for(auto casess : this->cases){
        std::cout<<"Case "<<i<<": ";
        casess.showQueueTokens();
        i++;
    }
}


unsigned Board::indexCaseFull()
{
    unsigned result=0;
    for(unsigned i=0;i<9;i++){
        if(cases.at(i).sizeOfTokensQueue()==9){
            result=i;
            break;
        }
    }
    return result;
}

void Board::resetRulePlay()
{
    this->ruleReplay=false;
}




}
