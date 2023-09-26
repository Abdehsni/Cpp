#include <catch2/catch_test_macros.hpp>
#include "board.h"


TEST_CASE( "Testing_Board") {

    int length=10;
    int width=10;
    model::GameObject baba("baba 5 5 ");
    std::multimap<model::Coordinate,model::GameObject>cases={std::pair{model::Coordinate(5,5),baba}};
    std::map<model::Elements, model::Elements> rules={std::pair{model::Elements::BABA,model::Elements::YOU}};
    model::Board board(cases,rules,length,width,false,false);

    SECTION("board basic move"){

        board.moveGameObjects(model::Direction::NORTH);
        REQUIRE(board.getCases().find(model::Coordinate(5,4))!=board.getCases().end());
        board.moveGameObjects(model::Direction::NORTH);
        REQUIRE(board.isBlocked());
    }


}

TEST_CASE("Testin_win_North_flag_board"){
    int length=10;
    int width=10;
    model::GameObject baba("baba 5 6 ");
    model::GameObject flag("flag 5 5 ");
    model::GameObject txtflg("text_flag 7 7 ");
    model::GameObject is("is 8 7 ");
    model::GameObject win("win 8 7 ");
    model::GameObject txtBaba("text_baba 7 8 ");
    model::GameObject is2("is 8 8 ");
    model::GameObject you("you 9 8 ");

    std::multimap<model::Coordinate, model::GameObject> cases ={
        std::pair{baba.getCoordinate(), baba},
        std::pair{flag.getCoordinate(), flag},

        std::pair{txtflg.getCoordinate(),txtflg},
        std::pair{is.getCoordinate(),is},
        std::pair{win.getCoordinate(),win},

        std::pair{txtBaba.getCoordinate(),txtBaba},
        std::pair{is2.getCoordinate(),is2},
        std::pair{you.getCoordinate(),you},

    };
    std::map<model::Elements, model::Elements> rules = {
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::FLAG, model::Elements::WIN}
    };
    model::Board board(cases, rules, length, width, false, false);

    SECTION("board win condition") {

        REQUIRE_FALSE(board.isWin());

        board.moveGameObjects(model::Direction::NORTH);

        REQUIRE(board.isWin());
    }
}


TEST_CASE("Testin_win_SOUTH_flag_board"){

    int length=10;
    int width=10;

    model::GameObject baba("baba 5 5 ");
    model::GameObject flag("flag 5 6 ");
    model::GameObject txtflg("text_flag 7 7 ");
    model::GameObject is("is 8 7 ");
    model::GameObject win("win 8 7 ");
    model::GameObject txtBaba("text_baba 7 8 ");
    model::GameObject is2("is 8 8 ");
    model::GameObject you("you 9 8 ");

    std::multimap<model::Coordinate, model::GameObject> cases = {
      std::pair{baba.getCoordinate(),baba},
      std::pair{flag.getCoordinate(),flag}
    };
    std::map<model::Elements, model::Elements> rules = {
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::FLAG, model::Elements::WIN}
    };

    model::Board board(cases, rules, length, width, false, false);

    SECTION("board win condition") {

        REQUIRE_FALSE(board.isWin());

        board.moveGameObjects(model::Direction::SOUTH);

        REQUIRE(board.isWin());
    }


}

TEST_CASE("Testing_win_EAST_flag_board"){
    int length=10;
    int width=10;
    model::GameObject baba("baba 5 5 ");
    model::GameObject flag("flag 6 5 ");
    model::GameObject txtflg("text_flag 7 7 ");
    model::GameObject is("is 8 7 ");
    model::GameObject win("win 8 7 ");
    model::GameObject txtBaba("text_baba 7 8 ");
    model::GameObject is2("is 8 8 ");
    model::GameObject you("you 9 8 ");

    std::multimap<model::Coordinate, model::GameObject> cases = {
        std::pair{baba.getCoordinate(), baba},
        std::pair{flag.getCoordinate(), flag}
    };
    std::map<model::Elements, model::Elements> rules = {
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::FLAG, model::Elements::WIN}
    };
    model::Board board(cases, rules, length, width, false, false);

    SECTION("board win condition") {

        REQUIRE_FALSE(board.isWin());

        board.moveGameObjects(model::Direction::EAST);

        REQUIRE(board.isWin());
    }
}


