#ifndef COORDINATE_H
#define COORDINATE_H
#include<compare>
namespace model {

class Coordinate{
    int x;
    int y;
public:
    Coordinate();
    Coordinate(int x, int y);
    Coordinate(const Coordinate &c);
    bool operator ==(const Coordinate& c) const=default;
    auto operator<=>(const Coordinate& c) const=default;
    Coordinate& operator =(const Coordinate &c);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
};

}




#endif // COORDINATE_H
