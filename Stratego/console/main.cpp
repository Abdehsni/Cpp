#include <iostream>
#include "consoleController.h"
using std::cout;
using std::endl;

int main()
{
    Game game;
    ConsoleView consoleView{&game};
    controller::Controller controller{&game,&consoleView};
    controller.startGame();

/*
    Piece flag = Flag(ColorPiece::BLUE);

    game.burriedPiece(game.getCurrentPlayer(),flag);

    if(game.isFinish()==true){
            cout <<"ok"<<endl;
    }else {
            cout<<"ko"<<endl;
    }
            */

    return 0;
}
