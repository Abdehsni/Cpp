#include "catch.hpp"
#include "Square.h"

using model::Piece;
using model::Position;
using model::ColorPiece;
using model::Flag;
using model::Square;
using model::SquareType;

TEST_CASE("Testing methods of the Square class")
{
    SECTION("Test of method isAccessible false case"){

        Square square {SquareType::WATER};

        REQUIRE_FALSE(square.isAccessible());
    }
    SECTION("Test of method isAccessible true case"){

        Square square {SquareType::LAND};

        REQUIRE(square.isAccessible()==true);
    }
    SECTION("Test of method isEmpty false case"){

        Square square {SquareType::LAND};
        Piece p {10,"10",1,ColorPiece::BLUE};
        square.setPiece(p);

        REQUIRE_FALSE(square.isEmpty());
    }
    SECTION("Test of method isEmpty true case"){

        Square square {SquareType::LAND};

        REQUIRE(square.isEmpty()==true);
    }

    SECTION("Test of method remove"){

        Square square {SquareType::LAND};
        Piece p {10,"10",1,ColorPiece::BLUE};
        square.setPiece(p);
        square.remove();
        REQUIRE(square.isEmpty()==true);
    }


}
