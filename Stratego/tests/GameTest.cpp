#include "catch.hpp"
#include "Game.h"

using model::Board;
using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Player;
using model::Cemetery;
using model::Flag;
using model::Game;
using model::Bomb;

TEST_CASE("Testing methods of the Game class")
{
    Game game = Game();

    SECTION("Test of method sameSide 1")
    {
        Piece p1 =Piece(10,"Ma", 1, ColorPiece::RED);
        Piece p2 = Piece(7,"Mj", 1, ColorPiece::RED);

        REQUIRE(game.isSameSide(p1,p2)==true);

    }

    SECTION("Test of method sameSide 2")
    {
        Piece p1 =Piece(10,"Ma", 1, ColorPiece::RED);
        Piece p2 = Piece(7,"Mj", 1, ColorPiece::BLUE);

        REQUIRE(game.isSameSide(p1,p2)==false);

    }
    SECTION("Test of method isFinish 1")
    {
        Piece flag = Flag(ColorPiece::BLUE);

        game.burriedPiece(game.getCurrentPlayer(),flag);

        REQUIRE(game.isFinish()==true);
    }

    SECTION("Test of method isFinish 2")
    {
        game.nextPlayer();

        Piece flag = Flag(ColorPiece::BLUE);
        game.burriedPiece(game.getCurrentPlayer(),flag);

        REQUIRE(game.isFinish()==true);
    }


    SECTION("Test of method isFinish 3")
    {        Piece flag = Flag(ColorPiece::RED);


             game.set148(148);

                  REQUIRE(game.isFinish()==true);
    }





    SECTION("Test of method correctPositionSelected 1")
    {
        Position posInit = Position(1,4);

        REQUIRE(game.correctPositionSelected(posInit)==true);
    }


    SECTION("Test of method putPieceOnBoard 1")
    {
        Piece flag = Flag(ColorPiece::BLUE);
        Position posInit = Position(1,4);

        game.putPieceOnBoard(flag,posInit);
        REQUIRE(game.getBoard().getSquareAt(posInit.row,posInit.column).getPiece().getRank()==1000);
    }

    SECTION("Test of method pieceIn 1")
    {
        Piece flag = Flag(ColorPiece::BLUE);
        Position posInit = Position(1,4);

        game.putPieceOnBoard(flag,posInit);

        REQUIRE(game.getBoard().getSquareAt(posInit).getPiece().getRank()==1000);
    }

    SECTION("Test of method newPosition 1 case posFinal is empty")
    {
        Piece flag = Flag(ColorPiece::RED);
        Position posInit = Position(1,4);
        Position posFin = Position(2,4);

        game.putPieceOnBoard(flag,posInit);
        game.newPosition(posInit,posFin);

        REQUIRE(game.getBoard().getSquareAt(posFin).getPiece().getRank()==1000);
    }

    SECTION("Test of method newPosition 2 case battle ,the piece attack win")
    {
        //tester attak mm camp , mm rank, inf , bomb , cimetiere,histori(debug)
        Piece pieceAtk =Piece(10,"Ma", 1, ColorPiece::RED);
        Piece pieceDef =Piece(9,"P", 1, ColorPiece::BLUE);
        Position posInit = Position(1,4);
        Position posFin = Position(2,4);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.putPieceOnBoard(pieceDef,posFin);

        game.newPosition(posInit,posFin);

        REQUIRE(game.getBoard().getSquareAt(posFin).getPiece().getRank()==10);
    }


    SECTION("Test of method newPosition 3 case battle ,the piece attack lose")
    {
        //tester attak mm camp , mm rank, inf  bomb , cimetiere,histori(debug)
        Piece pieceAtk =Piece(9,"E", 1, ColorPiece::BLUE);
        Piece pieceDef =Piece(10,"Ma", 1, ColorPiece::RED);
        Position posInit = Position(1,4);
        Position posFin = Position(2,4);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.putPieceOnBoard(pieceDef,posFin);
        game.newPosition(posInit,posFin);

        REQUIRE(game.getBoard().getSquareAt(posFin).getPiece().getRank()==10);
    }
    SECTION("Test of method battle 1 case with the bomb and the scout ")
    {
        Piece de = Piece(3,"De", 1, ColorPiece::RED);
        Piece bomb = Bomb(ColorPiece::BLUE);

        game.battle(de,bomb);

        REQUIRE(game.battle(de,bomb)==de);
    }
    SECTION("Test of method battle 2 case with the bomb and another piece ")
    {
        Piece ma =Piece(10,"Ma", 1, ColorPiece::RED);
        Piece bomb = Bomb(ColorPiece::BLUE);

        game.battle(ma,bomb);

        REQUIRE(game.battle(ma,bomb)==bomb);
    }
    SECTION("Test of method battle 3 case with the espion and the marechal ")
    {
        Piece ma =Piece(10,"Ma", 1, ColorPiece::RED);
        Piece sc = Piece(1,"Es", 1, ColorPiece::BLUE);

        game.battle(sc,ma);

        REQUIRE(game.battle(sc,ma)==sc);

    }
    SECTION("Test of method battle 4 case a piece with another piece ")
    {
        Piece pieceAtk =Piece(9,"E", 1, ColorPiece::BLUE);
        Piece pieceDef =Piece(10,"10", 1, ColorPiece::RED);

        game.battle(pieceAtk,pieceDef);

        REQUIRE(game.battle(pieceAtk,pieceDef)==pieceDef);
    }

    SECTION("Test of method moveCheck 1 case the initial position is not in the board ")
    {
        Piece pieceAtk =Piece(9,"E", 1, ColorPiece::BLUE);
        Piece pieceDef =Piece(10,"Ma", 1, ColorPiece::RED);
        Position posInit = Position(11,4);
        Position posFin = Position(2,4);

        REQUIRE_THROWS(game.moveCheck(posInit,posFin));
    }

    SECTION("Test of method moveCheck 2 case the initial position is empty")
    {
        Piece pieceAtk =Piece(9,"E", 1, ColorPiece::BLUE);
        Piece pieceDef =Piece(10,"Ma", 1, ColorPiece::RED);
        Position posInit = Position(1,4);
        Position posFin = Position(2,4);

        REQUIRE_THROWS(game.moveCheck(posInit,posFin));
    }

    SECTION("Test of method moveCheck 3 case the final position is not in the board")
    {
        Piece pieceAtk =Piece(9,"E", 1, ColorPiece::BLUE);
        Piece pieceDef =Piece(10,"10", 1, ColorPiece::RED);
        Position posInit = Position(1,4);
        Position posFin = Position(12,4);

        REQUIRE_THROWS(game.moveCheck(posInit,posFin));
    }

    SECTION("Test of method moveCheck 4 case isSameSide")
    {
        Piece pieceAtk =Piece(1,"E", 9, ColorPiece::BLUE);
        Piece pieceDef =Piece(10,"10", 1, ColorPiece::BLUE);
        Position posInit = Position(1,4);
        Position posFin = Position(2,4);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.putPieceOnBoard(pieceDef,posFin);

        REQUIRE_THROWS(game.moveCheck(posInit,posFin));
    }



    SECTION("Test of method move 1 case 1 failed attack  ")
    {
        Piece pieceAtk =Piece(3,"De", 1, ColorPiece::RED);
        Piece pieceDef =Piece(10,"10", 1, ColorPiece::BLUE);

        Position posInit = Position(1,4);
        Position posFin = Position(2,4);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.putPieceOnBoard(pieceDef,posFin);
        game.move(posInit,posFin);

        REQUIRE(game.getBoard().getSquareAt(posFin).getPiece().getRank()==10);
    }

    SECTION("Test of method move 2 case 9 move the scout  ")
    {
        Piece pieceAtk =Piece(2,"E", 9, ColorPiece::RED);
        Piece pieceDef  =Piece(10,"Ma", 1, ColorPiece::BLUE);

        Position posInit = Position(1,2);
        Position posFin = Position(1,5);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.putPieceOnBoard(pieceDef,posFin);
        game.move(posInit,posFin);

        REQUIRE(game.getBoard().getSquareAt(posFin).getPiece().getRank()==10);
    }

    SECTION("Test of method move 3 case 9 cannot move the scout through water ")
    {
        Piece pieceAtk =Piece(2,"E", 9, ColorPiece::RED);
        Position posInit = Position(3,3);
        Position posFin = Position(7,3);

        game.putPieceOnBoard(pieceAtk,posInit);

        REQUIRE_THROWS(game.move(posInit,posFin));
    }

    SECTION("Test of method move 3 case 9 cannot move the scout through a piece ")
    {
        Piece pieceAtk =Piece(2,"E", 9, ColorPiece::RED);
        Piece pieceDef  =Piece(10,"Ma", 1, ColorPiece::BLUE);

        Position posInit = Position(3,2);
        Position posInter = Position(5,2);
        Position posFin = Position(6,2);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.putPieceOnBoard(pieceDef,posInter);

        REQUIRE_THROWS(game.move(posInit,posFin));
    }

    SECTION("Test of method move 4 case 9 move 7 squares ")
    {
        Piece pieceAtk =Piece(2,"E", 9, ColorPiece::RED);
        Position posInit = Position(0,0);
        Position posFin = Position(0,7);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.move(posInit,posFin);
        REQUIRE(game.getBoard().getSquareAt(posFin).getPiece().getRank()==2);
    }

    SECTION("Test of method move 5 case 9 move 5 squares ")
    {
        Piece pieceAtk =Piece(2,"E", 9, ColorPiece::RED);
        Position posInit = Position(0,0);
        Position posFin = Position(5,0);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.move(posInit,posFin);
        REQUIRE(game.getBoard().getSquareAt(posFin).getPiece().getRank()==2);
    }
    SECTION("Test of method move 6 case can't move the piece")
    {
        Piece pieceAtk = Bomb(ColorPiece::BLUE);
        Piece pieceDef =Piece(10,"10", 1, ColorPiece::RED);
        Position posInit = Position(1,4);
        Position posFin = Position(2,4);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.putPieceOnBoard(pieceDef,posFin);

        REQUIRE_THROWS(game.move(posInit,posFin));
    }
    SECTION("Test of method move 7 case  can't move the piece")
    {
        Piece pieceAtk  = Flag(ColorPiece::RED);
        Piece pieceDef =Piece(10,"10", 1, ColorPiece::BLUE);
        Position posInit = Position(1,4);
        Position posFin = Position(2,4);

        game.putPieceOnBoard(pieceAtk,posInit);
        game.putPieceOnBoard(pieceDef,posFin);

        REQUIRE_THROWS(game.move(posInit,posFin));
    }



    SECTION("Test of method checkRepeatMove 1")
    {
        Piece piece =Piece(10,"Ma", 1, ColorPiece::RED);
        Position pos1 = Position(1,4);
        Position pos2 = Position(1,3);
        game.setActualPos(pos2);
        piece.addPosToHistory(pos2);
        piece.addPosToHistory(pos1);
        piece.addPosToHistory(pos2);
        piece.addPosToHistory(pos1);
        piece.addPosToHistory(pos2);

        piece.addPosToHistory(pos1);
        piece.addPosToHistory(pos2);

        piece.addPosToHistory(pos1);
        piece.addPosToHistory(pos2);

        piece.addPosToHistory(pos1);
        piece.addPosToHistory(pos2);

        REQUIRE(game.checkRepeatMove(pos1,piece)==true);
    }
    /*
    SECTION("Test of method moveCheck 1")
        {
            Piece piece =Piece(10,"Ma", 1, ColorPiece::RED, 50001);
            Position pos1 = Position(1,4);
            Position pos2 = Position(1,3);
            game.putPieceOnBoard(piece,pos1);

            game.move(pos1,pos2);
            game.move(pos2,pos1);

            game.move(pos1,pos2);
            game.move(pos2,pos1);

            game.move(pos1,pos2);
            game.move(pos2,pos1);



            REQUIRE_THROWS(game.moveCheck(pos2,pos1));
        }
*/




}

