TEST_CASE("Testing_win_WEST_flag_board"){
    int length=10;
    int width=10;
    model::GameObject baba("baba 5 5 ");
    model::GameObject flag("flag 4 5 ");
    model::GameObject txtflg("text_flag 7 7 ");
    model::GameObject is("is 8 7 ");
    model::GameObject win("win 9 7 ");
    model::GameObject txtBaba("text_baba 7 8 ");
    model::GameObject is2("is 8 8 ");
    model::GameObject you("you 9 8 ");

    std::multimap<model::Coordinate, model::GameObject> cases = {
        std::pair{baba.getCoordinate(), baba},
        std::pair{flag.getCoordinate(), flag}
    };
    std::map<model::Elements, model::Elements> rules = {
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::FLAG, model::Elements::WIN}
    };
    model::Board board(cases, rules, length, width, false, false);

    SECTION("board win condition") {

        REQUIRE_FALSE(board.isWin());

        board.moveGameObjects(model::Direction::WEST);

        REQUIRE(board.isWin());
    }
}



TEST_CASE("Testing_Board_Borders") {
    int length=10;
    int width=10;
    model::GameObject baba("baba 5 9 ");
    std::multimap<model::Coordinate,model::GameObject>cases={std::pair{baba.getCoordinate(),baba}};
    std::map<model::Elements, model::Elements> rules={std::pair{model::Elements::BABA,model::Elements::YOU}};
    model::Board board(cases,rules,length,width,false,false);

    SECTION("board move beyond north border") {
        board.moveGameObjects(model::Direction::NORTH);
        REQUIRE(board.getCases().find(model::Coordinate(5,9)) == board.getCases().end());
    }
     rules={std::pair{model::Elements::BABA,model::Elements::YOU}};

    SECTION("board move beyond south border") {
        board.moveGameObjects(model::Direction::SOUTH);
        REQUIRE(board.getCases().find(model::Coordinate(5,9)) != board.getCases().end());
    }
     rules={std::pair{model::Elements::BABA,model::Elements::YOU}};

    SECTION("board move beyond east border") {
        board.moveGameObjects(model::Direction::EAST);
        REQUIRE(board.getCases().find(model::Coordinate(6,9))->second.getElement()==model::Elements::BABA);
    }
     rules={std::pair{model::Elements::BABA,model::Elements::YOU}};
    SECTION("board move beyond west border") {
        board.moveGameObjects(model::Direction::WEST);
        REQUIRE(board.getCases().find(model::Coordinate(4,9))->second.getElement()==model::Elements::BABA);
    }

}


TEST_CASE("Testing kill") {
    int length=10;
    int width=10;
    model::GameObject baba("baba 5 5 ");
    model::GameObject water("water 5 4 ");
    std::multimap<model::Coordinate, model::GameObject>cases={
        std::pair{baba.getCoordinate(), baba},
        std::pair{water.getCoordinate(), water}
    };

    std::map<model::Elements, model::Elements>rules={
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::WATER, model::Elements::KILL}
    };

    model::Board board(cases, rules, length, width, false, false);

    SECTION ("test Baba dies in water "){
        board.moveGameObjects(model::Direction::NORTH);
        REQUIRE(board.isBlocked() == true);
    }
}


TEST_CASE("Testing sink") {
    int length=10;
    int width=10;
    model::GameObject baba("baba 5 5 ");
    model::GameObject water("water 5 4 ");
    std::multimap<model::Coordinate, model::GameObject>cases={
        std::pair{baba.getCoordinate(), baba},
        std::pair{water.getCoordinate(), water}
    };

    std::map<model::Elements, model::Elements>rules={
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::WATER, model::Elements::SINK}
    };

    model::Board board(cases, rules, length, width, false, false);

    SECTION ("test Baba dies in water "){
        board.moveGameObjects(model::Direction::NORTH);
        REQUIRE(board.getCases().find(model::Coordinate(5,4))==board.getCases().end());
    }
}


TEST_CASE("Testing Stop") {
    int length=10;
    int width=10;
    model::GameObject baba("baba 5 5 ");
    model::GameObject water("water 5 4 ");
    std::multimap<model::Coordinate, model::GameObject>cases={
        std::pair{baba.getCoordinate(), baba},
        std::pair{water.getCoordinate(), water}
    };

    std::map<model::Elements, model::Elements>rules={
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::WATER, model::Elements::STOP}
    };

    model::Board board(cases, rules, length, width, false, false);

    SECTION ("test Baba dies in water "){
        board.moveGameObjects(model::Direction::NORTH);
        REQUIRE(board.getCases().find(model::Coordinate(5,5))->second.getElement()==model::Elements::BABA);
    }
}

