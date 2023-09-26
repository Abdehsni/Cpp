#include "catch.hpp"
#include "Piece.h"


using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Flag;


TEST_CASE("Testing methods of the Piece class")
{
    SECTION("Test of method setColor")
    {
        Piece p1 {10,"10",1,ColorPiece::RED};
        p1.setColor(ColorPiece::BLUE);
        REQUIRE(p1.getColor() == ColorPiece::BLUE);
    }

    SECTION("Test of method addPosToHistory 1")
    {
        Piece p1 {10,"10",1,ColorPiece::RED};
        Position position1 {1,2};
        Position position2 {1,3};
        Position position3 {1,4};

        p1.addPosToHistory(position1);
        p1.addPosToHistory(position2);
        p1.addPosToHistory(position3);

        bool samePos=p1.getHistory().back()==position3;

        REQUIRE(samePos==true);


    }
    SECTION("Test of method addPosToHistory 2")
    {
        Piece p1 {10,"10",1,ColorPiece::RED};
        Position position1 {1,2};
        Position position2 {1,3};
        Position position3 {1,4};

        p1.addPosToHistory(position1);
        p1.addPosToHistory(position2);
        p1.addPosToHistory(position3);

        bool samePos=p1.getHistory().back()==position2;

        REQUIRE_FALSE(samePos);


    }
}
