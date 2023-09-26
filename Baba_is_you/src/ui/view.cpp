#include"view.h"
#define numberThatTakesTwoPlaces 10

using model::Elements;
view::View::View()
{}


void view::View::update(const Observable *subject){
    const model::Game* game = dynamic_cast<const model::Game*>(subject);
    if (game != nullptr) {
        displayGame(*game);
    }
}

void view::View::displayGame(const model::Game &game)
{
    auto cases= game.getBoard().getCases();
    int width= game.getBoard().getWidth();
    int length= game.getBoard().getLength();

    displayInfoUsefull();
    limits(length);
    nbColumns(length);
    for(int y=0;y<width;y++){
        std::cout<<std::to_string(y);
        if(y<numberThatTakesTwoPlaces)std::cout<<" ";
        for(int x=0;x<length;x++){
            auto it =cases.find(model::Coordinate(x,y));
            if(it!=cases.end()){
                std::string objectToString=convertObjectToString(it->second);
                std::cout<<"|"<<objectToString<<"|";
            }else{
                std::cout<<"|   |";
            }
        }
        std::cout<<std::endl;
    }
    limits(length);
    std::cout<<"-----Cases with more than one gameObject-----"<<std::endl;
    for(int i=0;i<width;i++){
        for(int j=0;j<length;j++){
            auto range=cases.equal_range(model::Coordinate(i,j));
            if(std::distance(range.first,range.second)>1){
                std::cout<<"("<<std::to_string(i)<<","<<std::to_string(j)<<") :";
                std::for_each(range.first,range.second,
                    [&](auto object){std::cout<<convertObjectToString(object.second)<<"  ";});
                std::cout<<std::endl;
                }
            }
    }
}

void view::View::displayLoseTheLevel()
{
    std::cout<<"-----------YOU LOSE ,REPLAY THE LEVEL-----------";
}

void view::View::welcome()
{
    std::cout<<"Welcome to BABA_IS_YOU game ,do you want to load a game?y/n  : ";
}

void view::View::displayShutDownTheGame()
{
    std::cout<<"----------------Good Bye !!!!!-----------------"<<std::endl;
}

void view::View::displayFinishTheGame()
{
    std::cout<<"--------------Congrat's you finish the game---------------"<<std::endl;
}

void view::View::limits(int length)
{
    for(int i=0;i<length*5;i++){
        std::cout.put('-');
    }
    std::cout<<std::endl;
}


void view::View::nbColumns(int length)
{
    std::cout<<"  ";
    for(int i=0;i<length;i++){
        std::cout<<"  "<<std::to_string(i);
        if(i<numberThatTakesTwoPlaces){
            std::cout<<"  ";
        }else{
            std::cout<<" ";

        }
    }
    std::cout<<std::endl;
}


std::string view::View::convertObjectToString(model::GameObject &gameobject)
{
    std::string result{};
    auto element=gameobject.getElement();
    if(gameobject.isConnector()){
        switch(element){
        case Elements::IS: result=" IS";break;
        default:break;
        }
    }else if(gameobject.isText()){
        switch(element){
            case Elements::YOU: result="YOU";break;
            case Elements::STOP: result="STP";break;
            case Elements::PUSH: result="PSH";break;
            case Elements::WIN: result="WIN";break;
            case Elements::SINK: result="SNK";break;
            case Elements::KILL:result="KLL";break;
            case Elements::WALL:result="TWL";break;
            case Elements::ROCK:result="TRK";break;
            case Elements::BABA:result="TBB";break;
            case Elements::METAL:result="TMT";break;
            case Elements::GRASS:result="TGR";break;
            case Elements::FLAG:result="TFG";break;
            case Elements::WATER:result="TWT";break;
            case Elements::LAVA:result="TLV";break;
            default:break;
        }
    }else if(gameobject.isElement()){
        switch(element){
            case Elements::WALL:result="WLL";break;
            case Elements::ROCK:result="RCK";break;
            case Elements::BABA:result="BBA";break;
            case Elements::METAL:result="MTL";break;
            case Elements::GRASS:result="GRS";break;
            case Elements::FLAG:result="FLG";break;
            case Elements::WATER:result="WTR";break;
            case Elements::LAVA:result="LVA";break;
            default:break;
        }
    }else{
        std::invalid_argument("gameobject to display not recognized ");
    }
    return result;
}

void view::View::displayInfoUsefull()
{
    std::cout<<"-------------------------Code of Elements on board-------------------------"<<std::endl;
    std::cout<<"   STP = STOP"<<"        PSH = PUSH"<<"         SNK = SINK"<<std::endl;
    std::cout<<"   KLL = KILL"<<"        TWL = TEXT_WALL"<<"    TRK = TEXT_ROCK"<<std::endl;
    std::cout<<"   TBB = TEXT_BABA"<<"   TMT = TEXT_METAL"<<"   TGR = TEXT_GRASS"<<std::endl;
    std::cout<<"   TFG = TEXT_FLAG"<<"   TWT = TEXT_WATER"<<"   TLV = TEXT_LAVA"<<std::endl;
    std::cout<<"   WLL = WALL"<<"        RCK = ROCK"<<"         BBA = BABA"<<std::endl;
    std::cout<<"   MTL = METAL"<<"       GRS = GRASS"<<"        FLG = FLAG"<<std::endl;
    std::cout<<"   WTR = WATER"<<"       LVA = LAVA"<<std::endl;

}


