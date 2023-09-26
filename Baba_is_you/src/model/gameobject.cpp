#include "gameobject.h"

namespace model {

model::Type GameObject::getType() const
{
    return type;
}

GameObject::GameObject(model::Type type, model::Elements element, const Coordinate &coordinate) : type(type),
    element(element),
    coordinate(coordinate)
{}


/* Constructor that convert a string (usually from the fileloader ) into a gameObject
 * format of the string :  "element x y"
 * return a gameobject
*/

GameObject::GameObject(const std::string &string_object)
{
    size_t sizeOfFirstPart= string_object.find(" ");
    std::string firstPartOfStringObject = string_object.substr(0,sizeOfFirstPart);
    size_t sizeOfSecondPart= string_object.find(" ",sizeOfFirstPart+1);
    std::string secondPartOfStringObject= string_object.substr(sizeOfFirstPart+1,sizeOfSecondPart-sizeOfFirstPart-1);
    std::string thirdPartOfStringObject= string_object.substr(sizeOfSecondPart+1);
    coordinate = Coordinate(stoi(secondPartOfStringObject),stoi(thirdPartOfStringObject));

    if(firstPartOfStringObject=="text_wall"){
        type =model::Type::TEXT;
        element =model::Elements::WALL;
    }else if(firstPartOfStringObject=="text_rock"){
        type=model::Type::TEXT;
        element=model::Elements::ROCK;
    }else if(firstPartOfStringObject=="text_metal"){
        type=model::Type::TEXT;
        element=model::Elements::METAL;
    }else if(firstPartOfStringObject=="text_baba"){
        type=model::Type::TEXT;
        element=model::Elements::BABA;
    }else if(firstPartOfStringObject=="text_flag"){
        type=model::Type::TEXT;
        element=model::Elements::FLAG;
    }else if(firstPartOfStringObject=="text_grass"){
        type=model::Type::TEXT;
        element=model::Elements::GRASS;
    }else if(firstPartOfStringObject=="text_water"){
        type=model::Type::TEXT;
        element=model::Elements::WATER;
    }else if(firstPartOfStringObject=="text_lava"){
        type=model::Type::TEXT;
        element=model::Elements::LAVA;
    }else if(firstPartOfStringObject=="you"){
        type=model::Type::TEXT;
        element=model::Elements::YOU;
    }else if(firstPartOfStringObject=="stop"){
        type=model::Type::TEXT;
        element=model::Elements::STOP;
    }else if(firstPartOfStringObject=="push"){
        type=model::Type::TEXT;
        element=model::Elements::PUSH;
    }else if(firstPartOfStringObject=="win"){
        type=model::Type::TEXT;
        element=model::Elements::WIN;
    }else if(firstPartOfStringObject=="sink"){
        type=model::Type::TEXT;
        element=model::Elements::SINK;
    }else if(firstPartOfStringObject=="kill"){
        type=model::Type::TEXT;
        element=model::Elements::KILL;
    }else if(firstPartOfStringObject=="is"){
        type=model::Type::CONNECTOR;
        element=model::Elements::IS;
    }else if(firstPartOfStringObject=="wall"){
        type=model::Type::ELEMENT;
        element=model::Elements::WALL;
    }else if(firstPartOfStringObject=="rock"){
        type=model::Type::ELEMENT;
        element=model::Elements::ROCK;
    }else if(firstPartOfStringObject=="baba"){
        type=model::Type::ELEMENT;
        element=model::Elements::BABA;
    }else if(firstPartOfStringObject=="metal"){
        type=model::Type::ELEMENT;
        element=model::Elements::METAL;
    }else if(firstPartOfStringObject=="grass"){
        type=model::Type::ELEMENT;
        element=model::Elements::GRASS;
    }else if(firstPartOfStringObject=="flag"){
        type=model::Type::ELEMENT;
        element=model::Elements::FLAG;
    }else if(firstPartOfStringObject=="water"){
        type=model::Type::ELEMENT;
        element=model::Elements::WATER;
    }else if(firstPartOfStringObject=="lava"){
        type=model::Type::ELEMENT;
        element=model::Elements::LAVA;
    }else{
        throw std::invalid_argument("first_part_of String_no_valid");
    }
}


model::Elements GameObject::getElement() const
{
    return element;
}

const model::Coordinate &GameObject::getCoordinate() const
{
    return coordinate;
}

std::string GameObject::convertGameObjectToStringData()
{
    std::string result;
    if(type==model::Type::TEXT){
        switch(element){
            case model::Elements::BABA: result="text_baba";break;
            case model::Elements::FLAG: result="text_flag";break;
            case model::Elements::GRASS: result="text_grass";break;
            case model::Elements::KILL: result="kill";break;
            case model::Elements::LAVA: result="text_lava";break;
            case model::Elements::METAL: result="text_metal";break;
            case model::Elements::PUSH: result="push";break;
            case model::Elements::ROCK: result="text_rock";break;
            case model::Elements::SINK: result="sink";break;
            case model::Elements::STOP: result="stop";break;
            case model::Elements::WALL: result="text_wall";break;
            case model::Elements::WATER: result="text_water";break;
            case model::Elements::WIN: result="win";break;
            case model::Elements::YOU: result="you";break;
            default: throw std::invalid_argument("text_element not recognized");
        }
    }else if(type==model::Type::ELEMENT){
        switch(element){
           case model::Elements::BABA:result="baba";break;
           case model::Elements::FLAG:result="flag";break;
           case model::Elements::GRASS:result="grass";break;
           case model::Elements::LAVA:result="lava";break;
           case model::Elements::METAL:result="metal";break;
           case model::Elements::ROCK:result="rock";break;
           case model::Elements::WALL:result="wall";break;
           case model::Elements::WATER:result="water";break;
           default: throw std::invalid_argument("element not recognized");
        }
    }else{
        result="is";
    }
    result+=" "+std::to_string(coordinate.getX())+" "+std::to_string(coordinate.getY())+" ";
    return result;
}

Coordinate GameObject::nextCoordinate(const Coordinate &start ,const Direction &direction)
{
    Coordinate end=start;
    switch(direction){
    case Direction::NORTH:end.setY(end.getY()-1);break;
    case Direction::SOUTH:end.setY(end.getY()+1);break;
    case Direction::EAST:end.setX(end.getX()+1);break;
    case Direction::WEST:end.setX(end.getX()-1);break;
    default: throw std::invalid_argument("Problem with nextCoordinate");
    }
    return end;
}

void GameObject::moveNorth()
{
    coordinate.getX();
    coordinate.setY(coordinate.getY()-1);
}

void GameObject::moveSouth()
{
    coordinate.setY(coordinate.getY()+1);
}

void GameObject::moveEast()
{
    coordinate.setX(coordinate.getX()+1);
}

void GameObject::moveWest()
{
    coordinate.setX(coordinate.getX()-1);
}

