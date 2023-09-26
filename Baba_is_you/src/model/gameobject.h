#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include<string>
#include<stdexcept>
#include"type.h"
#include"elements.h"
#include"coordinate.h"
#include"direction.h"




namespace model{

class GameObject{
    model::Type type;
    model::Elements element;
    model::Coordinate coordinate;

public:
    /// Constructor used only for tests
    /// \brief GameObject
    /// \param type
    /// \param element
    /// \param coordinate
    GameObject(model::Type type, model::Elements element, const model::Coordinate &coordinate);
    GameObject(const std::string &string_object);
    model::Elements getElement() const;
    const model::Coordinate &getCoordinate() const;
    /// used for saving the game in a file,transform gameObject into string
    /// \brief convertGameObjectToStringData
    std::string convertGameObjectToStringData();

    /// give the next Coordinate depending on the direction
    /// \brief nextCoordinate
    /// \param start
    /// \param direction
    /// \return the next Coordinate

    Coordinate nextCoordinate(const Coordinate &start, const Direction &direction);

    void moveNorth();
    void moveSouth();
    void moveEast();
    void moveWest();
    bool isText() const;
    bool isConnector()const;
    bool isElement() const;
    bool isEffect()const;
    bool isTextElement()const;
    model::Type getType() const;
};

bool operator==(const GameObject& gameObject1, const GameObject & gameObject2);
}


#endif // PIECE_H
