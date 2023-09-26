#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include "ColorPiece.h"
using std::string;

/**
 * @brief The Player class
 */
namespace model {

class Player{
    string name;
    ColorPiece colorPiece;

public:
    Player();
    /**
     * @brief constructor of Player
     * @param name
     * @param colorPiece
     */
    Player(const string &name, ColorPiece colorPiece);
    /**
     * @brief The getter of the private attribute name
     */
    const string &getName() const;
    /**
     * @brief The setter of the private attribute name
     * @param newName
     */
    void setName(const string &newName);
    /**
     * @brief The getter of the private attribute colorPiece
     */
    ColorPiece getColorPiece() const;
    /**
     * @brief The setter of the private attribute colorPiece
     * @param newColorPiece
     */
    void setColorPiece(ColorPiece newColorPiece);

    /**
     * @brief operator ==
     * @param player
     */
    inline bool operator == (const Player& player)const;

};

inline const string &Player::getName() const
{
    return name;
}

inline void Player::setName(const string &newName)
{
    name = newName;
}

inline ColorPiece Player::getColorPiece() const
{
    return colorPiece;
}

inline void Player::setColorPiece(ColorPiece newColorPiece)
{
    colorPiece = newColorPiece;
}

bool Player::operator == (const Player& player)const{
    if(player.getColorPiece()==this->colorPiece){
        return true;
    }
    return false;
}
}
#endif // PLAYER_H


