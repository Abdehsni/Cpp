#include <iostream>
#include "board.h"

using model::Board;

int main()
{
  Board board;
  board.moveTokens(3);
  board.showCasesOfTheBoard();
  std::cout<<board.getRuleReplay()<<std::endl;
  return 0;
}
