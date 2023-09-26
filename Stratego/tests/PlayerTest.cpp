#include "catch.hpp"
#include "Player.h"

using model::ColorPiece;
using model::Player;


TEST_CASE("Testing methods of the Player class")
{
    SECTION("Test of operator")
    {
        Player p1 {"abde",ColorPiece::BLUE};
        Player current =p1;

        REQUIRE(p1==current);
    }

}