TEST_CASE("Testing updateRules") {
    int length=10;
    int width=10;
    model::GameObject baba("baba 5 5 ");
    model::GameObject water("water 5 4 ");
    model::GameObject flag("flag 4 5 ");
    model::GameObject txtflg("text_flag 7 7 ");
    model::GameObject is("is 8 7 ");
    model::GameObject win("win 9 7 ");
    model::GameObject txtBaba("text_baba 8 6 ");
    model::GameObject you("you 8 8 ");

    std::multimap<model::Coordinate, model::GameObject>cases={
        std::pair{baba.getCoordinate(), baba},
        std::pair{water.getCoordinate(), water},
        std::pair{flag.getCoordinate(),flag},
        std::pair{txtflg.getCoordinate(),txtflg},
        std::pair{is.getCoordinate(),is},
        std::pair{win.getCoordinate(),win},
        std::pair{txtBaba.getCoordinate(),txtBaba},
        std::pair{you.getCoordinate(),you}
    };

    std::map<model::Elements, model::Elements>rules={
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::WATER, model::Elements::STOP}
    };

    model::Board board(cases, rules, length, width, false, false);

    SECTION ("test updateRules() "){
        board.moveGameObjects(model::Direction::NORTH);
        REQUIRE(board.countNbRules()==2);
    }
}


TEST_CASE("Testing move with same gameobjects") {
    int length=10;
    int width=10;
    model::GameObject rock("rock 5 5 ");
    model::GameObject rock2("rock 5 4 ");
    model::GameObject rock3("rock 4 5 ");
    model::GameObject rock4("rock 7 7 ");
    model::GameObject is("is 8 8 ");
    model::GameObject txtRock("text_rock 7 8 ");
    model::GameObject you("you 9 8 ");

    std::multimap<model::Coordinate, model::GameObject>cases={
        std::pair{rock.getCoordinate(), rock},
        std::pair{rock2.getCoordinate(), rock2},
        std::pair{rock3.getCoordinate(),rock3},
        std::pair{rock4.getCoordinate(),rock4},
        std::pair{is.getCoordinate(),is},
        std::pair{txtRock.getCoordinate(),txtRock},
        std::pair{you.getCoordinate(),you}
    };

    std::map<model::Elements, model::Elements>rules={
        std::pair{model::Elements::ROCK, model::Elements::YOU}
    };

    model::Board board(cases, rules, length, width, false, false);

    SECTION ("test move"){
        board.moveGameObjects(model::Direction::NORTH);
        REQUIRE(board.getCases().find(model::Coordinate(5,4))->second.getElement()==model::Elements::ROCK);
        REQUIRE(board.getCases().find(model::Coordinate(5,3))->second.getElement()==model::Elements::ROCK);
        REQUIRE(board.getCases().find(model::Coordinate(4,4))->second.getElement()==model::Elements::ROCK);
        REQUIRE(board.getCases().find(model::Coordinate(7,6))->second.getElement()==model::Elements::ROCK);

    }
}



TEST_CASE("Test Push") {
    int length=10;
    int width=10;

    model::GameObject baba("baba 6 5 ");
    model::GameObject rock("rock 7 5 ");
    model::GameObject rock2("rock 8 5 ");
    model::GameObject rock3("rock 9 5 ");
    model::GameObject is("is 8 8 ");
    model::GameObject txtRock("text_rock 7 8 ");
    model::GameObject push("push 9 8 ");
    model::GameObject txtBaba("text_baba 8 7 ");
    model::GameObject you("you 8 9 ");

    std::multimap<model::Coordinate, model::GameObject>cases={
        std::pair{rock.getCoordinate(), rock},
        std::pair{rock2.getCoordinate(), rock2},
        std::pair{rock3.getCoordinate(),rock3},
        std::pair{baba.getCoordinate(),baba},
        std::pair{is.getCoordinate(),is},
        std::pair{txtRock.getCoordinate(),txtRock},
        std::pair{you.getCoordinate(),you},
        std::pair{push.getCoordinate(),push},
        std::pair{txtBaba.getCoordinate(),txtBaba},
    };

    std::map<model::Elements, model::Elements>rules={
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::ROCK,model::Elements::PUSH}
    };

    model::Board board(cases, rules, length, width, false, false);

    SECTION ("test move and push"){
        board.moveGameObjects(model::Direction::EAST);
        REQUIRE(board.getCases().find(model::Coordinate(9,5))->second.getElement()==model::Elements::ROCK);
        REQUIRE(board.getCases().find(model::Coordinate(6,5))->second.getElement()==model::Elements::BABA);
    }
}




TEST_CASE("Test Push with sink") {
    int length=10;
    int width=10;

    model::GameObject baba("baba 6 5 ");
    model::GameObject rock("rock 7 5 ");
    model::GameObject water("water 8 5 ");
        std::multimap<model::Coordinate, model::GameObject>cases={
                                                                     std::pair{rock.getCoordinate(), rock},
                                                                     std::pair{baba.getCoordinate(),baba},
                                                                     std::pair{water.getCoordinate(),water},
                                                                     };

        std::map<model::Elements, model::Elements>rules={
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::ROCK,model::Elements::PUSH},
        std::pair{model::Elements::WATER,model::Elements::SINK}
    };

    model::Board board(cases, rules, length, width, false, false);

    SECTION ("test move and push and sink"){
        board.moveGameObjects(model::Direction::EAST);
        REQUIRE(board.getCases().find(model::Coordinate(7,5))->second.getElement()==model::Elements::BABA);
    }
}


