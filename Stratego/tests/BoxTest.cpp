#include "catch.hpp"
#include "Box.h"

using model::Piece;
using model::Position;
using model::Box;
using model::Player;
using model::Bomb;
using model::ColorPiece;

TEST_CASE("Testing methods of the Box class")
{
    static Box b =Box();

    SECTION("Test of method put 1")
    {
        Player p =Player("Souli",ColorPiece::RED);

        Piece pute{b.put(p,"10")};

        REQUIRE(b.getPiecesP1().size()==39);
    }

    SECTION("Test of method put 2")
    {
        Player p {"Abde",ColorPiece::BLUE};

        Piece piece{b.put(p,"10")};

        REQUIRE(b.getPiecesP2().size()==39);
    }


    SECTION("Test of method pieceAllPut")
    {
        REQUIRE(b.pieceAllPut()==false);
    }
    SECTION("Test of method pieceAllPut")
    {
        b.clearAll();
        REQUIRE(b.pieceAllPut()==true);
    }


}

