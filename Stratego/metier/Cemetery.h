#ifndef CEMETERY_H
#define CEMETERY_H
#include "Piece.h"
#include "Player.h"

/**
 * @brief The Cemetery class
 */
namespace model {

class Cemetery{
    int nbDeadP1=0;
    int nbDeadP2=0;
public:

    /**
     * @brief Cemetery constructor
     */
    Cemetery(){};

    /**
     * @brief add a victim in the cemetry of the player p
     * @param p
     * @param piece
     */
    void victime(Player& p,Piece& piece);
    /**
     * @brief verify if a flag is found
     * @param piece
     * @return true if the piece is a flag
     */
    bool flagFound(Player &currentPlayer);

    /**
     * @brief Vérify if there is no more mobile piece
     * @param p
     * @return true
     */
    bool allDead(Player& p);

    /**
     * @brief The getter of the private attribute nbDeadP1
     * @return number dead of p1
     */
    int getNbDeadP1() const;

    /**
     * @brief The setter of the private attribute nbDeadP2
     * @param newNbDeadP1
     */
    void setNbDeadP1(int newNbDeadP1);

    /**
     * @brief The getter of the private attribute nbDeadP2
     * @return number dead of p2
     */
    int getNbDeadP2() const;

    /**
     * @brief The setter of the private attribute nbDeadP2
     * @param newNbDeadP2
     */
    void setNbDeadP2(int newNbDeadP2);
};

inline int Cemetery::getNbDeadP1() const
{
    return nbDeadP1;
}

inline void Cemetery::setNbDeadP1(int newNbDeadP1)
{
    nbDeadP1 = newNbDeadP1;
}

inline int Cemetery::getNbDeadP2() const
{
    return nbDeadP2;
}

inline void Cemetery::setNbDeadP2(int newNbDeadP2)
{
    nbDeadP2 = newNbDeadP2;
}

}
#endif // CEMETERY_H



