#include "catch.hpp"
#include "Position.h"

using model::Position;

TEST_CASE("Testing methods of the Position class")
{
    SECTION("Test of method operator - 1"){

        Position position1 {1,2};
        Position position2 {1,2};
        bool equal = position1-position2;
        REQUIRE(equal==0);
    }
    SECTION("Test of method operator - 2"){

        Position position1 {1,2};
        Position position2 {1,3};
        int equal = position1-position2;
        REQUIRE_FALSE(equal==1);
    }
    SECTION("Test of method operator =="){
        Position position1 {1,2};
        Position position2 {1,2};
        REQUIRE(position1==position2);
    }

    SECTION("Test of method operator !="){
        Position position1 {1,2};
        Position position2 {4,2};
        REQUIRE(position1!=position2);
    }

}
