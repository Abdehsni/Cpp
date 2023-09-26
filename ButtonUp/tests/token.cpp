#include "catch.hpp"
#include "array.hpp"
#include <queue>
#include "token.h"
#include "case.h"
#include "Color.h"


using model::Color;
using model::Token;
using model::Case;
using std::queue;


TEST_CASE("Testing Token instanciation"){

    Token tok1(Color::BLACK);
    Token tok2(Color::RED);
    Token tok3(Color::WHITE);

    queue<Token>list;
    Case casee;
    SECTION("testing isempty"){
     REQUIRE(casee.isEmpty());
     REQUIRE(list.empty());
    }





}
