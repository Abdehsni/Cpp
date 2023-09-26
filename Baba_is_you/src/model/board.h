#include"gameobject.h"
#include"direction.h"
#include <string>
#include<vector>
#include<map>
#include<stdexcept>
#ifndef BOARD_H
#define BOARD_H

namespace model{

class Board{

    std::multimap<Coordinate,GameObject>cases;
    ///First element correspond to the gameObjects concerned, the second is the effect associated with it
    std::map<Elements,Elements>rules;
    int length;
    int width;
    bool win;
    bool blocked;

    bool isInside(Coordinate coordinate);
    bool caseEmpty(const Coordinate &coordinate);
    void moveOneGameObject(GameObject &gameObject, const Direction &direction, std::vector<GameObject> &elementsToRemove);
    void updateRules();
    void removeOneGameObjectFromCases(GameObject gameObject);
    void insertOneGameObjectIntoCases(GameObject gameObject);

    /// isEmptyCase is a case within gameObject with no rules that has an effect like an empty case
    /// we check if it contains something but doesn't matter for the move
    /// \brief isEmptyCase
    /// \param movingObject
    /// \param coordinate
    /// \param elementsToRemove
    /// \return true if nothing disturb the move
    ///
    bool isEmptyCase(const GameObject &movingObject, const Coordinate& coordinate, const std::vector<GameObject> &elementsToRemove);

    bool isKillingCase(const Coordinate& coordinate);
    bool isSinkingCase(const Coordinate& coordinate);
    bool isWinningCase(const Coordinate& coordinate);
    bool isPushingCase(const Coordinate& coordinate);
    bool isTextElementChecked(const Coordinate& coordinate);
    bool isEffectElementChecked(const Coordinate& coordinate);

    ///check if a gameObject is listed as something to delete from the board
    /// to not disturb a move with gameobject marqued for removal
    /// \brief checkInRemovingObject
    /// \param gameObject
    /// \param elementsToRemove
    bool checkInRemovingObject(const GameObject &gameObject,const std::vector<GameObject>&elementsToRemove);

    /// check if the gameObject has an effect like push or stop or kill or sink
    /// \brief checkEffect
    /// \param movingObject
    /// \param gameobject
    /// \return true or false
    bool checkEffect(const GameObject &movingObject, const GameObject &gameobject);
    void doMove(GameObject& gameObject, const Direction& direction);


    /// method use for case where there are many gameObject
    /// we need to find a gameObject with pushing effect to make the move
    /// \brief findThePushingGameObject
    /// \param coordinate
    GameObject findThePushingGameObject(const Coordinate &coordinate);

public:
    Board();
    ///Constructor used only for tests
    /// \brief Board
    /// \param cases
    /// \param rules
    /// \param length
    /// \param width
    /// \param win
    /// \param blocked
    Board(const std::multimap<Coordinate,GameObject>&cases, const std::map<Elements, Elements> &rules, int length, int width, bool win, bool blocked);
    void moveGameObjects(const Direction &direction);
    void initialiseBoard(const std::tuple<std::vector<std::string>, int, int> &data);
    std::tuple<std::vector<std::string>, int, int> convertBoardToData();
    bool isWin();
    bool isBlocked();
    const std::multimap<Coordinate, GameObject> &getCases() const;
    int getLength() const;
    int getWidth() const;
    int countNbRules()const;
};

}



#endif // BOARD_H
