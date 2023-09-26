#include "catch.hpp"
#include "array.hpp"
#include "board.h"
#include "token.h"


using model::Board;
using model::Token;

TEST_CASE("Testing Board instanciation"){

    Board board;
     SECTION("Testing place token random"){
       REQUIRE(board.tokenBoxEmpty());
     }
      board.moveTokens(3);
     SECTION("Testing move one token with index"){
         REQUIRE(board.getCaseAtIndex(3).isEmpty());
         REQUIRE(board.getCaseAtIndex(4).sizeOfTokensQueue()==2);
     }
     board.moveTokens(4);
     SECTION("Testing move with many tokens"){
         REQUIRE(board.getCaseAtIndex(5).sizeOfTokensQueue()==2);
         REQUIRE(board.getRuleReplay()==true);
     }
     board.moveTokens(7);
     board.moveTokens(8);
     SECTION("Testing move tokens at last of the array"){
         REQUIRE(board.getCaseAtIndex(7).isEmpty());
         REQUIRE(board.getCaseAtIndex(8).isEmpty());
         REQUIRE(board.getCaseAtIndex(0).sizeOfTokensQueue()==2);
         REQUIRE(board.getCaseAtIndex(1).sizeOfTokensQueue()==2);
     }



}

