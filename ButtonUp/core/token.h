#ifndef TOKEN_H
#define TOKEN_H
#include <Color.h>

namespace model{

class Token{

    Color color;
public:
    Token(Color color);

    Color getColor() const;
    bool isWhite();
    bool isRed();
    bool isBlack();
    bool operator ==(Token tok);

};

}

#endif // TOKEN_H
