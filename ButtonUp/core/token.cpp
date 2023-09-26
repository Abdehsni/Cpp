#include <token.h>

namespace model {

Token::Token(model::Color color) : color(color)
{}

Color Token::getColor() const
{
    return color;
}

bool Token::isWhite()
{
    return color==Color::WHITE?true:false;
}

bool Token::isRed()
{
    return color==Color::RED?true:false;
}

bool Token::isBlack()
{
    return color==Color::BLACK?true:false;
}

bool Token::operator ==(Token tok)
{
    if(this->color==tok.color)return true;
    else return false;
}



}
