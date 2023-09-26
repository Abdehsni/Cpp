#include "catch.hpp"
#include "Board.h"

using model::Board;
using model::Piece;
using model::Position;
using model::ColorPiece;

TEST_CASE("Testing methods of the Board class")
{
    Board board = Board();


    SECTION("Test of method getSquareAt and putPieceAt"){
        Piece p = Piece(10,"Ma",1,ColorPiece::BLUE);
        Position pos = Position(2,4);
        board.putPieceAt(p,pos);
        REQUIRE(board.getSquareAt(pos).isEmpty()==false);
    }

    SECTION("Test of method getSquareAt and putPieceAt"){
        Piece p = Piece(10,"Ma",1,ColorPiece::BLUE);
        Position pos = Position(4,6);
        REQUIRE(board.getSquareAt(pos).isEmpty()==true);
    }

    SECTION("Test of method removePiece"){
        Piece p = Piece(10,"Ma",1,ColorPiece::BLUE);
        Position pos = Position(2,4);
        board.removePiece(pos);
        REQUIRE(board.getSquareAt(pos).isEmpty()==true);
    }

    SECTION("Test of method isInside true case"){
        Position pos = Position(2,6);
        REQUIRE(board.isInside(pos)==true);
    }

    SECTION("Test of method isInside false case"){
        Position pos = Position(2,15);
        REQUIRE(board.isInside(pos)==false);
    }



}
