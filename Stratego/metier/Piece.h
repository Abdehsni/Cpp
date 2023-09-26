#ifndef PIECE_H
#define PIECE_H
#include <string>
#include "ColorPiece.h"
#include <vector>
#include "Position.h"
#include "iostream"

using std::string;
using std::vector;

/**
 * @brief The Piece class
 */

namespace model {

class Piece {

protected:
    int rank;
    string symbol;
    int moveMax;
    ColorPiece color;
    vector<Position> history;
    bool isHidden=false;

public:

    Piece()=delete;

    /**
     * Constructor of Piece
     * @brief Piece
     * @param rank
     * @param symbol
     * @param moveMax
     * @param color
     */
    Piece(int rank, const string &symbol, int moveMax, ColorPiece color);

    /**
     * @brief add a move to history
     * @param pos
     */
    void addPosToHistory(Position pos);
    /**
     * @brief operator >
     * @param piece
     */
    inline bool operator > (Piece& piece);
    /**
     * @brief operator ==
     * @param piece
     */
    inline bool operator == ( Piece& piece1);
    /**
     * @brief operator !=
     * @param piece
     */
    inline bool operator != ( Piece& piece);

    /**
     * @brief getRank
     */
    int getRank() const;
    /**
     * @brief setRank
     * @param newRank
     */
    void setRank(int newRank);
    /**
     * @brief getSymbol
     */
    const string &getSymbol() const;
    /**
     * @brief setSymbol
     * @param newSymbol
     */
    void setSymbol(const string &newSymbol);
    /**
     * @brief getMoveMax
     */
    int getMoveMax() const;
    /**
     * @brief setMoveMax
     * @param newMoveMax
     */
    void setMoveMax(int newMoveMax);
    /**
     * @brief getColor
     */
    ColorPiece getColor() const;
    /**
     * @brief setColor
     * @param newColor
     */
    void setColor(ColorPiece newColor);

    /**
     * @brief getHistory
     */
    const vector<Position> &getHistory() const;
    /**
     * @brief The setter of the private attribute history
     * @param newHistory
     */
    void setHistory(const vector<Position> &newHistory);

    /**
     * @brief Show the piece
     */
    void showPiece();
    /**
     * @brief Hide the piece
     */
    void hidePiece();
    /**
     * @brief The getter of the private attribute isHidden
     */
    bool getIsHidden()const;
    virtual Piece battle(Piece pieceAttk);

};

inline int Piece::getRank() const
{
    return rank;
}


inline void Piece::setRank(int newRank)
{
    rank = newRank;
}

inline const string &Piece::getSymbol() const
{
    return symbol;
}

inline void Piece::setSymbol(const string &newSymbol)
{
    symbol = newSymbol;
}

inline int Piece::getMoveMax() const
{
    return moveMax;
}

inline void Piece::setMoveMax(int newMoveMax)
{
    moveMax = newMoveMax;
}

inline ColorPiece Piece::getColor() const
{
    return color;
}

inline void Piece::setColor(ColorPiece newColor)
{
    color = newColor;
}

inline const vector<Position> &Piece::getHistory() const
{
    return history;
}

inline void Piece::setHistory(const vector<Position> &newHistory)
{
    history = newHistory;
}

bool Piece::operator == ( Piece& piece){
    if(this->rank==piece.rank){
        return true;
    }
    return false;
}
bool Piece::operator != ( Piece& piece){
    if(this->color!=piece.color){
        return true;
    }
    return false;
}

bool Piece::operator > (Piece& piece){
    if(this->rank>piece.rank){
        return true ;
    }else {
        return false ;
    }

}

class Bomb : public Piece{
public:
    Bomb( ColorPiece color);
    Piece battle(Piece pieceAttk){
        return pieceAttk.getRank()!=3 ? *this: pieceAttk;
    }
};

class Flag : public Piece{
public:
    Flag( ColorPiece color);
    Piece battle(Piece pieceAttk){
        return pieceAttk;
    }

};


class Scout :public  Piece{
public:
    Scout( ColorPiece color);

};

}


#endif // PIECE_H



