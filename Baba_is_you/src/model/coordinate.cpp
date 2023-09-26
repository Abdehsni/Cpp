#include"coordinate.h"

namespace model {
Coordinate::Coordinate()
{}

Coordinate::Coordinate(int x, int y) : x(x),
    y(y)
{}

Coordinate::Coordinate(const Coordinate &c)
{
    x=c.x;
    y=c.y;
}

Coordinate &Coordinate::operator=(const Coordinate &c)
{
    if(this!=&c){
        x=c.x;
        y=c.y;
    }
    return *this;
}

int Coordinate::getX()const
{
    return x;
}

void Coordinate::setX(int newX)
{
    x = newX;
}

int Coordinate::getY()const
{
    return y;
}

void Coordinate::setY(int newY)
{
    y = newY;
}

}
