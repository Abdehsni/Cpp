#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Color.h"

using std::string;

namespace model {

class Player{
    string name;
    unsigned age;
    unsigned score;
    Color color;
public:
    Player(const string &name, unsigned age,Color color);
    const std::string& getName()const;
    int getAge() const;
    bool operator <(Player p);
    bool operator >(Player p);
    const unsigned& getScore()const;
    void addScore(unsigned i);
    void resetScore();
};

}
#endif // PLAYER_H