 bool GameObject::isText()const
{
    return type == Type::TEXT;
}

bool GameObject::isConnector()const
{
    return type == Type::CONNECTOR;
}

bool GameObject::isElement()const
{
    return type == Type::ELEMENT;
}

bool GameObject::isEffect() const
{
    bool effect{false};
    if(isText()){
        switch(element){
        case Elements::KILL:effect=true;break;
        case Elements::PUSH:effect=true;break;
        case Elements::SINK:effect=true;break;
        case Elements::STOP:effect=true;break;
        case Elements::WIN:effect=true;break;
        case Elements::YOU:effect=true;break;
        default:break;
        }
    }
    return effect;
}

bool GameObject::isTextElement() const
{
    bool textElement{false};
    if(isText()){
        switch(element){
        case Elements::BABA:textElement=true;break;
        case Elements::FLAG:textElement=true;break;
        case Elements::GRASS:textElement=true;break;
        case Elements::LAVA:textElement=true;break;
        case Elements::METAL:textElement=true;break;
        case Elements::ROCK:textElement=true;break;
        case Elements::WATER:textElement=true;break;
        case Elements::WALL:textElement=true;break;
        default:break;
        }
    }
    return textElement;

}


bool operator==(const GameObject &gameObject1, const GameObject &gameObject2)
{
    return gameObject1.getType()==gameObject2.getType()&&gameObject1.getElement()==gameObject2.getElement();
}


}
