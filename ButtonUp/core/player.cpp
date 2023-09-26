#include "player.h"

namespace model {

const string&  Player::getName()const
{
    return name;
}

int Player::getAge() const
{
    return age;
}

bool Player::operator <(Player p)
{
    return this->age<p.age;
}

bool Player::operator >(Player p)
{
    return this->age>p.age;
}

const unsigned &Player::getScore() const
{
    return score;
}

void Player::addScore(unsigned i)
{
   this->score+=i;
}

void Player::resetScore()
{
    this->score=0;
}

Player::Player(const string &name, unsigned age,Color color) : name(name),
    age(age),score(0),color(color)
{}

}
