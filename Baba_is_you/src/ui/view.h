#ifndef VIEW_H
#define VIEW_H
#include<iostream>
#include<algorithm>
#include<iomanip>
#include "game.h"
#include "utility/Observer.h"


namespace view{

class View : public Observer{

    void displayCases(model::Board &Board);
    void limits(int length);
    void nbColumns(int length);
    std::string convertObjectToString(model::GameObject& gameobject);
    void displayInfoUsefull();
public:
    View();
    void update(const Observable * subject)override;
    void displayGame(const model::Game &game);
    void displayLoseTheLevel();
    void welcome();
    void displayShutDownTheGame();
    void displayFinishTheGame();


};

}





#endif // VIEW_H
