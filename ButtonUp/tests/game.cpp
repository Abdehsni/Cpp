#include "catch.hpp"
#include "array.hpp"
#include "game.h"

using model::Player;
using model::Game;

TEST_CASE("Testing Game instanciation"){

     SECTION("Testing construction game"){
        string nameP1{"abde"};
        string nameP2{"Mounir"};
        unsigned ageP1{23};
        unsigned ageP2{43};
        Game game;
        game.realInscription(nameP1,ageP1,nameP2,ageP2);

       REQUIRE(game.getCurrentPlayer().getAge()==43);
       REQUIRE(game.getCurrentPlayer().getScore()==0);
    }




}
