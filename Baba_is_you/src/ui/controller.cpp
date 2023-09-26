#include "controller.h"
#include "view.h"
#define MAX_LEVEL 5  //max levels available
#define MinSizePathName 4

const model::Game &Controller::game() const
{
    return _game;
}

bool Controller::inputYesOrNo()
{
    std::string input;
    bool valid_input = false;
    while (!valid_input) {
        std::string inputline;
        std::getline(std::cin, inputline);
        input = inputline.substr(0, inputline.find(' '));
        if (input == "yes" || input == "no"|| input=="y" || input=="n") {
            valid_input = true;
        } else {
            std::cout << "Invalid input. Enter either 'yes' or 'no' or 'y' or 'n': " << std::endl;
        }

    }

    if(input=="yes" ||input=="y"){
        return true;
    }else{
        return false;
    }

}

bool Controller::checkInput(const std::string &input)
{
    return input=="I"||input=="K"||input=="L"||input=="J"||input=="R"||input=="V"||input=="Q"
           ||input=="i"||input=="k"||input=="l"||input=="j"||input=="r"||input=="v"||input=="q";
}


Controller::Controller(std::unique_ptr<view::View> view)
{
    _view= std::move(view);
    view::View * interimView= _view.get();
    _game.registerObserver(interimView);
}

void Controller::playGame()
{
    _view->welcome();
    if(inputYesOrNo()==true){
        bool exceptionSolved{false};
        while(!exceptionSolved){
            std::string path = askForPathForSavingOrLoadingGame(false);
            try {
                exceptionSolved=true;
                _game.loadGame(path);
            } catch (const std::invalid_argument& e) {
                std::cout<<e.what()<<std::endl;
                exceptionSolved=false;
            }

        }

    }else{
        _game.startGame();        
    }

    bool endGame{false};
    while(!endGame){
        while(!_game.levelWon()&&!_game.levelFailed()){
            std::string action = askForAction();
            if(action=="I"||action=="i"){
                _game.move(model::Direction::NORTH);
            }else if(action=="K"||action=="k"){
                _game.move(model::Direction::SOUTH);
            }else if(action=="J"||action=="j"){
                _game.move(model::Direction::WEST);
            }else if(action=="L"||action=="l"){
                _game.move(model::Direction::EAST);
            }else if(action=="R"||action=="r"){
                _game.restartLevel();

                break;
            }else if(action=="V"||action=="v"){
                bool exceptionSolved{false};
                while(!exceptionSolved){
                    std::string name = askForPathForSavingOrLoadingGame(true);
                    try {
                        exceptionSolved=true;
                        _game.saveGame(name);
                    } catch (const std::invalid_argument& e) {
                        std::cout<<e.what()<<std::endl;
                        exceptionSolved=false;
                    }

                }
                endGame=true;
                break;
            }else if(action=="Q"||action=="q"){
                endGame=true;
                break;
            }

        }
        if(_game.levelWon()){
            if(_game.getCurrentLevel()<MAX_LEVEL){
              _game.nextLevel();

            }else{
                endGame=true;
                _view->displayFinishTheGame();
            }
        }else if(_game.levelFailed()){
            _view->displayLoseTheLevel();
            _game.restartLevel();

        }else if(!endGame){
            _game.restartLevel();

        }

    }
    //end of game
    _view->displayShutDownTheGame();

}

std::string Controller::askForAction(){
    std::string inputLine;
    std::string input;
    bool validinput{false};
    while(!validinput){
        std::cout<<"Enter a command(I = move north, K = move south, L = move to east, J = move to west, R = reset level , V = save game and quit, Q = quit) : "<<std::endl;
        std::getline(std::cin, inputLine);
        input = inputLine.substr(0, inputLine.find(' '));
        if(checkInput(input)){
            validinput=true;
        }else{
            std::cout<<std::setw(10)<<"Wrong command , enter a valid command"<<std::endl;
        }
    }
    return input;
}


std::string Controller::askForPathForSavingOrLoadingGame(bool saving)
{
    std::string inputLine;
    std::string input;
    bool valideinput{false};
    while(!valideinput){
        if(saving){
            std::cout<<"Enter a name to save the game in a file .txt (existing or not) : ";
        }else{
            std::cout<<"Enter the save to load the game from a file .txt (existing file only) : ";
        }
        std::getline(std::cin, inputLine);
        input = inputLine.substr(0, inputLine.find(' '));
        if (input.size() >= MinSizePathName && input.substr(input.size()-4) == ".txt") {
            valideinput=true;
        }else{
            std::cout<<std::endl<<"This is not a .txt file , try again "<<std::endl;
        }
    }
    return input;
}

