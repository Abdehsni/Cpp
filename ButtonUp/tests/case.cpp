#include "catch.hpp"
#include "array.hpp"
#include "case.h"
#include "Color.h"
#include "token.h"

using model::Case;
using model::Color;
using model::Token;

TEST_CASE("Testing Case instanciation"){

    Case oneCase;
    Token one_token(Color::BLACK);
    oneCase.addOneToken(one_token);


    SECTION("Testing Case with one token"){
        REQUIRE(oneCase.getFirstToken().getColor() == Color::BLACK);
    }
    oneCase.removeOneToken();
    SECTION("Testing Remove one token"){   
        REQUIRE(oneCase.isEmpty()==true);
    }
    SECTION("Testing Case with list of tokens"){
        Token token1(Color::WHITE);
        Token token2(Color::BLACK);
        Token token3(Color::RED);
        oneCase.addOneToken(token1);
        oneCase.addOneToken(token2);
        oneCase.addOneToken(token3);
        REQUIRE(oneCase.getFirstToken().getColor()==Color::WHITE);
    }
    SECTION("Testing to get the last element of a queue"){
        Token token1(Color::WHITE);
        Token token2(Color::BLACK);
        Token token3(Color::RED);
        oneCase.addOneToken(token1);
        oneCase.addOneToken(token2);
        oneCase.addOneToken(token3);
        Token result = oneCase.getLastToken();
        REQUIRE(result.getColor()==Color::RED);
        REQUIRE(oneCase.isWhiteTokenInTheQueue());
    }

    SECTION("TEST ISWHITE IN THE QUEUE"){
        REQUIRE(!oneCase.isWhiteTokenInTheQueue());
    }

}
