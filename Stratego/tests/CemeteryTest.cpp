#include "catch.hpp"
#include "Cemetery.h"

using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Player;
using model::Cemetery;
using model::Flag;

TEST_CASE("Testing methods of the Cemetery class")
{
   static Cemetery c = Cemetery();

    SECTION("Test of method victime")
    {
        Player p {"Souli",ColorPiece::RED};
        Piece p1 {10,"10",1,ColorPiece::BLUE};
        c.victime(p,p1);
        REQUIRE(c.getNbDeadP1()==10);
    }

    SECTION("Test of method victime")
    {
        Player p {"Souli",ColorPiece::RED};
        Piece p1 {9,"9", 1, ColorPiece::BLUE};
        c.victime(p,p1);
        REQUIRE(c.getNbDeadP1()==19);
    }

    SECTION("Test of method victime")
    {
        Player p {"Souli",ColorPiece::BLUE};
        Piece p1 {9,"9", 1, ColorPiece::RED};
        c.victime(p,p1);
        REQUIRE(c.getNbDeadP2()==9);
    }

    SECTION("Test of method flagFound")
    {
       Cemetery c2 {};
        Flag f {ColorPiece::RED};
       Player p {"Souli",ColorPiece::BLUE};
       c2.victime(p,f);
        REQUIRE(c2.flagFound(p)==true);
    }



}
