#include"board.h"


namespace model {
const std::multimap<Coordinate, GameObject> &Board::getCases() const
{
    return cases;
}

int Board::getLength() const
{
    return length;
}

int Board::getWidth() const
{
    return width;
}

int Board::countNbRules() const
{
    return rules.size();
}

bool Board::isInside(Coordinate coordinate)
{
    return coordinate.getX()<length && coordinate.getX() >=0 && coordinate.getY()<width && coordinate.getY()>=0;
}

bool Board::caseEmpty(const Coordinate &coordinate)
{
     return cases.find(coordinate) == cases.end();
}

Board::Board()
{
}

Board::Board(const std::multimap<Coordinate, GameObject> &cases, const std::map<Elements, Elements> &rules,
             int length, int width, bool win, bool blocked):cases(cases),rules(rules),
    length(length),
    width(width),
    win(win),
    blocked(blocked)
{
}


void Board::initialiseBoard(const std::tuple<std::vector<std::string>, int, int> &data)
{
    rules.clear();
    cases.clear();
    win=false;
    blocked=false;
    length=std::get<1>(data);
    width=std::get<2>(data);
    auto string_objects= std::get<0>(data);
    for(const auto& string_object: string_objects){
        model::GameObject gameObject(string_object);
        cases.emplace(model::Coordinate(gameObject.getCoordinate()),gameObject);
    }
    updateRules();
}


std::tuple<std::vector<std::string>, int, int> Board::convertBoardToData()
{
    std::vector<std::string>gameobjects;
    for(auto &_case:cases){
        gameobjects.push_back(_case.second.convertGameObjectToStringData());
    }
    return std::make_tuple(gameobjects,length,width);
}

bool Board::isWin()
{
    return win;
}

void Board::moveGameObjects(const Direction& direction)
{
    Elements elemToMove=Elements::BABA;
    bool ruleYou{false};
    //we use this boolean to check after the move if the player is blocked(he cannot move anyway)
    bool ruleYouAfterMove{false};

    for(auto const & rule : rules){
        if(rule.second==Elements::YOU){
            elemToMove=rule.first ;
            ruleYou=true;
            break;
        }
    }

    if(!ruleYou){
        blocked=true;
    }else{
            bool checkElemToMove{false};
            std::vector<GameObject> elementsToRemove;
            std::vector<GameObject> elementsToMove;

            for(int x=0;x<length;x++){
                for(int y=0;y<width;y++){
                    auto range = cases.equal_range(Coordinate(x,y));
                    for (auto it = range.first; it != range.second; ++it) {
                        if (it->second.isElement() && it->second.getElement() == elemToMove) {
                            checkElemToMove = true;
                            elementsToMove.push_back(it->second);
                        }
                    }
                }
            }

            for (auto element : elementsToMove) {
                moveOneGameObject(element, direction,elementsToRemove);
                 updateRules();
            }


            if(!elementsToRemove.empty()){
                for(const auto &elements : elementsToRemove){
                    removeOneGameObjectFromCases(elements);
                }
            }

            for(auto const & rule : rules){
                if(rule.second==Elements::YOU){
                    ruleYouAfterMove=true;
                }
            }
            if(!checkElemToMove||!ruleYouAfterMove)blocked=true;
        }
}

/// we assume that a case where is a Text Element gameOobject
/// cannot contain another gameObject as seen in the game
void Board::moveOneGameObject(GameObject &gameObject, const Direction& direction, std::vector<GameObject> &elementsToRemove)
{
    Coordinate destination = gameObject.nextCoordinate(gameObject.getCoordinate(),direction);
    if(isInside(destination)){
        bool isPushing=isPushingCase(destination);
        if(isPushing||isEmptyCase(gameObject,destination,elementsToRemove)){
            if(isPushing){
                if(isWinningCase(destination)&&rules.find(gameObject.getElement())->second==Elements::YOU){
                    win=true;
                }else{
                auto elemt=findThePushingGameObject(destination);
                moveOneGameObject(elemt,direction,elementsToRemove);
                }
            }
            if(isEmptyCase(gameObject,destination,elementsToRemove)){
                doMove(gameObject,direction);
            }else if(isKillingCase(destination)&&rules.find(gameObject.getElement())->second==Elements::YOU){
                elementsToRemove.push_back(gameObject);
            }
         //Warning:for killing or sinking when moving a group of gameObject, only remove one element
        }else if(isKillingCase(destination)&&rules.find(gameObject.getElement())->second==Elements::YOU){
            elementsToRemove.push_back(gameObject);
        }else if(isSinkingCase(destination)){
            elementsToRemove.push_back(gameObject);
            elementsToRemove.push_back(cases.find(destination)->second);
        }else if(isWinningCase(destination)&&rules.find(gameObject.getElement())->second==Elements::YOU){
            win=true;
        }
    }
}



bool Board::isEmptyCase(const GameObject &movingObject ,const Coordinate &coordinate,const std::vector<GameObject> &elementsToRemove)
{
    bool empty{true};
    for(const auto &_case : cases){
        if(_case.first==coordinate){
            GameObject gameObject = _case.second;
            if(gameObject.isConnector()||gameObject.isText()||
                (checkEffect(movingObject,gameObject)&&!checkInRemovingObject(gameObject,elementsToRemove))){
                 empty=false;
                 break;
            }

        }
     }
    return empty;
}


bool Board::isKillingCase(const Coordinate &coordinate)
{
    bool kill{false};
    auto range = cases.equal_range(coordinate);
    for(auto it = range.first; it != range.second; ++it) {
        if(it->second.isElement() && rules.find(it->second.getElement())->second == Elements::KILL) {
            kill = true;
            break;
        }
    }
    return kill;
}

bool Board::isSinkingCase(const Coordinate &coordinate)
{
    bool sink{false};
    auto range = cases.equal_range(coordinate);
    for(auto it = range.first; it != range.second; ++it) {
        if(it->second.isElement() && rules.find(it->second.getElement())->second == Elements::KILL) {
            sink = true;
            break;
        }
    }
    return sink;
}


bool Board::isWinningCase(const Coordinate &coordinate)
{
    bool win{false};
    auto range = cases.equal_range(coordinate);
    for(auto it = range.first; it != range.second; ++it) {
        if(it->second.isElement() && rules.find(it->second.getElement())->second == Elements::WIN) {
            win = true;
            break;
        }
    }
    return win;
}


bool Board::isPushingCase(const Coordinate &coordinate)
{
    bool isPushing{false};
    auto range = cases.equal_range(coordinate);
    for (auto it = range.first; it != range.second; ++it) {
        const auto& gameObject = it->second;
        if (rules.find(gameObject.getElement())->second == Elements::SINK) {
            isPushing = false;
            break;
        }
        if (gameObject.isText() || gameObject.isConnector()) {
            isPushing = true;
            break;
        } else if (rules.find(gameObject.getElement())->second == Elements::PUSH) {
            isPushing = true;
        }
    }

    return isPushing;
}

/// we assume that a case where is a Text Element gameOobject
/// cannot contain another gameObject as seen in the game
bool Board::isTextElementChecked(const Coordinate &coordinate)
{
    bool isTrue{false};
    if(isInside(coordinate)){
        auto _case=cases.find(coordinate)->second;
        if(_case.isTextElement())isTrue=true;
    }
    return isTrue;
}

/// we assume that a case where is a Effect Element gameOobject
/// cannot contain another gameObject as seen in the game
bool Board::isEffectElementChecked(const Coordinate &coordinate)
{
    bool isTrue{false};
    if(isInside(coordinate)){
        auto _case=cases.find(coordinate)->second;
        if(_case.isEffect())isTrue=true;
    }
    return isTrue;;
}


bool Board::checkInRemovingObject(const GameObject &gameObject, const std::vector<GameObject> &elementsToRemove)
{
    bool gameObjectWaitingForDelete{false};
    for(const auto &element:elementsToRemove){
        if(gameObject==element&&gameObject.getCoordinate()==element.getCoordinate()){
            gameObjectWaitingForDelete=true;
            break;
        }
    }
    return gameObjectWaitingForDelete;
}


///
/// \brief Board::checkEffect
/// here we use find and not equal_range because rules is a map
///
bool Board::checkEffect(const GameObject &movingObject,const GameObject &gameobject)
{
    bool effect{false};
    auto rule = rules.find(gameobject.getElement());
    if(rule!=rules.end()){
        switch(rule->second){
        case Elements::STOP:effect=true;break;
        case Elements::SINK:effect=true;break;
        case Elements::KILL:
            if(rules.find(movingObject.getElement())->second==Elements::YOU){effect=true;}
            ;break;
        case Elements::WIN:
            if(rules.find(movingObject.getElement())->second==Elements::YOU){effect=true;}
            break;
        case Elements::PUSH:effect=true;break;
        default:break;
        }
    }
    return effect;
}

void Board::doMove(GameObject &gameObject, const Direction &direction)
{

    removeOneGameObjectFromCases(gameObject);

    switch(direction){
    case Direction::NORTH:
        gameObject.moveNorth();
        break;
    case Direction::SOUTH:
        gameObject.moveSouth();
        break;
    case Direction::WEST:
        gameObject.moveWest();
        break;
    case Direction::EAST:
        gameObject.moveEast();
        break;
    }

    insertOneGameObjectIntoCases(gameObject);

}

GameObject Board::findThePushingGameObject(const Coordinate &coordinate)
{
    //here we create a random gameObject, "baba 1 1 " doesnt matter for the algorithm
    GameObject gameObject("baba 1 1 ");
    auto range = cases.equal_range(coordinate);
    if (std::distance(range.first, range.second) > 1) {
        for(auto it = range.first; it != range.second; it++){
            gameObject=it->second;
            if(rules.find(gameObject.getElement())->second==Elements::PUSH){
                break;
            }else if(gameObject.isText()||gameObject.isConnector()){
                break;
            }
        }
    }else if(range.first != cases.end()){
        gameObject=range.first->second;
    }
    return gameObject;
}


void Board::removeOneGameObjectFromCases(GameObject gameObject)
{

    auto range = cases.equal_range(gameObject.getCoordinate());
    for (auto it = range.first; it != range.second; ++it) {
            if (it->second == gameObject ){
            cases.erase(it);
            break;
        }
    }
}

void Board::insertOneGameObjectIntoCases(GameObject gameObject){
    cases.insert(std::make_pair(gameObject.getCoordinate(),gameObject));
}




///we cannot use equal_range here because we dont now the location of the IS gameObject
void Board::updateRules()
{
    rules.clear();
    std::vector<Coordinate> coordinatesIs;
    for (const auto& [coordinate, gameObject] : cases) {
        if (gameObject.isConnector()) {
            coordinatesIs.push_back(coordinate);
        }
    }
    for(const auto& coordinate:coordinatesIs){
        Coordinate left=Coordinate(coordinate.getX()-1,coordinate.getY());
        Coordinate up=Coordinate(coordinate.getX(),coordinate.getY()-1);
        Coordinate right=Coordinate(coordinate.getX()+1,coordinate.getY());
        Coordinate below=Coordinate(coordinate.getX(),coordinate.getY()+1);
        if(isTextElementChecked(left)&&isEffectElementChecked(right)){
            rules.emplace(cases.find(left)->second.getElement(),cases.find(right)->second.getElement());
        }
        if(isTextElementChecked(up)&&isEffectElementChecked(below)){
            rules.emplace(cases.find(up)->second.getElement(),cases.find(below)->second.getElement());
        }
    }
}


bool Board::isBlocked()
{
    return blocked;
}

}