TEST_CASE("Test Push with kill") {
    int length=10;
    int width=10;

    model::GameObject baba("baba 6 5 ");
    model::GameObject rock("rock 7 5 ");
    model::GameObject water("water 8 5 ");

    model::GameObject txtRock("text_rock 7 8 ");
    model::GameObject is("is 8 8 ");
    model::GameObject push("push 9 8 ");

    model::GameObject txtBaba("text_baba 1 1 ");
    model::GameObject is2("is 2 1 ");
    model::GameObject you("you 3 1 ");

    model::GameObject txtWater("text_water 1 2 ");
    model::GameObject is3("is 2 2 ");
    model::GameObject kill("kill 3 2");


        std::multimap<model::Coordinate, model::GameObject>cases={
        std::pair{rock.getCoordinate(), rock},
        std::pair{baba.getCoordinate(),baba},
        std::pair{water.getCoordinate(),water},
        std::pair{txtRock.getCoordinate(),txtRock},
        std::pair{is.getCoordinate(),is},
        std::pair{push.getCoordinate(),push},
        std::pair{txtBaba.getCoordinate(),txtBaba},
        std::pair{is2.getCoordinate(),is2},
        std::pair{you.getCoordinate(),you},
        std::pair{txtWater.getCoordinate(),txtWater},
        std::pair{is3.getCoordinate(),is3},
        std::pair{kill.getCoordinate(),kill},
         };

    std::map<model::Elements, model::Elements>rules={
        std::pair{model::Elements::BABA, model::Elements::YOU},
        std::pair{model::Elements::ROCK,model::Elements::PUSH},
        std::pair{model::Elements::WATER,model::Elements::KILL},
    };

    model::Board board(cases, rules, length, width, false, false);

    SECTION ("test move and push and kill"){
        board.moveGameObjects(model::Direction::EAST);
        REQUIRE(board.getCases().find(model::Coordinate(7,5))->second.getElement()==model::Elements::BABA);
        board.moveGameObjects(model::Direction::EAST);
        REQUIRE(board.getCases().find(model::Coordinate(7,5))==board.getCases().end());
    }
}

TEST_CASE("Test Push with not kill rocks") {
int length=10;
int width=10;

model::GameObject baba("baba 3 5 ");
model::GameObject rock("rock 4 5 ");
model::GameObject rock2("rock 5 5 ");
model::GameObject lava("lava 6 5 ");

model::GameObject txtRock("text_rock 7 8 ");
model::GameObject is("is 8 8 ");
model::GameObject push("push 9 8 ");

model::GameObject txtBaba("text_baba 1 1 ");
model::GameObject is2("is 2 1 ");
model::GameObject you("you 3 1 ");

model::GameObject txtLava("text_lava 1 2 ");
model::GameObject is3("is 2 2 ");
model::GameObject kill("kill 3 2 ");


std::multimap<model::Coordinate, model::GameObject>cases={
     std::pair{rock.getCoordinate(), rock},
     std::pair{rock2.getCoordinate(), rock2},
     std::pair{baba.getCoordinate(),baba},
     std::pair{lava.getCoordinate(),lava},
     std::pair{txtRock.getCoordinate(),txtRock},
     std::pair{is.getCoordinate(),is},
     std::pair{push.getCoordinate(),push},
     std::pair{txtBaba.getCoordinate(),txtBaba},
     std::pair{is2.getCoordinate(),is2},
     std::pair{you.getCoordinate(),you},
     std::pair{txtLava.getCoordinate(),txtLava},
     std::pair{is3.getCoordinate(),is3},
     std::pair{kill.getCoordinate(),kill},
  };

std::map<model::Elements, model::Elements>rules={
            std::pair{model::Elements::BABA, model::Elements::YOU},
            std::pair{model::Elements::ROCK,model::Elements::PUSH},
            std::pair{model::Elements::LAVA,model::Elements::KILL},
        };

model::Board board(cases, rules, length, width, false, false);

    SECTION ("test move and push and kill"){
        board.moveGameObjects(model::Direction::EAST);
        board.moveGameObjects(model::Direction::EAST);
        REQUIRE(board.getCases().find(model::Coordinate(7,5))->second.getElement()==model::Elements::ROCK);
    }
}
